#!/bin/sh
# $Id: starter_type3font.tcl,v 1.1.2.3 2009/11/18 00:16:14 rjs Exp $
#
# Hide the exec to Tcl but not to the shell by appending a backslash\
exec tclsh "$0" ${1+"$@"}

# The lappend line is unnecessary if PDFlib has been installed
# in the Tcl package directory
set auto_path [linsert $auto_path 0 .libs .]

package require pdflib 7.0

# Type 3 font starter:
# Create a simple Type 3 font from vector data
#
# Define a type 3 font with the glyphs "l" and "space" and output text with
# that font. In addition the glyph ".notdef" is defined which any undefined
# character will be mapped to.
#
# Required software: PDFlib/PDFlib+PDI/PPS 7
# Required data: none
#

set p [PDF_new]

if { [catch {

    # This is where the data files are. Adjust as necessary.
    set searchpath "../data" 
    set outfile "starter_type3font.pdf" 
    set title "Starter Type 3 Font" 

	PDF_set_parameter $p "SearchPath" $searchpath

	PDF_set_parameter $p "errorpolicy" "exception"

	PDF_begin_document $p $outfile ""

	PDF_set_info $p "Creator" "PDFlib starter sample"
	PDF_set_info $p "Title" "starter_type3font"

	# Create the font "SimpleFont" containing the glyph "l",
	# the glyph "space" for spaces and the glyph ".notdef" for any
	# undefined character

	PDF_begin_font $p "SimpleFont" 0.001 0.0 0.0 0.001 0.0 0.0 ""
	PDF_begin_glyph $p ".notdef" 266 0 0 0 0
	PDF_end_glyph $p
	PDF_begin_glyph $p "space" 266 0 0 0 0
	PDF_end_glyph $p
	PDF_begin_glyph $p "l" 266 0 0 266 570
	PDF_setlinewidth $p 20
	PDF_setdash $p 0 0
	set x 197 
	set y 10 
	PDF_moveto $p $x $y
	set y [expr $y + 530]
	PDF_lineto $p $x $y
	set x [expr $x - 64]
	PDF_lineto $p $x $y
	set y [expr $y - 530]
	PDF_moveto $p $x $y
	set x [expr $x + 128]
	PDF_lineto $p $x $y

	PDF_stroke $p
	PDF_end_glyph $p

	PDF_end_font $p

	# Start page
	PDF_begin_page_ext $p 0 0 "width=300 height=200"

	# Load the new "SimpleFont" font
	set font [PDF_load_font $p "SimpleFont" "winansi" ""]

	# Output the characters "l" and "space" of the "SimpleFont" font.
	# The character "x" is undefined and will be mapped to ".notdef"

	PDF_fit_textline $p "lll lllxlll" 100 100 "font=$font fontsize=40"

	PDF_end_page_ext $p ""

	PDF_end_document $p ""

} result]} {
    puts stderr $result
}

PDF_delete $p
