<?php
/* $Id: starter_tagged.php,v 1.1.2.2 2009/08/07 07:30:46 rjs Exp $
 *
 * Tagged PDF starter:
 * Create document with structure information for reflow and accessibility
 *
 * required software: PDFlib/PDFlib+PDI/PPS 7
 * required data: none (dummy text created in program)
 */

/* This is where the data files are. Adjust as necessary. */
$searchpath = "../data";
$outfilename = "starter_tagged.pdf";

try {
    $p = new PDFlib();

    # This means we must check return values of load_font() etc.
    $p->set_parameter("errorpolicy", "return");

    $p->set_parameter("SearchPath", $searchpath);

    /* "lang" contains the predominant document language */
    if ($p->begin_document($outfilename, "tagged=true lang=en") == 0) {
	die("Error: " . $p->get_errmsg());
    }

    $p->set_info("Creator", "PDFlib starter sample");
    $p->set_info("Title", "starter_tagged");

    /* Automatically create spaces between chunks of text */
    $p->set_parameter("autospace", "true");

    /* open the first structure element as a child of the document
     * structure root (=0)
     */
    $id = $p->begin_item("P", "Title = {Simple Paragraph}");

    $p->begin_page_ext(0, 0, "width=a4.width height=a4.height");

    $font = $p->load_font("Helvetica", "winansi", "");
    if ($font == 0) {
	die("Error: " . $p->get_errmsg());
    }
    $p->setfont($font, 24.0);

    $p->show_xy("Hello, Tagged PDF!", 50, 700);
    $p->continue_text("This PDF has a very simple");
    $p->continue_text("document structure.");

    $p->end_item($id);

    /* The page number is created as an artifact; it will be
     * ignored when reflowing the page in Acrobat.
     */
    $id_artifact = $p->begin_item("Artifact", "");
    $p->show_xy("Page 1", 250, 100);
    $p->end_item($id_artifact);

    $p->end_page_ext("");

    $p->end_document("");

    print "$outfilename generated";

}
catch (PDFlibException $e) {
    die("PDFlib exception occurred in starter_tagged sample:\n" .
	"[" . $e->get_errnum() . "] " . $e->get_apiname() . ": " .
	$e->get_errmsg() . "\n");
}
catch (Exception $e) {
    die($e);
}

$p = 0;
?>
