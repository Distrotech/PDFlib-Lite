#!/usr/bin/perl
# $Id: starter_graphics.pl,v 1.1.2.3 2008/12/25 13:28:41 rp Exp $
# Starter Graphics:
# Create some basic examples of vector graphics
#
# Stroke a line, curve, circle, arc, and rectangle using the current line width
# and stroke color. Stroke and fill a rectangle.
# Draw an arc segment by drawing a line and an arc, closing the path and
# filling and stroking it.
# Draw a rectangle and use it as the clipping a path. Draw and fill a circle
# using the clipping path defined.
#
# Required software: PDFlib Lite/PDFlib/PDFlib+PDI/PPS 7
# Required data: none

use pdflib_pl 7.0;
use strict;

# This is where the data files are. Adjust as necessary.
my $searchpath = "../data";
my $outfile = "starter_graphics.pdf";
my $title = "Starter Graphics";

# create a new PDFlib object
my $p = PDF_new();

my $buf;
my $xt=20;
my $x = 210;
my $y=770;
my $dy=90;
my $font;


eval {
    PDF_set_parameter($p, "SearchPath", $searchpath);

    # This means we must check return values of load_font() etc.
    PDF_set_parameter($p, "errorpolicy", "return");

    if (PDF_begin_document($p, $outfile, "") == -1) {
	printf("Error: %s\n", PDF_get_errmsg($p));
	PDF_delete($p);
	return(2);
    }

    PDF_set_info($p, "Creator", "PDFlib Cookbook");
    $buf = $title . '  $Revision: 1.1.2.3 $';
    PDF_set_info($p, "Title", $buf);

    # Load the font; for PDFlib Lite: change "unicode" to "winansi"
    $font = PDF_load_font($p, "Helvetica", "winansi", "");
    if ($font == -1) {
	printf("Error: %s\n", PDF_get_errmsg($p));
	PDF_delete($p);
	exit(2);
    }

    # Start an A4 page
    PDF_begin_page_ext($p, 0, 0, "width=a4.width height=a4.height");

    # Set the font
    PDF_setfont($p, $font, 14);

    # Set the line width
    PDF_setlinewidth($p, 2.0);

    # Set the stroke color
    PDF_setcolor($p, "stroke", "rgb", 0.0, 0.5, 0.5, 0.0);

    # Set the fill color
    PDF_setcolor($p, "fill", "rgb", 0.0, 0.85, 0.85, 0.0);


    # -------------
    # Stroke a line
    # -------------
    

    # Set the current point for graphics output
    PDF_moveto($p, $x, $y);

    # Draw a line from the current point to the supplied point
    PDF_lineto($p, $x+300, $y+50);

    # Stroke the path using the current line width and stroke color, and
    # clear it
    
    PDF_stroke($p);

    # Output some descriptive black text
    PDF_fit_textline($p, "lineto() and stroke()", $xt, $y,
	"fillcolor={gray 0}");


    # --------------
    # Stroke a curve
    # --------------
    

    # Set the current point for graphics output
    PDF_moveto($p, $x, $y-=$dy);

    # Draw a Bézier curve from the current point to (x3, y3), using three
    # control points
    
    PDF_curveto($p, $x+50, $y+40, $x+200, $y+80, $x+300, $y+30);

    # Stroke the path using the current line width and stroke color, and
    # clear it
    
    PDF_stroke($p);

    # Output some descriptive black text
    PDF_fit_textline($p, "curveto() and stroke()", $xt, $y, 
	"fillcolor={gray 0}");


    # ---------------
    # Stroke a circle
    # ---------------
    

    # Draw a circle at position (x, y) with a radius of 40
    PDF_circle($p, $x, $y-=$dy, 40);

    # Stroke the path using the current line width and stroke color, and
    # clear it
    
    PDF_stroke($p);

    # Output some descriptive black text
    PDF_fit_textline($p, "circle() and stroke()", $xt, $y,
	"fillcolor={gray 0}");


    # ---------------------
    # Stroke an arc segment
    # ---------------------
    

    # Draw an arc segment counterclockwise at position (x, y) with a radius
    # of 40 starting at an angle of 90 degrees and ending at 180 degrees
    
    PDF_arc($p, $x, $y-=$dy+20, 40, 90, 180);

    # Stroke the path using the current line width and stroke color, and
    # clear it
    
    PDF_stroke($p);

    # Output some descriptive black text
    PDF_fit_textline($p, "arc() and stroke()", $xt, $y,
	"fillcolor={gray 0}");


    # ------------------
    # Stroke a rectangle
    # ------------------
    

    # Draw a rectangle at position (x, y) with a width of 200 and a height
    # of 50
    
    PDF_rect($p, $x, $y-=$dy, 200, 50);

    # Stroke the path using the current line width and stroke color, and
    # clear it
    
    PDF_stroke($p);

    # Output some descriptive black text
    PDF_fit_textline($p, "rect() and stroke()", $xt, $y,
	"fillcolor={gray 0}");


    # ----------------
    # Fill a rectangle
    # ----------------
    

    # Draw a rectangle at position (x, y) with a width of 200 and a height
    # of 50
    
    PDF_rect($p, $x, $y-=$dy, 200, 50);

    # Fill the path using current fill color, and clear it
    PDF_fill($p);

    # Output some descriptive black text
    PDF_fit_textline($p, "rect() and fill()", $xt, $y,
	"fillcolor={gray 0}");


    # ---------------------------
    # Fill and stroke a rectangle
    # ---------------------------
    

    # Draw a rectangle at position (x, y) with a width of 200 and a height
    # of 50
    
    PDF_rect($p, $x, $y-=$dy, 200, 50);

    # Fill and stroke the path using the current line width, fill color,
    # and stroke color, and clear it
    
    PDF_fill_stroke($p);

    # Output some descriptive black text
    PDF_fit_textline($p, "rect() and fill_stroke()", $xt, $y,
	"fillcolor={gray 0}");


    # -------------------------------------------------------------
    # Draw a line and an arc, close the path and fill and stroke it
    # -------------------------------------------------------------
    

    # Set the current point for graphics output
    PDF_moveto($p, $x-40, $y-=$dy);

    # Draw a line from the current point to the supplied point
    PDF_lineto($p, $x, $y);

    # Draw an arc segment counterclockwise at position (x, y) with a radius
    # of 40 starting at an angle of 90 degrees and ending at 180 degrees
    
    PDF_arc($p, $x, $y, 40, 90, 180);

    # Close the path and stroke and fill it, i.e. close the current subpath
    # (add a straight line segment from the current point to the starting
    # point of the path), and stroke and fill the complete current path
    
    PDF_closepath_fill_stroke($p);

    # Output some descriptive black text
    PDF_fit_textline($p, "lineto(), arc(), and", $xt, $y+20,
	"fillcolor={gray 0}");
    PDF_fit_textline($p, "closepath_fill_stroke()", $xt, $y,
	"fillcolor={gray 0}");


    # -----------------------------------------------------------------
    # Draw a rectangle and use it as the clipping a path. Draw and fill
    # a circle and clip it according to the clipping path defined.
    # -----------------------------------------------------------------
    

    # Save the current graphics state including the current clipping
    # path which is set to the entire page by default
    
    PDF_save($p);

    # Draw a rectangle at position (x, y) with a width of 200 and a height
    # of 50
    
    PDF_rect($p, $x, $y-=$dy, 200, 50);

    # Use the current path as the clipping path for subsequent operations
    PDF_clip($p);

    # Draw a circle at position (x, y) with a radius of 100
    PDF_circle($p, $x, $y, 80);

    # Fill the path with the current fill color and clear it
    PDF_fill($p);

    # Restore the graphics state which has been saved above
    PDF_restore($p);

    # Output some descriptive black text
    PDF_fit_textline($p, "rect(), clip(),", $xt, $y+20,
	"fillcolor={gray 0}");
    PDF_fit_textline($p, "circle(), and fill()", $xt, $y,
	"fillcolor={gray 0}");

    PDF_end_page_ext($p, "");

    PDF_end_document($p, "");

};

if ($@) {
    printf("starter_graphics: PDFlib Exception occurred:\n");
    printf(" $@\n");
    exit;
}
