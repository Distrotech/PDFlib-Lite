#!/usr/bin/python
# $Id: starter_textflow.py,v 1.7.2.4 2009/03/02 14:14:07 rjs Exp $
#
# Textflow starter:
# Create multi-column text output which may span multiple pages
#
# required software: PDFlib/PDFlib+PDI/PPS 7
# required data: none

import sys
from pdflib_py import *


outfilename = "starter_textflow.pdf"
tf = -1
llx1= 50; lly1=50; urx1=250; ury1=800
llx2=300; lly2=50; urx2=500; ury2=800

# Repeat the dummy text to produce more contents
count = 50

optlist1 = "fontname=Helvetica fontsize=10.5 encoding=unicode " \
    "fillcolor={gray 0} alignment=justify"
optlist2 = "fontname=Helvetica-Bold fontsize=14 encoding=unicode " \
    "fillcolor={rgb 1 0 0} charref"

# Dummy text for filling the columns. Soft hyphens are marked with
# the character reference "&shy;" (character references are
# enabled by the charref option).

text=  \
"Lorem ipsum dolor sit amet, consectetur adi&shy;pi&shy;sicing elit, sed do eius&shy;mod tempor incidi&shy;dunt ut labore et dolore magna ali&shy;qua. Ut enim ad minim ve&shy;niam, quis nostrud exer&shy;citation ull&shy;amco la&shy;bo&shy;ris nisi ut ali&shy;quip ex ea commodo con&shy;sequat. Duis aute irure dolor in repre&shy;henderit in voluptate velit esse cillum dolore eu fugiat nulla pari&shy;atur. Excep&shy;teur sint occae&shy;cat cupi&shy;datat non proident, sunt in culpa qui officia dese&shy;runt mollit anim id est laborum. "

p = PDF_new()

try:
  try:
    # This means we must check return values of load_font() etc.
    PDF_set_parameter(p, "errorpolicy", "return")

    if (PDF_begin_document(p, outfilename, "") == -1):
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    PDF_set_info(p, "Creator", "PDFlib starter sample")
    PDF_set_info(p, "Title", "starter_textflow")

    # Create some amount of dummy text and feed it to a Textflow
    # object with alternating options. 

    for i in range(count):
        i += 1
        num = repr(i) + " "

        tf = PDF_add_textflow(p, tf, num, optlist2)
        if (tf == -1):
            raise PDFlibException("Error: " + PDF_get_errmsg(p))

        tf = PDF_add_textflow(p, tf, text, optlist1)
        if (tf == -1):
            raise PDFlibException("Error: " + PDF_get_errmsg(p))

    # Loop until all of the text is placed; create new pages
    # as long as more text needs to be placed. Two columns will
    # be created on all pages.

    result = "_boxfull"
    while (result == "_boxfull" or result == "_nextpage"):
        # Add "showborder to visualize the fitbox borders
        optlist = "verticalalign=justify linespreadlimit=120% "

        PDF_begin_page_ext(p, 0, 0, "width=a4.width height=a4.height")

        # Fill the first column
        result = PDF_fit_textflow(p, tf, llx1, lly1, urx1, ury1, optlist)

        # Fill the second column if we have more text*/
        if (result != "_stop"):
            result = PDF_fit_textflow(p, tf, llx2, lly2, urx2, ury2, optlist)

        PDF_end_page_ext(p, "")

        # "_boxfull" means we must continue because there is more text
        # "_nextpage" is interpreted as "start new column"


    # Check for errors
    if (result != "_stop"):
        # "_boxempty" happens if the box is very small and doesn't
        # hold any text at all.

        if (result == "_boxempty"):
            raise PDFlibException("Error: Textflow box too small")
        else:
            # Any other return value is a user exit caused by
            # the "return" option; this requires dedicated code to
            # deal with.
            raise PDFlibException("User return '" + result + "' found in Textflow")

    PDF_delete_textflow(p, tf)

    PDF_end_document(p, "")

  except PDFlibException:
    print("PDFlib exception occurred:\n[%d] %s: %s" %
	((PDF_get_errnum(p)), PDF_get_apiname(p),  PDF_get_errmsg(p)))

  except Exception:
    print("Exception occurred: %s" % (exc_info()[0]))

finally:
    PDF_delete(p)
