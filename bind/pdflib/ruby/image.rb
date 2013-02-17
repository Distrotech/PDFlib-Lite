#!/usr/bin/env ruby
#
#  $Id: image.rb,v 1.3.2.3 2008/02/28 14:49:59 rjs Exp $
#
#  PDFlib client: image example in Ruby
# 

require 'PDFlib'

imagefile = "nesrin.jpg"
# This is where font/image/PDF input files live. Adjust as necessary.
searchpath = "../data"

begin
  p = PDFlib.new

  # This means we must check return values of load_font() etc.
  p.set_parameter("errorpolicy", "return")

  p.set_parameter("SearchPath", searchpath)

  if (p.begin_document("image.pdf", "") == -1)
    raise "Error: " + p.get_errmsg()
  end

  p.set_info("Creator", "image.rb")
  p.set_info("Author", "Thomas Merz")
  p.set_info("Title", "image sample (Ruby)")

  image = p.load_image("auto", imagefile, "")
  if (image == -1)
    raise "Error: " + p.get_errmsg()
  end

  # dummy page size, will be adjusted by PDF_fit_image()
  p.begin_page_ext(10, 10, "")
  p.fit_image(image, 0.0, 0.0, "adjustpage")
  p.close_image(image)
  p.end_page_ext("")

  p.end_document("")

rescue  PDFlibException => pe
  print "PDFlib exception occurred in image sample:\n"
  print "[" + pe.get_errnum.to_s + "] " + pe.get_apiname + \
		  ": " + pe.get_errmsg + "\n"
rescue Exception => e
  print e.backtrace.join("\n") + "\n" + e.to_s
ensure
  p.delete() if p
end

# vim: sw=2
