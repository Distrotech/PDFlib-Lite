#if defined(_WRAP_CODE)

    
/* Activate a previously created structure element or other content item.. */
static VALUE
activate_item(VALUE self, VALUE id)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_activate_item(pdf, NUM2INT(id));
    } pdf_catch;
    
    return self;
}

    
/* Create a 3D view (requires PDF 1.6). Returns: A 3D view handle, or -1 (in PHP: 0) on error.. */
static VALUE
create_3dview(VALUE self, VALUE username, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_create_3dview(pdf, CHAR(username), 0, CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Load a 3D model from a disk-based or virtual file (requires PDF 1.6).  Returns: A 3D handle, or -1 (in PHP: 0) on error.. */
static VALUE
load_3ddata(VALUE self, VALUE filename, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_load_3ddata(pdf, CHAR(filename), 0, CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Create a named destination on an arbitrary page in the current document.. */
static VALUE
add_nameddest(VALUE self, VALUE name, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_add_nameddest(pdf, CHAR(name), LEN(name), CHAR(optlist));
    } pdf_catch;
    
    return self;
}

    
/* Add a cell to a new or existing table.  Returns: A table handle which can be used in subsequent table-related calls. . */
static VALUE
add_table_cell(VALUE self, VALUE table, VALUE column, VALUE row, VALUE text, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_add_table_cell(pdf, NUM2INT(table), NUM2INT(column), NUM2INT(row), CHAR(text), LEN(text), CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Create a Textflow object, or add text and explicit options to an existing Textflow. Returns: A Textflow handle, or -1 (in PHP: 0) on error.. */
static VALUE
add_textflow(VALUE self, VALUE textflow, VALUE text, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_add_textflow(pdf, NUM2INT(textflow), CHAR(text), LEN(text), CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Add an existing image as thumbnail for the current page.. */
static VALUE
add_thumbnail(VALUE self, VALUE image)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_add_thumbnail(pdf, NUM2INT(image));
    } pdf_catch;
    
    return self;
}

    
/* Draw a counterclockwise circular arc segment.. */
static VALUE
arc(VALUE self, VALUE x, VALUE y, VALUE r, VALUE alpha, VALUE beta)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_arc(pdf, NUM2DBL(x), NUM2DBL(y), NUM2DBL(r), NUM2DBL(alpha), NUM2DBL(beta));
    } pdf_catch;
    
    return self;
}

    
/* Draw a clockwise circular arc segment.. */
static VALUE
arcn(VALUE self, VALUE x, VALUE y, VALUE r, VALUE alpha, VALUE beta)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_arcn(pdf, NUM2DBL(x), NUM2DBL(y), NUM2DBL(r), NUM2DBL(alpha), NUM2DBL(beta));
    } pdf_catch;
    
    return self;
}

    
/* Create a new PDF file subject to various options.  Returns: -1 (in PHP: 0) on error, and 1 otherwise. . */
static VALUE
begin_document(VALUE self, VALUE filename, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_begin_document(pdf, CHAR(filename), 0, CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Start a Type 3 font definition.. */
static VALUE
begin_font(VALUE self, VALUE fontname, VALUE a, VALUE b, VALUE c, VALUE d, VALUE e, VALUE f, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_begin_font(pdf, CHAR(fontname), 0, NUM2DBL(a), NUM2DBL(b), NUM2DBL(c), NUM2DBL(d), NUM2DBL(e), NUM2DBL(f), CHAR(optlist));
    } pdf_catch;
    
    return self;
}

    
/* Start a glyph definition for a Type 3 font.. */
static VALUE
begin_glyph(VALUE self, VALUE glyphname, VALUE wx, VALUE llx, VALUE lly, VALUE urx, VALUE ury)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_begin_glyph(pdf, CHAR(glyphname), NUM2DBL(wx), NUM2DBL(llx), NUM2DBL(lly), NUM2DBL(urx), NUM2DBL(ury));
    } pdf_catch;
    
    return self;
}

    
/* Open a structure element or other content item with attributes supplied as options.  Returns: An item handle. . */
static VALUE
begin_item(VALUE self, VALUE tag, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_begin_item(pdf, CHAR(tag), CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Start a layer for subsequent output on the page (requires PDF 1.5).. */
static VALUE
begin_layer(VALUE self, VALUE layer)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_begin_layer(pdf, NUM2INT(layer));
    } pdf_catch;
    
    return self;
}

    
/* Add a new page to the document, and specify various options.. */
static VALUE
begin_page_ext(VALUE self, VALUE width, VALUE height, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_begin_page_ext(pdf, NUM2DBL(width), NUM2DBL(height), CHAR(optlist));
    } pdf_catch;
    
    return self;
}

    
/* Start a pattern definition.  Returns: A pattern handle. . */
static VALUE
begin_pattern(VALUE self, VALUE width, VALUE height, VALUE xstep, VALUE ystep, VALUE painttype)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_begin_pattern(pdf, NUM2DBL(width), NUM2DBL(height), NUM2DBL(xstep), NUM2DBL(ystep), NUM2INT(painttype));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Deprecated, use PDF_begin_template_ext().. */
static VALUE
begin_template(VALUE self, VALUE width, VALUE height)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_begin_template(pdf, NUM2DBL(width), NUM2DBL(height));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Start a template definition.  Returns: A template handle. . */
static VALUE
begin_template_ext(VALUE self, VALUE width, VALUE height, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_begin_template_ext(pdf, NUM2DBL(width), NUM2DBL(height), CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Draw a circle.. */
static VALUE
circle(VALUE self, VALUE x, VALUE y, VALUE r)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_circle(pdf, NUM2DBL(x), NUM2DBL(y), NUM2DBL(r));
    } pdf_catch;
    
    return self;
}

    
/* Use the current path as clipping path, and terminate the path.. */
static VALUE
clip(VALUE self)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_clip(pdf);
    } pdf_catch;
    
    return self;
}

    
/* Close an image.. */
static VALUE
close_image(VALUE self, VALUE image)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_close_image(pdf, NUM2INT(image));
    } pdf_catch;
    
    return self;
}

    
/* Deprecated, use PDF_close_pdi_document().. */
static VALUE
close_pdi(VALUE self, VALUE doc)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_close_pdi(pdf, NUM2INT(doc));
    } pdf_catch;
    
    return self;
}

    
/* Close all open PDI page handles, and close the input PDF document.. */
static VALUE
close_pdi_document(VALUE self, VALUE doc)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_close_pdi_document(pdf, NUM2INT(doc));
    } pdf_catch;
    
    return self;
}

    
/* Close the page handle and free all page-related resources.. */
static VALUE
close_pdi_page(VALUE self, VALUE page)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_close_pdi_page(pdf, NUM2INT(page));
    } pdf_catch;
    
    return self;
}

    
/* Close the current path.. */
static VALUE
closepath(VALUE self)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_closepath(pdf);
    } pdf_catch;
    
    return self;
}

    
/* Close the path, fill, and stroke it.. */
static VALUE
closepath_fill_stroke(VALUE self)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_closepath_fill_stroke(pdf);
    } pdf_catch;
    
    return self;
}

    
/* Close the path, and stroke it.. */
static VALUE
closepath_stroke(VALUE self)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_closepath_stroke(pdf);
    } pdf_catch;
    
    return self;
}

    
/* Apply a transformation matrix to the current coordinate system.. */
static VALUE
concat(VALUE self, VALUE a, VALUE b, VALUE c, VALUE d, VALUE e, VALUE f)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_concat(pdf, NUM2DBL(a), NUM2DBL(b), NUM2DBL(c), NUM2DBL(d), NUM2DBL(e), NUM2DBL(f));
    } pdf_catch;
    
    return self;
}

    
/* Same as PDF_continue_text(), but with explicit string length.. */
static VALUE
continue_text(VALUE self, VALUE text)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_continue_text2(pdf, CHAR(text), LEN(text));
    } pdf_catch;
    
    return self;
}

    
/* Create an action which can be applied to various objects and events. Returns: An action handle.. */
static VALUE
create_action(VALUE self, VALUE type, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_create_action(pdf, CHAR(type), CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Create a rectangular annotation on the current page.. */
static VALUE
create_annotation(VALUE self, VALUE llx, VALUE lly, VALUE urx, VALUE ury, VALUE type, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_create_annotation(pdf, NUM2DBL(llx), NUM2DBL(lly), NUM2DBL(urx), NUM2DBL(ury), CHAR(type), CHAR(optlist));
    } pdf_catch;
    
    return self;
}

    
/* Create a bookmark subject to various options. Returns: A handle for the generated bookmark.. */
static VALUE
create_bookmark(VALUE self, VALUE text, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_create_bookmark(pdf, CHAR(text), LEN(text), CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Create a form field on the current page subject to various options.. */
static VALUE
create_field(VALUE self, VALUE llx, VALUE lly, VALUE urx, VALUE ury, VALUE name, VALUE type, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_create_field(pdf, NUM2DBL(llx), NUM2DBL(lly), NUM2DBL(urx), NUM2DBL(ury), CHAR(name), LEN(name), CHAR(type), CHAR(optlist));
    } pdf_catch;
    
    return self;
}

    
/* Create a form field group subject to various options. Returns: A graphics state handle.. */
static VALUE
create_fieldgroup(VALUE self, VALUE name, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_create_fieldgroup(pdf, CHAR(name), LEN(name), CHAR(optlist));
    } pdf_catch;
    
    return self;
}

    
/* Create a graphics state object subject to various options.. */
static VALUE
create_gstate(VALUE self, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_create_gstate(pdf, CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Create a named virtual read-only file from data provided in memory.. */
static VALUE
create_pvf(VALUE self, VALUE filename, VALUE data, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_create_pvf(pdf, CHAR(filename), 0, CHAR(data), LEN(data), CHAR(optlist));
    } pdf_catch;
    
    return self;
}

    
/* Create a Textflow object from text contents, inline options, and explicit options.  Returns: A Textflow handle, or -1 (in PHP: 0) on error.. */
static VALUE
create_textflow(VALUE self, VALUE text, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_create_textflow(pdf, CHAR(text), LEN(text), CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Draw a Bezier curve from the current point, using 3 more control points.. */
static VALUE
curveto(VALUE self, VALUE x_1, VALUE y_1, VALUE x_2, VALUE y_2, VALUE x_3, VALUE y_3)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_curveto(pdf, NUM2DBL(x_1), NUM2DBL(y_1), NUM2DBL(x_2), NUM2DBL(y_2), NUM2DBL(x_3), NUM2DBL(y_3));
    } pdf_catch;
    
    return self;
}

    
/* Create a new layer definition (requires PDF 1.5). Returns: A layer handle.. */
static VALUE
define_layer(VALUE self, VALUE name, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_define_layer(pdf, CHAR(name), LEN(name), CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Delete a named virtual file and free its data structures (but not the contents). Returns: -1 (in PHP: 0) if the virtual file exists but is locked, and 1 otherwise.. */
static VALUE
delete_pvf(VALUE self, VALUE filename)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_delete_pvf(pdf, CHAR(filename), 0);
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Delete a table and all associated data structures.. */
static VALUE
delete_table(VALUE self, VALUE table, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_delete_table(pdf, NUM2INT(table), CHAR(optlist));
    } pdf_catch;
    
    return self;
}

    
/* Delete a textflow and all associated data structures.. */
static VALUE
delete_textflow(VALUE self, VALUE textflow)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_delete_textflow(pdf, NUM2INT(textflow));
    } pdf_catch;
    
    return self;
}

    
/* Add a glyph name and/or Unicode value to a custom encoding.. */
static VALUE
encoding_set_char(VALUE self, VALUE encoding, VALUE slot, VALUE glyphname, VALUE uv)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_encoding_set_char(pdf, CHAR(encoding), NUM2INT(slot), CHAR(glyphname), NUM2INT(uv));
    } pdf_catch;
    
    return self;
}

    
/* Close the generated PDF document and apply various options.. */
static VALUE
end_document(VALUE self, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_end_document(pdf, CHAR(optlist));
    } pdf_catch;
    
    return self;
}

    
/* Terminate a Type 3 font definition.. */
static VALUE
end_font(VALUE self)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_end_font(pdf);
    } pdf_catch;
    
    return self;
}

    
/* Terminate a glyph definition for a Type 3 font.. */
static VALUE
end_glyph(VALUE self)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_end_glyph(pdf);
    } pdf_catch;
    
    return self;
}

    
/* Close a structure element or other content item.. */
static VALUE
end_item(VALUE self, VALUE id)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_end_item(pdf, NUM2INT(id));
    } pdf_catch;
    
    return self;
}

    
/* Deactivate all active layers (requires PDF 1.5).. */
static VALUE
end_layer(VALUE self)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_end_layer(pdf);
    } pdf_catch;
    
    return self;
}

    
/* End the least recently opened marked content sequence (unsupported).. */
static VALUE
end_mc(VALUE self)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_end_mc(pdf);
    } pdf_catch;
    
    return self;
}

    
/* Finish a page, and apply various options.. */
static VALUE
end_page_ext(VALUE self, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_end_page_ext(pdf, CHAR(optlist));
    } pdf_catch;
    
    return self;
}

    
/* Finish a pattern definition.. */
static VALUE
end_pattern(VALUE self)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_end_pattern(pdf);
    } pdf_catch;
    
    return self;
}

    
/* Finish a template definition.. */
static VALUE
end_template(VALUE self)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_end_template(pdf);
    } pdf_catch;
    
    return self;
}

    
/* End the current path without filling or stroking it.. */
static VALUE
endpath(VALUE self)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_endpath(pdf);
    } pdf_catch;
    
    return self;
}

    
/* Fill the interior of the path with the current fill color.. */
static VALUE
fill(VALUE self)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_fill(pdf);
    } pdf_catch;
    
    return self;
}

    
/* Fill an image block with variable data according to its properties. Returns: -1 (in PHP: 0) on error, and 1 otherwise.. */
static VALUE
fill_imageblock(VALUE self, VALUE page, VALUE blockname, VALUE image, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_fill_imageblock(pdf, NUM2INT(page), CHAR(blockname), NUM2INT(image), CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Fill a PDF block with variable data according to its properties. Returns: -1 (in PHP: 0) on error, and 1 otherwise.. */
static VALUE
fill_pdfblock(VALUE self, VALUE page, VALUE blockname, VALUE contents, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_fill_pdfblock(pdf, NUM2INT(page), CHAR(blockname), NUM2INT(contents), CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Fill and stroke the path with the current fill and stroke color.. */
static VALUE
fill_stroke(VALUE self)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_fill_stroke(pdf);
    } pdf_catch;
    
    return self;
}

    
/* Fill a text block with variable data according to its properties. Returns: -1 (in PHP: 0) on error, and 1 otherwise.. */
static VALUE
fill_textblock(VALUE self, VALUE page, VALUE blockname, VALUE text, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_fill_textblock(pdf, NUM2INT(page), CHAR(blockname), CHAR(text), LEN(text), CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Place an image or template on the page, subject to various options.. */
static VALUE
fit_image(VALUE self, VALUE image, VALUE x, VALUE y, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_fit_image(pdf, NUM2INT(image), NUM2DBL(x), NUM2DBL(y), CHAR(optlist));
    } pdf_catch;
    
    return self;
}

    
/* Place an imported PDF page on the page subject to various options.. */
static VALUE
fit_pdi_page(VALUE self, VALUE page, VALUE x, VALUE y, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_fit_pdi_page(pdf, NUM2INT(page), NUM2DBL(x), NUM2DBL(y), CHAR(optlist));
    } pdf_catch;
    
    return self;
}

    
/* Fully or partially place a table on the page.  Returns: A string which specifies the reason for returning.. */
static VALUE
fit_table(VALUE self, VALUE table, VALUE llx, VALUE lly, VALUE urx, VALUE ury, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    const char *ret = NULL;

    pdf_try {
	ret = PDF_fit_table(pdf, NUM2INT(table), NUM2DBL(llx), NUM2DBL(lly), NUM2DBL(urx), NUM2DBL(ury), CHAR(optlist));
    } pdf_catch;
    
    return rb_str_new2(ret);
}

    
/* Format the next portion of a textflow into a rectangular area. Returns: A string which specifies the reason for returning.. */
static VALUE
fit_textflow(VALUE self, VALUE textflow, VALUE llx, VALUE lly, VALUE urx, VALUE ury, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    const char *ret = NULL;

    pdf_try {
	ret = PDF_fit_textflow(pdf, NUM2INT(textflow), NUM2DBL(llx), NUM2DBL(lly), NUM2DBL(urx), NUM2DBL(ury), CHAR(optlist));
    } pdf_catch;
    
    return rb_str_new2(ret);
}

    
/* Place a single line of text at position (x, y) subject to various options.. */
static VALUE
fit_textline(VALUE self, VALUE text, VALUE x, VALUE y, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_fit_textline(pdf, CHAR(text), LEN(text), NUM2DBL(x), NUM2DBL(y), CHAR(optlist));
    } pdf_catch;
    
    return self;
}

    
/* Get the name of the API function which threw the last exception or failed. Returns: Name of an API function.. */
static VALUE
get_apiname(VALUE self)
{
    PDF *pdf = get_pdf(self);
    const char *ret = NULL;

    pdf_try {
	ret = PDF_get_apiname(pdf);
    } pdf_catch;
    
    return rb_str_new2(ret);
}

    
/* Get the contents of the PDF output buffer. Returns: A buffer full of binary PDF data for consumption by the client.. */
static VALUE
get_buffer(VALUE self)
{
    PDF *pdf = get_pdf(self);
    long size = -1;
    const char *ret = NULL;


    pdf_try {
	ret = PDF_get_buffer(pdf, &size);
    } pdf_catch;
    
    return rb_str_new(ret, size);
}

    
/* Get the text of the last thrown exception or the reason of a failed function call. Returns: Text containing the description of the most recent error condition.. */
static VALUE
get_errmsg(VALUE self)
{
    PDF *pdf = get_pdf(self);
    const char *ret = NULL;

    pdf_try {
	ret = PDF_get_errmsg(pdf);
    } pdf_catch;
    
    return rb_str_new2(ret);
}

    
/* Get the number of the last thrown exception or the reason of a failed function call. Returns: The error code of the most recent error condition.. */
static VALUE
get_errnum(VALUE self)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_get_errnum(pdf);
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Get the contents of some PDFlib parameter with string type. Returns: The string value of the parameter as a hypertext string.. */
static VALUE
get_parameter(VALUE self, VALUE key, VALUE modifier)
{
    PDF *pdf = get_pdf(self);
    const char *ret = NULL;

    pdf_try {
	ret = PDF_get_parameter(pdf, CHAR(key), NUM2DBL(modifier));
    } pdf_catch;
    
    return rb_str_new2(ret);
}

    
/* Deprecated, use PDF_pcos_get_string().. */
static VALUE
get_pdi_parameter(VALUE self, VALUE key, VALUE doc, VALUE page, VALUE reserved)
{
    PDF *pdf = get_pdf(self);
    int len = -1;
    const char *ret = NULL;


    pdf_try {
	ret = PDF_get_pdi_parameter(pdf, CHAR(key), NUM2INT(doc), NUM2INT(page), NUM2INT(reserved), &len);
    } pdf_catch;
    
    return rb_str_new(ret, len);
}

    
/* Deprecated, use PDF_pcos_get_number().. */
static VALUE
get_pdi_value(VALUE self, VALUE key, VALUE doc, VALUE page, VALUE reserved)
{
    PDF *pdf = get_pdf(self);
    double ret = 0;

    pdf_try {
	ret = PDF_get_pdi_value(pdf, CHAR(key), NUM2INT(doc), NUM2INT(page), NUM2INT(reserved));
    } pdf_catch;
    
    return rb_float_new(ret);
}

    
/* Get the value of some PDFlib parameter with numerical type. Returns: The numerical value of the parameter.. */
static VALUE
get_value(VALUE self, VALUE key, VALUE modifier)
{
    PDF *pdf = get_pdf(self);
    double ret = 0;

    pdf_try {
	ret = PDF_get_value(pdf, CHAR(key), NUM2DBL(modifier));
    } pdf_catch;
    
    return rb_float_new(ret);
}

    
/* Query detailed information about a loaded font.  Returns: The value of some font property as requested by keyword.. */
static VALUE
info_font(VALUE self, VALUE font, VALUE keyword, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    double ret = 0;

    pdf_try {
	ret = PDF_info_font(pdf, NUM2INT(font), CHAR(keyword), CHAR(optlist));
    } pdf_catch;
    
    return rb_float_new(ret);
}

    
/* Query information about a matchbox on the current page. Returns: The value of some matchbox parameter as requested by keyword.. */
static VALUE
info_matchbox(VALUE self, VALUE boxname, VALUE num, VALUE keyword)
{
    PDF *pdf = get_pdf(self);
    double ret = 0;

    pdf_try {
	ret = PDF_info_matchbox(pdf, CHAR(boxname), 0, NUM2INT(num), CHAR(keyword));
    } pdf_catch;
    
    return rb_float_new(ret);
}

    
/* Retrieve table information related to the most recently placed table instance. Returns: The value of some table parameter as requested by keyword.. */
static VALUE
info_table(VALUE self, VALUE table, VALUE keyword)
{
    PDF *pdf = get_pdf(self);
    double ret = 0;

    pdf_try {
	ret = PDF_info_table(pdf, NUM2INT(table), CHAR(keyword));
    } pdf_catch;
    
    return rb_float_new(ret);
}

    
/* Query the current state of a Textflow. Returns: The value of some Textflow parameter as requested by keyword.. */
static VALUE
info_textflow(VALUE self, VALUE textflow, VALUE keyword)
{
    PDF *pdf = get_pdf(self);
    double ret = 0;

    pdf_try {
	ret = PDF_info_textflow(pdf, NUM2INT(textflow), CHAR(keyword));
    } pdf_catch;
    
    return rb_float_new(ret);
}

    
/* Query geometrical sizes of a textline at position (0, 0).. */
static VALUE
info_textline(VALUE self, VALUE text, VALUE keyword, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    double ret = 0;

    pdf_try {
	ret = PDF_info_textline(pdf, CHAR(text), LEN(text), CHAR(keyword), CHAR(optlist));
    } pdf_catch;
    
    return rb_float_new(ret);
}

    
/* Perform textline formatting and query the resulting metrics. Returns: The value of some text metric value as requested by keyword.. */
static VALUE
initgraphics(VALUE self)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_initgraphics(pdf);
    } pdf_catch;
    
    return self;
}

    
/* Draw a line from the current point to another point.. */
static VALUE
lineto(VALUE self, VALUE x, VALUE y)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_lineto(pdf, NUM2DBL(x), NUM2DBL(y));
    } pdf_catch;
    
    return self;
}

    
/* Search for a font and prepare it for later use.  Returns: A font handle.. */
static VALUE
load_font(VALUE self, VALUE fontname, VALUE encoding, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_load_font(pdf, CHAR(fontname), 0, CHAR(encoding), CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Search for an ICC profile, and prepare it for later use. Returns: A profile handle.. */
static VALUE
load_iccprofile(VALUE self, VALUE profilename, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_load_iccprofile(pdf, CHAR(profilename), 0, CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Open a disk-based or virtual image file subject to various options. Returns: An image handle, or -1 (in PHP: 0) on error.. */
static VALUE
load_image(VALUE self, VALUE imagetype, VALUE filename, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_load_image(pdf, CHAR(imagetype), CHAR(filename), 0, CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Find a built-in spot color name, or make a named spot color from the current fill color. Returns: A color handle.. */
static VALUE
makespotcolor(VALUE self, VALUE spotname)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_makespotcolor(pdf, CHAR(spotname), 0);
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Set the current point.. */
static VALUE
moveto(VALUE self, VALUE x, VALUE y)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_moveto(pdf, NUM2DBL(x), NUM2DBL(y));
    } pdf_catch;
    
    return self;
}

    
/* Open a disk-based or virtual PDF document and prepare it for later use. Returns: A PDI document handle.. */
static VALUE
open_pdi_document(VALUE self, VALUE filename, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_open_pdi_document(pdf, CHAR(filename), 0, CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Prepare a page for later use with PDF_fit_pdi_page(). Returns: A page handle.. */
static VALUE
open_pdi_page(VALUE self, VALUE doc, VALUE pagenumber, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_open_pdi_page(pdf, NUM2INT(doc), NUM2INT(pagenumber), CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Get the value of a pCOS path with type number or boolean. Returns: The numerical value of the object identified by the pCOS path.. */
static VALUE
pcos_get_number(VALUE self, VALUE doc, VALUE path)
{
    PDF *pdf = get_pdf(self);
    double ret = 0;

    pdf_try {
	ret = PDF_pcos_get_number(pdf, NUM2INT(doc), "%s", CHAR(path));
    } pdf_catch;
    
    return rb_float_new(ret);
}

    
/* Get the value of a pCOS path with type name, string or boolean. Returns: A string with the value of the object identified by the pCOS path.. */
static VALUE
pcos_get_string(VALUE self, VALUE doc, VALUE path)
{
    PDF *pdf = get_pdf(self);
    const char *ret = NULL;

    pdf_try {
	ret = PDF_pcos_get_string(pdf, NUM2INT(doc), "%s", CHAR(path));
    } pdf_catch;
    
    return rb_str_new2(ret);
}

    
/* Get the contents of a pCOS path with type stream, fstream, or string. Returns: The unencrypted data contained in the stream or string.. */
static VALUE
pcos_get_stream(VALUE self, VALUE doc, VALUE optlist, VALUE path)
{
    PDF *pdf = get_pdf(self);
    int length = -1;
    const char *ret = NULL;


    pdf_try {
	ret = PDF_pcos_get_stream(pdf, NUM2INT(doc), &length, CHAR(optlist), "%s", CHAR(path));
    } pdf_catch;
    
    return rb_str_new(ret, length);
}

    
/* Process certain elements of an imported PDF document. Returns: -1 (in PHP: 0) on error, and 1 otherwise.. */
static VALUE
process_pdi(VALUE self, VALUE doc, VALUE page, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_process_pdi(pdf, NUM2INT(doc), NUM2INT(page), CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Draw a rectangle.. */
static VALUE
rect(VALUE self, VALUE x, VALUE y, VALUE width, VALUE height)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_rect(pdf, NUM2DBL(x), NUM2DBL(y), NUM2DBL(width), NUM2DBL(height));
    } pdf_catch;
    
    return self;
}

    
/* Restore the most recently saved graphics state from the stack.. */
static VALUE
restore(VALUE self)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_restore(pdf);
    } pdf_catch;
    
    return self;
}

    
/* Resume a page to add more content to it.. */
static VALUE
resume_page(VALUE self, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_resume_page(pdf, CHAR(optlist));
    } pdf_catch;
    
    return self;
}

    
/* Rotate the coordinate system.. */
static VALUE
rotate(VALUE self, VALUE phi)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_rotate(pdf, NUM2DBL(phi));
    } pdf_catch;
    
    return self;
}

    
/* Save the current graphics state to a stack.. */
static VALUE
save(VALUE self)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_save(pdf);
    } pdf_catch;
    
    return self;
}

    
/* Scale the coordinate system.. */
static VALUE
scale(VALUE self, VALUE sx, VALUE sy)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_scale(pdf, NUM2DBL(sx), NUM2DBL(sy));
    } pdf_catch;
    
    return self;
}

    
/* Activate a graphics state object.. */
static VALUE
set_gstate(VALUE self, VALUE gstate)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_set_gstate(pdf, NUM2INT(gstate));
    } pdf_catch;
    
    return self;
}

    
/* Like PDF_set_info(), but with explicit string length.. */
static VALUE
set_info(VALUE self, VALUE key, VALUE value)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_set_info2(pdf, CHAR(key), CHAR(value), LEN(value));
    } pdf_catch;
    
    return self;
}

    
/* Define hierarchical, group, and lock conditions among layers (requires PDF 1.5).. */
static VALUE
set_layer_dependency(VALUE self, VALUE type, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_set_layer_dependency(pdf, CHAR(type), CHAR(optlist));
    } pdf_catch;
    
    return self;
}

    
/* Set some PDFlib parameter with string type.. */
static VALUE
set_parameter(VALUE self, VALUE key, VALUE value)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_set_parameter(pdf, CHAR(key), CHAR(value));
    } pdf_catch;
    
    return self;
}

    
/* Set the position for text output on the page.. */
static VALUE
set_text_pos(VALUE self, VALUE x, VALUE y)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_set_text_pos(pdf, NUM2DBL(x), NUM2DBL(y));
    } pdf_catch;
    
    return self;
}

    
/* Set the value of some PDFlib parameter with numerical type.. */
static VALUE
set_value(VALUE self, VALUE key, VALUE value)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_set_value(pdf, CHAR(key), NUM2DBL(value));
    } pdf_catch;
    
    return self;
}

    
/* Set the current color space and color.. */
static VALUE
setcolor(VALUE self, VALUE fstype, VALUE colorspace, VALUE c1, VALUE c2, VALUE c3, VALUE c4)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_setcolor(pdf, CHAR(fstype), CHAR(colorspace), NUM2DBL(c1), NUM2DBL(c2), NUM2DBL(c3), NUM2DBL(c4));
    } pdf_catch;
    
    return self;
}

    
/* Set the current dash pattern.. */
static VALUE
setdash(VALUE self, VALUE b, VALUE w)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_setdash(pdf, NUM2DBL(b), NUM2DBL(w));
    } pdf_catch;
    
    return self;
}

    
/* Set a dash pattern defined by an option list.. */
static VALUE
setdashpattern(VALUE self, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_setdashpattern(pdf, CHAR(optlist));
    } pdf_catch;
    
    return self;
}

    
/* Set the flatness parameter.. */
static VALUE
setflat(VALUE self, VALUE flatness)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_setflat(pdf, NUM2DBL(flatness));
    } pdf_catch;
    
    return self;
}

    
/* Set the current font in the specified size.. */
static VALUE
setfont(VALUE self, VALUE font, VALUE fontsize)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_setfont(pdf, NUM2INT(font), NUM2DBL(fontsize));
    } pdf_catch;
    
    return self;
}

    
/* Set the linecap parameter.. */
static VALUE
setlinecap(VALUE self, VALUE linecap)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_setlinecap(pdf, NUM2INT(linecap));
    } pdf_catch;
    
    return self;
}

    
/* Set the linejoin parameter.. */
static VALUE
setlinejoin(VALUE self, VALUE linejoin)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_setlinejoin(pdf, NUM2INT(linejoin));
    } pdf_catch;
    
    return self;
}

    
/* Set the current linewidth.. */
static VALUE
setlinewidth(VALUE self, VALUE width)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_setlinewidth(pdf, NUM2DBL(width));
    } pdf_catch;
    
    return self;
}

    
/* Explicitly set the current transformation matrix.. */
static VALUE
setmatrix(VALUE self, VALUE a, VALUE b, VALUE c, VALUE d, VALUE e, VALUE f)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_setmatrix(pdf, NUM2DBL(a), NUM2DBL(b), NUM2DBL(c), NUM2DBL(d), NUM2DBL(e), NUM2DBL(f));
    } pdf_catch;
    
    return self;
}

    
/* Set the miter limit.. */
static VALUE
setmiterlimit(VALUE self, VALUE miter)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_setmiterlimit(pdf, NUM2DBL(miter));
    } pdf_catch;
    
    return self;
}

    
/* Define a blend from the current fill color to another color (requires PDF 1.4 or above).. */
static VALUE
shading(VALUE self, VALUE shtype, VALUE x_0, VALUE y_0, VALUE x_1, VALUE y_1, VALUE c_1, VALUE c_2, VALUE c_3, VALUE c_4, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_shading(pdf, CHAR(shtype), NUM2DBL(x_0), NUM2DBL(y_0), NUM2DBL(x_1), NUM2DBL(y_1), NUM2DBL(c_1), NUM2DBL(c_2), NUM2DBL(c_3), NUM2DBL(c_4), CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Define a shading pattern using a shading object (requires PDF 1.4). Returns: A shading handle.. */
static VALUE
shading_pattern(VALUE self, VALUE shading, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    int ret = 0;

    pdf_try {
	ret = PDF_shading_pattern(pdf, NUM2INT(shading), CHAR(optlist));
    } pdf_catch;
    
    return INT2NUM(ret);
}

    
/* Fill an area with a shading, based on a shading object (requires PDF 1.4).. */
static VALUE
shfill(VALUE self, VALUE shading)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_shfill(pdf, NUM2INT(shading));
    } pdf_catch;
    
    return self;
}

    
/* Same as PDF_show() but with explicit string length.. */
static VALUE
show(VALUE self, VALUE text)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_show2(pdf, CHAR(text), LEN(text));
    } pdf_catch;
    
    return self;
}

    
/* Same as PDF_show_xy() but with explicit string length.. */
static VALUE
show_xy(VALUE self, VALUE text, VALUE x, VALUE y)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_show_xy2(pdf, CHAR(text), LEN(text), NUM2DBL(x), NUM2DBL(y));
    } pdf_catch;
    
    return self;
}

    
/* Skew the coordinate system.. */
static VALUE
skew(VALUE self, VALUE alpha, VALUE beta)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_skew(pdf, NUM2DBL(alpha), NUM2DBL(beta));
    } pdf_catch;
    
    return self;
}

    
/* Same as PDF_stringwidth(), but with explicit string length.. */
static VALUE
stringwidth(VALUE self, VALUE text, VALUE font, VALUE fontsize)
{
    PDF *pdf = get_pdf(self);
    double ret = 0;

    pdf_try {
	ret = PDF_stringwidth2(pdf, CHAR(text), LEN(text), NUM2INT(font), NUM2DBL(fontsize));
    } pdf_catch;
    
    return rb_float_new(ret);
}

    
/* Stroke the path with the current color and line width, and clear it.. */
static VALUE
stroke(VALUE self)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_stroke(pdf);
    } pdf_catch;
    
    return self;
}

    
/* Suspend the current page so that it can later be resumed.. */
static VALUE
suspend_page(VALUE self, VALUE optlist)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_suspend_page(pdf, CHAR(optlist));
    } pdf_catch;
    
    return self;
}

    
/* Translate the origin of the coordinate system.. */
static VALUE
translate(VALUE self, VALUE tx, VALUE ty)
{
    PDF *pdf = get_pdf(self);
    pdf_try {
	PDF_translate(pdf, NUM2DBL(tx), NUM2DBL(ty));
    } pdf_catch;
    
    return self;
}
#endif /* defined(_WRAP_CODE) */
#if defined(_WRAP_METHODS)
    rb_define_method(cPDFlib, "activate_item", activate_item, 1);
    rb_define_method(cPDFlib, "create_3dview", create_3dview, 2);
    rb_define_method(cPDFlib, "load_3ddata", load_3ddata, 2);
    rb_define_method(cPDFlib, "add_nameddest", add_nameddest, 2);
    rb_define_method(cPDFlib, "add_table_cell", add_table_cell, 5);
    rb_define_method(cPDFlib, "add_textflow", add_textflow, 3);
    rb_define_method(cPDFlib, "add_thumbnail", add_thumbnail, 1);
    rb_define_method(cPDFlib, "arc", arc, 5);
    rb_define_method(cPDFlib, "arcn", arcn, 5);
    rb_define_method(cPDFlib, "begin_document", begin_document, 2);
    rb_define_method(cPDFlib, "begin_font", begin_font, 8);
    rb_define_method(cPDFlib, "begin_glyph", begin_glyph, 6);
    rb_define_method(cPDFlib, "begin_item", begin_item, 2);
    rb_define_method(cPDFlib, "begin_layer", begin_layer, 1);
    rb_define_method(cPDFlib, "begin_page_ext", begin_page_ext, 3);
    rb_define_method(cPDFlib, "begin_pattern", begin_pattern, 5);
    rb_define_method(cPDFlib, "begin_template", begin_template, 2);
    rb_define_method(cPDFlib, "begin_template_ext", begin_template_ext, 3);
    rb_define_method(cPDFlib, "circle", circle, 3);
    rb_define_method(cPDFlib, "clip", clip, 0);
    rb_define_method(cPDFlib, "close_image", close_image, 1);
    rb_define_method(cPDFlib, "close_pdi", close_pdi, 1);
    rb_define_method(cPDFlib, "close_pdi_document", close_pdi_document, 1);
    rb_define_method(cPDFlib, "close_pdi_page", close_pdi_page, 1);
    rb_define_method(cPDFlib, "closepath", closepath, 0);
    rb_define_method(cPDFlib, "closepath_fill_stroke", closepath_fill_stroke, 0);
    rb_define_method(cPDFlib, "closepath_stroke", closepath_stroke, 0);
    rb_define_method(cPDFlib, "concat", concat, 6);
    rb_define_method(cPDFlib, "continue_text", continue_text, 1);
    rb_define_method(cPDFlib, "create_action", create_action, 2);
    rb_define_method(cPDFlib, "create_annotation", create_annotation, 6);
    rb_define_method(cPDFlib, "create_bookmark", create_bookmark, 2);
    rb_define_method(cPDFlib, "create_field", create_field, 7);
    rb_define_method(cPDFlib, "create_fieldgroup", create_fieldgroup, 2);
    rb_define_method(cPDFlib, "create_gstate", create_gstate, 1);
    rb_define_method(cPDFlib, "create_pvf", create_pvf, 3);
    rb_define_method(cPDFlib, "create_textflow", create_textflow, 2);
    rb_define_method(cPDFlib, "curveto", curveto, 6);
    rb_define_method(cPDFlib, "define_layer", define_layer, 2);
    rb_define_method(cPDFlib, "delete_pvf", delete_pvf, 1);
    rb_define_method(cPDFlib, "delete_table", delete_table, 2);
    rb_define_method(cPDFlib, "delete_textflow", delete_textflow, 1);
    rb_define_method(cPDFlib, "encoding_set_char", encoding_set_char, 4);
    rb_define_method(cPDFlib, "end_document", end_document, 1);
    rb_define_method(cPDFlib, "end_font", end_font, 0);
    rb_define_method(cPDFlib, "end_glyph", end_glyph, 0);
    rb_define_method(cPDFlib, "end_item", end_item, 1);
    rb_define_method(cPDFlib, "end_layer", end_layer, 0);
    rb_define_method(cPDFlib, "end_mc", end_mc, 0);
    rb_define_method(cPDFlib, "end_page_ext", end_page_ext, 1);
    rb_define_method(cPDFlib, "end_pattern", end_pattern, 0);
    rb_define_method(cPDFlib, "end_template", end_template, 0);
    rb_define_method(cPDFlib, "endpath", endpath, 0);
    rb_define_method(cPDFlib, "fill", fill, 0);
    rb_define_method(cPDFlib, "fill_imageblock", fill_imageblock, 4);
    rb_define_method(cPDFlib, "fill_pdfblock", fill_pdfblock, 4);
    rb_define_method(cPDFlib, "fill_stroke", fill_stroke, 0);
    rb_define_method(cPDFlib, "fill_textblock", fill_textblock, 4);
    rb_define_method(cPDFlib, "fit_image", fit_image, 4);
    rb_define_method(cPDFlib, "fit_pdi_page", fit_pdi_page, 4);
    rb_define_method(cPDFlib, "fit_table", fit_table, 6);
    rb_define_method(cPDFlib, "fit_textflow", fit_textflow, 6);
    rb_define_method(cPDFlib, "fit_textline", fit_textline, 4);
    rb_define_method(cPDFlib, "get_apiname", get_apiname, 0);
    rb_define_method(cPDFlib, "get_buffer", get_buffer, 0);
    rb_define_method(cPDFlib, "get_errmsg", get_errmsg, 0);
    rb_define_method(cPDFlib, "get_errnum", get_errnum, 0);
    rb_define_method(cPDFlib, "get_parameter", get_parameter, 2);
    rb_define_method(cPDFlib, "get_pdi_parameter", get_pdi_parameter, 4);
    rb_define_method(cPDFlib, "get_pdi_value", get_pdi_value, 4);
    rb_define_method(cPDFlib, "get_value", get_value, 2);
    rb_define_method(cPDFlib, "info_font", info_font, 3);
    rb_define_method(cPDFlib, "info_matchbox", info_matchbox, 3);
    rb_define_method(cPDFlib, "info_table", info_table, 2);
    rb_define_method(cPDFlib, "info_textflow", info_textflow, 2);
    rb_define_method(cPDFlib, "info_textline", info_textline, 3);
    rb_define_method(cPDFlib, "initgraphics", initgraphics, 0);
    rb_define_method(cPDFlib, "lineto", lineto, 2);
    rb_define_method(cPDFlib, "load_font", load_font, 3);
    rb_define_method(cPDFlib, "load_iccprofile", load_iccprofile, 2);
    rb_define_method(cPDFlib, "load_image", load_image, 3);
    rb_define_method(cPDFlib, "makespotcolor", makespotcolor, 1);
    rb_define_method(cPDFlib, "moveto", moveto, 2);
    rb_define_method(cPDFlib, "open_pdi_document", open_pdi_document, 2);
    rb_define_method(cPDFlib, "open_pdi_page", open_pdi_page, 3);
    rb_define_method(cPDFlib, "pcos_get_number", pcos_get_number, 2);
    rb_define_method(cPDFlib, "pcos_get_string", pcos_get_string, 2);
    rb_define_method(cPDFlib, "pcos_get_stream", pcos_get_stream, 3);
    rb_define_method(cPDFlib, "process_pdi", process_pdi, 3);
    rb_define_method(cPDFlib, "rect", rect, 4);
    rb_define_method(cPDFlib, "restore", restore, 0);
    rb_define_method(cPDFlib, "resume_page", resume_page, 1);
    rb_define_method(cPDFlib, "rotate", rotate, 1);
    rb_define_method(cPDFlib, "save", save, 0);
    rb_define_method(cPDFlib, "scale", scale, 2);
    rb_define_method(cPDFlib, "set_gstate", set_gstate, 1);
    rb_define_method(cPDFlib, "set_info", set_info, 2);
    rb_define_method(cPDFlib, "set_layer_dependency", set_layer_dependency, 2);
    rb_define_method(cPDFlib, "set_parameter", set_parameter, 2);
    rb_define_method(cPDFlib, "set_text_pos", set_text_pos, 2);
    rb_define_method(cPDFlib, "set_value", set_value, 2);
    rb_define_method(cPDFlib, "setcolor", setcolor, 6);
    rb_define_method(cPDFlib, "setdash", setdash, 2);
    rb_define_method(cPDFlib, "setdashpattern", setdashpattern, 1);
    rb_define_method(cPDFlib, "setflat", setflat, 1);
    rb_define_method(cPDFlib, "setfont", setfont, 2);
    rb_define_method(cPDFlib, "setlinecap", setlinecap, 1);
    rb_define_method(cPDFlib, "setlinejoin", setlinejoin, 1);
    rb_define_method(cPDFlib, "setlinewidth", setlinewidth, 1);
    rb_define_method(cPDFlib, "setmatrix", setmatrix, 6);
    rb_define_method(cPDFlib, "setmiterlimit", setmiterlimit, 1);
    rb_define_method(cPDFlib, "shading", shading, 10);
    rb_define_method(cPDFlib, "shading_pattern", shading_pattern, 2);
    rb_define_method(cPDFlib, "shfill", shfill, 1);
    rb_define_method(cPDFlib, "show", show, 1);
    rb_define_method(cPDFlib, "show_xy", show_xy, 3);
    rb_define_method(cPDFlib, "skew", skew, 2);
    rb_define_method(cPDFlib, "stringwidth", stringwidth, 3);
    rb_define_method(cPDFlib, "stroke", stroke, 0);
    rb_define_method(cPDFlib, "suspend_page", suspend_page, 1);
    rb_define_method(cPDFlib, "translate", translate, 2);
#endif /* defined(_WRAP_METHODS)*/
