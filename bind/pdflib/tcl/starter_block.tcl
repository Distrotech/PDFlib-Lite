#!/bin/sh
# $Id: starter_block.tcl,v 1.4.2.2 2008/05/09 10:11:55 rjs Exp $
#
# Hide the exec to Tcl but not to the shell by appending a backslash\
exec tclsh "$0" ${1+"$@"}

# Block starter:
# Import a PDF page containing, and process all blocks. The blocks are
# retrieved via pCOS, and the block filling functions are used to
# visualize the blocks on the output page. A real-world application would
# of course fill the blocks with data retrieved from some external data
# source.
#
# required software: PPS 7 or above
# required data: input PDF

# The lappend line is unnecessary if PDFlib has been installed
# in the Tcl package directory
set auto_path [linsert $auto_path 0 .libs .]

package require pdflib 7.0

# This is where the data files are. Adjust as necessary.
set searchpath "../data"
set infile "boilerplate.pdf"
set outfilename "starter_block.pdf"

set p [PDF_new]

if { [catch {

    # This means we must check return values of load_font() etc.
    PDF_set_parameter $p "errorpolicy"  "return"

    PDF_set_parameter $p "SearchPath" $searchpath

    if {[PDF_begin_document $p $outfilename ""] == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    PDF_set_info $p "Creator" "PDFlib starter sample"
    PDF_set_info $p "Title" "starter_block"

    # Open a PDF containing blocks
    set indoc [PDF_open_pdi_document $p $infile ""]
    if {$indoc == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    # Open the first $page
    set page [PDF_open_pdi_page $p $indoc 1 ""]
    if {$page == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    set width [PDF_pcos_get_number $p $indoc "pages\[0\]/width"]
    set height [PDF_pcos_get_number $p $indoc "pages\[0\]/height"]

    PDF_begin_page_ext $p $width $height ""

    # Place the imported $page on the output $page
    PDF_fit_pdi_page $p $page 0 0 ""

    # Query the number of blocks on the first page
    set blockcount [PDF_pcos_get_number $p $indoc \
	"length:pages\[0\]/blocks"]

    if {$blockcount == 0} {
	puts stderr "Error: $infile does not contain any PDFlib blocks"
	exit
    }

    # Loop over all blocks on the $page
    for {set i 0} {$i < $blockcount} {incr i} {
	# Fetch the name and type of the $i-th block on the first page
	# (one of Text/Image/PDF)

	set blockname [PDF_pcos_get_string $p $indoc \
	    "pages\[0\]/blocks\[$i\]/Name"]

	set blocktype [PDF_pcos_get_string $p $indoc \
	    "pages\[0\]/blocks\[$i\]/Subtype"]

	# Visualize all text blocks
	if {$blocktype == "Text"} {
	    set optlist "fontname=Helvetica encoding=unicode \
		fillcolor={rgb 1 0 0} bordercolor={gray 0} linewidth=0.25"

	    # We simply use the $blockname as content
	    if {[PDF_fill_textblock $p \
			$page $blockname $blockname $optlist] == -1} {
		print "Warning: [PDF_get_errmsg $p]"
	    }
	}
    }

    PDF_end_page_ext $p ""
    PDF_close_pdi_page $p $page

    PDF_end_document $p ""
    PDF_close_pdi_document $p $indoc

} result] } {
    puts stderr "$result"
}

# delete the PDFlib object
PDF_delete $p
