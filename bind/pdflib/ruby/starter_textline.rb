#!/usr/bin/env ruby
# $Id: starter_textline.rb,v 1.1.2.2 2008/02/28 14:49:59 rjs Exp $
# Starter text line:
# Demonstrate various options for placing a text line
#
# Place a text line with different font sizes.
# Output overlined, stroke out, and underlined text.
# Output text and define character spacing, work spacing, or horizontal
# scaling.
# Output text with a defined fill color. Output text including its outlines
# with a defined stroke color.
# Place text into a box at various positions. Place text completely into a box
# with automatic scaling if required.
#
# Required software: PDFlib Lite/PDFlib/PDFlib+PDI/PPS 7
# Required data: none

require 'PDFlib'

# This is where the data files are. Adjust as necessary.
searchpath = "../input"
outfile = "starter_textline.pdf"
title = "Starter Text Line"

x = 10
xt = 280
y = 800
yoff = 50
textline = "Giant Wing Paper Plane"

begin
    p = PDFlib.new

	p.set_parameter("SearchPath", searchpath)

	# This means we must check return values of load_font() etc.
	p.set_parameter("errorpolicy", "return")

	# we use "utf8" as textformat, this allows to use unicode encoding
	p.set_parameter("textformat", "utf8");

	# Set an output path according to the name of the topic
	if (p.begin_document(outfile, "") == -1)
        raise "Error: " + p.get_errmsg()
    end

	p.set_info("Creator", "PDFlib Cookbook")
	p.set_info("Title", title + " $Revision: 1.1.2.2 $")

	# Start Page
	p.begin_page_ext(0, 0, "width=a4.width height=a4.height")

	# For PDFlib Lite: change "unicode" to "winansi"
	font = p.load_font("Helvetica", "unicode", "")
	if font == -1
		raise "Error: " + p.get_errmsg + "\n"
	end

	# Set the font with a font size of 14
	p.setfont(font, 14)


	# Place the text line without any options applied
	p.fit_textline(textline, x, y, "")

	# Output descriptive text
	p.fit_textline("fit_textline() without any options", xt, y,
		"fontsize=12")


	# Place the text with a different font size
	optlist = "fontsize=22"

	p.fit_textline(textline, x, y-=yoff, optlist) # sample text
	p.fit_textline(optlist, xt, y, "fontsize=12") # description


	# Place stroke out text
	optlist = "strikeout"

	p.fit_textline(textline, x, y-=yoff, optlist) # sample text
	p.fit_textline(optlist, xt, y, "fontsize=12") # description


	# Place underlined text
	optlist = "underline underlinewidth=7% underlineposition=-20%"

	p.fit_textline(textline, x, y-=yoff, optlist) # sample text
	p.fit_textline(optlist, xt, y, "fontsize=12") # description


	# Place overlined text
	optlist = "overline"

	p.fit_textline(textline, x, y-=yoff, optlist) # sample text
	p.fit_textline(optlist, xt, y, "fontsize=12") # description


	# Place the text with a horizontal scaling of 150%
	optlist = "horizscaling=150%"

	p.fit_textline(textline, x, y-=yoff, optlist) # sample text
	p.fit_textline(optlist, xt, y, "fontsize=12") # description


	# Place the text with a character spacing of 30% of the font size
	optlist = "charspacing=30%"

	p.fit_textline(textline, x, y-=yoff, optlist) # sample text
	p.fit_textline(optlist, xt, y, "fontsize=12") # description


	# Place the text with a word spacing of 50% of the font size
	optlist = "wordspacing=50%"

	p.fit_textline(textline, x, y-=yoff, optlist) # sample text
	p.fit_textline(optlist, xt, y, "fontsize=12") # description


	# Place the text with a different fill color
	optlist = "fillcolor={rgb 0.5 0.2 0.5}"

	p.fit_textline(textline, x, y-=yoff, optlist)
	p.fit_textline(optlist, xt, y, "fontsize=12")


	# Place the text including its outlines using a text rendering mode of
	# 2 for "filling and stroking text" and different fill and stroke
	# colors

	optlist =
		"fontsize=22 fillcolor={rgb 0.6 0.3 0.6} strokecolor={gray 0} " + \
		"strokewidth=0.4 textrendering=2"

	p.fit_textline(textline, x, y-=yoff, optlist)

	# Output descriptive text
	p.fit_textline("fillcolor={rgb 0.6 0.3 0.6} strokecolor={gray 0} ",
		xt, y+10, "fontsize=12")
	p.fit_textline("strokewidth=0.4 textrendering=2 fontsize=22",
		xt, y-5, "fontsize=12")


	# Place the text with its outlines using a text rendering mode of
	# 1 for "stroking text" and a stroke color of black

	optlist =
		"fontsize=22 strokecolor={gray 0} strokewidth=0.4 textrendering=1"

	p.fit_textline(textline, x, y-=yoff, optlist)

	# Output descriptive text
	p.fit_textline("strokecolor={gray 0} strokewidth=0.4", xt, y+10,
		"fontsize=12")
	p.fit_textline("textrendering=1 fontsize=22", xt, y-=5,
		"fontsize=12")


	# Place the text in a box with default positioning and fitting
	optlist = "boxsize={200 20} showborder"

	p.fit_textline(textline, x, y-=yoff, optlist) # sample text
	p.fit_textline(optlist, xt, y+3, "fontsize=12") # description


	# Place the text in a box on the top right
	optlist = "boxsize={200 20} position={top right} showborder"

	p.fit_textline(textline, x, y-=yoff, optlist) # sample text
	p.fit_textline(optlist, xt, y+3, "fontsize=12") # description


	# Use "fitmethod=clip" to place the text in a box not large enough to
	# show the complete text. The text will be clipped.

	optlist = "boxsize={130 20} fitmethod=clip showborder"

	p.fit_textline(textline, x, y-=yoff, optlist) # sample text
	p.fit_textline(optlist, xt, y+3, "fontsize=12") # description


	# Fit the text into the box automatically with "fitmethod=auto".
	# In this case, if the text doesn't fit into the box a distortion
	# factor is calculated which makes the text fit into the box. If this
	# factor is larger than the "shrinklimit" option the text will
	# be distorted by that factor. Otherwise, the font size will be
	# be decreased until until the text fits into the box.


	# Use "fitmethod=auto" to place the text in a box not large enough to
	# show the complete text. The text will be distorted.

	optlist = "boxsize={130 20} fitmethod=auto showborder"

	p.fit_textline(textline, x, y-=yoff, optlist) # sample text
	p.fit_textline(optlist, xt, y+3, "fontsize=12") # description


	# Use "fitmethod=auto" to place the text in a box too small to show the
	# complete text. The font size will be reduced until the text fits into
	# the box.

	optlist = "boxsize={100 20} fitmethod=auto showborder"

	p.fit_textline(textline, x, y-=yoff, optlist) # sample text
	p.fit_textline(optlist, xt, y+3, "fontsize=12") # description

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
