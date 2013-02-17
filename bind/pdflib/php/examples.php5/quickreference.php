<?php
/* $Id: quickreference.php,v 1.6.2.1 2008/04/06 17:55:03 rp Exp $
 *
 * PDFlib+PDI client: mini imposition demo
 */

$infile    = "reference.pdf";
/* This is where font/image/PDF input files live. Adjust as necessary. */
$searchpath = "../data";
$maxrow    = 2;
$maxcol    = 2;
$width     = 500.0;
$height    = 770.0;
$endpage   = 0;

try {
    $p = new PDFlib();

    # This means we must check return values of load_font() etc.
    $p->set_parameter("errorpolicy", "return");

    $p->set_parameter("SearchPath", $searchpath);

    /*  open new PDF file; insert a file name to create the PDF on disk */
    if ($p->begin_document("", "") == 0) {
	die("Error: " . $p->get_errmsg());
    }

    /* This line is required to avoid problems on Japanese systems */
    $p->set_parameter("hypertextencoding", "winansi");

    $p->set_info("Creator", "quickreference.php");
    $p->set_info("Author", "Thomas Merz");
    $p->set_info("Title", "mini imposition demo (php)");

    $manual = $p->open_pdi($infile, "", 0);
    if (!$manual) {
	die("Error: " . $p->get_errmsg());
    }

    $row = 0;
    $col = 0;

    $p->set_parameter("topdown", "true");

    $endpage = $p->pcos_get_number($manual, "length:pages");

    for ($pageno = 1; $pageno <= $endpage; $pageno++) {
	if ($row == 0 && $col == 0) {
	    $p->begin_page_ext($width, $height, "");
	    $font = $p->load_font("Helvetica-Bold", "winansi", "");
	    if ($font == 0) {
		die("Error: " . $p->get_errmsg());
	    }
	    $p->setfont($font, 18);
	    $p->set_text_pos(24, 24);
	    $p->show("PDFlib Quick Reference");
	}

	$page = $p->open_pdi_page($manual, $pageno, "");

	if (!$page) {
	    die("Error: " . $p->get_errmsg());
	}

	$optlist = sprintf("scale %f", 1/$maxrow);

	$p->fit_pdi_page($page, 
	    $width/$maxcol*$col, ($row + 1) * $height/$maxrow, $optlist);
	$p->close_pdi_page($page);

	$col++;
	if ($col == $maxcol) {
	    $col = 0;
	    $row++;
	}
	if ($row == $maxrow) {
	    $row = 0;
	    $p->end_page_ext("");
	}
    }

    /* finish the last partial page */
    if ($row != 0 || $col != 0) {
	$p->end_page_ext("");
    }

    $p->end_document("");
    $p->close_pdi($manual);

    $buf = $p->get_buffer();
    $len = strlen($buf);

    header("Content-type: application/pdf");
    header("Content-Length: $len");
    header("Content-Disposition: inline; filename=quickreference_php.pdf");
    print $buf;

}
catch (PDFlibException $e) {
    die("PDFlib exception occurred in quickreference sample:\n" .
	"[" . $e->get_errnum() . "] " . $e->get_apiname() . ": " .
	$e->get_errmsg() . "\n");
}
catch (Exception $e) {
    die($e);
}

$p = 0;
?>
