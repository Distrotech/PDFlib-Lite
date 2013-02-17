<?php
/* $Id: starter_pdfa.php,v 1.1.2.2 2009/08/07 07:30:46 rjs Exp $
 *
 * PDF/A starter:
 * Create PDF/A-compliant output
 *
 * required software: PDFlib/PDFlib+PDI/PPS 7
 * required data: font file, image file
 */

/* This is where the data files are. Adjust as necessary. */
$searchpath = "../data";
$imagefile = "nesrin.jpg";
$outfilename = "starter_pdfa.pdf";

try {
    $p = new PDFlib();


    # This means we must check return values of load_font() etc.
    $p->set_parameter("errorpolicy", "return");

    $p->set_parameter("SearchPath", $searchpath);

    /* we use "utf8" as textformat, this allows to use unicode encoding */
    $p->set_parameter("textformat", "utf8");

    /* PDF/A-1a requires Tagged PDF */
    if ($p->begin_document($outfilename, "pdfa=PDF/A-1b:2005") == 0) {
	die("Error: " . $p->get_errmsg());
    }

    /*
     * We use sRGB as output intent since it allows the color
     * spaces CIELab, ICC-based, grayscale, and RGB.
     *
     * If you need CMYK color you must use a CMYK output profile.
     */

    $p->load_iccprofile("sRGB", "usage=outputintent");

    $p->set_info("Creator", "PDFlib starter sample");
    $p->set_info("Title", "starter_pdfa");

    $p->begin_page_ext(595, 842, "");

    /* $font embedding is required for PDF/A */
    $font = $p->load_font("LuciduxSans-Oblique", "unicode", "embedding");
    if ($font == 0) {
	die("Error: " . $p->get_errmsg());
    }
    $p->setfont($font, 24);

    $p->fit_textline("PDF/A-1b:2005 starter", 50, 700, "");

    /* We can use an RGB $image since we already supplied an
     * output intent profile.
     */
    $image = $p->load_image("auto", $imagefile, "");

    if ($image == 0) {
	die("Error: " . $p->get_errmsg());
    }

    /* Place the $image at the bottom of the page */
    $p->fit_image($image, 0.0, 0.0, "scale=0.5");

    $p->end_page_ext("");

    $p->end_document("");

    print "$outfilename generated";

}
catch (PDFlibException $e) {
    die("PDFlib exception occurred in starter_pdfa sample:\n" .
	"[" . $e->get_errnum() . "] " . $e->get_apiname() . ": " .
	$e->get_errmsg() . "\n");
}
catch (Exception $e) {
    die($e);
}

$p = 0;
?>
