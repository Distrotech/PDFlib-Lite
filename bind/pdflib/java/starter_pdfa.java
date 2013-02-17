/* $Id: starter_pdfa.java,v 1.3 2006/09/27 20:39:25 tm Exp $
 *
 * PDF/A starter:
 * Create PDF/A-compliant output
 *
 * required software: PDFlib/PDFlib+PDI/PPS 7
 * required data: font file, image file
 */

import java.io.*;
import com.pdflib.pdflib;
import com.pdflib.PDFlibException;

public class starter_pdfa
{
    public static void main (String argv[])
    {
	/* This is where the data files are. Adjust as necessary. */
	String searchpath = "../data";

	pdflib p = null;
	String imagefile = "nesrin.jpg";

	int font;
	int image;

	try {
	    p = new pdflib();

	    p.set_parameter("SearchPath", searchpath);

	    /* This means we must check return values of load_font() etc. */
	    p.set_parameter("errorpolicy", "return");

	    /* PDF/A-1a requires Tagged PDF */
	    if (p.begin_document("starter_pdfa.pdf", "pdfa=PDF/A-1b:2005")
	    	== -1)
		throw new Exception("Error: " + p.get_errmsg());

	    /*
	     * We use sRGB as output intent since it allows the color
	     * spaces CIELab, ICC-based, grayscale, and RGB.
	     *
	     * If you need CMYK color you must use a CMYK output profile.
	     */

	    p.load_iccprofile("sRGB", "usage=outputintent");

	    p.set_info("Creator", "PDFlib starter sample");
	    p.set_info("Title", "starter_pdfa");

	    p.begin_page_ext(595, 842, "");

	    /* Font embedding is required for PDF/A */
	    font = p.load_font("LuciduxSans-Oblique", "unicode", "embedding");

	    if (font == -1)
		throw new Exception("Error: " + p.get_errmsg());

	    p.setfont(font, 24);

	    p.fit_textline("PDF/A-1b:2005 starter", 50, 700, "");

	    /* We can use an RGB image since we already supplied an
	     * output intent profile.
	     */
	    image = p.load_image("auto", imagefile, "");

	    if (image == -1)
		throw new Exception("Error: " + p.get_errmsg());

	    /* Place the image at the bottom of the page */
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
