#!/usr/bin/python
# $Id: starter_pcos.py,v 1.5.2.6 2009/03/02 14:14:07 rjs Exp $
#
# pCOS starter:
# Dump information from an existing PDF document
#
# required software: PDFlib+PDI/PPS 7
# required data: PDF input file

import sys
from pdflib_py import *

def printf(format, *args):
    sys.stdout.write(format % args)

# This is where the data files are. Adjust as necessary.
searchpath = "../data"
pdfinput = "TET-datasheet.pdf"
docoptlist = "requiredmode=minimum"

p = PDF_new()

try:
  try:
    # This means we must check return values of load_font() etc.
    PDF_set_parameter(p, "errorpolicy", "return")

    PDF_set_parameter(p, "SearchPath", searchpath)

    # We do not create any output document, so no call to
    # begin_document() is required.


    # Open the input document
    doc = PDF_open_pdi_document(p, pdfinput, docoptlist)
    if (doc == -1):
        raise PDFlibException("Error: " + PDF_get_errmsg(p))

    # --------- general information (always available)

    pcosmode = PDF_pcos_get_number(p, doc, "pcosmode")

    printf("   File name: %s\n",
        PDF_pcos_get_string(p, doc,"filename"))

    printf(" PDF version: %s\n",
        PDF_pcos_get_number(p, doc, "pdfversion")/10)

    printf("  Encryption: %s\n",
        PDF_pcos_get_string(p, doc, "encrypt/description"))

    a = 1 == 1 and "Yes" or "No"
    a = ("No", "Yes")[1 == 1]

    printf("   Master pw: %s\n",
        ((PDF_pcos_get_number(p, doc, "encrypt/master") != 0) and "yes" or "no"))

    printf("     User pw: %s\n",
        ((PDF_pcos_get_number(p, doc, "encrypt/user") != 0) and "yes" or "no"))

    printf("Text copying: %s\n",
        ((PDF_pcos_get_number(p, doc, "encrypt/nocopy") != 0) and "no" or "yes"))

    printf("  Linearized: %s\n",
        ((PDF_pcos_get_number(p, doc, "linearized") != 0) and "yes" or "no"))

    printf("      Tagged: %s\n\n",
        ((PDF_pcos_get_number(p, doc, "tagged") != 0) and "yes" or "no"))

    if (pcosmode == 0):
        printf("Minimum mode: no more information available\n\n")
        exit(0)

    # --------- more details (requires at least user password)
    printf("No. of pages: %d\n",
        PDF_pcos_get_number(p, doc, "length:pages"))

    printf(" Page 1 size: width=%.3f, height=%.3f\n",
         PDF_pcos_get_number(p, doc, "pages[0]/width"),
         PDF_pcos_get_number(p, doc, "pages[0]/height"))

    count = PDF_pcos_get_number(p, doc, "length:fonts")
    printf("No. of fonts: %d\n",  count)

    for i in range (0, int(count), 1):
        fonts = "fonts[" + repr(i) + "]/embedded"
        if (PDF_pcos_get_number(p, doc, fonts) != 0):
            printf("embedded ")
        else:
            printf("unembedded ")

        fonts = "fonts[" + repr(i) + "]/type"
        printf(PDF_pcos_get_string(p, doc, fonts) + " font ")
        fonts = "fonts[" + repr(i) + "]/name"
        printf("%s\n", PDF_pcos_get_string(p, doc, fonts))

    printf("\n")

    if (pcosmode == 1):
        print("Restricted mode: no more information available")
        exit(0)

    # ----- document Info keys and XMP metadata (requires master pw)

    count = PDF_pcos_get_number(p, doc, "length:/Info")

    for i in range (0, int(count), 1):
        info = "type:/Info[" + repr(i) + "]"
        objtype = PDF_pcos_get_string(p, doc, info)

        info = "/Info[" + repr(i) + "].key"
        key = PDF_pcos_get_string(p, doc, info)
        j = 12 - len(key)
        while (j > 0):
            printf(" ")
            j -= 1

        printf(key + ": ")

        # Info entries can be stored as string or name objects
        if (objtype == "name" or objtype == "string"):
            info = "/Info[" + repr(i) + "]"
            printf("'" + PDF_pcos_get_string(p, doc, info) + "'\n")
        else:
            info = "type:/Info[" + repr(i) + "]"
            printf("(" + PDF_pcos_get_string(p, doc, info) + " object)\n")

    printf("\nXMP meta data: ")


    objtype = PDF_pcos_get_string(p, doc, "type:/Root/Metadata")
    if (objtype == "stream"):
        contents = PDF_pcos_get_stream(p, doc, "", "/Root/Metadata")
        printf("%d bytes \n", len(contents))
        printf("")
    else:
        printf("not present\n")

    PDF_close_pdi_document(p, doc)

  except PDFlibException:
    print("PDFlib exception occurred:\n[%d] %s: %s" %
	((PDF_get_errnum(p)), PDF_get_apiname(p),  PDF_get_errmsg(p)))

  except Exception:
    print("Exception occurred: %s" % (exc_info()[0]))

finally:
    PDF_delete(p)
