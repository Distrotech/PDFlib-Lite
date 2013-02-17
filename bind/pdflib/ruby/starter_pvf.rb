#!/usr/bin/env ruby
# $Id: starter_pvf.rb,v 1.1.2.2 2008/02/28 14:49:59 rjs Exp $
# PDFlib Virtual File system (PVF):
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

require 'PDFlib'

# This is where the data files are. Adjust as necessary.
searchpath = "../data"
outfile = "starter_pvf.pdf"
title = "PDFlib Virtual File System"

begin
    p = PDFlib.new

	p.set_parameter("SearchPath", searchpath)

	# This means we must check return values of load_font() etc.
	p.set_parameter("errorpolicy", "return")

	# Set an output path according to the name of the topic
	if (p.begin_document(outfile, "") == -1)
        raise "Error: " + p.get_errmsg()
    end

	p.set_info("Creator", "PDFlib Cookbook")
	p.set_info("Title", title + " $Revision: 1.1.2.2 $")

	# We just read some image data from a file to really benefit
	# from using PVF read the data from a Web site or a database instead

 	imageData = IO.read("../data/PDFlib-logo.tif")

	p.create_pvf("/pvf/image", imageData, "")

	# Load the image from the PVF
	image = p.load_image("auto", "/pvf/image" , "")
	if (image == -1)
        raise "Error: " + p.get_errmsg()
    end

	# Fit the image on page 1
	p.begin_page_ext(595, 842, "")

	p.fit_image(image, 350, 750, "")

	p.end_page_ext("")

	# Fit the image on page 2
	p.begin_page_ext(595, 842, "")

	p.fit_image(image, 350, 50, "")

	p.end_page_ext("")

	# Delete the virtual file to free the allocated memory

	p.delete_pvf("/pvf/image")

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
