#if defined(_WRAP_CODE)

    
XS(_wrap_PDF_activate_item) { /* {{{ */
    PDF * p;
    int id;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_activate_item(p, id);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_activate_item. Expected PDFPtr.");
	XSRETURN(1);
    }

    id = SvIV(ST(1));

    try {
        PDF_activate_item(p, id);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_create_3dview) { /* {{{ */
    PDF * p;
    const char * username;
    size_t username_len;
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_create_3dview(p, username, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_create_3dview. Expected PDFPtr.");
	XSRETURN(1);
    }

    username = SvPV(ST(1), username_len);
    optlist = SvPV(ST(2), PL_na);

    try {
        _result = PDF_create_3dview(p, username, 0, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_load_3ddata) { /* {{{ */
    PDF * p;
    const char * filename;
    size_t filename_len;
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_load_3ddata(p, filename, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_load_3ddata. Expected PDFPtr.");
	XSRETURN(1);
    }

    filename = SvPV(ST(1), filename_len);
    optlist = SvPV(ST(2), PL_na);

    try {
        _result = PDF_load_3ddata(p, filename, 0, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_add_bookmark) { /* {{{ */
    PDF * p;
    const char * text;
    size_t len;
    int parent;
    int open;
    int _result = -1;
    dXSARGS;

    if (items != 4) {
	croak("Usage: PDF_add_bookmark(p, text, parent, open);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_add_bookmark. Expected PDFPtr.");
	XSRETURN(1);
    }

    text = SvPV(ST(1), len);
    parent = SvIV(ST(2));
    open = SvIV(ST(3));

    try {
        _result = PDF_add_bookmark2(p, text, (int)len, parent, open);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_add_launchlink) { /* {{{ */
    PDF * p;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * filename;
    dXSARGS;

    if (items != 6) {
	croak("Usage: PDF_add_launchlink(p, llx, lly, urx, ury, filename);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_add_launchlink. Expected PDFPtr.");
	XSRETURN(1);
    }

    llx = SvNV(ST(1));
    lly = SvNV(ST(2));
    urx = SvNV(ST(3));
    ury = SvNV(ST(4));
    filename = SvPV(ST(5), PL_na);

    try {
        PDF_add_launchlink(p, llx, lly, urx, ury, filename);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_add_locallink) { /* {{{ */
    PDF * p;
    double llx;
    double lly;
    double urx;
    double ury;
    int page;
    const char * optlist;
    dXSARGS;

    if (items != 7) {
	croak("Usage: PDF_add_locallink(p, llx, lly, urx, ury, page, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_add_locallink. Expected PDFPtr.");
	XSRETURN(1);
    }

    llx = SvNV(ST(1));
    lly = SvNV(ST(2));
    urx = SvNV(ST(3));
    ury = SvNV(ST(4));
    page = SvIV(ST(5));
    optlist = SvPV(ST(6), PL_na);

    try {
        PDF_add_locallink(p, llx, lly, urx, ury, page, optlist);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_add_nameddest) { /* {{{ */
    PDF * p;
    const char * name;
    size_t name_len;
    const char * optlist;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_add_nameddest(p, name, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_add_nameddest. Expected PDFPtr.");
	XSRETURN(1);
    }

    name = SvPV(ST(1), name_len);
    optlist = SvPV(ST(2), PL_na);

    try {
        PDF_add_nameddest(p, name, (int)name_len, optlist);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_add_note) { /* {{{ */
    PDF * p;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * contents;
    size_t len_cont;
    const char * title;
    size_t len_title;
    const char * icon;
    int open;
    dXSARGS;

    if (items != 9) {
	croak("Usage: PDF_add_note(p, llx, lly, urx, ury, contents, title, icon, open);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_add_note. Expected PDFPtr.");
	XSRETURN(1);
    }

    llx = SvNV(ST(1));
    lly = SvNV(ST(2));
    urx = SvNV(ST(3));
    ury = SvNV(ST(4));
    contents = SvPV(ST(5), len_cont);
    title = SvPV(ST(6), len_title);
    icon = SvPV(ST(7), PL_na);
    open = SvIV(ST(8));

    try {
        PDF_add_note2(p, llx, lly, urx, ury, contents, (int)len_cont, title, (int)len_title, icon, open);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_add_pdflink) { /* {{{ */
    PDF * p;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * filename;
    int page;
    const char * optlist;
    dXSARGS;

    if (items != 8) {
	croak("Usage: PDF_add_pdflink(p, llx, lly, urx, ury, filename, page, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_add_pdflink. Expected PDFPtr.");
	XSRETURN(1);
    }

    llx = SvNV(ST(1));
    lly = SvNV(ST(2));
    urx = SvNV(ST(3));
    ury = SvNV(ST(4));
    filename = SvPV(ST(5), PL_na);
    page = SvIV(ST(6));
    optlist = SvPV(ST(7), PL_na);

    try {
        PDF_add_pdflink(p, llx, lly, urx, ury, filename, page, optlist);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_add_table_cell) { /* {{{ */
    PDF * p;
    int table;
    int column;
    int row;
    const char * text;
    size_t text_len;
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 6) {
	croak("Usage: PDF_add_table_cell(p, table, column, row, text, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_add_table_cell. Expected PDFPtr.");
	XSRETURN(1);
    }

    table = SvIV(ST(1));
    column = SvIV(ST(2));
    row = SvIV(ST(3));
    text = SvPV(ST(4), text_len);
    optlist = SvPV(ST(5), PL_na);

    try {
        _result = PDF_add_table_cell(p, table, column, row, text, (int)text_len, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_add_textflow) { /* {{{ */
    PDF * p;
    int textflow;
    const char * text;
    size_t text_len;
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 4) {
	croak("Usage: PDF_add_textflow(p, textflow, text, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_add_textflow. Expected PDFPtr.");
	XSRETURN(1);
    }

    textflow = SvIV(ST(1));
    text = SvPV(ST(2), text_len);
    optlist = SvPV(ST(3), PL_na);

    try {
        _result = PDF_add_textflow(p, textflow, text, (int)text_len, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_add_thumbnail) { /* {{{ */
    PDF * p;
    int image;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_add_thumbnail(p, image);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_add_thumbnail. Expected PDFPtr.");
	XSRETURN(1);
    }

    image = SvIV(ST(1));

    try {
        PDF_add_thumbnail(p, image);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_add_weblink) { /* {{{ */
    PDF * p;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * url;
    dXSARGS;

    if (items != 6) {
	croak("Usage: PDF_add_weblink(p, llx, lly, urx, ury, url);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_add_weblink. Expected PDFPtr.");
	XSRETURN(1);
    }

    llx = SvNV(ST(1));
    lly = SvNV(ST(2));
    urx = SvNV(ST(3));
    ury = SvNV(ST(4));
    url = SvPV(ST(5), PL_na);

    try {
        PDF_add_weblink(p, llx, lly, urx, ury, url);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_arc) { /* {{{ */
    PDF * p;
    double x;
    double y;
    double r;
    double alpha;
    double beta;
    dXSARGS;

    if (items != 6) {
	croak("Usage: PDF_arc(p, x, y, r, alpha, beta);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_arc. Expected PDFPtr.");
	XSRETURN(1);
    }

    x = SvNV(ST(1));
    y = SvNV(ST(2));
    r = SvNV(ST(3));
    alpha = SvNV(ST(4));
    beta = SvNV(ST(5));

    try {
        PDF_arc(p, x, y, r, alpha, beta);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_arcn) { /* {{{ */
    PDF * p;
    double x;
    double y;
    double r;
    double alpha;
    double beta;
    dXSARGS;

    if (items != 6) {
	croak("Usage: PDF_arcn(p, x, y, r, alpha, beta);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_arcn. Expected PDFPtr.");
	XSRETURN(1);
    }

    x = SvNV(ST(1));
    y = SvNV(ST(2));
    r = SvNV(ST(3));
    alpha = SvNV(ST(4));
    beta = SvNV(ST(5));

    try {
        PDF_arcn(p, x, y, r, alpha, beta);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_attach_file) { /* {{{ */
    PDF * p;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * filename;
    size_t filename_len;
    const char * description;
    size_t len_descr;
    const char * author;
    size_t len_auth;
    const char * mimetype;
    const char * icon;
    dXSARGS;

    if (items != 10) {
	croak("Usage: PDF_attach_file(p, llx, lly, urx, ury, filename, description, author, mimetype, icon);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_attach_file. Expected PDFPtr.");
	XSRETURN(1);
    }

    llx = SvNV(ST(1));
    lly = SvNV(ST(2));
    urx = SvNV(ST(3));
    ury = SvNV(ST(4));
    filename = SvPV(ST(5), filename_len);
    description = SvPV(ST(6), len_descr);
    author = SvPV(ST(7), len_auth);
    mimetype = SvPV(ST(8), PL_na);
    icon = SvPV(ST(9), PL_na);

    try {
        PDF_attach_file2(p, llx, lly, urx, ury, filename, 0, description, (int)len_descr, author, (int)len_auth, mimetype, icon);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_begin_document) { /* {{{ */
    PDF * p;
    const char * filename;
    size_t filename_len;
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_begin_document(p, filename, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_begin_document. Expected PDFPtr.");
	XSRETURN(1);
    }

    filename = SvPV(ST(1), filename_len);
    optlist = SvPV(ST(2), PL_na);

    try {
        _result = PDF_begin_document(p, filename, 0, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_begin_font) { /* {{{ */
    PDF * p;
    const char * fontname;
    size_t fontname_len;
    double a;
    double b;
    double c;
    double d;
    double e;
    double f;
    const char * optlist;
    dXSARGS;

    if (items != 9) {
	croak("Usage: PDF_begin_font(p, fontname, a, b, c, d, e, f, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_begin_font. Expected PDFPtr.");
	XSRETURN(1);
    }

    fontname = SvPV(ST(1), fontname_len);
    a = SvNV(ST(2));
    b = SvNV(ST(3));
    c = SvNV(ST(4));
    d = SvNV(ST(5));
    e = SvNV(ST(6));
    f = SvNV(ST(7));
    optlist = SvPV(ST(8), PL_na);

    try {
        PDF_begin_font(p, fontname, 0, a, b, c, d, e, f, optlist);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_begin_glyph) { /* {{{ */
    PDF * p;
    const char * glyphname;
    double wx;
    double llx;
    double lly;
    double urx;
    double ury;
    dXSARGS;

    if (items != 7) {
	croak("Usage: PDF_begin_glyph(p, glyphname, wx, llx, lly, urx, ury);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_begin_glyph. Expected PDFPtr.");
	XSRETURN(1);
    }

    glyphname = SvPV(ST(1), PL_na);
    wx = SvNV(ST(2));
    llx = SvNV(ST(3));
    lly = SvNV(ST(4));
    urx = SvNV(ST(5));
    ury = SvNV(ST(6));

    try {
        PDF_begin_glyph(p, glyphname, wx, llx, lly, urx, ury);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_begin_item) { /* {{{ */
    PDF * p;
    const char * tag;
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_begin_item(p, tag, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_begin_item. Expected PDFPtr.");
	XSRETURN(1);
    }

    tag = SvPV(ST(1), PL_na);
    optlist = SvPV(ST(2), PL_na);

    try {
        _result = PDF_begin_item(p, tag, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_begin_layer) { /* {{{ */
    PDF * p;
    int layer;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_begin_layer(p, layer);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_begin_layer. Expected PDFPtr.");
	XSRETURN(1);
    }

    layer = SvIV(ST(1));

    try {
        PDF_begin_layer(p, layer);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_begin_page) { /* {{{ */
    PDF * p;
    double width;
    double height;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_begin_page(p, width, height);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_begin_page. Expected PDFPtr.");
	XSRETURN(1);
    }

    width = SvNV(ST(1));
    height = SvNV(ST(2));

    try {
        PDF_begin_page(p, width, height);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_begin_page_ext) { /* {{{ */
    PDF * p;
    double width;
    double height;
    const char * optlist;
    dXSARGS;

    if (items != 4) {
	croak("Usage: PDF_begin_page_ext(p, width, height, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_begin_page_ext. Expected PDFPtr.");
	XSRETURN(1);
    }

    width = SvNV(ST(1));
    height = SvNV(ST(2));
    optlist = SvPV(ST(3), PL_na);

    try {
        PDF_begin_page_ext(p, width, height, optlist);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_begin_pattern) { /* {{{ */
    PDF * p;
    double width;
    double height;
    double xstep;
    double ystep;
    int painttype;
    int _result = -1;
    dXSARGS;

    if (items != 6) {
	croak("Usage: PDF_begin_pattern(p, width, height, xstep, ystep, painttype);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_begin_pattern. Expected PDFPtr.");
	XSRETURN(1);
    }

    width = SvNV(ST(1));
    height = SvNV(ST(2));
    xstep = SvNV(ST(3));
    ystep = SvNV(ST(4));
    painttype = SvIV(ST(5));

    try {
        _result = PDF_begin_pattern(p, width, height, xstep, ystep, painttype);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_begin_template) { /* {{{ */
    PDF * p;
    double width;
    double height;
    int _result = -1;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_begin_template(p, width, height);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_begin_template. Expected PDFPtr.");
	XSRETURN(1);
    }

    width = SvNV(ST(1));
    height = SvNV(ST(2));

    try {
        _result = PDF_begin_template(p, width, height);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_begin_template_ext) { /* {{{ */
    PDF * p;
    double width;
    double height;
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 4) {
	croak("Usage: PDF_begin_template_ext(p, width, height, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_begin_template_ext. Expected PDFPtr.");
	XSRETURN(1);
    }

    width = SvNV(ST(1));
    height = SvNV(ST(2));
    optlist = SvPV(ST(3), PL_na);

    try {
        _result = PDF_begin_template_ext(p, width, height, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_circle) { /* {{{ */
    PDF * p;
    double x;
    double y;
    double r;
    dXSARGS;

    if (items != 4) {
	croak("Usage: PDF_circle(p, x, y, r);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_circle. Expected PDFPtr.");
	XSRETURN(1);
    }

    x = SvNV(ST(1));
    y = SvNV(ST(2));
    r = SvNV(ST(3));

    try {
        PDF_circle(p, x, y, r);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_clip) { /* {{{ */
    PDF * p;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_clip(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_clip. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        PDF_clip(p);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_close) { /* {{{ */
    PDF * p;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_close(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_close. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        PDF_close(p);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_close_image) { /* {{{ */
    PDF * p;
    int image;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_close_image(p, image);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_close_image. Expected PDFPtr.");
	XSRETURN(1);
    }

    image = SvIV(ST(1));

    try {
        PDF_close_image(p, image);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_close_pdi) { /* {{{ */
    PDF * p;
    int doc;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_close_pdi(p, doc);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_close_pdi. Expected PDFPtr.");
	XSRETURN(1);
    }

    doc = SvIV(ST(1));

    try {
        PDF_close_pdi(p, doc);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_close_pdi_document) { /* {{{ */
    PDF * p;
    int doc;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_close_pdi_document(p, doc);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_close_pdi_document. Expected PDFPtr.");
	XSRETURN(1);
    }

    doc = SvIV(ST(1));

    try {
        PDF_close_pdi_document(p, doc);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_close_pdi_page) { /* {{{ */
    PDF * p;
    int page;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_close_pdi_page(p, page);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_close_pdi_page. Expected PDFPtr.");
	XSRETURN(1);
    }

    page = SvIV(ST(1));

    try {
        PDF_close_pdi_page(p, page);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_closepath) { /* {{{ */
    PDF * p;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_closepath(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_closepath. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        PDF_closepath(p);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_closepath_fill_stroke) { /* {{{ */
    PDF * p;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_closepath_fill_stroke(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_closepath_fill_stroke. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        PDF_closepath_fill_stroke(p);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_closepath_stroke) { /* {{{ */
    PDF * p;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_closepath_stroke(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_closepath_stroke. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        PDF_closepath_stroke(p);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_concat) { /* {{{ */
    PDF * p;
    double a;
    double b;
    double c;
    double d;
    double e;
    double f;
    dXSARGS;

    if (items != 7) {
	croak("Usage: PDF_concat(p, a, b, c, d, e, f);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_concat. Expected PDFPtr.");
	XSRETURN(1);
    }

    a = SvNV(ST(1));
    b = SvNV(ST(2));
    c = SvNV(ST(3));
    d = SvNV(ST(4));
    e = SvNV(ST(5));
    f = SvNV(ST(6));

    try {
        PDF_concat(p, a, b, c, d, e, f);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_continue_text) { /* {{{ */
    PDF * p;
    const char * text;
    size_t text_len;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_continue_text(p, text);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_continue_text. Expected PDFPtr.");
	XSRETURN(1);
    }

    text = SvPV(ST(1), text_len);

    try {
        PDF_continue_text2(p, text, (int)text_len);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_create_action) { /* {{{ */
    PDF * p;
    const char * type;
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_create_action(p, type, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_create_action. Expected PDFPtr.");
	XSRETURN(1);
    }

    type = SvPV(ST(1), PL_na);
    optlist = SvPV(ST(2), PL_na);

    try {
        _result = PDF_create_action(p, type, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_create_annotation) { /* {{{ */
    PDF * p;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * type;
    const char * optlist;
    dXSARGS;

    if (items != 7) {
	croak("Usage: PDF_create_annotation(p, llx, lly, urx, ury, type, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_create_annotation. Expected PDFPtr.");
	XSRETURN(1);
    }

    llx = SvNV(ST(1));
    lly = SvNV(ST(2));
    urx = SvNV(ST(3));
    ury = SvNV(ST(4));
    type = SvPV(ST(5), PL_na);
    optlist = SvPV(ST(6), PL_na);

    try {
        PDF_create_annotation(p, llx, lly, urx, ury, type, optlist);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_create_bookmark) { /* {{{ */
    PDF * p;
    const char * text;
    size_t text_len;
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_create_bookmark(p, text, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_create_bookmark. Expected PDFPtr.");
	XSRETURN(1);
    }

    text = SvPV(ST(1), text_len);
    optlist = SvPV(ST(2), PL_na);

    try {
        _result = PDF_create_bookmark(p, text, (int)text_len, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_create_field) { /* {{{ */
    PDF * p;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * name;
    size_t name_len;
    const char * type;
    const char * optlist;
    dXSARGS;

    if (items != 8) {
	croak("Usage: PDF_create_field(p, llx, lly, urx, ury, name, type, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_create_field. Expected PDFPtr.");
	XSRETURN(1);
    }

    llx = SvNV(ST(1));
    lly = SvNV(ST(2));
    urx = SvNV(ST(3));
    ury = SvNV(ST(4));
    name = SvPV(ST(5), name_len);
    type = SvPV(ST(6), PL_na);
    optlist = SvPV(ST(7), PL_na);

    try {
        PDF_create_field(p, llx, lly, urx, ury, name, (int)name_len, type, optlist);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_create_fieldgroup) { /* {{{ */
    PDF * p;
    const char * name;
    size_t name_len;
    const char * optlist;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_create_fieldgroup(p, name, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_create_fieldgroup. Expected PDFPtr.");
	XSRETURN(1);
    }

    name = SvPV(ST(1), name_len);
    optlist = SvPV(ST(2), PL_na);

    try {
        PDF_create_fieldgroup(p, name, (int)name_len, optlist);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_create_gstate) { /* {{{ */
    PDF * p;
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_create_gstate(p, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_create_gstate. Expected PDFPtr.");
	XSRETURN(1);
    }

    optlist = SvPV(ST(1), PL_na);

    try {
        _result = PDF_create_gstate(p, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_create_pvf) { /* {{{ */
    PDF * p;
    const char * filename;
    size_t filename_len;
    const void * data;
    size_t size;
    const char * optlist;
    dXSARGS;

    if (items != 4) {
	croak("Usage: PDF_create_pvf(p, filename, data, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_create_pvf. Expected PDFPtr.");
	XSRETURN(1);
    }

    filename = SvPV(ST(1), filename_len);
    data = SvPV(ST(2), size);
    optlist = SvPV(ST(3), PL_na);

    try {
        PDF_create_pvf(p, filename, 0, data, (size_t)size, optlist);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_create_textflow) { /* {{{ */
    PDF * p;
    const char * text;
    size_t text_len;
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_create_textflow(p, text, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_create_textflow. Expected PDFPtr.");
	XSRETURN(1);
    }

    text = SvPV(ST(1), text_len);
    optlist = SvPV(ST(2), PL_na);

    try {
        _result = PDF_create_textflow(p, text, (int)text_len, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_curveto) { /* {{{ */
    PDF * p;
    double x_1;
    double y_1;
    double x_2;
    double y_2;
    double x_3;
    double y_3;
    dXSARGS;

    if (items != 7) {
	croak("Usage: PDF_curveto(p, x_1, y_1, x_2, y_2, x_3, y_3);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_curveto. Expected PDFPtr.");
	XSRETURN(1);
    }

    x_1 = SvNV(ST(1));
    y_1 = SvNV(ST(2));
    x_2 = SvNV(ST(3));
    y_2 = SvNV(ST(4));
    x_3 = SvNV(ST(5));
    y_3 = SvNV(ST(6));

    try {
        PDF_curveto(p, x_1, y_1, x_2, y_2, x_3, y_3);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_define_layer) { /* {{{ */
    PDF * p;
    const char * name;
    size_t name_len;
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_define_layer(p, name, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_define_layer. Expected PDFPtr.");
	XSRETURN(1);
    }

    name = SvPV(ST(1), name_len);
    optlist = SvPV(ST(2), PL_na);

    try {
        _result = PDF_define_layer(p, name, (int)name_len, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_delete_pvf) { /* {{{ */
    PDF * p;
    const char * filename;
    size_t filename_len;
    int _result = -1;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_delete_pvf(p, filename);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_delete_pvf. Expected PDFPtr.");
	XSRETURN(1);
    }

    filename = SvPV(ST(1), filename_len);

    try {
        _result = PDF_delete_pvf(p, filename, 0);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_delete_table) { /* {{{ */
    PDF * p;
    int table;
    const char * optlist;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_delete_table(p, table, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_delete_table. Expected PDFPtr.");
	XSRETURN(1);
    }

    table = SvIV(ST(1));
    optlist = SvPV(ST(2), PL_na);

    try {
        PDF_delete_table(p, table, optlist);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_delete_textflow) { /* {{{ */
    PDF * p;
    int textflow;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_delete_textflow(p, textflow);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_delete_textflow. Expected PDFPtr.");
	XSRETURN(1);
    }

    textflow = SvIV(ST(1));

    try {
        PDF_delete_textflow(p, textflow);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_encoding_set_char) { /* {{{ */
    PDF * p;
    const char * encoding;
    int slot;
    const char * glyphname;
    int uv;
    dXSARGS;

    if (items != 5) {
	croak("Usage: PDF_encoding_set_char(p, encoding, slot, glyphname, uv);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_encoding_set_char. Expected PDFPtr.");
	XSRETURN(1);
    }

    encoding = SvPV(ST(1), PL_na);
    slot = SvIV(ST(2));
    glyphname = SvPV(ST(3), PL_na);
    uv = SvIV(ST(4));

    try {
        PDF_encoding_set_char(p, encoding, slot, glyphname, uv);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_end_document) { /* {{{ */
    PDF * p;
    const char * optlist;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_end_document(p, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_end_document. Expected PDFPtr.");
	XSRETURN(1);
    }

    optlist = SvPV(ST(1), PL_na);

    try {
        PDF_end_document(p, optlist);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_end_font) { /* {{{ */
    PDF * p;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_end_font(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_end_font. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        PDF_end_font(p);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_end_glyph) { /* {{{ */
    PDF * p;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_end_glyph(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_end_glyph. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        PDF_end_glyph(p);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_end_item) { /* {{{ */
    PDF * p;
    int id;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_end_item(p, id);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_end_item. Expected PDFPtr.");
	XSRETURN(1);
    }

    id = SvIV(ST(1));

    try {
        PDF_end_item(p, id);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_end_layer) { /* {{{ */
    PDF * p;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_end_layer(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_end_layer. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        PDF_end_layer(p);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_end_mc) { /* {{{ */
    PDF * p;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_end_mc(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_end_mc. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        PDF_end_mc(p);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_end_page) { /* {{{ */
    PDF * p;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_end_page(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_end_page. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        PDF_end_page(p);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_end_page_ext) { /* {{{ */
    PDF * p;
    const char * optlist;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_end_page_ext(p, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_end_page_ext. Expected PDFPtr.");
	XSRETURN(1);
    }

    optlist = SvPV(ST(1), PL_na);

    try {
        PDF_end_page_ext(p, optlist);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_end_pattern) { /* {{{ */
    PDF * p;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_end_pattern(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_end_pattern. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        PDF_end_pattern(p);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_end_template) { /* {{{ */
    PDF * p;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_end_template(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_end_template. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        PDF_end_template(p);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_endpath) { /* {{{ */
    PDF * p;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_endpath(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_endpath. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        PDF_endpath(p);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_fill) { /* {{{ */
    PDF * p;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_fill(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_fill. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        PDF_fill(p);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_fill_imageblock) { /* {{{ */
    PDF * p;
    int page;
    const char * blockname;
    int image;
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 5) {
	croak("Usage: PDF_fill_imageblock(p, page, blockname, image, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_fill_imageblock. Expected PDFPtr.");
	XSRETURN(1);
    }

    page = SvIV(ST(1));
    blockname = SvPV(ST(2), PL_na);
    image = SvIV(ST(3));
    optlist = SvPV(ST(4), PL_na);

    try {
        _result = PDF_fill_imageblock(p, page, blockname, image, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_fill_pdfblock) { /* {{{ */
    PDF * p;
    int page;
    const char * blockname;
    int contents;
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 5) {
	croak("Usage: PDF_fill_pdfblock(p, page, blockname, contents, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_fill_pdfblock. Expected PDFPtr.");
	XSRETURN(1);
    }

    page = SvIV(ST(1));
    blockname = SvPV(ST(2), PL_na);
    contents = SvIV(ST(3));
    optlist = SvPV(ST(4), PL_na);

    try {
        _result = PDF_fill_pdfblock(p, page, blockname, contents, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_fill_stroke) { /* {{{ */
    PDF * p;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_fill_stroke(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_fill_stroke. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        PDF_fill_stroke(p);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_fill_textblock) { /* {{{ */
    PDF * p;
    int page;
    const char * blockname;
    const char * text;
    size_t text_len;
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 5) {
	croak("Usage: PDF_fill_textblock(p, page, blockname, text, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_fill_textblock. Expected PDFPtr.");
	XSRETURN(1);
    }

    page = SvIV(ST(1));
    blockname = SvPV(ST(2), PL_na);
    text = SvPV(ST(3), text_len);
    optlist = SvPV(ST(4), PL_na);

    try {
        _result = PDF_fill_textblock(p, page, blockname, text, (int)text_len, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_findfont) { /* {{{ */
    PDF * p;
    const char * fontname;
    const char * encoding;
    int embed;
    int _result = -1;
    dXSARGS;

    if (items != 4) {
	croak("Usage: PDF_findfont(p, fontname, encoding, embed);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_findfont. Expected PDFPtr.");
	XSRETURN(1);
    }

    fontname = SvPV(ST(1), PL_na);
    encoding = SvPV(ST(2), PL_na);
    embed = SvIV(ST(3));

    try {
        _result = PDF_findfont(p, fontname, encoding, embed);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_fit_image) { /* {{{ */
    PDF * p;
    int image;
    double x;
    double y;
    const char * optlist;
    dXSARGS;

    if (items != 5) {
	croak("Usage: PDF_fit_image(p, image, x, y, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_fit_image. Expected PDFPtr.");
	XSRETURN(1);
    }

    image = SvIV(ST(1));
    x = SvNV(ST(2));
    y = SvNV(ST(3));
    optlist = SvPV(ST(4), PL_na);

    try {
        PDF_fit_image(p, image, x, y, optlist);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_fit_pdi_page) { /* {{{ */
    PDF * p;
    int page;
    double x;
    double y;
    const char * optlist;
    dXSARGS;

    if (items != 5) {
	croak("Usage: PDF_fit_pdi_page(p, page, x, y, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_fit_pdi_page. Expected PDFPtr.");
	XSRETURN(1);
    }

    page = SvIV(ST(1));
    x = SvNV(ST(2));
    y = SvNV(ST(3));
    optlist = SvPV(ST(4), PL_na);

    try {
        PDF_fit_pdi_page(p, page, x, y, optlist);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_fit_table) { /* {{{ */
    PDF * p;
    int table;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * optlist;
    const char *_result = NULL;
    dXSARGS;

    if (items != 7) {
	croak("Usage: PDF_fit_table(p, table, llx, lly, urx, ury, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_fit_table. Expected PDFPtr.");
	XSRETURN(1);
    }

    table = SvIV(ST(1));
    llx = SvNV(ST(2));
    lly = SvNV(ST(3));
    urx = SvNV(ST(4));
    ury = SvNV(ST(5));
    optlist = SvPV(ST(6), PL_na);

    try {
        _result = PDF_fit_table(p, table, llx, lly, urx, ury, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setpv((SV*)ST(0), _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_fit_textflow) { /* {{{ */
    PDF * p;
    int textflow;
    double llx;
    double lly;
    double urx;
    double ury;
    const char * optlist;
    const char *_result = NULL;
    dXSARGS;

    if (items != 7) {
	croak("Usage: PDF_fit_textflow(p, textflow, llx, lly, urx, ury, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_fit_textflow. Expected PDFPtr.");
	XSRETURN(1);
    }

    textflow = SvIV(ST(1));
    llx = SvNV(ST(2));
    lly = SvNV(ST(3));
    urx = SvNV(ST(4));
    ury = SvNV(ST(5));
    optlist = SvPV(ST(6), PL_na);

    try {
        _result = PDF_fit_textflow(p, textflow, llx, lly, urx, ury, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setpv((SV*)ST(0), _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_fit_textline) { /* {{{ */
    PDF * p;
    const char * text;
    size_t text_len;
    double x;
    double y;
    const char * optlist;
    dXSARGS;

    if (items != 5) {
	croak("Usage: PDF_fit_textline(p, text, x, y, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_fit_textline. Expected PDFPtr.");
	XSRETURN(1);
    }

    text = SvPV(ST(1), text_len);
    x = SvNV(ST(2));
    y = SvNV(ST(3));
    optlist = SvPV(ST(4), PL_na);

    try {
        PDF_fit_textline(p, text, (int)text_len, x, y, optlist);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_get_apiname) { /* {{{ */
    PDF * p;
    const char *_result = NULL;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_get_apiname(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_get_apiname. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        _result = PDF_get_apiname(p);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setpv((SV*)ST(0), _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_get_buffer) { /* {{{ */
    PDF * p;
    long size;
    const char *_result = NULL;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_get_buffer(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_get_buffer. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        _result =  (const char *)PDF_get_buffer(p, &size);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setpvn((SV*)ST(0), (char *) _result, size);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_get_errmsg) { /* {{{ */
    PDF * p;
    const char *_result = NULL;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_get_errmsg(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_get_errmsg. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        _result = PDF_get_errmsg(p);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setpv((SV*)ST(0), _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_get_errnum) { /* {{{ */
    PDF * p;
    int _result = -1;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_get_errnum(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_get_errnum. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        _result = PDF_get_errnum(p);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_get_parameter) { /* {{{ */
    PDF * p;
    const char * key;
    double modifier;
    const char *_result = NULL;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_get_parameter(p, key, modifier);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_get_parameter. Expected PDFPtr.");
	XSRETURN(1);
    }

    key = SvPV(ST(1), PL_na);
    modifier = SvNV(ST(2));

    try {
        _result = PDF_get_parameter(p, key, modifier);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setpv((SV*)ST(0), _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_get_pdi_parameter) { /* {{{ */
    PDF * p;
    const char * key;
    int doc;
    int page;
    int reserved;
    int len;
    const char *_result = NULL;
    dXSARGS;

    if (items != 5) {
	croak("Usage: PDF_get_pdi_parameter(p, key, doc, page, reserved);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_get_pdi_parameter. Expected PDFPtr.");
	XSRETURN(1);
    }

    key = SvPV(ST(1), PL_na);
    doc = SvIV(ST(2));
    page = SvIV(ST(3));
    reserved = SvIV(ST(4));

    try {
        _result =  (const char *)PDF_get_pdi_parameter(p, key, doc, page, reserved, &len);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setpvn((SV*)ST(0), (char *) _result, len);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_get_pdi_value) { /* {{{ */
    PDF * p;
    const char * key;
    int doc;
    int page;
    int reserved;
    double _result = -1;
    dXSARGS;

    if (items != 5) {
	croak("Usage: PDF_get_pdi_value(p, key, doc, page, reserved);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_get_pdi_value. Expected PDFPtr.");
	XSRETURN(1);
    }

    key = SvPV(ST(1), PL_na);
    doc = SvIV(ST(2));
    page = SvIV(ST(3));
    reserved = SvIV(ST(4));

    try {
        _result = PDF_get_pdi_value(p, key, doc, page, reserved);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setnv(ST(0), _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_get_value) { /* {{{ */
    PDF * p;
    const char * key;
    double modifier;
    double _result = -1;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_get_value(p, key, modifier);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_get_value. Expected PDFPtr.");
	XSRETURN(1);
    }

    key = SvPV(ST(1), PL_na);
    modifier = SvNV(ST(2));

    try {
        _result = PDF_get_value(p, key, modifier);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setnv(ST(0), _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_info_font) { /* {{{ */
    PDF * p;
    int font;
    const char * keyword;
    const char * optlist;
    double _result = -1;
    dXSARGS;

    if (items != 4) {
	croak("Usage: PDF_info_font(p, font, keyword, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_info_font. Expected PDFPtr.");
	XSRETURN(1);
    }

    font = SvIV(ST(1));
    keyword = SvPV(ST(2), PL_na);
    optlist = SvPV(ST(3), PL_na);

    try {
        _result = PDF_info_font(p, font, keyword, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setnv(ST(0), _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_info_matchbox) { /* {{{ */
    PDF * p;
    const char * boxname;
    size_t boxname_len;
    int num;
    const char * keyword;
    double _result = -1;
    dXSARGS;

    if (items != 4) {
	croak("Usage: PDF_info_matchbox(p, boxname, num, keyword);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_info_matchbox. Expected PDFPtr.");
	XSRETURN(1);
    }

    boxname = SvPV(ST(1), boxname_len);
    num = SvIV(ST(2));
    keyword = SvPV(ST(3), PL_na);

    try {
        _result = PDF_info_matchbox(p, boxname, 0, num, keyword);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setnv(ST(0), _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_info_table) { /* {{{ */
    PDF * p;
    int table;
    const char * keyword;
    double _result = -1;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_info_table(p, table, keyword);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_info_table. Expected PDFPtr.");
	XSRETURN(1);
    }

    table = SvIV(ST(1));
    keyword = SvPV(ST(2), PL_na);

    try {
        _result = PDF_info_table(p, table, keyword);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setnv(ST(0), _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_info_textflow) { /* {{{ */
    PDF * p;
    int textflow;
    const char * keyword;
    double _result = -1;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_info_textflow(p, textflow, keyword);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_info_textflow. Expected PDFPtr.");
	XSRETURN(1);
    }

    textflow = SvIV(ST(1));
    keyword = SvPV(ST(2), PL_na);

    try {
        _result = PDF_info_textflow(p, textflow, keyword);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setnv(ST(0), _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_info_textline) { /* {{{ */
    PDF * p;
    const char * text;
    size_t text_len;
    const char * keyword;
    const char * optlist;
    double _result = -1;
    dXSARGS;

    if (items != 4) {
	croak("Usage: PDF_info_textline(p, text, keyword, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_info_textline. Expected PDFPtr.");
	XSRETURN(1);
    }

    text = SvPV(ST(1), text_len);
    keyword = SvPV(ST(2), PL_na);
    optlist = SvPV(ST(3), PL_na);

    try {
        _result = PDF_info_textline(p, text, (int)text_len, keyword, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setnv(ST(0), _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_initgraphics) { /* {{{ */
    PDF * p;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_initgraphics(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_initgraphics. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        PDF_initgraphics(p);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_lineto) { /* {{{ */
    PDF * p;
    double x;
    double y;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_lineto(p, x, y);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_lineto. Expected PDFPtr.");
	XSRETURN(1);
    }

    x = SvNV(ST(1));
    y = SvNV(ST(2));

    try {
        PDF_lineto(p, x, y);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_load_font) { /* {{{ */
    PDF * p;
    const char * fontname;
    size_t fontname_len;
    const char * encoding;
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 4) {
	croak("Usage: PDF_load_font(p, fontname, encoding, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_load_font. Expected PDFPtr.");
	XSRETURN(1);
    }

    fontname = SvPV(ST(1), fontname_len);
    encoding = SvPV(ST(2), PL_na);
    optlist = SvPV(ST(3), PL_na);

    try {
        _result = PDF_load_font(p, fontname, 0, encoding, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_load_iccprofile) { /* {{{ */
    PDF * p;
    const char * profilename;
    size_t profilename_len;
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_load_iccprofile(p, profilename, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_load_iccprofile. Expected PDFPtr.");
	XSRETURN(1);
    }

    profilename = SvPV(ST(1), profilename_len);
    optlist = SvPV(ST(2), PL_na);

    try {
        _result = PDF_load_iccprofile(p, profilename, 0, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_load_image) { /* {{{ */
    PDF * p;
    const char * imagetype;
    const char * filename;
    size_t filename_len;
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 4) {
	croak("Usage: PDF_load_image(p, imagetype, filename, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_load_image. Expected PDFPtr.");
	XSRETURN(1);
    }

    imagetype = SvPV(ST(1), PL_na);
    filename = SvPV(ST(2), filename_len);
    optlist = SvPV(ST(3), PL_na);

    try {
        _result = PDF_load_image(p, imagetype, filename, 0, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_makespotcolor) { /* {{{ */
    PDF * p;
    const char * spotname;
    size_t reserved;
    int _result = -1;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_makespotcolor(p, spotname);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_makespotcolor. Expected PDFPtr.");
	XSRETURN(1);
    }

    spotname = SvPV(ST(1), reserved);

    try {
        _result = PDF_makespotcolor(p, spotname, 0);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_moveto) { /* {{{ */
    PDF * p;
    double x;
    double y;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_moveto(p, x, y);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_moveto. Expected PDFPtr.");
	XSRETURN(1);
    }

    x = SvNV(ST(1));
    y = SvNV(ST(2));

    try {
        PDF_moveto(p, x, y);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_open_CCITT) { /* {{{ */
    PDF * p;
    const char * filename;
    int width;
    int height;
    int BitReverse;
    int K;
    int BlackIs1;
    int _result = -1;
    dXSARGS;

    if (items != 7) {
	croak("Usage: PDF_open_CCITT(p, filename, width, height, BitReverse, K, BlackIs1);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_open_CCITT. Expected PDFPtr.");
	XSRETURN(1);
    }

    filename = SvPV(ST(1), PL_na);
    width = SvIV(ST(2));
    height = SvIV(ST(3));
    BitReverse = SvIV(ST(4));
    K = SvIV(ST(5));
    BlackIs1 = SvIV(ST(6));

    try {
        _result = PDF_open_CCITT(p, filename, width, height, BitReverse, K, BlackIs1);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_open_file) { /* {{{ */
    PDF * p;
    const char * filename;
    int _result = -1;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_open_file(p, filename);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_open_file. Expected PDFPtr.");
	XSRETURN(1);
    }

    filename = SvPV(ST(1), PL_na);

    try {
        _result = PDF_open_file(p, filename);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_open_image_file) { /* {{{ */
    PDF * p;
    const char * imagetype;
    const char * filename;
    const char * stringparam;
    int intparam;
    int _result = -1;
    dXSARGS;

    if (items != 5) {
	croak("Usage: PDF_open_image_file(p, imagetype, filename, stringparam, intparam);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_open_image_file. Expected PDFPtr.");
	XSRETURN(1);
    }

    imagetype = SvPV(ST(1), PL_na);
    filename = SvPV(ST(2), PL_na);
    stringparam = SvPV(ST(3), PL_na);
    intparam = SvIV(ST(4));

    try {
        _result = PDF_open_image_file(p, imagetype, filename, stringparam, intparam);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_open_pdi_document) { /* {{{ */
    PDF * p;
    const char * filename;
    size_t filename_len;
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_open_pdi_document(p, filename, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_open_pdi_document. Expected PDFPtr.");
	XSRETURN(1);
    }

    filename = SvPV(ST(1), filename_len);
    optlist = SvPV(ST(2), PL_na);

    try {
        _result = PDF_open_pdi_document(p, filename, 0, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_open_pdi_page) { /* {{{ */
    PDF * p;
    int doc;
    int pagenumber;
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 4) {
	croak("Usage: PDF_open_pdi_page(p, doc, pagenumber, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_open_pdi_page. Expected PDFPtr.");
	XSRETURN(1);
    }

    doc = SvIV(ST(1));
    pagenumber = SvIV(ST(2));
    optlist = SvPV(ST(3), PL_na);

    try {
        _result = PDF_open_pdi_page(p, doc, pagenumber, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_pcos_get_number) { /* {{{ */
    PDF * p;
    int doc;
    const char * path;
    double _result = -1;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_pcos_get_number(p, doc, path);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_pcos_get_number. Expected PDFPtr.");
	XSRETURN(1);
    }

    doc = SvIV(ST(1));
    path = SvPV(ST(2), PL_na);

    try {
        _result = PDF_pcos_get_number(p, doc, "%s", path);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setnv(ST(0), _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_pcos_get_string) { /* {{{ */
    PDF * p;
    int doc;
    const char * path;
    const char *_result = NULL;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_pcos_get_string(p, doc, path);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_pcos_get_string. Expected PDFPtr.");
	XSRETURN(1);
    }

    doc = SvIV(ST(1));
    path = SvPV(ST(2), PL_na);

    try {
        _result = PDF_pcos_get_string(p, doc, "%s", path);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setpv((SV*)ST(0), _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_pcos_get_stream) { /* {{{ */
    PDF * p;
    int doc;
    int length;
    const char * optlist;
    const char * path;
    const char *_result = NULL;
    dXSARGS;

    if (items != 4) {
	croak("Usage: PDF_pcos_get_stream(p, doc, optlist, path);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_pcos_get_stream. Expected PDFPtr.");
	XSRETURN(1);
    }

    doc = SvIV(ST(1));
    optlist = SvPV(ST(2), PL_na);
    path = SvPV(ST(3), PL_na);

    try {
        _result =  (const char *)PDF_pcos_get_stream(p, doc, &length, optlist, "%s", path);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setpvn((SV*)ST(0), (char *) _result, length);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_place_image) { /* {{{ */
    PDF * p;
    int image;
    double x;
    double y;
    double scale;
    dXSARGS;

    if (items != 5) {
	croak("Usage: PDF_place_image(p, image, x, y, scale);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_place_image. Expected PDFPtr.");
	XSRETURN(1);
    }

    image = SvIV(ST(1));
    x = SvNV(ST(2));
    y = SvNV(ST(3));
    scale = SvNV(ST(4));

    try {
        PDF_place_image(p, image, x, y, scale);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_place_pdi_page) { /* {{{ */
    PDF * p;
    int page;
    double x;
    double y;
    double sx;
    double sy;
    dXSARGS;

    if (items != 6) {
	croak("Usage: PDF_place_pdi_page(p, page, x, y, sx, sy);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_place_pdi_page. Expected PDFPtr.");
	XSRETURN(1);
    }

    page = SvIV(ST(1));
    x = SvNV(ST(2));
    y = SvNV(ST(3));
    sx = SvNV(ST(4));
    sy = SvNV(ST(5));

    try {
        PDF_place_pdi_page(p, page, x, y, sx, sy);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_process_pdi) { /* {{{ */
    PDF * p;
    int doc;
    int page;
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 4) {
	croak("Usage: PDF_process_pdi(p, doc, page, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_process_pdi. Expected PDFPtr.");
	XSRETURN(1);
    }

    doc = SvIV(ST(1));
    page = SvIV(ST(2));
    optlist = SvPV(ST(3), PL_na);

    try {
        _result = PDF_process_pdi(p, doc, page, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_rect) { /* {{{ */
    PDF * p;
    double x;
    double y;
    double width;
    double height;
    dXSARGS;

    if (items != 5) {
	croak("Usage: PDF_rect(p, x, y, width, height);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_rect. Expected PDFPtr.");
	XSRETURN(1);
    }

    x = SvNV(ST(1));
    y = SvNV(ST(2));
    width = SvNV(ST(3));
    height = SvNV(ST(4));

    try {
        PDF_rect(p, x, y, width, height);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_restore) { /* {{{ */
    PDF * p;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_restore(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_restore. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        PDF_restore(p);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_resume_page) { /* {{{ */
    PDF * p;
    const char * optlist;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_resume_page(p, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_resume_page. Expected PDFPtr.");
	XSRETURN(1);
    }

    optlist = SvPV(ST(1), PL_na);

    try {
        PDF_resume_page(p, optlist);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_rotate) { /* {{{ */
    PDF * p;
    double phi;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_rotate(p, phi);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_rotate. Expected PDFPtr.");
	XSRETURN(1);
    }

    phi = SvNV(ST(1));

    try {
        PDF_rotate(p, phi);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_save) { /* {{{ */
    PDF * p;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_save(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_save. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        PDF_save(p);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_scale) { /* {{{ */
    PDF * p;
    double sx;
    double sy;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_scale(p, sx, sy);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_scale. Expected PDFPtr.");
	XSRETURN(1);
    }

    sx = SvNV(ST(1));
    sy = SvNV(ST(2));

    try {
        PDF_scale(p, sx, sy);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_set_border_color) { /* {{{ */
    PDF * p;
    double red;
    double green;
    double blue;
    dXSARGS;

    if (items != 4) {
	croak("Usage: PDF_set_border_color(p, red, green, blue);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_set_border_color. Expected PDFPtr.");
	XSRETURN(1);
    }

    red = SvNV(ST(1));
    green = SvNV(ST(2));
    blue = SvNV(ST(3));

    try {
        PDF_set_border_color(p, red, green, blue);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_set_border_dash) { /* {{{ */
    PDF * p;
    double b;
    double w;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_set_border_dash(p, b, w);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_set_border_dash. Expected PDFPtr.");
	XSRETURN(1);
    }

    b = SvNV(ST(1));
    w = SvNV(ST(2));

    try {
        PDF_set_border_dash(p, b, w);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_set_border_style) { /* {{{ */
    PDF * p;
    const char * style;
    double width;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_set_border_style(p, style, width);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_set_border_style. Expected PDFPtr.");
	XSRETURN(1);
    }

    style = SvPV(ST(1), PL_na);
    width = SvNV(ST(2));

    try {
        PDF_set_border_style(p, style, width);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_set_gstate) { /* {{{ */
    PDF * p;
    int gstate;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_set_gstate(p, gstate);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_set_gstate. Expected PDFPtr.");
	XSRETURN(1);
    }

    gstate = SvIV(ST(1));

    try {
        PDF_set_gstate(p, gstate);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_set_info) { /* {{{ */
    PDF * p;
    const char * key;
    const char * value;
    size_t value_len;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_set_info(p, key, value);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_set_info. Expected PDFPtr.");
	XSRETURN(1);
    }

    key = SvPV(ST(1), PL_na);
    value = SvPV(ST(2), value_len);

    try {
        PDF_set_info2(p, key, value, (int)value_len);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_set_layer_dependency) { /* {{{ */
    PDF * p;
    const char * type;
    const char * optlist;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_set_layer_dependency(p, type, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_set_layer_dependency. Expected PDFPtr.");
	XSRETURN(1);
    }

    type = SvPV(ST(1), PL_na);
    optlist = SvPV(ST(2), PL_na);

    try {
        PDF_set_layer_dependency(p, type, optlist);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_set_parameter) { /* {{{ */
    PDF * p;
    const char * key;
    const char * value;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_set_parameter(p, key, value);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_set_parameter. Expected PDFPtr.");
	XSRETURN(1);
    }

    key = SvPV(ST(1), PL_na);
    value = SvPV(ST(2), PL_na);

    try {
        PDF_set_parameter(p, key, value);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_set_text_pos) { /* {{{ */
    PDF * p;
    double x;
    double y;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_set_text_pos(p, x, y);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_set_text_pos. Expected PDFPtr.");
	XSRETURN(1);
    }

    x = SvNV(ST(1));
    y = SvNV(ST(2));

    try {
        PDF_set_text_pos(p, x, y);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_set_value) { /* {{{ */
    PDF * p;
    const char * key;
    double value;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_set_value(p, key, value);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_set_value. Expected PDFPtr.");
	XSRETURN(1);
    }

    key = SvPV(ST(1), PL_na);
    value = SvNV(ST(2));

    try {
        PDF_set_value(p, key, value);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_setcolor) { /* {{{ */
    PDF * p;
    const char * fstype;
    const char * colorspace;
    double c1;
    double c2;
    double c3;
    double c4;
    dXSARGS;

    if (items != 7) {
	croak("Usage: PDF_setcolor(p, fstype, colorspace, c1, c2, c3, c4);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_setcolor. Expected PDFPtr.");
	XSRETURN(1);
    }

    fstype = SvPV(ST(1), PL_na);
    colorspace = SvPV(ST(2), PL_na);
    c1 = SvNV(ST(3));
    c2 = SvNV(ST(4));
    c3 = SvNV(ST(5));
    c4 = SvNV(ST(6));

    try {
        PDF_setcolor(p, fstype, colorspace, c1, c2, c3, c4);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_setdash) { /* {{{ */
    PDF * p;
    double b;
    double w;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_setdash(p, b, w);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_setdash. Expected PDFPtr.");
	XSRETURN(1);
    }

    b = SvNV(ST(1));
    w = SvNV(ST(2));

    try {
        PDF_setdash(p, b, w);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_setdashpattern) { /* {{{ */
    PDF * p;
    const char * optlist;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_setdashpattern(p, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_setdashpattern. Expected PDFPtr.");
	XSRETURN(1);
    }

    optlist = SvPV(ST(1), PL_na);

    try {
        PDF_setdashpattern(p, optlist);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_setflat) { /* {{{ */
    PDF * p;
    double flatness;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_setflat(p, flatness);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_setflat. Expected PDFPtr.");
	XSRETURN(1);
    }

    flatness = SvNV(ST(1));

    try {
        PDF_setflat(p, flatness);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_setfont) { /* {{{ */
    PDF * p;
    int font;
    double fontsize;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_setfont(p, font, fontsize);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_setfont. Expected PDFPtr.");
	XSRETURN(1);
    }

    font = SvIV(ST(1));
    fontsize = SvNV(ST(2));

    try {
        PDF_setfont(p, font, fontsize);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_setgray) { /* {{{ */
    PDF * p;
    double gray;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_setgray(p, gray);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_setgray. Expected PDFPtr.");
	XSRETURN(1);
    }

    gray = SvNV(ST(1));

    try {
        PDF_setgray(p, gray);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_setgray_fill) { /* {{{ */
    PDF * p;
    double gray;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_setgray_fill(p, gray);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_setgray_fill. Expected PDFPtr.");
	XSRETURN(1);
    }

    gray = SvNV(ST(1));

    try {
        PDF_setgray_fill(p, gray);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_setgray_stroke) { /* {{{ */
    PDF * p;
    double gray;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_setgray_stroke(p, gray);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_setgray_stroke. Expected PDFPtr.");
	XSRETURN(1);
    }

    gray = SvNV(ST(1));

    try {
        PDF_setgray_stroke(p, gray);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_setlinecap) { /* {{{ */
    PDF * p;
    int linecap;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_setlinecap(p, linecap);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_setlinecap. Expected PDFPtr.");
	XSRETURN(1);
    }

    linecap = SvIV(ST(1));

    try {
        PDF_setlinecap(p, linecap);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_setlinejoin) { /* {{{ */
    PDF * p;
    int linejoin;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_setlinejoin(p, linejoin);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_setlinejoin. Expected PDFPtr.");
	XSRETURN(1);
    }

    linejoin = SvIV(ST(1));

    try {
        PDF_setlinejoin(p, linejoin);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_setlinewidth) { /* {{{ */
    PDF * p;
    double width;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_setlinewidth(p, width);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_setlinewidth. Expected PDFPtr.");
	XSRETURN(1);
    }

    width = SvNV(ST(1));

    try {
        PDF_setlinewidth(p, width);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_setmatrix) { /* {{{ */
    PDF * p;
    double a;
    double b;
    double c;
    double d;
    double e;
    double f;
    dXSARGS;

    if (items != 7) {
	croak("Usage: PDF_setmatrix(p, a, b, c, d, e, f);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_setmatrix. Expected PDFPtr.");
	XSRETURN(1);
    }

    a = SvNV(ST(1));
    b = SvNV(ST(2));
    c = SvNV(ST(3));
    d = SvNV(ST(4));
    e = SvNV(ST(5));
    f = SvNV(ST(6));

    try {
        PDF_setmatrix(p, a, b, c, d, e, f);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_setmiterlimit) { /* {{{ */
    PDF * p;
    double miter;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_setmiterlimit(p, miter);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_setmiterlimit. Expected PDFPtr.");
	XSRETURN(1);
    }

    miter = SvNV(ST(1));

    try {
        PDF_setmiterlimit(p, miter);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_setrgbcolor) { /* {{{ */
    PDF * p;
    double red;
    double green;
    double blue;
    dXSARGS;

    if (items != 4) {
	croak("Usage: PDF_setrgbcolor(p, red, green, blue);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_setrgbcolor. Expected PDFPtr.");
	XSRETURN(1);
    }

    red = SvNV(ST(1));
    green = SvNV(ST(2));
    blue = SvNV(ST(3));

    try {
        PDF_setrgbcolor(p, red, green, blue);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_setrgbcolor_fill) { /* {{{ */
    PDF * p;
    double red;
    double green;
    double blue;
    dXSARGS;

    if (items != 4) {
	croak("Usage: PDF_setrgbcolor_fill(p, red, green, blue);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_setrgbcolor_fill. Expected PDFPtr.");
	XSRETURN(1);
    }

    red = SvNV(ST(1));
    green = SvNV(ST(2));
    blue = SvNV(ST(3));

    try {
        PDF_setrgbcolor_fill(p, red, green, blue);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_setrgbcolor_stroke) { /* {{{ */
    PDF * p;
    double red;
    double green;
    double blue;
    dXSARGS;

    if (items != 4) {
	croak("Usage: PDF_setrgbcolor_stroke(p, red, green, blue);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_setrgbcolor_stroke. Expected PDFPtr.");
	XSRETURN(1);
    }

    red = SvNV(ST(1));
    green = SvNV(ST(2));
    blue = SvNV(ST(3));

    try {
        PDF_setrgbcolor_stroke(p, red, green, blue);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_shading) { /* {{{ */
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
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 11) {
	croak("Usage: PDF_shading(p, shtype, x_0, y_0, x_1, y_1, c_1, c_2, c_3, c_4, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_shading. Expected PDFPtr.");
	XSRETURN(1);
    }

    shtype = SvPV(ST(1), PL_na);
    x_0 = SvNV(ST(2));
    y_0 = SvNV(ST(3));
    x_1 = SvNV(ST(4));
    y_1 = SvNV(ST(5));
    c_1 = SvNV(ST(6));
    c_2 = SvNV(ST(7));
    c_3 = SvNV(ST(8));
    c_4 = SvNV(ST(9));
    optlist = SvPV(ST(10), PL_na);

    try {
        _result = PDF_shading(p, shtype, x_0, y_0, x_1, y_1, c_1, c_2, c_3, c_4, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_shading_pattern) { /* {{{ */
    PDF * p;
    int shading;
    const char * optlist;
    int _result = -1;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_shading_pattern(p, shading, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_shading_pattern. Expected PDFPtr.");
	XSRETURN(1);
    }

    shading = SvIV(ST(1));
    optlist = SvPV(ST(2), PL_na);

    try {
        _result = PDF_shading_pattern(p, shading, optlist);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setiv(ST(0),(IV) _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_shfill) { /* {{{ */
    PDF * p;
    int shading;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_shfill(p, shading);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_shfill. Expected PDFPtr.");
	XSRETURN(1);
    }

    shading = SvIV(ST(1));

    try {
        PDF_shfill(p, shading);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_show) { /* {{{ */
    PDF * p;
    const char * text;
    size_t text_len;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_show(p, text);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_show. Expected PDFPtr.");
	XSRETURN(1);
    }

    text = SvPV(ST(1), text_len);

    try {
        PDF_show2(p, text, (int)text_len);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_show_xy) { /* {{{ */
    PDF * p;
    const char * text;
    size_t text_len;
    double x;
    double y;
    dXSARGS;

    if (items != 4) {
	croak("Usage: PDF_show_xy(p, text, x, y);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_show_xy. Expected PDFPtr.");
	XSRETURN(1);
    }

    text = SvPV(ST(1), text_len);
    x = SvNV(ST(2));
    y = SvNV(ST(3));

    try {
        PDF_show_xy2(p, text, (int)text_len, x, y);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_skew) { /* {{{ */
    PDF * p;
    double alpha;
    double beta;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_skew(p, alpha, beta);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_skew. Expected PDFPtr.");
	XSRETURN(1);
    }

    alpha = SvNV(ST(1));
    beta = SvNV(ST(2));

    try {
        PDF_skew(p, alpha, beta);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_stringwidth) { /* {{{ */
    PDF * p;
    const char * text;
    size_t text_len;
    int font;
    double fontsize;
    double _result = -1;
    dXSARGS;

    if (items != 4) {
	croak("Usage: PDF_stringwidth(p, text, font, fontsize);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_stringwidth. Expected PDFPtr.");
	XSRETURN(1);
    }

    text = SvPV(ST(1), text_len);
    font = SvIV(ST(2));
    fontsize = SvNV(ST(3));

    try {
        _result = PDF_stringwidth2(p, text, (int)text_len, font, fontsize);
    } catch;
    
    ST(0) = sv_newmortal();
    sv_setnv(ST(0), _result);
    XSRETURN(1);
} /* }}} */

    
XS(_wrap_PDF_stroke) { /* {{{ */
    PDF * p;
    dXSARGS;

    if (items != 1) {
	croak("Usage: PDF_stroke(p);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_stroke. Expected PDFPtr.");
	XSRETURN(1);
    }


    try {
        PDF_stroke(p);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_suspend_page) { /* {{{ */
    PDF * p;
    const char * optlist;
    dXSARGS;

    if (items != 2) {
	croak("Usage: PDF_suspend_page(p, optlist);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_suspend_page. Expected PDFPtr.");
	XSRETURN(1);
    }

    optlist = SvPV(ST(1), PL_na);

    try {
        PDF_suspend_page(p, optlist);
    } catch;
    
    XSRETURN(0);
} /* }}} */

    
XS(_wrap_PDF_translate) { /* {{{ */
    PDF * p;
    double tx;
    double ty;
    dXSARGS;

    if (items != 3) {
	croak("Usage: PDF_translate(p, tx, ty);");
    }
    if (SWIG_GetPtr(ST(0),(void *) &p, "PDFPtr")) {
	croak("Type error in argument 1 of PDF_translate. Expected PDFPtr.");
	XSRETURN(1);
    }

    tx = SvNV(ST(1));
    ty = SvNV(ST(2));

    try {
        PDF_translate(p, tx, ty);
    } catch;
    
    XSRETURN(0);
} /* }}} */
#endif /* defined(_WRAP_CODE) */
#if defined(_WRAP_newXS)
    newXS("pdflibc::PDF_activate_item", _wrap_PDF_activate_item, file);
    newXS("pdflibc::PDF_create_3dview", _wrap_PDF_create_3dview, file);
    newXS("pdflibc::PDF_load_3ddata", _wrap_PDF_load_3ddata, file);
    newXS("pdflibc::PDF_add_bookmark", _wrap_PDF_add_bookmark, file);
    newXS("pdflibc::PDF_add_launchlink", _wrap_PDF_add_launchlink, file);
    newXS("pdflibc::PDF_add_locallink", _wrap_PDF_add_locallink, file);
    newXS("pdflibc::PDF_add_nameddest", _wrap_PDF_add_nameddest, file);
    newXS("pdflibc::PDF_add_note", _wrap_PDF_add_note, file);
    newXS("pdflibc::PDF_add_pdflink", _wrap_PDF_add_pdflink, file);
    newXS("pdflibc::PDF_add_table_cell", _wrap_PDF_add_table_cell, file);
    newXS("pdflibc::PDF_add_textflow", _wrap_PDF_add_textflow, file);
    newXS("pdflibc::PDF_add_thumbnail", _wrap_PDF_add_thumbnail, file);
    newXS("pdflibc::PDF_add_weblink", _wrap_PDF_add_weblink, file);
    newXS("pdflibc::PDF_arc", _wrap_PDF_arc, file);
    newXS("pdflibc::PDF_arcn", _wrap_PDF_arcn, file);
    newXS("pdflibc::PDF_attach_file", _wrap_PDF_attach_file, file);
    newXS("pdflibc::PDF_begin_document", _wrap_PDF_begin_document, file);
    newXS("pdflibc::PDF_begin_font", _wrap_PDF_begin_font, file);
    newXS("pdflibc::PDF_begin_glyph", _wrap_PDF_begin_glyph, file);
    newXS("pdflibc::PDF_begin_item", _wrap_PDF_begin_item, file);
    newXS("pdflibc::PDF_begin_layer", _wrap_PDF_begin_layer, file);
    newXS("pdflibc::PDF_begin_page", _wrap_PDF_begin_page, file);
    newXS("pdflibc::PDF_begin_page_ext", _wrap_PDF_begin_page_ext, file);
    newXS("pdflibc::PDF_begin_pattern", _wrap_PDF_begin_pattern, file);
    newXS("pdflibc::PDF_begin_template", _wrap_PDF_begin_template, file);
    newXS("pdflibc::PDF_begin_template_ext", _wrap_PDF_begin_template_ext, file);
    newXS("pdflibc::PDF_circle", _wrap_PDF_circle, file);
    newXS("pdflibc::PDF_clip", _wrap_PDF_clip, file);
    newXS("pdflibc::PDF_close", _wrap_PDF_close, file);
    newXS("pdflibc::PDF_close_image", _wrap_PDF_close_image, file);
    newXS("pdflibc::PDF_close_pdi", _wrap_PDF_close_pdi, file);
    newXS("pdflibc::PDF_close_pdi_document", _wrap_PDF_close_pdi_document, file);
    newXS("pdflibc::PDF_close_pdi_page", _wrap_PDF_close_pdi_page, file);
    newXS("pdflibc::PDF_closepath", _wrap_PDF_closepath, file);
    newXS("pdflibc::PDF_closepath_fill_stroke", _wrap_PDF_closepath_fill_stroke, file);
    newXS("pdflibc::PDF_closepath_stroke", _wrap_PDF_closepath_stroke, file);
    newXS("pdflibc::PDF_concat", _wrap_PDF_concat, file);
    newXS("pdflibc::PDF_continue_text", _wrap_PDF_continue_text, file);
    newXS("pdflibc::PDF_create_action", _wrap_PDF_create_action, file);
    newXS("pdflibc::PDF_create_annotation", _wrap_PDF_create_annotation, file);
    newXS("pdflibc::PDF_create_bookmark", _wrap_PDF_create_bookmark, file);
    newXS("pdflibc::PDF_create_field", _wrap_PDF_create_field, file);
    newXS("pdflibc::PDF_create_fieldgroup", _wrap_PDF_create_fieldgroup, file);
    newXS("pdflibc::PDF_create_gstate", _wrap_PDF_create_gstate, file);
    newXS("pdflibc::PDF_create_pvf", _wrap_PDF_create_pvf, file);
    newXS("pdflibc::PDF_create_textflow", _wrap_PDF_create_textflow, file);
    newXS("pdflibc::PDF_curveto", _wrap_PDF_curveto, file);
    newXS("pdflibc::PDF_define_layer", _wrap_PDF_define_layer, file);
    newXS("pdflibc::PDF_delete_pvf", _wrap_PDF_delete_pvf, file);
    newXS("pdflibc::PDF_delete_table", _wrap_PDF_delete_table, file);
    newXS("pdflibc::PDF_delete_textflow", _wrap_PDF_delete_textflow, file);
    newXS("pdflibc::PDF_encoding_set_char", _wrap_PDF_encoding_set_char, file);
    newXS("pdflibc::PDF_end_document", _wrap_PDF_end_document, file);
    newXS("pdflibc::PDF_end_font", _wrap_PDF_end_font, file);
    newXS("pdflibc::PDF_end_glyph", _wrap_PDF_end_glyph, file);
    newXS("pdflibc::PDF_end_item", _wrap_PDF_end_item, file);
    newXS("pdflibc::PDF_end_layer", _wrap_PDF_end_layer, file);
    newXS("pdflibc::PDF_end_mc", _wrap_PDF_end_mc, file);
    newXS("pdflibc::PDF_end_page", _wrap_PDF_end_page, file);
    newXS("pdflibc::PDF_end_page_ext", _wrap_PDF_end_page_ext, file);
    newXS("pdflibc::PDF_end_pattern", _wrap_PDF_end_pattern, file);
    newXS("pdflibc::PDF_end_template", _wrap_PDF_end_template, file);
    newXS("pdflibc::PDF_endpath", _wrap_PDF_endpath, file);
    newXS("pdflibc::PDF_fill", _wrap_PDF_fill, file);
    newXS("pdflibc::PDF_fill_imageblock", _wrap_PDF_fill_imageblock, file);
    newXS("pdflibc::PDF_fill_pdfblock", _wrap_PDF_fill_pdfblock, file);
    newXS("pdflibc::PDF_fill_stroke", _wrap_PDF_fill_stroke, file);
    newXS("pdflibc::PDF_fill_textblock", _wrap_PDF_fill_textblock, file);
    newXS("pdflibc::PDF_findfont", _wrap_PDF_findfont, file);
    newXS("pdflibc::PDF_fit_image", _wrap_PDF_fit_image, file);
    newXS("pdflibc::PDF_fit_pdi_page", _wrap_PDF_fit_pdi_page, file);
    newXS("pdflibc::PDF_fit_table", _wrap_PDF_fit_table, file);
    newXS("pdflibc::PDF_fit_textflow", _wrap_PDF_fit_textflow, file);
    newXS("pdflibc::PDF_fit_textline", _wrap_PDF_fit_textline, file);
    newXS("pdflibc::PDF_get_apiname", _wrap_PDF_get_apiname, file);
    newXS("pdflibc::PDF_get_buffer", _wrap_PDF_get_buffer, file);
    newXS("pdflibc::PDF_get_errmsg", _wrap_PDF_get_errmsg, file);
    newXS("pdflibc::PDF_get_errnum", _wrap_PDF_get_errnum, file);
    newXS("pdflibc::PDF_get_parameter", _wrap_PDF_get_parameter, file);
    newXS("pdflibc::PDF_get_pdi_parameter", _wrap_PDF_get_pdi_parameter, file);
    newXS("pdflibc::PDF_get_pdi_value", _wrap_PDF_get_pdi_value, file);
    newXS("pdflibc::PDF_get_value", _wrap_PDF_get_value, file);
    newXS("pdflibc::PDF_info_font", _wrap_PDF_info_font, file);
    newXS("pdflibc::PDF_info_matchbox", _wrap_PDF_info_matchbox, file);
    newXS("pdflibc::PDF_info_table", _wrap_PDF_info_table, file);
    newXS("pdflibc::PDF_info_textflow", _wrap_PDF_info_textflow, file);
    newXS("pdflibc::PDF_info_textline", _wrap_PDF_info_textline, file);
    newXS("pdflibc::PDF_initgraphics", _wrap_PDF_initgraphics, file);
    newXS("pdflibc::PDF_lineto", _wrap_PDF_lineto, file);
    newXS("pdflibc::PDF_load_font", _wrap_PDF_load_font, file);
    newXS("pdflibc::PDF_load_iccprofile", _wrap_PDF_load_iccprofile, file);
    newXS("pdflibc::PDF_load_image", _wrap_PDF_load_image, file);
    newXS("pdflibc::PDF_makespotcolor", _wrap_PDF_makespotcolor, file);
    newXS("pdflibc::PDF_moveto", _wrap_PDF_moveto, file);
    newXS("pdflibc::PDF_open_CCITT", _wrap_PDF_open_CCITT, file);
    newXS("pdflibc::PDF_open_file", _wrap_PDF_open_file, file);
    newXS("pdflibc::PDF_open_image_file", _wrap_PDF_open_image_file, file);
    newXS("pdflibc::PDF_open_pdi_document", _wrap_PDF_open_pdi_document, file);
    newXS("pdflibc::PDF_open_pdi_page", _wrap_PDF_open_pdi_page, file);
    newXS("pdflibc::PDF_pcos_get_number", _wrap_PDF_pcos_get_number, file);
    newXS("pdflibc::PDF_pcos_get_string", _wrap_PDF_pcos_get_string, file);
    newXS("pdflibc::PDF_pcos_get_stream", _wrap_PDF_pcos_get_stream, file);
    newXS("pdflibc::PDF_place_image", _wrap_PDF_place_image, file);
    newXS("pdflibc::PDF_place_pdi_page", _wrap_PDF_place_pdi_page, file);
    newXS("pdflibc::PDF_process_pdi", _wrap_PDF_process_pdi, file);
    newXS("pdflibc::PDF_rect", _wrap_PDF_rect, file);
    newXS("pdflibc::PDF_restore", _wrap_PDF_restore, file);
    newXS("pdflibc::PDF_resume_page", _wrap_PDF_resume_page, file);
    newXS("pdflibc::PDF_rotate", _wrap_PDF_rotate, file);
    newXS("pdflibc::PDF_save", _wrap_PDF_save, file);
    newXS("pdflibc::PDF_scale", _wrap_PDF_scale, file);
    newXS("pdflibc::PDF_set_border_color", _wrap_PDF_set_border_color, file);
    newXS("pdflibc::PDF_set_border_dash", _wrap_PDF_set_border_dash, file);
    newXS("pdflibc::PDF_set_border_style", _wrap_PDF_set_border_style, file);
    newXS("pdflibc::PDF_set_gstate", _wrap_PDF_set_gstate, file);
    newXS("pdflibc::PDF_set_info", _wrap_PDF_set_info, file);
    newXS("pdflibc::PDF_set_layer_dependency", _wrap_PDF_set_layer_dependency, file);
    newXS("pdflibc::PDF_set_parameter", _wrap_PDF_set_parameter, file);
    newXS("pdflibc::PDF_set_text_pos", _wrap_PDF_set_text_pos, file);
    newXS("pdflibc::PDF_set_value", _wrap_PDF_set_value, file);
    newXS("pdflibc::PDF_setcolor", _wrap_PDF_setcolor, file);
    newXS("pdflibc::PDF_setdash", _wrap_PDF_setdash, file);
    newXS("pdflibc::PDF_setdashpattern", _wrap_PDF_setdashpattern, file);
    newXS("pdflibc::PDF_setflat", _wrap_PDF_setflat, file);
    newXS("pdflibc::PDF_setfont", _wrap_PDF_setfont, file);
    newXS("pdflibc::PDF_setgray", _wrap_PDF_setgray, file);
    newXS("pdflibc::PDF_setgray_fill", _wrap_PDF_setgray_fill, file);
    newXS("pdflibc::PDF_setgray_stroke", _wrap_PDF_setgray_stroke, file);
    newXS("pdflibc::PDF_setlinecap", _wrap_PDF_setlinecap, file);
    newXS("pdflibc::PDF_setlinejoin", _wrap_PDF_setlinejoin, file);
    newXS("pdflibc::PDF_setlinewidth", _wrap_PDF_setlinewidth, file);
    newXS("pdflibc::PDF_setmatrix", _wrap_PDF_setmatrix, file);
    newXS("pdflibc::PDF_setmiterlimit", _wrap_PDF_setmiterlimit, file);
    newXS("pdflibc::PDF_setrgbcolor", _wrap_PDF_setrgbcolor, file);
    newXS("pdflibc::PDF_setrgbcolor_fill", _wrap_PDF_setrgbcolor_fill, file);
    newXS("pdflibc::PDF_setrgbcolor_stroke", _wrap_PDF_setrgbcolor_stroke, file);
    newXS("pdflibc::PDF_shading", _wrap_PDF_shading, file);
    newXS("pdflibc::PDF_shading_pattern", _wrap_PDF_shading_pattern, file);
    newXS("pdflibc::PDF_shfill", _wrap_PDF_shfill, file);
    newXS("pdflibc::PDF_show", _wrap_PDF_show, file);
    newXS("pdflibc::PDF_show_xy", _wrap_PDF_show_xy, file);
    newXS("pdflibc::PDF_skew", _wrap_PDF_skew, file);
    newXS("pdflibc::PDF_stringwidth", _wrap_PDF_stringwidth, file);
    newXS("pdflibc::PDF_stroke", _wrap_PDF_stroke, file);
    newXS("pdflibc::PDF_suspend_page", _wrap_PDF_suspend_page, file);
    newXS("pdflibc::PDF_translate", _wrap_PDF_translate, file);
#endif /* defined(_WRAP_newXS)*/
#if defined(_WRAP_PM)
*PDF_activate_item = *pdflibc::PDF_activate_item;
*PDF_create_3dview = *pdflibc::PDF_create_3dview;
*PDF_load_3ddata = *pdflibc::PDF_load_3ddata;
*PDF_add_bookmark = *pdflibc::PDF_add_bookmark;
*PDF_add_launchlink = *pdflibc::PDF_add_launchlink;
*PDF_add_locallink = *pdflibc::PDF_add_locallink;
*PDF_add_nameddest = *pdflibc::PDF_add_nameddest;
*PDF_add_note = *pdflibc::PDF_add_note;
*PDF_add_pdflink = *pdflibc::PDF_add_pdflink;
*PDF_add_table_cell = *pdflibc::PDF_add_table_cell;
*PDF_add_textflow = *pdflibc::PDF_add_textflow;
*PDF_add_thumbnail = *pdflibc::PDF_add_thumbnail;
*PDF_add_weblink = *pdflibc::PDF_add_weblink;
*PDF_arc = *pdflibc::PDF_arc;
*PDF_arcn = *pdflibc::PDF_arcn;
*PDF_attach_file = *pdflibc::PDF_attach_file;
*PDF_begin_document = *pdflibc::PDF_begin_document;
*PDF_begin_font = *pdflibc::PDF_begin_font;
*PDF_begin_glyph = *pdflibc::PDF_begin_glyph;
*PDF_begin_item = *pdflibc::PDF_begin_item;
*PDF_begin_layer = *pdflibc::PDF_begin_layer;
*PDF_begin_page = *pdflibc::PDF_begin_page;
*PDF_begin_page_ext = *pdflibc::PDF_begin_page_ext;
*PDF_begin_pattern = *pdflibc::PDF_begin_pattern;
*PDF_begin_template = *pdflibc::PDF_begin_template;
*PDF_begin_template_ext = *pdflibc::PDF_begin_template_ext;
*PDF_circle = *pdflibc::PDF_circle;
*PDF_clip = *pdflibc::PDF_clip;
*PDF_close = *pdflibc::PDF_close;
*PDF_close_image = *pdflibc::PDF_close_image;
*PDF_close_pdi = *pdflibc::PDF_close_pdi;
*PDF_close_pdi_document = *pdflibc::PDF_close_pdi_document;
*PDF_close_pdi_page = *pdflibc::PDF_close_pdi_page;
*PDF_closepath = *pdflibc::PDF_closepath;
*PDF_closepath_fill_stroke = *pdflibc::PDF_closepath_fill_stroke;
*PDF_closepath_stroke = *pdflibc::PDF_closepath_stroke;
*PDF_concat = *pdflibc::PDF_concat;
*PDF_continue_text = *pdflibc::PDF_continue_text;
*PDF_create_action = *pdflibc::PDF_create_action;
*PDF_create_annotation = *pdflibc::PDF_create_annotation;
*PDF_create_bookmark = *pdflibc::PDF_create_bookmark;
*PDF_create_field = *pdflibc::PDF_create_field;
*PDF_create_fieldgroup = *pdflibc::PDF_create_fieldgroup;
*PDF_create_gstate = *pdflibc::PDF_create_gstate;
*PDF_create_pvf = *pdflibc::PDF_create_pvf;
*PDF_create_textflow = *pdflibc::PDF_create_textflow;
*PDF_curveto = *pdflibc::PDF_curveto;
*PDF_define_layer = *pdflibc::PDF_define_layer;
*PDF_delete = *pdflibc::PDF_delete;
*PDF_delete_pvf = *pdflibc::PDF_delete_pvf;
*PDF_delete_table = *pdflibc::PDF_delete_table;
*PDF_delete_textflow = *pdflibc::PDF_delete_textflow;
*PDF_encoding_set_char = *pdflibc::PDF_encoding_set_char;
*PDF_end_document = *pdflibc::PDF_end_document;
*PDF_end_font = *pdflibc::PDF_end_font;
*PDF_end_glyph = *pdflibc::PDF_end_glyph;
*PDF_end_item = *pdflibc::PDF_end_item;
*PDF_end_layer = *pdflibc::PDF_end_layer;
*PDF_end_mc = *pdflibc::PDF_end_mc;
*PDF_end_page = *pdflibc::PDF_end_page;
*PDF_end_page_ext = *pdflibc::PDF_end_page_ext;
*PDF_end_pattern = *pdflibc::PDF_end_pattern;
*PDF_end_template = *pdflibc::PDF_end_template;
*PDF_endpath = *pdflibc::PDF_endpath;
*PDF_fill = *pdflibc::PDF_fill;
*PDF_fill_imageblock = *pdflibc::PDF_fill_imageblock;
*PDF_fill_pdfblock = *pdflibc::PDF_fill_pdfblock;
*PDF_fill_stroke = *pdflibc::PDF_fill_stroke;
*PDF_fill_textblock = *pdflibc::PDF_fill_textblock;
*PDF_findfont = *pdflibc::PDF_findfont;
*PDF_fit_image = *pdflibc::PDF_fit_image;
*PDF_fit_pdi_page = *pdflibc::PDF_fit_pdi_page;
*PDF_fit_table = *pdflibc::PDF_fit_table;
*PDF_fit_textflow = *pdflibc::PDF_fit_textflow;
*PDF_fit_textline = *pdflibc::PDF_fit_textline;
*PDF_get_apiname = *pdflibc::PDF_get_apiname;
*PDF_get_buffer = *pdflibc::PDF_get_buffer;
*PDF_get_errmsg = *pdflibc::PDF_get_errmsg;
*PDF_get_errnum = *pdflibc::PDF_get_errnum;
*PDF_get_parameter = *pdflibc::PDF_get_parameter;
*PDF_get_pdi_parameter = *pdflibc::PDF_get_pdi_parameter;
*PDF_get_pdi_value = *pdflibc::PDF_get_pdi_value;
*PDF_get_value = *pdflibc::PDF_get_value;
*PDF_info_font = *pdflibc::PDF_info_font;
*PDF_info_matchbox = *pdflibc::PDF_info_matchbox;
*PDF_info_table = *pdflibc::PDF_info_table;
*PDF_info_textflow = *pdflibc::PDF_info_textflow;
*PDF_info_textline = *pdflibc::PDF_info_textline;
*PDF_initgraphics = *pdflibc::PDF_initgraphics;
*PDF_lineto = *pdflibc::PDF_lineto;
*PDF_load_font = *pdflibc::PDF_load_font;
*PDF_load_iccprofile = *pdflibc::PDF_load_iccprofile;
*PDF_load_image = *pdflibc::PDF_load_image;
*PDF_makespotcolor = *pdflibc::PDF_makespotcolor;
*PDF_moveto = *pdflibc::PDF_moveto;
*PDF_new = *pdflibc::PDF_new;
*PDF_open_CCITT = *pdflibc::PDF_open_CCITT;
*PDF_open_file = *pdflibc::PDF_open_file;
*PDF_open_image = *pdflibc::PDF_open_image;
*PDF_open_image_file = *pdflibc::PDF_open_image_file;
*PDF_open_pdi = *pdflibc::PDF_open_pdi;
*PDF_open_pdi_document = *pdflibc::PDF_open_pdi_document;
*PDF_open_pdi_page = *pdflibc::PDF_open_pdi_page;
*PDF_pcos_get_number = *pdflibc::PDF_pcos_get_number;
*PDF_pcos_get_string = *pdflibc::PDF_pcos_get_string;
*PDF_pcos_get_stream = *pdflibc::PDF_pcos_get_stream;
*PDF_place_image = *pdflibc::PDF_place_image;
*PDF_place_pdi_page = *pdflibc::PDF_place_pdi_page;
*PDF_process_pdi = *pdflibc::PDF_process_pdi;
*PDF_rect = *pdflibc::PDF_rect;
*PDF_restore = *pdflibc::PDF_restore;
*PDF_resume_page = *pdflibc::PDF_resume_page;
*PDF_rotate = *pdflibc::PDF_rotate;
*PDF_save = *pdflibc::PDF_save;
*PDF_scale = *pdflibc::PDF_scale;
*PDF_set_border_color = *pdflibc::PDF_set_border_color;
*PDF_set_border_dash = *pdflibc::PDF_set_border_dash;
*PDF_set_border_style = *pdflibc::PDF_set_border_style;
*PDF_set_gstate = *pdflibc::PDF_set_gstate;
*PDF_set_info = *pdflibc::PDF_set_info;
*PDF_set_layer_dependency = *pdflibc::PDF_set_layer_dependency;
*PDF_set_parameter = *pdflibc::PDF_set_parameter;
*PDF_set_text_pos = *pdflibc::PDF_set_text_pos;
*PDF_set_value = *pdflibc::PDF_set_value;
*PDF_setcolor = *pdflibc::PDF_setcolor;
*PDF_setdash = *pdflibc::PDF_setdash;
*PDF_setdashpattern = *pdflibc::PDF_setdashpattern;
*PDF_setflat = *pdflibc::PDF_setflat;
*PDF_setfont = *pdflibc::PDF_setfont;
*PDF_setgray = *pdflibc::PDF_setgray;
*PDF_setgray_fill = *pdflibc::PDF_setgray_fill;
*PDF_setgray_stroke = *pdflibc::PDF_setgray_stroke;
*PDF_setlinecap = *pdflibc::PDF_setlinecap;
*PDF_setlinejoin = *pdflibc::PDF_setlinejoin;
*PDF_setlinewidth = *pdflibc::PDF_setlinewidth;
*PDF_setmatrix = *pdflibc::PDF_setmatrix;
*PDF_setmiterlimit = *pdflibc::PDF_setmiterlimit;
*PDF_setpolydash = *pdflibc::PDF_setpolydash;
*PDF_setrgbcolor = *pdflibc::PDF_setrgbcolor;
*PDF_setrgbcolor_fill = *pdflibc::PDF_setrgbcolor_fill;
*PDF_setrgbcolor_stroke = *pdflibc::PDF_setrgbcolor_stroke;
*PDF_shading = *pdflibc::PDF_shading;
*PDF_shading_pattern = *pdflibc::PDF_shading_pattern;
*PDF_shfill = *pdflibc::PDF_shfill;
*PDF_show = *pdflibc::PDF_show;
*PDF_show_boxed = *pdflibc::PDF_show_boxed;
*PDF_show_xy = *pdflibc::PDF_show_xy;
*PDF_skew = *pdflibc::PDF_skew;
*PDF_stringwidth = *pdflibc::PDF_stringwidth;
*PDF_stroke = *pdflibc::PDF_stroke;
*PDF_suspend_page = *pdflibc::PDF_suspend_page;
*PDF_translate = *pdflibc::PDF_translate;
*PDF_utf16_to_utf8 = *pdflibc::PDF_utf16_to_utf8;
*PDF_utf32_to_utf16 = *pdflibc::PDF_utf32_to_utf16;
*PDF_utf8_to_utf16 = *pdflibc::PDF_utf8_to_utf16;
PDF_activate_item
PDF_create_3dview
PDF_load_3ddata
PDF_add_bookmark
PDF_add_launchlink
PDF_add_locallink
PDF_add_nameddest
PDF_add_note
PDF_add_pdflink
PDF_add_table_cell
PDF_add_textflow
PDF_add_thumbnail
PDF_add_weblink
PDF_arc
PDF_arcn
PDF_attach_file
PDF_begin_document
PDF_begin_font
PDF_begin_glyph
PDF_begin_item
PDF_begin_layer
PDF_begin_page
PDF_begin_page_ext
PDF_begin_pattern
PDF_begin_template
PDF_begin_template_ext
PDF_circle
PDF_clip
PDF_close
PDF_close_image
PDF_close_pdi
PDF_close_pdi_document
PDF_close_pdi_page
PDF_closepath
PDF_closepath_fill_stroke
PDF_closepath_stroke
PDF_concat
PDF_continue_text
PDF_create_action
PDF_create_annotation
PDF_create_bookmark
PDF_create_field
PDF_create_fieldgroup
PDF_create_gstate
PDF_create_pvf
PDF_create_textflow
PDF_curveto
PDF_define_layer
PDF_delete
PDF_delete_pvf
PDF_delete_table
PDF_delete_textflow
PDF_encoding_set_char
PDF_end_document
PDF_end_font
PDF_end_glyph
PDF_end_item
PDF_end_layer
PDF_end_mc
PDF_end_page
PDF_end_page_ext
PDF_end_pattern
PDF_end_template
PDF_endpath
PDF_fill
PDF_fill_imageblock
PDF_fill_pdfblock
PDF_fill_stroke
PDF_fill_textblock
PDF_findfont
PDF_fit_image
PDF_fit_pdi_page
PDF_fit_table
PDF_fit_textflow
PDF_fit_textline
PDF_get_apiname
PDF_get_buffer
PDF_get_errmsg
PDF_get_errnum
PDF_get_parameter
PDF_get_pdi_parameter
PDF_get_pdi_value
PDF_get_value
PDF_info_font
PDF_info_matchbox
PDF_info_table
PDF_info_textflow
PDF_info_textline
PDF_initgraphics
PDF_lineto
PDF_load_font
PDF_load_iccprofile
PDF_load_image
PDF_makespotcolor
PDF_moveto
PDF_new
PDF_open_CCITT
PDF_open_file
PDF_open_image
PDF_open_image_file
PDF_open_pdi
PDF_open_pdi_document
PDF_open_pdi_page
PDF_pcos_get_number
PDF_pcos_get_string
PDF_pcos_get_stream
PDF_place_image
PDF_place_pdi_page
PDF_process_pdi
PDF_rect
PDF_restore
PDF_resume_page
PDF_rotate
PDF_save
PDF_scale
PDF_set_border_color
PDF_set_border_dash
PDF_set_border_style
PDF_set_gstate
PDF_set_info
PDF_set_layer_dependency
PDF_set_parameter
PDF_set_text_pos
PDF_set_value
PDF_setcolor
PDF_setdash
PDF_setdashpattern
PDF_setflat
PDF_setfont
PDF_setgray
PDF_setgray_fill
PDF_setgray_stroke
PDF_setlinecap
PDF_setlinejoin
PDF_setlinewidth
PDF_setmatrix
PDF_setmiterlimit
PDF_setpolydash
PDF_setrgbcolor
PDF_setrgbcolor_fill
PDF_setrgbcolor_stroke
PDF_shading
PDF_shading_pattern
PDF_shfill
PDF_show
PDF_show_boxed
PDF_show_xy
PDF_skew
PDF_stringwidth
PDF_stroke
PDF_suspend_page
PDF_translate
PDF_utf16_to_utf8
PDF_utf32_to_utf16
PDF_utf8_to_utf16

#endif /* defined(_WRAP_PM)*/
