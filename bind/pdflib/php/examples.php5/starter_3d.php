<?php
/* $Id: starter_3d.php,v 1.1.2.2 2009/08/07 07:30:46 rjs Exp $
 * 3D Starter:
 * Create a 3D model and load it into a U3D annotation.
 *
 * Define a 3D view and load some 3D data with the view defined. Then create
 * an annotation containing the loaded 3D data with the defined 3D view as the
 * initial view.
 *
 * Acrobat 7.07 or above is required for viewing PDF documents containing a
 * 3D model.
 *
 * Required software: PDFlib/PDFlib+PDI/PPS 7.0.1
 * Required data: U3D data file
 */

# This is where the data files are. Adjust if necessary.
$searchpath = "../data";
$outfile = "starter_3d.pdf";

# Required minimum PDFlib version
$requiredversion = 701;
$requiredvstr = "7.0.1";

try {
    $p = new PDFlib();

    $p->set_parameter("SearchPath", $searchpath);

    # This means we must check return values of load_font() etc.
    $p->set_parameter("errorpolicy", "return");

    # Check whether the required minimum PDFlib version is available
    $major = $p->get_value("major", 0);
    $minor = $p->get_value("minor", 0);
    $revision = $p->get_value("revision", 0);

    if ($major*100 + $minor*10 + $revision < $requiredversion) {
	die("Error: PDFlib " . $requiredvstr . " or above is required\n");
    }

    # Start the document
    if ($p->begin_document($outfile, "") == 0) {
	die("Error: " . $p->get_errmsg());
    }

    $p->set_info("Creator", "PDFlib Cookbook");
    $p->set_info("Title", "starter_3d");

    $font = $p->load_font("Helvetica", "winansi", "");
    if ($font == 0) {
	die("Error: " . $p->get_errmsg());
    }

    $p->begin_page_ext(0, 0, "width=a4.width height=a4.height");

    # Define a U3D view
    $optlist = "name=FirstView background={fillcolor={rgb 1 0.5 0.1}}";
    if (($u3dview = $p->create_3dview("First view", $optlist)) == 0) {
	die("Error: " . $p->get_errmsg());
    }

    # Load some U3D data with the view defined above
    $buf = "views={$u3dview}";
    if (($u3ddata = $p->load_3ddata("box.u3d", $buf)) == 0) {
	die("Error: " . $p->get_errmsg());
    }

    # Create an annotation containing the loaded U3D data with the
    # defined 3D view as the initial view
    #
    $buf = "name=annot usercoordinates contents=U3D 3ddata=$u3ddata 3dactivate={enable=open} 3Dinitialview=$u3dview";
    $p->create_annotation(116, 400, 447, 580, "3D", $buf);

    $p->end_page_ext("");

    $p->end_document("");

    $p->delete();

    print "$outfile generated";
}
catch (PDFlibException $e) {
    die("PDFlib exception occurred in invoice sample:\n" .
        "[" . $e->get_errnum() . "] " . $e->get_apiname() . ": " .
        $e->get_errmsg() . "\n");
}
catch (Exception $e) {
    die($e);
}

$p = 0;
?>
