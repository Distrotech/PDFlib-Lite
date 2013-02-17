/* $Id: businesscardServlet.java,v 1.13 2004/05/17 12:47:19 rp Exp $
 *
 * PDFlib client: hello servlet example in Java
 */

import java.io.*;
import javax.servlet.*;

import com.pdflib.pdflib;
import com.pdflib.PDFlibException;

public class businesscardServlet extends GenericServlet
{
    public void service(ServletRequest request, ServletResponse response)
    {
	int font;
	pdflib p = null ;
	int i, blockcontainer, page;
	String infile = "boilerplate.pdf";
        /* This is where font/image/PDF input files live. Adjust as necessary.
         *
         * Note that this directory must also contain the LuciduxSans font
         * outline and metrics files.
         */
	String searchpath = "../data";
	String[][] data = {
	    { "name",                   "Victor Kraxi" },
	    { "business.title",         "Chief Paper Officer" },
	    { "business.address.line1", "17, Aviation Road" },
	    { "business.address.city",  "Paperfield" },
	    { "business.telephone.voice","phone +1 234 567-89" },
	    { "business.telephone.fax", "fax +1 234 567-98" },
	    { "business.email",         "victor@kraxi.com" },
	    { "business.homepage",      "www.kraxi.com" },
	    };
	byte[] buf;
	ServletOutputStream out;

	try{
	    p = new pdflib();

	// Generate a PDF in memory; insert a file name to create PDF on disk
	    if (p.begin_document("", "") == -1) {
		throw new Exception("Error: " + p.get_errmsg());
	    }

	    /*Set the search path for fonts and PDF files */
	    p.set_parameter("SearchPath", searchpath);

	    p.set_info("Creator", "businesscard.java");
	    p.set_info("Author", "Thomas Merz");
	    p.set_info("Title","PDFlib block processing sample (Java)");

	    blockcontainer = p.open_pdi(infile, "", 0);
	    if (blockcontainer == -1) {
		throw new Exception("Error: " + p.get_errmsg());
	    }

	    page = p.open_pdi_page(blockcontainer, 1, "");
	    if (page == -1) {
		throw new Exception("Error: " + p.get_errmsg());
	    }

	    p.begin_page_ext(20, 20, "");              // dummy page size

	    // This will adjust the page size to the block container's size.
	    p.fit_pdi_page(page, 0, 0, "adjustpage");

	    // Fill all text blocks with dynamic data 
	    for (i = 0; i < (int) data.length; i++) {
		if (p.fill_textblock(page, data[i][0], data[i][1],
			"embedding encoding=unicode") == -1) {
		    System.err.println("Warning: " + p.get_errmsg());
		}
	    }

	    p.end_page_ext("");                        // close page
	    p.close_pdi_page(page);

	    p.end_document("");                           // close PDF document
	    p.close_pdi(blockcontainer);

	    buf = p.get_buffer();

	    response.setContentType("application/pdf");
	    response.setContentLength(buf.length);

	    out = response.getOutputStream();
	    out.write(buf);
	    out.close();

        } catch (PDFlibException e) {
	    System.err.print("PDFlib exception occurred in businesscard sample:\n");
	    System.err.print("[" + e.get_errnum() + "] " + e.get_apiname() +
			    ": " + e.get_errmsg() + "\n");
        } catch (Exception e) {
            System.err.println(e.getMessage());
        } finally {
            if (p != null) {
		p.delete();			/* delete the PDFlib object */
            }
        }
    }
}
