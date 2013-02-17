#!/bind/sh
# $Id: starter_3d.tcl,v 1.1.2.1 2008/02/22 23:45:34 rjs Exp $
# 3D Starter:
# Create a 3D model and load it into a U3D annotation.
# Hide the exec to Tcl but not to the shell by appending a backslash\
exec tclsh "$0" ${1+"$@"}

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
#

# The lappend line is unnecessary if PDFlib has been installed
# in the Tcl package directory
set auto_path [linsert $auto_path 0 .libs .]

package require pdflib 7.0

# This is where the data files are. Adjust if necessary.
set searchpath "../data"
set outfile "starter_3d.pdf"

# Required minimum PDFlib version
set requiredversion 701
set requiredvstr "7.0.1"

# create a new PDFlib object
set p [PDF_new]


if { [catch { 

    PDF_set_parameter $p "SearchPath" $searchpath

    # This means we must check return values of load_font() etc.
    PDF_set_parameter $p "errorpolicy" "return"

    # Check whether the required minimum PDFlib version is available
    set major [PDF_get_value $p "major" 0]
    set minor [PDF_get_value $p "minor" 0]
    set revision [PDF_get_value $p "revision" 0]

    if {$major*100 + $minor*10 + $revision < $requiredversion} {
	puts stderr [format "Error: PDFlib %s or above is required\n" $requiredvstr ]
	exit
    }

    # Start the document
    if {[PDF_begin_document $p outfile ""] == -1} {
        puts stderr "Error:  [PDF_get_errmsg $p]"
	exit
    }

    PDF_set_info $p "Creator" "PDFlib Cookbook"
    PDF_set_info $p "Title" "starter_3d"

    set font [PDF_load_font $p "Helvetica" "winansi" ""]
    if {$font == -1} {
        puts stderr "Error:  [PDF_get_errmsg $p]"
	exit
    }

    PDF_begin_page_ext $p 0 0 "width=a4.width height=a4.height"

    # Define a U3D view
    set optlist "name=FirstView background={fillcolor={rgb 1 0.5 0.1}}"
    set u3dview [PDF_create_3dview $p "First view" $optlist]
    if {$u3dview == -1} {
        puts stderr "Error:  [PDF_get_errmsg $p]"
	exit
    }

    # Load some U3D data with the view defined above
    set buf [format "views={%d}" $u3dview ]
    set u3ddata [PDF_load_3ddata $p "box.u3d" $buf]
    if {$u3ddata == -1} {
        puts stderr "Error:  [PDF_get_errmsg $p]"
	exit
    }

    # Create an annotation containing the loaded U3D data with the
    # defined 3D view as the initial view
    #
    set buf [format "name=annot usercoordinates contents=U3D 3ddata=%d 3dactivate={enable=open} 3Dinitialview=%d" $u3ddata  $u3dview]
    PDF_create_annotation $p 116 400 447 580 "3D" $buf

    PDF_end_page_ext $p ""

    PDF_end_document $p ""

} result] } {
    puts stderr "$result$"
}

# delete the PDFlib object
PDF_delete $p

