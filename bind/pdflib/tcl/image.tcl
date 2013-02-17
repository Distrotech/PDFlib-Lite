#!/bin/sh
# $Id: image.tcl,v 1.26 2006/10/03 23:38:40 rjs Exp $
#
# PDFlib client: image example in Tcl
#

# Hide the exec to Tcl but not to the shell by appending a backslash\
exec tclsh "$0" ${1+"$@"}

# The lappend line is unnecessary if PDFlib has been installed
# in the Tcl package directory
set auto_path [linsert $auto_path 0 .libs .]

package require pdflib 7.0

set imagefile "nesrin.jpg"

set p [PDF_new]

if { [catch {

    # This is where font/image/PDF input files live. Adjust as necessary.
    set searchpath "../data"

    # This means we must check return values of load_font() etc.
    PDF_set_parameter $p "errorpolicy"  "return"

    PDF_set_parameter $p "SearchPath" $searchpath

    if {[PDF_begin_document $p "image.pdf" ""] == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    PDF_set_info $p "Creator" "image.tcl"
    PDF_set_info $p "Author" "Thomas Merz"
    PDF_set_info $p "Title" "image sample (Tcl)"

    set image [PDF_load_image $p "auto" $imagefile ""]

    if {$image == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    # We generate a page with arbitrary dimensions
    PDF_begin_page_ext $p 10 10 ""
    PDF_fit_image $p $image 0 0 "adjustpage"
    PDF_close_image $p $image
    PDF_end_page_ext $p ""

    PDF_end_document $p ""

} result] } {
    puts stderr "$result"
}

# delete the PDFlib object
PDF_delete $p
