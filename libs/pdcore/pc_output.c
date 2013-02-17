/*---------------------------------------------------------------------------*
 |              PDFlib - A library for generating PDF on the fly             |
 +---------------------------------------------------------------------------+
 | Copyright (c) 1997-2006 Thomas Merz and PDFlib GmbH. All rights reserved. |
 +---------------------------------------------------------------------------+
 |                                                                           |
 |    This software is subject to the PDFlib license. It is NOT in the       |
 |    public domain. Extended versions and commercial licenses are           |
 |    available, please check http://www.pdflib.com.                         |
 |                                                                           |
 *---------------------------------------------------------------------------*/

/* $Id: pc_output.c,v 1.144.2.29 2009/10/23 11:28:02 stm Exp $
 *
 * PDFlib output routines
 *
 */

#include "pc_util.h"
#include "pc_file.h"
#include "pc_md5.h"

#if (defined(WIN32) || defined(OS2)) && !defined(WINCE)
#include <fcntl.h>
#include <io.h>
#endif

/* for time_t, timer().
*/
#ifndef WINCE
#include <time.h>
#else
#include <winbase.h>
#endif

#if !defined(PDF_MAC_NOCORESERVICES) && (defined(MAC) || defined (MACOSX))

/*
 * Setting the file type requires either Carbon or InterfaceLib/Classic.
 * If we have neither (i.e. a Mach-O build without Carbon) we suppress
 * the code for setting the file type and creator.
 */

#if !defined(MACOSX) || (defined(PDF_TARGET_API_MAC_CARBON) && \
     defined(PDF_ALLOW_MAC_DEPR_FUNCS))
#define PDF_FILETYPE_SUPPORTED
#include <Files.h>
#endif

#endif /* !PDF_MAC_NOCORESERVICES && (MAC || MACOSX) */

#ifdef HAVE_LIBZ
#include "zlib.h"
#endif

#ifdef HAVE_LIBZ
#define PDF_DEFAULT_COMPRESSION	6		/* default zlib level */
#else
#define PDF_DEFAULT_COMPRESSION	0		/* no compression */
#endif

#define STREAM_BUFSIZE	65536		/* initial output buffer size */
#define STREAM_MAXINCR	1048576		/* max. output buffer increment */
#define ID_CHUNKSIZE	2048		/* object ids */

struct pdc_output_s {
    pdc_core	*pdc;			/* core context */

    pdc_bool    open;                   /* file open */
    pdc_byte	*basepos;		/* start of this chunk */
    pdc_byte	*curpos;		/* next write position */
    pdc_byte	*maxpos;		/* maximum position of chunk */
    int		buf_incr;		/* current buffer increment */
    pdc_off_t	base_offset;		/* base offset of this chunk */
    pdc_bool	compressing;		/* in compression state */
    pdc_flush_state flush;
#ifdef HAVE_LIBZ
    z_stream	z;			/* zlib compression stream */
#endif

    FILE	*fp;			/* output file stream */
#if defined(MVS) || defined(MVS_TEST)
    const char *fopenparams;            /* additional fopen() parameters */
    int		recordsize;		/* file record size */
#endif

    /* client-supplied data sink procedure */
    size_t	(*writeproc)(pdc_output *out, void *data, size_t size);

    int		compresslevel;		/* zlib compression level */
    pdc_bool	compr_changed;		/* compress level has been changed */
    pdc_off_t	length;			/* length of stream */

    pdc_off_t	*file_offset;		/* the objects' file offsets */
    int		file_offset_capacity;
    pdc_id	lastobj;		/* highest object id */

    pdc_off_t	start_pos;		/* stream start position */
    pdc_off_t	xref_pos;		/* xref table start position */

    MD5_CTX	md5;			/* MD5 digest context for file ID */
    unsigned char id[2][MD5_DIGEST_LENGTH];
    void	*opaque;		/* this will be used to store PDF *p */


    /* ------------- extended output control ------------- */
};

/* ----------- service function to get PDF version string  -------------- */

const char *
pdc_get_pdfversion(pdc_core *pdc, int compatibility)
{
    return pdc_errprintf(pdc, "%d.%d", compatibility / 10, compatibility % 10);
}

/* --------------------- PDFlib stream handling ----------------------- */

void *
pdc_get_opaque(pdc_output *out)
{
    return out->opaque;
}

#ifdef HAVE_LIBZ
/* wrapper for pdc_malloc for use in zlib */
static voidpf
pdc_zlib_alloc(voidpf pdc, uInt items, uInt size)
{
    return (voidpf) pdc_malloc((pdc_core *) pdc, items * size, "zlib");
}

#endif	/* HAVE_LIBZ */

pdc_bool
pdc_stream_not_empty(pdc_output *out)
{
    return (!out->writeproc && out->curpos != out->basepos);
}

char *
pdc_get_stream_contents(pdc_output *out, pdc_off_t *size)
{
    pdc_core *pdc = out->pdc;

    if (out->writeproc)
	pdc_error(pdc, PDC_E_IO_NOBUFFER, 0, 0, 0, 0);

    if (size)
	*size = (pdc_off_t) (out->curpos - out->basepos);

    out->base_offset += (out->curpos - out->basepos);
    out->curpos = out->basepos;

    return (char *) out->basepos;
}

static size_t
pdc_writeproc_file(pdc_output *out, void *data, size_t size)
{
    return pdc__fwrite(data, 1, size, out->fp);
}

#if defined(_MSC_VER) && defined(_MANAGED)
#pragma unmanaged
#endif
static pdc_bool
pdc_init_stream(
    pdc_core *pdc,
    pdc_output *out,
    const char *filename,
    FILE *fp,
    size_t (*writeproc)(pdc_output *out, void *data, size_t size))
{
    static const char fn[] = "pdc_init_stream";

#if (defined(MAC) || defined(MACOSX)) && defined(PDF_FILETYPE_SUPPORTED)
#if !defined(TARGET_API_MAC_CARBON) || defined(__MWERKS__)
    FCBPBRec	fcbInfo;
    Str32	name;
#endif	/* TARGET_API_MAC_CARBON */
    FInfo	fInfo;
    FSSpec	fSpec;
#endif  /* (MAC || MACOSX) && PDF_FILETYPE_SUPPORTED */

    /*
     * This may be left over from the previous run. We deliberately
     * don't reuse the previous buffer in order to avoid potentially
     * unwanted growth of the allocated buffer due to a single large
     * document in a longer series of documents.
     */
    if (out->basepos)
	pdc_free(pdc, (void *) out->basepos);

    out->basepos	= (pdc_byte *) pdc_malloc(pdc, STREAM_BUFSIZE, fn);
    out->curpos		= out->basepos;
    out->maxpos		= out->basepos + STREAM_BUFSIZE;
    out->buf_incr	= STREAM_BUFSIZE;

    out->base_offset	= 0;
    out->compressing	= pdc_false;

#ifdef HAVE_LIBZ
    /* zlib sometimes reads uninitialized memory where it shouldn't... */
    memset(&out->z, 0, sizeof out->z);

    out->z.zalloc	= (alloc_func) pdc_zlib_alloc;
    out->z.zfree	= (free_func) pdc_free;
    out->z.opaque	= (voidpf) pdc;

    if (deflateInit(&out->z, pdc_get_compresslevel(out)) != Z_OK)
	pdc_error(pdc, PDC_E_IO_COMPRESS, "deflateInit", 0, 0, 0);

    out->compr_changed = pdc_false;
#endif

    /* Defaults */
    out->fp		= (FILE *) NULL;
    out->writeproc	= pdc_writeproc_file;

    if (fp)
    {
	out->fp	= fp;
    }
    else if (writeproc)
    {
	out->writeproc	= writeproc;		/* PDF_open_mem */
    }
    else if (filename == NULL || *filename == '\0')
    {
	/* PDF_open_file with in-core output */
	out->writeproc = NULL;
    }
    else
    {
	/* PDF_open_file with file output */
#if !((defined(MAC) || defined (MACOSX)) && defined(__MWERKS__))
	if (filename && !strcmp(filename, "-"))
        {
	    out->fp = stdout;
#if !defined(__MWERKS__) && (defined(WIN32) || defined(OS2))
#if !defined(__BORLANDC__) && !defined(OS2)
	    _setmode(_fileno(stdout), _O_BINARY);
#else
	    setmode(fileno(stdout), O_BINARY);
#endif /* !__BORLANDC__ && !OS2 */
#endif
	}
        else
        {
#endif /* !MAC */
            char fopenparams[200]; /* sufficient */

#if defined(MVS) || defined(MVS_TEST)
            if (out->fopenparams != (char *) 0)
            {
                strcpy(fopenparams, WRITEMODE);
                strcat(fopenparams, ",");
                strcat(fopenparams, out->fopenparams);
            }
            else if (out->recordsize <= 1)
            {
                strcpy(fopenparams, WRITEMODE_V);
            }
            else
            {
                strcpy(fopenparams, WRITEMODE);
            }
#else
            strcpy(fopenparams, WRITEMODE);
#endif

            out->fp = pdc_fopen_logg(out->pdc, filename, fopenparams);
	    if (out->fp == NULL)
		return pdc_false;

#if (defined(MAC) || defined(MACOSX)) && defined(PDF_FILETYPE_SUPPORTED)
            if (!pdc->ptfrun)
            {
                /* set the proper type and creator for the output file */
#if TARGET_API_MAC_CARBON && !defined(__MWERKS__)

                if (FSPathMakeFSSpec((const UInt8 *) filename, &fSpec) == noErr)
                {
                    FSpGetFInfo(&fSpec, &fInfo);
                    fInfo.fdType = 'PDF ';
                    fInfo.fdCreator = 'CARO';
                    FSpSetFInfo(&fSpec, &fInfo);
                }

#else

                memset(&fcbInfo, 0, sizeof(FCBPBRec));
                fcbInfo.ioRefNum = (short) out->fp->handle;
                fcbInfo.ioNamePtr = name;

                if (!PBGetFCBInfoSync(&fcbInfo) &&
                    FSMakeFSSpec(fcbInfo.ioFCBVRefNum, fcbInfo.ioFCBParID,
                    name, &fSpec) == noErr)
                {
                        FSpGetFInfo(&fSpec, &fInfo);
                        fInfo.fdType = 'PDF ';
                        fInfo.fdCreator = 'CARO';
                        FSpSetFInfo(&fSpec, &fInfo);
                }
#endif  /* !defined(TARGET_API_MAC_CARBON) || defined(__MWERKS__) */
            }
#endif	/* (MAC || MACOSX) && PDF_FILETYPE_SUPPORTED */

#if !((defined(MAC) || defined (MACOSX)) && defined(__MWERKS__))
	}
#endif /* !MAC */
    }

    return pdc_true;
}
#if defined(_MSC_VER) && defined(_MANAGED)
#pragma managed
#endif

/* close the output file, if opened with PDF_open_file();
 * close the output stream if opened
 */

static void
pdc_close_stream(pdc_output *out)
{
    /* this time we MUST flush the stream -
    ** even if (flush == pdc_flush_none)
    */
    out->flush = pdc_flush_heavy;
    pdc_flush_stream(out);

#ifdef HAVE_LIBZ
    /*
     * This is delicate: we must ignore the return value because of the
     * following reasoning: We are called in two situations:
     * - end of document
     * - exception
     * In the first case compression is inactive, so deflateEnd() will
     * fail only in the second case. However, when an exception occurs
     * the document is definitely unusable, so we avoid recursive exceptions
     * or an (unallowed) exception in PDF_delete().
     */

    (void) deflateEnd(&out->z);
#endif

    /* close the output file if writing to file, but do not close the
     * in-core output stream since the caller will have to
     * fetch the buffer after PDF_close().
     */
    if (out->fp)
    {
        pdc_fclose_logg(out->pdc, out->fp);

	/* mark fp as dead in case the error handler jumps in later */
	out->fp = NULL;
    }
}

static void
pdc_check_stream(pdc_output *out, size_t len)
{
    size_t newsize;
    size_t cur;
    pdc_core *pdc = out->pdc;

    if (out->curpos + len <= out->maxpos)
	return;

    pdc_flush_stream(out);

    if (out->curpos + len <= out->maxpos)
	return;

    do
    {
	out->maxpos += out->buf_incr;

	if (out->buf_incr < STREAM_MAXINCR)
	    out->buf_incr *= 2;
    } while (out->curpos + len > out->maxpos);

    cur = (size_t) (out->curpos - out->basepos);
    newsize = (size_t) (out->maxpos - out->basepos);

    out->basepos = (pdc_byte *)
	pdc_realloc(pdc, (void *) out->basepos, newsize, "pdc_check_stream");
    out->maxpos = out->basepos + newsize;
    out->curpos = out->basepos + cur;
}

void
pdc_flush_stream(pdc_output *out)
{
    size_t size;
    pdc_core *pdc = out->pdc;

    if (!out->writeproc || out->flush == pdc_flush_none)
	return;

    size = (size_t) (out->curpos - out->basepos);

    if (size == 0)
	return;

    if (out->writeproc(out, (void *) out->basepos, size) != size) {
	pdc_free(pdc, out->basepos);
	out->basepos = NULL;
	out->writeproc = NULL;
	pdc_error(pdc, PDC_E_IO_NOWRITE, 0, 0, 0, 0);
    }

    out->base_offset += (out->curpos - out->basepos);
    out->curpos = out->basepos;
}

pdc_off_t
pdc_tell_out(pdc_output *out)
{
    return (out->base_offset + (out->curpos - out->basepos));
}

/* --------------------- compression handling ----------------------- */

static void
pdc_begin_compress(pdc_output *out)
{
    pdc_core *pdc = out->pdc;

    if (!pdc_get_compresslevel(out)) {
	out->compressing = pdc_false;
	return;
    }

#ifdef HAVE_LIBZ
    if (out->compr_changed)
    {
	if (deflateEnd(&out->z) != Z_OK)
	    pdc_error(pdc, PDC_E_IO_COMPRESS, "deflateEnd", 0, 0, 0);

	if (deflateInit(&out->z, pdc_get_compresslevel(out)) != Z_OK)
	    pdc_error(pdc, PDC_E_IO_COMPRESS, "deflateInit", 0, 0, 0);

	out->compr_changed = pdc_false;
    }
    else
    {
	if (deflateReset(&out->z) != Z_OK)
	    pdc_error(pdc, PDC_E_IO_COMPRESS, "deflateReset", 0, 0, 0);
    }

    out->z.avail_in = 0;
#endif /* HAVE_LIBZ */

    out->compressing = pdc_true;
}


static void
pdc_end_compress(pdc_output *out)
{
    int status;
    pdc_core *pdc = out->pdc;

    /* this may happen during cleanup triggered by an exception handler */
    if (!out->compressing)
	return;

    if (!pdc_get_compresslevel(out)) {
	out->compressing = pdc_false;
	return;
    }


#ifdef HAVE_LIBZ
    /* Finish the stream */
    do {
	pdc_check_stream(out, 128);
	out->z.next_out = (Bytef *) out->curpos;
	out->z.avail_out = (uInt) (out->maxpos - out->curpos);

	status = deflate(&(out->z), Z_FINISH);
	out->curpos = out->z.next_out;

	if (status != Z_STREAM_END && status != Z_OK)
	    pdc_error(pdc, PDC_E_IO_COMPRESS, "Z_FINISH", 0, 0, 0);

    } while (status != Z_STREAM_END);

    out->compressing = pdc_false;
#endif /* HAVE_LIBZ */
}

/* ---------------------- Low-level output function ---------------------- */
/*
 * Write binary data to the output without any modification,
 * and apply compression if we are currently in compression mode.
 */


void
pdc_write(pdc_output *out, const void *data, size_t size)
{
    int estimate = 0;
    pdc_core *pdc = out->pdc;

#ifdef HAVE_LIBZ
    if (out->compressing) {
	out->z.avail_in		= (uInt) size;
	out->z.next_in		= (Bytef *) data;
	out->z.avail_out	= 0;

	while (out->z.avail_in > 0) {
	    if (out->z.avail_out == 0) {
		/* estimate output buffer size */
		estimate = (int) (out->z.avail_in/4 + 16);
		pdc_check_stream(out, (size_t) estimate);
		out->z.next_out = (Bytef *) out->curpos;
		out->z.avail_out = (uInt) (out->maxpos - out->curpos);
	    }

	    if (deflate(&(out->z), Z_NO_FLUSH) != Z_OK)
		pdc_error(pdc, PDC_E_IO_COMPRESS, "Z_NO_FLUSH", 0, 0, 0);

	    out->curpos = out->z.next_out;
	}
    } else {
#endif /* HAVE_LIBZ */

	pdc_check_stream(out, size);
	memcpy(out->curpos, data, size);
	out->curpos += size;

#ifdef HAVE_LIBZ
    }
#endif /* HAVE_LIBZ */
}


/* --------------------------- Setup --------------------------- */

pdc_output *
pdc_boot_output(pdc_core *pdc)
{
    static const char *fn = "pdc_boot_output";
    pdc_output *out;

    out = (pdc_output*)pdc_malloc(pdc, sizeof(pdc_output), fn);
    out->pdc = pdc;

    out->file_offset	= NULL;

    /* curpos must be initialized here so that the check for empty
     * buffer in PDF_delete() also works in the degenerate case of
     * no output produced.
     */
    out->basepos = out->curpos = NULL;

    out->open = pdc_false;

    return out;
}

void
pdc_init_outctl(pdc_outctl *oc)
{
    oc->filename	= 0;
    oc->fp		= 0;
    oc->writeproc	= 0;
    oc->flush		= pdc_flush_page;
#if defined(MVS) || defined(MVS_TEST)
    oc->fopenparams     = 0;
    oc->recordsize      = 0;
#endif


} /* pdc_init_outctl */

/*
 * Initialize the PDF output.
 * Note that the caller is responsible for supplying sensible arguments.
 */
#if defined(_MSC_VER) && defined(_MANAGED)
#pragma unmanaged
#endif
pdc_bool
pdc_init_output(
    void *opaque,
    pdc_output *out,
    int compatibility,
    pdc_outctl *oc)
{
    static const char *fn = "pdc_init_output";
    pdc_core *pdc = out->pdc;
    int i;

    pdc_cleanup_output(out, pdc_false);

    out->opaque		= opaque;

    out->lastobj	= 0;
#if defined(MVS) || defined(MVS_TEST)
    out->fopenparams    = oc->fopenparams;
    out->recordsize     = oc->recordsize;
#endif

    if (out->file_offset == NULL) {
	out->file_offset_capacity = ID_CHUNKSIZE;

	out->file_offset = (pdc_off_t *) pdc_malloc(pdc,
		sizeof(pdc_off_t) * out->file_offset_capacity, fn);
    }

    for (i = 1; i < out->file_offset_capacity; ++i)
	out->file_offset[i] = PDC_BAD_ID;

    out->compresslevel	= PDF_DEFAULT_COMPRESSION;
    out->compr_changed	= pdc_false;
    out->flush = oc->flush;

    memcpy(out->id[0], out->id[1], MD5_DIGEST_LENGTH);


    if (!pdc_init_stream(pdc, out, oc->filename, oc->fp, oc->writeproc))
	return pdc_false;


    {
	/* Write the document header */
	pdc_printf(out, "%%PDF-%s\n", pdc_get_pdfversion(pdc, compatibility));

#define PDC_MAGIC_BINARY "\045\344\343\317\322\012"
	pdc_write(out, PDC_MAGIC_BINARY, sizeof(PDC_MAGIC_BINARY) - 1);
    }

    out->open = pdc_true;

    return pdc_true;
}
#if defined(_MSC_VER) && defined(_MANAGED)
#pragma managed
#endif

void
pdc_close_output(pdc_output *out)
{
    if (out->open)
    {
        out->open = pdc_false;

        pdc_close_stream(out);

        if (out->file_offset)
        {
            pdc_free(out->pdc, out->file_offset);
            out->file_offset = 0;
        }

    }
}

void
pdc_cleanup_output(pdc_output *out, pdc_bool keep_buf)
{
    pdc_core *pdc = out->pdc;

    if (out->file_offset)
    {
	pdc_free(pdc, out->file_offset);
	out->file_offset = NULL;
    }


    if (!keep_buf && out->basepos)
    {
	pdc_free(pdc, (void *) out->basepos);
	out->basepos = NULL;
        out->curpos = NULL;
    }

}

/* --------------------------- Digest --------------------------- */

void
pdc_init_digest(pdc_output *out)
{
    MD5_Init(&out->md5);
}

void
pdc_update_digest(pdc_output *out, unsigned char *input,
    unsigned int len)
{
    MD5_Update(&out->md5, input, len);
}

void
pdc_finish_digest(pdc_output *out, pdc_bool settime)
{
    if (settime)
    {
        time_t timer;

        time(&timer);
        MD5_Update(&out->md5, (unsigned char *) &timer, sizeof timer);
    }

    MD5_Final(out->id[1], &out->md5);
}

unsigned char *
pdc_get_digest(pdc_output *out)
{
    return out->id[1];
}

/* --------------------------- Objects and ids --------------------------- */

pdc_id
pdc_begin_obj(pdc_output *out, pdc_id obj_id)
{
    if (obj_id == PDC_NEW_ID)
	obj_id = pdc_alloc_id(out);

    out->file_offset[obj_id] = pdc_tell_out(out);
    pdc_printf(out, "%ld 0 obj\n", obj_id);


    return obj_id;
}

pdc_id
pdc_alloc_id(pdc_output *out)
{


    out->lastobj++;

    if (out->lastobj > PDF_MAXINDOBJS)
        pdc_error(out->pdc, PDC_E_INT_TOOMUCH_INDOBJS,
                  pdc_errprintf(out->pdc, "%d", PDF_MAXINDOBJS), 0, 0, 0);

    if (out->lastobj >= out->file_offset_capacity) {
	out->file_offset_capacity *= 2;
	out->file_offset = (pdc_off_t *)
	    pdc_realloc(out->pdc, out->file_offset,
		sizeof(pdc_off_t) * out->file_offset_capacity, "pdc_alloc_id");
    }

    /* only needed for verifying obj table in PDF_close() */
    out->file_offset[out->lastobj] = PDC_BAD_ID;

    return out->lastobj;
}


/* --------------------------- Strings --------------------------- */

void
pdc_put_pdfstring(pdc_output *out, const char *text, int len)
{
    const unsigned char *goal, *s;

    if (!len)
        len = (int) strlen(text);

    if (out->pdc->compatibility <= PDC_1_5 && len > PDF_MAXSTRINGSIZE)
        pdc_error(out->pdc, PDC_E_INT_TOOLONG_TEXTSTR,
                  pdc_errprintf(out->pdc, "%d", PDF_MAXSTRINGSIZE), 0, 0, 0);


    pdc_putc(out, PDF_PARENLEFT);

    goal = (const unsigned char *) text + len;

    for (s = (const unsigned char *) text; s < goal; s++)
    {
	switch (*s)
        {
	    case PDF_RETURN:
		pdc_putc(out, PDF_BACKSLASH);
		pdc_putc(out, PDF_r);
		break;

            case PDF_NEWLINE:
		pdc_putc(out, PDF_BACKSLASH);
		pdc_putc(out, PDF_n);
		break;

	    default:
		if (*s == PDF_PARENLEFT || *s == PDF_PARENRIGHT ||
		    *s == PDF_BACKSLASH)
		    pdc_putc(out, PDF_BACKSLASH);
		pdc_putc(out, (char) *s);
	}
    }

    pdc_putc(out, PDF_PARENRIGHT);
}

/* normalized file name according PDF specification */
void
pdc_put_pdffilename(pdc_output *out, const char *text, int len)
{
    static const char *fn = "pdc_put_pdffilename";
    pdc_byte *btext = (pdc_byte *) text;
    pdc_bool isuni = pdc_is_utf16be_unicode(btext);
    char *ttext;
    pdc_byte c, cp, cpp;
    int i, ia = 0, j = 0;

    ttext = (char *) pdc_calloc(out->pdc, (size_t) (len + 4), fn);

    if (isuni)
    {
        ttext[0] = PDF_BOM0;
        ttext[1] = PDF_BOM1;
        ia = 2;
        j = 2;
    }

    /* absolute path name:
     * r:\pdfdocs\spec.pdf -> /r/pdfdocs/spec.pdf
     * pclib/eng:\pdfdocs\spec.pdf -> /pclib/eng/pdfdocs/spec.pdf
     */
    cp = 0x7F;
    for (i = ia; i < len; i++)
    {
        c = btext[i];
        if (c == PDF_COLON && (!isuni || cp == 0))
        {
            if (isuni)
            {
                ttext[j] = 0;
                j++;
            }
            ttext[j] = PDF_SLASH;
            j++;

            break;
        }
        cp = c;
    }

    cp = 0x7F;
    cpp = 0x7F;
    for (i = ia; i < len; i++)
    {
        c = btext[i];

        if ((c == PDF_BACKSLASH || c == PDF_SLASH || c == PDF_COLON) &&
            (!isuni || cp == 0))
        {
            /* convert to slash, but avoid multiple slashes */
            if (cpp != PDF_SLASH)
            {
                c = PDF_SLASH;
            }
            else
            {
                if (isuni)
                    j--;
                continue;
            }
        }

        ttext[j] = c;
        j++;

        cp = c;
        if (c)
            cpp = c;
    }

    len = j;

    pdc_put_pdfstring(out, ttext, len);

    pdc_free(out->pdc, ttext);
}


/* --------------------------- Streams --------------------------- */

void
pdc_begin_pdfstream(pdc_output *out)
{
    pdc_puts(out, "stream\n");

    out->start_pos = pdc_tell_out(out);

    if (out->compresslevel)
	pdc_begin_compress(out);
}

void
pdc_end_pdfstream(pdc_output *out)
{
    if (out->compresslevel)
	pdc_end_compress(out);

    out->length = pdc_tell_out(out) - out->start_pos;

    /* some PDF consumers seem to need the additional "\n" before "endstream",
    ** the PDF reference allows it, and Acrobat's "repair" feature relies on it.
    */
    pdc_puts(out, "\nendstream\n");
}

pdc_off_t
pdc_get_pdfstreamlength(pdc_output *out)
{
    return out->length;
}

void
pdc_put_pdfstreamlength(pdc_output *out, pdc_id length_id)
{

    pdc_begin_obj(out, length_id);	/* Length object */
    pdc_printf(out, "%lld\n", out->length);
    pdc_end_obj(out);
}

void
pdc_set_compresslevel(pdc_output *out, int compresslevel)
{
    out->compresslevel = compresslevel;
    out->compr_changed = pdc_true;
}

int
pdc_get_compresslevel(pdc_output *out)
{
    return out->compresslevel;
}


/* --------------------------- Names --------------------------- */

/* characters illegal in PDF names: "()<>[]{}/%#" */
#define PDF_ILL_IN_NAMES "\050\051\074\076\133\135\173\175\057\045\043"

#define PDF_NEEDS_QUOTE(c) \
	((c) < 33 || (c) > 126 || strchr(PDF_ILL_IN_NAMES, (c)) != (char *) 0)

void
pdc_put_pdfname(pdc_output *out, const char *text, size_t len)
{
    const unsigned char *goal, *s;
    static const char BinToHex[] = PDF_STRING_0123456789ABCDEF;

    if (!len)
        len = strlen(text);

    goal = (const unsigned char *) text + len;

    pdc_putc(out, PDF_SLASH);

    for (s = (const unsigned char *) text; s < goal; s++) {
	if (PDF_NEEDS_QUOTE(*s)) {
	    pdc_putc(out, PDF_HASH);
	    pdc_putc(out, BinToHex[*s >> 4]);	/* first nibble  */
	    pdc_putc(out, BinToHex[*s & 0x0F]);	/* second nibble  */
	} else
	    pdc_putc(out, (char) *s);
    }
}

/* --------------------------- Document sections  --------------------------- */

void
pdc_mark_free(pdc_output *out, pdc_id obj_id)
{
    out->file_offset[obj_id] = PDC_FREE_ID;
}


void
pdc_write_xref(pdc_output *out)
{
    pdc_id	start = 1;
    pdc_id	i;
    pdc_id	free_id;
    pdc_core *	pdc = out->pdc;



    /* Don't write any object after this check! */

    for (i = start; i <= out->lastobj; i++) {
	if (out->file_offset[i] == PDC_BAD_ID) {
	    pdc_warning(pdc, PDC_E_INT_UNUSEDOBJ,
		pdc_errprintf(pdc, "%ld", i), 0, 0, 0);
	    /* write a dummy object */
	    pdc_begin_obj(out, i);
	    pdc_printf(out, "null %% unused object\n");
	    pdc_end_obj(out);
	}
    }


    out->xref_pos = pdc_tell_out(out);
    pdc_puts(out, "xref\n");
    pdc_printf(out, "0 %ld\n", out->lastobj + 1);

    /* find the last free entry in the xref table.
    */
    out->file_offset[0] = PDC_FREE_ID;
    for (free_id = out->lastobj;
	out->file_offset[free_id] != PDC_FREE_ID;
	--free_id)
	;

    pdc_printf(out, "%010ld 65535 f \n", free_id);
    free_id = 0;

#define PDF_FLUSH_AFTER_MANY_OBJS	3000    /* ca. 60 KB */
    for (i = 1; i <= out->lastobj; i++) {
	/* Avoid spike in memory usage at the end of the document */
	if (i % PDF_FLUSH_AFTER_MANY_OBJS == 0)
	    pdc_flush_stream(out);

	if (out->file_offset[i] == PDC_FREE_ID)
	{
	    pdc_printf(out, "%010ld 00001 f \n", free_id);
	    free_id = i;
	}
	else
	{
	    pdc_printf(out, "%010lld 00000 n \n", out->file_offset[i]);
	}
    }
}

void
pdc_write_digest(pdc_output *out)
{
    static const char bin2hex[] = PDF_STRING_0123456789ABCDEF;

    int i;

    pdc_puts(out, "/ID[<");
    for (i = 0; i < MD5_DIGEST_LENGTH; ++i)
    {
	pdc_putc(out, bin2hex[out->id[0][i] >> 4]);
	pdc_putc(out, bin2hex[out->id[0][i] & 0x0F]);
    }
    pdc_puts(out, "><");
    for (i = 0; i < MD5_DIGEST_LENGTH; ++i)
    {
	pdc_putc(out, bin2hex[out->id[1][i] >> 4]);
	pdc_putc(out, bin2hex[out->id[1][i] & 0x0F]);
    }
    pdc_puts(out, ">]\n");
}

void
pdc_write_eof(pdc_output *out)
{
#if defined(MVS) || defined(MVS_TEST)
    int i, k;

    if (out->recordsize > 1)
    {
	if ((i = (pdc_tell_out(out) + 6) % out->recordsize) != 0)
	{
	    for (k = 0; k < out->recordsize - i - 1; ++k)
		pdc_putc(out, PDF_SPACE);

	    pdc_putc(out, PDF_NEWLINE);
	}
    }
#endif /* MVS */
    pdc_puts(out, "%%EOF\n");
}

void
pdc_write_trailer(
    pdc_output *out,
    pdc_id info_id,
    pdc_id root_id,
    int root_gen,
    long xref_size,
    pdc_off_t xref_prev,
    pdc_off_t xref_pos)
{
    if (xref_size == -1)
    {
	xref_size = out->lastobj + 1;
    }

    if (xref_pos == -1)
    {
	xref_pos = out->xref_pos;
    }

    /* we've seen PDF consumers that need the linefeed...
    */
    pdc_puts(out, "trailer\n");

    pdc_begin_dict(out);				/* trailer */
    pdc_printf(out, "/Size %ld\n", xref_size);

    if (xref_prev != -1)
	pdc_printf(out, "/Prev %lld\n", xref_prev);

    pdc_printf(out, "/Root %ld %d R\n", root_id, root_gen);

    if (info_id != PDC_BAD_ID)
	pdc_printf(out, "/Info %ld 0 R\n", info_id);

    pdc_write_digest(out);
    pdc_end_dict(out);				/* trailer */

    pdc_puts(out, "startxref\n");
    pdc_printf(out, "%lld\n", xref_pos);
    pdc_write_eof(out);
}

/* ---------------------- High-level output functions ---------------------- */

/*
 * Write a native encoded string to the output.
 */

static void
pdc_puts_internal(pdc_output *out, char *s, pdc_bool tocopy)
{
    char *scp = s;
    (void) tocopy;

    pdc_write(out, (void *) scp, strlen(scp));
}

void
pdc_puts(pdc_output *out, const char *s)
{
    pdc_puts_internal(out, (char *) s, pdc_true);
}

/*
 * Write a ASCII character to the output.
 */

void
pdc_putc(pdc_output *out, const char c)
{
    pdc_write(out, (void *) &c, (size_t) 1);
}

/*
 * Write a formatted string (native encoded) to the output.
 */

void
pdc_printf(pdc_output *out, const char *fmt, ...)
{
    char buf[PDC_GEN_BUFSIZE];
    va_list ap;

    va_start(ap, fmt);

    pdc_vsprintf(out->pdc, pdc_true, buf, fmt, ap);
    pdc_puts_internal(out, buf, pdc_false);

    va_end(ap);
}

