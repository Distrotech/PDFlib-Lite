#!/usr/bin/env ruby
# $Id: starter_basic.rb,v 1.3.2.5 2008/02/28 14:49:59 rjs Exp $
#
# Basic starter:
# Create some simple text, vector graphics and image output
#
# required software: PDFlib Lite/PDFlib/PDFlib+PDI/PPS 7
# required data: none
#

require 'PDFlib'

# This is where the data files are. Adjust as necessary.
searchpath = "../data"

imagefile = "nesrin.jpg"

begin
  p = PDFlib.new

  # This means we must check return values of load_font() etc.
  p.set_parameter("errorpolicy", "return")

  p.set_parameter("SearchPath", searchpath)

  # we use "utf8" as textformat, this allows to use unicode encoding
  p.set_parameter("textformat", "utf8");

  if (p.begin_document("starter_basic.pdf", "") == -1)
    raise "Error: " + p.get_errmsg()
  end

  p.set_info("Creator", "PDFlib starter sample")
  p.set_info("Title", "starter_basic")

  # We load the image before the first page, and use it
  # on all pages
  #
  image = p.load_image("auto", imagefile, "")

  if (image == -1)
    raise "Error: " + p.get_errmsg()
  end

  # Page 1
  p.begin_page_ext(595, 842, "")

  # For PDFlib Lite: change "unicode" to "winansi"
  font = p.load_font("Helvetica-Bold", "unicode", "")
  if font == -1
    raise "Error: " + p.get_errmsg + "\n"
  end

  p.setfont(font, 24)

  p.set_text_pos(50, 700)
  p.show("Hello world!")

  p.fit_image(image,  0.0,  0.0, "scale=0.25")

  p.end_page_ext("")

  # Page 2
  p.begin_page_ext(595, 842, "")

  # red rectangle
  p.setcolor("fill", "rgb", 1.0, 0.0, 0.0, 0.0)
  p.rect(200, 200, 250, 150)
  p.fill()

  # blue circle
  p.setcolor("fill", "rgb", 0.0, 0.0, 1.0, 0.0)
  p.arc(400, 600, 100, 0, 360)
  p.fill()

  # thick gray line
  p.setcolor("stroke", "gray", 0.5, 0.0, 0.0, 0.0)
  p.setlinewidth(10)
  p.moveto(100, 500)
  p.lineto(300, 700)
  p.stroke()

  # Using the same image handle means the data will be copied
  # to the PDF only once, which saves space.
  #
  p.fit_image(image, 150.0, 25.0, "scale=0.25")
  p.end_page_ext("")

  # Page 3
  p.begin_page_ext(595, 842, "")

  # Fit the image to a box of predefined size (without distortion)
  optlist = "boxsize={400 400} position={center} fitmethod=meet"

  p.fit_image(image, 100, 200, optlist)

  p.end_page_ext("")

  p.close_image(image)
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
# vim: sw=2
