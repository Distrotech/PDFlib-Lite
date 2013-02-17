<?php
/* $Id: starter_pcos.php,v 1.6.2.1 2007/02/16 12:15:51 stm Exp $
 *
 * pCOS starter:
 * Dump information from an existing PDF document
 *
 * required software: PDFlib+PDI/PPS 7
 * required data: PDF input file
 */

/* This is where the data files are. Adjust as necessary. */
$searchpath = "../data";
$pdfinput = "TET-datasheet.pdf";
$docoptlist = "requiredmode=minimum";

$p = PDF_new();

# This means we must check return values of load_font() etc.
PDF_set_parameter($p, "errorpolicy", "return");

PDF_set_parameter($p, "SearchPath", $searchpath);

/* We do not create any output document, so no call to
 * begin_document() is required.
 */

/* Open the input document */
$doc = PDF_open_pdi_document($p, $pdfinput, $docoptlist);
if ($doc == 0) {
    die("Error: " . PDF_get_errmsg($p));
}

/* --------- general information (always available) */

$pcosmode = PDF_pcos_get_number($p, $doc, "pcosmode");

printf("   File name: %s\n",
    PDF_pcos_get_string($p, $doc,"filename"));

printf(" PDF version: %s\n",
    PDF_pcos_get_number($p, $doc, "pdfversion")/10);

printf("  Encryption: %s\n",
    PDF_pcos_get_string($p, $doc, "encrypt/description"));

printf("   Master pw: %s\n",
    ((PDF_pcos_get_number($p, $doc, "encrypt/master") != 0) ? "yes":"no"));

printf("     User pw: %s\n",
    ((PDF_pcos_get_number($p, $doc, "encrypt/user") != 0) ? "yes" : "no"));

printf("Text copying: %s\n",
    ((PDF_pcos_get_number($p, $doc, "encrypt/nocopy") != 0) ? "no":"yes"));

printf("  Linearized: %s\n",
    ((PDF_pcos_get_number($p, $doc, "linearized") != 0) ? "yes" : "no"));

printf("      Tagged: %s\n\n",
    ((PDF_pcos_get_number($p, $doc, "tagged") != 0) ? "yes" : "no"));

if ($pcosmode == 0) {
    printf("Minimum mode: no more information available\n\n");
    PDF_delete($p);
    exit(0);
}

/* --------- more details (requires at least user password) */
printf("No. of pages: %s\n",
    PDF_pcos_get_number($p, $doc, "length:pages"));

printf(" Page 1 size: width=%.3f, height=%.3f\n",
     PDF_pcos_get_number($p, $doc, "pages[0]/width"),
     PDF_pcos_get_number($p, $doc, "pages[0]/height"));

$count = PDF_pcos_get_number($p, $doc, "length:fonts");
printf("No. of fonts: %s\n",  $count);

for ($i=0; $i < $count; $i++) {
    $fonts = "fonts[" . $i . "]/embedded";
    if (PDF_pcos_get_number($p, $doc, $fonts) != 0)
	print("embedded ");
    else
	print("unembedded ");

    $fonts = "fonts[" . $i . "]/type";
    print(PDF_pcos_get_string($p, $doc, $fonts) . " font ");
    $fonts = "fonts[" . $i . "]/name";
    printf("%s\n", PDF_pcos_get_string($p, $doc, $fonts));
}

printf("\n");

if ($pcosmode == 1) {
    print(
	"Restricted mode: no more information available");
    PDF_delete($p);
    exit(0);
}

/* ----- document $info keys and XMP metadata (requires master pw) */

$count = PDF_pcos_get_number($p, $doc, "length:/Info");

for ($i=0; $i < $count; $i++) {
    $info = "type:/Info[" . $i . "]";
    $objtype = PDF_pcos_get_string($p, $doc, $info);

    $info = "/Info[" . $i . "].key";
    $key = PDF_pcos_get_string($p, $doc, $info);
    $len = 12 - strlen($key);
    while ($len-- > 0) print(" ");

    print($key . ": ");

    /* $info entries can be stored as string or name objects */
    if ($objtype == "name" || $objtype == "string") {
	$info = "/Info[" . $i . "]";
	printf("'" . PDF_pcos_get_string($p, $doc, $info) .  "'\n");
    } else {
	$info = "type:/Info[" . $i . "]";
	printf("(" . PDF_pcos_get_string($p, $doc, $info) .  " object)\n");
    }
}

print("\n" . "XMP meta data: ");


$objtype = PDF_pcos_get_string($p, $doc, "type:/Root/Metadata");
if ($objtype == "stream") {
    $contents = PDF_pcos_get_stream($p, $doc, "", "/Root/Metadata");
    print(strlen($contents) . " bytes \n");
    printf("");
} else {
    printf("not present");
}

PDF_close_pdi_document($p, $doc);

PDF_delete($p);
?>
