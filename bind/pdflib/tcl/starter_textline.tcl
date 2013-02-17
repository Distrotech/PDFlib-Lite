#!/bin/sh
# $Id: starter_textline.tcl,v 1.1.2.2 2008/01/10 12:08:01 kurt Exp $
#
# Hide the exec to Tcl but not to the shell by appending a backslash\
exec tclsh "$0" ${1+"$@"}

# The lappend line is unnecessary if PDFlib has been installed
# in the Tcl package directory
set auto_path [linsert $auto_path 0 .libs .]

package require pdflib 7.0

# Starter text line:
# Demonstrate various options for placing a text line
#
# Place a text line with different font sizes.
# Output overlined stroke out and underlined text.
# Output text and define character spacing work spacing or horizontal
# scaling.
# Output text with a defined fill color. Output text including its outlines
# with a defined stroke color.
# Place text into a box at various positions. Place text completely into a box
# with automatic scaling if required.
#
# Required software: PDFlib Lite/PDFlib/PDFlib+PDI/PPS 7
# Required data: none
#

set p [PDF_new]

if { [catch {

    # This is where the data files are. Adjust as necessary. 
    set searchpath "../data"
    set outfile "starter_textline.pdf"
    
	PDF_set_parameter $p "SearchPath" $searchpath

	PDF_set_parameter $p "errorpolicy" "exception"

	# Set an output path according to the name of the topic 
	PDF_begin_document $p $outfile ""

	PDF_set_info $p "Creator" "PDFlib starter sample" 
	PDF_set_info $p "Title" "starter_textline" 

	# Start Page 
	PDF_begin_page_ext $p 0 0 "width=a4.width height=a4.height" 

	# For PDFlib Lite: change "unicode" to "winansi" 
	set font [PDF_load_font $p "Helvetica" "winansi" ""]

	# Set the font with a font size of 14 
	PDF_setfont $p $font 14 

    set x 10 
    set xt 280 
    set y 800 
    set yoff 50
    set textline "Giant Wing Paper Plane"

	# Place the text line without any options applied 
	PDF_fit_textline $p $textline $x $y "" 

	# Output descriptive text 
	PDF_fit_textline $p "fit_textline() without any options" $xt $y	"fontsize=12" 

	# Place the text with a different font size 
	set optlist "fontsize=22"

    set y [expr $y - $yoff]
	PDF_fit_textline $p $textline $x $y $optlist       
	PDF_fit_textline $p $optlist $xt $y "fontsize=12"   


	# Place stroke out text 
	set optlist "strikeout"

    set y [expr $y - $yoff]
	PDF_fit_textline $p $textline $x $y $optlist       
	PDF_fit_textline $p $optlist $xt $y "fontsize=12"   


	# Place underlined text 
	set optlist "underline underlinewidth=7% underlineposition=-20%"

    set y [expr $y - $yoff]
	PDF_fit_textline $p $textline $x $y $optlist       
	PDF_fit_textline $p $optlist $xt $y "fontsize=12"   


	# Place overlined text 
	set optlist "overline"

    set y [expr $y - $yoff]
	PDF_fit_textline $p $textline $x $y $optlist       
	PDF_fit_textline $p $optlist $xt $y "fontsize=12"   


	# Place the text with a horizontal scaling of 150% 
	set optlist "horizscaling=150%"

    set y [expr $y - $yoff]
	PDF_fit_textline $p $textline $x $y $optlist       
	PDF_fit_textline $p $optlist $xt $y "fontsize=12"   


	# Place the text with a character spacing of 30% of the font size 
	set optlist "charspacing=30%"

    set y [expr $y - $yoff]
	PDF_fit_textline $p $textline $x $y $optlist       
	PDF_fit_textline $p $optlist $xt $y "fontsize=12"   


	# Place the text with a word spacing of 50% of the font size 
	set optlist "wordspacing=50%"

    set y [expr $y - $yoff]
	PDF_fit_textline $p $textline $x $y $optlist       
	PDF_fit_textline $p $optlist $xt $y "fontsize=12"   


	# Place the text with a different fill color 
	set optlist "fillcolor={rgb 0.5 0.2 0.5}"

    set y [expr $y - $yoff]
	PDF_fit_textline $p $textline $x $y $optlist 
	PDF_fit_textline $p $optlist $xt $y "fontsize=12" 


	# Place the text including its outlines using a text rendering mode of
	# 2 for "filling and stroking text" and different fill and stroke
	# colors


	set optlist \
		"fontsize=22 fillcolor={rgb 0.6 0.3 0.6} strokecolor={gray 0} \
		 strokewidth=0.4 textrendering=2"

    set y [expr $y - $yoff]
	PDF_fit_textline $p $textline $x $y $optlist 

	# Output descriptive text 
	PDF_fit_textline $p "fillcolor={rgb 0.6 0.3 0.6} strokecolor={gray 0} " \
		 $xt [expr $y + 10] "fontsize=12" 
	PDF_fit_textline $p "strokewidth=0.4 textrendering=2 fontsize=22" \
		 $xt [expr $y - 5] "fontsize=12" 


	# Place the text with its outlines using a text rendering mode of
	# 1 for "stroking text" and a stroke color of black
	 
	set optlist \
		"fontsize=22 strokecolor={gray 0} strokewidth=0.4 textrendering=1"

    set y [expr $y - $yoff]
	PDF_fit_textline $p $textline $x $y $optlist 

	# Output descriptive text 
	PDF_fit_textline $p "strokecolor={gray 0} strokewidth=0.4" \
	    $xt [expr $y + 10] "fontsize=12" 
	PDF_fit_textline $p "textrendering=1 fontsize=22" \
        $xt [expr $y - 5] "fontsize=12" 

	# Place the text in a box with default positioning and fitting 
	set optlist "boxsize={200 20} showborder"

    set y [expr $y - $yoff]
	PDF_fit_textline $p $textline $x $y $optlist                  
	PDF_fit_textline $p $optlist $xt [expr $y + 3] "fontsize=12"  


	# Place the text in a box on the top right 
	set optlist "boxsize={200 20} position={top right} showborder"

    set y [expr $y - $yoff]
	PDF_fit_textline $p $textline $x $y $optlist                  
	PDF_fit_textline $p $optlist $xt [expr $y + 3] "fontsize=12"  


	# Use "fitmethod=clip" to place the text in a box not large enough to
	# show the complete text. The text will be clipped.
	 
	set optlist "boxsize={130 20} fitmethod=clip showborder"

    set y [expr $y - $yoff]
	PDF_fit_textline $p $textline $x $y $optlist                  
	PDF_fit_textline $p $optlist $xt [expr $y + 3] "fontsize=12"  


	# Fit the text into the box automatically with "fitmethod=auto".
	# In this case if the text doesn't fit into the box a distortion
	# factor is calculated which makes the text fit into the box. If this
	# factor is larger than the "shrinklimit" option the text will
	# be distorted by that factor. Otherwise the font size will be
	# be decreased until until the text fits into the box.
	 

	# Use "fitmethod=auto" to place the text in a box not large enough to
	# show the complete text. The text will be distorted.
	 
	set optlist "boxsize={130 20} fitmethod=auto showborder"

    set y [expr $y - $yoff]
	PDF_fit_textline $p $textline $x $y $optlist                  
	PDF_fit_textline $p $optlist $xt [expr $y + 3] "fontsize=12"  


	# Use "fitmethod=auto" to place the text in a box too small to show the
	# complete text. The font size will be reduced until the text fits into
	# the box.
	 
	set optlist "boxsize={100 20} fitmethod=auto showborder"

    set y [expr $y - $yoff]
	PDF_fit_textline $p $textline $x $y $optlist                  
	PDF_fit_textline $p $optlist $xt [expr $y + 3] "fontsize=12"  

	PDF_end_page_ext $p "" 

	PDF_end_document $p "" 


} result]} {
    puts stderr $result
}

PDF_delete $p
