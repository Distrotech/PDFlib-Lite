#!/usr/bin/python
# $Id: businesscard.py,v 1.15.2.3 2009/03/02 14:14:07 rjs Exp $
#
# PDFlib client: block processing example in Python
#

from sys import *
from pdflib_py import *

infile = "boilerplate.pdf"

# This is where font/image/PDF input files live. Adjust as necessary.
#
# Note that this directory must also contain the LuciduxSans font outline
# and metrics files.
#
searchpath = "../data"

data_name = [
 "name",
 "business.title",
 "business.address.line1",
 "business.address.city",
 "business.telephone.voice",
 "business.telephone.fax",
 "business.email",
 "business.homepage" ]

data_value = [
 "Victor Kraxi",
 "Chief Paper Officer",
 "17, Aviation Road",
 "Paperfield",
 "phone +1 234 567-89",
 "fax +1 234 567-98",
 "victor@kraxi.com",
 "www.kraxi.com" ]

BLOCKCOUNT = 8

p = PDF_new()

try:
  try:
    # This means we must check return values of load_font() etc.
    PDF_set_parameter(p, "errorpolicy", "return")

    # Set the search path for fonts and PDF files
    PDF_set_parameter(p, "SearchPath", searchpath)

    if PDF_begin_document(p, "businesscard.pdf", "") == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    PDF_set_info(p, "Creator", "businesscard.py")
    PDF_set_info(p, "Author", "Thomas Merz")
    PDF_set_info(p, "Title","PDFlib block processing sample (C)")

    blockcontainer = PDF_open_pdi_document(p, infile, "")
    if blockcontainer == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    page = PDF_open_pdi_page(p, blockcontainer, 1, "")
    if page == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    PDF_begin_page_ext(p, 20, 20, "")           # dummy page size

    # This will adjust the page size to the block container's size.
    PDF_fit_pdi_page(p, page, 0, 0, "adjustpage")

    # Fill all text blocks with dynamic data
    for i in range(0, BLOCKCOUNT, 1):
        if PDF_fill_textblock(p, page, data_name[i], data_value[i], \
                    "embedding encoding=unicode") == -1:
            print("Warning: " + PDF_get_errmsg(p) + "\n")

    PDF_end_page_ext(p, "")
    PDF_close_pdi_page(p, page)

    PDF_end_document(p, "")
    PDF_close_pdi_document(p, blockcontainer)

  except PDFlibException:
    print("PDFlib exception occurred:\n[%d] %s: %s" %
	((PDF_get_errnum(p)), PDF_get_apiname(p),  PDF_get_errmsg(p)))

  except Exception:
    print("Exception occurred: %s" % (exc_info()[0]))

finally:
    PDF_delete(p)
