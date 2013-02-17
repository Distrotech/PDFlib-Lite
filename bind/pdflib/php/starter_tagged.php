<?php
/* $Id: starter_tagged.php,v 1.4.2.1 2008/01/11 11:32:35 kurt Exp $
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

$p = PDF_new();

# This means we must check return values of load_font() etc.
PDF_set_parameter($p, "errorpolicy", "return");

PDF_set_parameter($p, "SearchPath", $searchpath);

if (PDF_begin_document($p, $outfilename, "tagged=true") == 0) {
    die("Error: " . PDF_get_errmsg($p));
}

PDF_set_info($p, "Creator", "PDFlib starter sample");
PDF_set_info($p, "Title", "starter_tagged");

/* Automatically create spaces between chunks of text */
PDF_set_parameter($p, "autospace", "true");

/* open the first structure element as a child of the document
 * structure root (=0)
 */
$id = PDF_begin_item($p, "P", "Title = {Simple Paragraph}");

PDF_begin_page_ext($p, 0, 0, "width=a4.width height=a4.height");

$font = PDF_load_font($p, "Helvetica", "winansi", "");
if ($font == 0) {
    die("Error: " . PDF_get_errmsg($p));
}
PDF_setfont($p, $font, 24.0);

PDF_show_xy($p, "Hello, Tagged PDF!", 50, 700);
PDF_continue_text($p, "This PDF has a very simple");
PDF_continue_text($p, "document structure.");

PDF_end_item($p, $id);

/* The page number is created as an artifact; it will be
 * ignored when reflowing the page in Acrobat.
 */
$id_artifact = PDF_begin_item($p, "Artifact", "");
PDF_show_xy($p, "Page 1", 250, 100);
PDF_end_item($p, $id_artifact);

PDF_end_page_ext($p, "");

PDF_end_document($p, "");

PDF_delete($p);

print "$outfilename generated";
?>
