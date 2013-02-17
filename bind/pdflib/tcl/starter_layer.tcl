#!/bin/sh
# $Id: starter_layer.tcl,v 1.1.2.2 2008/02/11 20:10:29 rjs Exp $
#
# Hide the exec to Tcl but not to the shell by appending a backslash\
exec tclsh "$0" ${1+"$@"}

# The lappend line is unnecessary if PDFlib has been installed
# in the Tcl package directory
set auto_path [linsert $auto_path 0 .libs .]

package require pdflib 7.0

# Starter layer:
# Define several layers output images and text to them and define
# particular layers to be visible when opening the document
#
# Define two layers for RGB or Grayscale images and two layers for English or
# German image captions. Output images and text on the various layers and
# open the document with the RGB images and English captions visible.
#
# Required software: PDFlib/PDFlib+PDI/PPS 7
# Required data: grayscale and RGB images
 
set p [PDF_new]

if { [catch {

    # This is where the data files are. Adjust as necessary. 
    set searchpath "../data"
    set outfile "starter_layer.pdf"

    set rgb "nesrin.jpg"
    set gray "nesrin_gray.jpg"

	PDF_set_parameter $p "SearchPath" $searchpath

	PDF_set_parameter $p "errorpolicy" "exception"

	# Open the document with the "Layers" navigation tab visible 
	PDF_begin_document $p $outfile "openmode=layers"

	PDF_set_info $p "Creator" "PDFlib starter sample"
	PDF_set_info $p "Title" "starter_layer"

	# Load the font 
	set font [PDF_load_font $p "Helvetica" "winansi" ""]

	# Load the Grayscale image 
	set imageGray [PDF_load_image $p "auto" $gray ""]

	# Load the RGB image 
	set imageRGB [PDF_load_image $p "auto" $rgb ""]

	# Define all layers which will be used, and their relationships.
	# This should be done before the first page if the layers are
	# used on more than one page.

	# Define the layer "RGB"
	set layerRGB [PDF_define_layer $p "RGB" ""]

	# Define the layer "Grayscale" which is hidden when opening the
	# document or printing it.
	 
	set layerGray [PDF_define_layer $p "Grayscale" \
		"initialviewstate=false initialprintstate=false"]

	# At most one of the "Grayscale" and "RGB" layers should be visible 
	PDF_set_layer_dependency $p "Radiobtn" "group={$layerGray $layerRGB}"

	# Define the layer "English"
	set layerEN [PDF_define_layer $p "English" ""]

	# Define the layer "German" which is hidden when opening the document
	# or printing it.
	set layerDE [PDF_define_layer $p "German" \
		"initialviewstate=false initialprintstate=false"]

	# At most one of the "English" and "German" layers should be visible 
	PDF_set_layer_dependency $p "Radiobtn" "group={$layerEN $layerDE}"

	# Start page 
	PDF_begin_page_ext $p 0 0 "width=a4.width height=a4.height"

	# Place the RGB image on the layer "RGB"
	PDF_begin_layer $p $layerRGB
	PDF_fit_image $p $imageRGB 100 400 "boxsize={400 300} fitmethod=meet"

	# Place the Grayscale image on the layer "Grayscale"
	PDF_begin_layer $p $layerGray
	PDF_fit_image $p $imageGray 100 400	"boxsize={400 300} fitmethod=meet"
	# Place an English image caption on the layer "English"
	PDF_begin_layer $p $layerEN
	PDF_fit_textline $p "This is the Nesrin image." 100 370 \
	    "font=$font fontsize=20"

	# Place a German image caption on the layer "German"
	PDF_begin_layer $p $layerDE
	PDF_fit_textline $p "Das ist das Nesrin-Bild." 100 370 \
		"font=$font fontsize=20"

	PDF_end_layer $p

	PDF_end_page_ext $p ""

	PDF_end_document $p ""

} result]} {
    puts stderr $result
}

PDF_delete $p
