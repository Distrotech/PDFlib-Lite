#!/usr/bin/python
# Id: starter_image.pl,v 1.1.2.2 2007/12/21 14:04:32 rjs Exp 
# Starter image:
# Load and place an image using various options for scaling and positioning
#
# Place the image it its original size.
# Place the image with scaling and orientation to the west.
# Fit the image into a box with clipping.
# Fit the image into a box with proportional resizing.
# Fit the image into a box entirely.
#
# Required software: PDFlib Lite/PDFlib/PDFlib+PDI/PPS 7
# Required data: image file

# This is where the data files are. Adjust as necessary.
searchpath = "../data"
outfile = "starter_image.pdf"
title = "Starter Image"

imagefile = "lionel.jpg"
bw = 400
bh = 200
x = 20
y = 580
yoffset = 260

from sys import *
from pdflib_py import *

# create a new PDFlib object
p = PDF_new()

try:
  try:
    PDF_set_parameter(p, "SearchPath", searchpath)

    # This means we must check return values of load_font() etc.
    PDF_set_parameter(p, "errorpolicy", "return")

    if PDF_begin_document(p, outfile, "") == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    PDF_set_info(p, "Creator", "PDFlib Cookbook")
    buf = title +  '  Revision: 1.1.2.2 '
    PDF_set_info(p, "Title", buf)

    # For PDFlib Lite: change "unicode" to "winansi"
    font = PDF_load_font(p, "Helvetica", "winansi", "")
    if font == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    # Load the image
    image = PDF_load_image(p, "auto", imagefile, "")
    if image == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    # Start page 1
    PDF_begin_page_ext(p, 0, 0, "width=a4.width height=a4.height")
    PDF_setfont(p, font, 12)


    # ------------------------------------
    # Place the image in its original size
    # ------------------------------------
    

    # Position the image in its original size with its lower left corner
    # at the reference point (20, 380)
    
    PDF_fit_image(p, image, 20, 380, "")

    # Output some descriptive text
    PDF_fit_textline(p,
        "The image is placed with the lower left corner in its original size at reference point (20, 380):", 20, 820, "")
    PDF_fit_textline(p, "fit_image(image, 20, 380, \"\");", 20, 800, "")


    # --------------------------------------------------------
    # Place the image with scaling and orientation to the west
    # --------------------------------------------------------
    

    # Position the image with its lower right corner at the reference
    # point (580, 20).
    # "scale=0.5" scales the image by 0.5.
    # "orientate=west" orientates the image to the west.
    
    PDF_fit_image(p, image, 580, 20,
        "scale=0.5 position={right bottom} orientate=west")

    # Output some descriptive text
    PDF_fit_textline(p,
        "The image is placed with a scaling of 0.5 and an orientation to the west with the lower right corner", 580, 320,
        "position={right bottom}")
    PDF_fit_textline(p,
        " at reference point (580, 20): fit_image(image, 580, 20, \"scale=0.5 orientate=west position={right bottom}\");",
        580, 300, "position={right bottom}")

    PDF_end_page_ext(p, "")

    # Start page 2
    PDF_begin_page_ext(p, 0, 0, "width=a4.width height=a4.height")
    PDF_setfont(p, font, 12)


    # --------------------------------------
    # Fit the image into a box with clipping
    # --------------------------------------
    

    # The "boxsize" option defines a box with a given width and height and
    # its lower left corner located at the reference point.
    # "position={right top}" positions the image on the top right of the
    # box.
    # "fitmethod=clip" clips the image to fit it into the box.
    
    buf = "boxsize={" + repr(bw) + " " + repr(bh) + "} position={right top} fitmethod=clip"
    PDF_fit_image(p, image, x, y, buf)

    # Output some descriptive text
    PDF_fit_textline(p,
        "fit_image(image, x, y, \"boxsize={400 200} position={right top} fitmethod=clip\");", 20, y+bh+10, "")


    # ---------------------------------------------------
    # Fit the image into a box with proportional resizing
    # ---------------------------------------------------
    

    # The "boxsize" option defines a box with a given width and height and
    # its lower left corner located at the reference point.
    # "position={center}" positions the image in the center of the
    # box.
    # "fitmethod=meet" resizes the image proportionally until its height
    # or width completely fits into the box.
    # The "showborder" option is used to illustrate the borders of the box.
    
    buf = "boxsize={" + repr(bw) + " " + repr(bh) + "} position={center} fitmethod=meet showborder"
    y = y - yoffset
    PDF_fit_image(p, image, x, y, buf)

    # Output some descriptive text
    PDF_fit_textline(p,
        "fit_image(image, x, y, \"boxsize={400 200} position={center} fitmethod=meet showborder\");", 20, y+bh+10, "")


    # ---------------------------------
    # Fit the image into a box entirely
    # ---------------------------------
    

    # The "boxsize" option defines a box with a given width and height and
    # its lower left corner located at the reference point.
    # By default, the image is positioned in the lower left corner of the
    # box.
    # "fitmethod=entire" resizes the image proportionally until its height
    # or width completely fits into the box.
    
    buf =  "boxsize={" + repr(bw) + " " + repr(bh) + "} fitmethod=entire"
    y = y - yoffset
    PDF_fit_image(p, image, x, y, buf)

    # Output some descriptive text
    PDF_fit_textline(p,
        "fit_image(image, x, y, \"boxsize={400 200} fitmethod=entire\");",
        20, y+bh+10, "")

    PDF_end_page_ext(p, "")

    PDF_close_image(p, image)

    PDF_end_document(p, "")

  except PDFlibException:
    print("PDFlib exception occurred:\n[%d] %s: %s" %
	((PDF_get_errnum(p)), PDF_get_apiname(p),  PDF_get_errmsg(p)))

  except Exception:
    print("Exception occurred: %s" % (exc_info()[0]))

finally:
    PDF_delete(p)
