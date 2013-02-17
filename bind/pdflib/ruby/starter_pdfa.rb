#!/usr/bin/env ruby
# $Id: starter_pdfa.rb,v 1.3.2.4 2008/02/28 14:49:59 rjs Exp $
#
# PDF/A starter:
# Create PDF/A-compliant output
#
# required software: PDFlib/PDFlib+PDI/PPS 7
# required data: font file, image file
#/

require 'PDFlib'


searchpath = "../data"

imagefile = "nesrin.jpg"

begin
  p = PDFlib.new

  # This means we must check return values of load_font() etc.
  p.set_parameter("errorpolicy", "return")

  p.set_parameter("SearchPath", searchpath)

  # we use "utf8" as textformat, this allows to use unicode encoding
  p.set_parameter("textformat", "utf8");

  # PDF/A-1a requires Tagged PDF
  if (p.begin_document("starter_pdfa.pdf", "pdfa=PDF/A-1b:2005") == -1)
    raise "Error: " + p.get_errmsg()
  end

  #
  # We use sRGB as output intent since it allows the color
  # spaces CIELab, ICC-based, grayscale, and RGB.
  #
  # If you need CMYK color you must use a CMYK output profile.
  #

  p.load_iccprofile("sRGB", "usage=outputintent")

  p.set_info("Creator", "PDFlib starter sample")
  p.set_info("Title", "starter_pdfa")

  p.begin_page_ext(595, 842, "")

  # Font embedding is required for PDF/A
  font = p.load_font("LuciduxSans-Oblique", "unicode", "embedding")
  if font == -1
    raise "Error: " + p.get_errmsg + "\n"
  end

  p.setfont(font, 24)

  p.fit_textline("PDF/A-1b:2005 starter", 50, 700, "")

  # We can use an RGB image since we already supplied an
  # output intent profile.
  #
  image = p.load_image("auto", imagefile, "")

  if (image == -1)
    raise "Error: " + p.get_errmsg()
  end

  # Place the image at the bottom of the page
  p.fit_image(image, 0.0, 0.0, "scale=0.5")

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

# vim: sw=2
