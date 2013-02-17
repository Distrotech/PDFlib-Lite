#!/usr/bin/python
# $Id: chartab.py,v 1.12.2.3 2009/03/02 14:14:07 rjs Exp $
#
# PDFlib client: hello character table in Python
#

from sys import *
from pdflib_py import *

# change these as required
fontname = "LuciduxSans-Oblique"

# This is where font/image/PDF input files live. Adjust as necessary.
searchpath = "../data"

# list of encodings to use
encoding = ["iso8859-1", "iso8859-2", "iso8859-15"]

# whether or not to embed the font
embed = ""
# embed = "not "
embedding = "embedding"
# embedding = ""

ENCODINGS       = 3
FONTSIZE        = 16
TOP             = 700
LEFT            = 50
YINCR           = 2*FONTSIZE
XINCR           = 2*FONTSIZE

# create a new PDFlib object
p = PDF_new()

try:
  try:
    # This means we must check return values of load_font() etc.
    PDF_set_parameter(p, "errorpolicy", "return")

    PDF_set_parameter(p, "SearchPath", searchpath)

    # open new PDF file
    if PDF_begin_document(p, "chartab.pdf", "destination {type fitwindow page 1}") == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    PDF_set_info(p, "Creator", "chartab.py")
    PDF_set_info(p, "Author", "Thomas Merz")
    PDF_set_info(p, "Title", "Character table (Python)")

    # loop over all encodings
    for page in range(0, ENCODINGS, 1):
        PDF_begin_page_ext(p, 595, 842, "")

        # print the heading and generate the bookmark
        font = PDF_load_font(p, "Helvetica", "unicode", "")
        if font == -1:
            raise PDFlibException("Error: " + PDF_get_errmsg(p))

        PDF_setfont(p, font, FONTSIZE)
        buf = fontname + " (" + encoding[page] + ") " + embed + "embedded"

        PDF_show_xy(p, buf, LEFT - XINCR, TOP + 3 * YINCR)
        PDF_create_bookmark(p, buf, "")

        # print the row and column captions
        PDF_setfont(p, font, 2 * FONTSIZE/3)

        for row in range(0, 16, 1):
            buf = "x" + repr(row)
            PDF_show_xy(p, buf, LEFT + row*XINCR, TOP + YINCR)

            buf = "x" + repr(row)
            PDF_show_xy(p, buf, LEFT - XINCR, TOP - row * YINCR)

        # print the character table
        font = PDF_load_font(p, fontname, encoding[page], embedding)
        if font == -1:
            raise PDFlibException("Error: " + PDF_get_errmsg(p))

        PDF_setfont(p, font, FONTSIZE)

        y = TOP
        x = LEFT

        for row in range(0, 16, 1):
            for col in range(0, 16, 1):
                val = (16*row + col)
                if val != 0:
		    # for python 3 use
		    # buf = chr(val)
                    buf = unichr(val)
                    PDF_show_xy(p, buf, x, y)
                x += XINCR
            x = LEFT
            y -= YINCR

        PDF_end_page_ext(p, "")

    PDF_end_document(p, "")

  except PDFlibException:
    print("PDFlib exception occurred:\n[%d] %s: %s" %
	((PDF_get_errnum(p)), PDF_get_apiname(p),  PDF_get_errmsg(p)))

  except Exception:
    print("Exception occurred: %s" % (exc_info()[0]))

finally:
    PDF_delete(p)
