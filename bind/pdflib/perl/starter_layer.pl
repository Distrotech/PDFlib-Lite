#!/usr/bin/perl
# $Id: starter_layer.pl,v 1.1.2.5 2008/12/25 13:28:41 rp Exp $
# Starter layer:
# Define several layers, output images and text to them and define
# particular layers to be visible when opening the document
#
# Define two layers for RGB or Grayscale images and two layers for English or
# German image captions. Output images and text on the various layers and
# open the document with the RGB images and English captions visible.
#
# Required software: PDFlib/PDFlib+PDI/PPS 7
# Required data: grayscale and RGB images
#

use pdflib_pl 7.0;
use strict;

# This is where the data files are. Adjust as necessary. 
my $searchpath = "../data";
my $outfile = "starter_layer.pdf";
my $title = "Starter Layer";

# create a new PDFlib object
my $p = PDF_new();

my $rgb = "nesrin.jpg";
my $gray = "nesrin_gray.jpg";

my $buf;
my $font;
my $imageRGB;
my $imageGray;
my $layerRGB;
my $layerGray;
my $layerEN;
my $layerDE;


eval {
    PDF_set_parameter($p, "SearchPath", $searchpath);

    # This means we must check return values of load_font() etc.
    PDF_set_parameter($p, "errorpolicy", "return");


    # Open the document with the "Layers" navigation tab visible
    if (PDF_begin_document($p, $outfile, "openmode=layers") == -1) {
	printf("Error: %s\n", PDF_get_errmsg($p));
	PDF_delete($p);
	exit(2);
    }

    PDF_set_info($p, "Creator", "PDFlib Cookbook");
    $buf = $title . ' $Revision: 1.1.2.5 $';
    PDF_set_info($p, "Title", $buf);

    # Load the font
    $font = PDF_load_font($p, "Helvetica", "winansi", "");

    if ($font == -1) {
	printf("Error: %s\n", PDF_get_errmsg($p));
	PDF_delete($p);
	exit(2);
    }

    # Load the Grayscale image
    $imageGray = PDF_load_image($p, "auto", $gray, "");
    if ($imageGray == -1) {
	printf("Error: %s\n", PDF_get_errmsg($p));
	PDF_delete($p);
	exit(2);
    }

    # Load the RGB image
    $imageRGB = PDF_load_image($p, "auto", $rgb, "");
    if ($imageRGB == -1) {
	printf("Error: %s\n", PDF_get_errmsg($p));
	PDF_delete($p);
	exit(2);
    }

    # Define all layers which will be used, and their relationships.
    # This should be done before the first page if the layers are
    # used on more than one page.

    # Define the layer "RGB"
    $layerRGB = PDF_define_layer($p, "RGB", "");

    # Define the layer "Grayscale" which is hidden when opening the
    # document or printing it.
    $layerGray = PDF_define_layer($p, "Grayscale",
		"initialviewstate=false initialprintstate=false");

    # At most one of the "Grayscale" and "RGB" layers should be visible
    $buf = "group={" . $layerGray . " " . $layerRGB . "}";
    PDF_set_layer_dependency($p, "Radiobtn", $buf);

    # Define the layer "English"
    $layerEN = PDF_define_layer($p, "English", "");

    # Define the layer "German" which is hidden when opening the document
    # or printing it.
    $layerDE = PDF_define_layer($p, "German",
		"initialviewstate=false initialprintstate=false");

    # At most one of the "English" and "German" layers should be visible
    $buf = "group={" . $layerEN . " " . $layerDE . "}";
    PDF_set_layer_dependency($p, "Radiobtn", $buf);

    # Start page
    PDF_begin_page_ext($p, 0, 0, "width=a4.width height=a4.height");

    # Place the RGB image on the layer "RGB"
    PDF_begin_layer($p, $layerRGB);
    PDF_fit_image($p, $imageRGB, 100, 400,
		"boxsize={400 300} fitmethod=meet");

    # Place the Grayscale image on the layer "Grayscale"
    PDF_begin_layer($p, $layerGray);
    PDF_fit_image($p, $imageGray, 100, 400,
		"boxsize={400 300} fitmethod=meet");

    # Place an English image caption on the layer "English"
    PDF_begin_layer($p, $layerEN);
    $buf =  "font=" . $font . "  fontsize=20";
    PDF_fit_textline($p, "This is the Nesrin image.", 100, 370, $buf);

    # Place a German image caption on the layer "German"
    PDF_begin_layer($p, $layerDE);
    $buf = "font=" . $font . " fontsize=20";
    PDF_fit_textline($p, "Das ist das Nesrin-Bild.", 100, 370, $buf);

    PDF_end_layer($p);

    PDF_end_page_ext($p, "");

    PDF_end_document($p, "");

};

if ($@) {
    printf("starter_layer: PDFlib Exception occurred:\n");
    printf(" $@\n");
    exit;
}
