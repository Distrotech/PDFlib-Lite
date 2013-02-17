#!/usr/bin/python
# $Id: starter_pdfmerge.py,v 1.4.2.5 2009/03/02 14:14:07 rjs Exp $
#
# PDF merge starter:
# Merge pages from multiple PDF documents; interactive elements (e.g. 
# bookmarks) will be dropped.
#
# required software: PDFlib+PDI/PPS 7
# required data: PDF documents

import sys
from pdflib_py import *

def printf(format, *args):
    sys.stdout.write(format % args)

# This is where the data files are. Adjust as necessary.
searchpath = "../data"
outfilename = "starter_pdfmerge.pdf"

pdffiles = (
        "PDFlib-real-world.pdf",
        "PDFlib-datasheet.pdf",
        "TET-datasheet.pdf",
        "PLOP-datasheet.pdf",
        "pCOS-datasheet.pdf"
)

p = PDF_new()

try:
  try:
    # This means we must check return values of load_font() etc.
    PDF_set_parameter(p, "errorpolicy", "return")

    PDF_set_parameter(p, "SearchPath", searchpath)

    if (PDF_begin_document(p, outfilename, "") == -1):
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    PDF_set_info(p, "Creator", "PDFlib starter sample")
    PDF_set_info(p, "Title", "starter_pdfmerge")

    for pdffile in (pdffiles):
        # Open the input PDF
        indoc = PDF_open_pdi_document(p, pdffile, "")
        if (indoc == -1):
            printf("Error: %s\n", PDF_get_errmsg(p))
            next

        endpage = PDF_pcos_get_number(p, indoc, "/Root/Pages/Count")

        # Loop over all pages of the input document
        for pageno in range(1, int(endpage)+1, 1):
            page = PDF_open_pdi_page(p, indoc, pageno, "")
            if (page == -1):
                printf("Error: %s\n", PDF_get_errmsg(p))
                next

            # Dummy page size; will be adjusted later
            PDF_begin_page_ext(p, 10, 10, "")

            # Create a bookmark with the file name
            if (pageno == 1):
                PDF_create_bookmark(p, pdffile, "")

            # Place the imported page on the output page, and
            # adjust the page size
            
            PDF_fit_pdi_page(p, page, 0, 0, "adjustpage")
            PDF_close_pdi_page(p, page)

            PDF_end_page_ext(p, "")

        PDF_close_pdi_document(p, indoc)

    PDF_end_document(p, "")

  except PDFlibException:
    print("PDFlib exception occurred:\n[%d] %s: %s" %
	((PDF_get_errnum(p)), PDF_get_apiname(p),  PDF_get_errmsg(p)))

  except Exception:
    print("Exception occurred: %s" % (exc_info()[0]))

finally:
    PDF_delete(p)
