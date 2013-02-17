/* $Id: starter_type3font.java,v 1.1.2.4 2009/11/18 00:16:11 rjs Exp $
 * Type 3 font starter:
 * Create a simple Type 3 font from vector data
 *
 * Define a type 3 font with the glyphs "l" and "space" and output text with
 * that font. In addition the glyph ".notdef" is defined which any undefined
 * character will be mapped to.
 *
 * Required software: PDFlib/PDFlib+PDI/PPS 7
 * Required data: none
 */

import com.pdflib.pdflib;
import com.pdflib.PDFlibException;

public class starter_type3font
{
    public static void main (String argv[])
    {
    /* This is where the data files are. Adjust as necessary. */
    String searchpath = "../data";
    String outfile = "starter_type3font.pdf";
    String title = "Starter Type 3 Font";

    pdflib p = null;
    int font;
    double x, y;

    try {
        p = new pdflib();

        p.set_parameter("SearchPath", searchpath);

        /* This means we must check return values of load_font() etc. */
        p.set_parameter("errorpolicy", "return");

        if (p.begin_document(outfile, "") == -1)
        throw new Exception("Error: " + p.get_errmsg());

        p.set_info("Creator", "PDFlib Cookbook");

        /* Create the font "SimpleFont" containing the glyph "l",
         * the glyph "space" for spaces and the glyph ".notdef" for any
         * undefined character
         */
        p.begin_font("SimpleFont", 0.001, 0.0, 0.0, 0.001, 0.0, 0.0, "");
        p.begin_glyph(".notdef", 266, 0, 0, 0, 0);
        p.end_glyph();
        p.begin_glyph("space", 266, 0, 0, 0, 0);
        p.end_glyph();
        p.begin_glyph("l", 266, 0, 0, 266, 570);
        p.setlinewidth(20);
        p.setdash(0, 0);
        x = 197;
        y = 10;
        p.moveto(x, y);
        y += 530;
        p.lineto(x, y);
        x -= 64;
        p.lineto(x, y);
        y -= 530;
        p.moveto(x, y);
        x += 128;
        p.lineto(x, y);

        p.stroke();
        p.end_glyph();

        p.end_font();

        /* Start page */
        p.begin_page_ext(0, 0, "width=300 height=200");

        /* Load the new "SimpleFont" font */
        font = p.load_font("SimpleFont", "winansi", "");

        if (font == -1)
            throw new Exception("Error: " + p.get_errmsg());

        /* Output the characters "l" and "space" of the "SimpleFont" font.
         * The character "x" is undefined and will be mapped to ".notdef"
         */
        p.fit_textline("lll lllxlll", 100, 100, "font=" + font
		+ " fontsize=40");

        p.end_page_ext("");

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
