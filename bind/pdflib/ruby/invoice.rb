#!/usr/bin/env ruby
#
# $Id: invoice.rb,v 1.4.2.5 2008/02/28 14:49:59 rjs Exp $
#
# PDFlib client: invoice example in ruby
#

require 'PDFlib'

infile = "stationery.pdf"
# This is where font/image/PDF input files live. Adjust as necessary.
searchpath = "../data"
left = 55
right = 530
fontsize = 12
pagewidth = 595
pageheight = 842
baseopt =
  "ruler        {   30 45     275   375   475} " +
  "tabalignment {right left right right right} " +
  "hortabmethod ruler fontsize 12 "


now = Time.now
fulldate = now.strftime("%b %d, %Y")

String      closingtext =
  "Terms of payment: <fillcolor={rgb 1 0 0}>30 days net. " +
  "<fillcolor={gray 0}>90 days warranty starting at the day of sale. " +
  "This warranty covers defects in workmanship only. " +
  "<fontname=Helvetica-BoldOblique encoding=winansi>" +
  "Kraxi Systems, Inc. " +
  "<resetfont>will, at its option, repair or replace the " +
  "product under the warranty. This warranty is not transferable. " +
  "No returns or exchanges will be accepted for wet products."

data = [
  { "name" => "Super Kite",         "price" => 20,  "quantity" => 2},
  { "name" => "Turbo Flyer",        "price" => 40,  "quantity" => 5},
  { "name" => "Giga Trash",         "price" => 180, "quantity" => 1},
  { "name" => "Bare Bone Kit",      "price" => 50,  "quantity" => 3},
  { "name" => "Nitty Gritty",       "price" => 20,  "quantity" => 10},
  { "name" => "Pretty Dark Flyer",  "price" => 75,  "quantity" => 1},
  { "name" => "Free Gift",          "price" => 0,   "quantity" => 1}
]

months = [
  "January", "February", "March", "April", "May", "June",
  "July", "August", "September", "October", "November", "December"
]

begin
  p = PDFlib.new

  # This means we must check return values of load_font() etc.
  p.set_parameter("errorpolicy", "return")

  p.set_parameter("SearchPath", searchpath)

  if (p.begin_document("invoice.pdf", "") == -1)
    raise "Error: " + p.get_errmsg
  end

  p.set_info("Creator", "invoice.rb")
  p.set_info("Author", "Thomas Merz")
  p.set_info("Title", "PDFlib invoice generation demo (Ruby)")

  stationery = p.open_pdi_document(infile, "")
  if (stationery == -1)
    raise "Error: " + p.get_errmsg
  end

  page = p.open_pdi_page(stationery, 1, "")
  if (page == -1)
    raise "Error: " + p.get_errmsg
  end

  boldfont = p.load_font("Helvetica-Bold", "winansi", "")
  if boldfont == -1
    raise "Error: " + p.get_errmsg + "\n"
  end

  regularfont = p.load_font("Helvetica", "winansi", "")
  if regularfont == -1
    raise "Error: " + p.get_errmsg + "\n"
  end

  leading = fontsize + 2

  # Establish coordinates with the origin in the upper left corner.
  p.begin_page_ext(pagewidth, pageheight, "topdown")

  p.fit_pdi_page(page, 0, pageheight, "")
  p.close_pdi_page(page)

  p.setfont(regularfont, fontsize)

  # Print the address
  y = 170
  p.set_value("leading", leading)

  p.show_xy("John Q. Doe", left, y)
  p.continue_text("255 Customer Lane")
  p.continue_text("Suite B")
  p.continue_text("12345 User Town")
  p.continue_text("Everland")

  # Print the header and date

  p.setfont(boldfont, fontsize)
  y = 300
  p.show_xy("INVOICE", left, y)

  p.fit_textline(fulldate, right, y, "position {100 0}")

  # Print the invoice header line

  y = 370
  buf = "\tITEM\tDESCRIPTION\tQUANTITY\tPRICE\tAMOUNT"
  optlist = baseopt + " font " + boldfont.to_s

  textflow = p.create_textflow(buf, optlist)
  if (textflow == -1)
    raise "Error: " + p.get_errmsg
  end

  p.fit_textflow(textflow, left, y-leading, right, y, "")
  p.delete_textflow(textflow)

  # Print the article list

  i = 1
  y += 2*leading
  total = 0

  optlist = baseopt + " font " + regularfont.to_s

  data.each { |row|
    sum = row["price"] * row["quantity"]
    buf = sprintf("\t%d\t%s\t%d\t%.2f\t%.2f",
	i, row["name"], row["quantity"], row["price"], sum);

    textflow = p.create_textflow(buf, optlist)
    if (textflow == -1)
      raise "Error: " + p.get_errmsg
    end

    p.fit_textflow(textflow, left, y-leading, right, y, "")
    p.delete_textflow(textflow)

    i += 1
    y += leading
    total += sum
  }

  y += leading
  p.setfont(boldfont, fontsize)
  p.fit_textline(total.to_s, right, y, "position {100 0}")

  # Print the closing text

  y += 5*leading

  optlist = "alignment=justify leading=120% " \
	  "fontname=Helvetica fontsize=12 encoding=winansi "

  textflow = p.create_textflow(closingtext, optlist)
  if (textflow == -1)
    raise "Error: " + p.get_errmsg
  end

  p.fit_textflow(textflow, left, y+6*leading, right, y, "")
  p.delete_textflow(textflow)

  p.end_page_ext("")
  p.end_document("")
  p.close_pdi_document(stationery)

rescue  PDFlibException => pe
  print "PDFlib exception occurred in invoice sample:\n"
  print "[" + pe.get_errnum.to_s + "] " + pe.get_apiname + \
		  ": " + pe.get_errmsg + "\n"
rescue  Exception => e
  print e.backtrace.join("\n") + "\n" + e.to_s + "\n"
ensure
  p.delete() if p
end

# vim: sw=2
