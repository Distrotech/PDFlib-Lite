#!/usr/bin/env ruby
# $Id: starter_type3font.rb,v 1.1.2.3 2009/11/18 00:16:13 rjs Exp $
# Type 3 font starter:
# Create a simple Type 3 font from vector data
#
# Define a type 3 font with the glyphs "l" and "space" and output text with
# that font. In addition the glyph ".notdef" is defined which any undefined
# character will be mapped to.
#
# Required software: PDFlib/PDFlib+PDI/PPS 7
# Required data: none

require 'PDFlib'

# This is where the data files are. Adjust as necessary.
searchpath = "../data"
outfile = "starter_type3font.pdf"
title = "Starter Type 3 Font"

begin
    p = PDFlib.new

	p.set_parameter("SearchPath", searchpath)

	# This means we must check return values of load_font() etc.
	p.set_parameter("errorpolicy", "return")

	if (p.begin_document(outfile, "") == -1)
        raise "Error: " + p.get_errmsg()
    end

	p.set_info("Creator", "PDFlib Cookbook")
	p.set_info("Title", title + " $Revision: 1.1.2.3 $")

	# Create the font "SimpleFont" containing the glyph "l",
	# the glyph "space" for spaces and the glyph ".notdef" for any
	# undefined character

	p.begin_font("SimpleFont", 0.001, 0.0, 0.0, 0.001, 0.0, 0.0, "")
	p.begin_glyph(".notdef", 266, 0, 0, 0, 0)
	p.end_glyph()
	p.begin_glyph("space", 266, 0, 0, 0, 0)
	p.end_glyph()
	p.begin_glyph("l", 266, 0, 0, 266, 570)
	p.setlinewidth(20)
	p.setdash(0, 0)
	x = 197
	y = 10
	p.moveto(x, y)
	y += 530
	p.lineto(x, y)
	x -= 64
	p.lineto(x, y)
	y -= 530
	p.moveto(x, y)
	x += 128
	p.lineto(x, y)

	p.stroke()
	p.end_glyph()

	p.end_font()

	# Start page
	p.begin_page_ext(0, 0, "width=300 height=200")

	# Load the new "SimpleFont" font
	font = p.load_font("SimpleFont", "winansi", "")
	if font == -1
		raise "Error: " + p.get_errmsg + "\n"
	end

	# Output the characters "l" and "space" of the "SimpleFont" font.
	# The character "x" is undefined and will be mapped to ".notdef"

	p.fit_textline("lll lllxlll", 100, 100, "font=" + font.to_s + \
	    " fontsize=40")

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

# vim: sw=4
