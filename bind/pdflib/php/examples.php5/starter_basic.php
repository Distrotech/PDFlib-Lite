<?php
/* $Id: starter_basic.php,v 1.1.2.2 2009/08/07 07:30:46 rjs Exp $
 *
 * Basic starter:
 * Create some simple text, vector graphics and image output
 *
 * required software: PDFlib Lite/PDFlib/PDFlib+PDI/PPS 7
 * required data: none
 */

/* This is where the data files are. Adjust as necessary. */
$searchpath = "../data/";
$imagefile = "nesrin.jpg";
$outfilename = "starter_basic.pdf";

try {
    $p = new PDFlib();


    # This means we must check return values of load_font() etc.
    $p->set_parameter("errorpolicy", "return");

    $p->set_parameter("SearchPath", $searchpath);

    /* we use "utf8" as textformat, this allows to use unicode encoding */
    $p->set_parameter("textformat", "utf8");

    if ($p->begin_document($outfilename, "") == 0) {
	die("Error: " . $p->get_errmsg());
    }

    $p->set_info("Creator", "PDFlib starter sample");
    $p->set_info("Title", "starter_basic");

    /* We load the $image before the first page, and use it
     * on all pages
     */
    $image = $p->load_image("auto", $imagefile, "");

    if ($image == 0) {
	die("Error: " . $p->get_errmsg());
    }

    /* Page 1 */
    $p->begin_page_ext(595, 842, "");

    /* For PDFlib Lite: change "unicode" to "winansi" */
    $font = $p->load_font("Helvetica-Bold", "unicode", "");
    if ($font == 0) {
	die("Error: " . $p->get_errmsg());
    }

    $p->setfont($font, 24);

    $p->set_text_pos(50, 700);
    $p->show("Hello world!");

    $p->fit_image($image, 0.0, 0.0, "scale=0.25");

    $p->end_page_ext("");

    /* Page 2 */
    $p->begin_page_ext(595, 842, "");

    /* red rectangle */
    $p->setcolor("fill", "rgb", 1.0, 0.0, 0.0, 0.0);
    $p->rect(200, 200, 250, 150);
    $p->fill();

    /* blue circle */
    $p->setcolor("fill", "rgb", 0.0, 0.0, 1.0, 0.0);
    $p->arc(400, 600, 100, 0, 360);
    $p->fill();

    /* thick gray line */
    $p->setcolor("stroke", "gray", 0.5, 0.0, 0.0, 0.0);
    $p->setlinewidth(10);
    $p->moveto(100, 500);
    $p->lineto(300, 700);
    $p->stroke();

    /* Using the same $image handle means the data will be copied
     * to the PDF only once, which saves space.
     */
    $p->fit_image($image, 150.0, 25.0, "scale=0.25");
    $p->end_page_ext("");

    /* Page 3 */
    $p->begin_page_ext(595, 842, "");

    /* Fit the image to a box of predefined size (without distortion) */
    $optlist = "boxsize={400 400} position={center} fitmethod=meet";
    $p->fit_image($image, 100, 200, $optlist);

    $p->end_page_ext("");

    $p->close_image($image);
    $p->end_document("");

    print "$outfilename generated";

}
catch (PDFlibException $e) {
    die("PDFlib exception occurred in starter_basic sample:\n" .
	"[" . $e->get_errnum() . "] " . $e->get_apiname() . ": " .
	$e->get_errmsg() . "\n");
}
catch (Exception $e) {
    die($e);
}

$p = 0;
?>
