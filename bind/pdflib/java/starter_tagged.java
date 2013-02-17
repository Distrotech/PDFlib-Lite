/* $Id: starter_tagged.java,v 1.2.2.1 2008/01/11 11:32:35 kurt Exp $
 *
 * Tagged PDF starter:
 * Create document with structure information for reflow and accessibility
 *
 * required software: PDFlib/PDFlib+PDI/PPS 7
 * required data: none (dummy text created in program)
 */

import java.io.*;
import com.pdflib.pdflib;
import com.pdflib.PDFlibException;

public class starter_tagged
{
    public static void main (String argv[])
    {
	/* This is where the data files are. Adjust as necessary. */
	String searchpath = "../data";

	pdflib p = null;
	int id, id_artifact, font;

	try {
	    p = new pdflib();

	    p.set_parameter("SearchPath", searchpath);

	    /* This means we must check return values of load_font() etc. */
	    p.set_parameter("errorpolicy", "return");

	    if (p.begin_document("starter_tagged.pdf", "tagged=true") == -1)
		throw new Exception("Error: " + p.get_errmsg());

	    p.set_info("Creator", "PDFlib starter sample");
	    p.set_info("Title", "starter_tagged");

	    /* Automatically create spaces between chunks of text */
	    p.set_parameter("autospace", "true");

	    /* open the first structure element as a child of the document
	     * structure root (=0)
	     */
	    id = p.begin_item("P", "Title = {Simple Paragraph}");

	    p.begin_page_ext(0, 0, "width=a4.width height=a4.height");

	    font = p.load_font("Helvetica", "winansi", "");

	    if (font == -1)
		throw new Exception("Error: " + p.get_errmsg());

	    p.setfont(font, 24.0);

	    p.show_xy("Hello, Tagged PDF!", 50, 700);
	    p.continue_text("This PDF has a very simple");
	    p.continue_text("document structure.");

	    p.end_item(id);

	    /* The page number is created as an artifact; it will be
	     * ignored when reflowing the page in Acrobat.
	     */
	    id_artifact = p.begin_item("Artifact", "");
	    p.show_xy("Page 1", 250, 100);
	    p.end_item(id_artifact);

	    p.end_page_ext("");

	    p.end_document("");

        } catch (PDFlibException e){
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
