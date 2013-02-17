/*---------------------------------------------------------------------------*
 |              PDFlib - A library for generating PDF on the fly             |
 +---------------------------------------------------------------------------+
 | Copyright (c) 2000-2006 Thomas Merz and PDFlib GmbH. All rights reserved. |
 +---------------------------------------------------------------------------+
 |                                                                           |
 |    This software is subject to the PDFlib license. It is NOT in the       |
 |    public domain. Extended versions and commercial licenses are           |
 |    available, please check http://www.pdflib.com.                         |
 |                                                                           |
 *---------------------------------------------------------------------------*/

/* $Id: pdfimpose.c,v 1.22.2.2 2008/05/27 09:10:37 kurt Exp $
 *
 * Impose multiple PDF documents on a single sheet,
 * or concatenate multiple PDFs (if no -g option is supplied),
 * or create PDF/A from one or more PDF/A input documents.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(__CYGWIN32__)
#include <getopt.h>
#elif defined(WIN32)
int getopt(int argc, char * const argv[], const char *optstring);
extern char *optarg;
extern int optind;
#elif !defined(WIN32) && !defined(MAC)
#include <unistd.h>
#endif

#include "pdflib.h"

static void
usage(void)
{
    fprintf(stderr,

"\npdfimpose: impose multiple PDF documents on a single sheet.\n"
"(c) PDFlib GmbH 2001-2006 www.pdflib.com\n"
"\n"
"usage: pdfimpose [options] pdffiles(s)\n"
"\n"
"Available options:\n"
"-a level      PDF/A compatibility level: \"PDF/A-1b:2005\" or \"none\""
"              default: none\n"
"-b            print boxes around imposed pages\n"
"-g wxh        number of columns and rows per sheet (default: 1x1)\n"
"-I <filename> name of a PDF/A file from which to copy the output intent\n"
"              default: first PDF/A input file\n"
"-l            landscape mode\n"
"-n            start each document on a new page\n"
"-o <filename> PDF output file name\n"
"-p <pagesize> page format (a0-a6, letter, legal, etc.)\n"
"-q            quiet mode: do not emit info messages\n"
"-v <version>  PDF output version: 1.3, 1.4, 1.5, 1.6, 1.7\n");

    exit(1);
}

int
main(int argc, char *argv[])
{
    char	*pdffilename = NULL;
    char	*pdfversion = NULL;
    PDF		*p;
    int		opt;
    int		doc, page;
    int		pageno, docpages;
    char	*filename, *intent=NULL;
    int		quiet = 0, landscape = 0, boxes = 0, newpage = 0;
    int		cols = 1, rows = 1;
    int		c = 0, r = 0;
    double	sheetwidth = 595.0, sheetheight = 842.0;
    double	width, height, scale = 1.0f;
    double	rowheight = 0.0f, colwidth = 0.0f;
    char	*pagesize = NULL;
    char 	*pdfalevel = NULL;
    char	optlist[1024];

    while ((opt = getopt(argc, argv, "a:bg:I:lnp:o:qv:")) != -1)
	switch (opt) {
	    case 'a':
		if (strcmp(optarg, "none"))
		    pdfalevel = optarg;
		break;

	    case 'b':
		boxes = 1;
		break;

	    case 'g':
		if (sscanf(optarg, "%dx%d", &rows, &cols) != 2) {
		    fprintf(stderr, "Error: Couldn't parse -g option.\n");
		    usage();
		}
		if (rows <= 0 || cols <= 0) {
		    fprintf(stderr, "Bad row or column number.\n");
		    usage();
		}
		break;

	    case 'I':
		intent = optarg;
		break;

	    case 'l':
		landscape = 1;
		break;

	    case 'n':
		newpage = 1;
		break;

	    case 'p':
		pagesize = optarg;
		break;

	    case 'o':
		pdffilename = optarg;
		break;

	    case 'v':
		pdfversion = optarg;
		break;

	    case 'q':
		quiet = 1;
		break;

	    case '?':
	    default:
		usage();
	}

    if (optind == argc)
    {
	fprintf(stderr, "Error: no PDF files given.\n");
	usage();
    }

    if (pdffilename == NULL)
    {
	fprintf(stderr, "Error: no PDF output file given.\n");
	usage();
    }

    p = PDF_new();

    PDF_TRY(p)
    {

	optlist[0] = 0;

	if (pdfversion)
	    sprintf(optlist, "compatibility=%s ", pdfversion);

	if (pdfalevel)
	    sprintf(optlist+strlen(optlist), "pdfa=%s ", pdfalevel);

	if (PDF_begin_document(p, pdffilename, 0, optlist) == -1)
	{
	    fprintf(stderr, "Error: %s.\n", PDF_get_errmsg(p));
	    exit(1);
	}

	if (pdfalevel)
	{
	    int res;

	    /* Use intent from the first PDF if none specified */
	    if (!intent)
		intent = argv[optind];

	    if (!quiet)
		fprintf(stderr, "Using output intent from file '%s'.\n",
		    intent);

	    if ((doc = PDF_open_pdi_document(p, intent, 0, "infomode")) == -1)
	    {
		if (!quiet)
		    fprintf(stderr, "Error: %s.\n", PDF_get_errmsg(p));
		exit(99);
	    }

	    res = (int) PDF_pcos_get_number(p, doc, "type:/Root/OutputIntents");

	    if (res == pcos_ot_array)
	    {
		res = PDF_process_pdi(p, doc, 0, "action=copyoutputintent");
		if (res == -1)
		{
		    if (!quiet)
			fprintf(stderr, "Error: %s.\n", PDF_get_errmsg(p));
		    exit(99);
		}
		PDF_close_pdi_document(p, doc);
	    }
	    else
	    {
		fprintf(stderr,
		    "No output intent found.\n");
	    }
	}

	PDF_set_info(p, "Creator", "pdfimpose by PDFlib GmbH");

	PDF_set_parameter(p, "openaction", "fitpage");

	/* multi-page imposition: calculate scaling factor and cell dimensions*/
	if (rows != 1 || cols != 1)
	{
	    if (landscape)
	    {
		height = sheetheight;
		sheetheight = sheetwidth;
		sheetwidth = height;
	    }

	    if (rows > cols)
		scale = 1.0f / rows;
	    else
		scale = 1.0f / cols;

	    rowheight = sheetheight * scale;
	    colwidth = sheetwidth * scale;
	}

	/* process all PDF documents */
	while (optind++ < argc)
	{
	    filename = argv[optind-1];

	    if (!quiet)
		fprintf(stderr, "Imposing '%s'...\n", filename);

	    if ((doc = PDF_open_pdi_document(p, filename, 0, "")) == -1)
	    {
		if (!quiet)
		    fprintf(stderr, "Error: %s.\n", PDF_get_errmsg(p));
		continue;
	    }

	    /* query number of pages in the document */
	    docpages = (int) PDF_pcos_get_number(p, doc, "/Root/Pages/Count");

	    /* single cell only: concatenate */
	    if (rows == 1 && cols == 1)
	    {
		/* open all pages and add to the output file */
		for (pageno = 1; pageno <= docpages ; pageno++)
		{

		    page = PDF_open_pdi_page(p, doc, pageno, "");

		    if (page == -1)
		    {
			if (!quiet)
			    fprintf(stderr, "Couldn't open page %d (%s)\n",
				pageno, PDF_get_errmsg(p));
			break;
		    }

		    sheetwidth = PDF_pcos_get_number(p, doc,
				    "pages[%d]/width", pageno-1);
		    sheetheight = PDF_pcos_get_number(p, doc,
				    "pages[%d]/height", pageno-1);

		    optlist[0] = 0;

		    if (pagesize)
		    {
			sprintf(optlist, landscape ?
				"width=%s.height height=%s.width " :
				"width=%s.width height=%s.height ",
				pagesize, pagesize);
		    }

		    PDF_begin_page_ext(p, sheetwidth, sheetheight, optlist);

		    /* define bookmark with filename */
		    if (pageno == 1)
			PDF_create_bookmark(p, argv[optind-1], 0, "");

		    PDF_fit_pdi_page(p, page, 0.0f, 0.0f, "");
		    PDF_close_pdi_page(p, page);
		    PDF_end_page_ext(p, "");
		}

	    }
	    else
	    {		/* impose multiple pages */

		if (newpage)
		    r = c = 0;

		/* open all pages and add to the output file */
		for (pageno = 1; pageno <= docpages ; pageno++) {

		    page = PDF_open_pdi_page(p, doc, pageno, "");

		    if (page == -1)
		    {
			if (!quiet)
			    fprintf(stderr, "Couldn't open page %d (%s)\n",
				pageno, PDF_get_errmsg(p));
			break;
		    }

		    /* start a new page */
		    if (r == 0 && c == 0)
			PDF_begin_page_ext(p, sheetwidth, sheetheight, "");

		    /* define bookmark with filename */
		    if (pageno == 1)
			PDF_create_bookmark(p, argv[optind-1], 0, "");

		    width = PDF_pcos_get_number(p, doc,
				    "pages[%d]/width", pageno-1);
		    height = PDF_pcos_get_number(p, doc,
				    "pages[%d]/height", pageno-1);

		    /*
		     * The save/restore pair is required to get the clipping
		     * right, and helps PostScript printing manage its memory
		     * efficiently.
		     */
		    PDF_save(p);
		    PDF_rect(p, c * colwidth, sheetheight - (r + 1) * rowheight,
			colwidth, rowheight);
		    PDF_clip(p);

		    if (pdfalevel)
			PDF_setcolor(p,"stroke", "lab", 0.0f, 0.0f, 0.0f, 0.0f);
		    else
			PDF_setcolor(p,"stroke","gray", 0.0f, 0.0f, 0.0f, 0.0f);

		    sprintf(optlist,
			    "boxsize {%f %f} position 0 fitmethod meet",
			    colwidth, rowheight);

		    PDF_fit_pdi_page(p, page,
			c * colwidth, sheetheight - (r + 1) * rowheight,
			optlist);

		    PDF_close_pdi_page(p, page);

		    /* only half of the linewidth will be drawn due to clip() */
		    if (boxes) {
			PDF_setlinewidth(p, 1.0f * scale);
			PDF_rect(p, c * colwidth,
			    sheetheight - (r + 1) * rowheight,
			    colwidth, rowheight);
			PDF_stroke(p);
		    }

		    PDF_restore(p);

		    c++;
		    if (c == cols)
		    {
			c = 0;
			r++;
		    }
		    if (r == rows)
		    {
			r = 0;
			PDF_end_page_ext(p, "");
		    }
		}
	    }

	    PDF_close_pdi_document(p, doc);
	}

	/* finish last page if multi-page imposition */
	if ((rows != 1 || cols != 1) && (r != 0 || c != 0))
	    PDF_end_page_ext(p, "");

	PDF_end_document(p, "");
    }

    PDF_CATCH(p)
    {
        printf("\npdfimpose: error while creating PDF output (%s(): %s)\n",
		PDF_get_apiname(p), PDF_get_errmsg(p));
        PDF_delete(p);
        exit(99);
    }

    PDF_delete(p);
    exit(0);
}
