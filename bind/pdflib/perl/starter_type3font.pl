#!/usr/bin/perl
# $Id: starter_type3font.pl,v 1.1.2.5 2009/11/18 00:16:12 rjs Exp $
# Type 3 font starter:
# Create a simple Type 3 font from vector data
#
# Define a type 3 font with the glyphs "l" and "space" and output text with
# that font. In addition the glyph ".notdef" is defined which any undefined
# character will be mapped to.
#
# Required software: PDFlib/PDFlib+PDI/PPS 7
# Required data: none


use pdflib_pl 7.0;
use strict;

# This is where the data files are. Adjust as necessary.
my $searchpath = "../data";
my $outfile = "starter_type3font.pdf";
my $title = "Starter Type 3 Font";

my $buf;
my $font;
my ($x, $y);
# create a new PDFlib object
my $p = PDF_new();

eval {
    PDF_set_parameter($p, "SearchPath", $searchpath);

    # This means we must check return values of load_font() etc.
    PDF_set_parameter($p, "errorpolicy", "return");

    if (PDF_begin_document($p, $outfile, "") == -1) {
	printf("Error: %s\n", PDF_get_errmsg($p));
	PDF_delete($p);
	exit(2);
    }

    PDF_set_info($p, "Creator", "PDFlib Cookbook");
    $buf = $title . '  $Revision: 1.1.2.5 $';
    PDF_set_info($p, "Title", $buf);

    # Create the font "SimpleFont" containing the glyph "l",
    # the glyph "space" for spaces and the glyph ".notdef" for any
    # undefined character

    PDF_begin_font($p, "SimpleFont",
		0.001, 0.0, 0.0, 0.001, 0.0, 0.0, "");
    PDF_begin_glyph($p, ".notdef", 266, 0, 0, 0, 0);
    PDF_end_glyph($p);
    PDF_begin_glyph($p, "space", 266, 0, 0, 0, 0);
    PDF_end_glyph($p);
    PDF_begin_glyph($p, "l", 266, 0, 0, 266, 570);
    PDF_setlinewidth($p, 20);
    PDF_setdash($p, 0, 0);
    $x = 197;
    $y = 10;
    PDF_moveto($p, $x, $y);
    $y += 530;
    PDF_lineto($p, $x, $y);
    $x -= 64;
    PDF_lineto($p, $x, $y);
    $y -= 530;
    PDF_moveto($p, $x, $y);
    $x += 128;
    PDF_lineto($p, $x, $y);

    PDF_stroke($p);
    PDF_end_glyph($p);

    PDF_end_font($p);

    # Start page
    PDF_begin_page_ext($p, 0, 0, "width=300 height=200");

    # Load the new "SimpleFont" font
    $font = PDF_load_font($p, "SimpleFont", "winansi", "");

    if ($font == -1) {
	printf("Error: %s\n", PDF_get_errmsg($p));
	PDF_delete($p);
	exit(2);
    }

    # Output the characters "l" and "space" of the "SimpleFont" font.
    # The character "x" is undefined and will be mapped to ".notdef"

    $buf = " font=" . $font . " fontsize=40";
    PDF_fit_textline($p, "lll lllxlll", 100, 100, $buf);

    PDF_end_page_ext($p, "");

    PDF_end_document($p, "");
};

if ($@) {
    printf("starter_type3font: PDFlib Exception occurred:\n");
    printf(" $@\n");
    exit;
}
