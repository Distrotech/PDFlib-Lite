#!/bin/sh
# $Id: starter_pdfa.tcl,v 1.1.2.1 2008/03/13 11:44:43 rjs Exp $
#
# Hide the exec to Tcl but not to the shell by appending a backslash\
exec tclsh "$0" ${1+"$@"}

# PDF/A starter:
# Create PDF/A-compliant output
#
# required software: PDFlib/PDFlib+PDI/PPS 7
# required data: font file, image file
#
# The lappend line is unnecessary if PDFlib has been installed
# in the Tcl package directory
set auto_path [linsert $auto_path 0 .libs .]

package require pdflib 7.0


# This is where the data files are. Adjust as necessary.
set searchpath "../data"
set imagefile "nesrin.jpg"
set outfilename "starter_pdfa.pdf"

set p [PDF_new]

if { [catch {
    PDF_set_parameter $p "SearchPath" $searchpath

    # PDF/A-1a requires Tagged PDF
    if {[PDF_begin_document $p $outfilename "pdfa=PDF/A-1b:2005"] == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    # We use sRGB as output intent since it allows the color
    # spaces, CIELab, ICC-based, grayscale and RGB.
    #
    # If you need CMYK color you must use a CMYK output profile.

    PDF_load_iccprofile $p "sRGB" "usage=outputintent"

    PDF_set_info $p "Creator" "PDFlib starter sample"
    PDF_set_info $p "Title" "starter_pdfa"

    PDF_begin_page_ext $p 595 842 ""

    # $font embedding is required for PDF/A
    set font [PDF_load_font $p "LuciduxSans-Oblique" "unicode" "embedding"]
    if {$font == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }
    PDF_setfont $p $font 24

    PDF_fit_textline $p "PDF/A-1b:2005 starter" 50 700 ""

    # We can use an RGB $image since we already supplied an
    # output intent profile.

    set image [PDF_load_image $p "auto" $imagefile ""]
    if {$image == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    # Place the $image at the bottom of the page
    PDF_fit_image $p $image 0.0 0.0 "scale=0.5"

    PDF_end_page_ext $p ""

    PDF_end_document $p ""

} result] } {
    puts stderr "$result"
}

# delete the PDFlib object
PDF_delete $p
