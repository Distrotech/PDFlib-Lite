#!/usr/bin/perl
# $Id: starter_3d.pl,v 1.1.2.2 2008/12/25 13:28:41 rp Exp $
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
#

use pdflib_pl 7.0;

# This is where the data files are. Adjust if necessary.
$searchpath = "../data";
$outfile = "starter_3d.pdf";

# Required minimum PDFlib version
$requiredversion = 701;
$requiredvstr = "7.0.1";

$p = PDF_new();

eval {
    PDF_set_parameter($p, "SearchPath", $searchpath);

    # This means we must check return values of load_font() etc.
    PDF_set_parameter($p, "errorpolicy", "return");

    # Check whether the required minimum PDFlib version is available
    $major = PDF_get_value($p, "major", 0);
    $minor = PDF_get_value($p, "minor", 0);
    $revision = PDF_get_value($p, "revision", 0);

    if ($major*100 + $minor*10 + $revision < $requiredversion) {
	die("Error: PDFlib %s or above is required\n", $requiredvstr);
    }

    # Start the document
    if (PDF_begin_document($p, $outfile, "") == -1) {
	die("Error: %s\n", PDF_get_errmsg($p));
    }

    PDF_set_info($p, "Creator", "PDFlib Cookbook");
    PDF_set_info($p, "Title", "starter_3d");

    $font = PDF_load_font($p, "Helvetica", "winansi", "");
    if ($font == -1) {
	die("Error: %s\n", PDF_get_errmsg($p));
    }

    PDF_begin_page_ext($p, 0, 0, "width=a4.width height=a4.height");

    # Define a U3D view
    $optlist = "name=FirstView background={fillcolor={rgb 1 0.5 0.1}}";
    if (($u3dview = PDF_create_3dview($p, "First view", $optlist)) == -1) {
	die("Error: %s\n", PDF_get_errmsg($p));
    }

    # Load some U3D data with the view defined above
    $buf = "views={$u3dview}";
    if (($u3ddata = PDF_load_3ddata($p, "box.u3d", $buf)) == -1) {
	die("Error: %s\n", PDF_get_errmsg($p));
    }

    # Create an annotation containing the loaded U3D data with the
    # defined 3D view as the initial view
    #
    $buf = "name=annot usercoordinates contents=U3D 3ddata=$u3ddata 3dactivate={enable=open} 3Dinitialview=$u3dview";
    PDF_create_annotation($p, 116, 400, 447, 580, "3D", $buf);

    PDF_end_page_ext($p, "");

    PDF_end_document($p, "");

};

if ($@) {
    printf("starter_3d: PDFlib Exception occurred:\n");
    printf(" $@\n");
    exit;
}

PDF_delete($p);
