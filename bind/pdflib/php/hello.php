<?php
/* $Id: hello.php,v 1.15 2006/10/01 20:33:35 rjs Exp $
 *
 * PDFlib client: hello example in PHP
 */

$p = PDF_new();

# This means we must check return values of load_font() etc.
PDF_set_parameter($p, "errorpolicy", "return");

/* This line is required to avoid problems on Japanese systems */
PDF_set_parameter($p, "hypertextencoding", "winansi");

/*  open new PDF file; insert a file name to create the PDF on disk */
if (PDF_begin_document($p, "", "") == 0) {
    die("Error: " . PDF_get_errmsg($p));
}

PDF_set_info($p, "Creator", "hello.php");
PDF_set_info($p, "Author", "Rainer Schaaf");
PDF_set_info($p, "Title", "Hello world (PHP)!");

PDF_begin_page_ext($p, 595, 842, "");

$font = PDF_load_font($p, "Helvetica-Bold", "winansi", "");
if ($font == 0) {
    die("Error: " . PDF_get_errmsg($p));
}

PDF_setfont($p, $font, 24.0);
PDF_set_text_pos($p, 50, 700);
PDF_show($p, "Hello world!");
PDF_continue_text($p, "(says PHP)");
PDF_end_page_ext($p, "");

PDF_end_document($p, "");

$buf = PDF_get_buffer($p);
$len = strlen($buf);

header("Content-type: application/pdf");
header("Content-Length: $len");
header("Content-Disposition: inline; filename=hello.pdf");
print $buf;

PDF_delete($p);
?>
