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

/* $Id: pdflib_pl.c,v 1.52.2.6 2010/03/31 21:38:00 rjs Exp $
 *
 * Wrapper code for the PDFlib Perl binding
 *
 */
#undef PERL_IMPLICIT_SYS 

/* some defines for SWIG {{{ */
/*
 * The PERL_OBJECT #define is only required for ActivePerl < 5.6
 *
 * IMPORTANT: in this case the code must be compiled in C++ mode!
 */
#if defined(WIN32) && \
	defined(PERL_REVISION) && defined(PERL_VERSION) && \
	PERL_REVISION == 5 && PERL_VERSION < 6
#define PERL_OBJECT
#endif

#ifdef __cplusplus
#include <math.h>
#include <stdlib.h>

extern "C" {
#endif /* __cplusplus */

#undef DEBUG
#include <EXTERN.h>
#include <perl.h>
#include <XSUB.h>
/*#undef free
#undef malloc
*/
#include <string.h>

#ifdef __cplusplus
}
#endif /* __cplusplus */

/* Compilers which are not strictly ANSI conforming can set PDF_VOLATILE
 * to an empty value.
 */
#ifndef PDF_VOLATILE
#define PDF_VOLATILE    volatile
#endif

/* Definitions for compiling Perl extensions on a variety of machines */

#if defined(WIN32) || defined(__WIN32__)
#   if defined(_MSC_VER)
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

/* #defines for older Perl versions < 5.005_50 */
#if !defined(PERL_REVISION) || \
	((PERL_REVISION >= 5) && \
	((PERL_VERSION<5) || ((PERL_VERSION==5) && (PERL_SUBVERSION<50))))
#ifndef PL_sv_yes
#define PL_sv_yes sv_yes
#endif
#ifndef PL_na
#define PL_na na
#endif
#endif

#ifdef PERL_OBJECT
#define MAGIC_PPERL  CPerlObj *pPerl = (CPerlObj *) this;
#define MAGIC_CAST   (int (CPerlObj::*)(SV *, MAGIC *))
#define SWIGCLASS_STATIC
#else
#define MAGIC_PPERL
#define MAGIC_CAST
#define SWIGCLASS_STATIC static
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
/* }}} */

/* Swig data structures {{{ */
typedef struct SwigPtrType {
  char               *name;
  int               len;
  void               *(*cast)(void *);
  struct SwigPtrType *next;
} SwigPtrType;

/* Pointer cache structure */
typedef struct {
  int               stat;               /* Status (valid) bit             */
  SwigPtrType        *tp;                 /* Pointer to type structure      */
  char                name[256];          /* Given datatype name            */
  char                mapped[256];        /* Equivalent name                */
} SwigCacheType;

static int SwigPtrMax  = 64;	/* Max entries that can be currently held */
static int SwigPtrN    = 0;	/* Current number of entries              */
static int SwigPtrSort = 0;	/* Status flag indicating sort            */
static SwigPtrType *SwigPtrTable = 0;  /* Table containing pointer equivalences  */
static int SwigStart[256];	/* Table containing starting positions    */

/* Cached values */
#define SWIG_CACHESIZE  8
#define SWIG_CACHEMASK  0x7
static SwigCacheType SwigCache[SWIG_CACHESIZE];
static int SwigCacheIndex = 0;
static int SwigLastCache = 0;
/* }}} */

/* swig helper functions {{{ */
/* Sort comparison function {{{ */
static int swigsort(const void *data1, const void *data2) {
	SwigPtrType *d1 = (SwigPtrType *) data1;
	SwigPtrType *d2 = (SwigPtrType *) data2;
	return strcmp(d1->name,d2->name);
}
/* }}} */

/* Binary Search function {{{ */
static int swigcmp(const void *key, const void *data) {
  char *k = (char *) key;
  SwigPtrType *d = (SwigPtrType *) data;
  return strncmp(k,d->name,d->len);
}
/* }}} */

/* Register a new datatype with the type-checker {{{ */

#ifndef PERL_OBJECT
SWIGSTATIC
void SWIG_RegisterMapping(char *origtype, char *newtype, void *(*cast)(void *)) {
#else
SWIGSTATIC
#define SWIG_RegisterMapping(a,b,c) _SWIG_RegisterMapping(pPerl, a,b,c)
void _SWIG_RegisterMapping(CPerlObj *pPerl, char *origtype, char *newtype, void *(*cast)(void *)) {
#endif

  int i;
  SwigPtrType *t = 0, *t1;

  if (!SwigPtrTable) {
    SwigPtrTable = (SwigPtrType *) malloc(SwigPtrMax*sizeof(SwigPtrType));
    SwigPtrN = 0;
  }
  if (SwigPtrN >= SwigPtrMax) {
    SwigPtrMax = 2*SwigPtrMax;
    SwigPtrTable = (SwigPtrType *) realloc(SwigPtrTable,SwigPtrMax*sizeof(SwigPtrType));
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
  while (t->next) {
    if (strcmp(t->name,newtype) == 0) {
      if (cast) t->cast = cast;
      return;
    }
    t = t->next;
  }
  t1 = (SwigPtrType *) malloc(sizeof(SwigPtrType));
  t1->name = newtype;
  t1->len = strlen(t1->name);
  t1->cast = cast;
  t1->next = 0;
  t->next = t1;
  SwigPtrSort = 0;
}

/* Function for getting a pointer value */

#ifndef PERL_OBJECT
SWIGSTATIC
char *SWIG_GetPtr(SV *sv, void **ptr, char *_t)
#else
SWIGSTATIC
#define SWIG_GetPtr(a,b,c) _SWIG_GetPtr(pPerl,a,b,c)
char *_SWIG_GetPtr(CPerlObj *pPerl, SV *sv, void **ptr, char *_t)
#endif
{
  char temp_type[256];
  char *name,*_c;
  int len,i,start,end;
  IV   tmp = 0;
  SwigPtrType *sp,*tp;
  SwigCacheType *cache;

  /* If magical, apply more magic */

  if (SvGMAGICAL(sv))
    mg_get(sv);

  /* Check to see if this is an object */
  if (sv_isobject(sv)) {
    SV *tsv = (SV*) SvRV(sv);
    if ((SvTYPE(tsv) == SVt_PVHV)) {
      MAGIC *mg;
      if (SvMAGICAL(tsv)) {
	mg = mg_find(tsv,'P');
	if (mg) {
	  SV *rsv = mg->mg_obj;
	  if (sv_isobject(rsv)) {
	    tmp = SvIV((SV*)SvRV(rsv));
	  }
	}
      } else {
	return "Not a valid pointer value";
      }
    } else {
      tmp = SvIV((SV*)SvRV(sv));
    }
    if (!_t) {
      *(ptr) = (void *) tmp;
      return (char *) 0;
    }
  } else if (! SvOK(sv)) {            /* Check for undef */
    *(ptr) = (void *) 0;
    return (char *) 0;
  } else if (SvTYPE(sv) == SVt_RV) {       /* Check for NULL pointer */
    *(ptr) = (void *) 0;
    if (!SvROK(sv))
      return (char *) 0;
    else
      return "Not a valid pointer value";
  } else {                                 /* Don't know what it is */
      *(ptr) = (void *) 0;
      return "Not a valid pointer value";
  }
  if (_t) {
    /* Now see if the types match */

    if (!sv_isa(sv,_t)) {
      _c = HvNAME(SvSTASH(SvRV(sv)));
      if (!SwigPtrSort) {
	qsort((void *) SwigPtrTable, SwigPtrN, sizeof(SwigPtrType), swigsort);
	for (i = 0; i < 256; i++) {
	  SwigStart[i] = SwigPtrN;
	}
	for (i = SwigPtrN-1; i >= 0; i--) {
	  SwigStart[(int) SwigPtrTable[i].name[0]] = i;
	}
	for (i = 255; i >= 1; i--) {
	  if (SwigStart[i-1] > SwigStart[i])
	    SwigStart[i-1] = SwigStart[i];
	}
	SwigPtrSort = 1;
	for (i = 0; i < SWIG_CACHESIZE; i++)
	  SwigCache[i].stat = 0;
      }
      /* First check cache for matches.  Uses last cache value as starting point */
      cache = &SwigCache[SwigLastCache];
      for (i = 0; i < SWIG_CACHESIZE; i++) {
	if (cache->stat) {
	  if (strcmp(_t,cache->name) == 0) {
	    if (strcmp(_c,cache->mapped) == 0) {
	      cache->stat++;
	      *ptr = (void *) tmp;
	      if (cache->tp->cast) *ptr = (*(cache->tp->cast))(*ptr);
	      return (char *) 0;
	    }
	  }
	}
	SwigLastCache = (SwigLastCache+1) & SWIG_CACHEMASK;
	if (!SwigLastCache) cache = SwigCache;
	else cache++;
      }

      start = SwigStart[(int) _t[0]];
      end = SwigStart[_t[0]+1];
      sp = &SwigPtrTable[start];
      while (start < end) {
	if (swigcmp(_t,sp) == 0) break;
	sp++;
	start++;
      }
      if (start >= end) sp = 0;
      if (sp) {
	while (swigcmp(_t,sp) == 0) {
	  name = sp->name;
	  len = sp->len;
	  tp = sp->next;
	  while(tp) {
	    if (tp->len >= 255) {
	      return _c;
	    }
	    strcpy(temp_type,tp->name);
	    strncat(temp_type,_t+len,255-tp->len);
	    if (sv_isa(sv,temp_type)) {
	      /* Get pointer value */
	      *ptr = (void *) tmp;
	      if (tp->cast) *ptr = (*(tp->cast))(*ptr);

	      strcpy(SwigCache[SwigCacheIndex].mapped,_c);
	      strcpy(SwigCache[SwigCacheIndex].name,_t);
	      SwigCache[SwigCacheIndex].stat = 1;
	      SwigCache[SwigCacheIndex].tp = tp;
	      SwigCacheIndex = SwigCacheIndex & SWIG_CACHEMASK;
	      return (char *) 0;
	    }
	    tp = tp->next;
	  }
	  /* Hmmm. Didn't find it this time */
 	  sp++;
	}
      }
      /* Didn't find any sort of match for this data.
	 Get the pointer value and return the received type */
      *ptr = (void *) tmp;
      return _c;
    } else {
      /* Found a match on the first try.  Return pointer value */
      *ptr = (void *) tmp;
      return (char *) 0;
    }
  }
  *ptr = (void *) tmp;
  return (char *) 0;
}
/* }}} */
/* }}} */

#ifdef __cplusplus
extern "C"
#endif

#ifndef PERL_OBJECT
/* If we don't use the XS macro it doesn't work with all Perl configurations */
SWIGEXPORT(/* */, XS(boot_pdflib_pl));
#else
SWIGEXPORT(void,boot_pdflib_pl)(CV *cv, CPerlObj *pPerl);
#endif

#include <setjmp.h>

#include "pdflib.h"

/* Exception handling */
#define SWIG_exception(msg)   	croak(msg)
#define try     PDF_TRY(p)
#define catch   PDF_CATCH(p) { \
                char errmsg[1024];\
		sprintf(errmsg, "PDFlib Error [%d] %s: %s", PDF_get_errnum(p),\
				    PDF_get_apiname(p), PDF_get_errmsg(p));\
		SWIG_exception(errmsg); \
		}

/* }}} */

XS(_wrap_PDF_new) { /* {{{ */
    PDF * _result;
    int PDF_VOLATILE argvi = 0;
    dXSARGS ;
    char versionbuf[32];

    if (items != 0)
        croak("Usage: PDF_new();");

    _result = PDF_new();


    if (_result) {
#if defined(PERL_REVISION) && defined(PERL_VERSION) && defined(PERL_SUBVERSION)
	sprintf(versionbuf, "Perl %d.%d.%d",
	    PERL_REVISION, PERL_VERSION, PERL_SUBVERSION);
#else
	sprintf(versionbuf, "Perl");
#endif
	PDF_set_parameter(_result, "binding", versionbuf);
    } else {
	SWIG_exception("PDF_new: internal error");
    }

    ST(argvi) = sv_newmortal();
    sv_setref_pv(ST(argvi++),"PDFPtr", (void *) _result);
    XSRETURN(argvi);
} /* }}} */

XS(_wrap_PDF_delete) { /* {{{ */
    PDF * p;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_delete(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_delete. Expected PDFPtr.");
	XSRETURN(1);
    }

    PDF_delete(p);

    XSRETURN(0);
} /* }}} */
    
XS(_wrap_PDF_open_pdi) { /* {{{ */
    PDF * p;
    char * PDF_VOLATILE filename;
    char * PDF_VOLATILE optlist;
    int PDF_VOLATILE len;
    int _result = -1;
    dXSARGS ;

    if (items != 4)
        croak("Usage: PDF_open_pdi(p, filename, optlist, len);");

    if (SWIG_GetPtr(ST(0),(void *) &p,"PDFPtr")) {
        croak("Type error in argument 1 of PDF_open_pdi. Expected PDFPtr.");
        XSRETURN(1);
    }
    filename = (char *) SvPV(ST(1),PL_na);
    optlist = (char *) SvPV(ST(2),PL_na);
    len = (int )SvIV(ST(3));

    try {     
	_result = (int )PDF_open_pdi(p,filename,optlist,0);
    } catch;

    ST(0) = sv_newmortal(); sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

XS(_wrap_PDF_setpolydash) { /* {{{ */
    PDF *p;
    SV *val;
    AV *av;
    float *carray;
    int PDF_VOLATILE length;
    int i;
    dXSARGS ;

    if (items != 2)
        croak("Usage: PDF_setpolydash(p, arrayref);");

    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
        croak("Type error in argument 1 of PDF_setpolydash. Expected PDFPtr.");
        XSRETURN(1);
    }

    if (!SvROK(ST(1))) {
        croak("Type error in argument 2 of PDF_setpolydash. Expected reference to array.");
        XSRETURN(1);
    }

    av = (AV *) SvRV(ST(1));
    length = (int) av_len(av) + 1;

    carray = (float *) malloc(sizeof(float) * length);
    if (carray == NULL)
    {
	croak("Out of memory in PDF_set_polydash");
	return;
    }

    for (i = 0; i < length; i++) {
	val = *av_fetch(av, i, 0);
	if ((!SvNOK(val)) && (!SvIOK(val))) {
	    croak("expected a reference to a double array in PDF_setpolydash\n");
	}
	carray[i] = (float)SvNV(val);
    }

    try {     PDF_setpolydash(p, carray, length);
    } catch;

    free(carray);
    XSRETURN(0);
} /* }}} */

XS(_wrap_PDF_open_image) { /* {{{ */
    int _result= -1;
    PDF * p;
    char * PDF_VOLATILE _arg1;
    char * PDF_VOLATILE _arg2;
    char * PDF_VOLATILE _arg3;
    long  PDF_VOLATILE _arg4;
    int PDF_VOLATILE _arg5;
    int PDF_VOLATILE _arg6;
    int PDF_VOLATILE _arg7;
    int PDF_VOLATILE _arg8;
    char * PDF_VOLATILE _arg9;
    int PDF_VOLATILE argvi = 0;
    dXSARGS ;

    if (items != 10)
        croak("Usage: PDF_open_image(p, imagetype, source, data, length, width, height, components, bpc, params);");
    if (SWIG_GetPtr(ST(0),(void *) &p,"PDFPtr")) {
        croak("Type error in argument 1 of PDF_open_image. Expected PDFPtr.");
        XSRETURN(1);
    }
    _arg1 = (char *) SvPV(ST(1),PL_na);
    _arg2 = (char *) SvPV(ST(2),PL_na);
    _arg3 = (char *) SvPV(ST(3),PL_na);
    _arg4 = (long )SvIV(ST(4));
    _arg5 = (int )SvIV(ST(5));
    _arg6 = (int )SvIV(ST(6));
    _arg7 = (int )SvIV(ST(7));
    _arg8 = (int )SvIV(ST(8));
    _arg9 = (char *) SvPV(ST(9),PL_na);

    try {     _result = (int )PDF_open_image(p,_arg1,_arg2,_arg3,_arg4,_arg5,_arg6,_arg7,_arg8,_arg9);
    } catch;

    ST(argvi) = sv_newmortal();
    sv_setiv(ST(argvi++),(IV) _result);
    XSRETURN(argvi);
} /* }}} */

XS(_wrap_PDF_utf16_to_utf8) { /* {{{ */
    char * _result = (char *)0;
    PDF * p;
    char * PDF_VOLATILE utf16string;
    size_t len;
    dXSARGS ;

    if (items != 2)
        croak("Usage: PDF_utf16_to_utf8(p, utf16string);");
    if (SWIG_GetPtr(ST(0),(void *) &p,"PDFPtr")) {
        croak("Type error in argument 1 of PDF_utf16_to_utf8. Expected PDFPtr.");
        XSRETURN(1);
    }
    utf16string = (char *) SvPV(ST(1),len);

    try {  _result = (char*) PDF_utf16_to_utf8(p, utf16string, (int) len, (int *)0);
    } catch;

    ST(0) = sv_newmortal();
    sv_setpv((SV*)ST(0), (char *) _result);
    XSRETURN(1);
} /* }}} */

XS(_wrap_PDF_utf8_to_utf16) { /* {{{ */
    char * _result = (char *)0;
    PDF * p;
    char * PDF_VOLATILE utf8string;
    char * PDF_VOLATILE format;
    int size;
    dXSARGS ;

    if (items != 3)
        croak("Usage: PDF_utf8_to_utf16(p, utf8string, ordering);");
    if (SWIG_GetPtr(ST(0),(void *) &p,"PDFPtr")) {
        croak("Type error in argument 1 of PDF_utf8_to_utf16. Expected PDFPtr.");
        XSRETURN(1);
    }
    utf8string = (char *) SvPV(ST(1),PL_na);
    format = (char *) SvPV(ST(2),PL_na);

    try {  _result = (char*) PDF_utf8_to_utf16(p, utf8string, format, &size);
    } catch;

    ST(0) = sv_newmortal();
    sv_setpvn((SV*)ST(0), (char *) _result, size);
    XSRETURN(1);
} /* }}} */


XS(_wrap_PDF_utf32_to_utf16) { /* {{{ */
    PDF * p;
    const char * utf32string;
    size_t len;
    const char * ordering;
    int size;
    const char *_result = NULL;
    dXSARGS;

    if (items != 3) {
        croak("Usage: PDF_utf32_to_utf16(p, utf32string, ordering);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
croak("Type error in argument 1 of PDF_utf32_to_utf16. Expected PDPDFr.");
        XSRETURN(1);
    }

    utf32string = SvPV(ST(1), len);
    ordering = SvPV(ST(2), PL_na);

    try {
        _result = PDF_utf32_to_utf16(p, utf32string, (int)len, ordering, &size);
    } catch;

    ST(0) = sv_newmortal();
    sv_setpvn((SV*)ST(0), (char *) _result, size);
    XSRETURN(1);
} /* }}} */



XS(_wrap_PDF_show_boxed) { /* {{{ */
    PDF * p;
    const char * text;
    size_t text_len;
    double left;
    double top;
    double width;
    double height;
    const char * hmode;
    const char * feature;
    int _result = -1;
    dXSARGS;

    if (items != 8) {
	croak("Usage: PDF_show_boxed(p, text, left, top, width, height, hmode, feature);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_show_boxed. Expected PDFPtr.");
	XSRETURN(1);
    }

    text = SvPV(ST(1), text_len);
    left = SvNV(ST(2));
    top = SvNV(ST(3));
    width = SvNV(ST(4));
    height = SvNV(ST(5));
    hmode = SvPV(ST(6), PL_na);
    feature = SvPV(ST(7), PL_na);

    try {
        _result = PDF_show_boxed(p, text, left, top, width, height, hmode, feature);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
/* BEGIN created with wrap.pl */
#define _WRAP_CODE	1
#include "pl_wrapped.c"
#undef _WRAP_CODE
/* END created with wrap.pl */


XS(_wrap_perl5_pdflib_var_init) { /* {{{ */
    dXSARGS;
    (void) items;

    XSRETURN(1);
} /* }}} */

#ifdef __cplusplus
extern "C"
#endif
XS(boot_pdflib_pl) { /* {{{ */
    dXSARGS;
    char *file = __FILE__;
    newXS("pdflibc::var_pdflib_init", _wrap_perl5_pdflib_var_init, file);

    (void) items;

    newXS("pdflibc::PDF_new", _wrap_PDF_new, file);
    newXS("pdflibc::PDF_delete", _wrap_PDF_delete, file);
    newXS("pdflibc::PDF_setpolydash", _wrap_PDF_setpolydash, file);
    newXS("pdflibc::PDF_open_pdi", _wrap_PDF_open_pdi, file);
    newXS("pdflibc::PDF_open_image", _wrap_PDF_open_image, file);
    newXS("pdflibc::PDF_show_boxed", _wrap_PDF_show_boxed, file);
    newXS("pdflibc::PDF_utf16_to_utf8", _wrap_PDF_utf16_to_utf8, file);
    newXS("pdflibc::PDF_utf32_to_utf16", _wrap_PDF_utf32_to_utf16, file);
    newXS("pdflibc::PDF_utf8_to_utf16", _wrap_PDF_utf8_to_utf16, file);

    /* BEGIN created with wrap.pl */
#define _WRAP_newXS
#include "pl_wrapped.c"
#undef _WRAP_newXS
    /* END created with wrap.pl */
/*
 * These are the pointer type-equivalency mappings.
 * (Used by the SWIG pointer type-checker).
 */
    SWIG_RegisterMapping("unsigned short","short",0);
    SWIG_RegisterMapping("PDF","struct PDF_s",0);
    SWIG_RegisterMapping("long","unsigned long",0);
    SWIG_RegisterMapping("long","signed long",0);
    SWIG_RegisterMapping("signed short","short",0);
    SWIG_RegisterMapping("signed int","int",0);
    SWIG_RegisterMapping("short","unsigned short",0);
    SWIG_RegisterMapping("short","signed short",0);
    SWIG_RegisterMapping("unsigned long","long",0);
    SWIG_RegisterMapping("int","unsigned int",0);
    SWIG_RegisterMapping("int","signed int",0);
    SWIG_RegisterMapping("unsigned int","int",0);
    SWIG_RegisterMapping("struct PDF_s","PDF",0);
    SWIG_RegisterMapping("signed long","long",0);
    ST(0) = &PL_sv_yes;
    XSRETURN(1);
} /* }}} */

/* vim600: fdm=marker
 */
