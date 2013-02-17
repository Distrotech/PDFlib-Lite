<?php
/* $Id: starter_pcos.php,v 1.1.2.2 2009/08/07 07:30:46 rjs Exp $
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

try {
    $p = new PDFlib();


    # This means we must check return values of load_font() etc.
    $p->set_parameter("errorpolicy", "return");

    $p->set_parameter("SearchPath", $searchpath);

    /* We do not create any output document, so no call to
     * begin_document() is required.
     */

    /* Open the input document */
    $doc = $p->open_pdi_document($pdfinput, $docoptlist);
    if ($doc == 0) {
	die("Error: " . $p->get_errmsg());
    }

    /* --------- general information (always available) */

    $pcosmode = $p->pcos_get_number($doc, "pcosmode");

    printf("<PRE>");
    printf("   File name: %s\n",
	$p->pcos_get_string($doc,"filename"));

    printf(" PDF version: %s\n",
	$p->pcos_get_number($doc, "pdfversion")/10);

    printf("  Encryption: %s\n",
	$p->pcos_get_string($doc, "encrypt/description"));

    printf("   Master pw: %s\n",
	(($p->pcos_get_number($doc, "encrypt/master") != 0) ? "yes":"no"));

    printf("     User pw: %s\n",
	(($p->pcos_get_number($doc, "encrypt/user") != 0) ? "yes" : "no"));

    printf("Text copying: %s\n",
	(($p->pcos_get_number($doc, "encrypt/nocopy") != 0) ? "no":"yes"));

    printf("  Linearized: %s\n",
	(($p->pcos_get_number($doc, "linearized") != 0) ? "yes" : "no"));

    printf("      Tagged: %s\n\n",
	(($p->pcos_get_number($doc, "tagged") != 0) ? "yes" : "no"));

    if ($pcosmode == 0) {
	printf("Minimum mode: no more information available\n\n");
	$p->delete();
	exit(0);
    }

    /* --------- more details (requires at least user password) */
    printf("No. of pages: %s\n",
	$p->pcos_get_number($doc, "length:pages"));

    printf(" Page 1 size: width=%.3f, height=%.3f\n",
	 $p->pcos_get_number($doc, "pages[0]/width"),
	 $p->pcos_get_number($doc, "pages[0]/height"));

    $count = $p->pcos_get_number($doc, "length:fonts");
    printf("No. of fonts: %s\n",  $count);

    for ($i=0; $i < $count; $i++) {
	$fonts = "fonts[" . $i . "]/embedded";
	if ($p->pcos_get_number($doc, $fonts) != 0)
	    print("embedded ");
	else
	    print("unembedded ");

	$fonts = "fonts[" . $i . "]/type";
	print($p->pcos_get_string($doc, $fonts) . " font ");
	$fonts = "fonts[" . $i . "]/name";
	printf("%s\n", $p->pcos_get_string($doc, $fonts));
    }

    printf("\n");

    if ($pcosmode == 1) {
	print(
	    "Restricted mode: no more information available");
	$p->delete();
	exit(0);
    }

    /* ----- document $info keys and XMP metadata (requires master pw) */

    $count = $p->pcos_get_number($doc, "length:/Info");

    for ($i=0; $i < $count; $i++) {
	$info = "type:/Info[" . $i . "]";
	$objtype = $p->pcos_get_string($doc, $info);

	$info = "/Info[" . $i . "].key";
	$key = $p->pcos_get_string($doc, $info);
	$len = 12 - strlen($key);
	while ($len-- > 0) print(" ");

	print($key . ": ");

	/* $info entries can be stored as string or name objects */
	if ($objtype == "name" || $objtype == "string") {
	    $info = "/Info[" . $i . "]";
	    printf("'" . $p->pcos_get_string($doc, $info) .  "'\n");
	} else {
	    $info = "type:/Info[" . $i . "]";
	    printf("(" . $p->pcos_get_string($doc, $info) .  " object)\n");
	}
    }

    print("\n" . "XMP meta data: ");


    $objtype = $p->pcos_get_string($doc, "type:/Root/Metadata");
    if ($objtype == "stream") {
	$contents = $p->pcos_get_stream($doc, "", "/Root/Metadata");
	print(strlen($contents) . " bytes \n");
	printf("");
    } else {
	printf("not present");
    }

    $p->close_pdi_document($doc);

}
catch (PDFlibException $e) {
    die("PDFlib exception occurred in starter_pcos sample:\n" .
	"[" . $e->get_errnum() . "] " . $e->get_apiname() . ": " .
	$e->get_errmsg() . "\n");
}
catch (Exception $e) {
    die($e);
}

$p = 0;
?>
