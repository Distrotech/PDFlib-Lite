#!/usr/bin/env ruby
# $Id: starter_pdfmerge.rb,v 1.2.2.4 2008/02/28 14:49:59 rjs Exp $
#
# PDF merge starter:
# Merge pages from multiple PDF documents; interactive elements (e.g. 
# bookmarks) will be dropped.
#
# required software: PDFlib+PDI/PPS 7
# required data: PDF documents
#

require 'PDFlib'

# This is where the data files are. Adjust as necessary.
String searchpath = "../data"

pdffiles = [
	"PDFlib-real-world.pdf",
	"PDFlib-datasheet.pdf",
	"TET-datasheet.pdf",
	"PLOP-datasheet.pdf",
	"pCOS-datasheet.pdf"
]

begin
  p = PDFlib.new

  # This means we must check return values of load_font() etc.
  p.set_parameter("errorpolicy", "return")

  p.set_parameter("SearchPath", searchpath)

  if (p.begin_document("starter_pdfmerge.pdf", "") == -1)
    raise "Error: " + p.get_errmsg()
  end

  p.set_info("Creator", "PDFlib starter sample")
  p.set_info("Title", "starter_pdfmerge")

  pdffiles.each { |pdffile|
    # Open the input PDF
    indoc = p.open_pdi_document(pdffile, "")
    if (indoc == -1)
      print "Error: " + p.get_errmsg()
      continue
    end

    endpage = p.pcos_get_number(indoc, "/Root/Pages/Count")

    # Loop over all pages of the input document
    1.step(endpage, 1) do |pageno|
      page = p.open_pdi_page(indoc, pageno, "")

      if (page == -1)
	print "Error: " + p.get_errmsg()
	continue
      end
      # Dummy page size; will be adjusted later
      p.begin_page_ext(10, 10, "")

      # Create a bookmark with the file name
      if (pageno == 1)
	p.create_bookmark(pdffile, "")
      end

      # Place the imported page on the output page, and
      # adjust the page size
      #/
      p.fit_pdi_page(page, 0, 0, "adjustpage")
      p.close_pdi_page(page)

      p.end_page_ext("")
    end
    p.close_pdi_document(indoc)
  }

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
