#!/usr/bin/env ruby
#  $Id: pdfclock.rb,v 1.3.2.3 2008/02/28 14:49:59 rjs Exp $
# 
#  PDFlib client: pdfclock example in Ruby
#

require 'PDFlib'

RADIUS = 200.0
MARGIN = 20.0
time = Time.now

begin
  p = PDFlib.new

  # This means we must check return values of load_font() etc.
  p.set_parameter("errorpolicy", "return")

  if (p.begin_document("pdfclock.pdf", "") == -1)
    raise "Error: " + p.get_errmsg
  end

  p.set_info("Creator", "pdfclock.rb")
  p.set_info("Author", "Thomas Merz")
  p.set_info("Title", "PDF clock (Ruby)")

  p.begin_page_ext( (2 * (RADIUS + MARGIN)), (2 * (RADIUS + MARGIN)), "")

  p.translate(RADIUS + MARGIN, RADIUS + MARGIN)
  p.setcolor("fillstroke", "rgb", 0.0, 0.0, 1.0, 0.0)
  p.save

  # minute strokes 
  p.setlinewidth(2.0)
  0.step(360, 6) do |alpha|
    p.rotate(6.0)
    p.moveto(RADIUS, 0.0)
    p.lineto(RADIUS-MARGIN/3, 0.0)
    p.stroke
  end

  p.restore
  p.save

  # 5 minute strokes
  p.setlinewidth(3.0)
  0.step(360, 30) do |alpha|
    p.rotate(30.0)
    p.moveto(RADIUS, 0.0)
    p.lineto(RADIUS-MARGIN, 0.0)
    p.stroke
  end

  # draw hour hand 
  p.save
  p.rotate((-((time.min/60.0) + time.hour - 3.0) * 30.0))
  p.moveto(-RADIUS/10, -RADIUS/20)
  p.lineto(RADIUS/2, 0.0)
  p.lineto(-RADIUS/10, RADIUS/20)
  p.closepath
  p.fill
  p.restore

  # draw minute hand
  p.save
  p.rotate((-((time.sec/60.0) + time.min - 15.0) * 6.0))
  p.moveto(-RADIUS/10, -RADIUS/20)
  p.lineto(RADIUS * 0.8, 0.0)
  p.lineto(-RADIUS/10, RADIUS/20)
  p.closepath
  p.fill
  p.restore

  # draw second hand
  p.setcolor("fillstroke", "rgb", 1.0, 0.0, 0.0, 0.0)
  p.setlinewidth(2)
  p.save
  p.rotate(-((time.sec - 15.0) * 6.0))
  p.moveto(-RADIUS/5, 0.0)
  p.lineto(RADIUS, 0.0)
  p.stroke
  p.restore

  # draw little circle at center
  p.circle(0, 0, RADIUS/30)
  p.fill

  p.restore
  p.end_page_ext("")
  p.end_document("")

rescue  PDFlibException => pe
  print "PDFlib exception occurred in pdfclock sample:\n"
  print "[" + pe.get_errnum.to_s + "] " + pe.get_apiname + \
		  ": " + pe.get_errmsg + "\n"
rescue Exception => e
  print e.backtrace.join("\n") + "\n" + e.to_s
ensure
  p.delete() if p
end

# vim: sw=2
