#!/usr/bin/env ruby
#
# $Id: hello.rb,v 1.6.2.4 2008/02/28 14:49:59 rjs Exp $
#
# PDFlib client: hello example in Ruby
#

require 'PDFlib'

begin
  p = PDFlib.new

  # This means we must check return values of load_font() etc.
  p.set_parameter("errorpolicy", "return")

  if (p.begin_document("hello.pdf", "") == -1)
    raise  "Error: " + p.get_errmsg
  end

  p.set_info("Creator", "hello.rb")
  p.set_info("Author", "Thomas Merz")
  p.set_info("Title", "Hello world (Ruby)!")

  p.begin_page_ext(595, 842, "")

  font = p.load_font("Helvetica-Bold", "winansi", "")
  if font == -1
    raise "Error: " + p.get_errmsg + "\n"
  end


  p.setfont(font, 24)

  p.set_text_pos(50, 700)
  p.show("Hello world!")
  p.continue_text("(says Ruby)")
  p.end_page_ext("")

  p.end_document("")

rescue  PDFlibException => pe
  print "PDFlib exception occurred in hello sample:\n"
  print "[" + pe.get_errnum.to_s + "] " + pe.get_apiname + \
		  ": " + pe.get_errmsg + "\n"
rescue  Exception => e
  print e.backtrace.join("\n") + "\n" + e.to_s
ensure
  p.delete() if p
end

# vim: sw=2
