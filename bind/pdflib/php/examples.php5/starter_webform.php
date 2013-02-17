<?php
/* $Id: starter_webform.php,v 1.1.2.1 2007/09/27 12:58:00 rjs Exp $
*
* Webform starter:
* create a linearized PDF (for fast delivery over the Web, also known
* as "fast Web view") which is encrypted and contains some form fields.
* A few lines of JavaScript are inserted as "page open" action to
* automatically populate the date field with the current date.
*
* required software: PDFlib/PDFlib+PDI/PPS 7
* required data: none
*/
$outfilename = "starter_webform.pdf";

$llx=150; $lly=550; $urx=350; $ury=575;

/* JavaScript for automatically filling the date into a form field */
$js = "var d = util.printd(\"mm/dd/yyyy\", new Date());" .
    "var date = this.getField(\"date\");" .
    "date.value = d;";

try {
    $p = new PDFlib();

    # This means we must check return values of load_font() etc.
    $p->set_parameter("errorpolicy", "return");

    /* Prevent changes with a master password */
    $optlist = "linearize masterpassword=pdflib permissions={nomodify}";

    if ($p->begin_document($outfilename, $optlist) == 0) {
	die("Error: " . $p->get_errmsg());
    }

    $p->set_info("Creator", "PDFlib starter sample");
    $p->set_info("Title", "starter_webform");

    $optlist = "script={" . $js . "}";
    $action = $p->create_action("JavaScript", $optlist);

    $optlist = "action={open=" . $action . "}";
    $p->begin_page_ext(595, 842, $optlist);

    $font = $p->load_font("Helvetica", "winansi", "");
    if ($font == 0) {
	die("Error: " . $p->get_errmsg());
    }
    $p->setfont($font, 24);

    $p->fit_textline("Date: ", 125, $lly+5, "position={right bottom}");

    /* The tooltip will be used as rollover text for the field */
    $optlist =
	"tooltip={Date (will be filled automatically)} " .
	"bordercolor={gray 0} font=" . $font;
    $p->create_field($llx, $lly, $urx, $ury, "date", "textfield", $optlist);

    $lly-=100; $ury-=100;
    $p->fit_textline("Name: ", 125, $lly+5, "position={right bottom}");

    $optlist = "tooltip={Enter your name here} " .
	"bordercolor={gray 0} font=" . $font;
    $p->create_field($llx, $lly, $urx, $ury, "name", "textfield", $optlist);

    $p->end_page_ext("");

    $p->end_document("");

    print "$outfilename generated";

}
catch (PDFlibException $e) {
    die("PDFlib exception occurred in starter_webform sample:\n" .
	"[" . $e->get_errnum() . "] " . $e->get_apiname() . ": " .
	$e->get_errmsg() . "\n");
}
catch (Exception $e) {
    die($e);
}

$p = 0;
?>
