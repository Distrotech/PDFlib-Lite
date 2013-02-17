#!/usr/bin/env ruby
# $Id: starter_layer.rb,v 1.1.2.2 2008/02/28 14:49:59 rjs Exp $
# Starter layer:
# Define several layers, output images and text to them and define
# particular layers to be visible when opening the document
#
# Define two layers for RGB or Grayscale images and two layers for English or
# German image captions. Output images and text on the various layers and
# open the document with the RGB images and English captions visible.
#
# Required software: PDFlib/PDFlib+PDI/PPS 7
# Required data: grayscale and RGB images

require 'PDFlib'

# This is where the data files are. Adjust as necessary.
searchpath = "../data"
outfile = "starter_layer.pdf"
title = "Starter Layer"

rgb = "nesrin.jpg"
gray = "nesrin_gray.jpg"

begin
    p = PDFlib.new

	p.set_parameter("SearchPath", searchpath)

	# This means we must check return values of load_font() etc.
	p.set_parameter("errorpolicy", "return")

	# we use "utf8" as textformat, this allows to use unicode encoding
	p.set_parameter("textformat", "utf8");

	# Open the document with the "Layers" navigation tab visible
	if (p.begin_document(outfile, "openmode=layers") == -1)
        raise "Error: " + p.get_errmsg()
    end

	p.set_info("Creator", "PDFlib Cookbook")
	p.set_info("Title", title + " $Revision: 1.1.2.2 $")

	# Load the font
	font = p.load_font("Helvetica", "unicode", "")
	if font == -1
		raise "Error: " + p.get_errmsg + "\n"
	end

	# Load the Grayscale image
	imageGray = p.load_image("auto", gray, "")
	if imageGray == -1
		raise "Error: " + p.get_errmsg + "\n"
	end

	# Load the RGB image
	imageRGB = p.load_image("auto", rgb, "")
	if imageRGB == -1
		raise "Error: " + p.get_errmsg + "\n"
	end

	#
	# Define all layers which will be used, and their relationships.
	# This should be done before the first page if the layers are
	# used on more than one page.


	# Define the layer "RGB"
	layerRGB = p.define_layer("RGB", "")

	# Define the layer "Grayscale" which is hidden when opening the
	# document or printing it.
	layerGray = p.define_layer("Grayscale",
	    "initialviewstate=false initialprintstate=false")

	# At most one of the "Grayscale" and "RGB" layers should be visible 
	p.set_layer_dependency("Radiobtn", "group={" + layerGray.to_s + " " + \
	    layerRGB.to_s + "}")

	# Define the layer "English"
	layerEN = p.define_layer("English", "")

	# Define the layer "German" which is hidden when opening the document
	# or printing it.
	layerDE = p.define_layer("German",
	    "initialviewstate=false initialprintstate=false")

	# At most one of the "English" and "German" layers should be visible
	p.set_layer_dependency("Radiobtn", "group={" + layerEN.to_s + " " + \
	    layerDE.to_s + "}")

	# Start page
	p.begin_page_ext(0, 0, "width=a4.width height=a4.height")

	# Place the RGB image on the layer "RGB"
	p.begin_layer(layerRGB)
	p.fit_image(imageRGB, 100, 400, "boxsize={400 300} fitmethod=meet")

	# Place the Grayscale image on the layer "Grayscale"
	p.begin_layer(layerGray)
	p.fit_image(imageGray, 100, 400, "boxsize={400 300} fitmethod=meet")

	# Place an English image caption on the layer "English"
	p.begin_layer(layerEN)
	p.fit_textline("This is the Nesrin image.", 100, 370, "font=" + \
	    font.to_s + " fontsize=20")

	# Place a German image caption on the layer "German" 
	p.begin_layer(layerDE)
	p.fit_textline("Das ist das Nesrin-Bild.", 100, 370, "font=" + \
	    font.to_s + " fontsize=20")

	p.end_layer()

	p.end_page_ext("")

	p.end_document("")

rescue  PDFlibException => pe
  print "PDFlib exception occurred:\n"
  print "[" + pe.get_errnum.to_s + "] " + pe.get_apiname + \
		": " + pe.get_errmsg + "\n"
rescue  Exception => e
  print e.backtrace.join("\n") + "\n" + e.to_s
ensure
  p.delete() if p
end

# vim: sw=4
