/* $Id: starter_pdfmerge.java,v 1.4.2.1 2007/08/08 15:09:40 rp Exp $
 *
 * PDF merge starter:
 * Merge pages from multiple PDF documents; interactive elements (e.g. 
 * bookmarks) will be dropped.
 *
 * required software: PDFlib+PDI/PPS 7
 * required data: PDF documents
 */

import java.io.*;
import com.pdflib.pdflib;
import com.pdflib.PDFlibException;

public class starter_pdfmerge
{
    public static void main (String argv[])
    {
	/* This is where the data files are. Adjust as necessary. */
	String searchpath = "../data";

	pdflib p = null;
	String pdffiles[] =
	{
		"PDFlib-real-world.pdf",
		"PDFlib-datasheet.pdf",
		"TET-datasheet.pdf",
		"PLOP-datasheet.pdf",
		"pCOS-datasheet.pdf"
	};
	int i;

	try {
	    p = new pdflib();

	    p.set_parameter("SearchPath", searchpath);

	    /* This means we must check return values of load_font() etc. */
	    p.set_parameter("errorpolicy", "return");

	    if (p.begin_document("starter_pdfmerge.pdf", "") == -1)
		throw new Exception("Error: " + p.get_errmsg());

	    p.set_info("Creator", "PDFlib starter sample");
	    p.set_info("Title", "starter_pdfmerge");

	    for (i=0; i < pdffiles.length; i++)
	    {
		int indoc, endpage, pageno, page; 

		/* Open the input PDF */
		indoc = p.open_pdi_document(pdffiles[i], "");
		if (indoc == -1)
		{
		    System.err.println("Error: " + p.get_errmsg());
		    continue;
		}

		endpage = (int) p.pcos_get_number(indoc, "/Root/Pages/Count");

		/* Loop over all pages of the input document */
		for (pageno = 1; pageno <= endpage; pageno++)
		{
		    page = p.open_pdi_page(indoc, pageno, "");

		    if (page == -1)
		    {
			System.err.println("Error: " + p.get_errmsg());
			continue;
		    }
		    /* Dummy page size; will be adjusted later */
		    p.begin_page_ext(10, 10, "");

		    /* Create a bookmark with the file name */
		    if (pageno == 1)
			p.create_bookmark(pdffiles[i], "");

		    /* Place the imported page on the output page, and
		     * adjust the page size
		     */
		    p.fit_pdi_page(page, 0, 0, "adjustpage");
		    p.close_pdi_page(page);

		    p.end_page_ext("");
		}
		p.close_pdi_document(indoc);
	    }

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
