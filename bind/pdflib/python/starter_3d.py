#!/usr/bin/python
# Id: starter_3d.pl,v 1.1.2.1 2008/02/20 22:06:41 rjs Exp $
# 3D Starter:
# Create a 3D model and load it into a U3D annotation.
#
# Define a 3D view and load some 3D data with the view defined. Then create
# an annotation containing the loaded 3D data with the defined 3D view as the
# initial view.
#
# Acrobat 7.07 or above is required for viewing PDF documents containing a
# 3D model.
#
# Required software: PDFlib/PDFlib+PDI/PPS 7.0.1
# Required data: U3D data file
#

from sys import *
from pdflib_py import *

# This is where the data files are. Adjust if necessary.
searchpath = "../data"
outfile = "starter_3d.pdf"

# Required minimum PDFlib version
requiredversion = 701
requiredvstr = "7.0.1"

# create a new PDFlib object
p = PDF_new()

try:
  try:
    PDF_set_parameter(p, "SearchPath", searchpath)

    # This means we must check return values of load_font() etc.
    PDF_set_parameter(p, "errorpolicy", "return")

    # Check whether the required minimum PDFlib version is available
    major = PDF_get_value(p, "major", 0)
    minor = PDF_get_value(p, "minor", 0)
    revision = PDF_get_value(p, "revision", 0)

    if major*100 + minor*10 + revision < requiredversion:
        raise Exception("Error: PDFlib " + requiredvstr + " or above is required\n")

    # Start the document
    if PDF_begin_document(p, outfile, "") == -1:
        raise Exception("Error: " + PDF_get_errmsg(p))

    PDF_set_info(p, "Creator", "PDFlib Cookbook")
    PDF_set_info(p, "Title", "starter_3d")

    font = PDF_load_font(p, "Helvetica", "winansi", "")
    if font == -1:
        raise Exception("Error: " + PDF_get_errmsg(p))

    PDF_begin_page_ext(p, 0, 0, "width=a4.width height=a4.height")

    # Define a U3D view
    optlist = "name=FirstView background={fillcolor={rgb 1 0.5 0.1}}"
    u3dview = PDF_create_3dview(p, "First view", optlist)
    if u3dview == -1:
        raise Exception("Error: " + PDF_get_errmsg(p))

    # Load some U3D data with the view defined above
    buf = "views={" + repr(u3dview) + "}"
    u3ddata = PDF_load_3ddata(p, "box.u3d", buf)
    if u3ddata == -1:
        raise Exception("Error: " + PDF_get_errmsg(p))

    # Create an annotation containing the loaded U3D data with the
    # defined 3D view as the initial view
    #
    buf = "name=annot usercoordinates contents=U3D 3ddata=" + repr(u3ddata) \
        + " 3dactivate={enable=open} 3Dinitialview=" + repr(u3dview)
    PDF_create_annotation(p, 116, 400, 447, 580, "3D", buf)

    PDF_end_page_ext(p, "")

    PDF_end_document(p, "")

  except PDFlibException:
    print("PDFlib exception occurred:\n[%d] %s: %s" %
	((PDF_get_errnum(p)), PDF_get_apiname(p),  PDF_get_errmsg(p)))

  except Exception:
    print("Exception occurred: %s" % (exc_info()[0]))

finally:
    PDF_delete(p)
