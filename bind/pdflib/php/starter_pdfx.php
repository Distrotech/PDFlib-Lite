<?php
/* $Id: starter_pdfx.php,v 1.7 2006/10/02 19:22:45 rjs Exp $
 *
 * PDF/X starter:
 * Create PDF/X-compliant output
 *
 * required software: PDFlib/PDFlib+PDI/PPS 7
 * required data: font file, image file, icc profile
 *                (see www.pdflib.com for ICC profiles)
 */

/* This is where the data files are. Adjust as necessary.*/
$searchpath = "../data";
$imagefile = "nesrin.jpg";
$outfilename = "starter_pdfx.pdf";

$p = PDF_new();

# This means we must check return values of load_font() etc.
PDF_set_parameter($p, "errorpolicy", "return");

PDF_set_parameter($p, "SearchPath", $searchpath);

/* we use "utf8" as textformat, this allows to use unicode encoding */
PDF_set_parameter($p, "textformat", "utf8");

if (PDF_begin_document($p, $outfilename, "pdfx=PDF/X-3:2002") == 0) {
    die("Error: " . PDF_get_errmsg($p));
}

PDF_set_info($p, "Creator", "PDFlib starter sample");
PDF_set_info($p, "Title", "starter_pdfx");

/*
 * You can use one of the Standard output intents (e.g. for SWOP
 * printing) which do not require an ICC profile:

PDF_load_iccprofile($p, "CGATS TR 001", "usage=outputintent");

 * However, if you use ICC or Lab color you must load an ICC
 * profile as output intent:
 */
if (PDF_load_iccprofile($p, "ISOcoated.icc", "usage=outputintent") == -1) {
    printf("Error: %s\n", PDF_get_errmsg($p));
    printf("Please install the ICC profile package from " .
	"www.pdflib.com to run the PDF/X starter sample.\n");
    PDF_delete(p);
    return(2);
}

PDF_begin_page_ext($p, 595, 842, "");

/* $font embedding is required for PDF/X */
$font = PDF_load_font($p, "LuciduxSans-Oblique", "unicode", "embedding");
if ($font == 0) {
    die("Error: " . PDF_get_errmsg($p));
}
PDF_setfont($p, $font, 24);

$spot = PDF_makespotcolor($p, "PANTONE 123 C");
PDF_setcolor($p, "fill", "spot", $spot, 1.0, 0.0, 0.0);
PDF_fit_textline($p, "PDF/X-3:2002 starter", 50, 700, "");

/* The RGB $image below needs an $icc profile; we use sRGB. */
$icc = PDF_load_iccprofile($p, "sRGB", "");
$image = PDF_load_image($p, "auto", $imagefile, "iccprofile=" . $icc);

if ($image == 0) {
    die("Error: " . PDF_get_errmsg($p));
}

PDF_fit_image($p, $image, 0.0, 0.0, "scale=0.5");

PDF_end_page_ext($p, "");

PDF_end_document($p, "");

PDF_delete($p);

print "$outfilename generated";
?>
