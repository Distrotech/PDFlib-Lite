#!/usr/bin/python
# $Id: quickreference.py,v 1.18.2.3 2009/03/02 14:14:07 rjs Exp $
#
# PDFlib/PDI client: mini imposition demo
#

from sys import *
from pdflib_py import *

maxrow = 2
maxcol = 2
width = 500.0
height = 770.0

infile = "reference.pdf"
searchpath = "../data"

p = PDF_new()

try:
  try:
    # This means we must check return values of load_font() etc.
    PDF_set_parameter(p, "errorpolicy", "return")

    PDF_set_parameter(p, "SearchPath", searchpath)

    if PDF_begin_document(p, "quickreference.pdf", "") == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    PDF_set_info(p, "Creator", "quickreference.py")
    PDF_set_info(p, "Author", "Thomas Merz")
    PDF_set_info(p, "Title", "mini imposition demo (Python)")

    manual = PDF_open_pdi_document(p, infile, "")
    if manual == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    row = 0
    col = 0

    PDF_set_parameter(p, "topdown", "true")

    endpage = int(PDF_pcos_get_number(p, manual, "length:pages"))

    for pageno in range(1, endpage+1):
        if row == 0 and col == 0:
            PDF_begin_page_ext(p, width, height, "")
            font = PDF_load_font(p, "Helvetica-Bold", "unicode", "")
            if font == -1:
                raise PDFlibException("Error: " + PDF_get_errmsg(p))
            PDF_setfont(p, font, 18)
            PDF_set_text_pos(p, 24, 24)
            PDF_show(p, "PDFlib Quick Reference")

        page = PDF_open_pdi_page(p, manual, pageno, "")

        if page == -1:
            raise PDFlibException("Error: " + PDF_get_errmsg(p))

        optlist = "scale " + repr(1.0/maxrow)

        PDF_fit_pdi_page(p, page,
                width/maxcol*col, (row + 1) * height/maxrow, optlist)
        PDF_close_pdi_page(p, page)

        col = col+1
        if col == maxcol:
            col = 0
            row = row+1

        if row == maxrow:
            row = 0
            PDF_end_page_ext(p, "")

    # finish the last partial page
    if row != 0 or col != 0:
        PDF_end_page_ext(p, "")

    PDF_end_document(p, "")
    PDF_close_pdi_document(p, manual)

  except PDFlibException:
    print("PDFlib exception occurred:\n[%d] %s: %s" %
	((PDF_get_errnum(p)), PDF_get_apiname(p),  PDF_get_errmsg(p)))

  except Exception:
    print("Exception occurred: %s" % (exc_info()[0]))

finally:
    PDF_delete(p)
