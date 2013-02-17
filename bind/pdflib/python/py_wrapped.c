#if defined(_WRAP_CODE)

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_activate_item(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_activate_item(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int id;


    if (!PyArg_ParseTuple(args, "si:PDF_activate_item"
	, &py_p, &id)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_activate_item(
p, id);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_create_3dview(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_create_3dview(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * username = NULL;
    Py_ssize_t username_len;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	""
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_create_3dview"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &username, &username_len
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_create_3dview(
p, username, 
#ifdef PDF_UNICODE_WRAPPER
	username_len
#else
	0
#endif /* PDF_UNICODE_WRAPPER */
	, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)username);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)username);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_load_3ddata(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_load_3ddata(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * filename = NULL;
    Py_ssize_t filename_len;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	""
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_load_3ddata"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &filename, &filename_len
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_load_3ddata(
p, filename, 
#ifdef PDF_UNICODE_WRAPPER
	filename_len
#else
	0
#endif /* PDF_UNICODE_WRAPPER */
	, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)filename);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)filename);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_add_bookmark(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_add_bookmark(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * text = NULL;
    Py_ssize_t len;
    int parent;
    int open;
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	"ii:PDF_add_bookmark"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &text, &len, &parent, &open)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_add_bookmark2(
p, text, (int)len, parent, open);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)text);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)text);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_add_launchlink(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_add_launchlink(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * filename;


    if (!PyArg_ParseTuple(args, "sdddds:PDF_add_launchlink"
	, &py_p, &llx, &lly, &urx, &ury, &filename)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_add_launchlink(
p, llx, lly, urx, ury, filename);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_add_locallink(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_add_locallink(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double llx;
    double lly;
    double urx;
    double ury;
    int page;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */


    if (!PyArg_ParseTuple(args, "sddddi"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_add_locallink"
	, &py_p, &llx, &lly, &urx, &ury, &page
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        PDF_add_locallink(
p, llx, lly, urx, ury, page, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_add_nameddest(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_add_nameddest(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * name = NULL;
    Py_ssize_t name_len;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */


    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	""
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_add_nameddest"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &name, &name_len
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        PDF_add_nameddest(
p, name, (int)name_len, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)name);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)name);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_add_note(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_add_note(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * contents = NULL;
    Py_ssize_t len_cont;
    const char * title = NULL;
    Py_ssize_t len_title;
    const char * icon;
    int open;


    if (!PyArg_ParseTuple(args, "sdddd"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	""
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	"si:PDF_add_note"
	, &py_p, &llx, &lly, &urx, &ury
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &contents, &len_cont
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &title, &len_title, &icon, &open)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
#endif /* PDF_UNICODE_WRAPPER */
        PDF_add_note2(
p, llx, lly, urx, ury, contents, (int)len_cont, title, 
(int)len_title, icon, open);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)contents);
    PyMem_Free((void *)title);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)contents);
    PyMem_Free((void *)title);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_add_pdflink(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_add_pdflink(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * filename;
    int page;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */


    if (!PyArg_ParseTuple(args, "sddddsi"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_add_pdflink"
	, &py_p, &llx, &lly, &urx, &ury, &filename, &page
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        PDF_add_pdflink(
p, llx, lly, urx, ury, filename, page, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_add_table_cell(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_add_table_cell(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int table;
    int column;
    int row;
    const char * text = NULL;
    Py_ssize_t text_len;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "siii"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	""
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_add_table_cell"
	, &py_p, &table, &column, &row
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &text, &text_len
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_add_table_cell(
p, table, column, row, text, (int)text_len, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)text);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)text);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_add_textflow(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_add_textflow(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int textflow;
    const char * text = NULL;
    Py_ssize_t text_len;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "si"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	""
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_add_textflow"
	, &py_p, &textflow
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &text, &text_len
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_add_textflow(
p, textflow, text, (int)text_len, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)text);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)text);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_add_thumbnail(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_add_thumbnail(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int image;


    if (!PyArg_ParseTuple(args, "si:PDF_add_thumbnail"
	, &py_p, &image)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_add_thumbnail(
p, image);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_add_weblink(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_add_weblink(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * url;


    if (!PyArg_ParseTuple(args, "sdddds:PDF_add_weblink"
	, &py_p, &llx, &lly, &urx, &ury, &url)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_add_weblink(
p, llx, lly, urx, ury, url);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_arc(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_arc(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double x;
    double y;
    double r;
    double alpha;
    double beta;


    if (!PyArg_ParseTuple(args, "sddddd:PDF_arc"
	, &py_p, &x, &y, &r, &alpha, &beta)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_arc(
p, x, y, r, alpha, beta);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_arcn(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_arcn(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double x;
    double y;
    double r;
    double alpha;
    double beta;


    if (!PyArg_ParseTuple(args, "sddddd:PDF_arcn"
	, &py_p, &x, &y, &r, &alpha, &beta)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_arcn(
p, x, y, r, alpha, beta);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_attach_file(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_attach_file(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * filename = NULL;
    Py_ssize_t filename_len;
    const char * description = NULL;
    Py_ssize_t len_descr;
    const char * author = NULL;
    Py_ssize_t len_auth;
    const char * mimetype;
    const char * icon;


    if (!PyArg_ParseTuple(args, "sdddd"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	""
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	""
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	"ss:PDF_attach_file"
	, &py_p, &llx, &lly, &urx, &ury
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &filename, &filename_len
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &description, &len_descr
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &author, &len_auth, &mimetype, &icon)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
#endif /* PDF_UNICODE_WRAPPER */
        PDF_attach_file2(
p, llx, lly, urx, ury, filename, 
#ifdef PDF_UNICODE_WRAPPER
	filename_len
#else
	0
#endif /* PDF_UNICODE_WRAPPER */
	, description, 
(int)len_descr, author, (int)len_auth, mimetype, icon);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)filename);
    PyMem_Free((void *)description);
    PyMem_Free((void *)author);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)filename);
    PyMem_Free((void *)description);
    PyMem_Free((void *)author);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_begin_document(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_begin_document(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * filename = NULL;
    Py_ssize_t filename_len;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	""
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_begin_document"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &filename, &filename_len
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_begin_document(
p, filename, 
#ifdef PDF_UNICODE_WRAPPER
	filename_len
#else
	0
#endif /* PDF_UNICODE_WRAPPER */
	, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)filename);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)filename);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_begin_font(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_begin_font(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * fontname = NULL;
    Py_ssize_t fontname_len;
    double a;
    double b;
    double c;
    double d;
    double e;
    double f;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */


    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	"dddddd"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_begin_font"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &fontname, &fontname_len, &a, &b, &c, &d, &e, &f
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        PDF_begin_font(
p, fontname, 
#ifdef PDF_UNICODE_WRAPPER
	fontname_len
#else
	0
#endif /* PDF_UNICODE_WRAPPER */
	, a, b, c, d, e, 
f, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)fontname);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)fontname);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_begin_glyph(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_begin_glyph(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * glyphname;
    double wx;
    double llx;
    double lly;
    double urx;
    double ury;


    if (!PyArg_ParseTuple(args, "ssddddd:PDF_begin_glyph"
	, &py_p, &glyphname, &wx, &llx, &lly, &urx, &ury)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_begin_glyph(
p, glyphname, wx, llx, lly, urx, ury);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_begin_item(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_begin_item(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * tag;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "ss"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_begin_item"
	, &py_p, &tag
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_begin_item(
p, tag, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_begin_layer(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_begin_layer(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int layer;


    if (!PyArg_ParseTuple(args, "si:PDF_begin_layer"
	, &py_p, &layer)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_begin_layer(
p, layer);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_begin_page(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_begin_page(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double width;
    double height;


    if (!PyArg_ParseTuple(args, "sdd:PDF_begin_page"
	, &py_p, &width, &height)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_begin_page(
p, width, height);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_begin_page_ext(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_begin_page_ext(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double width;
    double height;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */


    if (!PyArg_ParseTuple(args, "sdd"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_begin_page_ext"
	, &py_p, &width, &height
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        PDF_begin_page_ext(
p, width, height, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_begin_pattern(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_begin_pattern(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double width;
    double height;
    double xstep;
    double ystep;
    int painttype;
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "sddddi:PDF_begin_pattern"
	, &py_p, &width, &height, &xstep, &ystep, &painttype)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            _retval = PDF_begin_pattern(
p, width, height, xstep, ystep, painttype);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_begin_template(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_begin_template(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double width;
    double height;
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "sdd:PDF_begin_template"
	, &py_p, &width, &height)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            _retval = PDF_begin_template(
p, width, height);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_begin_template_ext(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_begin_template_ext(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double width;
    double height;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "sdd"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_begin_template_ext"
	, &py_p, &width, &height
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_begin_template_ext(
p, width, height, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_circle(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_circle(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double x;
    double y;
    double r;


    if (!PyArg_ParseTuple(args, "sddd:PDF_circle"
	, &py_p, &x, &y, &r)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_circle(
p, x, y, r);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_clip(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_clip(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;


    if (!PyArg_ParseTuple(args, "s:PDF_clip"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_clip(
p);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_close(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_close(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;


    if (!PyArg_ParseTuple(args, "s:PDF_close"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_close(
p);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_close_image(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_close_image(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int image;


    if (!PyArg_ParseTuple(args, "si:PDF_close_image"
	, &py_p, &image)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_close_image(
p, image);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_close_pdi(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_close_pdi(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int doc;


    if (!PyArg_ParseTuple(args, "si:PDF_close_pdi"
	, &py_p, &doc)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_close_pdi(
p, doc);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_close_pdi_document(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_close_pdi_document(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int doc;


    if (!PyArg_ParseTuple(args, "si:PDF_close_pdi_document"
	, &py_p, &doc)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_close_pdi_document(
p, doc);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_close_pdi_page(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_close_pdi_page(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int page;


    if (!PyArg_ParseTuple(args, "si:PDF_close_pdi_page"
	, &py_p, &page)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_close_pdi_page(
p, page);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_closepath(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_closepath(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;


    if (!PyArg_ParseTuple(args, "s:PDF_closepath"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_closepath(
p);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_closepath_fill_stroke(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_closepath_fill_stroke(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;


    if (!PyArg_ParseTuple(args, "s:PDF_closepath_fill_stroke"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_closepath_fill_stroke(
p);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_closepath_stroke(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_closepath_stroke(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;


    if (!PyArg_ParseTuple(args, "s:PDF_closepath_stroke"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_closepath_stroke(
p);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_concat(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_concat(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double a;
    double b;
    double c;
    double d;
    double e;
    double f;


    if (!PyArg_ParseTuple(args, "sdddddd:PDF_concat"
	, &py_p, &a, &b, &c, &d, &e, &f)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_concat(
p, a, b, c, d, e, f);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_continue_text(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_continue_text(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * text = NULL;
    Py_ssize_t text_len;


    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_continue_text"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &text, &text_len)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
#endif /* PDF_UNICODE_WRAPPER */
        PDF_continue_text2(
p, text, (int)text_len);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)text);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)text);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_create_action(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_create_action(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * type;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "ss"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_create_action"
	, &py_p, &type
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_create_action(
p, type, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_create_annotation(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_create_annotation(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * type;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */


    if (!PyArg_ParseTuple(args, "sdddds"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_create_annotation"
	, &py_p, &llx, &lly, &urx, &ury, &type
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        PDF_create_annotation(
p, llx, lly, urx, ury, type, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_create_bookmark(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_create_bookmark(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * text = NULL;
    Py_ssize_t text_len;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	""
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_create_bookmark"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &text, &text_len
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_create_bookmark(
p, text, (int)text_len, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)text);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)text);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_create_field(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_create_field(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * name = NULL;
    Py_ssize_t name_len;
    const char * type;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */


    if (!PyArg_ParseTuple(args, "sdddd"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	"s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_create_field"
	, &py_p, &llx, &lly, &urx, &ury
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &name, &name_len, &type
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        PDF_create_field(
p, llx, lly, urx, ury, name, (int)name_len, type, 
optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)name);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)name);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_create_fieldgroup(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_create_fieldgroup(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * name = NULL;
    Py_ssize_t name_len;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */


    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	""
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_create_fieldgroup"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &name, &name_len
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        PDF_create_fieldgroup(
p, name, (int)name_len, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)name);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)name);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_create_gstate(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_create_gstate(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_create_gstate"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_create_gstate(
p, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_create_pvf(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_create_pvf(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * filename = NULL;
    Py_ssize_t filename_len;
    const void * data;
    Py_ssize_t size;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */


    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	"s#"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_create_pvf"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &filename, &filename_len, &data, &size
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        PDF_create_pvf(
p, filename, 
#ifdef PDF_UNICODE_WRAPPER
	filename_len
#else
	0
#endif /* PDF_UNICODE_WRAPPER */
	, data, (size_t)size, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)filename);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)filename);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_create_textflow(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_create_textflow(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * text = NULL;
    Py_ssize_t text_len;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	""
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_create_textflow"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &text, &text_len
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_create_textflow(
p, text, (int)text_len, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)text);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)text);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_curveto(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_curveto(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double x_1;
    double y_1;
    double x_2;
    double y_2;
    double x_3;
    double y_3;


    if (!PyArg_ParseTuple(args, "sdddddd:PDF_curveto"
	, &py_p, &x_1, &y_1, &x_2, &y_2, &x_3, &y_3)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_curveto(
p, x_1, y_1, x_2, y_2, x_3, y_3);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_define_layer(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_define_layer(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * name = NULL;
    Py_ssize_t name_len;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	""
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_define_layer"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &name, &name_len
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_define_layer(
p, name, (int)name_len, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)name);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)name);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_delete_pvf(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_delete_pvf(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * filename = NULL;
    Py_ssize_t filename_len;
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_delete_pvf"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &filename, &filename_len)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_delete_pvf(
p, filename, 
#ifdef PDF_UNICODE_WRAPPER
	filename_len
#else
	0
#endif /* PDF_UNICODE_WRAPPER */
	);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)filename);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)filename);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_delete_table(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_delete_table(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int table;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */


    if (!PyArg_ParseTuple(args, "si"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_delete_table"
	, &py_p, &table
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        PDF_delete_table(
p, table, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_delete_textflow(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_delete_textflow(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int textflow;


    if (!PyArg_ParseTuple(args, "si:PDF_delete_textflow"
	, &py_p, &textflow)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_delete_textflow(
p, textflow);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_encoding_set_char(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_encoding_set_char(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * encoding;
    int slot;
    const char * glyphname;
    int uv;


    if (!PyArg_ParseTuple(args, "ssisi:PDF_encoding_set_char"
	, &py_p, &encoding, &slot, &glyphname, &uv)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_encoding_set_char(
p, encoding, slot, glyphname, uv);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_end_document(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_end_document(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */


    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_end_document"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        PDF_end_document(
p, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_end_font(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_end_font(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;


    if (!PyArg_ParseTuple(args, "s:PDF_end_font"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_end_font(
p);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_end_glyph(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_end_glyph(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;


    if (!PyArg_ParseTuple(args, "s:PDF_end_glyph"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_end_glyph(
p);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_end_item(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_end_item(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int id;


    if (!PyArg_ParseTuple(args, "si:PDF_end_item"
	, &py_p, &id)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_end_item(
p, id);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_end_layer(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_end_layer(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;


    if (!PyArg_ParseTuple(args, "s:PDF_end_layer"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_end_layer(
p);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_end_mc(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_end_mc(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;


    if (!PyArg_ParseTuple(args, "s:PDF_end_mc"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_end_mc(
p);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_end_page(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_end_page(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;


    if (!PyArg_ParseTuple(args, "s:PDF_end_page"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_end_page(
p);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_end_page_ext(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_end_page_ext(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */


    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_end_page_ext"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        PDF_end_page_ext(
p, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_end_pattern(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_end_pattern(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;


    if (!PyArg_ParseTuple(args, "s:PDF_end_pattern"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_end_pattern(
p);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_end_template(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_end_template(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;


    if (!PyArg_ParseTuple(args, "s:PDF_end_template"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_end_template(
p);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_endpath(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_endpath(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;


    if (!PyArg_ParseTuple(args, "s:PDF_endpath"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_endpath(
p);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_fill(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_fill(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;


    if (!PyArg_ParseTuple(args, "s:PDF_fill"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_fill(
p);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_fill_imageblock(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_fill_imageblock(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int page;
    const char * blockname = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * blockname_str = NULL;
    Py_ssize_t blockname_len;
#endif /* PDF_UNICODE_WRAPPER */
    int image;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "si"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	"i"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_fill_imageblock"
	, &py_p, &page
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &blockname_str, &blockname_len
#else
	, &blockname
#endif /* PDF_UNICODE_WRAPPER */
	, &image
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        blockname = PDF_utf16_to_utf8(p, blockname_str, blockname_len, NULL);
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_fill_imageblock(
p, page, blockname, image, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)blockname_str);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)blockname_str);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_fill_pdfblock(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_fill_pdfblock(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int page;
    const char * blockname = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * blockname_str = NULL;
    Py_ssize_t blockname_len;
#endif /* PDF_UNICODE_WRAPPER */
    int contents;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "si"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	"i"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_fill_pdfblock"
	, &py_p, &page
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &blockname_str, &blockname_len
#else
	, &blockname
#endif /* PDF_UNICODE_WRAPPER */
	, &contents
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        blockname = PDF_utf16_to_utf8(p, blockname_str, blockname_len, NULL);
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_fill_pdfblock(
p, page, blockname, contents, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)blockname_str);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)blockname_str);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_fill_stroke(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_fill_stroke(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;


    if (!PyArg_ParseTuple(args, "s:PDF_fill_stroke"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_fill_stroke(
p);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_fill_textblock(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_fill_textblock(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int page;
    const char * blockname = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * blockname_str = NULL;
    Py_ssize_t blockname_len;
#endif /* PDF_UNICODE_WRAPPER */
    const char * text = NULL;
    Py_ssize_t text_len;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "si"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	""
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	""
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_fill_textblock"
	, &py_p, &page
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &blockname_str, &blockname_len
#else
	, &blockname
#endif /* PDF_UNICODE_WRAPPER */
	
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &text, &text_len
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        blockname = PDF_utf16_to_utf8(p, blockname_str, blockname_len, NULL);
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_fill_textblock(
p, page, blockname, text, (int)text_len, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)blockname_str);
    PyMem_Free((void *)text);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)blockname_str);
    PyMem_Free((void *)text);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_findfont(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_findfont(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * fontname;
    const char * encoding;
    int embed;
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "sssi:PDF_findfont"
	, &py_p, &fontname, &encoding, &embed)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            _retval = PDF_findfont(
p, fontname, encoding, embed);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_fit_image(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_fit_image(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int image;
    double x;
    double y;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */


    if (!PyArg_ParseTuple(args, "sidd"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_fit_image"
	, &py_p, &image, &x, &y
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        PDF_fit_image(
p, image, x, y, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_fit_pdi_page(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_fit_pdi_page(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int page;
    double x;
    double y;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */


    if (!PyArg_ParseTuple(args, "sidd"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_fit_pdi_page"
	, &py_p, &page, &x, &y
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        PDF_fit_pdi_page(
p, page, x, y, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_fit_table(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_fit_table(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int table;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    const char PDF_VOLATILE *_retval = 0;

    if (!PyArg_ParseTuple(args, "sidddd"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_fit_table"
	, &py_p, &table, &llx, &lly, &urx, &ury
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_fit_table(
p, table, llx, lly, urx, ury, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("s", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_fit_textflow(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_fit_textflow(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int textflow;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    const char PDF_VOLATILE *_retval = 0;

    if (!PyArg_ParseTuple(args, "sidddd"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_fit_textflow"
	, &py_p, &textflow, &llx, &lly, &urx, &ury
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_fit_textflow(
p, textflow, llx, lly, urx, ury, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("s", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_fit_textline(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_fit_textline(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * text = NULL;
    Py_ssize_t text_len;
    double x;
    double y;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */


    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	"dd"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_fit_textline"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &text, &text_len, &x, &y
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        PDF_fit_textline(
p, text, (int)text_len, x, y, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)text);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)text);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_get_apiname(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_get_apiname(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char PDF_VOLATILE *_retval = 0;

    if (!PyArg_ParseTuple(args, "s:PDF_get_apiname"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            _retval = PDF_get_apiname(
p);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    return Py_BuildValue("s", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_get_buffer(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_get_buffer(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    long size;
    const char PDF_VOLATILE *_retval = 0;

    if (!PyArg_ParseTuple(args, "s:PDF_get_buffer"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            _retval = PDF_get_buffer(
p, &size);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    

#if PY_MAJOR_VERSION >= 3
    return Py_BuildValue("y#", _retval, size);
#else /* PY_MAJOR_VERSION >= 3 */
    return Py_BuildValue("s#", _retval, size);
#endif /* PY_MAJOR_VERSION >= 3 */
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_get_errmsg(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_get_errmsg(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char PDF_VOLATILE *_retval = 0;

    if (!PyArg_ParseTuple(args, "s:PDF_get_errmsg"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            _retval = PDF_get_errmsg(
p);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    return Py_BuildValue("s", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_get_errnum(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_get_errnum(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "s:PDF_get_errnum"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            _retval = PDF_get_errnum(
p);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_get_parameter(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_get_parameter(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * key;
    double modifier;
    const char PDF_VOLATILE *_retval = 0;

    if (!PyArg_ParseTuple(args, "ssd:PDF_get_parameter"
	, &py_p, &key, &modifier)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            _retval = PDF_get_parameter(
p, key, modifier);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    return Py_BuildValue("s", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_get_pdi_parameter(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_get_pdi_parameter(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * key;
    int doc;
    int page;
    int reserved;
    int len;
    const char PDF_VOLATILE *_retval = 0;

    if (!PyArg_ParseTuple(args, "ssiii:PDF_get_pdi_parameter"
	, &py_p, &key, &doc, &page, &reserved)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            _retval = PDF_get_pdi_parameter(
p, key, doc, page, reserved, &len);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    

#if PY_MAJOR_VERSION >= 3
    return Py_BuildValue("y#", _retval, len);
#else /* PY_MAJOR_VERSION >= 3 */
    return Py_BuildValue("s#", _retval, len);
#endif /* PY_MAJOR_VERSION >= 3 */
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_get_pdi_value(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_get_pdi_value(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * key;
    int doc;
    int page;
    int reserved;
    double PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "ssiii:PDF_get_pdi_value"
	, &py_p, &key, &doc, &page, &reserved)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            _retval = PDF_get_pdi_value(
p, key, doc, page, reserved);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    return Py_BuildValue("d", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_get_value(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_get_value(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * key;
    double modifier;
    double PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "ssd:PDF_get_value"
	, &py_p, &key, &modifier)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            _retval = PDF_get_value(
p, key, modifier);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    return Py_BuildValue("d", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_info_font(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_info_font(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int font;
    const char * keyword;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    double PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "sis"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_info_font"
	, &py_p, &font, &keyword
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_info_font(
p, font, keyword, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("d", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_info_matchbox(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_info_matchbox(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * boxname = NULL;
    Py_ssize_t boxname_len;
    int num;
    const char * keyword;
    double PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	"is:PDF_info_matchbox"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &boxname, &boxname_len, &num, &keyword)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_info_matchbox(
p, boxname, 
#ifdef PDF_UNICODE_WRAPPER
	boxname_len
#else
	0
#endif /* PDF_UNICODE_WRAPPER */
	, num, keyword);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)boxname);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)boxname);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("d", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_info_table(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_info_table(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int table;
    const char * keyword;
    double PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "sis:PDF_info_table"
	, &py_p, &table, &keyword)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            _retval = PDF_info_table(
p, table, keyword);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    return Py_BuildValue("d", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_info_textflow(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_info_textflow(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int textflow;
    const char * keyword;
    double PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "sis:PDF_info_textflow"
	, &py_p, &textflow, &keyword)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            _retval = PDF_info_textflow(
p, textflow, keyword);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    return Py_BuildValue("d", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_info_textline(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_info_textline(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * text = NULL;
    Py_ssize_t text_len;
    const char * keyword;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    double PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	"s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_info_textline"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &text, &text_len, &keyword
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_info_textline(
p, text, (int)text_len, keyword, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)text);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)text);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("d", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_initgraphics(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_initgraphics(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;


    if (!PyArg_ParseTuple(args, "s:PDF_initgraphics"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_initgraphics(
p);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_lineto(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_lineto(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double x;
    double y;


    if (!PyArg_ParseTuple(args, "sdd:PDF_lineto"
	, &py_p, &x, &y)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_lineto(
p, x, y);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_load_font(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_load_font(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * fontname = NULL;
    Py_ssize_t fontname_len;
    const char * encoding;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	"s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_load_font"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &fontname, &fontname_len, &encoding
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_load_font(
p, fontname, 
#ifdef PDF_UNICODE_WRAPPER
	fontname_len
#else
	0
#endif /* PDF_UNICODE_WRAPPER */
	, encoding, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)fontname);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)fontname);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_load_iccprofile(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_load_iccprofile(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * profilename = NULL;
    Py_ssize_t profilename_len;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	""
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_load_iccprofile"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &profilename, &profilename_len
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_load_iccprofile(
p, profilename, 
#ifdef PDF_UNICODE_WRAPPER
	profilename_len
#else
	0
#endif /* PDF_UNICODE_WRAPPER */
	, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)profilename);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)profilename);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_load_image(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_load_image(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * imagetype;
    const char * filename = NULL;
    Py_ssize_t filename_len;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "ss"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	""
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_load_image"
	, &py_p, &imagetype
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &filename, &filename_len
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_load_image(
p, imagetype, filename, 
#ifdef PDF_UNICODE_WRAPPER
	filename_len
#else
	0
#endif /* PDF_UNICODE_WRAPPER */
	, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)filename);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)filename);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_makespotcolor(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_makespotcolor(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * spotname;
    Py_ssize_t reserved;
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "ss#:PDF_makespotcolor"
	, &py_p, &spotname, &reserved)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_makespotcolor(
p, spotname, 0);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_moveto(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_moveto(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double x;
    double y;


    if (!PyArg_ParseTuple(args, "sdd:PDF_moveto"
	, &py_p, &x, &y)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_moveto(
p, x, y);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_open_CCITT(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_open_CCITT(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * filename;
    int width;
    int height;
    int BitReverse;
    int K;
    int BlackIs1;
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "ssiiiii:PDF_open_CCITT"
	, &py_p, &filename, &width, &height, &BitReverse, &K, &BlackIs1)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            _retval = PDF_open_CCITT(
p, filename, width, height, BitReverse, K, BlackIs1);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_open_file(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_open_file(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * filename;
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "ss:PDF_open_file"
	, &py_p, &filename)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            _retval = PDF_open_file(
p, filename);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_open_image_file(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_open_image_file(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * imagetype;
    const char * filename;
    const char * stringparam;
    int intparam;
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "ssssi:PDF_open_image_file"
	, &py_p, &imagetype, &filename, &stringparam, &intparam)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            _retval = PDF_open_image_file(
p, imagetype, filename, stringparam, intparam);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_open_pdi_document(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_open_pdi_document(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * filename = NULL;
    Py_ssize_t filename_len;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	""
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_open_pdi_document"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &filename, &filename_len
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_open_pdi_document(
p, filename, 
#ifdef PDF_UNICODE_WRAPPER
	filename_len
#else
	0
#endif /* PDF_UNICODE_WRAPPER */
	, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)filename);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)filename);
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_open_pdi_page(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_open_pdi_page(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int doc;
    int pagenumber;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "sii"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_open_pdi_page"
	, &py_p, &doc, &pagenumber
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_open_pdi_page(
p, doc, pagenumber, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_pcos_get_number(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_pcos_get_number(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int doc;
    const char * path = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * path_str = NULL;
    Py_ssize_t path_len;
#endif /* PDF_UNICODE_WRAPPER */
    double PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "si"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_pcos_get_number"
	, &py_p, &doc
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &path_str, &path_len
#else
	, &path
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        path = PDF_utf16_to_utf8(p, path_str, path_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_pcos_get_number(
p, doc, "%s", path);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)path_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)path_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("d", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_pcos_get_string(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_pcos_get_string(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int doc;
    const char * path = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * path_str = NULL;
    Py_ssize_t path_len;
#endif /* PDF_UNICODE_WRAPPER */
    const char PDF_VOLATILE *_retval = 0;

    if (!PyArg_ParseTuple(args, "si"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_pcos_get_string"
	, &py_p, &doc
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &path_str, &path_len
#else
	, &path
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        path = PDF_utf16_to_utf8(p, path_str, path_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_pcos_get_string(
p, doc, "%s", path);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)path_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)path_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("s", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_pcos_get_stream(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_pcos_get_stream(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int doc;
    int length;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    const char * path = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * path_str = NULL;
    Py_ssize_t path_len;
#endif /* PDF_UNICODE_WRAPPER */
    const char PDF_VOLATILE *_retval = 0;

    if (!PyArg_ParseTuple(args, "si"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	""
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_pcos_get_stream"
	, &py_p, &doc
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &path_str, &path_len
#else
	, &path
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
        path = PDF_utf16_to_utf8(p, path_str, path_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_pcos_get_stream(
p, doc, &length, optlist, "%s", path);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
    PyMem_Free((void *)path_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
    PyMem_Free((void *)path_str);
#endif /* PDF_UNICODE_WRAPPER */

#if PY_MAJOR_VERSION >= 3
    return Py_BuildValue("y#", _retval, length);
#else /* PY_MAJOR_VERSION >= 3 */
    return Py_BuildValue("s#", _retval, length);
#endif /* PY_MAJOR_VERSION >= 3 */
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_place_image(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_place_image(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int image;
    double x;
    double y;
    double scale;


    if (!PyArg_ParseTuple(args, "siddd:PDF_place_image"
	, &py_p, &image, &x, &y, &scale)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_place_image(
p, image, x, y, scale);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_place_pdi_page(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_place_pdi_page(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int page;
    double x;
    double y;
    double sx;
    double sy;


    if (!PyArg_ParseTuple(args, "sidddd:PDF_place_pdi_page"
	, &py_p, &page, &x, &y, &sx, &sy)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_place_pdi_page(
p, page, x, y, sx, sy);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_process_pdi(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_process_pdi(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int doc;
    int page;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "sii"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_process_pdi"
	, &py_p, &doc, &page
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_process_pdi(
p, doc, page, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_rect(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_rect(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double x;
    double y;
    double width;
    double height;


    if (!PyArg_ParseTuple(args, "sdddd:PDF_rect"
	, &py_p, &x, &y, &width, &height)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_rect(
p, x, y, width, height);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_restore(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_restore(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;


    if (!PyArg_ParseTuple(args, "s:PDF_restore"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_restore(
p);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_resume_page(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_resume_page(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */


    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_resume_page"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        PDF_resume_page(
p, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_rotate(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_rotate(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double phi;


    if (!PyArg_ParseTuple(args, "sd:PDF_rotate"
	, &py_p, &phi)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_rotate(
p, phi);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_save(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_save(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;


    if (!PyArg_ParseTuple(args, "s:PDF_save"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_save(
p);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_scale(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_scale(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double sx;
    double sy;


    if (!PyArg_ParseTuple(args, "sdd:PDF_scale"
	, &py_p, &sx, &sy)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_scale(
p, sx, sy);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_set_border_color(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_set_border_color(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double red;
    double green;
    double blue;


    if (!PyArg_ParseTuple(args, "sddd:PDF_set_border_color"
	, &py_p, &red, &green, &blue)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_set_border_color(
p, red, green, blue);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_set_border_dash(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_set_border_dash(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double b;
    double w;


    if (!PyArg_ParseTuple(args, "sdd:PDF_set_border_dash"
	, &py_p, &b, &w)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_set_border_dash(
p, b, w);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_set_border_style(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_set_border_style(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * style;
    double width;


    if (!PyArg_ParseTuple(args, "ssd:PDF_set_border_style"
	, &py_p, &style, &width)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_set_border_style(
p, style, width);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_set_gstate(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_set_gstate(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int gstate;


    if (!PyArg_ParseTuple(args, "si:PDF_set_gstate"
	, &py_p, &gstate)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_set_gstate(
p, gstate);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_set_info(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_set_info(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * key = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * key_str = NULL;
    Py_ssize_t key_len;
#endif /* PDF_UNICODE_WRAPPER */
    const char * value = NULL;
    Py_ssize_t value_len;


    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	""
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_set_info"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &key_str, &key_len
#else
	, &key
#endif /* PDF_UNICODE_WRAPPER */
	
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &value, &value_len)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        key = PDF_utf16_to_utf8(p, key_str, key_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        PDF_set_info2(
p, key, value, (int)value_len);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)key_str);
    PyMem_Free((void *)value);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)key_str);
    PyMem_Free((void *)value);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_set_layer_dependency(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_set_layer_dependency(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * type;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */


    if (!PyArg_ParseTuple(args, "ss"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_set_layer_dependency"
	, &py_p, &type
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        PDF_set_layer_dependency(
p, type, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_set_parameter(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_set_parameter(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * key;
    const char * value = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * value_str = NULL;
    Py_ssize_t value_len;
#endif /* PDF_UNICODE_WRAPPER */


    if (!PyArg_ParseTuple(args, "ss"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_set_parameter"
	, &py_p, &key
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &value_str, &value_len
#else
	, &value
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        value = PDF_utf16_to_utf8(p, value_str, value_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        PDF_set_parameter(
p, key, value);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)value_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)value_str);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_set_text_pos(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_set_text_pos(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double x;
    double y;


    if (!PyArg_ParseTuple(args, "sdd:PDF_set_text_pos"
	, &py_p, &x, &y)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_set_text_pos(
p, x, y);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_set_value(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_set_value(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * key;
    double value;


    if (!PyArg_ParseTuple(args, "ssd:PDF_set_value"
	, &py_p, &key, &value)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_set_value(
p, key, value);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_setcolor(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_setcolor(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * fstype;
    const char * colorspace;
    double c1;
    double c2;
    double c3;
    double c4;


    if (!PyArg_ParseTuple(args, "sssdddd:PDF_setcolor"
	, &py_p, &fstype, &colorspace, &c1, &c2, &c3, &c4)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_setcolor(
p, fstype, colorspace, c1, c2, c3, c4);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_setdash(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_setdash(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double b;
    double w;


    if (!PyArg_ParseTuple(args, "sdd:PDF_setdash"
	, &py_p, &b, &w)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_setdash(
p, b, w);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_setdashpattern(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_setdashpattern(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */


    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_setdashpattern"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        PDF_setdashpattern(
p, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_setflat(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_setflat(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double flatness;


    if (!PyArg_ParseTuple(args, "sd:PDF_setflat"
	, &py_p, &flatness)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_setflat(
p, flatness);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_setfont(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_setfont(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int font;
    double fontsize;


    if (!PyArg_ParseTuple(args, "sid:PDF_setfont"
	, &py_p, &font, &fontsize)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_setfont(
p, font, fontsize);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_setgray(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_setgray(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double gray;


    if (!PyArg_ParseTuple(args, "sd:PDF_setgray"
	, &py_p, &gray)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_setgray(
p, gray);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_setgray_fill(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_setgray_fill(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double gray;


    if (!PyArg_ParseTuple(args, "sd:PDF_setgray_fill"
	, &py_p, &gray)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_setgray_fill(
p, gray);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_setgray_stroke(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_setgray_stroke(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double gray;


    if (!PyArg_ParseTuple(args, "sd:PDF_setgray_stroke"
	, &py_p, &gray)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_setgray_stroke(
p, gray);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_setlinecap(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_setlinecap(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int linecap;


    if (!PyArg_ParseTuple(args, "si:PDF_setlinecap"
	, &py_p, &linecap)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_setlinecap(
p, linecap);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_setlinejoin(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_setlinejoin(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int linejoin;


    if (!PyArg_ParseTuple(args, "si:PDF_setlinejoin"
	, &py_p, &linejoin)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_setlinejoin(
p, linejoin);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_setlinewidth(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_setlinewidth(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double width;


    if (!PyArg_ParseTuple(args, "sd:PDF_setlinewidth"
	, &py_p, &width)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_setlinewidth(
p, width);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_setmatrix(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_setmatrix(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double a;
    double b;
    double c;
    double d;
    double e;
    double f;


    if (!PyArg_ParseTuple(args, "sdddddd:PDF_setmatrix"
	, &py_p, &a, &b, &c, &d, &e, &f)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_setmatrix(
p, a, b, c, d, e, f);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_setmiterlimit(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_setmiterlimit(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double miter;


    if (!PyArg_ParseTuple(args, "sd:PDF_setmiterlimit"
	, &py_p, &miter)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_setmiterlimit(
p, miter);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_setrgbcolor(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_setrgbcolor(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double red;
    double green;
    double blue;


    if (!PyArg_ParseTuple(args, "sddd:PDF_setrgbcolor"
	, &py_p, &red, &green, &blue)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_setrgbcolor(
p, red, green, blue);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_setrgbcolor_fill(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_setrgbcolor_fill(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double red;
    double green;
    double blue;


    if (!PyArg_ParseTuple(args, "sddd:PDF_setrgbcolor_fill"
	, &py_p, &red, &green, &blue)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_setrgbcolor_fill(
p, red, green, blue);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_setrgbcolor_stroke(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_setrgbcolor_stroke(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double red;
    double green;
    double blue;


    if (!PyArg_ParseTuple(args, "sddd:PDF_setrgbcolor_stroke"
	, &py_p, &red, &green, &blue)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_setrgbcolor_stroke(
p, red, green, blue);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_shading(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_shading(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * shtype;
    double x_0;
    double y_0;
    double x_1;
    double y_1;
    double c_1;
    double c_2;
    double c_3;
    double c_4;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "ssdddddddd"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_shading"
	, &py_p, &shtype, &x_0, &y_0, &x_1, &y_1, &c_1, &c_2, &c_3, &c_4
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_shading(
p, shtype, x_0, y_0, x_1, y_1, c_1, c_2, 
c_3, c_4, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_shading_pattern(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_shading_pattern(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int shading;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */
    int PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "si"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_shading_pattern"
	, &py_p, &shading
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_shading_pattern(
p, shading, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("i", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_shfill(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_shfill(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    int shading;


    if (!PyArg_ParseTuple(args, "si:PDF_shfill"
	, &py_p, &shading)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_shfill(
p, shading);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_show(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_show(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * text = NULL;
    Py_ssize_t text_len;


    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_show"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &text, &text_len)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
#endif /* PDF_UNICODE_WRAPPER */
        PDF_show2(
p, text, (int)text_len);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)text);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)text);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_show_xy(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_show_xy(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * text = NULL;
    Py_ssize_t text_len;
    double x;
    double y;


    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	"dd:PDF_show_xy"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &text, &text_len, &x, &y)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
#endif /* PDF_UNICODE_WRAPPER */
        PDF_show_xy2(
p, text, (int)text_len, x, y);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)text);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)text);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_skew(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_skew(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double alpha;
    double beta;


    if (!PyArg_ParseTuple(args, "sdd:PDF_skew"
	, &py_p, &alpha, &beta)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_skew(
p, alpha, beta);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_stringwidth(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_stringwidth(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * text = NULL;
    Py_ssize_t text_len;
    int font;
    double fontsize;
    double PDF_VOLATILE _retval = -1;

    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s#"
#endif /* PDF_UNICODE_WRAPPER */
	"id:PDF_stringwidth"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV
#endif /* PDF_UNICODE_WRAPPER */
	, &text, &text_len, &font, &fontsize)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
#endif /* PDF_UNICODE_WRAPPER */
        _retval = PDF_stringwidth2(
p, text, (int)text_len, font, fontsize);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)text);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)text);
#endif /* PDF_UNICODE_WRAPPER */
    return Py_BuildValue("d", _retval);
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_stroke(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_stroke(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;


    if (!PyArg_ParseTuple(args, "s:PDF_stroke"
	, &py_p)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_stroke(
p);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_suspend_page(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_suspend_page(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    const char * optlist = NULL;
#ifdef PDF_UNICODE_WRAPPER
    const char * optlist_str = NULL;
    Py_ssize_t optlist_len;
#endif /* PDF_UNICODE_WRAPPER */


    if (!PyArg_ParseTuple(args, "s"
#ifdef PDF_UNICODE_WRAPPER
	"es#"
#else
	"s"
#endif /* PDF_UNICODE_WRAPPER */
	":PDF_suspend_page"
	, &py_p
#ifdef PDF_UNICODE_WRAPPER
	, UTFCONV, &optlist_str, &optlist_len
#else
	, &optlist
#endif /* PDF_UNICODE_WRAPPER */
	)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

    #ifdef PDF_UNICODE_WRAPPER
        optlist = PDF_utf16_to_utf8(p, optlist_str, optlist_len, NULL);
#endif /* PDF_UNICODE_WRAPPER */
        PDF_suspend_page(
p, optlist);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
#ifdef PDF_UNICODE_WRAPPER
    PyMem_Free((void *)optlist_str);
#endif /* PDF_UNICODE_WRAPPER */
    Py_INCREF(Py_None); return Py_None;
}

    
static PyObject *
#ifdef PDF_UNICODE_WRAPPER
_wrap_PDF_translate(PyObject *self, PyObject *args)
#else
_nuwrap_PDF_translate(PyObject *self, PyObject *args)
#endif /* PDF_UNICODE_WRAPPER */
{
    char *py_p = 0;
    PyThreadState *_save = NULL;
    PDF * p;
    double tx;
    double ty;


    if (!PyArg_ParseTuple(args, "sdd:PDF_translate"
	, &py_p, &tx, &ty)) {
        return NULL;
    }
    if (py_p && SWIG_GetPtr(py_p, (void *) &p, "_PDF_p")) {
        PDF_WrongPDFHandle("PDF_activate_item");
        return NULL;
    }

    _save = PyEval_SaveThread();

    PDF_TRY(p) {

            PDF_translate(
p, tx, ty);
    } PDF_CATCH(p) { 
	PyEval_RestoreThread(_save);
	PDF_throw_pyexception(self, p);
        return NULL;
    }

    PyEval_RestoreThread(_save);
    
    Py_INCREF(Py_None); return Py_None;
}
#endif /* defined(_WRAP_CODE) */
#if defined(_WRAP_newXS)
#if defined(PDF_UNICODE_WRAPPER)
    { "PDF_activate_item", _wrap_PDF_activate_item, 1 },
    { "PDF_create_3dview", _wrap_PDF_create_3dview, 1 },
    { "PDF_load_3ddata", _wrap_PDF_load_3ddata, 1 },
    { "PDF_add_bookmark", _wrap_PDF_add_bookmark, 1 },
    { "PDF_add_launchlink", _wrap_PDF_add_launchlink, 1 },
    { "PDF_add_locallink", _wrap_PDF_add_locallink, 1 },
    { "PDF_add_nameddest", _wrap_PDF_add_nameddest, 1 },
    { "PDF_add_note", _wrap_PDF_add_note, 1 },
    { "PDF_add_pdflink", _wrap_PDF_add_pdflink, 1 },
    { "PDF_add_table_cell", _wrap_PDF_add_table_cell, 1 },
    { "PDF_add_textflow", _wrap_PDF_add_textflow, 1 },
    { "PDF_add_thumbnail", _wrap_PDF_add_thumbnail, 1 },
    { "PDF_add_weblink", _wrap_PDF_add_weblink, 1 },
    { "PDF_arc", _wrap_PDF_arc, 1 },
    { "PDF_arcn", _wrap_PDF_arcn, 1 },
    { "PDF_attach_file", _wrap_PDF_attach_file, 1 },
    { "PDF_begin_document", _wrap_PDF_begin_document, 1 },
    { "PDF_begin_font", _wrap_PDF_begin_font, 1 },
    { "PDF_begin_glyph", _wrap_PDF_begin_glyph, 1 },
    { "PDF_begin_item", _wrap_PDF_begin_item, 1 },
    { "PDF_begin_layer", _wrap_PDF_begin_layer, 1 },
    { "PDF_begin_page", _wrap_PDF_begin_page, 1 },
    { "PDF_begin_page_ext", _wrap_PDF_begin_page_ext, 1 },
    { "PDF_begin_pattern", _wrap_PDF_begin_pattern, 1 },
    { "PDF_begin_template", _wrap_PDF_begin_template, 1 },
    { "PDF_begin_template_ext", _wrap_PDF_begin_template_ext, 1 },
    { "PDF_circle", _wrap_PDF_circle, 1 },
    { "PDF_clip", _wrap_PDF_clip, 1 },
    { "PDF_close", _wrap_PDF_close, 1 },
    { "PDF_close_image", _wrap_PDF_close_image, 1 },
    { "PDF_close_pdi", _wrap_PDF_close_pdi, 1 },
    { "PDF_close_pdi_document", _wrap_PDF_close_pdi_document, 1 },
    { "PDF_close_pdi_page", _wrap_PDF_close_pdi_page, 1 },
    { "PDF_closepath", _wrap_PDF_closepath, 1 },
    { "PDF_closepath_fill_stroke", _wrap_PDF_closepath_fill_stroke, 1 },
    { "PDF_closepath_stroke", _wrap_PDF_closepath_stroke, 1 },
    { "PDF_concat", _wrap_PDF_concat, 1 },
    { "PDF_continue_text", _wrap_PDF_continue_text, 1 },
    { "PDF_create_action", _wrap_PDF_create_action, 1 },
    { "PDF_create_annotation", _wrap_PDF_create_annotation, 1 },
    { "PDF_create_bookmark", _wrap_PDF_create_bookmark, 1 },
    { "PDF_create_field", _wrap_PDF_create_field, 1 },
    { "PDF_create_fieldgroup", _wrap_PDF_create_fieldgroup, 1 },
    { "PDF_create_gstate", _wrap_PDF_create_gstate, 1 },
    { "PDF_create_pvf", _wrap_PDF_create_pvf, 1 },
    { "PDF_create_textflow", _wrap_PDF_create_textflow, 1 },
    { "PDF_curveto", _wrap_PDF_curveto, 1 },
    { "PDF_define_layer", _wrap_PDF_define_layer, 1 },
    { "PDF_delete", _wrap_PDF_delete, 1 },
    { "PDF_delete_pvf", _wrap_PDF_delete_pvf, 1 },
    { "PDF_delete_table", _wrap_PDF_delete_table, 1 },
    { "PDF_delete_textflow", _wrap_PDF_delete_textflow, 1 },
    { "PDF_encoding_set_char", _wrap_PDF_encoding_set_char, 1 },
    { "PDF_end_document", _wrap_PDF_end_document, 1 },
    { "PDF_end_font", _wrap_PDF_end_font, 1 },
    { "PDF_end_glyph", _wrap_PDF_end_glyph, 1 },
    { "PDF_end_item", _wrap_PDF_end_item, 1 },
    { "PDF_end_layer", _wrap_PDF_end_layer, 1 },
    { "PDF_end_mc", _wrap_PDF_end_mc, 1 },
    { "PDF_end_page", _wrap_PDF_end_page, 1 },
    { "PDF_end_page_ext", _wrap_PDF_end_page_ext, 1 },
    { "PDF_end_pattern", _wrap_PDF_end_pattern, 1 },
    { "PDF_end_template", _wrap_PDF_end_template, 1 },
    { "PDF_endpath", _wrap_PDF_endpath, 1 },
    { "PDF_fill", _wrap_PDF_fill, 1 },
    { "PDF_fill_imageblock", _wrap_PDF_fill_imageblock, 1 },
    { "PDF_fill_pdfblock", _wrap_PDF_fill_pdfblock, 1 },
    { "PDF_fill_stroke", _wrap_PDF_fill_stroke, 1 },
    { "PDF_fill_textblock", _wrap_PDF_fill_textblock, 1 },
    { "PDF_findfont", _wrap_PDF_findfont, 1 },
    { "PDF_fit_image", _wrap_PDF_fit_image, 1 },
    { "PDF_fit_pdi_page", _wrap_PDF_fit_pdi_page, 1 },
    { "PDF_fit_table", _wrap_PDF_fit_table, 1 },
    { "PDF_fit_textflow", _wrap_PDF_fit_textflow, 1 },
    { "PDF_fit_textline", _wrap_PDF_fit_textline, 1 },
    { "PDF_get_apiname", _wrap_PDF_get_apiname, 1 },
    { "PDF_get_buffer", _wrap_PDF_get_buffer, 1 },
    { "PDF_get_errmsg", _wrap_PDF_get_errmsg, 1 },
    { "PDF_get_errnum", _wrap_PDF_get_errnum, 1 },
    { "PDF_get_parameter", _wrap_PDF_get_parameter, 1 },
    { "PDF_get_pdi_parameter", _wrap_PDF_get_pdi_parameter, 1 },
    { "PDF_get_pdi_value", _wrap_PDF_get_pdi_value, 1 },
    { "PDF_get_value", _wrap_PDF_get_value, 1 },
    { "PDF_info_font", _wrap_PDF_info_font, 1 },
    { "PDF_info_matchbox", _wrap_PDF_info_matchbox, 1 },
    { "PDF_info_table", _wrap_PDF_info_table, 1 },
    { "PDF_info_textflow", _wrap_PDF_info_textflow, 1 },
    { "PDF_info_textline", _wrap_PDF_info_textline, 1 },
    { "PDF_initgraphics", _wrap_PDF_initgraphics, 1 },
    { "PDF_lineto", _wrap_PDF_lineto, 1 },
    { "PDF_load_font", _wrap_PDF_load_font, 1 },
    { "PDF_load_iccprofile", _wrap_PDF_load_iccprofile, 1 },
    { "PDF_load_image", _wrap_PDF_load_image, 1 },
    { "PDF_makespotcolor", _wrap_PDF_makespotcolor, 1 },
    { "PDF_moveto", _wrap_PDF_moveto, 1 },
    { "PDF_new", _wrap_PDF_new, 1 },
    { "PDF_open_CCITT", _wrap_PDF_open_CCITT, 1 },
    { "PDF_open_file", _wrap_PDF_open_file, 1 },
    { "PDF_open_image", _wrap_PDF_open_image, 1 },
    { "PDF_open_image_file", _wrap_PDF_open_image_file, 1 },
    { "PDF_open_pdi", _wrap_PDF_open_pdi, 1 },
    { "PDF_open_pdi_document", _wrap_PDF_open_pdi_document, 1 },
    { "PDF_open_pdi_page", _wrap_PDF_open_pdi_page, 1 },
    { "PDF_pcos_get_number", _wrap_PDF_pcos_get_number, 1 },
    { "PDF_pcos_get_string", _wrap_PDF_pcos_get_string, 1 },
    { "PDF_pcos_get_stream", _wrap_PDF_pcos_get_stream, 1 },
    { "PDF_place_image", _wrap_PDF_place_image, 1 },
    { "PDF_place_pdi_page", _wrap_PDF_place_pdi_page, 1 },
    { "PDF_process_pdi", _wrap_PDF_process_pdi, 1 },
    { "PDF_rect", _wrap_PDF_rect, 1 },
    { "PDF_restore", _wrap_PDF_restore, 1 },
    { "PDF_resume_page", _wrap_PDF_resume_page, 1 },
    { "PDF_rotate", _wrap_PDF_rotate, 1 },
    { "PDF_save", _wrap_PDF_save, 1 },
    { "PDF_scale", _wrap_PDF_scale, 1 },
    { "PDF_set_border_color", _wrap_PDF_set_border_color, 1 },
    { "PDF_set_border_dash", _wrap_PDF_set_border_dash, 1 },
    { "PDF_set_border_style", _wrap_PDF_set_border_style, 1 },
    { "PDF_set_gstate", _wrap_PDF_set_gstate, 1 },
    { "PDF_set_info", _wrap_PDF_set_info, 1 },
    { "PDF_set_layer_dependency", _wrap_PDF_set_layer_dependency, 1 },
    { "PDF_set_parameter", _wrap_PDF_set_parameter, 1 },
    { "PDF_set_text_pos", _wrap_PDF_set_text_pos, 1 },
    { "PDF_set_value", _wrap_PDF_set_value, 1 },
    { "PDF_setcolor", _wrap_PDF_setcolor, 1 },
    { "PDF_setdash", _wrap_PDF_setdash, 1 },
    { "PDF_setdashpattern", _wrap_PDF_setdashpattern, 1 },
    { "PDF_setflat", _wrap_PDF_setflat, 1 },
    { "PDF_setfont", _wrap_PDF_setfont, 1 },
    { "PDF_setgray", _wrap_PDF_setgray, 1 },
    { "PDF_setgray_fill", _wrap_PDF_setgray_fill, 1 },
    { "PDF_setgray_stroke", _wrap_PDF_setgray_stroke, 1 },
    { "PDF_setlinecap", _wrap_PDF_setlinecap, 1 },
    { "PDF_setlinejoin", _wrap_PDF_setlinejoin, 1 },
    { "PDF_setlinewidth", _wrap_PDF_setlinewidth, 1 },
    { "PDF_setmatrix", _wrap_PDF_setmatrix, 1 },
    { "PDF_setmiterlimit", _wrap_PDF_setmiterlimit, 1 },
    { "PDF_setpolydash", _wrap_PDF_setpolydash, 1 },
    { "PDF_setrgbcolor", _wrap_PDF_setrgbcolor, 1 },
    { "PDF_setrgbcolor_fill", _wrap_PDF_setrgbcolor_fill, 1 },
    { "PDF_setrgbcolor_stroke", _wrap_PDF_setrgbcolor_stroke, 1 },
    { "PDF_shading", _wrap_PDF_shading, 1 },
    { "PDF_shading_pattern", _wrap_PDF_shading_pattern, 1 },
    { "PDF_shfill", _wrap_PDF_shfill, 1 },
    { "PDF_show", _wrap_PDF_show, 1 },
    { "PDF_show_xy", _wrap_PDF_show_xy, 1 },
    { "PDF_skew", _wrap_PDF_skew, 1 },
    { "PDF_stringwidth", _wrap_PDF_stringwidth, 1 },
    { "PDF_stroke", _wrap_PDF_stroke, 1 },
    { "PDF_suspend_page", _wrap_PDF_suspend_page, 1 },
    { "PDF_translate", _wrap_PDF_translate, 1 },
#else /* PDF_UNICODE_WRAPPER */
    { "PDF_activate_item", _nuwrap_PDF_activate_item, 1 },
    { "PDF_create_3dview", _nuwrap_PDF_create_3dview, 1 },
    { "PDF_load_3ddata", _nuwrap_PDF_load_3ddata, 1 },
    { "PDF_add_bookmark", _nuwrap_PDF_add_bookmark, 1 },
    { "PDF_add_launchlink", _nuwrap_PDF_add_launchlink, 1 },
    { "PDF_add_locallink", _nuwrap_PDF_add_locallink, 1 },
    { "PDF_add_nameddest", _nuwrap_PDF_add_nameddest, 1 },
    { "PDF_add_note", _nuwrap_PDF_add_note, 1 },
    { "PDF_add_pdflink", _nuwrap_PDF_add_pdflink, 1 },
    { "PDF_add_table_cell", _nuwrap_PDF_add_table_cell, 1 },
    { "PDF_add_textflow", _nuwrap_PDF_add_textflow, 1 },
    { "PDF_add_thumbnail", _nuwrap_PDF_add_thumbnail, 1 },
    { "PDF_add_weblink", _nuwrap_PDF_add_weblink, 1 },
    { "PDF_arc", _nuwrap_PDF_arc, 1 },
    { "PDF_arcn", _nuwrap_PDF_arcn, 1 },
    { "PDF_attach_file", _nuwrap_PDF_attach_file, 1 },
    { "PDF_begin_document", _nuwrap_PDF_begin_document, 1 },
    { "PDF_begin_font", _nuwrap_PDF_begin_font, 1 },
    { "PDF_begin_glyph", _nuwrap_PDF_begin_glyph, 1 },
    { "PDF_begin_item", _nuwrap_PDF_begin_item, 1 },
    { "PDF_begin_layer", _nuwrap_PDF_begin_layer, 1 },
    { "PDF_begin_page", _nuwrap_PDF_begin_page, 1 },
    { "PDF_begin_page_ext", _nuwrap_PDF_begin_page_ext, 1 },
    { "PDF_begin_pattern", _nuwrap_PDF_begin_pattern, 1 },
    { "PDF_begin_template", _nuwrap_PDF_begin_template, 1 },
    { "PDF_begin_template_ext", _nuwrap_PDF_begin_template_ext, 1 },
    { "PDF_circle", _nuwrap_PDF_circle, 1 },
    { "PDF_clip", _nuwrap_PDF_clip, 1 },
    { "PDF_close", _nuwrap_PDF_close, 1 },
    { "PDF_close_image", _nuwrap_PDF_close_image, 1 },
    { "PDF_close_pdi", _nuwrap_PDF_close_pdi, 1 },
    { "PDF_close_pdi_document", _nuwrap_PDF_close_pdi_document, 1 },
    { "PDF_close_pdi_page", _nuwrap_PDF_close_pdi_page, 1 },
    { "PDF_closepath", _nuwrap_PDF_closepath, 1 },
    { "PDF_closepath_fill_stroke", _nuwrap_PDF_closepath_fill_stroke, 1 },
    { "PDF_closepath_stroke", _nuwrap_PDF_closepath_stroke, 1 },
    { "PDF_concat", _nuwrap_PDF_concat, 1 },
    { "PDF_continue_text", _nuwrap_PDF_continue_text, 1 },
    { "PDF_create_action", _nuwrap_PDF_create_action, 1 },
    { "PDF_create_annotation", _nuwrap_PDF_create_annotation, 1 },
    { "PDF_create_bookmark", _nuwrap_PDF_create_bookmark, 1 },
    { "PDF_create_field", _nuwrap_PDF_create_field, 1 },
    { "PDF_create_fieldgroup", _nuwrap_PDF_create_fieldgroup, 1 },
    { "PDF_create_gstate", _nuwrap_PDF_create_gstate, 1 },
    { "PDF_create_pvf", _nuwrap_PDF_create_pvf, 1 },
    { "PDF_create_textflow", _nuwrap_PDF_create_textflow, 1 },
    { "PDF_curveto", _nuwrap_PDF_curveto, 1 },
    { "PDF_define_layer", _nuwrap_PDF_define_layer, 1 },
    { "PDF_delete", _nuwrap_PDF_delete, 1 },
    { "PDF_delete_pvf", _nuwrap_PDF_delete_pvf, 1 },
    { "PDF_delete_table", _nuwrap_PDF_delete_table, 1 },
    { "PDF_delete_textflow", _nuwrap_PDF_delete_textflow, 1 },
    { "PDF_encoding_set_char", _nuwrap_PDF_encoding_set_char, 1 },
    { "PDF_end_document", _nuwrap_PDF_end_document, 1 },
    { "PDF_end_font", _nuwrap_PDF_end_font, 1 },
    { "PDF_end_glyph", _nuwrap_PDF_end_glyph, 1 },
    { "PDF_end_item", _nuwrap_PDF_end_item, 1 },
    { "PDF_end_layer", _nuwrap_PDF_end_layer, 1 },
    { "PDF_end_mc", _nuwrap_PDF_end_mc, 1 },
    { "PDF_end_page", _nuwrap_PDF_end_page, 1 },
    { "PDF_end_page_ext", _nuwrap_PDF_end_page_ext, 1 },
    { "PDF_end_pattern", _nuwrap_PDF_end_pattern, 1 },
    { "PDF_end_template", _nuwrap_PDF_end_template, 1 },
    { "PDF_endpath", _nuwrap_PDF_endpath, 1 },
    { "PDF_fill", _nuwrap_PDF_fill, 1 },
    { "PDF_fill_imageblock", _nuwrap_PDF_fill_imageblock, 1 },
    { "PDF_fill_pdfblock", _nuwrap_PDF_fill_pdfblock, 1 },
    { "PDF_fill_stroke", _nuwrap_PDF_fill_stroke, 1 },
    { "PDF_fill_textblock", _nuwrap_PDF_fill_textblock, 1 },
    { "PDF_findfont", _nuwrap_PDF_findfont, 1 },
    { "PDF_fit_image", _nuwrap_PDF_fit_image, 1 },
    { "PDF_fit_pdi_page", _nuwrap_PDF_fit_pdi_page, 1 },
    { "PDF_fit_table", _nuwrap_PDF_fit_table, 1 },
    { "PDF_fit_textflow", _nuwrap_PDF_fit_textflow, 1 },
    { "PDF_fit_textline", _nuwrap_PDF_fit_textline, 1 },
    { "PDF_get_apiname", _nuwrap_PDF_get_apiname, 1 },
    { "PDF_get_buffer", _nuwrap_PDF_get_buffer, 1 },
    { "PDF_get_errmsg", _nuwrap_PDF_get_errmsg, 1 },
    { "PDF_get_errnum", _nuwrap_PDF_get_errnum, 1 },
    { "PDF_get_parameter", _nuwrap_PDF_get_parameter, 1 },
    { "PDF_get_pdi_parameter", _nuwrap_PDF_get_pdi_parameter, 1 },
    { "PDF_get_pdi_value", _nuwrap_PDF_get_pdi_value, 1 },
    { "PDF_get_value", _nuwrap_PDF_get_value, 1 },
    { "PDF_info_font", _nuwrap_PDF_info_font, 1 },
    { "PDF_info_matchbox", _nuwrap_PDF_info_matchbox, 1 },
    { "PDF_info_table", _nuwrap_PDF_info_table, 1 },
    { "PDF_info_textflow", _nuwrap_PDF_info_textflow, 1 },
    { "PDF_info_textline", _nuwrap_PDF_info_textline, 1 },
    { "PDF_initgraphics", _nuwrap_PDF_initgraphics, 1 },
    { "PDF_lineto", _nuwrap_PDF_lineto, 1 },
    { "PDF_load_font", _nuwrap_PDF_load_font, 1 },
    { "PDF_load_iccprofile", _nuwrap_PDF_load_iccprofile, 1 },
    { "PDF_load_image", _nuwrap_PDF_load_image, 1 },
    { "PDF_makespotcolor", _nuwrap_PDF_makespotcolor, 1 },
    { "PDF_moveto", _nuwrap_PDF_moveto, 1 },
    { "PDF_new", _nuwrap_PDF_new, 1 },
    { "PDF_open_CCITT", _nuwrap_PDF_open_CCITT, 1 },
    { "PDF_open_file", _nuwrap_PDF_open_file, 1 },
    { "PDF_open_image", _nuwrap_PDF_open_image, 1 },
    { "PDF_open_image_file", _nuwrap_PDF_open_image_file, 1 },
    { "PDF_open_pdi", _nuwrap_PDF_open_pdi, 1 },
    { "PDF_open_pdi_document", _nuwrap_PDF_open_pdi_document, 1 },
    { "PDF_open_pdi_page", _nuwrap_PDF_open_pdi_page, 1 },
    { "PDF_pcos_get_number", _nuwrap_PDF_pcos_get_number, 1 },
    { "PDF_pcos_get_string", _nuwrap_PDF_pcos_get_string, 1 },
    { "PDF_pcos_get_stream", _nuwrap_PDF_pcos_get_stream, 1 },
    { "PDF_place_image", _nuwrap_PDF_place_image, 1 },
    { "PDF_place_pdi_page", _nuwrap_PDF_place_pdi_page, 1 },
    { "PDF_process_pdi", _nuwrap_PDF_process_pdi, 1 },
    { "PDF_rect", _nuwrap_PDF_rect, 1 },
    { "PDF_restore", _nuwrap_PDF_restore, 1 },
    { "PDF_resume_page", _nuwrap_PDF_resume_page, 1 },
    { "PDF_rotate", _nuwrap_PDF_rotate, 1 },
    { "PDF_save", _nuwrap_PDF_save, 1 },
    { "PDF_scale", _nuwrap_PDF_scale, 1 },
    { "PDF_set_border_color", _nuwrap_PDF_set_border_color, 1 },
    { "PDF_set_border_dash", _nuwrap_PDF_set_border_dash, 1 },
    { "PDF_set_border_style", _nuwrap_PDF_set_border_style, 1 },
    { "PDF_set_gstate", _nuwrap_PDF_set_gstate, 1 },
    { "PDF_set_info", _nuwrap_PDF_set_info, 1 },
    { "PDF_set_layer_dependency", _nuwrap_PDF_set_layer_dependency, 1 },
    { "PDF_set_parameter", _nuwrap_PDF_set_parameter, 1 },
    { "PDF_set_text_pos", _nuwrap_PDF_set_text_pos, 1 },
    { "PDF_set_value", _nuwrap_PDF_set_value, 1 },
    { "PDF_setcolor", _nuwrap_PDF_setcolor, 1 },
    { "PDF_setdash", _nuwrap_PDF_setdash, 1 },
    { "PDF_setdashpattern", _nuwrap_PDF_setdashpattern, 1 },
    { "PDF_setflat", _nuwrap_PDF_setflat, 1 },
    { "PDF_setfont", _nuwrap_PDF_setfont, 1 },
    { "PDF_setgray", _nuwrap_PDF_setgray, 1 },
    { "PDF_setgray_fill", _nuwrap_PDF_setgray_fill, 1 },
    { "PDF_setgray_stroke", _nuwrap_PDF_setgray_stroke, 1 },
    { "PDF_setlinecap", _nuwrap_PDF_setlinecap, 1 },
    { "PDF_setlinejoin", _nuwrap_PDF_setlinejoin, 1 },
    { "PDF_setlinewidth", _nuwrap_PDF_setlinewidth, 1 },
    { "PDF_setmatrix", _nuwrap_PDF_setmatrix, 1 },
    { "PDF_setmiterlimit", _nuwrap_PDF_setmiterlimit, 1 },
    { "PDF_setpolydash", _nuwrap_PDF_setpolydash, 1 },
    { "PDF_setrgbcolor", _nuwrap_PDF_setrgbcolor, 1 },
    { "PDF_setrgbcolor_fill", _nuwrap_PDF_setrgbcolor_fill, 1 },
    { "PDF_setrgbcolor_stroke", _nuwrap_PDF_setrgbcolor_stroke, 1 },
    { "PDF_shading", _nuwrap_PDF_shading, 1 },
    { "PDF_shading_pattern", _nuwrap_PDF_shading_pattern, 1 },
    { "PDF_shfill", _nuwrap_PDF_shfill, 1 },
    { "PDF_show", _nuwrap_PDF_show, 1 },
    { "PDF_show_xy", _nuwrap_PDF_show_xy, 1 },
    { "PDF_skew", _nuwrap_PDF_skew, 1 },
    { "PDF_stringwidth", _nuwrap_PDF_stringwidth, 1 },
    { "PDF_stroke", _nuwrap_PDF_stroke, 1 },
    { "PDF_suspend_page", _nuwrap_PDF_suspend_page, 1 },
    { "PDF_translate", _nuwrap_PDF_translate, 1 },
#endif /* PDF_UNICODE_WRAPPER */
#endif /* defined(_WRAP_newXS)*/
