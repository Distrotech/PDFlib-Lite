<?php
# $Id: starter_layer.php,v 1.1.2.2 2008/02/11 20:10:28 rjs Exp $
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

# This is where the data files are. Adjust as necessary. 
$searchpath = "../data";
$title = "Starter Layer";

$rgb = "nesrin.jpg";
$gray = "nesrin_gray.jpg";

try {
    # create a new PDFlib object
    $p = new PDFlib();

    $p->set_parameter("SearchPath", $searchpath);

    # This means we must check return values of load_font() etc.
    $p->set_parameter("errorpolicy", "return");


    # Open the document with the "Layers" navigation tab visible
    if ($p->begin_document("", "openmode=layers") == 0) {
	die("Error: " .  $p->get_errmsg());
    }

    $p->set_info("Creator", "PDFlib Cookbook");
    $buf = $title . ' $Revision: 1.1.2.2 $';
    $p->set_info("Title", $buf);

    # Load the font
    $font = $p->load_font("Helvetica", "winansi", "");

    if ($font == 0) {
	die("Error: " .  $p->get_errmsg());
    }

    # Load the Grayscale image
    $imageGray = $p->load_image("auto", $gray, "");
    if ($imageGray == 0) {
	die("Error: " .  $p->get_errmsg());
    }

    # Load the RGB image
    $imageRGB = $p->load_image("auto", $rgb, "");
    if ($imageRGB == 0) {
	die("Error: " .  $p->get_errmsg());
    }

    # Define all layers which will be used, and their relationships.
    # This should be done before the first page if the layers are
    # used on more than one page.

    # Define the layer "RGB"
    $layerRGB = $p->define_layer("RGB", "");

    # Define the layer "Grayscale" which is hidden when opening the
    # document or printing it.
    $layerGray = $p->define_layer("Grayscale",
		"initialviewstate=false initialprintstate=false");

    # At most one of the "Grayscale" and "RGB" layers should be visible
    $buf = "group={" . $layerGray . " " . $layerRGB . "}";
    $p->set_layer_dependency("Radiobtn", $buf);

    # Define the layer "English"
    $layerEN = $p->define_layer("English", "");

    # Define the layer "German" which is hidden when opening the document
    # or printing it.
    $layerDE = $p->define_layer("German",
		"initialviewstate=false initialprintstate=false");

    # At most one of the "English" and "German" layers should be visible
    $buf = "group={" . $layerEN . " " . $layerDE . "}";
    $p->set_layer_dependency("Radiobtn", $buf);

    # Start page
    $p->begin_page_ext(0, 0, "width=a4.width height=a4.height");

    # Place the RGB image on the layer "RGB"
    $p->begin_layer($layerRGB);
    $p->fit_image($imageRGB, 100, 400,
		"boxsize={400 300} fitmethod=meet");

    # Place the Grayscale image on the layer "Grayscale"
    $p->begin_layer($layerGray);
    $p->fit_image($imageGray, 100, 400,
		"boxsize={400 300} fitmethod=meet");

    # Place an English image caption on the layer "English"
    $p->begin_layer($layerEN);
    $buf =  "font=" . $font . "  fontsize=20";
    $p->fit_textline("This is the Nesrin image.", 100, 370, $buf);

    # Place a German image caption on the layer "German"
    $p->begin_layer($layerDE);
    $buf = "font=" . $font . " fontsize=20";
    $p->fit_textline("Das ist das Nesrin-Bild.", 100, 370, $buf);

    $p->end_layer();

    $p->end_page_ext("");

    $p->end_document("");

    $buf = $p->get_buffer();
    $len = strlen($buf);

    header("Content-type: application/pdf");
    header("Content-Length: $len");
    header("Content-Disposition: inline; filename=hello.pdf");
    print $buf;
}
catch (PDFlibException $e) {
    die("PDFlib exception occurred in hello sample:\n" .
        "[" . $e->get_errnum() . "] " . $e->get_apiname() . ": " .
        $e->get_errmsg() . "\n");
}
catch (Exception $e) {
    die($e);
}

$p = 0;

?>
