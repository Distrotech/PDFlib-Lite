#!/usr/bin/perl
# $Id: hello.pl,v 1.27 2006/10/01 19:55:11 rjs Exp $
#
# PDFlib client: hello example in Perl
#

use pdflib_pl 7.0;

$p = PDF_new();

eval {
    # This means we must check return values of load_font() etc.
    PDF_set_parameter($p, "errorpolicy", "return");

    # This line is required to avoid problems on Japanese systems
    PDF_set_parameter($p, "hypertextencoding", "winansi");

    if (PDF_begin_document($p, "hello.pdf", "") == -1) {
	die("Error: %s\n", PDF_get_errmsg($p));
    }

    PDF_set_info($p, "Creator", "hello.pl");
    PDF_set_info($p, "Author", "Thomas Merz");
    PDF_set_info($p, "Title", "Hello world (Perl)!");

    PDF_begin_page_ext($p, 595, 842, "");

    $font = PDF_load_font($p, "Helvetica-Bold", "winansi", "");
    if ($font == -1) {
	die("Error: %s\n", PDF_get_errmsg($p));
    }

    PDF_setfont($p, $font, 24.0);
    PDF_set_text_pos($p, 50, 700);
    PDF_show($p, "Hello world!");
    PDF_continue_text($p, "(says Perl)");
    PDF_end_page_ext($p, "");

    PDF_end_document($p, "");
};

if ($@) {
    printf("hello: PDFlib Exception occurred:\n");
    printf(" $@\n");
    exit;
}

PDF_delete($p);
