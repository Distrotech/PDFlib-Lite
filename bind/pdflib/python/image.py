#!/usr/bin/python
# $Id: image.py,v 1.17.2.3 2009/03/02 14:14:07 rjs Exp $
#
# PDFlib client: image example in Python
#

from sys import *
from pdflib_py import *

imagefile = "nesrin.jpg"

# This is where font/image/PDF input files live. Adjust as necessary.
searchpath = "../data"


p = PDF_new()

try:
  try:
    # This means we must check return values of load_font() etc.
    PDF_set_parameter(p, "errorpolicy", "return")

    PDF_set_parameter(p, "SearchPath", searchpath)

    if PDF_begin_document(p, "image.pdf", "") == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    PDF_set_info(p, "Creator", "image.py")
    PDF_set_info(p, "Author", "Thomas Merz")
    PDF_set_info(p, "Title", "image sample (Python)")

    image = PDF_load_image(p, "auto", imagefile, "")
    if image == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    # dummy page size, will be adjusted by PDF_fit_image()
    PDF_begin_page_ext(p, 10, 10, "")
    PDF_fit_image(p, image, 0, 0, "adjustpage")
    PDF_close_image(p, image)
    PDF_end_page_ext(p, "")

    PDF_end_document(p, "")

  except PDFlibException:
    print("PDFlib exception occurred:\n[%d] %s: %s" %
	((PDF_get_errnum(p)), PDF_get_apiname(p),  PDF_get_errmsg(p)))

  except Exception:
    print("Exception occurred: %s" % (exc_info()[0]))

finally:
    PDF_delete(p)
