#!/bin/sh
# $Id: starter_table.tcl,v 1.2.2.1 2008/03/20 21:31:51 rjs Exp $
#
# Hide the exec to Tcl but not to the shell by appending a backslash\
exec tclsh "$0" ${1+"$@"}

# Table starter:
# Create table which may span multiple pages
#
# required software: PDFlib/PDFlib+PDI/PPS 7
# required data: image file (dummy text created within the program)

# The lappend line is unnecessary if PDFlib has been installed
# in the Tcl package directory
set auto_path [linsert $auto_path 0 .libs .]

package require pdflib 7.0

# This is where the data files are. Adjust as necessary.
set searchpath "../data"
set imagefile "nesrin.jpg"
set outfilename "starter_table.pdf"

set tf -1
set tbl -1
set rowmax 50
set colmax 5
set llx 50
set lly 50
set urx 550
set ury 800

set headertext "Table header (centered across all columns)"

# Dummy text for filling a cell with multi-line Textflow
set tf_text "Lorem ipsum dolor sit amet, consectetur adi&shy;pi&shy;sicing elit, sed do eius&shy;mod tempor incidi&shy;dunt ut labore et dolore magna ali&shy;qua. Ut enim ad minim ve&shy;niam, quis nostrud exer&shy;citation ull&shy;amco la&shy;bo&shy;ris nisi ut ali&shy;quip ex ea commodo con&shy;sequat. Duis aute irure dolor in repre&shy;henderit in voluptate velit esse cillum dolore eu fugiat nulla pari&shy;atur. Excep&shy;teur sint occae&shy;cat cupi&shy;datat non proident, sunt in culpa qui officia dese&shy;runt mollit anim id est laborum. "

set p [PDF_new]

if { [catch {
    # This means we must check return values of load_font() etc.
    PDF_set_parameter $p "errorpolicy" "return"

    PDF_set_parameter $p "SearchPath" $searchpath

    if {[PDF_begin_document $p $outfilename ""] == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
    }

    PDF_set_info $p "Creator" "PDFlib starter sample"
    PDF_set_info $p "Title" "starter_table"

    # -------------------- Add table cells --------------------

    # ---------- row 1: table header (spans all columns)
    set row 1
    set col  1
    set font [PDF_load_font $p "Times-Bold" "unicode" ""]
    if {$font == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    set optlist [format "fittextline={position=center font=%d " $font]
    append optlist [format "fontsize=14} colspan=%d" $colmax]

    set tbl [PDF_add_table_cell $p $tbl $col $row $headertext $optlist]
    if {$tbl == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    # ---------- row 2: various kinds of content
    # ----- Simple text cell
    set row [expr $row + 1]
    set col 1

    set optlist [format "fittextline={font=%d fontsize=10 orientate=west}" $font]

    set tbl [PDF_add_table_cell $p $tbl $col $row "vertical line" $optlist]
    if {$tbl == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    # ----- Colorized background
    set col [expr $col + 1]

    set optlist [format "fittextline={font=%d fontsize=10} " $font]
    append optlist "matchbox={fillcolor={rgb 0.9 0.5 0}}"

    set tbl [PDF_add_table_cell $p $tbl $col $row "some color" $optlist]
    if {$tbl == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    # ----- Multi-line text with Textflow
    set col [expr $col + 1]
    set font [PDF_load_font $p "Times-Roman" "unicode" ""]
    if {$font == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    set optlist "charref fontname=Times-Roman encoding=unicode fontsize=8 "

    set tf [PDF_add_textflow $p $tf $tf_text $optlist]

    set optlist [format "margin=2 textflow=%d" $tf]

    set tbl [PDF_add_table_cell $p $tbl $col $row "" $optlist]
    if {$tbl == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    # ----- Rotated $image
    set col [expr $col + 1]

    set image [PDF_load_image $p "auto" $imagefile ""]
    if {$tbl == -1} {
	puts stderr "Couldn't load $image: [PDF_get_errmsg $p]"
	exit
    }

    set optlist [format "image=%d fitimage={orientate=west}" $image]

    set tbl [PDF_add_table_cell $p $tbl $col $row "" $optlist]
    if {$tbl == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    # ----- Diagonal stamp
    set col [expr $col + 1]

    set optlist [format "fittextline={font=%d fontsize=10 stamp=ll2ur}" $font]

    set tbl [PDF_add_table_cell $p $tbl $col $row "entry void" $optlist]
    if {$tbl == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    # ---------- Fill $row 3 and above with their numbers
    for {set row [expr $row + 1]} {$row <= $rowmax} {set row [expr $row + 1]} {
	for {set col 1} {$col <= $colmax} {set col [expr $col + 1]} {
	    set num [format "Col %d/Row %d" $col $row]
	    set optlist "colwidth=20% fittextline={font="
	    append optlist [format "%s fontsize=10}" $font]
	    set tbl [PDF_add_table_cell $p $tbl $col $row $num $optlist]
	    if {$tbl == -1} {
		puts stderr "Error: [PDF_get_errmsg $p]"
		exit
	    }
	}
    }

    # ---------- Place the table on one or more pages ----------

    #
    # Loop until all of the table is placed; create new pages
    # as long as more table instances need to be placed.

    set result "_boxfull"
    while {$result == "_boxfull"} {
	PDF_begin_page_ext $p 0 0 "width=a4.width height=a4.height"

	# Shade every other $row; draw lines for all table cells.
	# Add "showcells showborder" to visualize cell borders 

	set optlist "header=1 fill={{area=rowodd fillcolor={gray 0.9}}} "
	append optlist "stroke={{line=other}} "

	# Place the table instance
	set result [PDF_fit_table $p $tbl $llx $lly $urx $ury $optlist]
	if {$result == "_error"} {
	    puts stderr "Couldn't place table: [PDF_get_errmsg $p]"
	    exit
	}

	PDF_end_page_ext $p ""

    }

    # Check the $result; "_stop" means all is ok.
    if {$result != "_stop"} {
	if {$result == "_error"} {
	    puts stderr "Error when placing table: [PDF_get_errmsg $p]"
	    exit
	} else {
	    # Any other return value is a user exit caused by
	    # the "return" option; this requires dedicated code to
	    # deal with.
	    puts stderr "User return found in Textflow"
	    exit
	}
    }

    # This will also delete Textflow handles used in the table
    PDF_delete_table $p $tbl ""

    PDF_end_document $p ""

} result] } {
    puts stderr "$result"
}

# delete the PDFlib object
PDF_delete $p
