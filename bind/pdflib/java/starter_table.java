/* $Id: starter_table.java,v 1.9 2006/10/02 21:11:38 tm Exp $
 *
 * Table starter:
 * Create table which may span multiple pages
 *
 * required software: PDFlib/PDFlib+PDI/PPS 7
 * required data: image file (dummy text created within the program)
 */

import java.io.*;
import com.pdflib.pdflib;
import com.pdflib.PDFlibException;

public class starter_table
{
    public static void main (String argv[]) 
    {
	/* This is where the data files are. Adjust as necessary. */
	String searchpath = "../data";

	String imagefile = "nesrin.jpg";

	int i, row, col, font, image, tf=-1, tbl=-1;
	final int rowmax=50, colmax=5;

	pdflib p = null;
	final double llx= 50, lly=50, urx=550, ury=800;
	String headertext = "Table header (centered across all columns)";
	String result;
	String optlist;

	/* Dummy text for filling a cell with multi-line Textflow */
	final String tf_text = 
"Lorem ipsum dolor sit amet, consectetur adi&shy;pi&shy;sicing elit, sed do eius&shy;mod tempor incidi&shy;dunt ut labore et dolore magna ali&shy;qua. Ut enim ad minim ve&shy;niam, quis nostrud exer&shy;citation ull&shy;amco la&shy;bo&shy;ris nisi ut ali&shy;quip ex ea commodo con&shy;sequat. Duis aute irure dolor in repre&shy;henderit in voluptate velit esse cillum dolore eu fugiat nulla pari&shy;atur. Excep&shy;teur sint occae&shy;cat cupi&shy;datat non proident, sunt in culpa qui officia dese&shy;runt mollit anim id est laborum. ";

	try {
	    p = new pdflib();

	    p.set_parameter("SearchPath", searchpath);

	    /* This means we must check return values of load_font() etc. */
	    p.set_parameter("errorpolicy", "return");

	    if (p.begin_document("starter_table.pdf", "") == -1)
		throw new Exception("Error: " + p.get_errmsg());

	    p.set_info("Creator", "PDFlib starter sample");
	    p.set_info("Title", "starter_table");

	    /* -------------------- Add table cells -------------------- */

	    /* ---------- Row 1: table header (spans all columns) */
	    row = 1; col = 1;
	    font = p.load_font("Times-Bold", "unicode", "");

	    if (font == -1)
		throw new Exception("Error: " + p.get_errmsg());

	    optlist = "fittextline={position=center font=" + font +
		    " fontsize=14} " + "colspan=" + colmax;

	    tbl = p.add_table_cell(tbl, col, row, headertext, optlist);

	    if (tbl == -1)
		throw new Exception("Error adding cell: " + p.get_errmsg());

	    /* ---------- Row 2: various kinds of content */
	    /* ----- Simple text cell */
	    row++; col=1;

	    optlist =
	    "fittextline={font=" + font + " fontsize=10 orientate=west}";

	    tbl = p.add_table_cell(tbl, col, row, "vertical line", optlist);

	    if (tbl == -1)
		throw new Exception("Error adding cell: " + p.get_errmsg());

	    /* ----- Colorized background */
	    col++;

	    optlist =
	    "fittextline={font=" + font + " fontsize=10} " +
	    "matchbox={fillcolor={rgb 0.9 0.5 0}}";

	    tbl = p.add_table_cell(tbl, col, row, "some color", optlist);

	    if (tbl == -1)
		throw new Exception("Error adding cell: " + p.get_errmsg());

	    /* ----- Multi-line text with Textflow */
	    col++;
	    font = p.load_font("Times-Roman", "unicode", "");

	    if (font == -1)
		throw new Exception("Error: " + p.get_errmsg());

	    optlist =
	    	"charref fontname=Times-Roman encoding=unicode fontsize=8 ";

	    tf = p.add_textflow(tf, tf_text, optlist);
	    if (tf == -1)
		throw new Exception("Error: " + p.get_errmsg());

	    optlist = "margin=2 textflow=" + tf;

	    tbl = p.add_table_cell(tbl, col, row, "", optlist);

	    if (tbl == -1)
		throw new Exception("Error adding cell: " + p.get_errmsg());

	    /* ----- Rotated image */
	    col++;

	    image = p.load_image("auto", imagefile, "");
	    if (image == -1)
		throw new Exception ("Couldn't load image: " + p.get_errmsg());

	    optlist = "image=" + image + " fitimage={orientate=west}";

	    tbl = p.add_table_cell(tbl, col, row, "", optlist);

	    if (tbl == -1)
		throw new Exception("Error adding cell: " + p.get_errmsg());

	    /* ----- Diagonal stamp */
	    col++;

	    optlist = "fittextline={font=" + font + " fontsize=10 stamp=ll2ur}";

	    tbl = p.add_table_cell(tbl, col, row, "entry void", optlist);

	    if (tbl == -1)
		throw new Exception("Error adding cell: " + p.get_errmsg());

	    /* ---------- Fill row 3 and above with their numbers */
	    for (row++; row <= rowmax; row++)
	    {
		for (col = 1; col <= colmax; col++)
		{
		    String num;

		    num = "Col " + col + "/Row " + row;
		    optlist = 
		    "colwidth=20% fittextline={font=" + font + " fontsize=10}";
		    tbl = p.add_table_cell(tbl, col, row, num, optlist);

		    if (tbl == -1)
			throw new Exception("Error adding cell: " + 
			    p.get_errmsg());
		}
	    }

	    /* ---------- Place the table on one or more pages ---------- */

	    /*
	     * Loop until all of the table is placed; create new pages
	     * as long as more table instances need to be placed.
	     */
	    do {
		p.begin_page_ext(0, 0, "width=a4.width height=a4.height");

		/* Shade every other row; draw lines for all table cells.
		 * Add "showcells showborder" to visualize cell borders 
		 */
		optlist =
		"header=1 fill={{area=rowodd fillcolor={gray 0.9}}} " +
		"stroke={{line=other}} ";

		/* Place the table instance */
		result = p.fit_table(tbl, llx, lly, urx, ury, optlist);

		if (result.equals("_error"))
		    throw new Exception ("Couldn't place table : " + 
					p.get_errmsg());

		p.end_page_ext("");

	    } while (result.equals("_boxfull"));

	    /* Check the result; "_stop" means all is ok. */
	    if (!result.equals("_stop")) 
	    {
		if (result.equals( "_error")) 
		{
		    throw new Exception ("Error when placing table: " + 
				    p.get_errmsg());
		}
		else 
		{
		    /* Any other return value is a user exit caused by
		     * the "return" option; this requires dedicated code to
		     * deal with.
		     */
		    throw new Exception ("User return found in Textflow");
		}
	    }

	    /* This will also delete Textflow handles used in the table */
	    p.delete_table(tbl, "");

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
