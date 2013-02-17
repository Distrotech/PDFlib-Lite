#!/usr/bin/env ruby
#
# $Id: quickreference.rb,v 1.5.2.4 2008/02/28 14:49:59 rjs Exp $
#
# PDFlib client:  mini imposition demo
#

require 'PDFlib'

maxrow = 2
maxcol = 2
width = 500
height = 770
infile = "reference.pdf"
# This is where font/image/PDF input files live. Adjust as necessary.
searchpath = "../data"

begin
  p = PDFlib.new

  # This means we must check return values of load_font() etc.
  p.set_parameter("errorpolicy", "return")

  p.set_parameter("SearchPath", searchpath)

  if (p.begin_document("quickreference.pdf", "") == -1)
    raise "Error: " + p.get_errmsg()
  end

  p.set_info("Creator", "quickreference.rb")
  p.set_info("Author", "Thomas Merz")
  p.set_info("Title", "imposition demo (Ruby)")

  manual = p.open_pdi_document(infile, "")
  if (manual == -1)
    raise "Error: " + p.get_errmsg()
  end

  row = 0
  col = 0

  p.set_parameter("topdown", "true")

  endpage = p.pcos_get_number(manual, "length:pages")

  1.step(endpage, 1) do |pageno|
    if (row == 0 && col == 0)
      p.begin_page_ext(width, height, "")
      font = p.load_font("Helvetica-Bold", "winansi", "")
      if font == -1
	raise "Error: " + p.get_errmsg + "\n"
      end

      p.setfont(font, 18)
      p.set_text_pos(24, 24)
      p.show("PDFlib Quick Reference")
    end

    page = p.open_pdi_page(manual, pageno, "")

    if (page == -1)
      raise "Error: " + p.get_errmsg()
    end

    p.fit_pdi_page(page, width/maxcol*col,
	(row + 1) * height/maxrow, "scale " + (1.0/maxrow).to_s)
    p.close_pdi_page(page)

    col = col + 1
    if (col == maxcol)
      col = 0
      row = row + 1
    end
    if (row == maxrow)
      row = 0
      p.end_page_ext("")
    end
  end

  # finish the last partial page
  if (row != 0 || col != 0)
    p.end_page_ext("")
  end

  p.end_document("")
  p.close_pdi_document(manual)

rescue  PDFlibException => pe
  print "PDFlib exception occurred in quickreference sample:\n"
  print "[" + pe.get_errnum.to_s + "] " + pe.get_apiname + \
		  ": " + pe.get_errmsg + "\n"
rescue  Exception => e
  print e.backtrace.join("\n") + "\n" + e.to_s
ensure
  p.delete() if p
end

# vim: sw=2
