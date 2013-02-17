<?php
/* $Id: starter_pdfmerge.php,v 1.1.2.2 2009/08/07 07:30:46 rjs Exp $
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

try {
    $p = new PDFlib();


    # This means we must check return values of load_font() etc.
    $p->set_parameter("errorpolicy", "return");

    $p->set_parameter("SearchPath", $searchpath);

    if ($p->begin_document($outfilename, "") == 0)
	die("Error: " . $p->get_errmsg());

    $p->set_info("Creator", "PDFlib starter sample");
    $p->set_info("Title", "starter_pdfmerge");

    foreach ($pdffiles as $pdffile) { 
	/* Open the input PDF */
	$indoc = $p->open_pdi_document($pdffile, "");
	if ($indoc == 0) {
	    printf("Error: %s\n", $p->get_errmsg());
	    continue;
	}

	$endpage = $p->pcos_get_number($indoc, "/Root/Pages/Count");

	/* Loop over all pages of the input document */
	for ($pageno = 1; $pageno <= $endpage; $pageno++) {
	    $page = $p->open_pdi_page($indoc, $pageno, "");

	    if ($page == 0) {
		printf("Error: %s\n", $p->get_errmsg());
		continue;
	    }
	    /* Dummy $page size; will be adjusted later */
	    $p->begin_page_ext(10, 10, "");

	    /* Create a bookmark with the file name */
	    if ($pageno == 1) {
		$p->create_bookmark($pdffile, "");
	    }

	    /* Place the imported $page on the output $page, and
	     * adjust the $page size
	     */
	    $p->fit_pdi_page($page, 0, 0, "adjustpage");
	    $p->close_pdi_page($page);

	    $p->end_page_ext("");
	}
	$p->close_pdi_document($indoc);
    }

    $p->end_document("");

    print "$outfilename generated";

}
catch (PDFlibException $e) {
    die("PDFlib exception occurred in starter_pdfmerge sample:\n" .
	"[" . $e->get_errnum() . "] " . $e->get_apiname() . ": " .
	$e->get_errmsg() . "\n");
}
catch (Exception $e) {
    die($e);
}

$p = 0;
?>
