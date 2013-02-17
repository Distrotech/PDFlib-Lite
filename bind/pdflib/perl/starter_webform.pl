#!/usr/bin/perl
# $Id: starter_webform.pl,v 1.3.2.1 2008/12/25 13:28:41 rp Exp $
#
# Webform starter:
# create a linearized PDF (for fast delivery over the Web, also known
# as "fast Web view") which is encrypted and contains some form fields.
# A few lines of JavaScript are inserted as "page open" action to
# automatically populate the date field with the current date.
#
# required software: PDFlib/PDFlib+PDI/PPS 7
# required data: none

use pdflib_pl 7.0;

$outfilename = "starter_webform.pdf";

$llx=150; $lly=550; $urx=350; $ury=575;

# JavaScript for automatically filling the date into a form field
$js = "var d = util.printd(\"mm/dd/yyyy\", new Date());" .
    "var date = this.getField(\"date\");" .
    "date.value = d;";

$p = PDF_new();

eval {
    # This means we must check return values of load_font() etc.
    PDF_set_parameter($p, "errorpolicy", "return");

    # Prevent changes with a master password
    $optlist = "linearize masterpassword=pdflib permissions={nomodify}";

    if (PDF_begin_document($p, $outfilename, $optlist) == -1) {
	die("Error: " . PDF_get_errmsg($p));
    }

    PDF_set_info($p, "Creator", "PDFlib starter sample");
    PDF_set_info($p, "Title", "starter_webform");

    $optlist = "script={" . $js . "}";
    $action = PDF_create_action($p, "JavaScript", $optlist);

    $optlist = "action={open=" . $action . "}";
    PDF_begin_page_ext($p, 595, 842, $optlist);

    $font = PDF_load_font($p, "Helvetica", "winansi", "");
    if ($font == -1) {
	die("Error: %s\n", PDF_get_errmsg($p));
    }
    PDF_setfont($p, $font, 24);

    PDF_fit_textline($p, "Date: ", 125, $lly+5, "position={right bottom}");

    # The tooltip will be used as rollover text for the field
    $optlist =
	"tooltip={Date (will be filled automatically)} " .
	"bordercolor={gray 0} font=" . $font;
    PDF_create_field($p, $llx, $lly, $urx, $ury, "date", "textfield", $optlist);

    $lly-=100; $ury-=100;
    PDF_fit_textline($p, "Name: ", 125, $lly+5, "position={right bottom}");

    $optlist = "tooltip={Enter your name here} " .
	"bordercolor={gray 0} font=" . $font;
    PDF_create_field($p, $llx, $lly, $urx, $ury, "name", "textfield", $optlist);

    PDF_end_page_ext($p, "");

    PDF_end_document($p, "");

    PDF_delete($p);
};

if ($@) {
    printf("starter_webform: PDFlib Exception occurred:\n");
    printf(" $@\n");
    exit;
}
