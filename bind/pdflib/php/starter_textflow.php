<?php
/* $Id: starter_textflow.php,v 1.6 2006/10/02 21:11:38 tm Exp $
 *
 * Textflow starter:
 * Create multi-column text output which may span multiple pages
 *
 * required software: PDFlib/PDFlib+PDI/PPS 7 or above
 * required data: none
 */

$outfilename = "starter_textflow.pdf";
$tf = 0;
$llx1= 50; $lly1=50; $urx1=250; $ury1=800;
$llx2=300; $lly2=50; $urx2=500; $ury2=800;

/* Repeat the dummy text to produce more contents */
$count = 50;

$optlist1 = "fontname=Helvetica fontsize=10.5 encoding=unicode " .
    "fillcolor={gray 0} alignment=justify";
$optlist2 = "fontname=Helvetica-Bold fontsize=14 encoding=unicode " .
    "fillcolor={rgb 1 0 0} charref";

/* Dummy text for filling the columns. Soft hyphens are marked with
 * the character reference "&shy;" (character references are
 * enabled by the charref option).
 */
$text= 
"Lorem ipsum dolor sit amet, consectetur adi&shy;pi&shy;sicing elit, sed do eius&shy;mod tempor incidi&shy;dunt ut labore et dolore magna ali&shy;qua. Ut enim ad minim ve&shy;niam, quis nostrud exer&shy;citation ull&shy;amco la&shy;bo&shy;ris nisi ut ali&shy;quip ex ea commodo con&shy;sequat. Duis aute irure dolor in repre&shy;henderit in voluptate velit esse cillum dolore eu fugiat nulla pari&shy;atur. Excep&shy;teur sint occae&shy;cat cupi&shy;datat non proident, sunt in culpa qui officia dese&shy;runt mollit anim id est laborum. ";

$p = PDF_new();

# This means we must check return values of load_font() etc.
PDF_set_parameter($p, "errorpolicy", "return");

/* we use "utf8" as textformat, this allows to use unicode encoding */
PDF_set_parameter($p, "textformat", "utf8");

if (PDF_begin_document($p, $outfilename, "") == 0) {
    die("Error: " . PDF_get_errmsg($p));
}

PDF_set_info($p, "Creator", "PDFlib starter sample");
PDF_set_info($p, "Title", "starter_textflow");

/* Create some amount of dummy text and feed it to a Textflow
 * object with alternating options. 
 */
for ($i=1; $i<=$count; $i++) {
    $num = $i . " ";

    $tf = PDF_add_textflow($p, $tf, $num, $optlist2);
    if ($tf == 0)
	die("Error: " . PDF_get_errmsg($p));

    $tf = PDF_add_textflow($p, $tf, $text, $optlist1);
    if ($tf == 0)
	die("Error: " . PDF_get_errmsg($p));
}

/* Loop until all of the text is placed; create new pages
 * as long as more text needs to be placed. Two columns will
 * be created on all pages.
 */
do {
    /* Add "showborder to visualize the fitbox borders */
    $optlist = "verticalalign=justify linespreadlimit=120% ";

    PDF_begin_page_ext($p, 0, 0, "width=a4.width height=a4.height");

    /* Fill the first column */
    $result = PDF_fit_textflow($p, $tf, $llx1, $lly1, $urx1, $ury1, $optlist);

    /* Fill the second column if we have more text*/
    if ($result != "_stop") {
	$result = PDF_fit_textflow($p, $tf, 
		    $llx2, $lly2, $urx2, $ury2, $optlist);
    }

    PDF_end_page_ext($p, "");

    /* "_boxfull" means we must continue because there is more text;
     * "_nextpage" is interpreted as "start new column"
     */
} while ($result == "_boxfull" || $result == "_nextpage");

/* Check for errors */
if (!$result == "_stop") {
    /* "_boxempty" happens if the box is very small and doesn't
     * hold any text at all.
     */
    if ($result == "_boxempty") {
	die("Error: Textflow box too small");
    } else {
	/* Any other return value is a user exit caused by
	 * the "return" option; this requires dedicated code to
	 * deal with.
	 */
	die("User return '" . $result . "' found in Textflow");
    }
}

PDF_delete_textflow($p, $tf);

PDF_end_document($p, "");

PDF_delete($p);

print "$outfilename generated";
?>
