<?php
/* $Id: starter_table.php,v 1.1.2.2 2009/08/07 07:30:46 rjs Exp $
 *
 * Table starter:
 * Create table which may span multiple pages
 *
 * required software: PDFlib/PDFlib+PDI/PPS 7
 * required data: image file (dummy text created within the program)
 */

/* This is where the data files are. Adjust as necessary. */
$searchpath = "../data";
$imagefile = "nesrin.jpg";
$outfilename = "starter_table.pdf";

$tf=0; $tbl=0;
$rowmax = 50; $colmax = 5;
$llx= 50; $lly=50; $urx=550; $ury=800;

$headertext = "Table header (centered across all columns)";

/* Dummy text for filling a cell with multi-line Textflow */
$tf_text = 
"Lorem ipsum dolor sit amet, consectetur adi&shy;pi&shy;sicing elit, sed do eius&shy;mod tempor incidi&shy;dunt ut labore et dolore magna ali&shy;qua. Ut enim ad minim ve&shy;niam, quis nostrud exer&shy;citation ull&shy;amco la&shy;bo&shy;ris nisi ut ali&shy;quip ex ea commodo con&shy;sequat. Duis aute irure dolor in repre&shy;henderit in voluptate velit esse cillum dolore eu fugiat nulla pari&shy;atur. Excep&shy;teur sint occae&shy;cat cupi&shy;datat non proident, sunt in culpa qui officia dese&shy;runt mollit anim id est laborum. ";

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
    $p->set_info("Title", "starter_table");

    /* -------------------- Add table cells -------------------- */

    /* ---------- row 1: table header (spans all columns) */
    $row = 1; $col = 1;
    $font = $p->load_font("Times-Bold", "unicode", "");
    if ($font == 0) {
	die("Error: " . $p->get_errmsg());
    }

    $optlist = "fittextline={position=center font=" . $font . " fontsize=14} " .
    "colspan=" . $colmax;

    $tbl = $p->add_table_cell($tbl, $col, $row, $headertext, $optlist);
    if ($tbl == 0) {
	die("Error: " . $p->get_errmsg());
    }

    /* ---------- row 2: various kinds of content */
    /* ----- Simple text cell */
    $row++; $col=1;

    $optlist = "fittextline={font=" . $font . " fontsize=10 orientate=west}";

    $tbl = $p->add_table_cell($tbl, $col, $row, "vertical line", $optlist);
    if ($tbl == 0) {
	die("Error: " . $p->get_errmsg());
    }

    /* ----- Colorized background */
    $col++;

    $optlist = "fittextline={font=" . $font . " fontsize=10} " .
    "matchbox={fillcolor={rgb 0.9 0.5 0}}";

    $tbl = $p->add_table_cell($tbl, $col, $row, "some color", $optlist);
    if ($tbl == 0) {
	die("Error: " . $p->get_errmsg());
    }

    /* ----- Multi-line text with Textflow */
    $col++;
    $font = $p->load_font("Times-Roman", "unicode", "");
    if ($font == 0) {
	die("Error: " . $p->get_errmsg());
    }

    $optlist = "charref fontname=Times-Roman encoding=unicode fontsize=8 ";

    $tf = $p->add_textflow($tf, $tf_text, $optlist);
    if ($tf == 0) {
	die("Error: " . $p->get_errmsg());
    }

    $optlist = "margin=2 textflow=" . $tf;

    $tbl = $p->add_table_cell($tbl, $col, $row, "", $optlist);
    if ($tbl == 0) {
	die("Error: " . $p->get_errmsg());
    }

    /* ----- Rotated $image */
    $col++;

    $image = $p->load_image("auto", $imagefile, "");
    if ($image == 0) {
	die("Couldn't load $image: " . $p->get_errmsg());
    }

    $optlist = "image=" . $image . " fitimage={orientate=west}";

    $tbl = $p->add_table_cell($tbl, $col, $row, "", $optlist);
    if ($tbl == 0) {
	die("Error: " . $p->get_errmsg());
    }

    /* ----- Diagonal stamp */
    $col++;

    $optlist = "fittextline={font=" . $font . " fontsize=10 stamp=ll2ur}";

    $tbl = $p->add_table_cell($tbl, $col, $row, "entry void", $optlist);
    if ($tbl == 0) {
	die("Error: " . $p->get_errmsg());
    }

    /* ---------- Fill $row 3 and above with their numbers */
    for ($row++; $row <= $rowmax; $row++) {
	for ($col = 1; $col <= $colmax; $col++) {
	    $num = "Col " . $col . "/Row " . $row;
	    $optlist = "colwidth=20% fittextline={font=" . $font . " fontsize=10}";
	    $tbl = $p->add_table_cell($tbl, $col, $row, $num, $optlist);
	    if ($tbl == 0) {
		die("Error: " . $p->get_errmsg());
	    }
	}
    }

    /* ---------- Place the table on one or more pages ---------- */

    /*
     * Loop until all of the table is placed; create new pages
     * as long as more table instances need to be placed.
     */
    do {
	$p->begin_page_ext(0, 0, "width=a4.width height=a4.height");

	/* Shade every other $row; draw lines for all table cells.
	 * Add "showcells showborder" to visualize cell borders 
	 */
	$optlist = "header=1 fill={{area=rowodd fillcolor={gray 0.9}}} " .
	"stroke={{line=other}} ";

	/* Place the table instance */
	$result = $p->fit_table($tbl, $llx, $lly, $urx, $ury, $optlist);
	if ($result ==  "_error") {
	    die("Couldn't place table: " . $p->get_errmsg());
	}

	$p->end_page_ext("");

    } while ($result == "_boxfull");

    /* Check the $result; "_stop" means all is ok. */
    if ($result != "_stop") {
	if ($result ==  "_error") {
	    die("Error when placing table: " . $p->get_errmsg());
	} else {
	    /* Any other return value is a user exit caused by
	     * the "return" option; this requires dedicated code to
	     * deal with.
	     */
	    die("User return found in Textflow");
	}
    }

    /* This will also delete Textflow handles used in the table */
    $p->delete_table($tbl, "");

    $p->end_document("");

    print "$outfilename generated";

}
catch (PDFlibException $e) {
    die("PDFlib exception occurred in starter_table sample:\n" .
	"[" . $e->get_errnum() . "] " . $e->get_apiname() . ": " .
	$e->get_errmsg() . "\n");
}
catch (Exception $e) {
    die($e);
}

$p = 0;
?>
