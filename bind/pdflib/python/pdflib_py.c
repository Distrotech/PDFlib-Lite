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

/* $Id: pdflib_py.c,v 1.32.2.7 2009/03/05 11:56:35 rjs Exp $
 *
 * Wrapper code for the PDFlib Python binding
 *
 */

#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
#define PY_SSIZE_T_CLEAN 1
#include <Python.h>
#ifdef __cplusplus
}
#endif

#if PY_VERSION_HEX < 0x02050000
typedef int Py_ssize_t;
#define PY_SSIZE_T_MAX INT_MAX
#define PY_SSIZE_T_MIN INT_MIN
#endif

/* Compilers which are not strictly ANSI conforming can set PDF_VOLATILE
 * to an empty value.
 */
#ifndef PDF_VOLATILE
#define PDF_VOLATILE    volatile
#endif

/* Definitions for Windows/Unix exporting */
#if defined(__WIN32__)
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


#include <stdlib.h>


/* Make a pointer value string */

static
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

static
char *SWIG_GetPtr(char *_c, void **ptr, char *_t)
{
  unsigned long _p;
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

#include <setjmp.h>

#include "pdflib.h"

/*
 * Byte order
 * WORDS_BIGENDIAN will be set by the configure script on most platforms.
 * Only on platforms where there is no configure script we must set the
 * endianness explicitly (most importantly CodeWarrior on the Mac)
 */
/* And we have to explicitly set it one Platforms where crosscompiling
 * is used (like Mac to create Universal Binaries)
 */
#if  defined(__APPLE__)
#  if defined(__ppc__) || defined(__ppc64__)
#    define UTFCONV	"utf-16-be"
#  else
#    define UTFCONV	"utf-16-le"
#  endif
#else  /* APPLE */
#  if defined(WORDS_BIGENDIAN)
#    define UTFCONV	"utf-16-be"
#  else
#    define UTFCONV	"utf-16-le"
#  endif
#endif /* APPLE */

struct module_state {
    PyObject *PDFlibException;
};

#if PY_MAJOR_VERSION >= 3
#define GETSTATE(m) ((struct module_state*)PyModule_GetState(m))
#else /*  PY_MAJOR_VERSION >= 3 */
#define GETSTATE(m) (&_state)
static struct module_state _state;
#endif /*  PY_MAJOR_VERSION >= 3 */


/* Exception handling */

#define try	PDF_TRY(p)
#define catch	PDF_CATCH(p) { \
		PDF_throw_pyexception(self, p); \
		return NULL; \
		}

static void
PDF_throw_pyexception(PyObject *m, PDF *p)
{
    char errmsg[1024];
    struct module_state *st = GETSTATE(m);
    sprintf(errmsg, "PDFlib Error [%d] %s: %s", PDF_get_errnum(p),
			PDF_get_apiname(p), PDF_get_errmsg(p));
    PyErr_SetString(st->PDFlibException, errmsg);
}

static void
PDF_WrongPDFHandle(const char *funcname)
{
    char text[128];

    sprintf(text, "Type error in argument 1 of %s. Expected _PDF_p.", funcname);
    PyErr_SetString(PyExc_TypeError, text);
}



static PyObject *_wrap_PDF_new(PyObject *self, PyObject *args)
{
    PDF *p;
    char _ptemp[128];
    char versionbuf[32];

    if(!PyArg_ParseTuple(args,":PDF_new"))
        return NULL;

    p = PDF_new();

    if (!p) {
        PyErr_SetString(PyExc_SystemError, "PDFlib error: in PDF_new()");
        return NULL;
    }

    try {
#if defined(PY_VERSION)
        sprintf(versionbuf, "Python %s", PY_VERSION);
#elif defined(PATCHLEVEL)
        sprintf(versionbuf, "Python %s", PATCHLEVEL);
#else
        sprintf(versionbuf, "Python (unknown)");
#endif
        PDF_set_parameter(p, "binding", versionbuf);
	PDF_set_parameter(p, "unicaplang", "true");
	PDF_set_parameter(p, "textformat", "auto2");
	PDF_set_parameter(p, "hypertextformat", "auto2");
	PDF_set_parameter(p, "hypertextencoding", "");
    } catch;

    SWIG_MakePtr(_ptemp, (char *) p,"_PDF_p");
    return Py_BuildValue("s",_ptemp);
}

static PyObject *_nuwrap_PDF_new(PyObject *self, PyObject *args)
{
    PDF *p;
    char _ptemp[128];
    char versionbuf[32];

    if(!PyArg_ParseTuple(args,":PDF_new"))
        return NULL;

    p = PDF_new();

    if (!p) {
        PyErr_SetString(PyExc_SystemError, "PDFlib error: in PDF_new()");
        return NULL;
    }

    try {
#if defined(PY_VERSION)
        sprintf(versionbuf, "Python %s", PY_VERSION);
#elif defined(PATCHLEVEL)
        sprintf(versionbuf, "Python %s", PATCHLEVEL);
#else
        sprintf(versionbuf, "Python (unknown)");
#endif
        PDF_set_parameter(p, "binding", versionbuf);
    } catch;

    SWIG_MakePtr(_ptemp, (char *) p,"_PDF_p");
    return Py_BuildValue("s",_ptemp);
}

static PyObject *_wrap_PDF_delete(PyObject *self, PyObject *args)
{
    PDF *p;
    char *py_p = 0;

    if (!PyArg_ParseTuple(args,"s:PDF_delete", &py_p))
        return NULL;
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p"))
    {
        PDF_WrongPDFHandle("PDF_delete");
        return NULL;
    }

    PDF_delete(p);

    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_nuwrap_PDF_delete(PyObject *self, PyObject *args)
{
    PDF *p;
    char *py_p = 0;

    if (!PyArg_ParseTuple(args,"s:PDF_delete", &py_p))
        return NULL;
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p"))
    {
        PDF_WrongPDFHandle("PDF_delete");
        return NULL;
    }

    PDF_delete(p);

    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_PDF_open_pdi(PyObject *self, PyObject *args)
{
    PDF *p;
    char *py_p = 0;
    const char *filename;
    const char *optlist;
    int reserved;
    int PDF_VOLATILE _result = 0;

    if (!PyArg_ParseTuple(args,"sssi:PDF_open_pdi",
		    &py_p, &filename, &optlist, &reserved))
        return NULL;
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p"))
    {
        PDF_WrongPDFHandle("PDF_open_pdi");
        return NULL;
    }

    try { _result = (int) PDF_open_pdi(p, filename, optlist, 0);
    } catch;

    return Py_BuildValue("i", _result);
}

static PyObject *_nuwrap_PDF_open_pdi(PyObject *self, PyObject *args)
{
    PDF *p;
    char *py_p = 0;
    const char *filename;
    const char *optlist;
    int reserved;
    int PDF_VOLATILE _result = 0;

    if (!PyArg_ParseTuple(args,"sssi:PDF_open_pdi",
		    &py_p, &filename, &optlist, &reserved))
        return NULL;
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p"))
    {
        PDF_WrongPDFHandle("PDF_open_pdi");
        return NULL;
    }

    try { _result = (int) PDF_open_pdi(p, filename, optlist, 0);
    } catch;

    return Py_BuildValue("i", _result);
}

static PyObject *_wrap_PDF_setpolydash(PyObject *self, PyObject *args)
{
    PDF *p;
    char *py_p = 0;
    PyObject *parray = NULL;

    PyObject *val;
    float fval, *carray;
    int PDF_VOLATILE length, i;

    if (!PyArg_ParseTuple(args,"sO:PDF_setpolydash", &py_p, &parray))
        return NULL;
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p"))
    {
        PDF_WrongPDFHandle("PDF_setpolydash");
        return NULL;
    }

    length = PyTuple_Size(parray);

    carray = (float *) malloc(sizeof(float) * length);
    if (carray == NULL)
    {
        PyErr_SetString(PyExc_TypeError, "Out of memory in PDF_set_polydash");
        return NULL;
    }

    for (i = 0; i < length; i++)
    {
        val = PyTuple_GetItem(parray, i);
        if (!PyArg_Parse(val, "f:PDF_setpolydash", &fval))
        {
            PyErr_SetString(PyExc_TypeError,
                "Type error in argument 2 of PDF_setpolydash. Expected float.");
            return NULL;
        }
        carray[i] = fval;
    }

    try { PDF_setpolydash(p, carray, length);
    } catch;

    free(carray);

    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_nuwrap_PDF_setpolydash(PyObject *self, PyObject *args)
{
    PDF *p;
    char *py_p = 0;
    PyObject *parray = NULL;

    PyObject *val;
    float fval, *carray;
    int PDF_VOLATILE length, i;

    if (!PyArg_ParseTuple(args,"sO:PDF_setpolydash", &py_p, &parray))
        return NULL;
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p"))
    {
        PDF_WrongPDFHandle("PDF_setpolydash");
        return NULL;
    }

    length = PyTuple_Size(parray);

    carray = (float *) malloc(sizeof(float) * length);
    if (carray == NULL)
    {
        PyErr_SetString(PyExc_TypeError, "Out of memory in PDF_set_polydash");
        return NULL;
    }

    for (i = 0; i < length; i++)
    {
        val = PyTuple_GetItem(parray, i);
        if (!PyArg_Parse(val, "f:PDF_setpolydash", &fval))
        {
            PyErr_SetString(PyExc_TypeError,
                "Type error in argument 2 of PDF_setpolydash. Expected float.");
            return NULL;
        }
        carray[i] = fval;
    }

    try { PDF_setpolydash(p, carray, length);
    } catch;

    free(carray);

    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *_wrap_PDF_open_image(PyObject *self, PyObject *args)
{
    PDF *p;
    char *py_p = 0;
    const char *imagetype;
    const char *source;
    const char *data;
    Py_ssize_t dummy;
    Py_ssize_t length;
    int width;
    int height;
    int components;
    int bpc;
    const char *params;
    int PDF_VOLATILE _result = 0;

    if (!PyArg_ParseTuple(args,"ssss#liiiis:PDF_open_image",
            &py_p, &imagetype, &source, &data, &dummy,
            &length, &width, &height, &components, &bpc, &params))
        return NULL;
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p"))
    {
        PDF_WrongPDFHandle("PDF_open_image");
        return NULL;
    }
    try {
	_result = (int) PDF_open_image(p, imagetype, source, data,
		    (long)length, width, height, components, bpc, params);
    } catch;

    return Py_BuildValue("i", _result);
}

static PyObject *_nuwrap_PDF_open_image(PyObject *self, PyObject *args)
{
    PDF *p;
    char *py_p = 0;
    const char *imagetype;
    const char *source;
    const char *data;
    int dummy;
    Py_ssize_t length;
    int width;
    int height;
    int components;
    int bpc;
    const char *params;
    int PDF_VOLATILE _result = 0;

    if (!PyArg_ParseTuple(args,"ssss#liiiis:PDF_open_image",
	    &py_p, &imagetype, &source, &data, &dummy,
		    &length, &width, &height, &components, &bpc, &params))
        return NULL;
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p"))
    {
        PDF_WrongPDFHandle("PDF_open_image");
        return NULL;
    }

    try {
	_result = (int) PDF_open_image(p, imagetype, source,
		data, (long)length, width, height, components, bpc, params);
    } catch;

    return Py_BuildValue("i", _result);
}

static PyObject *
_nuwrap_PDF_show_boxed(PyObject *self, PyObject *args)
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * text = NULL;
    Py_ssize_t text_len;
    double left;
    double top;
    double width;
    double height;
    const char * hmode;
    const char * feature;
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "s"
	"s#"
	"ddddss:PDF_show_boxed"
	, &py_p
	, &text, &text_len, &left, &top, &width, &height, &hmode, &feature)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

        _retval = PDF_show_boxed( p, text, left, top, width, height, hmode,
feature);
    } PDF_CATCH(p) {
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);

    return Py_BuildValue("i", _retval);
}


static PyObject *
_wrap_PDF_show_boxed(PyObject *self, PyObject *args)
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * text = NULL;
    Py_ssize_t text_len;
    double left;
    double top;
    double width;
    double height;
    const char * hmode;
    const char * feature;
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "s"
	"es#"
	"ddddss:PDF_show_boxed"
	, &py_p
	, UTFCONV
	, &text, &text_len, &left, &top, &width, &height, &hmode, &feature)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

        _retval = PDF_show_boxed2(
p, text, text_len, left, top, width, height, hmode,
feature);
    } PDF_CATCH(p) {
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
    PyMem_Free((void *)text);
        return NULL;
    }

    PyEval_RestoreThread(_save);

    PyMem_Free((void *)text);
    return Py_BuildValue("i", _retval);
}


static PyObject *_nuwrap_PDF_utf16_to_utf8(PyObject *self, PyObject *args)
{
    PDF *p;
    char *py_p = 0;
    const char *utf16string;
    Py_ssize_t utf16string_len;
    int size;
    char PDF_VOLATILE *_result = NULL;

    if (!PyArg_ParseTuple(args,"su#i:PDF_utf16_to_utf8",
		&py_p, &utf16string, &utf16string_len, &size))
        return NULL;
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p"))
    {
        PDF_WrongPDFHandle("PDF_utf16_to_utf8");
        return NULL;
    }

    try {
	_result = (char *) PDF_utf16_to_utf8(p, utf16string,
				    (int)utf16string_len, &size);
    } catch;

    return Py_BuildValue("s#", _result, size);
}

static PyObject *_nuwrap_PDF_utf8_to_utf16(PyObject *self, PyObject *args)
{
    PDF *p;
    char *py_p = 0;
    const char *utf8string;
    const char *format;
    int size;
    char PDF_VOLATILE *_result = NULL;

    if (!PyArg_ParseTuple(args,"sss:PDF_utf8_to_utf16",
				&py_p, &utf8string, &format))
        return NULL;
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p"))
    {
        PDF_WrongPDFHandle("PDF_utf8_to_utf16");
        return NULL;
    }

    try { _result = (char *) PDF_utf8_to_utf16(p, utf8string, format, &size);
    } catch;

    return Py_BuildValue("u#", _result, size);
}

/* BEGIN created with wrap.pl */
#define _WRAP_CODE      1
#define PDF_UNICODE_WRAPPER 1
#include "py_wrapped.c"
#undef PDF_UNICODE_WRAPPER
#include "py_wrapped.c"
#undef _WRAP_CODE
/* END created with wrap.pl */

static PyMethodDef pdflibMethods[] =
{
    { "PDF_new", _wrap_PDF_new, 1 },
    { "PDF_delete", _wrap_PDF_delete, 1 },
    { "PDF_open_pdi", _wrap_PDF_open_pdi, 1 },
    { "PDF_setpolydash", _wrap_PDF_setpolydash, 1 },
    { "PDF_open_image", _wrap_PDF_open_image, 1 },
    { "PDF_show_boxed", _wrap_PDF_show_boxed, 1 },
#define _WRAP_newXS
#define PDF_UNICODE_WRAPPER 1
#include "py_wrapped.c"
#undef PDF_UNICODE_WRAPPER
#undef _WRAP_newXS

    { NULL, NULL },
};
static PyMethodDef nupdflibMethods[] =
{
    { "PDF_new", _nuwrap_PDF_new, 1 },
    { "PDF_delete", _nuwrap_PDF_delete, 1 },
    { "PDF_open_pdi", _nuwrap_PDF_open_pdi, 1 },
    { "PDF_setpolydash", _nuwrap_PDF_setpolydash, 1 },
    { "PDF_open_image", _nuwrap_PDF_open_image, 1 },
    { "PDF_show_boxed", _nuwrap_PDF_show_boxed, 1 },
    { "PDF_utf16_to_utf8", _nuwrap_PDF_utf16_to_utf8, 1 },
    { "PDF_utf8_to_utf16", _nuwrap_PDF_utf8_to_utf16, 1 },
#define _WRAP_newXS
#include "py_wrapped.c"
#undef _WRAP_newXS

    { NULL, NULL },
};

#if PY_MAJOR_VERSION >= 3

static int pdflib_py_traverse(PyObject *m, visitproc visit, void *arg) {
    Py_VISIT(GETSTATE(m)->PDFlibException);
    return 0;
}

static int pdflib_py_clear(PyObject *m) {
    Py_CLEAR(GETSTATE(m)->PDFlibException);
    return 0;
}


static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "pdflib_py",
    NULL,
    sizeof(struct module_state),
    pdflibMethods,
    NULL,
    pdflib_py_traverse,
    pdflib_py_clear,
    NULL
};

static struct PyModuleDef numoduledef = {
    PyModuleDef_HEAD_INIT,
    "pdflib_py",
    NULL,
    sizeof(struct module_state),
    nupdflibMethods,
    NULL,
    pdflib_py_traverse,
    pdflib_py_clear,
    NULL
};

#define INITERROR return NULL
#else /* PY_MAJOR_VERSION >= 3 */
#define INITERROR return
#endif /* PY_MAJOR_VERSION >= 3 */

#if PY_MAJOR_VERSION >= 3
#ifdef __cplusplus
extern "C"
#endif
SWIGEXPORT(PyObject *,PyInit_pdflib_py)()

#else /* PY_MAJOR_VERSION >= 3 */

#ifdef __cplusplus
extern "C"
#endif
SWIGEXPORT(void,initpdflib_py)()
#endif /* PY_MAJOR_VERSION >= 3 */
{
    PyObject *m;
    struct module_state *st;

#if PY_MAJOR_VERSION >= 3
    m = PyModule_Create(&moduledef);
#else /* PY_MAJOR_VERSION >= 3 */
    m = Py_InitModule("pdflib_py", pdflibMethods);
#endif /* PY_MAJOR_VERSION >= 3 */

    if (m == NULL)
        INITERROR;

    st = GETSTATE(m);
    st->PDFlibException = PyErr_NewException("pdflib_py.PDFlibException",
		    NULL, NULL);
    if (st->PDFlibException == NULL) {
        Py_DECREF(m);
        INITERROR;
    }
    Py_INCREF(st->PDFlibException);
    PyModule_AddObject(m, "PDFlibException", st->PDFlibException);

#if PY_MAJOR_VERSION >= 3
    return m;
#endif
}

#if PY_MAJOR_VERSION >= 3
#ifdef __cplusplus
extern "C"
#endif
SWIGEXPORT(PyObject *,PyInit_nupdflib_py)()

#else /* PY_MAJOR_VERSION >= 3 */

#ifdef __cplusplus
extern "C"
#endif
SWIGEXPORT(void,initnupdflib_py)()
#endif /* PY_MAJOR_VERSION >= 3 */
{
    PyObject *m;
    struct module_state *st;

#if PY_MAJOR_VERSION >= 3
    m = PyModule_Create(&numoduledef);
#else /* PY_MAJOR_VERSION >= 3 */
    m = Py_InitModule("nupdflib_py", nupdflibMethods);
#endif /* PY_MAJOR_VERSION >= 3 */
    if (m == NULL)
        INITERROR;

    st = GETSTATE(m);

    /* PDFlib exception handling */
    st->PDFlibException = PyErr_NewException("nupdflib_py.PDFlibException",
	NULL, NULL);
    Py_INCREF(st->PDFlibException);
    PyModule_AddObject(m, "PDFlibException", st->PDFlibException);

#if PY_MAJOR_VERSION >= 3
    return m;
#endif
}
