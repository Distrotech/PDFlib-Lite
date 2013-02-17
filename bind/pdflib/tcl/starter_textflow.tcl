#!/bin/sh
# $Id: starter_textflow.tcl,v 1.2 2006/10/04 18:12:31 rjs Exp $
#
# Hide the exec to Tcl but not to the shell by appending a backslash\
exec tclsh "$0" ${1+"$@"}

# Textflow starter:
# Create multi-column text output which may span multiple pages
#
# required software: PDFlib/PDFlib+PDI/PPS 7 or above
# required data: none

# The lappend line is unnecessary if PDFlib has been installed
# in the Tcl package directory
set auto_path [linsert $auto_path 0 .libs .]

package require pdflib 7.0

set outfilename "starter_textflow.pdf"
set tf -1
set llx1 50
set lly1 50
set urx1 250
set ury1 800
set llx2 300
set lly2 50
set urx2 500
set ury2 800

# Repeat the dummy text to produce more contents
set count 50

set optlist1 "fontname=Helvetica fontsize=10.5 encoding=unicode fillcolor={gray 0} alignment=justify"
set optlist2 "fontname=Helvetica-Bold fontsize=14 encoding=unicode fillcolor={rgb 1 0 0} charref"

# Dummy text for filling the columns. Soft hyphens are marked with
# the character reference "&shy;" (character references are
# enabled by the charref option).

set text "Lorem ipsum dolor sit amet, consectetur adi&shy;pi&shy;sicing elit, sed do eius&shy;mod tempor incidi&shy;dunt ut labore et dolore magna ali&shy;qua. Ut enim ad minim ve&shy;niam, quis nostrud exer&shy;citation ull&shy;amco la&shy;bo&shy;ris nisi ut ali&shy;quip ex ea commodo con&shy;sequat. Duis aute irure dolor in repre&shy;henderit in voluptate velit esse cillum dolore eu fugiat nulla pari&shy;atur. Excep&shy;teur sint occae&shy;cat cupi&shy;datat non proident, sunt in culpa qui officia dese&shy;runt mollit anim id est laborum. "

set p [PDF_new]

if { [catch {
    # This means we must check return values of load_font() etc.
    PDF_set_parameter $p "errorpolicy" "return"

    if {[PDF_begin_document $p $outfilename ""] == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    PDF_set_info $p "Creator" "PDFlib starter sample"
    PDF_set_info $p "Title" "starter_textflow"

    # Create some amount of dummy text and feed it to a Textflow
    # object with alternating options. 

    for {set i 1} {$i <= $count} {set i [expr $i + 1]} {
	set num [format "%d " $i]

	set tf [PDF_add_textflow $p $tf $num $optlist2]
	set tf [PDF_add_textflow $p $tf $text $optlist1]
    }

    # Loop until all of the text is placed; create new pages
    # as long as more text needs to be placed. Two columns will
    # be created on all pages.
 
    set result "_boxfull"
    while {$result == "_boxfull" || $result == "_nextpage"} {
	# Add "showborder to visualize the fitbox borders
	set optlist "verticalalign=justify linespreadlimit=120% "

	PDF_begin_page_ext $p 0 0 "width=a4.width height=a4.height"

	# Fill the first column
	set result [PDF_fit_textflow $p $tf $llx1 $lly1 $urx1 $ury1 $optlist]

	# Fill the second column if we have more text*/
	if {$result != "_stop"} {
	    set result [PDF_fit_textflow $p $tf $llx2 $lly2 $urx2 $ury2 $optlist]
	}

	PDF_end_page_ext $p ""

	# "_boxfull" means we must continue because there is more text;
	# "_nextpage" is interpreted as "start new column"

    }

    # Check for errors
    if {$result != "_stop"} {
	# "_boxempty" happens if the box is very small and doesn't
	# hold any text at all.

	if {$result == "_boxempty"} {
	    puts stderr "Error: Textflow box too small"
	    exit
	} else {
	    # Any other return value is a user exit caused by
	    # the "return" option; this requires dedicated code to
	    # deal with.
	    puts stderr [format "User return '' found in Textflow" $resulst]
	    exit
	}
    }

    PDF_delete_textflow $p $tf

    PDF_end_document $p ""

} result] } {
    puts stderr "$result"
}

# delete the PDFlib object
PDF_delete $p
