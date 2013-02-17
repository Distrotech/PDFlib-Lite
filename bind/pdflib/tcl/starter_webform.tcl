#!/bin/sh
# $Id: starter_webform.tcl,v 1.1.2.1 2008/03/20 19:47:01 rp Exp $
#
# Hide the exec to Tcl but not to the shell by appending a backslash\
exec tclsh "$0" ${1+"$@"}

# Webform starter:
# create a linearized PDF (for fast delivery over the Web also known
# as "fast Web view") which is encrypted and contains some form fields.
# A few lines of JavaScript are inserted as "page open" action to
# automatically populate the date field with the current date.
#
# required software: PDFlib/PDFlib+PDI/PPS 7
# required data: none

# The lappend line is unnecessary if PDFlib has been installed
# in the Tcl package directory
set auto_path [linsert $auto_path 0 .libs .]

package require pdflib 7.0

set outfilename "starter_webform.pdf"

set llx 150
set lly 550
set urx 350
set ury 575

# JavaScript for automatically filling the date into a form field
set js "var d = util.printd(\"mm/dd/yyyy\" new Date()var date = this.getField(\"date\");date.value = d;"

set p [PDF_new]

if { [catch {
    # This means we must check return values of load_font() etc.
    PDF_set_parameter $p "errorpolicy" "return"

    # Prevent changes with a master password
    set optlist  "linearize masterpassword=pdflib permissions={nomodify}"

    if {[PDF_begin_document $p $outfilename $optlist] == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    PDF_set_info $p "Creator" "PDFlib starter sample"
    PDF_set_info $p "Title" "starter_webform"

    set optlist [format "script={%s}" $js]
    set action [PDF_create_action $p "JavaScript" $optlist]

    set optlist [format "action={open=%d}" $action]
    PDF_begin_page_ext $p 595 842 $optlist

    set font [PDF_load_font $p "Helvetica" "winansi" ""]
    if {$font == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }
    PDF_setfont $p $font 24

    PDF_fit_textline $p "Date: " 125 [expr $lly + 5] "position={right bottom}"

    # The tooltip will be used as rollover text for the field
    set optlist "tooltip={Date (will be filled automatically)} "
    append optlist [format "bordercolor={gray 0} font=%d" $font]
    PDF_create_field $p $llx $lly $urx $ury "date" "textfield" $optlist

    set lly [expr $lly - 100]
    set ury [expr $ury - 100]

    PDF_fit_textline $p "Name: " 125 [expr $lly + 5] "position={right bottom}"

    set optlist "tooltip={Enter your name here} "
    append optlist [format "bordercolor={gray 0} font=%d" $font]
    PDF_create_field $p $llx $lly $urx $ury "name" "textfield" $optlist

    PDF_end_page_ext $p ""

    PDF_end_document $p ""

} result] } {
    puts stderr "$result"
}

# delete the PDFlib object
PDF_delete $p
