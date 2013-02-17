<?php
/* $Id: starter_pdfa.php,v 1.3 2006/10/01 20:33:35 rjs Exp $
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

$p = PDF_new();

# This means we must check return values of load_font() etc.
PDF_set_parameter($p, "errorpolicy", "return");

PDF_set_parameter($p, "SearchPath", $searchpath);

/* we use "utf8" as textformat, this allows to use unicode encoding */
PDF_set_parameter($p, "textformat", "utf8");

/* PDF/A-1a requires Tagged PDF */
if (PDF_begin_document($p, $outfilename, "pdfa=PDF/A-1b:2005") == 0) {
    die("Error: " . PDF_get_errmsg($p));
}

/*
 * We use sRGB as output intent since it allows the color
 * spaces CIELab, ICC-based, grayscale, and RGB.
 *
 * If you need CMYK color you must use a CMYK output profile.
 */

PDF_load_iccprofile($p, "sRGB", "usage=outputintent");

PDF_set_info($p, "Creator", "PDFlib starter sample");
PDF_set_info($p, "Title", "starter_pdfa");

PDF_begin_page_ext($p, 595, 842, "");

/* $font embedding is required for PDF/A */
$font = PDF_load_font($p, "LuciduxSans-Oblique", "unicode", "embedding");
if ($font == 0) {
    die("Error: " . PDF_get_errmsg($p));
}
PDF_setfont($p, $font, 24);

PDF_fit_textline($p, "PDF/A-1b:2005 starter", 50, 700, "");

/* We can use an RGB $image since we already supplied an
 * output intent profile.
 */
$image = PDF_load_image($p, "auto", $imagefile, "");

if ($image == 0) {
    die("Error: " . PDF_get_errmsg($p));
}

/* Place the $image at the bottom of the page */
PDF_fit_image($p, $image, 0.0, 0.0, "scale=0.5");

PDF_end_page_ext($p, "");

PDF_end_document($p, "");

PDF_delete($p);

print "$outfilename generated";
?>
