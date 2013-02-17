/* $Id: starter_textflow.java,v 1.4 2006/10/02 21:11:38 tm Exp $
 *
 * Textflow starter:
 * Create multi-column text output which may span multiple pages
 *
 * required software: PDFlib/PDFlib+PDI/PPS 7 or above
 * required data: none
 */

import java.io.*;
import com.pdflib.pdflib;
import com.pdflib.PDFlibException;

public class starter_textflow
{
    public static void main (String argv[]) 
    {
	pdflib p = null;
	int i, tf = -1;
	String result;
	final double llx1= 50, lly1=50, urx1=250, ury1=800;
	final double llx2=300, lly2=50, urx2=500, ury2=800;

	/* Repeat the dummy text to produce more contents */
	final int count = 50;

	final String optlist1 =
	    "fontname=Helvetica fontsize=10.5 encoding=unicode " +
	    "fillcolor={gray 0} alignment=justify";

	final String optlist2 =
	    "fontname=Helvetica-Bold fontsize=14 encoding=unicode " +
	    "fillcolor={rgb 1 0 0} charref";

	/* Dummy text for filling the columns. Soft hyphens are marked with
	 * the character reference "&shy;" (character references are
	 * enabled by the charref option).
	 */
	final String text= 
"Lorem ipsum dolor sit amet, consectetur adi&shy;pi&shy;sicing elit, sed do eius&shy;mod tempor incidi&shy;dunt ut labore et dolore magna ali&shy;qua. Ut enim ad minim ve&shy;niam, quis nostrud exer&shy;citation ull&shy;amco la&shy;bo&shy;ris nisi ut ali&shy;quip ex ea commodo con&shy;sequat. Duis aute irure dolor in repre&shy;henderit in voluptate velit esse cillum dolore eu fugiat nulla pari&shy;atur. Excep&shy;teur sint occae&shy;cat cupi&shy;datat non proident, sunt in culpa qui officia dese&shy;runt mollit anim id est laborum. ";

	try {
	    p = new pdflib();

	    /* This means we must check return values of load_font() etc. */
	    p.set_parameter("errorpolicy", "return");

	    if (p.begin_document("starter_textflow.pdf", "") == -1)
		throw new Exception("Error: " + p.get_errmsg());

	    p.set_info("Creator", "PDFlib starter sample");
	    p.set_info("Title", "starter_textflow");

	    /* Create some amount of dummy text and feed it to a Textflow
	     * object with alternating options. 
	     */
	    for (i=1; i<=count; i++)
	    {
		String num = i + " ";

		tf = p.add_textflow(tf, num, optlist2);
		if (tf == -1)
		    throw new Exception("Error: " + p.get_errmsg());

		tf = p.add_textflow(tf, text, optlist1);
		if (tf == -1)
		    throw new Exception("Error: " + p.get_errmsg());
	    }

	    /* Loop until all of the text is placed; create new pages
	     * as long as more text needs to be placed. Two columns will
	     * be created on all pages.
	     */
	    do
	    {
		/* Add "showborder to visualize the fitbox borders */
		String optlist =
		    "verticalalign=justify linespreadlimit=120% ";

		p.begin_page_ext(0, 0, "width=a4.width height=a4.height");

		/* Fill the first column */
		result = p.fit_textflow(tf, llx1, lly1, urx1, ury1, optlist);

		/* Fill the second column if we have more text*/
		if (!result.equals("_stop"))
		    result = p.fit_textflow(tf, llx2, lly2, urx2, ury2,optlist);

		p.end_page_ext("");

		/* "_boxfull" means we must continue because there is more text;
		 * "_nextpage" is interpreted as "start new column"
		 */
	    } while (result.equals("_boxfull") || result.equals("_nextpage"));

	    /* Check for errors */
	    if (!result.equals("_stop"))
	    {
		/* "_boxempty" happens if the box is very small and doesn't
		 * hold any text at all.
		 */
		if (result.equals( "_boxempty"))
		    throw new Exception ("Error: Textflow box too small");
		else
		{
		    /* Any other return value is a user exit caused by
		     * the "return" option; this requires dedicated code to
		     * deal with.
		     */
		    throw new Exception ("User return '" + result + 
		    		"' found in Textflow");
		}
	    }

	    p.delete_textflow(tf);

	    p.end_document("");

        } catch (PDFlibException e) {
	    System.err.print("PDFlib exception occurred:\n");
	    System.err.print("[" + e.get_errnum() + "] " + e.get_apiname() +
			    ": " + e.get_errmsg() + "\n");
        } catch (Exception e) {
            System.err.println(e.getMessage());
        } finally {
            if (p != null) {
		p.delete();
            }
        }
    }
}
