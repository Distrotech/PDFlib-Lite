#!/bin/sh
# $Id: starter_pdfx.tcl,v 1.2 2006/10/05 19:58:26 rjs Exp $
#
# Hide the exec to Tcl but not to the shell by appending a backslash\
exec tclsh "$0" ${1+"$@"}

# PDF/X starter:
# Create PDF/X-compliant output
#
# required software: PDFlib/PDFlib+PDI/PPS 7
# required data: font file image file icc profile
#                 see www.pdflib.com for ICC profiles)

# The lappend line is unnecessary if PDFlib has been installed
# in the Tcl package directory
set auto_path [linsert $auto_path 0 .libs .]

package require pdflib 7.0

# This is where the data files are. Adjust as necessary.*/
set searchpath "../data";
set imagefile "nesrin.jpg";
set outfilename "starter_pdfx.pdf";

set p [PDF_new]

if { [catch {
    # This means we must check return values of load_font ) etc.
    PDF_set_parameter $p "errorpolicy" "return"

    PDF_set_parameter $p "SearchPath" $searchpath

    if {[PDF_begin_document $p $outfilename "pdfx=PDF/X-3:2002"] == 0} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    PDF_set_info $p "Creator" "PDFlib starter sample"
    PDF_set_info $p "Title" "starter_pdfx"

    #
    # You can use one of the Standard output intents  e.g. for SWOP
    # printing) which do not require an ICC profile:
    #
    # PDF_load_iccprofile $p "CGATS TR 001" "usage=outputintent"
    #
    # However if you use ICC or Lab color you must load an ICC
    # profile as output intent:
    
    if {[PDF_load_iccprofile $p "ISOcoated.icc" "usage=outputintent"] == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	puts stderr  "Please install the ICC profile package from www.pdflib.com to run the PDF/X starter sample.\n"
	PDF_delete $p
	return 2
    }

    PDF_begin_page_ext $p 595 842 ""

    # $font embedding is required for PDF/X
    set font [PDF_load_font $p "LuciduxSans-Oblique" "unicode" "embedding"]
    if {$font == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }
    PDF_setfont $p $font 24

    set spot [PDF_makespotcolor $p "PANTONE 123 C"]
    PDF_setcolor $p "fill" "spot" $spot 1.0 0.0 0.0
    PDF_fit_textline $p "PDF/X-3:2002 starter" 50 700 ""

    # The RGB $image below needs an $icc profile; we use sRGB.
    set icc [PDF_load_iccprofile $p "sRGB" ""]
    set image [PDF_load_image $p "auto" $imagefile "iccprofile=$icc"]

    if {$image == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    PDF_fit_image $p $image 0.0 0.0 "scale=0.5"

    PDF_end_page_ext $p ""

    PDF_end_document $p ""

} result] } {
    puts stderr "$result"
}

# delete the PDFlib object
PDF_delete $p
