#!/usr/bin/env ruby
# $Id: starter_webform.rb,v 1.2.2.4 2008/02/28 14:49:59 rjs Exp $
#
# Webform starter:
# create a linearized PDF (for fast delivery over the Web, also known
# as "fast Web view") which is encrypted and contains some form fields.
# A few lines of JavaScript are inserted as "page open" action to
# automatically populate the date field with the current date.
#
# required software: PDFlib/PDFlib+PDI/PPS 7
# required data: none

require 'PDFlib'

llx=150
lly=550
urx=350
ury=575

# JavaScript for automatically filling the date into a form field
js =
    "var d = util.printd(\"mm/dd/yyyy\", new Date());" +
    "var date = this.getField(\"date\");" +
    "date.value = d;"

begin
  p = PDFlib.new

  # This means we must check return values of load_font() etc.
  p.set_parameter("errorpolicy", "return")

  # Prevent changes with a master password
  optlist = "linearize masterpassword=pdflib permissions={nomodify}"

  if (p.begin_document("starter_webform.pdf", optlist) == -1)
    raise "Error: " + p.get_errmsg()
  end

  p.set_info("Creator", "PDFlib starter sample")
  p.set_info("Title", "starter_webform")

  optlist = "script={" + js + "}"
  action = p.create_action("JavaScript", optlist)

  optlist = "action={open=" + action.to_s + "}"
  p.begin_page_ext(595, 842, optlist)

  font = p.load_font("Helvetica", "winansi", "")

  if font == -1
    raise "Error: " + p.get_errmsg + "\n"
  end

  p.setfont(font, 24)

  p.fit_textline("Date: ", 125, lly+5, "position={right bottom}")

  # The tooltip will be used as rollover text for the field
  optlist =
      "tooltip={Date (will be filled automatically)} " +
      "bordercolor={gray 0} font=" + font.to_s
  p.create_field(llx, lly, urx, ury, "date", "textfield", optlist)

  lly-=100; ury-=100
  p.fit_textline("Name: ", 125, lly+5, "position={right bottom}")

  optlist = "tooltip={Enter your name here} " +
      "bordercolor={gray 0} font=" + font.to_s
  p.create_field(llx, lly, urx, ury, "name", "textfield", optlist)

  p.end_page_ext("")

  p.end_document("")

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
