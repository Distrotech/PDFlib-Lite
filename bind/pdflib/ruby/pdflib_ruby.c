/*---------------------------------------------------------------------------*
 |              PDFlib - A library for generating PDF on the fly             |
 +---------------------------------------------------------------------------+
 |           Copyright (c) 2006 PDFlib GmbH. All rights reserved.            |
 +---------------------------------------------------------------------------+
 |                                                                           |
 |    This software is subject to the PDFlib license. It is NOT in the       |
 |    public domain. Extended versions and commercial licenses are           |
 |    available, please check http://www.pdflib.com.                         |
 |                                                                           |
 *---------------------------------------------------------------------------*/

/* $Id: pdflib_ruby.c,v 1.10.2.6 2009/10/29 20:30:04 rjs Exp $
 *
 * Wrapper code for the PDFlib Ruby binding
 *
 */


#if _MSC_VER >= 1310    /* VS .NET 2003 and later */
/* pdflib.h declares some functions as deprecated, but we don't want to see
 * these warnings here */
#pragma warning(disable: 4995)
#endif

#include <ruby.h>
#include <pdflib.h>


VALUE cPDFlib;
VALUE ePDFlibError;

/* Exception Handling */

#define pdf_try   PDF_TRY(pdf)
#define pdf_catch PDF_CATCH(pdf) { \
 pdf_exception(PDF_get_errnum(pdf), PDF_get_apiname(pdf), PDF_get_errmsg(pdf));\
  }

#define CHAR(x)	StringValuePtr(x)
#if  defined(RSTRING_LEN)
#define LEN(x)	RSTRING_LEN(x)
#else
#define LEN(x) RSTRING(StringValue(x))->len
#endif

static VALUE
exception_get_apiname(VALUE exc)
{
    return rb_attr_get(exc, rb_intern("apiname"));
}

static VALUE
exception_get_errmsg(VALUE exc)
{
    return rb_attr_get(exc, rb_intern("errmsg"));
}

static VALUE
exception_get_errnum(VALUE exc)
{
    return rb_attr_get(exc, rb_intern("errnum"));
}

static void
pdf_exception(int errnum, const char *apiname, const char *errmsg)
{
    VALUE v_apiname;
    VALUE v_errmsg;
    VALUE v_errnum;
    VALUE exc;
    char buf[BUFSIZ];

    v_apiname =  rb_str_new2(apiname);
    v_errmsg =  rb_str_new2(errmsg);
    v_errnum =  INT2NUM(errnum);

    snprintf(buf, BUFSIZ, "[%d] %s: %s", errnum, apiname, errmsg);
    exc = rb_exc_new2(ePDFlibError, buf);

    rb_iv_set(exc, "apiname", v_apiname);
    rb_iv_set(exc, "errmsg", v_errmsg);
    rb_iv_set(exc, "errnum", v_errnum);

    rb_exc_raise(exc);
}

typedef struct {
    int deleted;
    PDF *pdf;
} Ruby_PDF;

/* get PDFlib object */

static PDF *
get_pdf(VALUE obj)
{
  Ruby_PDF *rpdf;

  Check_Type(obj, T_DATA);
  if (!rb_obj_is_kind_of(obj, cPDFlib)) {
    rb_raise(ePDFlibError, "not a PDFlib object");
  }
  Data_Get_Struct(obj, Ruby_PDF, rpdf);
  return rpdf->pdf;
}

static void 
pdf_free(Ruby_PDF *rpdf)
{
    /* find out if delete was called already */
    if (!rpdf->deleted) PDF_delete(rpdf->pdf);
    free(rpdf);
}

static VALUE
pdf_alloc(VALUE klass)
{
    PDF *pdf;
    Ruby_PDF *rpdf;
    VALUE obj;

    rpdf = malloc(sizeof(Ruby_PDF));
    if (rpdf == NULL) {
	pdf_exception(99, "PDF_new", "PDF_new: internal error");
    }
    rpdf->deleted = 0;
    rpdf->pdf = pdf = PDF_new();
    if (pdf != NULL) {
	pdf_try {
	    PDF_set_parameter(pdf, "binding", "Ruby");
	    PDF_set_parameter(pdf, "objorient", "true");
	} pdf_catch;
    } else {
	pdf_exception(99, "PDF_new", "PDF_new: internal error");
    }

    obj = Data_Wrap_Struct(klass, 0, pdf_free, rpdf);
    return obj;
}

/* RJS: nothing to initialize as far as I understand this in the moment */
static VALUE
pdf_initialize(VALUE self)
{
    return self;
}

/* call PDF_delete imediatelly to free all resources, don't wait for the GC */
static VALUE
delete(VALUE self, VALUE filename, VALUE optlist, VALUE len)
{
    Ruby_PDF *rpdf;

    Check_Type(self, T_DATA);
    if (!rb_obj_is_kind_of(self, cPDFlib)) {
        rb_raise(ePDFlibError, "not a PDFlib object");
    }
    Data_Get_Struct(self, Ruby_PDF, rpdf);

    rpdf->deleted = 1;
    PDF_delete(rpdf->pdf);
    return self;
}

#define _WRAP_CODE
#include "rb_wrapped.c"
#undef _WRAP_CODE

/* Open a disk-based or virtual PDF document and prepare it for later use. */
static VALUE
open_pdi(VALUE self, VALUE filename, VALUE optlist, VALUE len)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;
    pdf_try {
        ret = PDF_open_pdi(pdf, CHAR(filename), CHAR(optlist), 0);
    } pdf_catch;
    return INT2NUM(ret);
}

/* Deprecated, use PDF_fit_textline() or PDF_fit_textflow().. */
static VALUE
show_boxed(VALUE self, VALUE text, VALUE left, VALUE top, VALUE width, VALUE height, VALUE hmode, VALUE feature)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_show_boxed(pdf, CHAR(text), NUM2DBL(left), NUM2DBL(top), NUM2DBL(width), NUM2DBL(height), CHAR(hmode), CHAR(feature));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Convert a string from UTF-16 format to UTF-8. */
static VALUE
utf16_to_utf8(VALUE self, VALUE utf16string)
{
    PDF *pdf = get_pdf(self);
    int size;
    const char *rets = NULL;

    pdf_try {
        rets = PDF_utf16_to_utf8(pdf, CHAR(utf16string), LEN(utf16string),
	    &size);
    } pdf_catch;
    return rb_str_new2(rets);
}

/* Convert a string from UTF-8 format to UTF-16. */
static VALUE
utf8_to_utf16(VALUE self, VALUE utf8string, VALUE ordering)
{
    PDF *pdf = get_pdf(self);
    int size;
    const char *rets = NULL;

    pdf_try {
        rets = PDF_utf8_to_utf16(pdf, CHAR(utf8string), CHAR(ordering), &size);
    } pdf_catch;
    return rb_str_new(rets, size);
}

/* Convert a string from UTF-8 format to UTF-16. */
static VALUE
utf32_to_utf16(VALUE self, VALUE utf32string, VALUE ordering)
{
    PDF *pdf = get_pdf(self);
    int size;
    const char *rets = NULL;

    pdf_try {
        rets = PDF_utf32_to_utf16(pdf, CHAR(utf32string), LEN(utf32string), CHAR(ordering), &size);
    } pdf_catch;
    return rb_str_new(rets, size);
}




void
Init_PDFlib()
{
    /* define own exception class */
    ePDFlibError = rb_define_class("PDFlibException", rb_eStandardError);
    rb_define_method(ePDFlibError, "get_apiname", exception_get_apiname, 0);
    rb_define_method(ePDFlibError, "get_errmsg", exception_get_errmsg, 0);
    rb_define_method(ePDFlibError, "get_errnum", exception_get_errnum, 0);

    cPDFlib = rb_define_class("PDFlib", rb_cData);
    rb_define_alloc_func(cPDFlib, pdf_alloc);

    rb_define_method(cPDFlib, "initialize", pdf_initialize, -1);
    rb_define_method(cPDFlib, "delete", delete, 0);

#define _WRAP_METHODS
#include "rb_wrapped.c"
#undef _WRAP_METHODS

    rb_define_method(cPDFlib, "open_pdi", open_pdi, 3);
    rb_define_method(cPDFlib, "show_boxed", show_boxed, 7);
    rb_define_method(cPDFlib, "utf16_to_utf8", utf16_to_utf8, 1);
    rb_define_method(cPDFlib, "utf8_to_utf16", utf8_to_utf16, 2);
    rb_define_method(cPDFlib, "utf32_to_utf16", utf32_to_utf16, 2);
}
