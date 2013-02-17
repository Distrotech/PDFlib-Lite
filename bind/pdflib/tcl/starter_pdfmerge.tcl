#!/bin/sh
# $Id: starter_pdfmerge.tcl,v 1.1.2.1 2007/08/08 15:09:42 rp Exp $
#
# Hide the exec to Tcl but not to the shell by appending a backslash\
exec tclsh "$0" ${1+"$@"}

# PDF merge starter:
# Merge pages from multiple PDF documents; interactive elements (e.g. 
# bookmarks) will be dropped.
#
# required software: PDFlib+PDI/PPS 7
# required data: PDF documents

# The lappend line is unnecessary if PDFlib has been installed
# in the Tcl package directory
set auto_path [linsert $auto_path 0 .libs .]

package require pdflib 7.0

# This is where the data files are. Adjust as necessary.
set searchpath "../data"
set outfilename "starter_pdfmerge.pdf"

set pdffiles {
	"PDFlib-real-world.pdf"
	"PDFlib-datasheet.pdf"
	"TET-datasheet.pdf"
	"PLOP-datasheet.pdf"
	"pCOS-datasheet.pdf"
}

set p [PDF_new]

if { [catch {
    # This means we must check return values of load_font() etc.
    PDF_set_parameter $p "errorpolicy" "return"

    PDF_set_parameter $p "SearchPath" $searchpath

    if {[PDF_begin_document $p $outfilename ""] == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    PDF_set_info $p "Creator" "PDFlib starter sample"
    PDF_set_info $p "Title" "starter_pdfmerge"

    foreach pdffile $pdffiles { 
	# Open the input PDF
	set indoc [PDF_open_pdi_document $p $pdffile ""]
	if {$indoc == -1} {
	    puts stderr "Error: [PDF_get_errmsg $p]"
	    next;
	}

	set endpage [PDF_pcos_get_number $p $indoc "/Root/Pages/Count"]

	# Loop over all pages of the input document
	for {set pageno 1} {$pageno <= $endpage} {set pageno [expr $pageno + 1]} {
	    set page [PDF_open_pdi_page $p $indoc $pageno ""]

	    if {$page == -1} {
		puts stderr "Error: [PDF_get_errmsg $p]"
		next;
	    }
	    # Dummy $page size; will be adjusted later
	    PDF_begin_page_ext $p 10 10 ""

	    # Create a bookmark with the file name
	    if {$pageno == 1} {
		PDF_create_bookmark $p $pdffile ""
	    }

	    # Place the imported $page on the output $page and
	    # adjust the $page size
	    
	    PDF_fit_pdi_page $p $page 0 0 "adjustpage"
	    PDF_close_pdi_page $p $page

	    PDF_end_page_ext $p ""
	}
	PDF_close_pdi_document $p $indoc
    }

    PDF_end_document $p ""

} result] } {
    puts stderr "$result"
}

# delete the PDFlib object
PDF_delete $p
