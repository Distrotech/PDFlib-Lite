/* $Id: chartab-lite.java,v 1.4 2006/09/28 13:31:21 tm Exp $
 *
 * PDFlib client: character table
 */

import java.io.*;
import com.pdflib.pdflib;
import com.pdflib.PDFlibException;

public class chartab
{
    /* change these as required */
    static final String fontname = "LuciduxSans-Oblique";

    /* This is where font/image/PDF input files live. Adjust as necessary. */
    static final String searchpath = "../data";

    /* list of encodings to use */
    static final String encodings[] = {"iso8859-1", "iso8859-2", "iso8859-15"};
    static final int ENCODINGS = 3;
    static final double FONTSIZE	= 16;
    static final double TOP		= 700;
    static final double LEFT		= 50;
    static final double YINCR	= 2*FONTSIZE;
    static final double XINCR	= 2*FONTSIZE;

    public static void main (String argv[])
    {
	/* whether or not to embed the font */
	int embed = 1;

	String buf;
	String optlist;
	double x, y;
	int row, col, font, page;

	pdflib p = null ;

	try{
	    p = new pdflib();

	    /* This means we must check return values of load_font() etc. */
	    p.set_parameter("errorpolicy", "return");

	    if (p.begin_document("chartab.pdf",
	    	"destination {type fitwindow page 1}") == -1)
	    {
		throw new Exception("Error: " + p.get_errmsg());
	    }

	    p.set_parameter("SearchPath", searchpath);

	    p.set_info("Creator", "chartab.java");
	    p.set_info("Author", "Thomas Merz");
	    p.set_info("Title", "Character table (Java)");

	    /* loop over all encodings */
	    for (page = 0; page < ENCODINGS; page++)
	    {
		p.begin_page_ext(595, 842, "");  /* start a new page */

		/* print the heading and generate the bookmark */
		font = p.load_font("Helvetica", "winansi", "");
		if (font == -1)
		    throw new Exception("Error: " + p.get_errmsg());

		p.setfont(font, FONTSIZE);
		if (embed == 1) {
		    buf = fontname + " (" + encodings[page] + ") embedded";
		} else{
		    buf = fontname + " (" + encodings[page] + ") not  embedded";
		}

		p.show_xy(buf, LEFT - XINCR, TOP + 3 * YINCR);
		p.create_bookmark(buf, "");

		/* print the row and column captions */
		p.setfont(font, 2 * FONTSIZE/3);

		for (row = 0; row < 16; row++)
		{
		    buf ="x" + (Integer.toHexString(row)).toUpperCase();
		    p.show_xy(buf, LEFT + row*XINCR, TOP + YINCR);

		    buf = (Integer.toHexString(row)).toUpperCase() + "x";
		    p.show_xy(buf, LEFT - XINCR, TOP - row * YINCR);
		}

		/* print the character table */
		if (embed == 1) {
		    optlist = "embedding";
		} else{
		    optlist = "";
		}
		font = p.load_font(fontname, encodings[page], optlist);
		if (font == -1)
		    throw new Exception("Error: " + p.get_errmsg());

		p.setfont(font, FONTSIZE);

		y = TOP;
		x = LEFT;

		for (row = 0; row < 16; row++)
		{
		    for (col = 0; col < 16; col++) {
			buf = String.valueOf((char)(16*row + col));
			p.show_xy(buf, x, y);
			x += XINCR;
		    }
		    x = LEFT;
		    y -= YINCR;
		}

		p.end_page_ext("");
	    }
	    p.end_document("");

        } catch (PDFlibException e) {
	    System.err.print("PDFlib exception occurred in chartab sample:\n");
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
