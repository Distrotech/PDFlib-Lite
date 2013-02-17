#!/bin/sh
# $Id: quickreference.tcl,v 1.27 2006/10/03 23:38:40 rjs Exp $
#
# PDFlib/PDI client: mini imposition demo
#

# Hide the exec to Tcl but not to the shell by appending a backslash\
exec tclsh "$0" ${1+"$@"}

# The lappend line is unnecessary if PDFlib has been installed
# in the Tcl package directory
set auto_path [linsert $auto_path 0 .libs .]

package require pdflib 7.0

set maxrow	2
set maxcol	2
set startpage	1
set width	500.0
set height	770.0
set infile	"reference.pdf"
# This is where font/image/PDF input files live. Adjust as necessary.
set searchpath	"../data"

set p [PDF_new]

if { [catch {

    # This means we must check return values of load_font() etc.
    PDF_set_parameter $p "errorpolicy"  "return"

    PDF_set_parameter $p "SearchPath" $searchpath

    if {[PDF_begin_document $p "quickreference.pdf" ""] == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    PDF_set_info $p "Creator" "quickreference.tcl"
    PDF_set_info $p "Author" "Thomas Merz"
    PDF_set_info $p "Title" "Mini Imposition Demo (Tcl)"

    set manual [PDF_open_pdi_document $p $infile ""]
    if {$manual == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    set row 0
    set col 0

    PDF_set_parameter $p "topdown" "true"

    set endpage [PDF_pcos_get_number $p $manual "length:pages"]

    for {set pageno $startpage} {$pageno <= $endpage} \
					    {set pageno [expr $pageno + 1]} {
	if {$row == 0 && $col == 0} {
	    PDF_begin_page_ext $p $width $height ""
	    set font [PDF_load_font $p "Helvetica-Bold" "unicode" ""]
	    if {$font == -1} {
		puts stderr "Error: % [PDF_get_errmsg $p]"
		exit
	    }
	    PDF_setfont $p $font 18
	    PDF_set_text_pos $p 24 [expr 24]
	    PDF_show $p "PDFlib Quick Reference"
	}

	set page [PDF_open_pdi_page $p $manual $pageno ""]

	if {$page == -1} {
	    puts stderr "Error: [PDF_get_errmsg $p]"
	    exit
	}

	set scale [expr {1.0/$maxrow}]
	PDF_fit_pdi_page $p $page [expr $width/$maxcol*$col] \
	    [expr ($row + 1) * $height/$maxrow] "scale $scale"
	PDF_close_pdi_page $p $page

	set col [expr $col + 1]
	if {$col == $maxcol} {
	    set col 0
	    set row [expr $row + 1]
	}
	if {$row == $maxrow} {
	    set row 0
	    PDF_end_page $p
	}
    }

    # finish the last partial page
    if {$row != 0 || $col != 0} {
	PDF_end_page_ext $p ""
    }
    PDF_end_document $p ""
    PDF_close_pdi_document $p $manual

} result] } {
    puts stderr "$result"
}

# delete the PDFlib object
PDF_delete $p
