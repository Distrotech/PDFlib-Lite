<?php
/* $Id: starter_block.php,v 1.1.2.3 2009/08/07 07:30:46 rjs Exp $
 *
 * Block starter:
 * Import a PDF page containing, and process all blocks. The blocks are
 * retrieved via pCOS, and the block filling functions are used to
 * visualize the blocks on the output page. A real-world application would
 * of course fill the blocks with data retrieved from some external data
 * source.
 *
 * required software: PPS 7 or above
 * required data: input PDF
 */

/* This is where the data files are. Adjust as necessary. */
$searchpath = "../data";
$infile = "boilerplate.pdf";
$outfilename = "starter_block.pdf";

try {
    $p = new PDFlib();

    # This means we must check return values of load_font() etc.
    $p->set_parameter("errorpolicy", "return");

    $p->set_parameter("SearchPath", $searchpath);

    /* we use "utf8" as textformat, this allows to use unicode encoding */
    $p->set_parameter("textformat", "utf8");

    if ($p->begin_document($outfilename, "") == 0) {
	die("Error: " . $p->get_errmsg());
    }

    $p->set_info("Creator", "PDFlib starter sample");
    $p->set_info("Title", "starter_block");

    /* Open a PDF containing blocks */
    $indoc = $p->open_pdi_document($infile, "");
    if ($indoc == 0) {
	die("Error: " . $p->get_errmsg());
    }

    /* Open the first $page */
    $page = $p->open_pdi_page($indoc, 1, "");
    if ($page == 0) {
	die("Error: " . $p->get_errmsg());
    }

    $width = $p->pcos_get_number($indoc, "pages[0]/width");
    $height = $p->pcos_get_number($indoc, "pages[0]/height");

    $p->begin_page_ext($width, $height, "");

    /* Place the imported $page on the output $page */
    $p->fit_pdi_page($page, 0, 0, "");

    /* Query the number of blocks on the first page */
    $blockcount = $p->pcos_get_number($indoc, "length:pages[0]/blocks");

    if ($blockcount == 0) {
	die("Error: " .  $infile . "does not contain any PDFlib blocks");
    }

    /* Loop over all blocks on the $page */
    for ($i = 0; $i <  $blockcount; $i++) {
	/* Fetch the name and type of the $i-th block on the first page
	 * (one of Text/Image/PDF)
	 */
	$blockname = $p->pcos_get_string($indoc,
	    "pages[0]/blocks[" . $i . "]/Name");

	$blocktype = $p->pcos_get_string($indoc,
	    "pages[0]/blocks[" . $i . "]/Subtype");

	/* Visualize all text blocks */
	if ($blocktype == "Text") {
	    $optlist = "fontname=Helvetica encoding=unicode " .
		"fillcolor={rgb 1 0 0} " .
		"bordercolor={gray 0} linewidth=0.25";

	    /* We simply use the $blockname as content */
	    if ($p->fill_textblock(
			$page, $blockname, $blockname, $optlist) == 0) {
		print("Warning: " . $p->get_errmsg());
	    }
	}
    }

    $p->end_page_ext("");
    $p->close_pdi_page($page);

    $p->end_document("");
    $p->close_pdi_document($indoc);

    print "$outfilename generated";

}
catch (PDFlibException $e) {
    die("PDFlib exception occurred in starter_block sample:\n" .
	"[" . $e->get_errnum() . "] " . $e->get_apiname() . ": " .
	$e->get_errmsg() . "\n");
}
catch (Exception $e) {
    die($e);
}

$p = 0;
?>
