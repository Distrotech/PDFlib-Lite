#!/usr/bin/env ruby
# $Id: starter_pcos.rb,v 1.3.2.5 2008/02/28 14:49:59 rjs Exp $
#
# pCOS starter:
# Dump information from an existing PDF document
#
# required software: PDFlib+PDI/PPS 7
# required data: PDF input file
#/

require 'PDFlib'



# This is where the data files are. Adjust as necessary. */
String searchpath = "../data"

pdfinput = "TET-datasheet.pdf"

docoptlist = "requiredmode=minimum"

begin
  p = PDFlib.new

  # This means we must check return values of load_font() etc.
  p.set_parameter("errorpolicy", "return")

  p.set_parameter("SearchPath", searchpath)

  # We do not create any output document, so no call to
  # begin_document() is required.
  #/

  # Open the input document */
  if ((doc = p.open_pdi_document(pdfinput, docoptlist)) == -1)
    raise "Error: " + p.get_errmsg()
  end

  # --------- general information (always available) */

  pcosmode = p.pcos_get_number(doc, "pcosmode")

  print "   File name: " + 
      p.pcos_get_string(doc,"filename") + "\n"

  printf(" PDF version: %.1f\n", (p.pcos_get_number(doc, "pdfversion").to_f/10))

  print "  Encryption: " +
      p.pcos_get_string(doc, "encrypt/description") + "\n"

  print "   Master pw: " +
      ((p.pcos_get_number(doc, "encrypt/master") != 0) ? "yes":"no") + "\n"

  print "     User pw: " +
      ((p.pcos_get_number(doc, "encrypt/user") != 0) ? "yes" : "no") + "\n"

  print "Text copying: " +
      ((p.pcos_get_number(doc, "encrypt/nocopy") != 0) ? "no":"yes") + "\n"

  print "  Linearized: " +
      ((p.pcos_get_number(doc, "linearized") != 0) ? "yes" : "no") + "\n"

  print "      Tagged: " +
      ((p.pcos_get_number(doc, "tagged") != 0) ? "yes" : "no") +"\n" + "\n"

  if (pcosmode == 0)
    print "Minimum mode: no more information available\n" + "\n"
    return(0)
  end

  # --------- more details (requires at least user password) */
  print "No. of pages: " +
      p.pcos_get_number(doc, "length:pages").to_i.to_s + "\n"

  printf(" Page 1 size: width=%.3f, height=%.3f\n",
      p.pcos_get_number(doc, "pages[0]/width"),
      p.pcos_get_number(doc, "pages[0]/height"))

  count = p.pcos_get_number(doc, "length:fonts")
  print "No. of fonts: " +  count.to_i.to_s + "\n"

  0.step(count-1,1) do |i|
    fonts = "fonts[" + i.to_i.to_s + "]/embedded"
    if (p.pcos_get_number(doc, fonts) != 0)
      print "embedded "
    else
      print "unembedded "
    end

    fonts = "fonts[" + i.to_i.to_s + "]/type"
    print p.pcos_get_string(doc, fonts) + " font "
    fonts = "fonts[" + i.to_i.to_s + "]/name"
    print p.pcos_get_string(doc, fonts) + "\n"
  end

  print "" + "\n"

  if (pcosmode == 1)
    print "Restricted mode: no more information available"
    return(0)
  end

  # ----- document info keys and XMP metadata (requires master pw) */

  count = p.pcos_get_number(doc, "length:/Info")

  0.step(count-1,1) do |i|
    info = "type:/Info[" + i.to_i.to_s + "]"
    objtype = p.pcos_get_string(doc, info)

    info = "/Info[" + i.to_i.to_s + "].key"
    key = p.pcos_get_string(doc, info)
    len = 12 - key.length()

    len.step(1,-1) do |len|
      print " "
    end

    print key + ": "

    # Info entries can be stored as string or name objects */
    if (objtype == "name" || objtype == "string")
      info = "/Info[" + i.to_i.to_s + "]"
      print "'" + p.pcos_get_string(doc, info) + "'" + "\n"
    else
      info = "type:/Info[" + i.to_i.to_s + "]"
      print "(" + p.pcos_get_string(doc, info) + " object)" + "\n"
    end
  end

  print "\n" + "XMP meta data: "


  objtype = p.pcos_get_string(doc, "type:/Root/Metadata")
  if (objtype == "stream")
    contents = p.pcos_get_stream(doc, "", "/Root/Metadata")
    print contents.length.to_s + " bytes"
    print "" + "\n"
  else
    print "not present" + "\n"
  end

  p.close_pdi_document(doc)

rescue  PDFlibException => pe
  print "PDFlib exception occurred:\n"
  print "[" + pe.get_errnum.to_s + "] " + pe.get_apiname + \
		": " + pe.get_errmsg + "\n"
rescue  Exception => e
  print e.backtrace.join("\n") + "\n" + e.to_s
ensure
  p.delete() if p
end

# vim: sw=2
