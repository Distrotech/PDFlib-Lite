<?php
/* $Id: starter_pdfmerge.php,v 1.5.2.1 2007/08/08 15:09:41 rp Exp $
 *
 * PDF merge starter:
 * Merge pages from multiple PDF documents; interactive elements (e.g. 
 * bookmarks) will be dropped.
 *
 * required software: PDFlib+PDI/PPS 7
 * required data: PDF documents
 */

/* This is where the data files are. Adjust as necessary. */
$searchpath = "../data";
$outfilename = "starter_pdfmerge.pdf";

$pdffiles = array(
	"PDFlib-real-world.pdf",
	"PDFlib-datasheet.pdf",
	"TET-datasheet.pdf",
	"PLOP-datasheet.pdf",
	"pCOS-datasheet.pdf"
);

$p = PDF_new();

# This means we must check return values of load_font() etc.
PDF_set_parameter($p, "errorpolicy", "return");

PDF_set_parameter($p, "SearchPath", $searchpath);

if (PDF_begin_document($p, $outfilename, "") == 0)
    die("Error: " . PDF_get_errmsg($p));

PDF_set_info($p, "Creator", "PDFlib starter sample");
PDF_set_info($p, "Title", "starter_pdfmerge");

foreach ($pdffiles as $pdffile) { 
    /* Open the input PDF */
    $indoc = PDF_open_pdi_document($p, $pdffile, "");
    if ($indoc == 0) {
	printf("Error: %s\n", PDF_get_errmsg($p));
	continue;
    }

    $endpage = PDF_pcos_get_number($p, $indoc, "/Root/Pages/Count");

    /* Loop over all pages of the input document */
    for ($pageno = 1; $pageno <= $endpage; $pageno++) {
	$page = PDF_open_pdi_page($p, $indoc, $pageno, "");

	if ($page == 0) {
	    printf("Error: %s\n", PDF_get_errmsg($p));
	    continue;
	}
	/* Dummy $page size; will be adjusted later */
	PDF_begin_page_ext($p, 10, 10, "");

	/* Create a bookmark with the file name */
	if ($pageno == 1) {
	    PDF_create_bookmark($p, $pdffile, "");
	}

	/* Place the imported $page on the output $page, and
	 * adjust the $page size
	 */
	PDF_fit_pdi_page($p, $page, 0, 0, "adjustpage");
	PDF_close_pdi_page($p, $page);

	PDF_end_page_ext($p, "");
    }
    PDF_close_pdi_document($p, $indoc);
}

PDF_end_document($p, "");

PDF_delete($p);

print "$outfilename generated";
?>
