#!/usr/bin/python
#!/usr/bin/perl
# $Id: starter_block.py,v 1.4.2.5 2009/03/02 14:14:07 rjs Exp $
#
# Block starter:
# Import a PDF page containing, and process all blocks. The blocks are
# retrieved via pCOS, and the block filling functions are used to
# visualize the blocks on the output page. A real-world application would
# of course fill the blocks with data retrieved from some external data
# source.
#
# required software: PPS 7 or above
# required data: input PDF
#

from sys import *
from pdflib_py import *

# This is where the data files are. Adjust as necessary.
searchpath = "../data"
infile = "boilerplate.pdf"
outfilename = "starter_block.pdf"

p = PDF_new()

try:
  try:
    # This means we must check return values of load_font() etc.
    PDF_set_parameter(p, "errorpolicy", "return")

    PDF_set_parameter(p, "SearchPath", searchpath)

    if (PDF_begin_document(p, outfilename, "") == -1):
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    PDF_set_info(p, "Creator", "PDFlib starter sample")
    PDF_set_info(p, "Title", "starter_block")

    # Open a PDF containing blocks
    indoc = PDF_open_pdi_document(p, infile, "")
    if (indoc == -1):
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    # Open the first page
    page = PDF_open_pdi_page(p, indoc, 1, "")
    if (page == -1):
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    width = PDF_pcos_get_number(p, indoc, "pages[0]/width")
    height = PDF_pcos_get_number(p, indoc, "pages[0]/height")

    PDF_begin_page_ext(p, width, height, "")

    # Place the imported page on the output page
    PDF_fit_pdi_page(p, page, 0, 0, "")

    # Query the number of blocks on the first page
    blockcount = PDF_pcos_get_number(p, indoc,
        "length:pages[0]/blocks")

    if (blockcount == 0):
        raise PDFlibException("Error: " +  infile + "does not contain any PDFlib blocks")

    # Loop over all blocks on the page
    for i in range (0, int(blockcount), 1):
        # Fetch the name and type of the i-th block on the first page
        # (one of Text/Image/PDF)

        blockname = PDF_pcos_get_string(p, indoc,
            "pages[0]/blocks[" + repr(i) + "]/Name")

        blocktype = PDF_pcos_get_string(p, indoc,
            "pages[0]/blocks[" + repr(i) + "]/Subtype")

        # Visualize all text blocks
        if (blocktype == "Text"):
            optlist = "fontname=Helvetica encoding=unicode " \
                "fillcolor={rgb 1 0 0} " \
                "bordercolor={gray 0} linewidth=0.25"

            # We simply use the blockname as content
            if (PDF_fill_textblock(p,
                        page, blockname, blockname, optlist) == -1):
                print(("Warning: " + PDF_get_errmsg(p)))

    PDF_end_page_ext(p, "")
    PDF_close_pdi_page(p, page)

    PDF_end_document(p, "")
    PDF_close_pdi_document(p, indoc)

  except PDFlibException:
    print("PDFlib exception occurred:\n[%d] %s: %s" %
	((PDF_get_errnum(p)), PDF_get_apiname(p),  PDF_get_errmsg(p)))

  except Exception:
    print("Exception occurred: %s" % (exc_info()[0]))

finally:
    PDF_delete(p)
