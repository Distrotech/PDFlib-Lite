#!/usr/bin/env ruby
# $Id: starter_block.rb,v 1.3.2.5 2008/05/09 10:11:55 rjs Exp $
#
# Block starter:
# Import a PDF page containing, and process all blocks. The blocks are
# retrieved via pCOS, and the block filling functions are used to
# visualize the blocks on the output page. A real-world application would
# of course fill the blocks with data retrieved from some external data
# source.
#
# required software: PPS 7
# required data: input PDF
#/

require 'PDFlib'

# This is where the data files are. Adjust as necessary.
searchpath = "../data"

infile = "boilerplate.pdf"

begin
  p = PDFlib.new

  # This means we must check return values of load_font() etc.
  p.set_parameter("errorpolicy", "return")

  p.set_parameter("SearchPath", searchpath)

  # we use "utf8" as textformat, this allows to use unicode encoding
  p.set_parameter("textformat", "utf8");

  if (p.begin_document("starter_block.pdf", "") == -1)
    raise "Error: " + p.get_errmsg()
  end

  p.set_info("Creator", "PDFlib starter sample")
  p.set_info("Title", "starter_block")

  # Open a PDF containing blocks
  indoc = p.open_pdi_document(infile, "")
  if (indoc == -1)
    raise "Error: " + p.get_errmsg()
  end

  # Open the first page
  page = p.open_pdi_page(indoc, 1, "")
  if (page == -1)
    raise "Error: " + p.get_errmsg()
  end

  width = p.pcos_get_number(indoc, "pages[0]/width")
  height = p.pcos_get_number(indoc, "pages[0]/height")

  p.begin_page_ext(width, height, "")

  # Place the imported page on the output page
  p.fit_pdi_page(page, 0, 0, "")

  # Query the number of blocks on the first page
  blockcount = p.pcos_get_number(indoc, "length:pages[0]/blocks")

  if (blockcount == 0)
    raise "Error: " + infile + "does not contain any PDFlib blocks"
  end

  # Loop over all blocks on the page
  0.step(blockcount-1,1) do |i|
    # Fetch the name and type of the i-th block on the first page 
    # (one of Text/Image/PDF)
    #
    blockname = p.pcos_get_string(indoc,
	"pages[0]/blocks[" + i.to_i.to_s + "]/Name")

    blocktype = p.pcos_get_string(indoc,
	"pages[0]/blocks[" + i.to_i.to_s + "]/Subtype")

    # Visualize all text blocks
    if (blocktype == "Text")
	optlist = "fontname=Helvetica encoding=unicode " +
	    "fillcolor={rgb 1 0 0} bordercolor={gray 0} linewidth=0.25"

	# We simply use the blockname as content
	if (p.fill_textblock(page, blockname, blockname, optlist) == -1)
	    print "Warning: " + p.get_errmsg()
	end
    end
  end

  p.end_page_ext("")
  p.close_pdi_page(page)

  p.end_document("")
  p.close_pdi_document(indoc)

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
