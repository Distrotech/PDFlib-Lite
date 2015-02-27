/* Set this to define when not useing stubs for tcl 8.6 compatibility. */
#undef USE_INTERP_RESULT 1

#if defined(_WRAP_CODE)

    
static int
_wrap_PDF_activate_item(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int id;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_activate_item p id");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_activate_item");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_activate_item");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &id) != TCL_OK)
    {
	PDF_WrongParameter(interp, "id in PDF_activate_item");
	return TCL_ERROR;
    }

    try {
	PDF_activate_item(p, id);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_create_3dview(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * username = NULL;
    int username_len;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_create_3dview p username optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_create_3dview");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_create_3dview");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((username = PDF_GetStringFromObj(p, interp, objv[2], PDF_0UTF16, &username_len)) == NULL)
    {
	PDF_WrongParameter(interp, "username in PDF_create_3dview");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_create_3dview");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_create_3dview(p, username, username_len, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_load_3ddata(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * filename = NULL;
    int filename_len;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_load_3ddata p filename optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_load_3ddata");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_load_3ddata");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((filename = PDF_GetStringFromObj(p, interp, objv[2], PDF_0UTF16, &filename_len)) == NULL)
    {
	PDF_WrongParameter(interp, "filename in PDF_load_3ddata");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_load_3ddata");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_load_3ddata(p, filename, filename_len, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_add_bookmark(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * text = NULL;
    int text_len;
    int parent;
    int open;
    int volatile _retval = -1;

    if (objc != 5)
    {
	PDF_WrongCommand(interp, "PDF_add_bookmark p text parent open");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_add_bookmark");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_add_bookmark");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((text = PDF_GetStringFromObj(p, interp, objv[2], PDF_UTF16, &text_len)) == NULL)
    {
	PDF_WrongParameter(interp, "text in PDF_add_bookmark");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[3], &parent) != TCL_OK)
    {
	PDF_WrongParameter(interp, "parent in PDF_add_bookmark");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[4], &open) != TCL_OK)
    {
	PDF_WrongParameter(interp, "open in PDF_add_bookmark");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_add_bookmark2(p, text, text_len, parent, open);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_add_launchlink(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * filename = NULL;
    int filename_len;


    if (objc != 7)
    {
	PDF_WrongCommand(interp, "PDF_add_launchlink p llx lly urx ury filename");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_add_launchlink");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_add_launchlink");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &llx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "llx in PDF_add_launchlink");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &lly) != TCL_OK)
    {
	PDF_WrongParameter(interp, "lly in PDF_add_launchlink");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &urx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "urx in PDF_add_launchlink");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &ury) != TCL_OK)
    {
	PDF_WrongParameter(interp, "ury in PDF_add_launchlink");
	return TCL_ERROR;
    }
    if ((filename = PDF_GetStringFromObj(p, interp, objv[6], PDF_BYTES, &filename_len)) == NULL)
    {
	PDF_WrongParameter(interp, "filename in PDF_add_launchlink");
	return TCL_ERROR;
    }

    try {
	PDF_add_launchlink(p, llx, lly, urx, ury, filename);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_add_locallink(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double llx;
    double lly;
    double urx;
    double ury;
    int page;
    const char * optlist = NULL;
    int optlist_len;


    if (objc != 8)
    {
	PDF_WrongCommand(interp, "PDF_add_locallink p llx lly urx ury page optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_add_locallink");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_add_locallink");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &llx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "llx in PDF_add_locallink");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &lly) != TCL_OK)
    {
	PDF_WrongParameter(interp, "lly in PDF_add_locallink");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &urx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "urx in PDF_add_locallink");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &ury) != TCL_OK)
    {
	PDF_WrongParameter(interp, "ury in PDF_add_locallink");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[6], &page) != TCL_OK)
    {
	PDF_WrongParameter(interp, "page in PDF_add_locallink");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[7], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_add_locallink");
	return TCL_ERROR;
    }

    try {
	PDF_add_locallink(p, llx, lly, urx, ury, page, optlist);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_add_nameddest(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * name = NULL;
    int name_len;
    const char * optlist = NULL;
    int optlist_len;


    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_add_nameddest p name optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_add_nameddest");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_add_nameddest");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((name = PDF_GetStringFromObj(p, interp, objv[2], PDF_UTF16, &name_len)) == NULL)
    {
	PDF_WrongParameter(interp, "name in PDF_add_nameddest");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_add_nameddest");
	return TCL_ERROR;
    }

    try {
	PDF_add_nameddest(p, name, name_len, optlist);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_add_note(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * contents = NULL;
    int contents_len;
    const char * title = NULL;
    int title_len;
    const char * icon = NULL;
    int icon_len;
    int open;


    if (objc != 10)
    {
	PDF_WrongCommand(interp, "PDF_add_note p llx lly urx ury contents title icon open");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_add_note");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_add_note");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &llx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "llx in PDF_add_note");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &lly) != TCL_OK)
    {
	PDF_WrongParameter(interp, "lly in PDF_add_note");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &urx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "urx in PDF_add_note");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &ury) != TCL_OK)
    {
	PDF_WrongParameter(interp, "ury in PDF_add_note");
	return TCL_ERROR;
    }
    if ((contents = PDF_GetStringFromObj(p, interp, objv[6], PDF_UTF16, &contents_len)) == NULL)
    {
	PDF_WrongParameter(interp, "contents in PDF_add_note");
	return TCL_ERROR;
    }
    if ((title = PDF_GetStringFromObj(p, interp, objv[7], PDF_UTF16, &title_len)) == NULL)
    {
	PDF_WrongParameter(interp, "title in PDF_add_note");
	return TCL_ERROR;
    }
    if ((icon = PDF_GetStringFromObj(p, interp, objv[8], PDF_BYTES, &icon_len)) == NULL)
    {
	PDF_WrongParameter(interp, "icon in PDF_add_note");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[9], &open) != TCL_OK)
    {
	PDF_WrongParameter(interp, "open in PDF_add_note");
	return TCL_ERROR;
    }

    try {
	PDF_add_note2(p, llx, lly, urx, ury, contents, contents_len, title, title_len, icon, open);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_add_pdflink(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * filename = NULL;
    int filename_len;
    int page;
    const char * optlist = NULL;
    int optlist_len;


    if (objc != 9)
    {
	PDF_WrongCommand(interp, "PDF_add_pdflink p llx lly urx ury filename page optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_add_pdflink");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_add_pdflink");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &llx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "llx in PDF_add_pdflink");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &lly) != TCL_OK)
    {
	PDF_WrongParameter(interp, "lly in PDF_add_pdflink");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &urx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "urx in PDF_add_pdflink");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &ury) != TCL_OK)
    {
	PDF_WrongParameter(interp, "ury in PDF_add_pdflink");
	return TCL_ERROR;
    }
    if ((filename = PDF_GetStringFromObj(p, interp, objv[6], PDF_BYTES, &filename_len)) == NULL)
    {
	PDF_WrongParameter(interp, "filename in PDF_add_pdflink");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[7], &page) != TCL_OK)
    {
	PDF_WrongParameter(interp, "page in PDF_add_pdflink");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[8], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_add_pdflink");
	return TCL_ERROR;
    }

    try {
	PDF_add_pdflink(p, llx, lly, urx, ury, filename, page, optlist);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_add_table_cell(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int table;
    int column;
    int row;
    const char * text = NULL;
    int text_len;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 7)
    {
	PDF_WrongCommand(interp, "PDF_add_table_cell p table column row text optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_add_table_cell");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_add_table_cell");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &table) != TCL_OK)
    {
	PDF_WrongParameter(interp, "table in PDF_add_table_cell");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[3], &column) != TCL_OK)
    {
	PDF_WrongParameter(interp, "column in PDF_add_table_cell");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[4], &row) != TCL_OK)
    {
	PDF_WrongParameter(interp, "row in PDF_add_table_cell");
	return TCL_ERROR;
    }
    if ((text = PDF_GetStringFromObj(p, interp, objv[5], PDF_UTF16, &text_len)) == NULL)
    {
	PDF_WrongParameter(interp, "text in PDF_add_table_cell");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[6], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_add_table_cell");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_add_table_cell(p, table, column, row, text, text_len, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_add_textflow(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int textflow;
    const char * text = NULL;
    int text_len;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 5)
    {
	PDF_WrongCommand(interp, "PDF_add_textflow p textflow text optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_add_textflow");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_add_textflow");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &textflow) != TCL_OK)
    {
	PDF_WrongParameter(interp, "textflow in PDF_add_textflow");
	return TCL_ERROR;
    }
    if ((text = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF16, &text_len)) == NULL)
    {
	PDF_WrongParameter(interp, "text in PDF_add_textflow");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[4], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_add_textflow");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_add_textflow(p, textflow, text, text_len, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_add_thumbnail(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int image;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_add_thumbnail p image");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_add_thumbnail");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_add_thumbnail");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &image) != TCL_OK)
    {
	PDF_WrongParameter(interp, "image in PDF_add_thumbnail");
	return TCL_ERROR;
    }

    try {
	PDF_add_thumbnail(p, image);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_add_weblink(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * url = NULL;
    int url_len;


    if (objc != 7)
    {
	PDF_WrongCommand(interp, "PDF_add_weblink p llx lly urx ury url");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_add_weblink");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_add_weblink");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &llx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "llx in PDF_add_weblink");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &lly) != TCL_OK)
    {
	PDF_WrongParameter(interp, "lly in PDF_add_weblink");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &urx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "urx in PDF_add_weblink");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &ury) != TCL_OK)
    {
	PDF_WrongParameter(interp, "ury in PDF_add_weblink");
	return TCL_ERROR;
    }
    if ((url = PDF_GetStringFromObj(p, interp, objv[6], PDF_BYTES, &url_len)) == NULL)
    {
	PDF_WrongParameter(interp, "url in PDF_add_weblink");
	return TCL_ERROR;
    }

    try {
	PDF_add_weblink(p, llx, lly, urx, ury, url);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_arc(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double x;
    double y;
    double r;
    double alpha;
    double beta;


    if (objc != 7)
    {
	PDF_WrongCommand(interp, "PDF_arc p x y r alpha beta");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_arc");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_arc");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &x) != TCL_OK)
    {
	PDF_WrongParameter(interp, "x in PDF_arc");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &y) != TCL_OK)
    {
	PDF_WrongParameter(interp, "y in PDF_arc");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &r) != TCL_OK)
    {
	PDF_WrongParameter(interp, "r in PDF_arc");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &alpha) != TCL_OK)
    {
	PDF_WrongParameter(interp, "alpha in PDF_arc");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[6], &beta) != TCL_OK)
    {
	PDF_WrongParameter(interp, "beta in PDF_arc");
	return TCL_ERROR;
    }

    try {
	PDF_arc(p, x, y, r, alpha, beta);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_arcn(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double x;
    double y;
    double r;
    double alpha;
    double beta;


    if (objc != 7)
    {
	PDF_WrongCommand(interp, "PDF_arcn p x y r alpha beta");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_arcn");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_arcn");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &x) != TCL_OK)
    {
	PDF_WrongParameter(interp, "x in PDF_arcn");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &y) != TCL_OK)
    {
	PDF_WrongParameter(interp, "y in PDF_arcn");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &r) != TCL_OK)
    {
	PDF_WrongParameter(interp, "r in PDF_arcn");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &alpha) != TCL_OK)
    {
	PDF_WrongParameter(interp, "alpha in PDF_arcn");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[6], &beta) != TCL_OK)
    {
	PDF_WrongParameter(interp, "beta in PDF_arcn");
	return TCL_ERROR;
    }

    try {
	PDF_arcn(p, x, y, r, alpha, beta);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_attach_file(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * filename = NULL;
    int filename_len;
    const char * description = NULL;
    int description_len;
    const char * author = NULL;
    int author_len;
    const char * mimetype = NULL;
    int mimetype_len;
    const char * icon = NULL;
    int icon_len;


    if (objc != 11)
    {
	PDF_WrongCommand(interp, "PDF_attach_file p llx lly urx ury filename description author mimetype icon");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_attach_file");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_attach_file");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &llx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "llx in PDF_attach_file");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &lly) != TCL_OK)
    {
	PDF_WrongParameter(interp, "lly in PDF_attach_file");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &urx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "urx in PDF_attach_file");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &ury) != TCL_OK)
    {
	PDF_WrongParameter(interp, "ury in PDF_attach_file");
	return TCL_ERROR;
    }
    if ((filename = PDF_GetStringFromObj(p, interp, objv[6], PDF_0UTF16, &filename_len)) == NULL)
    {
	PDF_WrongParameter(interp, "filename in PDF_attach_file");
	return TCL_ERROR;
    }
    if ((description = PDF_GetStringFromObj(p, interp, objv[7], PDF_UTF16, &description_len)) == NULL)
    {
	PDF_WrongParameter(interp, "description in PDF_attach_file");
	return TCL_ERROR;
    }
    if ((author = PDF_GetStringFromObj(p, interp, objv[8], PDF_UTF16, &author_len)) == NULL)
    {
	PDF_WrongParameter(interp, "author in PDF_attach_file");
	return TCL_ERROR;
    }
    if ((mimetype = PDF_GetStringFromObj(p, interp, objv[9], PDF_BYTES, &mimetype_len)) == NULL)
    {
	PDF_WrongParameter(interp, "mimetype in PDF_attach_file");
	return TCL_ERROR;
    }
    if ((icon = PDF_GetStringFromObj(p, interp, objv[10], PDF_BYTES, &icon_len)) == NULL)
    {
	PDF_WrongParameter(interp, "icon in PDF_attach_file");
	return TCL_ERROR;
    }

    try {
	PDF_attach_file2(p, llx, lly, urx, ury, filename, filename_len, description, description_len, author, author_len, mimetype, icon);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_begin_document(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * filename = NULL;
    int filename_len;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_begin_document p filename optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_begin_document");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_begin_document");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((filename = PDF_GetStringFromObj(p, interp, objv[2], PDF_0UTF16, &filename_len)) == NULL)
    {
	PDF_WrongParameter(interp, "filename in PDF_begin_document");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_begin_document");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_begin_document(p, filename, filename_len, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_begin_font(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * fontname = NULL;
    int fontname_len;
    double a;
    double b;
    double c;
    double d;
    double e;
    double f;
    const char * optlist = NULL;
    int optlist_len;


    if (objc != 10)
    {
	PDF_WrongCommand(interp, "PDF_begin_font p fontname a b c d e f optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_begin_font");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_begin_font");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((fontname = PDF_GetStringFromObj(p, interp, objv[2], PDF_0UTF16, &fontname_len)) == NULL)
    {
	PDF_WrongParameter(interp, "fontname in PDF_begin_font");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &a) != TCL_OK)
    {
	PDF_WrongParameter(interp, "a in PDF_begin_font");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &b) != TCL_OK)
    {
	PDF_WrongParameter(interp, "b in PDF_begin_font");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &c) != TCL_OK)
    {
	PDF_WrongParameter(interp, "c in PDF_begin_font");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[6], &d) != TCL_OK)
    {
	PDF_WrongParameter(interp, "d in PDF_begin_font");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[7], &e) != TCL_OK)
    {
	PDF_WrongParameter(interp, "e in PDF_begin_font");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[8], &f) != TCL_OK)
    {
	PDF_WrongParameter(interp, "f in PDF_begin_font");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[9], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_begin_font");
	return TCL_ERROR;
    }

    try {
	PDF_begin_font(p, fontname, fontname_len, a, b, c, d, e, f, optlist);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_begin_glyph(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * glyphname = NULL;
    int glyphname_len;
    double wx;
    double llx;
    double lly;
    double urx;
    double ury;


    if (objc != 8)
    {
	PDF_WrongCommand(interp, "PDF_begin_glyph p glyphname wx llx lly urx ury");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_begin_glyph");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_begin_glyph");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((glyphname = PDF_GetStringFromObj(p, interp, objv[2], PDF_BYTES, &glyphname_len)) == NULL)
    {
	PDF_WrongParameter(interp, "glyphname in PDF_begin_glyph");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &wx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "wx in PDF_begin_glyph");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &llx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "llx in PDF_begin_glyph");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &lly) != TCL_OK)
    {
	PDF_WrongParameter(interp, "lly in PDF_begin_glyph");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[6], &urx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "urx in PDF_begin_glyph");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[7], &ury) != TCL_OK)
    {
	PDF_WrongParameter(interp, "ury in PDF_begin_glyph");
	return TCL_ERROR;
    }

    try {
	PDF_begin_glyph(p, glyphname, wx, llx, lly, urx, ury);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_begin_item(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * tag = NULL;
    int tag_len;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_begin_item p tag optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_begin_item");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_begin_item");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((tag = PDF_GetStringFromObj(p, interp, objv[2], PDF_BYTES, &tag_len)) == NULL)
    {
	PDF_WrongParameter(interp, "tag in PDF_begin_item");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_begin_item");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_begin_item(p, tag, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_begin_layer(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int layer;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_begin_layer p layer");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_begin_layer");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_begin_layer");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &layer) != TCL_OK)
    {
	PDF_WrongParameter(interp, "layer in PDF_begin_layer");
	return TCL_ERROR;
    }

    try {
	PDF_begin_layer(p, layer);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_begin_page(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double width;
    double height;


    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_begin_page p width height");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_begin_page");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_begin_page");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &width) != TCL_OK)
    {
	PDF_WrongParameter(interp, "width in PDF_begin_page");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &height) != TCL_OK)
    {
	PDF_WrongParameter(interp, "height in PDF_begin_page");
	return TCL_ERROR;
    }

    try {
	PDF_begin_page(p, width, height);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_begin_page_ext(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double width;
    double height;
    const char * optlist = NULL;
    int optlist_len;


    if (objc != 5)
    {
	PDF_WrongCommand(interp, "PDF_begin_page_ext p width height optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_begin_page_ext");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_begin_page_ext");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &width) != TCL_OK)
    {
	PDF_WrongParameter(interp, "width in PDF_begin_page_ext");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &height) != TCL_OK)
    {
	PDF_WrongParameter(interp, "height in PDF_begin_page_ext");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[4], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_begin_page_ext");
	return TCL_ERROR;
    }

    try {
	PDF_begin_page_ext(p, width, height, optlist);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_begin_pattern(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double width;
    double height;
    double xstep;
    double ystep;
    int painttype;
    int volatile _retval = -1;

    if (objc != 7)
    {
	PDF_WrongCommand(interp, "PDF_begin_pattern p width height xstep ystep painttype");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_begin_pattern");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_begin_pattern");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &width) != TCL_OK)
    {
	PDF_WrongParameter(interp, "width in PDF_begin_pattern");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &height) != TCL_OK)
    {
	PDF_WrongParameter(interp, "height in PDF_begin_pattern");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &xstep) != TCL_OK)
    {
	PDF_WrongParameter(interp, "xstep in PDF_begin_pattern");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &ystep) != TCL_OK)
    {
	PDF_WrongParameter(interp, "ystep in PDF_begin_pattern");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[6], &painttype) != TCL_OK)
    {
	PDF_WrongParameter(interp, "painttype in PDF_begin_pattern");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_begin_pattern(p, width, height, xstep, ystep, painttype);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_begin_template(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double width;
    double height;
    int volatile _retval = -1;

    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_begin_template p width height");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_begin_template");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_begin_template");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &width) != TCL_OK)
    {
	PDF_WrongParameter(interp, "width in PDF_begin_template");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &height) != TCL_OK)
    {
	PDF_WrongParameter(interp, "height in PDF_begin_template");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_begin_template(p, width, height);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_begin_template_ext(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double width;
    double height;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 5)
    {
	PDF_WrongCommand(interp, "PDF_begin_template_ext p width height optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_begin_template_ext");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_begin_template_ext");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &width) != TCL_OK)
    {
	PDF_WrongParameter(interp, "width in PDF_begin_template_ext");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &height) != TCL_OK)
    {
	PDF_WrongParameter(interp, "height in PDF_begin_template_ext");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[4], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_begin_template_ext");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_begin_template_ext(p, width, height, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_circle(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double x;
    double y;
    double r;


    if (objc != 5)
    {
	PDF_WrongCommand(interp, "PDF_circle p x y r");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_circle");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_circle");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &x) != TCL_OK)
    {
	PDF_WrongParameter(interp, "x in PDF_circle");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &y) != TCL_OK)
    {
	PDF_WrongParameter(interp, "y in PDF_circle");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &r) != TCL_OK)
    {
	PDF_WrongParameter(interp, "r in PDF_circle");
	return TCL_ERROR;
    }

    try {
	PDF_circle(p, x, y, r);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_clip(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;


    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_clip p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_clip");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_clip");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	PDF_clip(p);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_close(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;


    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_close p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_close");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_close");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	PDF_close(p);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_close_image(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int image;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_close_image p image");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_close_image");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_close_image");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &image) != TCL_OK)
    {
	PDF_WrongParameter(interp, "image in PDF_close_image");
	return TCL_ERROR;
    }

    try {
	PDF_close_image(p, image);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_close_pdi(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int doc;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_close_pdi p doc");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_close_pdi");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_close_pdi");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &doc) != TCL_OK)
    {
	PDF_WrongParameter(interp, "doc in PDF_close_pdi");
	return TCL_ERROR;
    }

    try {
	PDF_close_pdi(p, doc);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_close_pdi_document(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int doc;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_close_pdi_document p doc");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_close_pdi_document");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_close_pdi_document");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &doc) != TCL_OK)
    {
	PDF_WrongParameter(interp, "doc in PDF_close_pdi_document");
	return TCL_ERROR;
    }

    try {
	PDF_close_pdi_document(p, doc);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_close_pdi_page(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int page;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_close_pdi_page p page");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_close_pdi_page");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_close_pdi_page");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &page) != TCL_OK)
    {
	PDF_WrongParameter(interp, "page in PDF_close_pdi_page");
	return TCL_ERROR;
    }

    try {
	PDF_close_pdi_page(p, page);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_closepath(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;


    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_closepath p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_closepath");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_closepath");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	PDF_closepath(p);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_closepath_fill_stroke(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;


    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_closepath_fill_stroke p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_closepath_fill_stroke");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_closepath_fill_stroke");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	PDF_closepath_fill_stroke(p);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_closepath_stroke(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;


    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_closepath_stroke p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_closepath_stroke");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_closepath_stroke");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	PDF_closepath_stroke(p);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_concat(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double a;
    double b;
    double c;
    double d;
    double e;
    double f;


    if (objc != 8)
    {
	PDF_WrongCommand(interp, "PDF_concat p a b c d e f");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_concat");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_concat");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &a) != TCL_OK)
    {
	PDF_WrongParameter(interp, "a in PDF_concat");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &b) != TCL_OK)
    {
	PDF_WrongParameter(interp, "b in PDF_concat");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &c) != TCL_OK)
    {
	PDF_WrongParameter(interp, "c in PDF_concat");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &d) != TCL_OK)
    {
	PDF_WrongParameter(interp, "d in PDF_concat");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[6], &e) != TCL_OK)
    {
	PDF_WrongParameter(interp, "e in PDF_concat");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[7], &f) != TCL_OK)
    {
	PDF_WrongParameter(interp, "f in PDF_concat");
	return TCL_ERROR;
    }

    try {
	PDF_concat(p, a, b, c, d, e, f);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_continue_text(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * text = NULL;
    int text_len;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_continue_text p text");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_continue_text");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_continue_text");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((text = PDF_GetStringFromObj(p, interp, objv[2], PDF_UTF16, &text_len)) == NULL)
    {
	PDF_WrongParameter(interp, "text in PDF_continue_text");
	return TCL_ERROR;
    }

    try {
	PDF_continue_text2(p, text, text_len);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_create_action(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * type = NULL;
    int type_len;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_create_action p type optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_create_action");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_create_action");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((type = PDF_GetStringFromObj(p, interp, objv[2], PDF_BYTES, &type_len)) == NULL)
    {
	PDF_WrongParameter(interp, "type in PDF_create_action");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_create_action");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_create_action(p, type, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_create_annotation(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * type = NULL;
    int type_len;
    const char * optlist = NULL;
    int optlist_len;


    if (objc != 8)
    {
	PDF_WrongCommand(interp, "PDF_create_annotation p llx lly urx ury type optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_create_annotation");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_create_annotation");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &llx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "llx in PDF_create_annotation");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &lly) != TCL_OK)
    {
	PDF_WrongParameter(interp, "lly in PDF_create_annotation");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &urx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "urx in PDF_create_annotation");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &ury) != TCL_OK)
    {
	PDF_WrongParameter(interp, "ury in PDF_create_annotation");
	return TCL_ERROR;
    }
    if ((type = PDF_GetStringFromObj(p, interp, objv[6], PDF_BYTES, &type_len)) == NULL)
    {
	PDF_WrongParameter(interp, "type in PDF_create_annotation");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[7], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_create_annotation");
	return TCL_ERROR;
    }

    try {
	PDF_create_annotation(p, llx, lly, urx, ury, type, optlist);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_create_bookmark(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * text = NULL;
    int text_len;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_create_bookmark p text optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_create_bookmark");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_create_bookmark");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((text = PDF_GetStringFromObj(p, interp, objv[2], PDF_UTF16, &text_len)) == NULL)
    {
	PDF_WrongParameter(interp, "text in PDF_create_bookmark");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_create_bookmark");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_create_bookmark(p, text, text_len, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_create_field(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * name = NULL;
    int name_len;
    const char * type = NULL;
    int type_len;
    const char * optlist = NULL;
    int optlist_len;


    if (objc != 9)
    {
	PDF_WrongCommand(interp, "PDF_create_field p llx lly urx ury name type optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_create_field");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_create_field");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &llx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "llx in PDF_create_field");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &lly) != TCL_OK)
    {
	PDF_WrongParameter(interp, "lly in PDF_create_field");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &urx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "urx in PDF_create_field");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &ury) != TCL_OK)
    {
	PDF_WrongParameter(interp, "ury in PDF_create_field");
	return TCL_ERROR;
    }
    if ((name = PDF_GetStringFromObj(p, interp, objv[6], PDF_UTF16, &name_len)) == NULL)
    {
	PDF_WrongParameter(interp, "name in PDF_create_field");
	return TCL_ERROR;
    }
    if ((type = PDF_GetStringFromObj(p, interp, objv[7], PDF_BYTES, &type_len)) == NULL)
    {
	PDF_WrongParameter(interp, "type in PDF_create_field");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[8], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_create_field");
	return TCL_ERROR;
    }

    try {
	PDF_create_field(p, llx, lly, urx, ury, name, name_len, type, optlist);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_create_fieldgroup(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * name = NULL;
    int name_len;
    const char * optlist = NULL;
    int optlist_len;


    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_create_fieldgroup p name optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_create_fieldgroup");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_create_fieldgroup");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((name = PDF_GetStringFromObj(p, interp, objv[2], PDF_UTF16, &name_len)) == NULL)
    {
	PDF_WrongParameter(interp, "name in PDF_create_fieldgroup");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_create_fieldgroup");
	return TCL_ERROR;
    }

    try {
	PDF_create_fieldgroup(p, name, name_len, optlist);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_create_gstate(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_create_gstate p optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_create_gstate");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_create_gstate");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[2], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_create_gstate");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_create_gstate(p, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_create_pvf(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * filename = NULL;
    int filename_len;
    const void * data = NULL;
    int data_len;
    const char * optlist = NULL;
    int optlist_len;


    if (objc != 5)
    {
	PDF_WrongCommand(interp, "PDF_create_pvf p filename data optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_create_pvf");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_create_pvf");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((filename = PDF_GetStringFromObj(p, interp, objv[2], PDF_0UTF16, &filename_len)) == NULL)
    {
	PDF_WrongParameter(interp, "filename in PDF_create_pvf");
	return TCL_ERROR;
    }
    if ((data = PDF_GetStringFromObj(p, interp, objv[3], PDF_DATA, &data_len)) == NULL)
    {
	PDF_WrongParameter(interp, "data in PDF_create_pvf");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[4], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_create_pvf");
	return TCL_ERROR;
    }

    try {
	PDF_create_pvf(p, filename, filename_len, data, data_len, optlist);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_create_textflow(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * text = NULL;
    int text_len;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_create_textflow p text optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_create_textflow");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_create_textflow");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((text = PDF_GetStringFromObj(p, interp, objv[2], PDF_UTF16, &text_len)) == NULL)
    {
	PDF_WrongParameter(interp, "text in PDF_create_textflow");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_create_textflow");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_create_textflow(p, text, text_len, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_curveto(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double x_1;
    double y_1;
    double x_2;
    double y_2;
    double x_3;
    double y_3;


    if (objc != 8)
    {
	PDF_WrongCommand(interp, "PDF_curveto p x_1 y_1 x_2 y_2 x_3 y_3");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_curveto");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_curveto");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &x_1) != TCL_OK)
    {
	PDF_WrongParameter(interp, "x_1 in PDF_curveto");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &y_1) != TCL_OK)
    {
	PDF_WrongParameter(interp, "y_1 in PDF_curveto");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &x_2) != TCL_OK)
    {
	PDF_WrongParameter(interp, "x_2 in PDF_curveto");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &y_2) != TCL_OK)
    {
	PDF_WrongParameter(interp, "y_2 in PDF_curveto");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[6], &x_3) != TCL_OK)
    {
	PDF_WrongParameter(interp, "x_3 in PDF_curveto");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[7], &y_3) != TCL_OK)
    {
	PDF_WrongParameter(interp, "y_3 in PDF_curveto");
	return TCL_ERROR;
    }

    try {
	PDF_curveto(p, x_1, y_1, x_2, y_2, x_3, y_3);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_define_layer(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * name = NULL;
    int name_len;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_define_layer p name optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_define_layer");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_define_layer");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((name = PDF_GetStringFromObj(p, interp, objv[2], PDF_UTF16, &name_len)) == NULL)
    {
	PDF_WrongParameter(interp, "name in PDF_define_layer");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_define_layer");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_define_layer(p, name, name_len, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_delete_pvf(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * filename = NULL;
    int filename_len;
    int volatile _retval = -1;

    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_delete_pvf p filename");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_delete_pvf");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_delete_pvf");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((filename = PDF_GetStringFromObj(p, interp, objv[2], PDF_0UTF16, &filename_len)) == NULL)
    {
	PDF_WrongParameter(interp, "filename in PDF_delete_pvf");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_delete_pvf(p, filename, filename_len);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_delete_table(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int table;
    const char * optlist = NULL;
    int optlist_len;


    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_delete_table p table optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_delete_table");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_delete_table");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &table) != TCL_OK)
    {
	PDF_WrongParameter(interp, "table in PDF_delete_table");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_delete_table");
	return TCL_ERROR;
    }

    try {
	PDF_delete_table(p, table, optlist);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_delete_textflow(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int textflow;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_delete_textflow p textflow");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_delete_textflow");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_delete_textflow");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &textflow) != TCL_OK)
    {
	PDF_WrongParameter(interp, "textflow in PDF_delete_textflow");
	return TCL_ERROR;
    }

    try {
	PDF_delete_textflow(p, textflow);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_encoding_set_char(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * encoding = NULL;
    int encoding_len;
    int slot;
    const char * glyphname = NULL;
    int glyphname_len;
    int uv;


    if (objc != 6)
    {
	PDF_WrongCommand(interp, "PDF_encoding_set_char p encoding slot glyphname uv");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_encoding_set_char");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_encoding_set_char");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((encoding = PDF_GetStringFromObj(p, interp, objv[2], PDF_BYTES, &encoding_len)) == NULL)
    {
	PDF_WrongParameter(interp, "encoding in PDF_encoding_set_char");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[3], &slot) != TCL_OK)
    {
	PDF_WrongParameter(interp, "slot in PDF_encoding_set_char");
	return TCL_ERROR;
    }
    if ((glyphname = PDF_GetStringFromObj(p, interp, objv[4], PDF_BYTES, &glyphname_len)) == NULL)
    {
	PDF_WrongParameter(interp, "glyphname in PDF_encoding_set_char");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[5], &uv) != TCL_OK)
    {
	PDF_WrongParameter(interp, "uv in PDF_encoding_set_char");
	return TCL_ERROR;
    }

    try {
	PDF_encoding_set_char(p, encoding, slot, glyphname, uv);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_end_document(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * optlist = NULL;
    int optlist_len;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_end_document p optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_end_document");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_end_document");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[2], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_end_document");
	return TCL_ERROR;
    }

    try {
	PDF_end_document(p, optlist);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_end_font(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;


    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_end_font p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_end_font");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_end_font");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	PDF_end_font(p);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_end_glyph(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;


    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_end_glyph p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_end_glyph");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_end_glyph");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	PDF_end_glyph(p);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_end_item(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int id;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_end_item p id");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_end_item");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_end_item");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &id) != TCL_OK)
    {
	PDF_WrongParameter(interp, "id in PDF_end_item");
	return TCL_ERROR;
    }

    try {
	PDF_end_item(p, id);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_end_layer(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;


    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_end_layer p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_end_layer");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_end_layer");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	PDF_end_layer(p);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_end_mc(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;


    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_end_mc p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_end_mc");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_end_mc");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	PDF_end_mc(p);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_end_page(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;


    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_end_page p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_end_page");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_end_page");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	PDF_end_page(p);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_end_page_ext(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * optlist = NULL;
    int optlist_len;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_end_page_ext p optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_end_page_ext");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_end_page_ext");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[2], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_end_page_ext");
	return TCL_ERROR;
    }

    try {
	PDF_end_page_ext(p, optlist);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_end_pattern(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;


    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_end_pattern p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_end_pattern");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_end_pattern");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	PDF_end_pattern(p);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_end_template(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;


    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_end_template p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_end_template");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_end_template");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	PDF_end_template(p);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_endpath(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;


    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_endpath p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_endpath");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_endpath");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	PDF_endpath(p);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_fill(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;


    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_fill p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_fill");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_fill");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	PDF_fill(p);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_fill_imageblock(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int page;
    const char * blockname = NULL;
    int blockname_len;
    int image;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 6)
    {
	PDF_WrongCommand(interp, "PDF_fill_imageblock p page blockname image optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_fill_imageblock");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_fill_imageblock");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &page) != TCL_OK)
    {
	PDF_WrongParameter(interp, "page in PDF_fill_imageblock");
	return TCL_ERROR;
    }
    if ((blockname = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8, &blockname_len)) == NULL)
    {
	PDF_WrongParameter(interp, "blockname in PDF_fill_imageblock");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[4], &image) != TCL_OK)
    {
	PDF_WrongParameter(interp, "image in PDF_fill_imageblock");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[5], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_fill_imageblock");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_fill_imageblock(p, page, blockname, image, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_fill_pdfblock(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int page;
    const char * blockname = NULL;
    int blockname_len;
    int contents;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 6)
    {
	PDF_WrongCommand(interp, "PDF_fill_pdfblock p page blockname contents optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_fill_pdfblock");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_fill_pdfblock");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &page) != TCL_OK)
    {
	PDF_WrongParameter(interp, "page in PDF_fill_pdfblock");
	return TCL_ERROR;
    }
    if ((blockname = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8, &blockname_len)) == NULL)
    {
	PDF_WrongParameter(interp, "blockname in PDF_fill_pdfblock");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[4], &contents) != TCL_OK)
    {
	PDF_WrongParameter(interp, "contents in PDF_fill_pdfblock");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[5], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_fill_pdfblock");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_fill_pdfblock(p, page, blockname, contents, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_fill_stroke(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;


    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_fill_stroke p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_fill_stroke");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_fill_stroke");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	PDF_fill_stroke(p);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_fill_textblock(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int page;
    const char * blockname = NULL;
    int blockname_len;
    const char * text = NULL;
    int text_len;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 6)
    {
	PDF_WrongCommand(interp, "PDF_fill_textblock p page blockname text optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_fill_textblock");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_fill_textblock");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &page) != TCL_OK)
    {
	PDF_WrongParameter(interp, "page in PDF_fill_textblock");
	return TCL_ERROR;
    }
    if ((blockname = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8, &blockname_len)) == NULL)
    {
	PDF_WrongParameter(interp, "blockname in PDF_fill_textblock");
	return TCL_ERROR;
    }
    if ((text = PDF_GetStringFromObj(p, interp, objv[4], PDF_UTF16, &text_len)) == NULL)
    {
	PDF_WrongParameter(interp, "text in PDF_fill_textblock");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[5], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_fill_textblock");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_fill_textblock(p, page, blockname, text, text_len, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_findfont(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * fontname = NULL;
    int fontname_len;
    const char * encoding = NULL;
    int encoding_len;
    int embed;
    int volatile _retval = -1;

    if (objc != 5)
    {
	PDF_WrongCommand(interp, "PDF_findfont p fontname encoding embed");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_findfont");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_findfont");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((fontname = PDF_GetStringFromObj(p, interp, objv[2], PDF_BYTES, &fontname_len)) == NULL)
    {
	PDF_WrongParameter(interp, "fontname in PDF_findfont");
	return TCL_ERROR;
    }
    if ((encoding = PDF_GetStringFromObj(p, interp, objv[3], PDF_BYTES, &encoding_len)) == NULL)
    {
	PDF_WrongParameter(interp, "encoding in PDF_findfont");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[4], &embed) != TCL_OK)
    {
	PDF_WrongParameter(interp, "embed in PDF_findfont");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_findfont(p, fontname, encoding, embed);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_fit_image(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int image;
    double x;
    double y;
    const char * optlist = NULL;
    int optlist_len;


    if (objc != 6)
    {
	PDF_WrongCommand(interp, "PDF_fit_image p image x y optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_fit_image");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_fit_image");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &image) != TCL_OK)
    {
	PDF_WrongParameter(interp, "image in PDF_fit_image");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &x) != TCL_OK)
    {
	PDF_WrongParameter(interp, "x in PDF_fit_image");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &y) != TCL_OK)
    {
	PDF_WrongParameter(interp, "y in PDF_fit_image");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[5], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_fit_image");
	return TCL_ERROR;
    }

    try {
	PDF_fit_image(p, image, x, y, optlist);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_fit_pdi_page(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int page;
    double x;
    double y;
    const char * optlist = NULL;
    int optlist_len;


    if (objc != 6)
    {
	PDF_WrongCommand(interp, "PDF_fit_pdi_page p page x y optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_fit_pdi_page");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_fit_pdi_page");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &page) != TCL_OK)
    {
	PDF_WrongParameter(interp, "page in PDF_fit_pdi_page");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &x) != TCL_OK)
    {
	PDF_WrongParameter(interp, "x in PDF_fit_pdi_page");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &y) != TCL_OK)
    {
	PDF_WrongParameter(interp, "y in PDF_fit_pdi_page");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[5], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_fit_pdi_page");
	return TCL_ERROR;
    }

    try {
	PDF_fit_pdi_page(p, page, x, y, optlist);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_fit_table(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int table;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * optlist = NULL;
    int optlist_len;
    const char volatile *_retval = NULL;

    if (objc != 8)
    {
	PDF_WrongCommand(interp, "PDF_fit_table p table llx lly urx ury optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_fit_table");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_fit_table");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &table) != TCL_OK)
    {
	PDF_WrongParameter(interp, "table in PDF_fit_table");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &llx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "llx in PDF_fit_table");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &lly) != TCL_OK)
    {
	PDF_WrongParameter(interp, "lly in PDF_fit_table");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &urx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "urx in PDF_fit_table");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[6], &ury) != TCL_OK)
    {
	PDF_WrongParameter(interp, "ury in PDF_fit_table");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[7], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_fit_table");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_fit_table(p, table, llx, lly, urx, ury, optlist);
    } catch;

    Tcl_SetResult(interp, (char *) _retval, TCL_VOLATILE);

    return TCL_OK;
}

    
static int
_wrap_PDF_fit_textflow(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int textflow;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * optlist = NULL;
    int optlist_len;
    const char volatile *_retval = NULL;

    if (objc != 8)
    {
	PDF_WrongCommand(interp, "PDF_fit_textflow p textflow llx lly urx ury optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_fit_textflow");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_fit_textflow");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &textflow) != TCL_OK)
    {
	PDF_WrongParameter(interp, "textflow in PDF_fit_textflow");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &llx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "llx in PDF_fit_textflow");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &lly) != TCL_OK)
    {
	PDF_WrongParameter(interp, "lly in PDF_fit_textflow");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &urx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "urx in PDF_fit_textflow");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[6], &ury) != TCL_OK)
    {
	PDF_WrongParameter(interp, "ury in PDF_fit_textflow");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[7], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_fit_textflow");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_fit_textflow(p, textflow, llx, lly, urx, ury, optlist);
    } catch;

    Tcl_SetResult(interp, (char *) _retval, TCL_VOLATILE);

    return TCL_OK;
}

    
static int
_wrap_PDF_fit_textline(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * text = NULL;
    int text_len;
    double x;
    double y;
    const char * optlist = NULL;
    int optlist_len;


    if (objc != 6)
    {
	PDF_WrongCommand(interp, "PDF_fit_textline p text x y optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_fit_textline");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_fit_textline");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((text = PDF_GetStringFromObj(p, interp, objv[2], PDF_UTF16, &text_len)) == NULL)
    {
	PDF_WrongParameter(interp, "text in PDF_fit_textline");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &x) != TCL_OK)
    {
	PDF_WrongParameter(interp, "x in PDF_fit_textline");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &y) != TCL_OK)
    {
	PDF_WrongParameter(interp, "y in PDF_fit_textline");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[5], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_fit_textline");
	return TCL_ERROR;
    }

    try {
	PDF_fit_textline(p, text, text_len, x, y, optlist);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_get_apiname(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char volatile *_retval = NULL;

    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_get_apiname p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_get_apiname");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_get_apiname");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	_retval = PDF_get_apiname(p);
    } catch;

    Tcl_SetResult(interp, (char *) _retval, TCL_VOLATILE);

    return TCL_OK;
}

    
static int
_wrap_PDF_get_buffer(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    long size;
    const char volatile *_retval = NULL;    Tcl_Obj *objPtr;

    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_get_buffer p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_get_buffer");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_get_buffer");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	_retval = PDF_get_buffer(p, &size);
    } catch;

    objPtr = Tcl_GetObjResult(interp);
    Tcl_SetByteArrayObj(objPtr, (unsigned char *)_retval, size);

    return TCL_OK;
}

    
static int
_wrap_PDF_get_errmsg(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char volatile *_retval = NULL;

    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_get_errmsg p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_get_errmsg");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_get_errmsg");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	_retval = PDF_get_errmsg(p);
    } catch;

    Tcl_SetResult(interp, (char *) _retval, TCL_VOLATILE);

    return TCL_OK;
}

    
static int
_wrap_PDF_get_errnum(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int volatile _retval = -1;

    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_get_errnum p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_get_errnum");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_get_errnum");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	_retval = PDF_get_errnum(p);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_get_parameter(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * key = NULL;
    int key_len;
    double modifier;
    const char volatile *_retval = NULL;

    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_get_parameter p key modifier");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_get_parameter");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_get_parameter");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((key = PDF_GetStringFromObj(p, interp, objv[2], PDF_BYTES, &key_len)) == NULL)
    {
	PDF_WrongParameter(interp, "key in PDF_get_parameter");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &modifier) != TCL_OK)
    {
	PDF_WrongParameter(interp, "modifier in PDF_get_parameter");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_get_parameter(p, key, modifier);
    } catch;

    Tcl_SetResult(interp, (char *) _retval, TCL_VOLATILE);

    return TCL_OK;
}

    
static int
_wrap_PDF_get_pdi_parameter(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * key = NULL;
    int key_len;
    int doc;
    int page;
    int reserved;
    int len;
    const char volatile *_retval = NULL;    Tcl_Obj *objPtr;

    if (objc != 6)
    {
	PDF_WrongCommand(interp, "PDF_get_pdi_parameter p key doc page reserved");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_get_pdi_parameter");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_get_pdi_parameter");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((key = PDF_GetStringFromObj(p, interp, objv[2], PDF_BYTES, &key_len)) == NULL)
    {
	PDF_WrongParameter(interp, "key in PDF_get_pdi_parameter");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[3], &doc) != TCL_OK)
    {
	PDF_WrongParameter(interp, "doc in PDF_get_pdi_parameter");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[4], &page) != TCL_OK)
    {
	PDF_WrongParameter(interp, "page in PDF_get_pdi_parameter");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[5], &reserved) != TCL_OK)
    {
	PDF_WrongParameter(interp, "reserved in PDF_get_pdi_parameter");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_get_pdi_parameter(p, key, doc, page, reserved, &len);
    } catch;

    objPtr = Tcl_GetObjResult(interp);
    Tcl_SetByteArrayObj(objPtr, (unsigned char *)_retval, len);

    return TCL_OK;
}

    
static int
_wrap_PDF_get_pdi_value(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * key = NULL;
    int key_len;
    int doc;
    int page;
    int reserved;
    double volatile _retval = -1;

    if (objc != 6)
    {
	PDF_WrongCommand(interp, "PDF_get_pdi_value p key doc page reserved");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_get_pdi_value");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_get_pdi_value");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((key = PDF_GetStringFromObj(p, interp, objv[2], PDF_BYTES, &key_len)) == NULL)
    {
	PDF_WrongParameter(interp, "key in PDF_get_pdi_value");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[3], &doc) != TCL_OK)
    {
	PDF_WrongParameter(interp, "doc in PDF_get_pdi_value");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[4], &page) != TCL_OK)
    {
	PDF_WrongParameter(interp, "page in PDF_get_pdi_value");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[5], &reserved) != TCL_OK)
    {
	PDF_WrongParameter(interp, "reserved in PDF_get_pdi_value");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_get_pdi_value(p, key, doc, page, reserved);
    } catch;

    Tcl_PrintDouble(interp, (double)_retval, interp->result);

    return TCL_OK;
}

    
static int
_wrap_PDF_get_value(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * key = NULL;
    int key_len;
    double modifier;
    double volatile _retval = -1;

    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_get_value p key modifier");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_get_value");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_get_value");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((key = PDF_GetStringFromObj(p, interp, objv[2], PDF_BYTES, &key_len)) == NULL)
    {
	PDF_WrongParameter(interp, "key in PDF_get_value");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &modifier) != TCL_OK)
    {
	PDF_WrongParameter(interp, "modifier in PDF_get_value");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_get_value(p, key, modifier);
    } catch;

    Tcl_PrintDouble(interp, (double)_retval, interp->result);

    return TCL_OK;
}

    
static int
_wrap_PDF_info_font(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int font;
    const char * keyword = NULL;
    int keyword_len;
    const char * optlist = NULL;
    int optlist_len;
    double volatile _retval = -1;

    if (objc != 5)
    {
	PDF_WrongCommand(interp, "PDF_info_font p font keyword optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_info_font");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_info_font");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &font) != TCL_OK)
    {
	PDF_WrongParameter(interp, "font in PDF_info_font");
	return TCL_ERROR;
    }
    if ((keyword = PDF_GetStringFromObj(p, interp, objv[3], PDF_BYTES, &keyword_len)) == NULL)
    {
	PDF_WrongParameter(interp, "keyword in PDF_info_font");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[4], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_info_font");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_info_font(p, font, keyword, optlist);
    } catch;

    Tcl_PrintDouble(interp, (double)_retval, interp->result);

    return TCL_OK;
}

    
static int
_wrap_PDF_info_matchbox(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * boxname = NULL;
    int boxname_len;
    int num;
    const char * keyword = NULL;
    int keyword_len;
    double volatile _retval = -1;

    if (objc != 5)
    {
	PDF_WrongCommand(interp, "PDF_info_matchbox p boxname num keyword");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_info_matchbox");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_info_matchbox");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((boxname = PDF_GetStringFromObj(p, interp, objv[2], PDF_0UTF16, &boxname_len)) == NULL)
    {
	PDF_WrongParameter(interp, "boxname in PDF_info_matchbox");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[3], &num) != TCL_OK)
    {
	PDF_WrongParameter(interp, "num in PDF_info_matchbox");
	return TCL_ERROR;
    }
    if ((keyword = PDF_GetStringFromObj(p, interp, objv[4], PDF_BYTES, &keyword_len)) == NULL)
    {
	PDF_WrongParameter(interp, "keyword in PDF_info_matchbox");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_info_matchbox(p, boxname, boxname_len, num, keyword);
    } catch;

    Tcl_PrintDouble(interp, (double)_retval, interp->result);

    return TCL_OK;
}

    
static int
_wrap_PDF_info_table(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int table;
    const char * keyword = NULL;
    int keyword_len;
    double volatile _retval = -1;

    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_info_table p table keyword");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_info_table");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_info_table");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &table) != TCL_OK)
    {
	PDF_WrongParameter(interp, "table in PDF_info_table");
	return TCL_ERROR;
    }
    if ((keyword = PDF_GetStringFromObj(p, interp, objv[3], PDF_BYTES, &keyword_len)) == NULL)
    {
	PDF_WrongParameter(interp, "keyword in PDF_info_table");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_info_table(p, table, keyword);
    } catch;

    Tcl_PrintDouble(interp, (double)_retval, interp->result);

    return TCL_OK;
}

    
static int
_wrap_PDF_info_textflow(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int textflow;
    const char * keyword = NULL;
    int keyword_len;
    double volatile _retval = -1;

    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_info_textflow p textflow keyword");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_info_textflow");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_info_textflow");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &textflow) != TCL_OK)
    {
	PDF_WrongParameter(interp, "textflow in PDF_info_textflow");
	return TCL_ERROR;
    }
    if ((keyword = PDF_GetStringFromObj(p, interp, objv[3], PDF_BYTES, &keyword_len)) == NULL)
    {
	PDF_WrongParameter(interp, "keyword in PDF_info_textflow");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_info_textflow(p, textflow, keyword);
    } catch;

    Tcl_PrintDouble(interp, (double)_retval, interp->result);

    return TCL_OK;
}

    
static int
_wrap_PDF_info_textline(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * text = NULL;
    int text_len;
    const char * keyword = NULL;
    int keyword_len;
    const char * optlist = NULL;
    int optlist_len;
    double volatile _retval = -1;

    if (objc != 5)
    {
	PDF_WrongCommand(interp, "PDF_info_textline p text keyword optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_info_textline");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_info_textline");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((text = PDF_GetStringFromObj(p, interp, objv[2], PDF_UTF16, &text_len)) == NULL)
    {
	PDF_WrongParameter(interp, "text in PDF_info_textline");
	return TCL_ERROR;
    }
    if ((keyword = PDF_GetStringFromObj(p, interp, objv[3], PDF_BYTES, &keyword_len)) == NULL)
    {
	PDF_WrongParameter(interp, "keyword in PDF_info_textline");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[4], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_info_textline");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_info_textline(p, text, text_len, keyword, optlist);
    } catch;

    Tcl_PrintDouble(interp, (double)_retval, interp->result);

    return TCL_OK;
}

    
static int
_wrap_PDF_initgraphics(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;


    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_initgraphics p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_initgraphics");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_initgraphics");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	PDF_initgraphics(p);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_lineto(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double x;
    double y;


    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_lineto p x y");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_lineto");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_lineto");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &x) != TCL_OK)
    {
	PDF_WrongParameter(interp, "x in PDF_lineto");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &y) != TCL_OK)
    {
	PDF_WrongParameter(interp, "y in PDF_lineto");
	return TCL_ERROR;
    }

    try {
	PDF_lineto(p, x, y);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_load_font(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * fontname = NULL;
    int fontname_len;
    const char * encoding = NULL;
    int encoding_len;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 5)
    {
	PDF_WrongCommand(interp, "PDF_load_font p fontname encoding optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_load_font");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_load_font");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((fontname = PDF_GetStringFromObj(p, interp, objv[2], PDF_0UTF16, &fontname_len)) == NULL)
    {
	PDF_WrongParameter(interp, "fontname in PDF_load_font");
	return TCL_ERROR;
    }
    if ((encoding = PDF_GetStringFromObj(p, interp, objv[3], PDF_BYTES, &encoding_len)) == NULL)
    {
	PDF_WrongParameter(interp, "encoding in PDF_load_font");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[4], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_load_font");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_load_font(p, fontname, fontname_len, encoding, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_load_iccprofile(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * profilename = NULL;
    int profilename_len;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_load_iccprofile p profilename optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_load_iccprofile");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_load_iccprofile");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((profilename = PDF_GetStringFromObj(p, interp, objv[2], PDF_0UTF16, &profilename_len)) == NULL)
    {
	PDF_WrongParameter(interp, "profilename in PDF_load_iccprofile");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_load_iccprofile");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_load_iccprofile(p, profilename, profilename_len, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_load_image(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * imagetype = NULL;
    int imagetype_len;
    const char * filename = NULL;
    int filename_len;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 5)
    {
	PDF_WrongCommand(interp, "PDF_load_image p imagetype filename optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_load_image");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_load_image");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((imagetype = PDF_GetStringFromObj(p, interp, objv[2], PDF_BYTES, &imagetype_len)) == NULL)
    {
	PDF_WrongParameter(interp, "imagetype in PDF_load_image");
	return TCL_ERROR;
    }
    if ((filename = PDF_GetStringFromObj(p, interp, objv[3], PDF_0UTF16, &filename_len)) == NULL)
    {
	PDF_WrongParameter(interp, "filename in PDF_load_image");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[4], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_load_image");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_load_image(p, imagetype, filename, filename_len, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_makespotcolor(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * spotname = NULL;
    int spotname_len;
    int volatile _retval = -1;

    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_makespotcolor p spotname");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_makespotcolor");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_makespotcolor");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((spotname = PDF_GetStringFromObj(p, interp, objv[2], PDF_BYTES, &spotname_len)) == NULL)
    {
	PDF_WrongParameter(interp, "spotname in PDF_makespotcolor");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_makespotcolor(p, spotname, 0);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_moveto(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double x;
    double y;


    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_moveto p x y");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_moveto");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_moveto");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &x) != TCL_OK)
    {
	PDF_WrongParameter(interp, "x in PDF_moveto");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &y) != TCL_OK)
    {
	PDF_WrongParameter(interp, "y in PDF_moveto");
	return TCL_ERROR;
    }

    try {
	PDF_moveto(p, x, y);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_open_CCITT(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * filename = NULL;
    int filename_len;
    int width;
    int height;
    int BitReverse;
    int K;
    int BlackIs1;
    int volatile _retval = -1;

    if (objc != 8)
    {
	PDF_WrongCommand(interp, "PDF_open_CCITT p filename width height BitReverse K BlackIs1");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_open_CCITT");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_open_CCITT");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((filename = PDF_GetStringFromObj(p, interp, objv[2], PDF_BYTES, &filename_len)) == NULL)
    {
	PDF_WrongParameter(interp, "filename in PDF_open_CCITT");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[3], &width) != TCL_OK)
    {
	PDF_WrongParameter(interp, "width in PDF_open_CCITT");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[4], &height) != TCL_OK)
    {
	PDF_WrongParameter(interp, "height in PDF_open_CCITT");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[5], &BitReverse) != TCL_OK)
    {
	PDF_WrongParameter(interp, "BitReverse in PDF_open_CCITT");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[6], &K) != TCL_OK)
    {
	PDF_WrongParameter(interp, "K in PDF_open_CCITT");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[7], &BlackIs1) != TCL_OK)
    {
	PDF_WrongParameter(interp, "BlackIs1 in PDF_open_CCITT");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_open_CCITT(p, filename, width, height, BitReverse, K, BlackIs1);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_open_file(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * filename = NULL;
    int filename_len;
    int volatile _retval = -1;

    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_open_file p filename");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_open_file");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_open_file");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((filename = PDF_GetStringFromObj(p, interp, objv[2], PDF_BYTES, &filename_len)) == NULL)
    {
	PDF_WrongParameter(interp, "filename in PDF_open_file");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_open_file(p, filename);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_open_image_file(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * imagetype = NULL;
    int imagetype_len;
    const char * filename = NULL;
    int filename_len;
    const char * stringparam = NULL;
    int stringparam_len;
    int intparam;
    int volatile _retval = -1;

    if (objc != 6)
    {
	PDF_WrongCommand(interp, "PDF_open_image_file p imagetype filename stringparam intparam");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_open_image_file");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_open_image_file");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((imagetype = PDF_GetStringFromObj(p, interp, objv[2], PDF_BYTES, &imagetype_len)) == NULL)
    {
	PDF_WrongParameter(interp, "imagetype in PDF_open_image_file");
	return TCL_ERROR;
    }
    if ((filename = PDF_GetStringFromObj(p, interp, objv[3], PDF_BYTES, &filename_len)) == NULL)
    {
	PDF_WrongParameter(interp, "filename in PDF_open_image_file");
	return TCL_ERROR;
    }
    if ((stringparam = PDF_GetStringFromObj(p, interp, objv[4], PDF_BYTES, &stringparam_len)) == NULL)
    {
	PDF_WrongParameter(interp, "stringparam in PDF_open_image_file");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[5], &intparam) != TCL_OK)
    {
	PDF_WrongParameter(interp, "intparam in PDF_open_image_file");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_open_image_file(p, imagetype, filename, stringparam, intparam);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_open_pdi_document(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * filename = NULL;
    int filename_len;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_open_pdi_document p filename optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_open_pdi_document");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_open_pdi_document");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((filename = PDF_GetStringFromObj(p, interp, objv[2], PDF_0UTF16, &filename_len)) == NULL)
    {
	PDF_WrongParameter(interp, "filename in PDF_open_pdi_document");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_open_pdi_document");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_open_pdi_document(p, filename, filename_len, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_open_pdi_page(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int doc;
    int pagenumber;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 5)
    {
	PDF_WrongCommand(interp, "PDF_open_pdi_page p doc pagenumber optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_open_pdi_page");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_open_pdi_page");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &doc) != TCL_OK)
    {
	PDF_WrongParameter(interp, "doc in PDF_open_pdi_page");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[3], &pagenumber) != TCL_OK)
    {
	PDF_WrongParameter(interp, "pagenumber in PDF_open_pdi_page");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[4], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_open_pdi_page");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_open_pdi_page(p, doc, pagenumber, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_pcos_get_number(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int doc;
    const char * path = NULL;
    int path_len;
    double volatile _retval = -1;

    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_pcos_get_number p doc path");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_pcos_get_number");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_pcos_get_number");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &doc) != TCL_OK)
    {
	PDF_WrongParameter(interp, "doc in PDF_pcos_get_number");
	return TCL_ERROR;
    }
    if ((path = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8, &path_len)) == NULL)
    {
	PDF_WrongParameter(interp, "path in PDF_pcos_get_number");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_pcos_get_number(p, doc, "%s", path);
    } catch;

    Tcl_PrintDouble(interp, (double)_retval, interp->result);

    return TCL_OK;
}

    
static int
_wrap_PDF_pcos_get_string(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int doc;
    const char * path = NULL;
    int path_len;
    const char volatile *_retval = NULL;

    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_pcos_get_string p doc path");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_pcos_get_string");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_pcos_get_string");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &doc) != TCL_OK)
    {
	PDF_WrongParameter(interp, "doc in PDF_pcos_get_string");
	return TCL_ERROR;
    }
    if ((path = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8, &path_len)) == NULL)
    {
	PDF_WrongParameter(interp, "path in PDF_pcos_get_string");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_pcos_get_string(p, doc, "%s", path);
    } catch;

    Tcl_SetResult(interp, (char *) _retval, TCL_VOLATILE);

    return TCL_OK;
}

    
static int
_wrap_PDF_pcos_get_stream(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int doc;
    int length;
    const char * optlist = NULL;
    int optlist_len;
    const char * path = NULL;
    int path_len;
    const char volatile *_retval = NULL;    Tcl_Obj *objPtr;

    if (objc != 5)
    {
	PDF_WrongCommand(interp, "PDF_pcos_get_stream p doc optlist path");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_pcos_get_stream");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_pcos_get_stream");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &doc) != TCL_OK)
    {
	PDF_WrongParameter(interp, "doc in PDF_pcos_get_stream");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_pcos_get_stream");
	return TCL_ERROR;
    }
    if ((path = PDF_GetStringFromObj(p, interp, objv[4], PDF_UTF8, &path_len)) == NULL)
    {
	PDF_WrongParameter(interp, "path in PDF_pcos_get_stream");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_pcos_get_stream(p, doc, &length, optlist, "%s", path);
    } catch;

    objPtr = Tcl_GetObjResult(interp);
    Tcl_SetByteArrayObj(objPtr, (unsigned char *)_retval, length);

    return TCL_OK;
}

    
static int
_wrap_PDF_place_image(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int image;
    double x;
    double y;
    double scale;


    if (objc != 6)
    {
	PDF_WrongCommand(interp, "PDF_place_image p image x y scale");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_place_image");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_place_image");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &image) != TCL_OK)
    {
	PDF_WrongParameter(interp, "image in PDF_place_image");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &x) != TCL_OK)
    {
	PDF_WrongParameter(interp, "x in PDF_place_image");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &y) != TCL_OK)
    {
	PDF_WrongParameter(interp, "y in PDF_place_image");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &scale) != TCL_OK)
    {
	PDF_WrongParameter(interp, "scale in PDF_place_image");
	return TCL_ERROR;
    }

    try {
	PDF_place_image(p, image, x, y, scale);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_place_pdi_page(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int page;
    double x;
    double y;
    double sx;
    double sy;


    if (objc != 7)
    {
	PDF_WrongCommand(interp, "PDF_place_pdi_page p page x y sx sy");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_place_pdi_page");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_place_pdi_page");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &page) != TCL_OK)
    {
	PDF_WrongParameter(interp, "page in PDF_place_pdi_page");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &x) != TCL_OK)
    {
	PDF_WrongParameter(interp, "x in PDF_place_pdi_page");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &y) != TCL_OK)
    {
	PDF_WrongParameter(interp, "y in PDF_place_pdi_page");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &sx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "sx in PDF_place_pdi_page");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[6], &sy) != TCL_OK)
    {
	PDF_WrongParameter(interp, "sy in PDF_place_pdi_page");
	return TCL_ERROR;
    }

    try {
	PDF_place_pdi_page(p, page, x, y, sx, sy);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_process_pdi(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int doc;
    int page;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 5)
    {
	PDF_WrongCommand(interp, "PDF_process_pdi p doc page optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_process_pdi");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_process_pdi");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &doc) != TCL_OK)
    {
	PDF_WrongParameter(interp, "doc in PDF_process_pdi");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[3], &page) != TCL_OK)
    {
	PDF_WrongParameter(interp, "page in PDF_process_pdi");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[4], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_process_pdi");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_process_pdi(p, doc, page, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_rect(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double x;
    double y;
    double width;
    double height;


    if (objc != 6)
    {
	PDF_WrongCommand(interp, "PDF_rect p x y width height");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_rect");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_rect");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &x) != TCL_OK)
    {
	PDF_WrongParameter(interp, "x in PDF_rect");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &y) != TCL_OK)
    {
	PDF_WrongParameter(interp, "y in PDF_rect");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &width) != TCL_OK)
    {
	PDF_WrongParameter(interp, "width in PDF_rect");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &height) != TCL_OK)
    {
	PDF_WrongParameter(interp, "height in PDF_rect");
	return TCL_ERROR;
    }

    try {
	PDF_rect(p, x, y, width, height);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_restore(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;


    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_restore p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_restore");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_restore");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	PDF_restore(p);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_resume_page(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * optlist = NULL;
    int optlist_len;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_resume_page p optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_resume_page");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_resume_page");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[2], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_resume_page");
	return TCL_ERROR;
    }

    try {
	PDF_resume_page(p, optlist);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_rotate(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double phi;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_rotate p phi");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_rotate");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_rotate");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &phi) != TCL_OK)
    {
	PDF_WrongParameter(interp, "phi in PDF_rotate");
	return TCL_ERROR;
    }

    try {
	PDF_rotate(p, phi);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_save(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;


    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_save p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_save");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_save");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	PDF_save(p);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_scale(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double sx;
    double sy;


    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_scale p sx sy");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_scale");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_scale");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &sx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "sx in PDF_scale");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &sy) != TCL_OK)
    {
	PDF_WrongParameter(interp, "sy in PDF_scale");
	return TCL_ERROR;
    }

    try {
	PDF_scale(p, sx, sy);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_set_border_color(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double red;
    double green;
    double blue;


    if (objc != 5)
    {
	PDF_WrongCommand(interp, "PDF_set_border_color p red green blue");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_set_border_color");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_set_border_color");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &red) != TCL_OK)
    {
	PDF_WrongParameter(interp, "red in PDF_set_border_color");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &green) != TCL_OK)
    {
	PDF_WrongParameter(interp, "green in PDF_set_border_color");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &blue) != TCL_OK)
    {
	PDF_WrongParameter(interp, "blue in PDF_set_border_color");
	return TCL_ERROR;
    }

    try {
	PDF_set_border_color(p, red, green, blue);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_set_border_dash(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double b;
    double w;


    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_set_border_dash p b w");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_set_border_dash");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_set_border_dash");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &b) != TCL_OK)
    {
	PDF_WrongParameter(interp, "b in PDF_set_border_dash");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &w) != TCL_OK)
    {
	PDF_WrongParameter(interp, "w in PDF_set_border_dash");
	return TCL_ERROR;
    }

    try {
	PDF_set_border_dash(p, b, w);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_set_border_style(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * style = NULL;
    int style_len;
    double width;


    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_set_border_style p style width");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_set_border_style");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_set_border_style");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((style = PDF_GetStringFromObj(p, interp, objv[2], PDF_BYTES, &style_len)) == NULL)
    {
	PDF_WrongParameter(interp, "style in PDF_set_border_style");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &width) != TCL_OK)
    {
	PDF_WrongParameter(interp, "width in PDF_set_border_style");
	return TCL_ERROR;
    }

    try {
	PDF_set_border_style(p, style, width);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_set_gstate(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int gstate;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_set_gstate p gstate");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_set_gstate");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_set_gstate");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &gstate) != TCL_OK)
    {
	PDF_WrongParameter(interp, "gstate in PDF_set_gstate");
	return TCL_ERROR;
    }

    try {
	PDF_set_gstate(p, gstate);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_set_info(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * key = NULL;
    int key_len;
    const char * value = NULL;
    int value_len;


    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_set_info p key value");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_set_info");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_set_info");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((key = PDF_GetStringFromObj(p, interp, objv[2], PDF_UTF8, &key_len)) == NULL)
    {
	PDF_WrongParameter(interp, "key in PDF_set_info");
	return TCL_ERROR;
    }
    if ((value = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF16, &value_len)) == NULL)
    {
	PDF_WrongParameter(interp, "value in PDF_set_info");
	return TCL_ERROR;
    }

    try {
	PDF_set_info2(p, key, value, value_len);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_set_layer_dependency(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * type = NULL;
    int type_len;
    const char * optlist = NULL;
    int optlist_len;


    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_set_layer_dependency p type optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_set_layer_dependency");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_set_layer_dependency");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((type = PDF_GetStringFromObj(p, interp, objv[2], PDF_BYTES, &type_len)) == NULL)
    {
	PDF_WrongParameter(interp, "type in PDF_set_layer_dependency");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_set_layer_dependency");
	return TCL_ERROR;
    }

    try {
	PDF_set_layer_dependency(p, type, optlist);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_set_parameter(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * key = NULL;
    int key_len;
    const char * value = NULL;
    int value_len;


    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_set_parameter p key value");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_set_parameter");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_set_parameter");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((key = PDF_GetStringFromObj(p, interp, objv[2], PDF_BYTES, &key_len)) == NULL)
    {
	PDF_WrongParameter(interp, "key in PDF_set_parameter");
	return TCL_ERROR;
    }
    if ((value = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8, &value_len)) == NULL)
    {
	PDF_WrongParameter(interp, "value in PDF_set_parameter");
	return TCL_ERROR;
    }

    try {
	PDF_set_parameter(p, key, value);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_set_text_pos(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double x;
    double y;


    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_set_text_pos p x y");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_set_text_pos");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_set_text_pos");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &x) != TCL_OK)
    {
	PDF_WrongParameter(interp, "x in PDF_set_text_pos");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &y) != TCL_OK)
    {
	PDF_WrongParameter(interp, "y in PDF_set_text_pos");
	return TCL_ERROR;
    }

    try {
	PDF_set_text_pos(p, x, y);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_set_value(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * key = NULL;
    int key_len;
    double value;


    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_set_value p key value");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_set_value");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_set_value");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((key = PDF_GetStringFromObj(p, interp, objv[2], PDF_BYTES, &key_len)) == NULL)
    {
	PDF_WrongParameter(interp, "key in PDF_set_value");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &value) != TCL_OK)
    {
	PDF_WrongParameter(interp, "value in PDF_set_value");
	return TCL_ERROR;
    }

    try {
	PDF_set_value(p, key, value);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_setcolor(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * fstype = NULL;
    int fstype_len;
    const char * colorspace = NULL;
    int colorspace_len;
    double c1;
    double c2;
    double c3;
    double c4;


    if (objc != 8)
    {
	PDF_WrongCommand(interp, "PDF_setcolor p fstype colorspace c1 c2 c3 c4");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_setcolor");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_setcolor");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((fstype = PDF_GetStringFromObj(p, interp, objv[2], PDF_BYTES, &fstype_len)) == NULL)
    {
	PDF_WrongParameter(interp, "fstype in PDF_setcolor");
	return TCL_ERROR;
    }
    if ((colorspace = PDF_GetStringFromObj(p, interp, objv[3], PDF_BYTES, &colorspace_len)) == NULL)
    {
	PDF_WrongParameter(interp, "colorspace in PDF_setcolor");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &c1) != TCL_OK)
    {
	PDF_WrongParameter(interp, "c1 in PDF_setcolor");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &c2) != TCL_OK)
    {
	PDF_WrongParameter(interp, "c2 in PDF_setcolor");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[6], &c3) != TCL_OK)
    {
	PDF_WrongParameter(interp, "c3 in PDF_setcolor");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[7], &c4) != TCL_OK)
    {
	PDF_WrongParameter(interp, "c4 in PDF_setcolor");
	return TCL_ERROR;
    }

    try {
	PDF_setcolor(p, fstype, colorspace, c1, c2, c3, c4);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_setdash(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double b;
    double w;


    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_setdash p b w");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_setdash");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_setdash");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &b) != TCL_OK)
    {
	PDF_WrongParameter(interp, "b in PDF_setdash");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &w) != TCL_OK)
    {
	PDF_WrongParameter(interp, "w in PDF_setdash");
	return TCL_ERROR;
    }

    try {
	PDF_setdash(p, b, w);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_setdashpattern(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * optlist = NULL;
    int optlist_len;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_setdashpattern p optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_setdashpattern");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_setdashpattern");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[2], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_setdashpattern");
	return TCL_ERROR;
    }

    try {
	PDF_setdashpattern(p, optlist);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_setflat(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double flatness;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_setflat p flatness");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_setflat");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_setflat");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &flatness) != TCL_OK)
    {
	PDF_WrongParameter(interp, "flatness in PDF_setflat");
	return TCL_ERROR;
    }

    try {
	PDF_setflat(p, flatness);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_setfont(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int font;
    double fontsize;


    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_setfont p font fontsize");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_setfont");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_setfont");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &font) != TCL_OK)
    {
	PDF_WrongParameter(interp, "font in PDF_setfont");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &fontsize) != TCL_OK)
    {
	PDF_WrongParameter(interp, "fontsize in PDF_setfont");
	return TCL_ERROR;
    }

    try {
	PDF_setfont(p, font, fontsize);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_setgray(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double gray;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_setgray p gray");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_setgray");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_setgray");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &gray) != TCL_OK)
    {
	PDF_WrongParameter(interp, "gray in PDF_setgray");
	return TCL_ERROR;
    }

    try {
	PDF_setgray(p, gray);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_setgray_fill(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double gray;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_setgray_fill p gray");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_setgray_fill");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_setgray_fill");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &gray) != TCL_OK)
    {
	PDF_WrongParameter(interp, "gray in PDF_setgray_fill");
	return TCL_ERROR;
    }

    try {
	PDF_setgray_fill(p, gray);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_setgray_stroke(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double gray;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_setgray_stroke p gray");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_setgray_stroke");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_setgray_stroke");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &gray) != TCL_OK)
    {
	PDF_WrongParameter(interp, "gray in PDF_setgray_stroke");
	return TCL_ERROR;
    }

    try {
	PDF_setgray_stroke(p, gray);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_setlinecap(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int linecap;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_setlinecap p linecap");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_setlinecap");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_setlinecap");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &linecap) != TCL_OK)
    {
	PDF_WrongParameter(interp, "linecap in PDF_setlinecap");
	return TCL_ERROR;
    }

    try {
	PDF_setlinecap(p, linecap);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_setlinejoin(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int linejoin;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_setlinejoin p linejoin");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_setlinejoin");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_setlinejoin");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &linejoin) != TCL_OK)
    {
	PDF_WrongParameter(interp, "linejoin in PDF_setlinejoin");
	return TCL_ERROR;
    }

    try {
	PDF_setlinejoin(p, linejoin);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_setlinewidth(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double width;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_setlinewidth p width");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_setlinewidth");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_setlinewidth");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &width) != TCL_OK)
    {
	PDF_WrongParameter(interp, "width in PDF_setlinewidth");
	return TCL_ERROR;
    }

    try {
	PDF_setlinewidth(p, width);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_setmatrix(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double a;
    double b;
    double c;
    double d;
    double e;
    double f;


    if (objc != 8)
    {
	PDF_WrongCommand(interp, "PDF_setmatrix p a b c d e f");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_setmatrix");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_setmatrix");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &a) != TCL_OK)
    {
	PDF_WrongParameter(interp, "a in PDF_setmatrix");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &b) != TCL_OK)
    {
	PDF_WrongParameter(interp, "b in PDF_setmatrix");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &c) != TCL_OK)
    {
	PDF_WrongParameter(interp, "c in PDF_setmatrix");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &d) != TCL_OK)
    {
	PDF_WrongParameter(interp, "d in PDF_setmatrix");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[6], &e) != TCL_OK)
    {
	PDF_WrongParameter(interp, "e in PDF_setmatrix");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[7], &f) != TCL_OK)
    {
	PDF_WrongParameter(interp, "f in PDF_setmatrix");
	return TCL_ERROR;
    }

    try {
	PDF_setmatrix(p, a, b, c, d, e, f);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_setmiterlimit(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double miter;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_setmiterlimit p miter");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_setmiterlimit");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_setmiterlimit");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &miter) != TCL_OK)
    {
	PDF_WrongParameter(interp, "miter in PDF_setmiterlimit");
	return TCL_ERROR;
    }

    try {
	PDF_setmiterlimit(p, miter);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_setrgbcolor(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double red;
    double green;
    double blue;


    if (objc != 5)
    {
	PDF_WrongCommand(interp, "PDF_setrgbcolor p red green blue");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_setrgbcolor");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_setrgbcolor");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &red) != TCL_OK)
    {
	PDF_WrongParameter(interp, "red in PDF_setrgbcolor");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &green) != TCL_OK)
    {
	PDF_WrongParameter(interp, "green in PDF_setrgbcolor");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &blue) != TCL_OK)
    {
	PDF_WrongParameter(interp, "blue in PDF_setrgbcolor");
	return TCL_ERROR;
    }

    try {
	PDF_setrgbcolor(p, red, green, blue);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_setrgbcolor_fill(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double red;
    double green;
    double blue;


    if (objc != 5)
    {
	PDF_WrongCommand(interp, "PDF_setrgbcolor_fill p red green blue");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_setrgbcolor_fill");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_setrgbcolor_fill");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &red) != TCL_OK)
    {
	PDF_WrongParameter(interp, "red in PDF_setrgbcolor_fill");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &green) != TCL_OK)
    {
	PDF_WrongParameter(interp, "green in PDF_setrgbcolor_fill");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &blue) != TCL_OK)
    {
	PDF_WrongParameter(interp, "blue in PDF_setrgbcolor_fill");
	return TCL_ERROR;
    }

    try {
	PDF_setrgbcolor_fill(p, red, green, blue);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_setrgbcolor_stroke(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double red;
    double green;
    double blue;


    if (objc != 5)
    {
	PDF_WrongCommand(interp, "PDF_setrgbcolor_stroke p red green blue");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_setrgbcolor_stroke");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_setrgbcolor_stroke");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &red) != TCL_OK)
    {
	PDF_WrongParameter(interp, "red in PDF_setrgbcolor_stroke");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &green) != TCL_OK)
    {
	PDF_WrongParameter(interp, "green in PDF_setrgbcolor_stroke");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &blue) != TCL_OK)
    {
	PDF_WrongParameter(interp, "blue in PDF_setrgbcolor_stroke");
	return TCL_ERROR;
    }

    try {
	PDF_setrgbcolor_stroke(p, red, green, blue);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_shading(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * shtype = NULL;
    int shtype_len;
    double x_0;
    double y_0;
    double x_1;
    double y_1;
    double c_1;
    double c_2;
    double c_3;
    double c_4;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 12)
    {
	PDF_WrongCommand(interp, "PDF_shading p shtype x_0 y_0 x_1 y_1 c_1 c_2 c_3 c_4 optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_shading");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_shading");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((shtype = PDF_GetStringFromObj(p, interp, objv[2], PDF_BYTES, &shtype_len)) == NULL)
    {
	PDF_WrongParameter(interp, "shtype in PDF_shading");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &x_0) != TCL_OK)
    {
	PDF_WrongParameter(interp, "x_0 in PDF_shading");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &y_0) != TCL_OK)
    {
	PDF_WrongParameter(interp, "y_0 in PDF_shading");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[5], &x_1) != TCL_OK)
    {
	PDF_WrongParameter(interp, "x_1 in PDF_shading");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[6], &y_1) != TCL_OK)
    {
	PDF_WrongParameter(interp, "y_1 in PDF_shading");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[7], &c_1) != TCL_OK)
    {
	PDF_WrongParameter(interp, "c_1 in PDF_shading");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[8], &c_2) != TCL_OK)
    {
	PDF_WrongParameter(interp, "c_2 in PDF_shading");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[9], &c_3) != TCL_OK)
    {
	PDF_WrongParameter(interp, "c_3 in PDF_shading");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[10], &c_4) != TCL_OK)
    {
	PDF_WrongParameter(interp, "c_4 in PDF_shading");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[11], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_shading");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_shading(p, shtype, x_0, y_0, x_1, y_1, c_1, c_2, c_3, c_4, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_shading_pattern(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int shading;
    const char * optlist = NULL;
    int optlist_len;
    int volatile _retval = -1;

    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_shading_pattern p shading optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_shading_pattern");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_shading_pattern");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &shading) != TCL_OK)
    {
	PDF_WrongParameter(interp, "shading in PDF_shading_pattern");
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[3], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_shading_pattern");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_shading_pattern(p, shading, optlist);
    } catch;

    sprintf(interp->result, "%d", _retval);

    return TCL_OK;
}

    
static int
_wrap_PDF_shfill(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    int shading;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_shfill p shading");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_shfill");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_shfill");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[2], &shading) != TCL_OK)
    {
	PDF_WrongParameter(interp, "shading in PDF_shfill");
	return TCL_ERROR;
    }

    try {
	PDF_shfill(p, shading);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_show(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * text = NULL;
    int text_len;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_show p text");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_show");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_show");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((text = PDF_GetStringFromObj(p, interp, objv[2], PDF_UTF16, &text_len)) == NULL)
    {
	PDF_WrongParameter(interp, "text in PDF_show");
	return TCL_ERROR;
    }

    try {
	PDF_show2(p, text, text_len);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_show_xy(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * text = NULL;
    int text_len;
    double x;
    double y;


    if (objc != 5)
    {
	PDF_WrongCommand(interp, "PDF_show_xy p text x y");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_show_xy");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_show_xy");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((text = PDF_GetStringFromObj(p, interp, objv[2], PDF_UTF16, &text_len)) == NULL)
    {
	PDF_WrongParameter(interp, "text in PDF_show_xy");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &x) != TCL_OK)
    {
	PDF_WrongParameter(interp, "x in PDF_show_xy");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &y) != TCL_OK)
    {
	PDF_WrongParameter(interp, "y in PDF_show_xy");
	return TCL_ERROR;
    }

    try {
	PDF_show_xy2(p, text, text_len, x, y);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_skew(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double alpha;
    double beta;


    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_skew p alpha beta");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_skew");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_skew");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &alpha) != TCL_OK)
    {
	PDF_WrongParameter(interp, "alpha in PDF_skew");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &beta) != TCL_OK)
    {
	PDF_WrongParameter(interp, "beta in PDF_skew");
	return TCL_ERROR;
    }

    try {
	PDF_skew(p, alpha, beta);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_stringwidth(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * text = NULL;
    int text_len;
    int font;
    double fontsize;
    double volatile _retval = -1;

    if (objc != 5)
    {
	PDF_WrongCommand(interp, "PDF_stringwidth p text font fontsize");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_stringwidth");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_stringwidth");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((text = PDF_GetStringFromObj(p, interp, objv[2], PDF_UTF16, &text_len)) == NULL)
    {
	PDF_WrongParameter(interp, "text in PDF_stringwidth");
	return TCL_ERROR;
    }
    if (Tcl_GetIntFromObj(interp, objv[3], &font) != TCL_OK)
    {
	PDF_WrongParameter(interp, "font in PDF_stringwidth");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[4], &fontsize) != TCL_OK)
    {
	PDF_WrongParameter(interp, "fontsize in PDF_stringwidth");
	return TCL_ERROR;
    }

    try {
	_retval = PDF_stringwidth2(p, text, text_len, font, fontsize);
    } catch;

    Tcl_PrintDouble(interp, (double)_retval, interp->result);

    return TCL_OK;
}

    
static int
_wrap_PDF_stroke(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;


    if (objc != 2)
    {
	PDF_WrongCommand(interp, "PDF_stroke p");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_stroke");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_stroke");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }

    try {
	PDF_stroke(p);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_suspend_page(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    const char * optlist = NULL;
    int optlist_len;


    if (objc != 3)
    {
	PDF_WrongCommand(interp, "PDF_suspend_page p optlist");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_suspend_page");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_suspend_page");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if ((optlist = PDF_GetStringFromObj(p, interp, objv[2], PDF_UTF8, &optlist_len)) == NULL)
    {
	PDF_WrongParameter(interp, "optlist in PDF_suspend_page");
	return TCL_ERROR;
    }

    try {
	PDF_suspend_page(p, optlist);
    } catch;


    return TCL_OK;
}

    
static int
_wrap_PDF_translate(ClientData clientData, Tcl_Interp *interp,
    int objc, Tcl_Obj *CONST objv[])
{
    PDF *p;
    char *pdf;
    double tx;
    double ty;


    if (objc != 4)
    {
	PDF_WrongCommand(interp, "PDF_translate p tx ty");
	return TCL_ERROR;
    }

    if ((pdf = Tcl_GetStringFromObj(objv[1], NULL)) == NULL)
    {
	PDF_NoPDFHandle(interp, "PDF_translate");
        return TCL_ERROR;
    }

    if (SWIG_GetPtr(pdf, (void **) &p, "_PDF_p"))
    {
	PDF_WrongPDFHandle(interp, "PDF_translate");
        Tcl_AppendResult(interp, pdf, (char *) NULL);
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[2], &tx) != TCL_OK)
    {
	PDF_WrongParameter(interp, "tx in PDF_translate");
	return TCL_ERROR;
    }
    if (Tcl_GetDoubleFromObj(interp, objv[3], &ty) != TCL_OK)
    {
	PDF_WrongParameter(interp, "ty in PDF_translate");
	return TCL_ERROR;
    }

    try {
	PDF_translate(p, tx, ty);
    } catch;


    return TCL_OK;
}
#endif /* defined(_WRAP_CODE) */
#if defined(_WRAP_METHODS)
Tcl_CreateObjCommand(interp, "PDF_activate_item", (Tcl_ObjCmdProc*)
    _wrap_PDF_activate_item, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_create_3dview", (Tcl_ObjCmdProc*)
    _wrap_PDF_create_3dview, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_load_3ddata", (Tcl_ObjCmdProc*)
    _wrap_PDF_load_3ddata, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_add_bookmark", (Tcl_ObjCmdProc*)
    _wrap_PDF_add_bookmark, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_add_launchlink", (Tcl_ObjCmdProc*)
    _wrap_PDF_add_launchlink, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_add_locallink", (Tcl_ObjCmdProc*)
    _wrap_PDF_add_locallink, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_add_nameddest", (Tcl_ObjCmdProc*)
    _wrap_PDF_add_nameddest, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_add_note", (Tcl_ObjCmdProc*)
    _wrap_PDF_add_note, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_add_pdflink", (Tcl_ObjCmdProc*)
    _wrap_PDF_add_pdflink, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_add_table_cell", (Tcl_ObjCmdProc*)
    _wrap_PDF_add_table_cell, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_add_textflow", (Tcl_ObjCmdProc*)
    _wrap_PDF_add_textflow, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_add_thumbnail", (Tcl_ObjCmdProc*)
    _wrap_PDF_add_thumbnail, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_add_weblink", (Tcl_ObjCmdProc*)
    _wrap_PDF_add_weblink, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_arc", (Tcl_ObjCmdProc*)
    _wrap_PDF_arc, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_arcn", (Tcl_ObjCmdProc*)
    _wrap_PDF_arcn, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_attach_file", (Tcl_ObjCmdProc*)
    _wrap_PDF_attach_file, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_begin_document", (Tcl_ObjCmdProc*)
    _wrap_PDF_begin_document, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_begin_font", (Tcl_ObjCmdProc*)
    _wrap_PDF_begin_font, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_begin_glyph", (Tcl_ObjCmdProc*)
    _wrap_PDF_begin_glyph, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_begin_item", (Tcl_ObjCmdProc*)
    _wrap_PDF_begin_item, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_begin_layer", (Tcl_ObjCmdProc*)
    _wrap_PDF_begin_layer, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_begin_page", (Tcl_ObjCmdProc*)
    _wrap_PDF_begin_page, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_begin_page_ext", (Tcl_ObjCmdProc*)
    _wrap_PDF_begin_page_ext, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_begin_pattern", (Tcl_ObjCmdProc*)
    _wrap_PDF_begin_pattern, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_begin_template", (Tcl_ObjCmdProc*)
    _wrap_PDF_begin_template, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_begin_template_ext", (Tcl_ObjCmdProc*)
    _wrap_PDF_begin_template_ext, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_circle", (Tcl_ObjCmdProc*)
    _wrap_PDF_circle, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_clip", (Tcl_ObjCmdProc*)
    _wrap_PDF_clip, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_close", (Tcl_ObjCmdProc*)
    _wrap_PDF_close, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_close_image", (Tcl_ObjCmdProc*)
    _wrap_PDF_close_image, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_close_pdi", (Tcl_ObjCmdProc*)
    _wrap_PDF_close_pdi, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_close_pdi_document", (Tcl_ObjCmdProc*)
    _wrap_PDF_close_pdi_document, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_close_pdi_page", (Tcl_ObjCmdProc*)
    _wrap_PDF_close_pdi_page, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_closepath", (Tcl_ObjCmdProc*)
    _wrap_PDF_closepath, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_closepath_fill_stroke", (Tcl_ObjCmdProc*)
    _wrap_PDF_closepath_fill_stroke, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_closepath_stroke", (Tcl_ObjCmdProc*)
    _wrap_PDF_closepath_stroke, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_concat", (Tcl_ObjCmdProc*)
    _wrap_PDF_concat, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_continue_text", (Tcl_ObjCmdProc*)
    _wrap_PDF_continue_text, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_create_action", (Tcl_ObjCmdProc*)
    _wrap_PDF_create_action, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_create_annotation", (Tcl_ObjCmdProc*)
    _wrap_PDF_create_annotation, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_create_bookmark", (Tcl_ObjCmdProc*)
    _wrap_PDF_create_bookmark, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_create_field", (Tcl_ObjCmdProc*)
    _wrap_PDF_create_field, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_create_fieldgroup", (Tcl_ObjCmdProc*)
    _wrap_PDF_create_fieldgroup, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_create_gstate", (Tcl_ObjCmdProc*)
    _wrap_PDF_create_gstate, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_create_pvf", (Tcl_ObjCmdProc*)
    _wrap_PDF_create_pvf, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_create_textflow", (Tcl_ObjCmdProc*)
    _wrap_PDF_create_textflow, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_curveto", (Tcl_ObjCmdProc*)
    _wrap_PDF_curveto, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_define_layer", (Tcl_ObjCmdProc*)
    _wrap_PDF_define_layer, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_delete", (Tcl_ObjCmdProc*)
    _wrap_PDF_delete, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_delete_pvf", (Tcl_ObjCmdProc*)
    _wrap_PDF_delete_pvf, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_delete_table", (Tcl_ObjCmdProc*)
    _wrap_PDF_delete_table, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_delete_textflow", (Tcl_ObjCmdProc*)
    _wrap_PDF_delete_textflow, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_encoding_set_char", (Tcl_ObjCmdProc*)
    _wrap_PDF_encoding_set_char, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_end_document", (Tcl_ObjCmdProc*)
    _wrap_PDF_end_document, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_end_font", (Tcl_ObjCmdProc*)
    _wrap_PDF_end_font, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_end_glyph", (Tcl_ObjCmdProc*)
    _wrap_PDF_end_glyph, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_end_item", (Tcl_ObjCmdProc*)
    _wrap_PDF_end_item, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_end_layer", (Tcl_ObjCmdProc*)
    _wrap_PDF_end_layer, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_end_mc", (Tcl_ObjCmdProc*)
    _wrap_PDF_end_mc, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_end_page", (Tcl_ObjCmdProc*)
    _wrap_PDF_end_page, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_end_page_ext", (Tcl_ObjCmdProc*)
    _wrap_PDF_end_page_ext, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_end_pattern", (Tcl_ObjCmdProc*)
    _wrap_PDF_end_pattern, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_end_template", (Tcl_ObjCmdProc*)
    _wrap_PDF_end_template, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_endpath", (Tcl_ObjCmdProc*)
    _wrap_PDF_endpath, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_fill", (Tcl_ObjCmdProc*)
    _wrap_PDF_fill, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_fill_imageblock", (Tcl_ObjCmdProc*)
    _wrap_PDF_fill_imageblock, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_fill_pdfblock", (Tcl_ObjCmdProc*)
    _wrap_PDF_fill_pdfblock, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_fill_stroke", (Tcl_ObjCmdProc*)
    _wrap_PDF_fill_stroke, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_fill_textblock", (Tcl_ObjCmdProc*)
    _wrap_PDF_fill_textblock, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_findfont", (Tcl_ObjCmdProc*)
    _wrap_PDF_findfont, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_fit_image", (Tcl_ObjCmdProc*)
    _wrap_PDF_fit_image, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_fit_pdi_page", (Tcl_ObjCmdProc*)
    _wrap_PDF_fit_pdi_page, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_fit_table", (Tcl_ObjCmdProc*)
    _wrap_PDF_fit_table, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_fit_textflow", (Tcl_ObjCmdProc*)
    _wrap_PDF_fit_textflow, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_fit_textline", (Tcl_ObjCmdProc*)
    _wrap_PDF_fit_textline, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_get_apiname", (Tcl_ObjCmdProc*)
    _wrap_PDF_get_apiname, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_get_buffer", (Tcl_ObjCmdProc*)
    _wrap_PDF_get_buffer, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_get_errmsg", (Tcl_ObjCmdProc*)
    _wrap_PDF_get_errmsg, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_get_errnum", (Tcl_ObjCmdProc*)
    _wrap_PDF_get_errnum, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_get_parameter", (Tcl_ObjCmdProc*)
    _wrap_PDF_get_parameter, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_get_pdi_parameter", (Tcl_ObjCmdProc*)
    _wrap_PDF_get_pdi_parameter, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_get_pdi_value", (Tcl_ObjCmdProc*)
    _wrap_PDF_get_pdi_value, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_get_value", (Tcl_ObjCmdProc*)
    _wrap_PDF_get_value, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_info_font", (Tcl_ObjCmdProc*)
    _wrap_PDF_info_font, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_info_matchbox", (Tcl_ObjCmdProc*)
    _wrap_PDF_info_matchbox, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_info_table", (Tcl_ObjCmdProc*)
    _wrap_PDF_info_table, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_info_textflow", (Tcl_ObjCmdProc*)
    _wrap_PDF_info_textflow, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_info_textline", (Tcl_ObjCmdProc*)
    _wrap_PDF_info_textline, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_initgraphics", (Tcl_ObjCmdProc*)
    _wrap_PDF_initgraphics, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_lineto", (Tcl_ObjCmdProc*)
    _wrap_PDF_lineto, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_load_font", (Tcl_ObjCmdProc*)
    _wrap_PDF_load_font, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_load_iccprofile", (Tcl_ObjCmdProc*)
    _wrap_PDF_load_iccprofile, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_load_image", (Tcl_ObjCmdProc*)
    _wrap_PDF_load_image, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_makespotcolor", (Tcl_ObjCmdProc*)
    _wrap_PDF_makespotcolor, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_moveto", (Tcl_ObjCmdProc*)
    _wrap_PDF_moveto, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_new", (Tcl_ObjCmdProc*)
    _wrap_PDF_new, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_open_CCITT", (Tcl_ObjCmdProc*)
    _wrap_PDF_open_CCITT, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_open_file", (Tcl_ObjCmdProc*)
    _wrap_PDF_open_file, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_open_image", (Tcl_ObjCmdProc*)
    _wrap_PDF_open_image, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_open_image_file", (Tcl_ObjCmdProc*)
    _wrap_PDF_open_image_file, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_open_pdi", (Tcl_ObjCmdProc*)
    _wrap_PDF_open_pdi, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_open_pdi_document", (Tcl_ObjCmdProc*)
    _wrap_PDF_open_pdi_document, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_open_pdi_page", (Tcl_ObjCmdProc*)
    _wrap_PDF_open_pdi_page, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_pcos_get_number", (Tcl_ObjCmdProc*)
    _wrap_PDF_pcos_get_number, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_pcos_get_string", (Tcl_ObjCmdProc*)
    _wrap_PDF_pcos_get_string, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_pcos_get_stream", (Tcl_ObjCmdProc*)
    _wrap_PDF_pcos_get_stream, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_place_image", (Tcl_ObjCmdProc*)
    _wrap_PDF_place_image, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_place_pdi_page", (Tcl_ObjCmdProc*)
    _wrap_PDF_place_pdi_page, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_process_pdi", (Tcl_ObjCmdProc*)
    _wrap_PDF_process_pdi, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_rect", (Tcl_ObjCmdProc*)
    _wrap_PDF_rect, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_restore", (Tcl_ObjCmdProc*)
    _wrap_PDF_restore, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_resume_page", (Tcl_ObjCmdProc*)
    _wrap_PDF_resume_page, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_rotate", (Tcl_ObjCmdProc*)
    _wrap_PDF_rotate, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_save", (Tcl_ObjCmdProc*)
    _wrap_PDF_save, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_scale", (Tcl_ObjCmdProc*)
    _wrap_PDF_scale, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_set_border_color", (Tcl_ObjCmdProc*)
    _wrap_PDF_set_border_color, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_set_border_dash", (Tcl_ObjCmdProc*)
    _wrap_PDF_set_border_dash, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_set_border_style", (Tcl_ObjCmdProc*)
    _wrap_PDF_set_border_style, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_set_gstate", (Tcl_ObjCmdProc*)
    _wrap_PDF_set_gstate, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_set_info", (Tcl_ObjCmdProc*)
    _wrap_PDF_set_info, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_set_layer_dependency", (Tcl_ObjCmdProc*)
    _wrap_PDF_set_layer_dependency, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_set_parameter", (Tcl_ObjCmdProc*)
    _wrap_PDF_set_parameter, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_set_text_pos", (Tcl_ObjCmdProc*)
    _wrap_PDF_set_text_pos, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_set_value", (Tcl_ObjCmdProc*)
    _wrap_PDF_set_value, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_setcolor", (Tcl_ObjCmdProc*)
    _wrap_PDF_setcolor, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_setdash", (Tcl_ObjCmdProc*)
    _wrap_PDF_setdash, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_setdashpattern", (Tcl_ObjCmdProc*)
    _wrap_PDF_setdashpattern, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_setflat", (Tcl_ObjCmdProc*)
    _wrap_PDF_setflat, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_setfont", (Tcl_ObjCmdProc*)
    _wrap_PDF_setfont, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_setgray", (Tcl_ObjCmdProc*)
    _wrap_PDF_setgray, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_setgray_fill", (Tcl_ObjCmdProc*)
    _wrap_PDF_setgray_fill, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_setgray_stroke", (Tcl_ObjCmdProc*)
    _wrap_PDF_setgray_stroke, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_setlinecap", (Tcl_ObjCmdProc*)
    _wrap_PDF_setlinecap, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_setlinejoin", (Tcl_ObjCmdProc*)
    _wrap_PDF_setlinejoin, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_setlinewidth", (Tcl_ObjCmdProc*)
    _wrap_PDF_setlinewidth, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_setmatrix", (Tcl_ObjCmdProc*)
    _wrap_PDF_setmatrix, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_setmiterlimit", (Tcl_ObjCmdProc*)
    _wrap_PDF_setmiterlimit, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_setpolydash", (Tcl_ObjCmdProc*)
    _wrap_PDF_setpolydash, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_setrgbcolor", (Tcl_ObjCmdProc*)
    _wrap_PDF_setrgbcolor, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_setrgbcolor_fill", (Tcl_ObjCmdProc*)
    _wrap_PDF_setrgbcolor_fill, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_setrgbcolor_stroke", (Tcl_ObjCmdProc*)
    _wrap_PDF_setrgbcolor_stroke, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_shading", (Tcl_ObjCmdProc*)
    _wrap_PDF_shading, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_shading_pattern", (Tcl_ObjCmdProc*)
    _wrap_PDF_shading_pattern, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_shfill", (Tcl_ObjCmdProc*)
    _wrap_PDF_shfill, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_show", (Tcl_ObjCmdProc*)
    _wrap_PDF_show, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_show_xy", (Tcl_ObjCmdProc*)
    _wrap_PDF_show_xy, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_skew", (Tcl_ObjCmdProc*)
    _wrap_PDF_skew, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_stringwidth", (Tcl_ObjCmdProc*)
    _wrap_PDF_stringwidth, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_stroke", (Tcl_ObjCmdProc*)
    _wrap_PDF_stroke, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_suspend_page", (Tcl_ObjCmdProc*)
    _wrap_PDF_suspend_page, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
Tcl_CreateObjCommand(interp, "PDF_translate", (Tcl_ObjCmdProc*)
    _wrap_PDF_translate, (ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
#endif /* defined(_WRAP_METHODS)*/
