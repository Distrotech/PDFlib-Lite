/* $Id: starter_pdfx.java,v 1.5 2006/09/27 20:39:25 tm Exp $
 *
 * PDF/X starter:
 * Create PDF/X-compliant output
 *
 * required software: PDFlib/PDFlib+PDI/PPS 7 or above
 * required data: font file, image file, ICC profile
 *                (see www.pdflib.com for ICC profiles)
 */

import java.io.*;
import com.pdflib.pdflib;
import com.pdflib.PDFlibException;

public class starter_pdfx
{
    public static void main (String argv[])
    {
	/* This is where the data files are. Adjust as necessary.*/
	String searchpath = "../data";

	pdflib p = null;
	String imagefile = "nesrin.jpg";

	int font, image, spot, icc;

	try {
	    p = new pdflib();

	    p.set_parameter("SearchPath", searchpath);

	    /* This means we must check return values of load_font() etc. */
	    p.set_parameter("errorpolicy", "return");

	    if (p.begin_document("starter_pdfx.pdf", "pdfx=PDF/X-3:2002") == -1)
		throw new Exception("Error: " + p.get_errmsg());

	    p.set_info("Creator", "PDFlib starter sample");
	    p.set_info("Title", "starter_pdfx");

	    /*
	     * You can use one of the Standard output intents (e.g. for SWOP
	     * printing) which do not require an ICC profile:

	    p.load_iccprofile("CGATS TR 001", "usage=outputintent");

	     * However, if you use ICC or Lab color you must load an ICC
	     * profile as output intent:
	     */
	    if (p.load_iccprofile("ISOcoated.icc", "usage=outputintent") == -1)
	    {
		System.err.print("Error: " +  p.get_errmsg() + "\n");
		System.err.print("Please install the ICC profile package from "
		    + "www.pdflib.com to run the PDF/X starter sample.\n");
		p.delete();
		System.exit(2);
	    }

	    p.begin_page_ext(595, 842, "");

	    /* Font embedding is required for PDF/X */
	    font = p.load_font("LuciduxSans-Oblique", "unicode", "embedding");

	    if (font == -1)
		throw new Exception("Error: " + p.get_errmsg());

	    p.setfont(font, 24);

	    spot = p.makespotcolor("PANTONE 123 C");
	    p.setcolor("fill", "spot", spot, 1.0, 0.0, 0.0);
	    p.fit_textline("PDF/X-3:2002 starter", 50, 700, "");

	    /* The RGB image below needs an ICC profile; we use sRGB. */
	    icc = p.load_iccprofile("sRGB", "");
	    image = p.load_image("auto", imagefile, "iccprofile=" + icc);

	    if (image == -1)
		throw new Exception("Error: " + p.get_errmsg());

	    p.fit_image(image, 0.0, 0.0, "scale=0.5");

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
