#!/usr/bin/python
# Id: starter_table.pl,v 1.1 2006/08/30 20:31:09 rjs Exp 
#
# Table starter:
# Create table which may span multiple pages
#
# required software: PDFlib/PDFlib+PDI/PPS 7
# required data: image file (dummy text created within the program)

import sys
from pdflib_py import *

# This is where the data files are. Adjust as necessary.
searchpath = "../data"
imagefile = "nesrin.jpg"
outfilename = "starter_table.pdf"

tf=-1; tbl=-1
rowmax = 50; colmax = 5
llx= 50; lly=50; urx=550; ury=800

headertext = "Table header (centered across all columns)"

# Dummy text for filling a cell with multi-line Textflow
tf_text =  \
"Lorem ipsum dolor sit amet, consectetur adi&shy;pi&shy;sicing elit, sed do eius&shy;mod tempor incidi&shy;dunt ut labore et dolore magna ali&shy;qua. Ut enim ad minim ve&shy;niam, quis nostrud exer&shy;citation ull&shy;amco la&shy;bo&shy;ris nisi ut ali&shy;quip ex ea commodo con&shy;sequat. Duis aute irure dolor in repre&shy;henderit in voluptate velit esse cillum dolore eu fugiat nulla pari&shy;atur. Excep&shy;teur sint occae&shy;cat cupi&shy;datat non proident, sunt in culpa qui officia dese&shy;runt mollit anim id est laborum. "

p = PDF_new()

try:
  try:
    # This means we must check return values of load_font() etc.
    PDF_set_parameter(p, "errorpolicy", "return")

    PDF_set_parameter(p, "SearchPath", searchpath)

    if (PDF_begin_document(p, outfilename, "") == -1):
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    PDF_set_info(p, "Creator", "PDFlib starter sample")
    PDF_set_info(p, "Title", "starter_table")

    # -------------------- Add table cells --------------------

    # ---------- row 1: table header (spans all columns)
    row = 1; col = 1
    font = PDF_load_font(p, "Times-Bold", "unicode", "")
    if font == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))


    optlist = "fittextline={position=center font=" + repr(font) + " fontsize=14} "+\
        "colspan=" + repr(colmax)

    tbl = PDF_add_table_cell(p, tbl, col, row, headertext, optlist)
    if tbl == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    # ---------- row 2: various kinds of content
    # ----- Simple text cell
    row += 1; col=1

    optlist = "fittextline={font=" + repr(font) + " fontsize=10 orientate=west}"

    tbl = PDF_add_table_cell(p, tbl, col, row, "vertical line", optlist)
    if tbl == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    # ----- Colorized background
    col += 1

    optlist = "fittextline={font=" + repr(font) + " fontsize=10} " + \
    "matchbox={fillcolor={rgb 0.9 0.5 0}}"

    tbl = PDF_add_table_cell(p, tbl, col, row, "some color", optlist)
    if tbl == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    # ----- Multi-line text with Textflow
    col += 1
    font = PDF_load_font(p, "Times-Roman", "unicode", "")

    optlist = "charref fontname=Times-Roman encoding=unicode fontsize=8 "

    tf = PDF_add_textflow(p, tf, tf_text, optlist)
    if tf == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    optlist = "margin=2 textflow=" + repr(tf)

    tbl = PDF_add_table_cell(p, tbl, col, row, "", optlist)
    if tbl == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    # ----- Rotated image
    col += 1

    image = PDF_load_image(p, "auto", imagefile, "")
    if (image == -1):
        raise PDFlibException("Couldn't load image: " + PDF_get_errmsg(p))

    optlist = "image=" + repr(image) + " fitimage={orientate=west}"

    tbl = PDF_add_table_cell(p, tbl, col, row, "", optlist)
    if tbl == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    # ----- Diagonal stamp
    col += 1

    optlist = "fittextline={font=" + repr(font) + " fontsize=10 stamp=ll2ur}"

    tbl = PDF_add_table_cell(p, tbl, col, row, "entry void", optlist)
    if tbl == -1:
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    # ---------- Fill row 3 and above with their numbers
    row += 1
    for row in range(row, rowmax+1):
        for col in range(1, colmax+1):
            num = "Col " + repr(col) + "/Row " + repr(row)
            optlist = "colwidth=20% fittextline={font=" + repr(font) + " fontsize=10}"
            tbl = PDF_add_table_cell(p, tbl, col, row, num, optlist)
            if tbl == -1:
                raise PDFlibException("Error: " + PDF_get_errmsg(p))

            col += 1
        row += 1

    # ---------- Place the table on one or more pages ----------

    #
    # Loop until all of the table is placed; create new pages
    # as long as more table instances need to be placed.

    result = "_boxfull"
    while (result == "_boxfull"):
        PDF_begin_page_ext(p, 0, 0, "width=a4.width height=a4.height")

        # Shade every other row; draw lines for all table cells.
        # Add "showcells showborder" to visualize cell borders 

        optlist = "header=1 fill={{area=rowodd fillcolor={gray 0.9}}} " + \
        "stroke={{line=other}} "

        # Place the table instance
        result = PDF_fit_table(p, tbl, llx, lly, urx, ury, optlist)
        if (result ==  "_error"):
            raise PDFlibException("Couldn't place table: " + PDF_get_errmsg(p))

        PDF_end_page_ext(p, "")


    # Check the result; "_stop" means all is ok.
    if (result != "_stop"):
        if (result ==  "_error"):
            raise PDFlibException("Error when placing table: " + PDF_get_errmsg(p))
        else:
            # Any other return value is a user exit caused by
            # the "return" option; this requires dedicated code to
            # deal with.
            raise PDFlibException("User return found in Textflow")

    # This will also delete Textflow handles used in the table
    PDF_delete_table(p, tbl, "")

    PDF_end_document(p, "")

  except PDFlibException:
    print("PDFlib exception occurred:\n[%d] %s: %s" %
	((PDF_get_errnum(p)), PDF_get_apiname(p),  PDF_get_errmsg(p)))

  except Exception:
    print("Exception occurred: %s" % (exc_info()[0]))

finally:
    PDF_delete(p)
