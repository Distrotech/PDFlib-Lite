#!/usr/bin/env ruby
# $Id: starter_3d.rb,v 1.1.2.2 2008/02/28 14:49:59 rjs Exp $
# 3D Starter:
# Create a 3D model and load it into a U3D annotation.
#
# Define a 3D view and load some 3D data with the view defined. Then create
# an annotation containing the loaded 3D data with the defined 3D view as the
# initial view.
#
# Acrobat 7.07 or above is required for viewing PDF documents containing a
# 3D model.
#
# Required software: PDFlib/PDFlib+PDI/PPS 7.0.1
# Required data: U3D data file

require 'PDFlib'

# This is where the data files are. Adjust if necessary.
searchpath = "../data"
outfile = "starter_3d.pdf"
title = "Starter 3D"

# Required minimum PDFlib version
requiredversion = 701
requiredvstr = "7.0.1"

begin
    p = PDFlib.new

	p.set_parameter("SearchPath", searchpath)

	# This means we must check return values of load_font() etc.
	p.set_parameter("errorpolicy", "return")

	# Check whether the required minimum PDFlib version is available
	major = p.get_value("major", 0)
	minor = p.get_value("minor", 0)
	revision = p.get_value("revision", 0)

	if (major*100 + minor*10 + revision < requiredversion)
		raise "Error: PDFlib " + requiredvstr + " or above is required\n"
    end

	# Start the document
	if (p.begin_document(outfile, "") == -1)
        raise "Error: " + p.get_errmsg()
    end

	p.set_info("Creator", "PDFlib Cookbook")
	p.set_info("Title", title + " $Revision: 1.1.2.2 $")

	font = p.load_font("Helvetica", "winansi", "")
	if font == -1
		raise "Error: " + p.get_errmsg + "\n"
	end

	p.begin_page_ext(0, 0, "width=a4.width height=a4.height")

	# Define a U3D view
	optlist = "name=FirstView background={fillcolor={rgb 1 0.5 0.1}}"
	if ((u3dview = p.create_3dview("First view", optlist)) == -1)
		raise "Error: " + p.get_errmsg + "\n"
	end

	# Load some U3D data with the view defined above
	u3ddata = p.load_3ddata("box.u3d", "views={" + u3dview.to_s + "}")
	if u3ddata == -1
		raise "Error: " + p.get_errmsg + "\n"
	end

	# Create an annotation containing the loaded U3D data with the
	# defined 3D view as the initial view

	optlist = "name=annot usercoordinates contents=U3D 3ddata= " + \
	    u3ddata.to_s + " 3dactivate={enable=open} 3Dinitialview=" + \
	    u3dview.to_s
	p.create_annotation(116, 400, 447, 580, "3D", optlist)

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

# vim: sw=4
