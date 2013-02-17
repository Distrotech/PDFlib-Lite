#!/usr/bin/python
# $Id: starter_pdfa.py,v 1.4.2.4 2009/03/02 14:14:07 rjs Exp $
#
# PDF/A starter:
# Create PDF/A-compliant output
#
# required software: PDFlib/PDFlib+PDI/PPS 7
# required data: font file, image file

import sys
from pdflib_py import *

# This is where the data files are. Adjust as necessary.
searchpath = "../data"
imagefile = "nesrin.jpg"
outfilename = "starter_pdfa.pdf"

p = PDF_new()

try:
  try:
    # This means we must check return values of load_font() etc.
    PDF_set_parameter(p, "errorpolicy", "return")

    PDF_set_parameter(p, "SearchPath", searchpath)

    # PDF/A-1a requires Tagged PDF
    if (PDF_begin_document(p, outfilename, "pdfa=PDF/A-1b:2005") == -1):
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    #
    # We use sRGB as output intent since it allows the color
    # spaces CIELab, ICC-based, grayscale, and RGB.
    #
    # If you need CMYK color you must use a CMYK output profile.


    PDF_load_iccprofile(p, "sRGB", "usage=outputintent")

    PDF_set_info(p, "Creator", "PDFlib starter sample")
    PDF_set_info(p, "Title", "starter_pdfa")

    PDF_begin_page_ext(p, 595, 842, "")

    # font embedding is required for PDF/A
    font = PDF_load_font(p, "LuciduxSans-Oblique", "unicode", "embedding")
    if font == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    PDF_setfont(p, font, 24)

    PDF_fit_textline(p, "PDF/A-1b:2005 starter", 50, 700, "")

    # We can use an RGB image since we already supplied an
    # output intent profile.

    image = PDF_load_image(p, "auto", imagefile, "")
    if (image == -1):
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    # Place the image at the bottom of the page
    PDF_fit_image(p, image, 0.0, 0.0, "scale=0.5")

    PDF_end_page_ext(p, "")

    PDF_end_document(p, "")

  except PDFlibException:
    print("PDFlib exception occurred:\n[%d] %s: %s" %
	((PDF_get_errnum(p)), PDF_get_apiname(p),  PDF_get_errmsg(p)))

  except Exception:
    print("Exception occurred: %s" % (exc_info()[0]))

finally:
    PDF_delete(p)
