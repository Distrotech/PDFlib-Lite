#!/usr/bin/perl
# $Id: starter_block.pl,v 1.3.2.3 2008/12/25 13:28:41 rp Exp $
#
# Block starter:
# Import a PDF page containing, and process all blocks. The blocks are
# retrieved via pCOS, and the block filling functions are used to
# visualize the blocks on the output page. A real-world application would
# of course fill the blocks with data retrieved from some external data
# source.
#
# required software: PPS 7 or above
# required data: input PDF
#

use pdflib_pl 7.0;

# This is where the data files are. Adjust as necessary.
$searchpath = "../data";
$infile = "boilerplate.pdf";
$outfilename = "starter_block.pdf";

$p = PDF_new();

eval {
    # This means we must check return values of load_font() etc.
    PDF_set_parameter($p, "errorpolicy", "return");

    PDF_set_parameter($p, "SearchPath", $searchpath);

    # we use "utf8" as textformat, this allows to use unicode encoding
    PDF_set_parameter($p, "textformat", "utf8");

    if (PDF_begin_document($p, $outfilename, "") == -1) {
	die("Error: " . PDF_get_errmsg($p));
    }

    PDF_set_info($p, "Creator", "PDFlib starter sample");
    PDF_set_info($p, "Title", "starter_block");

    # Open a PDF containing blocks
    $indoc = PDF_open_pdi_document($p, $infile, "");
    if ($indoc == -1) {
	die("Error: " . PDF_get_errmsg($p));
    }

    # Open the first $page
    $page = PDF_open_pdi_page($p, $indoc, 1, "");
    if ($page == -1) {
	die("Error: " . PDF_get_errmsg($p));
    }

    $width = PDF_pcos_get_number($p, $indoc, "pages[0]/width");
    $height = PDF_pcos_get_number($p, $indoc, "pages[0]/height");

    PDF_begin_page_ext($p, $width, $height, "");

    # Place the imported $page on the output $page
    PDF_fit_pdi_page($p, $page, 0, 0, "");

    # Query the number of blocks on the first page
    $blockcount = PDF_pcos_get_number($p, $indoc, "length:pages[0]/blocks");

    if ($blockcount == 0) {
	die("Error: " .  $infile . "does not contain any PDFlib blocks");
    }

    # Loop over all blocks on the $page
    for ($i = 0; $i <  $blockcount; $i++) {
	# Fetch the name and type of the $i-th block on the first page
	# (one of Text/Image/PDF)

	$blockname = PDF_pcos_get_string($p, $indoc,
	    "pages[0]/blocks[" . $i . "]/Name");

	$blocktype = PDF_pcos_get_string($p, $indoc,
	    "pages[0]/blocks[" . $i . "]/Subtype");

	# Visualize all text blocks
	if ($blocktype == "Text") {
	    $optlist = "fontname=Helvetica encoding=unicode " .
		"fillcolor={rgb 1 0 0} " .
		"bordercolor={gray 0} linewidth=0.25";

	    # We simply use the $blockname as content
	    if (PDF_fill_textblock($p,
			$page, $blockname, $blockname, $optlist) == -1) {
		print("Warning: " . PDF_get_errmsg($p));
	    }
	}
    }

    PDF_end_page_ext($p, "");
    PDF_close_pdi_page($p, $page);

    PDF_end_document($p, "");
    PDF_close_pdi_document($p, $indoc);

    PDF_delete($p);
};

if ($@) {
    printf("starter_block: PDFlib Exception occurred:\n");
    printf(" $@\n");
    exit;
}
