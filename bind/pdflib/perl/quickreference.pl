#!/usr/bin/perl
# $Id: quickreference.pl,v 1.26 2006/10/01 19:55:11 rjs Exp $
#
# PDFlib+PDI client: mini imposition demo
#

use pdflib_pl 7.0;

$infile = "reference.pdf";
# This is where font/image/PDF input files live. Adjust as necessary.
$searchpath = "../data";
$maxrow = 2;
$maxcol = 2;
$width = 500.0;
$height = 770.0;
$endpage = 0 ;

$p = PDF_new();
eval{
    # This means we must check return values of load_font() etc.
    PDF_set_parameter($p, "errorpolicy", "return");

    PDF_set_parameter($p, "SearchPath", $searchpath);

    # This line is required to avoid problems on Japanese systems
    PDF_set_parameter($p, "hypertextencoding", "winansi");

    if (PDF_begin_document($p, "quickreference.pdf", "") == -1) {
	die("Error: %s\n", PDF_get_errmsg($p));
    }

    PDF_set_info($p, "Creator", "quickreference.pl");
    PDF_set_info($p, "Author", "Thomas Merz");
    PDF_set_info($p, "Title", "mini imposition demo (Perl)");

    $manual = PDF_open_pdi_document($p, $infile, "");
    if ($manual == -1) {
	die("Error: %s\n", PDF_get_errmsg($p));
    }

    $row = 0;
    $col = 0;

    PDF_set_parameter($p, "topdown", "true");

    $endpage = PDF_pcos_get_number($p, $manual, "length:pages");

    for ($pageno = 1; $pageno <= $endpage; $pageno++) {
	if ($row == 0 && $col == 0) {
	    PDF_begin_page_ext($p, $width, $height, "");
	    $font = PDF_load_font($p, "Helvetica-Bold", "winansi", "");
	    PDF_setfont($p, $font, 18);
	    PDF_set_text_pos($p, 24, 24);
	    PDF_show($p, "PDFlib Quick Reference");
	}

	$page = PDF_open_pdi_page($p, $manual, $pageno, "");

	if ($page == -1) {
	    die("Error: %s\n", PDF_get_errmsg($p));
	}

	PDF_fit_pdi_page($p, $page, $width/$maxcol*$col, ($row + 1)
		* $height/$maxrow, "scale ". 1/$maxrow);
	PDF_close_pdi_page($p, $page);

	$col++;
	if ($col == $maxcol) {
	    $col = 0;
	    $row++;
	}
	if ($row == $maxrow) {
	    $row = 0;
	    PDF_end_page_ext($p, "");
	}
    }

    # finish the last partial page
    if ($row != 0 || $col != 0) {
	PDF_end_page_ext($p, "");
    }

    PDF_end_document($p, "");
    PDF_close_pdi_document($p, $manual);
};

if ($@) {
    printf("quickreference: PDFlib Exception occurred:\n");
    printf(" $@\n");
    exit;
}

PDF_delete($p);
