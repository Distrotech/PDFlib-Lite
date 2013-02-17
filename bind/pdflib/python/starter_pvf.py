#!/usr/bin/python
# Id: starter_pvf.pl,v 1.1.2.2 2007/12/21 14:04:32 rjs Exp 
# PDFlib Virtual File system (PVF):
# Create a PVF file which holds an image or PDF, and import the data from the
# PVF file
#
# This avoids disk access and is especially useful when the same image or PDF
# is imported multiply. For examples, images which sit in a database don't
# have to be written and re-read from disk, but can be passed to PDFlib
# directly in memory. A similar technique can be used for loading other data
# such as fonts, ICC profiles, etc.
#
# Required software: PDFlib Lite/PDFlib/PDFlib+PDI/PPS 7
# Required data: image file

# This is where the data files are. Adjust as necessary.
searchpath = "../data"
outfile = "starter_pvf.pdf"
title = "PDFlib Virtual File System"

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
    buf = title + ' Revision: 1.1.2.2 '
    PDF_set_info(p, "Title", buf)

    # We just read some image data from a file; to really benefit
    # from using PVF read the data from a Web site or a database instead
    f = open("../data/PDFlib-logo.tif", "rb")
    f.seek(0, 2)
    filelen = f.tell()
    f.seek(0, 0)
    imagedata = f.read(filelen)


    PDF_create_pvf(p, "/pvf/image", imagedata, "")

    # Load the image from the PVF
    image = PDF_load_image(p, "auto", "/pvf/image", "")
    if image == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    # Fit the image on page 1
    PDF_begin_page_ext(p, 595, 842, "")

    PDF_fit_image(p, image, 350, 750, "")

    PDF_end_page_ext(p, "")

    # Fit the image on page 2
    PDF_begin_page_ext(p, 595, 842, "")

    PDF_fit_image(p, image, 350, 50, "")

    PDF_end_page_ext(p, "")

    # Delete the virtual file to free the allocated memory
    PDF_delete_pvf(p, "/pvf/image")

    PDF_end_document(p, "")

  except PDFlibException:
    print("PDFlib exception occurred:\n[%d] %s: %s" %
	((PDF_get_errnum(p)), PDF_get_apiname(p),  PDF_get_errmsg(p)))

  except Exception:
    print("Exception occurred: %s" % (exc_info()[0]))

finally:
    PDF_delete(p)
