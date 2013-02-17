#!/usr/bin/python
# $Id: hello.py,v 1.20.2.4 2009/03/02 14:14:07 rjs Exp $
#
# PDFlib client: hello example in Python
#

from sys import *
from pdflib_py import *

# create a new PDFlib object
p = PDF_new()

try:
  try:
    # This means we must check return values of load_font() etc.
    PDF_set_parameter(p, "errorpolicy", "return")

    if PDF_begin_document(p, "hello.pdf", "") == -1:
        raise Exception("Error: " + PDF_get_errmsg(p))

    PDF_set_info(p, "Author", "Thomas Merz")
    PDF_set_info(p, "Creator", "hello.py")
    PDF_set_info(p, "Title", "Hello world (Python)")

    PDF_begin_page_ext(p, 595, 842, "")

    font = PDF_load_font(p, "Helvetica-Bold", "unicode", "")
    if font == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    PDF_setfont(p, font, 24)
    PDF_set_text_pos(p, 50, 700)
    PDF_show(p, "Hello world!")
    PDF_continue_text(p, "(says Python)")
    PDF_end_page_ext(p, "")

    PDF_end_document(p, "")     

  except PDFlibException:
    print("PDFlib exception occurred:\n[%d] %s: %s" %
	((PDF_get_errnum(p)), PDF_get_apiname(p),  PDF_get_errmsg(p)))

  except Exception:
    print("Exception occurred: %s" % (exc_info()[0]))

finally:
    PDF_delete(p)
