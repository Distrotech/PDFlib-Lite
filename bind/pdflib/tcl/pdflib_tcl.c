/*---------------------------------------------------------------------------*
 |              PDFlib - A library for generating PDF on the fly             |
 +---------------------------------------------------------------------------+
 | Copyright (c) 1997-2005 Thomas Merz and PDFlib GmbH. All rights reserved. |
 +---------------------------------------------------------------------------+
 |                                                                           |
 |    This software is subject to the PDFlib license. It is NOT in the       |
 |    public domain. Extended versions and commercial licenses are           |
 |    available, please check http://www.pdflib.com.                         |
 |                                                                           |
 *---------------------------------------------------------------------------*/

/* $Id: pdflib_tcl.c,v 1.56.2.3 2009/04/21 10:35:23 rjs Exp $
 *
 * in sync with pdflib.h 1.151.2.22
 *
 * Wrapper code for the PDFlib Tcl binding
 *
 */

/*
 * Build with STUBS enabled
 *
 * if building with older TCL Versions than 8.2 you have to undef this
 */
#define USE_TCL_STUBS

#include <tcl.h>

#include <string.h>
#include <stdlib.h>

#if defined(__WIN32__)
#   define WIN32_LEAN_AND_MEAN
#   include <windows.h>
#   undef WIN32_LEAN_AND_MEAN

#   if defined(__WIN32__) && \
	(defined(_MSC_VER) || (defined(__GNUC__) && defined(__declspec)))
#	define SWIGEXPORT(a,b) __declspec(dllexport) a b
#   else
#	if defined(__BORLANDC__)
#	    define SWIGEXPORT(a,b) a _export b
#	else
#	    define SWIGEXPORT(a,b) a b
#	endif
#   endif
#else
#   define SWIGEXPORT(a,b) a b
#endif

#include <stdlib.h>

#ifdef SWIG_GLOBAL
#ifdef __cplusplus
#define SWIGSTATIC extern "C"
#else
#define SWIGSTATIC
#endif
#endif

#ifndef SWIGSTATIC
#define SWIGSTATIC static
#endif

/* SWIG pointer structure */

typedef struct SwigPtrType {
  char               *name;               /* Datatype name                  */
  int               len;                /* Length (used for optimization) */
  void               *(*cast)(void *);    /* Pointer casting function       */
  struct SwigPtrType *next;               /* Linked list pointer            */
} SwigPtrType;

/* Pointer cache structure */

typedef struct {
  int               stat;               /* Status (valid) bit             */
  SwigPtrType        *tp;                 /* Pointer to type structure      */
  char                name[256];          /* Given datatype name            */
  char                mapped[256];        /* Equivalent name                */
} SwigCacheType;

/* Some variables  */

static int SwigPtrMax  = 64;       /* Max entries that can be currently held */
                                   /* This value may be adjusted dynamically */
static int SwigPtrN    = 0;        /* Current number of entries              */
static int SwigPtrSort = 0;        /* Status flag indicating sort            */
static int SwigStart[256];         /* Starting positions of types            */

/* Pointer table */
static SwigPtrType *SwigPtrTable = 0;
                                   /* Table containing pointer equivalences  */

/* Cached values */

#define SWIG_CACHESIZE  8
#define SWIG_CACHEMASK  0x7
static SwigCacheType SwigCache[SWIG_CACHESIZE];
static int SwigCacheIndex = 0;
static int SwigLastCache = 0;

/* Sort comparison function */
static int swigsort(const void *data1, const void *data2) {
	SwigPtrType *d1 = (SwigPtrType *) data1;
	SwigPtrType *d2 = (SwigPtrType *) data2;
	return strcmp(d1->name,d2->name);
}

/* Binary Search function */
static int swigcmp(const void *key, const void *data) {
  char *k = (char *) key;
  SwigPtrType *d = (SwigPtrType *) data;
  return strncmp(k,d->name,d->len);
}

/* Register a new datatype with the type-checker */

SWIGSTATIC
void SWIG_RegisterMapping(char *origtype, char *newtype, void *(*cast)(void *))
{

  int i;
  SwigPtrType *t = 0,*t1;

  /* Allocate the pointer table if necessary */

  if (!SwigPtrTable) {
    SwigPtrTable = (SwigPtrType *) malloc(SwigPtrMax*sizeof(SwigPtrType));
    SwigPtrN = 0;
  }
  /* Grow the table */
  if (SwigPtrN >= SwigPtrMax) {
    SwigPtrMax = 2*SwigPtrMax;
    SwigPtrTable = (SwigPtrType *)
        realloc((char *) SwigPtrTable,SwigPtrMax*sizeof(SwigPtrType));
  }
  for (i = 0; i < SwigPtrN; i++)
    if (strcmp(SwigPtrTable[i].name,origtype) == 0) {
      t = &SwigPtrTable[i];
      break;
    }
  if (!t) {
    t = &SwigPtrTable[SwigPtrN];
    t->name = origtype;
    t->len = strlen(t->name);
    t->cast = 0;
    t->next = 0;
    SwigPtrN++;
  }

  /* Check for existing entry */

  while (t->next) {
    if ((strcmp(t->name,newtype) == 0)) {
      if (cast) t->cast = cast;
      return;
    }
    t = t->next;
  }

  /* Now place entry (in sorted order) */

  t1 = (SwigPtrType *) malloc(sizeof(SwigPtrType));
  t1->name = newtype;
  t1->len = strlen(t1->name);
  t1->cast = cast;
  t1->next = 0;
  t->next = t1;
  SwigPtrSort = 0;
}

/* Make a pointer value string */

SWIGSTATIC
void SWIG_MakePtr(char *_c, const void *_ptr, char *type) {
  static char _hex[16] =
  {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
   'a', 'b', 'c', 'd', 'e', 'f'};
  unsigned long _p, _s;
  char _result[20], *_r;    /* Note : a 64-bit hex number = 16 digits */
  _r = _result;
  _p = (unsigned long) _ptr;
  if (_p > 0) {
    while (_p > 0) {
      _s = _p & 0xf;
      *(_r++) = _hex[_s];
      _p = _p >> 4;
    }
    *_r = '_';
    while (_r >= _result)
      *(_c++) = *(_r--);
  } else {
    strcpy (_c, "NULL");
  }
  if (_ptr)
    strcpy (_c, type);
}

/* Function for getting a pointer value */

SWIGSTATIC
char *SWIG_GetPtr(char *_c, void **ptr, char *_t)
{
  unsigned long _p;
  char temp_type[256];
  char *name;
  int i, len;
  SwigPtrType *sp,*tp;
  SwigCacheType *cache;
  int start, end;
  _p = 0;

  /* Pointer values must start with leading underscore */
  if (*_c == '_') {
      _c++;
      /* Extract hex value from pointer */
      while (*_c) {
	  if ((*_c >= '0') && (*_c <= '9'))
	    _p = (_p << 4) + (*_c - '0');
	  else if ((*_c >= 'a') && (*_c <= 'f'))
	    _p = (_p << 4) + ((*_c - 'a') + 10);
	  else
	    break;
	  _c++;
      }

      if (_t) {
	if (strcmp(_t,_c)) {
	  if (!SwigPtrSort) {
	    qsort((void *) SwigPtrTable, SwigPtrN, sizeof(SwigPtrType),
                  swigsort);
	    for (i = 0; i < 256; i++) {
	      SwigStart[i] = SwigPtrN;
	    }
	    for (i = SwigPtrN-1; i >= 0; i--) {
	      SwigStart[(int) (SwigPtrTable[i].name[1])] = i;
	    }
	    for (i = 255; i >= 1; i--) {
	      if (SwigStart[i-1] > SwigStart[i])
		SwigStart[i-1] = SwigStart[i];
	    }
	    SwigPtrSort = 1;
	    for (i = 0; i < SWIG_CACHESIZE; i++)
	      SwigCache[i].stat = 0;
	  }

	  /* First check cache for matches.
           * Uses last cache value as starting point */
	  cache = &SwigCache[SwigLastCache];
	  for (i = 0; i < SWIG_CACHESIZE; i++) {
	    if (cache->stat) {
	      if (strcmp(_t,cache->name) == 0) {
		if (strcmp(_c,cache->mapped) == 0) {
		  cache->stat++;
		  *ptr = (void *) _p;
		  if (cache->tp->cast) *ptr = (*(cache->tp->cast))(*ptr);
		  return (char *) 0;
		}
	      }
	    }
	    SwigLastCache = (SwigLastCache+1) & SWIG_CACHEMASK;
	    if (!SwigLastCache) cache = SwigCache;
	    else cache++;
	  }
	  /* We have a type mismatch.  Will have to look through our type
	   * mapping table to figure out whether or not we can accept this
           * datatype */

	  start = SwigStart[(int) _t[1]];
	  end = SwigStart[(int) _t[1]+1];
	  sp = &SwigPtrTable[start];
	  while (start < end) {
	    if (swigcmp(_t,sp) == 0) break;
	    sp++;
	    start++;
	  }
	  if (start >= end) sp = 0;
	  /* Try to find a match for this */
	  if (sp) {
	    while (swigcmp(_t,sp) == 0) {
	      name = sp->name;
	      len = sp->len;
	      tp = sp->next;
	      /* Try to find entry for our given datatype */
	      while(tp) {
		if (tp->len >= 255) {
		  return _c;
		}
		strcpy(temp_type,tp->name);
		strncat(temp_type,_t+len,255-tp->len);
		if (strcmp(_c,temp_type) == 0) {

		  strcpy(SwigCache[SwigCacheIndex].mapped,_c);
		  strcpy(SwigCache[SwigCacheIndex].name,_t);
		  SwigCache[SwigCacheIndex].stat = 1;
		  SwigCache[SwigCacheIndex].tp = tp;
		  SwigCacheIndex = SwigCacheIndex & SWIG_CACHEMASK;

		  /* Get pointer value */
		  *ptr = (void *) _p;
		  if (tp->cast) *ptr = (*(tp->cast))(*ptr);
		  return (char *) 0;
		}
		tp = tp->next;
	      }
	      sp++;
	      /* Hmmm. Didn't find it this time */
	    }
	  }
	  /* Didn't find any sort of match for this data.
	     Get the pointer value and return the received type */
	  *ptr = (void *) _p;
	  return _c;
	} else {
	  /* Found a match on the first try.  Return pointer value */
	  *ptr = (void *) _p;
	  return (char *) 0;
	}
      } else {
	/* No type specified.  Good luck */
	*ptr = (void *) _p;
	return (char *) 0;
      }
  } else {
    if (strcmp (_c, "NULL") == 0) {
	*ptr = (void *) 0;
	return (char *) 0;
    }
    *ptr = (void *) 0;
    return _c;
  }
}

#ifdef __cplusplus
extern "C" {
#endif
SWIGEXPORT(int,Pdflib_Init)(Tcl_Interp *);
SWIGEXPORT(int,Pdflib_SafeInit)(Tcl_Interp *);
SWIGEXPORT(int,Pdflib_tcl_SafeInit)(Tcl_Interp *);
SWIGEXPORT(int,Pdflib_tcl_Init)(Tcl_Interp *);
SWIGEXPORT(int,Pdf_tcl_Init)(Tcl_Interp *);
SWIGEXPORT(int,Pdf_tcl_SafeInit)(Tcl_Interp *);
#ifdef __cplusplus
}
#endif

#include <setjmp.h>

#if _MSC_VER >= 1310    /* VS .NET 2003 and later */
/* pdflib.h declares some functions as deprecated, but we don't want to see
 * these warnings here */
#pragma warning(disable: 4995)
#endif

#include "pdflib.h"

/* Exception handling */

#define try	PDF_TRY(p)
#define catch	PDF_CATCH(p) {\
		char errmsg[1024];\
		sprintf(errmsg, "PDFlib Error [%d] %s: %s", PDF_get_errnum(p),\
		    PDF_get_apiname(p), PDF_get_errmsg(p));\
		Tcl_SetResult(interp, errmsg, TCL_STATIC);\
		    return TCL_ERROR;			\
	    }


/*
 * String handling
 */

#define PDF_0BYTES 0
#define PDF_BYTES  1
#define PDF_UTF8   2
#define PDF_UTF16  3
#define PDF_0UTF16 4
#define PDF_DATA   5

static const char *
PDF_GetStringFromObj(PDF *p, Tcl_Interp *interp, Tcl_Obj *objPtr, int key,
                     int *len)
{
    Tcl_UniChar *unistring = NULL;

    *len = 0;

    if (objPtr != NULL)
    {
        switch (key)
        {
            case PDF_DATA:
            return (const char *) Tcl_GetByteArrayFromObj(objPtr, len);

            case PDF_0BYTES:
            case PDF_BYTES:
            return (const char *) Tcl_GetStringFromObj(objPtr, len);

            case PDF_UTF8:
            case PDF_UTF16:
            case PDF_0UTF16:
            unistring = Tcl_GetUnicode(objPtr);
            if (unistring)
            {
                *len = 2 * Tcl_UniCharLen(unistring);
                if (key == PDF_UTF8)
                   return PDF_utf16_to_utf8(p, (char *) unistring, *len, len);
                return (const char *) unistring;
            }
        }
    }

    return NULL;
}

static void
PDF_WrongCommand(Tcl_Interp *interp, const char *vartext)
{
    char text[128];

    sprintf(text, "Wrong # args. %s", vartext);
    Tcl_SetResult(interp, text, TCL_STATIC);
}

static void
PDF_NoPDFHandle(Tcl_Interp *interp, const char *vartext)
{
    char text[128];

    sprintf(text, "Couldn't retrieve PDF handle in %s", vartext);
    Tcl_SetResult(interp, text, TCL_STATIC);
}

static void
PDF_WrongPDFHandle(Tcl_Interp *interp, const char *vartext)
{
    char text[128];

    sprintf(text, "Wrong PDF handle in %s", vartext);
    Tcl_SetResult(interp, text, TCL_STATIC);
}

static void
PDF_WrongParameter(Tcl_Interp *interp, const char *vartext)
{
    char text[128];

    sprintf(text, "Wrong parameter %s", vartext);
    Tcl_SetResult(interp, text, TCL_STATIC);
}

static int
_wrap_PDF_open_pdi(ClientData clientData, Tcl_Interp *interp, int objc,
                Tcl_Obj *CONST objv[])
{
    PDF *p;
    const char *filename;
    int filename_len;
    const char *optlist;
    int optlist_len;
    char *res;
    int volatile _result = -1;

    if (objc != 4 && objc != 5)  /* downward compatibility */
    {
        PDF_WrongCommand(interp, "PDF_open_pdi p filename optlist ");
        return TCL_ERROR;
    }

    if ((res = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
        PDF_NoPDFHandle(interp, "PDF_open_pdi");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(res, (void **) &p, "_PDF_p"))
    {
        PDF_WrongPDFHandle(interp, "PDF_open_pdi");
        Tcl_AppendResult(interp, res, (char *) NULL);
        return TCL_ERROR;
    }

    if ((filename = PDF_GetStringFromObj(p, interp, objv[2], PDF_0UTF16,
                        &filename_len)) == NULL)
    {
        PDF_WrongParameter(interp, "filename in PDF_open_pdi");
        return TCL_ERROR;
    }

    if ((optlist = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8,
                        &optlist_len)) == NULL)
    {
        PDF_WrongParameter(interp, "optlist in PDF_open_pdi");
        return TCL_ERROR;
    }

    try { _result = (int) PDF_open_pdi(p, filename, optlist, filename_len);
    } catch;

    sprintf(interp->result, "%d", _result);
    return TCL_OK;
}

static int
_wrap_PDF_delete(ClientData clientData, Tcl_Interp *interp, int objc,
                Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *res;

    if (objc != 2)
    {
        PDF_WrongCommand(interp, "PDF_delete p ");
        return TCL_ERROR;
    }

    if ((res = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
        PDF_NoPDFHandle(interp, "PDF_delete");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(res, (void **) &p, "_PDF_p"))
    {
        PDF_WrongPDFHandle(interp, "PDF_delete");
        Tcl_AppendResult(interp, res, (char *) NULL);
        return TCL_ERROR;
    }

    PDF_delete(p);

    return TCL_OK;
}

static int
_wrap_PDF_new(ClientData clientData, Tcl_Interp *interp, int objc,
                Tcl_Obj *CONST objv[])
{
    PDF *p;

    if (objc != 1)
    {
        PDF_WrongCommand(interp, "PDF_new ");
        return TCL_ERROR;
    }

    p = (PDF *) PDF_new();
    if (p != NULL)
    {
        int major, minor, type, patchlevel;
        char versionbuf[32];

        Tcl_GetVersion(&major, &minor, &patchlevel, &type);
        sprintf(versionbuf, "Tcl %d.%d%c%d", major, minor,
                "ab."[type], patchlevel);

        PDF_set_parameter(p, "binding", versionbuf);
        PDF_set_parameter(p, "unicaplang", "true");
        PDF_set_parameter(p, "textformat", "auto2");
        PDF_set_parameter(p, "hypertextformat", "auto2");
        PDF_set_parameter(p, "hypertextencoding", "");

        SWIG_MakePtr(interp->result, (void *) p, "_PDF_p");
    }
    else
    {
        Tcl_SetResult(interp, "Couldn't create PDF handle", TCL_STATIC);
    }

    return TCL_OK;
}

static int
_wrap_PDF_open_image(ClientData clientData, Tcl_Interp *interp, int objc,
                        Tcl_Obj *CONST objv[])
{
    PDF *p;
    const char *imagetype;
    int imagetype_len;
    const char *source;
    int source_len;
    const char *data;
    int data_len;
    long length;
    int width;
    int height;
    int components;
    int bpc;
    const char *params;
    int params_len;
    char *res;
    int volatile _result = -1;

    if (objc != 11)
    {
        PDF_WrongCommand(interp, "PDF_open_image p imagetype source "
                         "data length width height components bpc params ");
        return TCL_ERROR;
    }

    if ((res = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
        PDF_NoPDFHandle(interp, "PDF_open_image");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(res, (void **) &p, "_PDF_p"))
    {
        PDF_WrongPDFHandle(interp, "PDF_open_image");
        Tcl_AppendResult(interp, res, (char *) NULL);
        return TCL_ERROR;
    }

    if ((imagetype = PDF_GetStringFromObj(p, interp, objv[2], PDF_BYTES,
                        &imagetype_len)) == NULL)
    {
        PDF_WrongParameter(interp, "imagetype in PDF_open_image");
        return TCL_ERROR;
    }

    if ((source = PDF_GetStringFromObj(p, interp, objv[3], PDF_BYTES,
                        &source_len)) == NULL)
    {
        PDF_WrongParameter(interp, "source in PDF_open_image");
        return TCL_ERROR;
    }

    if ((data = Tcl_GetByteArrayFromObj(objv[4], &data_len)) == NULL)
    {
        PDF_WrongParameter(interp, "data in PDF_open_image");
        return TCL_ERROR;
    }

    if (Tcl_GetLongFromObj(interp, objv[5], &length) != TCL_OK)
    {
        PDF_WrongParameter(interp, "length in PDF_open_image");
        return TCL_ERROR;
    }

    if (Tcl_GetIntFromObj(interp, objv[6], &width) != TCL_OK)
    {
        PDF_WrongParameter(interp, "width in PDF_open_image");
        return TCL_ERROR;
    }

    if (Tcl_GetIntFromObj(interp, objv[7], &height) != TCL_OK)
    {
        PDF_WrongParameter(interp, "height in PDF_open_image");
        return TCL_ERROR;
    }

    if (Tcl_GetIntFromObj(interp, objv[8], &components) != TCL_OK)
    {
        PDF_WrongParameter(interp, "components in PDF_open_image");
        return TCL_ERROR;
    }

    if (Tcl_GetIntFromObj(interp, objv[9], &bpc) != TCL_OK)
    {
        PDF_WrongParameter(interp, "bpc in PDF_open_image");
        return TCL_ERROR;
    }

    if ((params = PDF_GetStringFromObj(p, interp, objv[10], PDF_BYTES,
                        &params_len)) == NULL)
    {
        PDF_WrongParameter(interp, "params in PDF_open_image");
        return TCL_ERROR;
    }

    try { _result = (int) PDF_open_image(p, imagetype, source, data,
                        length, width, height, components, bpc, params);
    } catch;

    sprintf(interp->result, "%d", _result);
    return TCL_OK;
}

static int
_wrap_PDF_setpolydash(ClientData clientData, Tcl_Interp *interp, int objc,
                        Tcl_Obj *CONST objv[])
{
    PDF *p;
    float *dasharray;
    int length;
    char *res;
    float *carray;
    double dval;
    int i;
    Tcl_Obj *val;

    if (objc != 3)
    {
        PDF_WrongCommand(interp, "PDF_setpolydash p dasharray ");
        return TCL_ERROR;
    }

    if ((res = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
        PDF_NoPDFHandle(interp, "PDF_setpolydash");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(res, (void **) &p, "_PDF_p"))
    {
        PDF_WrongPDFHandle(interp, "PDF_setpolydash");
        Tcl_AppendResult(interp, res, (char *) NULL);
        return TCL_ERROR;
    }

    if (Tcl_ListObjLength(interp, objv[2], &length) != TCL_OK) {
        PDF_WrongParameter(interp, "length in PDF_setpolydash");
        return TCL_ERROR;
    }

    carray = (float *) malloc(sizeof(float) * length);
    if (carray == NULL)
    {
        Tcl_SetResult(interp, "Out of memory in PDF_setpolydash", TCL_STATIC);
        return TCL_ERROR;
    }

    for (i = 0; i < length; i++)
    {
        if (Tcl_ListObjIndex(interp, objv[2], i, &val) != TCL_OK ||
            Tcl_GetDoubleFromObj(interp, val, &dval) != TCL_OK)
        {
            PDF_WrongParameter(interp, "array value in PDF_setpolydash");
            return TCL_ERROR;
        }
        carray[i] = (float) dval;
    }

    try { PDF_setpolydash(p, carray, length);
    } catch;

    free(carray);

    return TCL_OK;
}


static int
_wrap_PDF_show_boxed(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * text = NULL;
    int text_len;
    double left;
    double top;
    double width;
    double height;
    const char * hmode = NULL;
    int hmode_len;
    const char * feature = NULL;
    int feature_len;
    int volatile _retval = -1;

    if (objc != 9)
    {
	PDF_WrongCommand(interp,
                "PDF_show_boxed p text left top width height hmode feature");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_show_boxed");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_show_boxed");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((text = PDF_GetStringFromObj(p, interp, objv[2], PDF_UTF16, &text_len))
                        == NULL)
    {
	PDF_WrongParameter(interp, "text in PDF_show_boxed");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &left) != TCL_OK)
    {
	PDF_WrongParameter(interp, "left in PDF_show_boxed");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &top) != TCL_OK)
    {
	PDF_WrongParameter(interp, "top in PDF_show_boxed");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &width) != TCL_OK)
    {
	PDF_WrongParameter(interp, "width in PDF_show_boxed");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[6], &height) != TCL_OK)
    {
	PDF_WrongParameter(interp, "height in PDF_show_boxed");
	return TCL_ERROR;
    }
    if ((hmode = PDF_GetStringFromObj(p, interp, objv[7], PDF_BYTES,
                        &hmode_len)) == NULL)
    {
	PDF_WrongParameter(interp, "hmode in PDF_show_boxed");
	return TCL_ERROR;
    }
    if ((feature = PDF_GetStringFromObj(p, interp, objv[8], PDF_BYTES,
                        &feature_len)) == NULL)
    {
	PDF_WrongParameter(interp, "feature in PDF_show_boxed");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_show_boxed2(p, text, text_len, left, top, width, height,
                                hmode, feature);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}



#define _WRAP_CODE
#include "tcl_wrapped.c"
#undef _WRAP_CODE


/* This is required to make our extension work with safe Tcl interpreters */
SWIGEXPORT(int,Pdflib_SafeInit)(Tcl_Interp *interp)
{
    return TCL_OK;
}

/* This is required to satisfy pkg_mkIndex */
SWIGEXPORT(int,Pdflib_tcl_SafeInit)(Tcl_Interp *interp)
{
    return Pdflib_SafeInit(interp);
}

/* This is required to satisfy pkg_mkIndex */
SWIGEXPORT(int,Pdflib_tcl_Init)(Tcl_Interp *interp)
{
    return Pdflib_Init(interp);
}

/* This is required to satisfy pkg_mkIndex */
SWIGEXPORT(int,Pdf_tcl_Init)(Tcl_Interp *interp)
{
    return Pdflib_Init(interp);
}

/* This is required to satisfy pkg_mkIndex */
SWIGEXPORT(int,Pdf_tcl_SafeInit)(Tcl_Interp *interp)
{
    return Pdflib_SafeInit(interp);
}

SWIGEXPORT(int,Pdflib_Init)(Tcl_Interp *interp)
{
    char short_version[6];

    strncpy(short_version, PDFLIB_VERSIONSTRING, 5);
    short_version[5] = 0;

    if (interp == 0)
	return TCL_ERROR;

#ifdef USE_TCL_STUBS
    if (Tcl_InitStubs(interp, "8.2", 0) == NULL) {
 	return TCL_ERROR;
    }
#else
    if (Tcl_PkgRequire(interp, "Tcl", TCL_VERSION, 1) == NULL) {
 	return TCL_ERROR;
    }
#endif

    /* Tell Tcl which package we are going to define */
    Tcl_PkgProvide(interp, "pdflib", short_version);

    Tcl_CreateObjCommand(interp, "PDF_open_pdi",
                (Tcl_ObjCmdProc*) _wrap_PDF_open_pdi,
                (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);

    Tcl_CreateObjCommand(interp, "PDF_show_boxed", (Tcl_ObjCmdProc*)
	_wrap_PDF_show_boxed, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);

#define _WRAP_METHODS
#include "tcl_wrapped.c"
#undef _WRAP_METHODS


/*
 * These are the pointer type-equivalency mappings.
 * (Used by the SWIG pointer type-checker).
 */
    SWIG_RegisterMapping("_signed_long","_long",0);
    SWIG_RegisterMapping("_struct_PDF_s","_PDF",0);
    SWIG_RegisterMapping("_long","_unsigned_long",0);
    SWIG_RegisterMapping("_long","_signed_long",0);
    SWIG_RegisterMapping("_PDF","_struct_PDF_s",0);
    SWIG_RegisterMapping("_unsigned_long","_long",0);
    SWIG_RegisterMapping("_signed_int","_int",0);
    SWIG_RegisterMapping("_unsigned_short","_short",0);
    SWIG_RegisterMapping("_signed_short","_short",0);
    SWIG_RegisterMapping("_unsigned_int","_int",0);
    SWIG_RegisterMapping("_short","_unsigned_short",0);
    SWIG_RegisterMapping("_short","_signed_short",0);
    SWIG_RegisterMapping("_int","_unsigned_int",0);
    SWIG_RegisterMapping("_int","_signed_int",0);
    return TCL_OK;
}
