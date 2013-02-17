#!/bin/sh
# $Id: starter_image.tcl,v 1.1.2.1 2008/01/10 12:08:01 kurt Exp $
#
# Hide the exec to Tcl but not to the shell by appending a backslash\
exec tclsh "$0" ${1+"$@"}

# The lappend line is unnecessary if PDFlib has been installed
# in the Tcl package directory
set auto_path [linsert $auto_path 0 .libs .]

package require pdflib 7.0

# Starter image:
# Load and place an image using various options for scaling and positioning
#
# Place the image it its original size.
# Place the image with scaling and orientation to the west.
# Fit the image into a box with clipping.
# Fit the image into a box with proportional resizing.
# Fit the image into a box entirely.
#
# Required software: PDFlib Lite/PDFlib/PDFlib+PDI/PPS 7
# Required data: image file
#
 
set p [PDF_new]

if { [catch {

    # This is where the data files are. Adjust as necessary. 
    set searchpath "../data" 
    set outfile "starter_image.pdf" 

    set imagefile "lionel.jpg" 
    set bw 400 
    set bh 200 
    set x 20 
    set y 580 
    set yoffset 260 

	PDF_set_parameter $p "SearchPath" $searchpath 

	PDF_set_parameter $p "errorpolicy" "exception" 

	PDF_begin_document $p $outfile ""

	PDF_set_info $p "Creator" "PDFlib starter sample" 
	PDF_set_info $p "Title" "starter_image" 

	# For PDFlib Lite: change "unicode" to "winansi" 
	set font [PDF_load_font $p "Helvetica" "winansi" ""]

	# Load the image 
	set image [PDF_load_image $p "auto" $imagefile ""]

	# Start page 1 
	PDF_begin_page_ext $p 0 0 "width=a4.width height=a4.height" 
	PDF_setfont $p $font 12 


	# ------------------------------------
	# Place the image in its original size
	# ------------------------------------
	 

	# Position the image in its original size with its lower left corner
	# at the reference point (20 380)
	 
	PDF_fit_image $p $image 20 380 "" 

	# Output some descriptive text 
	PDF_fit_textline $p \
		"The image is placed with the lower left corner in its original \
		 size at reference point (20 380):" 20 820 "" 
	PDF_fit_textline $p "PDF_fit_image $image 20 380 \"\"" 20 800 "" 


	# --------------------------------------------------------
	# Place the image with scaling and orientation to the west
	# --------------------------------------------------------
	 

	# Position the image with its lower right corner at the reference
	# point (580 20).
	# "scale=0.5" scales the image by 0.5.
	# "orientate=west" orientates the image to the west.
	 
	PDF_fit_image $p $image 580 20 \
		"scale=0.5 position={right bottom} orientate=west" 

	# Output some descriptive text 
	PDF_fit_textline $p \
		"The image is placed with a scaling of 0.5 and an orientation to \
		 the west with the lower right corner" 580 320 \
		"position={right bottom}" 
	PDF_fit_textline $p \
		" at reference point (580 20): PDF_fit_image $image 580 20 \
		 \"scale=0.5 orientate=west position={right bottom}\"" \
		580 300 "position={right bottom}" 

	PDF_end_page_ext $p "" 

	# Start page 2 
	PDF_begin_page_ext $p 0 0 "width=a4.width height=a4.height" 
	PDF_setfont $p $font 12 


	# --------------------------------------
	# Fit the image into a box with clipping
	# --------------------------------------
	 

	# The "boxsize" option defines a box with a given width and height and
	# its lower left corner located at the reference point.
	# "position={right top}" positions the image on the top right of the
	# box.
	# "fitmethod=clip" clips the image to fit it into the box.
	 		 
	PDF_fit_image $p $image $x $y "boxsize={$bw $bh} position={right top} fitmethod=clip" 

	# Output some descriptive text 
	PDF_fit_textline $p \
		"PDF_fit_image $image $x $y \"boxsize={400 200} position={right top} fitmethod=clip\"" \
		20 [expr $y + $bh + 10] "" 


	# ---------------------------------------------------
	# Fit the image into a box with proportional resizing
	# ---------------------------------------------------
	 

	# The "boxsize" option defines a box with a given width and height and
	# its lower left corner located at the reference point.
	# "position={center}" positions the image in the center of the
	# box.
	# "fitmethod=meet" resizes the image proportionally until its height
	# or width completely fits into the box.
	# The "showborder" option is used to illustrate the borders of the box.
	 
    set y [expr $y - $yoffset]
	PDF_fit_image $p $image $x $y "boxsize={$bw $bh} position={center} fitmethod=meet showborder"

	# Output some descriptive text 
	PDF_fit_textline $p \
		"PDF_fit_image $image $x $y \"boxsize={400 200} position={center} fitmethod=meet showborder\"" \
		20 [expr $y + $bh + 10] "" 


	# ---------------------------------
	# Fit the image into a box entirely
	# ---------------------------------
	 

	# The "boxsize" option defines a box with a given width and height and
	# its lower left corner located at the reference point.
	# By default the image is positioned in the lower left corner of the
	# box.
	# "fitmethod=entire" resizes the image proportionally until its height
	# or width completely fits into the box.
	 
    set y [expr $y - $yoffset]
	PDF_fit_image $p $image $x $y "boxsize={$bw $bh} fitmethod=entire"

	# Output some descriptive text 
	PDF_fit_textline $p \
		"PDF_fit_image $ $x $y \"boxsize={400 200} fitmethod=entire\"" \
		20 [expr $y + $bh + 10] "" 

	PDF_end_page_ext $p "" 

	PDF_close_image $p $image 

	PDF_end_document $p "" 


} result]} {
    puts stderr $result
}

PDF_delete $p
