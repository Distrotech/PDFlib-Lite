# $Id: pdflib_pl.pm,v 1.25.2.1 2008/09/04 12:58:17 rjs Exp $
package pdflib_pl;
require Exporter;
require DynaLoader;
$VERSION=7.0;
@ISA = qw(Exporter DynaLoader);
package pdflibc;
bootstrap pdflib_pl;
var_pdflib_init();
@EXPORT = qw( );

# ---------- BASE METHODS -------------

package pdflib_pl;

sub TIEHASH {
    my ($classname,$obj) = @_;
    return bless $obj, $classname;
}

sub CLEAR { }

sub this {
    my $ptr = shift;
    return tied(%$ptr);
}


# ------- FUNCTION WRAPPERS --------

package pdflib_pl;
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
@EXPORT = qw(
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

);

# ------- VARIABLE STUBS --------

package pdflib_pl;

1;
