<?php
# $Id: starter_type3font.php,v 1.1.2.3 2008/07/30 13:16:29 rp Exp $
# Type 3 font starter:
# Create a simple Type 3 font from vector data
#
# Define a type 3 font with the glyphs "l" and "space" and output text with
# that font. In addition the glyph ".notdef" is defined which any undefined
# character will be mapped to.
#
# Required software: PDFlib/PDFlib+PDI/PPS 7
# Required data: none


# This is where the data files are. Adjust as necessary.
$searchpath = "../data";
$title = "Starter Type 3 Font";

try {
    # create a new PDFlib object
    $p = new PDFlib();

    $p->set_parameter("SearchPath", $searchpath);

    # This means we must check return values of load_font() etc.
    $p->set_parameter("errorpolicy", "return");

    if ($p->begin_document("", "") == 0) {
	die("Error: " .  $p->get_errmsg());
    }

    $p->set_info("Creator", "PDFlib Cookbook");
    $buf = $title . '  $Revision: 1.1.2.3 $';
    $p->set_info("Title", $buf);

    # Create the font "SimpleFont" containing the glyph "l",
    # the glyph "space" for spaces and the glyph ".notdef" for any
    # undefined character

    $p->begin_font("SimpleFont",
		0.001, 0.0, 0.0, 0.001, 0.0, 0.0, "");
    $p->begin_glyph(".notdef", 266, 0, 0, 0, 0);
    $p->end_glyph();
    $p->begin_glyph("space", 266, 0, 0, 0, 0);
    $p->end_glyph();
    $p->begin_glyph("l", 266, 69, 0, 197, 530);
    $p->setlinewidth(20);
    $p->setdash(0, 0);
    $x = 197;
    $y = 0;
    $p->moveto($x, $y);
    $y += 530;
    $p->lineto($x, $y);
    $x -= 64;
    $p->lineto($x, $y);
    $y -= 530;
    $p->moveto($x, $y);
    $x += 128;
    $p->lineto($x, $y);

    $p->closepath();
    $p->stroke();
    $p->end_glyph();

    $p->end_font();

    # Start page
    $p->begin_page_ext(0, 0, "width=300 height=200");

    # Load the new "SimpleFont" font
    $font = $p->load_font("SimpleFont", "winansi", "");

    if ($font == 0) {
	die("Error: " .  $p->get_errmsg());
    }

    # Output the characters "l" and "space" of the "SimpleFont" font.
    # The character "x" is undefined and will be mapped to ".notdef"

    $buf = " font=" . $font . " fontsize=40";
    $p->fit_textline("lll lllxlll", 100, 100, $buf);

    $p->end_page_ext("");

    $p->end_document("");

    $buf = $p->get_buffer();
    $len = strlen($buf);

    header("Content-type: application/pdf");
    header("Content-Length: $len");
    header("Content-Disposition: inline; filename=hello.pdf");
    print $buf;

}
catch (PDFlibException $e) {
    die("PDFlib exception occurred in hello sample:\n" .
        "[" . $e->get_errnum() . "] " . $e->get_apiname() . ": " .
        $e->get_errmsg() . "\n");
}
catch (Exception $e) {
    die($e);
}

$p = 0;

?>
