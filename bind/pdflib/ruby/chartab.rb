#!/usr/bin/env ruby
#
# $Id: chartab.rb,v 1.3.2.4 2008/02/28 14:49:59 rjs Exp $
#
# PDFlib client: character table
#

require 'PDFlib'

# change these as required
fontname = "LuciduxSans-Oblique"

# This is where font/image/PDF input files live. Adjust as necessary.
searchpath = "../data"

# list of encodings to use
encodings = ["iso8859-1", "iso8859-2", "iso8859-15"]
FONTSIZE	= 16
TOP		= 700
LEFT		= 50
YINCR	= 2*FONTSIZE
XINCR	= 2*FONTSIZE

# whether or not to embed the font 
embed = 1

begin
  p = PDFlib.new

  # This means we must check return values of load_font() etc.
  p.set_parameter("errorpolicy", "return")

  p.set_parameter("SearchPath", searchpath)

  if (p.begin_document("chartab.pdf",
      "destination {type fitwindow page 1}") == -1)
    raise "Error: " + p.get_errmsg()
  end

  p.set_info("Creator", "chartab.rb")
  p.set_info("Author", "Thomas Merz")
  p.set_info("Title", "Character table (Ruby)")

  # loop over all encodings
  encodings.each { |encoding|
    p.begin_page_ext(595, 842, "");  # start a new page

    # print the heading and generate the bookmark 
    font = p.load_font("Helvetica", "winansi", "")
    if font == -1
      raise "Error: " + p.get_errmsg + "\n"
    end

    p.setfont(font, FONTSIZE)
    if (embed == 1)
      buf = fontname + " (" + encoding + ") embedded"
    else
      buf = fontname + " (" + encoding + ") not  embedded"
    end

    p.show_xy(buf, LEFT - XINCR, TOP + 3 * YINCR)
    p.create_bookmark(buf, "")

    # print the row and column captions 
    p.setfont(font, 2 * FONTSIZE/3)

    0.step(16, 1) do |row|
      buf = sprintf("x%X", row)
      p.show_xy(buf, LEFT + row*XINCR, TOP + YINCR)

      buf = sprintf("%Xx", $row)
      p.show_xy(buf, LEFT - XINCR, TOP - row * YINCR)
    end

    # print the character table
    if (embed == 1)
	optlist = "embedding"
    else
	optlist = ""
    end
    font = p.load_font(fontname, encoding, optlist)
    if font == -1
      die("Error: " + p.get_errmsg + "\n")
    end

    p.setfont(font, FONTSIZE)

    y = TOP
    x = LEFT

    0.step(16, 1) do |row|
      0.step(16,1) do |col|
	buf = sprintf("%c", 16 * row + col)
	p.show_xy(buf, x, y)
	x += XINCR
      end
      x = LEFT
      y -= YINCR
    end

    p.end_page_ext("")
  }
  p.end_document("")

rescue  PDFlibException => pe
  print "PDFlib exception occurred in chartab sample:\n"
  print "[" + pe.get_errnum.to_s + "] " + pe.get_apiname + \
		  ": " + pe.get_errmsg + "\n"
rescue  Exception => e
  print e.backtrace.join("\n") + "\n" + e.to_s
ensure
  p.delete() if p
end

# vim: sw=2
