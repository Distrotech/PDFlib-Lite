#!/usr/bin/env ruby
# $Id: starter_tagged.rb,v 1.2.2.5 2008/02/28 14:49:59 rjs Exp $
#
# Tagged PDF starter:
# Create document with structure information for reflow and accessibility
#
# required software: PDFlib/PDFlib+PDI/PPS 7
# required data: none (dummy text created in program)
#/

require 'PDFlib'


# This is where the data files are. Adjust as necessary.
String searchpath = "../data"

begin
  p = PDFlib.new

  # This means we must check return values of load_font() etc.
  p.set_parameter("errorpolicy", "return")

  p.set_parameter("SearchPath", searchpath)

  if (p.begin_document("starter_tagged.pdf", "tagged=true") == -1)
    raise "Error: " + p.get_errmsg()
  end

  p.set_info("Creator", "PDFlib starter sample")
  p.set_info("Title", "starter_tagged")

  # Automatically create spaces between chunks of text
  p.set_parameter("autospace", "true")

  # open the first structure element as a child of the document
  # structure root (=0)
  #
  id = p.begin_item("P", "Title = {Simple Paragraph}")

  p.begin_page_ext(0, 0, "width=a4.width height=a4.height")

  font = p.load_font("Helvetica", "winansi", "")

  if font == -1
    raise "Error: " + p.get_errmsg + "\n"
  end

  p.setfont(font, 24.0)

  p.show_xy("Hello, Tagged PDF!", 50, 700)
  p.continue_text("This PDF has a very simple")
  p.continue_text("document structure.")

  p.end_item(id)

  # The page number is created as an artifact; it will be
  # ignored when reflowing the page in Acrobat.
  #
  id_artifact = p.begin_item("Artifact", "")
  p.show_xy("Page 1", 250, 100)
  p.end_item(id_artifact)

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
