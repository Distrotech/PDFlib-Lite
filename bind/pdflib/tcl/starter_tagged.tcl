#!/bin/sh
# $Id: starter_tagged.tcl,v 1.2.2.2 2008/01/11 11:32:37 kurt Exp $
#
# Hide the exec to Tcl but not to the shell by appending a backslash\
exec tclsh "$0" ${1+"$@"}

# Tagged PDF starter:
# Create document with structure information for reflow and accessibility
#
# required software: PDFlib/PDFlib+PDI/PPS 7
# required data: none (dummy text created in program)

# The lappend line is unnecessary if PDFlib has been installed
# in the Tcl package directory
set auto_path [linsert $auto_path 0 .libs .]

package require pdflib 7.0

# This is where the data files are. Adjust as necessary.
set searchpath "../data"
set outfilename "starter_tagged.pdf"

set p [PDF_new]

if { [catch {
    # This means we must check return values of load_font() etc.
    PDF_set_parameter $p "errorpolicy" "return"

    PDF_set_parameter $p "SearchPath" $searchpath

    if {[PDF_begin_document $p $outfilename "tagged=true"] == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    PDF_set_info $p "Creator" "PDFlib starter sample"
    PDF_set_info $p "Title" "starter_tagged"

    # Automatically create spaces between chunks of text
    PDF_set_parameter $p "autospace" "true"

    # open the first structure element as a child of the document
    # structure root  =0)
    
    set id [PDF_begin_item $p "P" "Title = {Simple Paragraph}"]

    PDF_begin_page_ext $p 0 0 "width=a4.width height=a4.height"

    set font [PDF_load_font $p "Helvetica" "winansi" ""]
    if {$font == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }
    PDF_setfont $p $font 24.0

    PDF_show_xy $p "Hello, Tagged PDF!" 50 700
    PDF_continue_text $p "This PDF has a very simple"
    PDF_continue_text $p "document structure."

    PDF_end_item $p $id

    # The page number is created as an artifact; it will be
    # ignored when reflowing the page in Acrobat.

    set id_artifact [PDF_begin_item $p "Artifact" ""]
    PDF_show_xy $p "Page 1" 250 100
    PDF_end_item $p $id_artifact

    PDF_end_page_ext $p ""

    PDF_end_document $p ""

} result] } {
    puts stderr "$result"
}

# delete the PDFlib object
PDF_delete $p
