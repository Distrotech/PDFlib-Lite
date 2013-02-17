#!/usr/bin/python
# Id: starter_textline.pl,v 1.1.2.2 2007/12/21 14:04:32 rjs Exp 
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

# This is where the data files are. Adjust as necessary.
searchpath = "../data"
outfile = "starter_textline.pdf"
title = "Starter Text Line"

x = 10
xt = 280
y = 800
yoff = 50
textline = "Giant Wing Paper Plane"


from sys import *
from pdflib_py import *

# create a new PDFlib object
p = PDF_new()

try:
  try:
    PDF_set_parameter(p, "SearchPath", searchpath)

    # This means we must check return values of load_font() etc.
    PDF_set_parameter(p, "errorpolicy", "return")

    # Set an output path according to the name of the topic
    if PDF_begin_document(p, outfile, "") == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    PDF_set_info(p, "Creator", "PDFlib Cookbook")
    buf = title + '  Revision: 1.1.2.2 '
    PDF_set_info(p, "Title", buf)

    # Start Page
    PDF_begin_page_ext(p, 0, 0, "width=a4.width height=a4.height")

    # For PDFlib Lite: change "unicode" to "winansi"
    font = PDF_load_font(p, "Helvetica", "winansi", "")

    if font == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    # Set the font with a font size of 14
    PDF_setfont(p, font, 14)


    # Place the text line without any options applied
    PDF_fit_textline(p, textline, x, y, "")

    # Output descriptive text
    PDF_fit_textline(p, "fit_textline() without any options", xt, y,
        "fontsize=12")


    # Place the text with a different font size
    optlist = "fontsize=22"
    
    y = y - yoff
    PDF_fit_textline(p, textline, x, y, optlist); # sample text
    PDF_fit_textline(p, optlist, xt, y, "fontsize=12"); # description
    
    
    # Place stroke out text
    optlist = "strikeout"
    
    y = y - yoff
    PDF_fit_textline(p, textline, x, y, optlist); # sample text
    PDF_fit_textline(p, optlist, xt, y, "fontsize=12"); # description
    
    
    # Place underlined text
    optlist = "underline underlinewidth=7% underlineposition=-20%"
    
    y = y - yoff
    PDF_fit_textline(p, textline, x, y, optlist); # sample text
    PDF_fit_textline(p, optlist, xt, y, "fontsize=12"); # description
    
    
    # Place overlined text
    optlist = "overline"
    
    y = y - yoff
    PDF_fit_textline(p, textline, x, y, optlist); # sample text
    PDF_fit_textline(p, optlist, xt, y, "fontsize=12"); # description
    
    
    # Place the text with a horizontal scaling of 150%
    optlist = "horizscaling=150%"
    
    y = y - yoff
    PDF_fit_textline(p, textline, x, y, optlist); # sample text
    PDF_fit_textline(p, optlist, xt, y, "fontsize=12"); # description
    
    
    # Place the text with a character spacing of 30% of the font size
    optlist = "charspacing=30%"
    
    y = y - yoff
    PDF_fit_textline(p, textline, x, y, optlist); # sample text
    PDF_fit_textline(p, optlist, xt, y, "fontsize=12"); # description
    
    
    # Place the text with a word spacing of 50% of the font size
    optlist = "wordspacing=50%"
    
    y = y - yoff
    PDF_fit_textline(p, textline, x, y, optlist); # sample text
    PDF_fit_textline(p, optlist, xt, y, "fontsize=12"); # description
    
    
    # Place the text with a different fill color
    optlist = "fillcolor={rgb 0.5 0.2 0.5}"
    
    y = y - yoff
    PDF_fit_textline(p, textline, x, y, optlist)
    PDF_fit_textline(p, optlist, xt, y, "fontsize=12")
    
    
    # Place the text including its outlines using a text rendering mode of
    # 2 for "filling and stroking text" and different fill and stroke
    # colors
    
    optlist = "fontsize=22 fillcolor={rgb 0.6 0.3 0.6} strokecolor={gray 0} strokewidth=0.4 textrendering=2"
    
    y = y - yoff
    PDF_fit_textline(p, textline, x, y, optlist)
    
    # Output descriptive text
    PDF_fit_textline(p, "fillcolor={rgb 0.6 0.3 0.6} strokecolor={gray 0} ",
        xt, y+10, "fontsize=12")
    PDF_fit_textline(p, "strokewidth=0.4 textrendering=2 fontsize=22",
        xt, y-5, "fontsize=12")
    
    
    # Place the text with its outlines using a text rendering mode of
    # 1 for "stroking text" and a stroke color of black
    
    optlist = "fontsize=22 strokecolor={gray 0} strokewidth=0.4 textrendering=1"
    
    y = y - yoff
    PDF_fit_textline(p, textline, x, y, optlist)
    
    # Output descriptive text
    PDF_fit_textline(p, "strokecolor={gray 0} strokewidth=0.4", xt, y+10,
        "fontsize=12")
    y = y - 5
    PDF_fit_textline(p, "textrendering=1 fontsize=22", xt, y, "fontsize=12")
    
    
    # Place the text in a box with default positioning and fitting
    optlist = "boxsize={200 20} showborder"
    
    y = y - yoff
    PDF_fit_textline(p, textline, x, y, optlist);   # sample text
    PDF_fit_textline(p, optlist, xt, y+3, "fontsize=12"); # description
    
    
    # Place the text in a box on the top right
    optlist = "boxsize={200 20} position={top right} showborder"
    
    y = y - yoff
    PDF_fit_textline(p, textline, x, y, optlist);   # sample text
    PDF_fit_textline(p, optlist, xt, y+3, "fontsize=12"); # description
    
    
    # Use "fitmethod=clip" to place the text in a box not large enough to 
    # show the complete text. The text will be clipped.
    
    optlist = "boxsize={130 20} fitmethod=clip showborder"
    
    y = y - yoff
    PDF_fit_textline(p, textline, x, y, optlist);   # sample text
    PDF_fit_textline(p, optlist, xt, y+3, "fontsize=12"); # description
    
    
    # Fit the text into the box automatically with "fitmethod=auto".
    # In this case, if the text doesn't fit into the box a distortion
    # factor is calculated which makes the text fit into the box. If this 
    # factor is larger than the "shrinklimit" option the text will
    # be distorted by that factor. Otherwise, the font size will be
    # be decreased until until the text fits into the box.
    
                
    # Use "fitmethod=auto" to place the text in a box not large enough to 
    # show the complete text. The text will be distorted.
    
    optlist = "boxsize={130 20} fitmethod=auto showborder"
    
    y = y - yoff
    PDF_fit_textline(p, textline, x, y, optlist);   # sample text
    PDF_fit_textline(p, optlist, xt, y+3, "fontsize=12"); # description
 
    
    # Use "fitmethod=auto" to place the text in a box too small to show the
    # complete text. The font size will be reduced until the text fits into
    # the box.
    
    optlist = "boxsize={100 20} fitmethod=auto showborder"
    
    y = y - yoff
    PDF_fit_textline(p, textline, x, y, optlist);   # sample text
    PDF_fit_textline(p, optlist, xt, y+3, "fontsize=12"); # description

    PDF_end_page_ext(p, "")

    PDF_end_document(p, "")

  except PDFlibException:
    print("PDFlib exception occurred:\n[%d] %s: %s" %
	((PDF_get_errnum(p)), PDF_get_apiname(p),  PDF_get_errmsg(p)))

  except Exception:
    print("Exception occurred: %s" % (exc_info()[0]))

finally:
    PDF_delete(p)
