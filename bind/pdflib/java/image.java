/* $Id: image.java,v 1.20 2006/09/28 13:31:21 tm Exp $
 *
 * PDFlib client: image example in Java
 */

import java.io.*;
import com.pdflib.pdflib;
import com.pdflib.PDFlibException;

public class image
{
    public static void main (String argv[]) 
    {
	int image;
	pdflib p = null;
	String imagefile = "nesrin.jpg";
	/* This is where font/image/PDF input files live. Adjust as necessary.*/
	String searchpath = "../data";

	try{

	    p = new pdflib();

	    /* This means we must check return values of load_font() etc. */
	    p.set_parameter("errorpolicy", "return");

	    if (p.begin_document("image.pdf", "") == -1)
		throw new Exception("Error: " + p.get_errmsg());

	    p.set_parameter("SearchPath", searchpath);

	    p.set_info("Creator", "image.java");
	    p.set_info("Author", "Thomas Merz");
	    p.set_info("Title", "image sample (Java)");

	    image = p.load_image("auto", imagefile, "");

	    if (image == -1)
		throw new Exception("Error: " + p.get_errmsg());

	    /* dummy page size, will be adjusted by PDF_fit_image() */
	    p.begin_page_ext(10, 10, "");
	    p.fit_image(image, 0.0, 0.0, "adjustpage");
	    p.close_image(image);
	    p.end_page_ext("");

	    p.end_document("");

        } catch (PDFlibException e) {
	    System.err.print("PDFlib exception occurred in hello sample:\n");
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
