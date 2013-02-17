#!/usr/bin/env ruby
# $Id: starter_pdfx.rb,v 1.6.2.4 2008/02/28 14:49:59 rjs Exp $
#
# PDF/X starter:
# Create PDF/X-compliant output
#
# required software: PDFlib/PDFlib+PDI/PPS 7
# required data: font file, image file, ICC profile
#                (see www.pdflib.com for ICC profiles)
#/

require 'PDFlib'

# This is where the data files are. Adjust as necessary
String searchpath = "../data"

String imagefile = "nesrin.jpg"

begin
  p = PDFlib.new

  # This means we must check return values of load_font() etc.
  p.set_parameter("errorpolicy", "return")

  p.set_parameter("SearchPath", searchpath)

  # we use "utf8" as textformat, this allows to use unicode encoding
  p.set_parameter("textformat", "utf8");

  if (p.begin_document("starter_pdfx.pdf", "pdfx=PDF/X-3:2002") == -1)
    raise "Error: " + p.get_errmsg()
  end

  p.set_info("Creator", "PDFlib starter sample")
  p.set_info("Title", "starter_pdfx")

  #
  # You can use one of the Standard output intents (e.g. for SWOP
  # printing) which do not require an ICC profile:

  #p.load_iccprofile("CGATS TR 001", "usage=outputintent")

  # However, if you use ICC or Lab color you must load an ICC
  # profile as output intent:
  #
  if (p.load_iccprofile("ISOcoated.icc", "usage=outputintent") == -1)
      raise "Error: " +  p.get_errmsg() + "\n" \
	+ "Please install the ICC profile package from " \
	+ "www.pdflib.com to run the PDF/X starter sample.\n"
  end

  p.begin_page_ext(595, 842, "")

  # Font embedding is required for PDF/X
  font = p.load_font("LuciduxSans-Oblique", "unicode", "embedding")

  if font == -1
    raise "Error: " + p.get_errmsg + "\n"
  end

  p.setfont(font, 24)

  spot = p.makespotcolor("PANTONE 123 C")
  p.setcolor("fill", "spot", spot, 1.0, 0.0, 0.0)
  p.fit_textline("PDF/X-3:2002 starter", 50, 700, "")

  # The RGB image below needs an ICC profile; we use sRGB.
  icc = p.load_iccprofile("sRGB", "")
  image = p.load_image("auto", imagefile, "iccprofile=" + icc.to_s)

  if (image == -1)
    raise "Error: " + p.get_errmsg()
  end

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
