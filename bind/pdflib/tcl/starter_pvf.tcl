#!/bin/sh
# $Id: starter_pvf.tcl,v 1.1.2.3 2008/01/10 12:08:01 kurt Exp $
#
# Hide the exec to Tcl but not to the shell by appending a backslash\
exec tclsh "$0" ${1+"$@"}

# The lappend line is unnecessary if PDFlib has been installed
# in the Tcl package directory
set auto_path [linsert $auto_path 0 .libs .]

package require pdflib 7.0

# PDFlib Virtual File system (PVF:
# Create a PVF file which holds an image or PDF, and import the data from the
# PVF file
#
# This avoids disk access and is especially useful when the same image or PDF
# is imported multiply. For examples, images which sit in a database don't
# have to be written and re-read from disk, but can be passed to PDFlib
# directly in memory. A similar technique can be used for loading other data
# such as fonts, ICC profiles, etc.
#
# Required software: PDFlib Lite/PDFlib/PDFlib+PDI/PPS 7
# Required data: image file
#
set p [PDF_new]

if { [catch {

    # This is where the data files are. Adjust as necessary.
    set searchpath "../data"
    set outfile "starter_pvf.pdf"

	PDF_set_parameter $p "SearchPath" $searchpath

	PDF_set_parameter $p "errorpolicy" "exception"

	# Set an output path according to the name of the topic
	PDF_begin_document $p $outfile ""

	PDF_set_info $p "Creator" "PDFlib starter sample"
	PDF_set_info $p "Title" "starter_pvf"

	# We just read some image data from a file to really benefit
	# from using PVF read the data from a Web site or a database instead
	
	set fp [open "../data/PDFlib-logo.tif"]
	fconfigure $fp -translation binary 
	set imagedata [read $fp]
	close $fp
		
	PDF_create_pvf $p "/pvf/image" $imagedata ""

	# Load the image from the PVF
	set image [PDF_load_image $p "auto" "/pvf/image" ""]

	# Fit the image on page 1
	PDF_begin_page_ext $p 595 842 ""

	PDF_fit_image $p $image 350 750 ""

	PDF_end_page_ext $p ""

	# Fit the image on page 2
	PDF_begin_page_ext $p 595 842 ""

	PDF_fit_image $p $image 350 50 ""

	PDF_end_page_ext $p ""

	# Delete the virtual file to free the allocated memory
	PDF_delete_pvf $p "/pvf/image" 
	unset imagedata

	PDF_end_document $p ""

} result]} {
    puts stderr $result
}

PDF_delete $p
