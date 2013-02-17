/* $Id: starter_block.java,v 1.3.2.1 2008/05/09 10:11:53 rjs Exp $
 *
 * Block starter:
 * Import a PDF page containing blocks, and process all blocks. The blocks
 * are retrieved via pCOS, and the block filling functions are used to
 * visualize the blocks on the output page. A real-world application would
 * of course fill the blocks with data retrieved from some external data
 * source.
 *
 * required software: PPS 7 or above
 * required data: input PDF
 */

import java.io.*;
import com.pdflib.pdflib;
import com.pdflib.PDFlibException;

public class starter_block
{
    public static void main (String argv[])
    {
	/* This is where the data files are. Adjust as necessary. */
	String searchpath = "../data";

	pdflib p = null;
	double width, height;
	String infile = "boilerplate.pdf";
	int i, page, indoc, blockcount;
	String optlist;

	try {
	    p = new pdflib();

	    p.set_parameter("SearchPath", searchpath);

	    /* This means we must check return values of load_font() etc. */
	    p.set_parameter("errorpolicy", "return");

	    if (p.begin_document("starter_block.pdf", "") == -1)
		throw new Exception("Error: " + p.get_errmsg());

	    p.set_info("Creator", "PDFlib starter sample");
	    p.set_info("Title", "starter_block");

	    /* Open a PDF containing blocks */
            indoc = p.open_pdi_document(infile, "");
            if (indoc == -1)
                throw new Exception("Error: " + p.get_errmsg());

	    /* Open the first page */
            page = p.open_pdi_page(indoc, 1, "");
            if (page == -1)
                throw new Exception("Error: " + p.get_errmsg());

	    width = p.pcos_get_number(indoc, "pages[0]/width");
	    height = p.pcos_get_number(indoc, "pages[0]/height");

	    p.begin_page_ext(width, height, "");

	    /* Place the imported page on the output page */
	    p.fit_pdi_page(page, 0, 0, "");

	    /* Query the number of blocks on the first page */
	    blockcount =
		(int) p.pcos_get_number(indoc, "length:pages[0]/blocks");

	    if (blockcount == 0)
                throw new Exception("Error: " +
			infile + "does not contain any PDFlib blocks");

	    /* Loop over all blocks on the page */
	    for (i = 0; i <  blockcount; i++)
	    {
		String blockname;
		String blocktype;

		/* Fetch the name and type of the i-th block on the first page
		 * (one of Text/Image/PDF)
		 */
		blockname = p.pcos_get_string(indoc,
		    "pages[0]/blocks[" + i + "]/Name");

		blocktype = p.pcos_get_string(indoc,
		    "pages[0]/blocks[" + i + "]/Subtype");

		/* Visualize all text blocks */
		if (blocktype.equals("Text"))
		{
		    optlist =
			"fontname=Helvetica encoding=unicode " +
			"fillcolor={rgb 1 0 0} " +
			"bordercolor={gray 0} linewidth=0.25";

		    /* We simply use the blockname as content */
		    if (p.fill_textblock(page, blockname, blockname, optlist)
		    	== -1)
			System.err.println("Warning: " + p.get_errmsg());
		}
	    }

	    p.end_page_ext("");
	    p.close_pdi_page(page);

	    p.end_document("");
	    p.close_pdi_document(indoc);

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
