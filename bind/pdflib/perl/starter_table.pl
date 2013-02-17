#!/usr/bin/perl
# $Id: starter_table.pl,v 1.4.2.1 2008/12/25 13:28:41 rp Exp $
#
# Table starter:
# Create table which may span multiple pages
#
# required software: PDFlib/PDFlib+PDI/PPS 7
# required data: image file (dummy text created within the program)

use pdflib_pl 7.0;

# This is where the data files are. Adjust as necessary.
$searchpath = "../data";
$imagefile = "nesrin.jpg";
$outfilename = "starter_table.pdf";

$tf=-1; $tbl=-1;
$rowmax = 50; $colmax = 5;
$llx= 50; $lly=50; $urx=550; $ury=800;

$headertext = "Table header (centered across all columns)";

# Dummy text for filling a cell with multi-line Textflow
$tf_text = 
"Lorem ipsum dolor sit amet, consectetur adi&shy;pi&shy;sicing elit, sed do eius&shy;mod tempor incidi&shy;dunt ut labore et dolore magna ali&shy;qua. Ut enim ad minim ve&shy;niam, quis nostrud exer&shy;citation ull&shy;amco la&shy;bo&shy;ris nisi ut ali&shy;quip ex ea commodo con&shy;sequat. Duis aute irure dolor in repre&shy;henderit in voluptate velit esse cillum dolore eu fugiat nulla pari&shy;atur. Excep&shy;teur sint occae&shy;cat cupi&shy;datat non proident, sunt in culpa qui officia dese&shy;runt mollit anim id est laborum. ";

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
    PDF_set_info($p, "Title", "starter_table");

    # -------------------- Add table cells --------------------

    # ---------- row 1: table header (spans all columns)
    $row = 1; $col = 1;
    $font = PDF_load_font($p, "Times-Bold", "unicode", "");
    if ($font == -1) {
	printf("Error: %s\n", PDF_get_errmsg($p)); exit;
    }

    $optlist = "fittextline={position=center font=" . $font . " fontsize=14} " .
    "colspan=" . $colmax;

    $tbl = PDF_add_table_cell($p, $tbl, $col, $row, $headertext, $optlist);
    if ($tbl == -1) {
	die("Error: %s\n", PDF_get_errmsg($p));
    }

    # ---------- row 2: various kinds of content
    # ----- Simple text cell
    $row++; $col=1;

    $optlist = "fittextline={font=" . $font . " fontsize=10 orientate=west}";

    $tbl = PDF_add_table_cell($p, $tbl, $col, $row, "vertical line", $optlist);
    if ($tbl == -1) {
	die("Error: %s\n", PDF_get_errmsg($p));
    }

    # ----- Colorized background
    $col++;

    $optlist = "fittextline={font=" . $font . " fontsize=10} " .
    "matchbox={fillcolor={rgb 0.9 0.5 0}}";

    $tbl = PDF_add_table_cell($p, $tbl, $col, $row, "some color", $optlist);
    if ($tbl == -1) {
	die("Error: %s\n", PDF_get_errmsg($p));
    }

    # ----- Multi-line text with Textflow
    $col++;
    $font = PDF_load_font($p, "Times-Roman", "unicode", "");
    if ($font == -1) {
	printf("Error: %s\n", PDF_get_errmsg($p)); exit;
    }

    $optlist = "charref fontname=Times-Roman encoding=unicode fontsize=8 ";

    $tf = PDF_add_textflow($p, $tf, $tf_text, $optlist);
    if ($tf == -1) {
	die("Error: %s\n", PDF_get_errmsg($p));
    }

    $optlist = "margin=2 textflow=" . $tf;

    $tbl = PDF_add_table_cell($p, $tbl, $col, $row, "", $optlist);
    if ($tbl == -1) {
	die("Error: %s\n", PDF_get_errmsg($p));
    }

    # ----- Rotated $image
    $col++;

    $image = PDF_load_image($p, "auto", $imagefile, "");
    if ($image == -1) {
	die("Couldn't load $image: " . PDF_get_errmsg($p));
    }

    $optlist = "image=" . $image . " fitimage={orientate=west}";

    $tbl = PDF_add_table_cell($p, $tbl, $col, $row, "", $optlist);
    if ($tbl == -1) {
	die("Error: %s\n", PDF_get_errmsg($p));
    }

    # ----- Diagonal stamp
    $col++;

    $optlist = "fittextline={font=" . $font . " fontsize=10 stamp=ll2ur}";

    $tbl = PDF_add_table_cell($p, $tbl, $col, $row, "entry void", $optlist);
    if ($tbl == -1) {
	die("Error: %s\n", PDF_get_errmsg($p));
    }

    # ---------- Fill $row 3 and above with their numbers
    for ($row++; $row <= $rowmax; $row++) {
	for ($col = 1; $col <= $colmax; $col++) {
	    $num = "Col " . $col . "/Row " . $row;
	    $optlist = "colwidth=20% fittextline={font=" . $font . " fontsize=10}";
	    $tbl = PDF_add_table_cell($p, $tbl, $col, $row, $num, $optlist);
	    if ($tbl == -1) {
	    die("Error: %s\n", PDF_get_errmsg($p));
	}
	}
    }

    # ---------- Place the table on one or more pages ----------

    #
    # Loop until all of the table is placed; create new pages
    # as long as more table instances need to be placed.

    do {
	PDF_begin_page_ext($p, 0, 0, "width=a4.width height=a4.height");

	# Shade every other $row; draw lines for all table cells.
	# Add "showcells showborder" to visualize cell borders 

	$optlist = "header=1 fill={{area=rowodd fillcolor={gray 0.9}}} " .
	"stroke={{line=other}} ";

	# Place the table instance
	$result = PDF_fit_table($p, $tbl, $llx, $lly, $urx, $ury, $optlist);
	if ($result eq "_error") {
	    die("Couldn't place table:" . PDF_get_errmsg($p));
	}

	PDF_end_page_ext($p, "");

    } while ($result eq "_boxfull");

    # Check the $result; "_stop" means all is ok.
    if ($result ne "_stop") {
	if ($result eq "_error") {
	    die("Error when placing table: " . PDF_get_errmsg($p));
	} else {
	    # Any other return value is a user exit caused by
	    # the "return" option; this requires dedicated code to
	    # deal with.
	    die("User return found in Textflow");
	}
    }

    # This will also delete Textflow handles used in the table
    PDF_delete_table($p, $tbl, "");

    PDF_end_document($p, "");

    PDF_delete($p);
};

if ($@) {
    printf("starter_table: PDFlib Exception occurred:\n");
    printf(" $@\n");
    exit;
}
