#!/usr/bin/perl
# $Id: image.pl,v 1.23 2006/10/01 19:55:11 rjs Exp $
#
# PDFlib client: image example in Perl
#

use pdflib_pl 7.0;

# This is where font/image/PDF input files live. Adjust as necessary.
$searchpath = "../data";
$imagefile = "nesrin.jpg";

$p = PDF_new();

eval {
    # This means we must check return values of load_font() etc.
    PDF_set_parameter($p, "errorpolicy", "return");

    PDF_set_parameter($p, "SearchPath", $searchpath);

    # This line is required to avoid problems on Japanese systems
    PDF_set_parameter($p, "hypertextencoding", "winansi");

    if (PDF_begin_document($p, "image.pdf", "") == -1){
	die("Error: %s\n", PDF_get_errmsg($p));
    }

    PDF_set_info($p, "Creator", "image.pl");
    PDF_set_info($p, "Author", "Thomas Merz");
    PDF_set_info($p, "Title", "image sample (Perl)");

    $image = PDF_load_image($p, "auto", $imagefile, "");
    die "Couldn't open image '$imagefile'" if ($image == -1);

    # dummy page size, will be adjusted by PDF_fit_image()
    PDF_begin_page_ext($p, 10, 10, "");
    PDF_fit_image($p, $image, 0, 0, "adjustpage");
    PDF_close_image($p, $image);
    PDF_end_page_ext($p, "");

    PDF_end_document($p, "");
};

if ($@) {
    printf("image: PDFlib Exception occurred:\n");
    printf(" $@\n");
    exit;
}

PDF_delete($p);
