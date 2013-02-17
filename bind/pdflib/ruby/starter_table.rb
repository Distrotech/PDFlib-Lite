#!/usr/bin/env ruby
# $Id: starter_table.rb,v 1.4.2.4 2008/02/28 14:49:59 rjs Exp $
#
# Table starter:
# Create table which may span multiple pages
#
# required software: PDFlib/PDFlib+PDI/PPS 7
# required data: image file (dummy text created within the program)
#/

require 'PDFlib'


searchpath = "../data"

imagefile = "nesrin.jpg"

tf=-1
tbl=-1
rowmax=50
colmax=5

llx= 50
lly=50
urx=550
ury=800
headertext = "Table header (centered across all columns)"

# Dummy text for filling a cell with multi-line Textflow
tf_text = 
"Lorem ipsum dolor sit amet, consectetur adi&shy;pi&shy;sicing elit, sed do eius&shy;mod tempor incidi&shy;dunt ut labore et dolore magna ali&shy;qua. Ut enim ad minim ve&shy;niam, quis nostrud exer&shy;citation ull&shy;amco la&shy;bo&shy;ris nisi ut ali&shy;quip ex ea commodo con&shy;sequat. Duis aute irure dolor in repre&shy;henderit in voluptate velit esse cillum dolore eu fugiat nulla pari&shy;atur. Excep&shy;teur sint occae&shy;cat cupi&shy;datat non proident, sunt in culpa qui officia dese&shy;runt mollit anim id est laborum. "

begin
  p = PDFlib.new

  # This means we must check return values of load_font() etc.
  p.set_parameter("errorpolicy", "return")

  p.set_parameter("SearchPath", searchpath)

  # we use "utf8" as textformat, this allows to use unicode encoding
  p.set_parameter("textformat", "utf8");

  if (p.begin_document("starter_table.pdf", "") == -1)
    raise "Error: " + p.get_errmsg()
  end

  p.set_info("Creator", "PDFlib starter sample")
  p.set_info("Title", "starter_table")

  # -------------------- Add table cells --------------------

  # ---------- Row 1: table header (spans all columns)
  row = 1
  col = 1
  font = p.load_font("Times-Bold", "unicode", "")

  if font == -1
    raise "Error: " + p.get_errmsg + "\n"
  end


  optlist =
  "fittextline={position=center font=" + font.to_s + " fontsize=14} " +
  "colspan=" + colmax.to_s

  tbl = p.add_table_cell(tbl, col, row, headertext, optlist)

  if tbl == -1
    raise "Error: " + p.get_errmsg + "\n"
  end

  # ---------- Row 2: various kinds of content
  # ----- Simple text cell
  row += 1
  col=1

  optlist = "fittextline={font=" + font.to_s + " fontsize=10 orientate=west}"

  tbl = p.add_table_cell(tbl, col, row, "vertical line", optlist)

  if tbl == -1
    raise "Error: " + p.get_errmsg + "\n"
  end

  # ----- Colorized background
  col += 1

  optlist = "fittextline={font=" + font.to_s + " fontsize=10} " +
  "matchbox={fillcolor={rgb 0.9 0.5 0}}"

  tbl = p.add_table_cell(tbl, col, row, "some color", optlist)

  if tbl == -1
    raise "Error: " + p.get_errmsg + "\n"
  end

  # ----- Multi-line text with Textflow
  col += 1
  font = p.load_font("Times-Roman", "unicode", "")

  if font == -1
    raise "Error: " + p.get_errmsg + "\n"
  end


  optlist = "charref fontname=Times-Roman encoding=unicode fontsize=8 "

  tf = p.add_textflow(tf, tf_text, optlist)
  if tf == -1
    raise "Error: " + p.get_errmsg + "\n"
  end

  optlist = "margin=2 textflow=" + tf.to_s

  tbl = p.add_table_cell(tbl, col, row, "", optlist)

  if tbl == -1
    raise "Error: " + p.get_errmsg + "\n"
  end

  # ----- Rotated image
  col += 1

  image = p.load_image("auto", imagefile, "")
  if (image == -1)
    raise "Couldn't load image: " + p.get_errmsg()
  end

  optlist = "image=" + image.to_s + " fitimage={orientate=west}"

  tbl = p.add_table_cell(tbl, col, row, "", optlist)

  if tbl == -1
    raise "Error: " + p.get_errmsg + "\n"
  end

  # ----- Diagonal stamp
  col += 1

  optlist = "fittextline={font=" + font.to_s + " fontsize=10 stamp=ll2ur}"

  tbl = p.add_table_cell(tbl, col, row, "entry void", optlist)

  if tbl == -1
    raise "Error: " + p.get_errmsg + "\n"
  end

  # ---------- Fill row 3 and above with their numbers
  row += 1
  row.step(rowmax,1) do |row|
    1.step(colmax,1) do |col|
      num = "Col " + col.to_s + "/Row " + row.to_s
      optlist = "colwidth=20% fittextline={font=" + font.to_s + " fontsize=10}"
      tbl = p.add_table_cell(tbl, col, row, num, optlist)

      if tbl == -1
	raise "Error: " + p.get_errmsg + "\n"
      end
    end
  end

  # ---------- Place the table on one or more pages ----------

  #
  # Loop until all of the table is placed; create new pages
  # as long as more table instances need to be placed.
  #
  begin
    p.begin_page_ext(0, 0, "width=a4.width height=a4.height")

    # Shade every other row; draw lines for all table cells.
    # Add "showcells showborder" to visualize cell borders 
    optlist = "header=1 fill={{area=rowodd fillcolor={gray 0.9}}} " +
    "stroke={{line=other}} "

    # Place the table instance
    result = p.fit_table(tbl, llx, lly, urx, ury, optlist)
    if (result ==  "_error")
      raise "Couldn't place table: " + p.get_errmsg()
    end

    p.end_page_ext("")

  end while (result == "_boxfull")

  # Check the result; "_stop" means all is ok.
  if (!result == "_stop") then
    if (result ==  "_error")
      raise "Error when placing table: " + p.get_errmsg()
    else 
      # Any other return value is a user exit caused by
      # the "return" option; this requires dedicated code to
      # deal with.
      raise "User return found in Textflow"
    end
  end

  # This will also delete Textflow handles used in the table
  p.delete_table(tbl, "")

  p.end_document("")

rescue  PDFlibException => pe
  print "PDFlib exception occurred:\n"
  print "[" + pe.get_errnum.to_s + "] " + pe.get_apiname + \
		": " + pe.get_errmsg + "\n"
  print pe.backtrace.join("\n") + "\n" + pe.to_s
rescue  Exception => e
  print e.backtrace.join("\n") + "\n" + e.to_s
ensure
  p.delete() if p
end

# vim: sw=2
