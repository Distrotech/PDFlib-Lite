/* $Id: starter_graphics.java,v 1.1.2.3 2008/03/10 18:43:48 rjs Exp $
 * Starter Graphics:
 * Create some basic examples of vector graphics
 *
 * Stroke a line, curve, circle, arc, and rectangle using the current line width
 * and stroke color. Stroke and fill a rectangle.
 * Draw an arc segment by drawing a line and an arc, closing the path and
 * filling and stroking it.
 * Draw a rectangle and use it as the clipping a path. Draw and fill a circle
 * using the clipping path defined.
 *
 * Required software: PDFlib Lite/PDFlib/PDFlib+PDI/PPS 7
 * Required data: none
 */
import com.pdflib.pdflib;
import com.pdflib.PDFlibException;

public class starter_graphics
{
    public static void main (String argv[])
    {
    /* This is where the data files are. Adjust if necessary. */
    String searchpath = "../data";
    String outfile = "starter_graphics.pdf";
    String title = "Starter Graphics";

    double xt=20, x = 210, y=770, dy=90;

    pdflib p = null;

    int font;

    try {
        p = new pdflib();

        p.set_parameter("SearchPath", searchpath);

        /* This means we must check return values of load_font() etc. */
        p.set_parameter("errorpolicy", "return");

        if (p.begin_document(outfile, "") == -1)
            throw new Exception("Error: " + p.get_errmsg());

        p.set_info("Creator", "PDFlib Cookbook");

        /* Load the font; for PDFlib Lite: change "unicode" to "winansi" */
        font = p.load_font("Helvetica", "unicode", "");
        if (font == -1)
            throw new Exception("Error: " + p.get_errmsg());

        /* Start an A4 page */
        p.begin_page_ext(0, 0, "width=a4.width height=a4.height");

        /* Set the font */
        p.setfont(font, 14);

        /* Set the line width */
        p.setlinewidth(2.0);

        /* Set the stroke color */
        p.setcolor("stroke", "rgb", 0.0, 0.5, 0.5, 0.0);

        /* Set the fill color */
        p.setcolor("fill", "rgb", 0.0, 0.85, 0.85, 0.0);


        /* -------------
         * Stroke a line
         * -------------
         */

        /* Set the current point for graphics output */
        p.moveto(x, y);

        /* Draw a line from the current point to the supplied point */
        p.lineto(x+300, y+50);

        /* Stroke the path using the current line width and stroke color, and
         * clear it
         */
        p.stroke();

        /* Output some descriptive black text */
        p.fit_textline("lineto() and stroke()", xt, y, "fillcolor={gray 0}");


        /* --------------
         * Stroke a curve
         * --------------
         */

       /* Set the current point for graphics output */
        p.moveto(x, y-=dy);

        /* Draw a Bezier curve from the current point to (x3, y3), using three
         * control points
         */
        p.curveto(x+50, y+40, x+200, y+80, x+300, y+30);

        /* Stroke the path using the current line width and stroke color, and
         * clear it
         */
        p.stroke();

        /* Output some descriptive black text */
        p.fit_textline("curveto() and stroke()", xt, y, "fillcolor={gray 0}");


        /* ---------------
         * Stroke a circle
         * ---------------
         */

        /* Draw a circle at position (x, y) with a radius of 40 */
        p.circle(x, y-=dy, 40);

        /* Stroke the path using the current line width and stroke color, and
         * clear it
         */
        p.stroke();

        /* Output some descriptive black text */
        p.fit_textline("circle() and stroke()", xt, y, "fillcolor={gray 0}");


        /* ---------------------
         * Stroke an arc segment
         * ---------------------
         */

        /* Draw an arc segment counterclockwise at position (x, y) with a radius
         * of 40 starting at an angle of 90 degrees and ending at 180 degrees
         */
        p.arc(x, y-=dy+20, 40, 90, 180);

        /* Stroke the path using the current line width and stroke color, and
         * clear it
         */
        p.stroke();

        /* Output some descriptive black text */
        p.fit_textline("arc() and stroke()", xt, y, "fillcolor={gray 0}");


        /* ------------------
         * Stroke a rectangle
         * ------------------
         */

        /* Draw a rectangle at position (x, y) with a width of 200 and a height
         * of 50
         */
        p.rect(x, y-=dy, 200, 50);

        /* Stroke the path using the current line width and stroke color, and
         * clear it
         */
        p.stroke();

        /* Output some descriptive black text */
        p.fit_textline("rect() and stroke()", xt, y, "fillcolor={gray 0}");


        /* ----------------
         * Fill a rectangle
         * ----------------
         */

        /* Draw a rectangle at position (x, y) with a width of 200 and a height
         * of 50
         */
        p.rect(x, y-=dy, 200, 50);

        /* Fill the path using current fill color, and clear it */
        p.fill();

        /* Output some descriptive black text */
        p.fit_textline("rect() and fill()", xt, y, "fillcolor={gray 0}");


        /* ---------------------------
         * Fill and stroke a rectangle
         * ---------------------------
         */

        /* Draw a rectangle at position (x, y) with a width of 200 and a height
         * of 50
         */
        p.rect(x, y-=dy, 200, 50);

        /* Fill and stroke the path using the current line width, fill color,
         * and stroke color, and clear it
         */
        p.fill_stroke();

        /* Output some descriptive black text */
        p.fit_textline("rect() and fill_stroke()", xt, y, "fillcolor={gray 0}");


        /* -------------------------------------------------------------
         * Draw a line and an arc, close the path and fill and stroke it
         * -------------------------------------------------------------
         */

        /* Set the current point for graphics output */
        p.moveto(x-40, y-=dy);

        /* Draw a line from the current point to the supplied point */
        p.lineto(x, y);

        /* Draw an arc segment counterclockwise at position (x, y) with a radius
         * of 40 starting at an angle of 90 degrees and ending at 180 degrees
         */
        p.arc(x, y, 40, 90, 180);

        /* Close the path and stroke and fill it, i.e. close the current subpath
         * (add a straight line segment from the current point to the starting
         * point of the path), and stroke and fill the complete current path
         */
        p.closepath_fill_stroke();

        /* Output some descriptive black text */
        p.fit_textline("lineto(), arc(), and", xt, y+20, "fillcolor={gray 0}");
        p.fit_textline("closepath_fill_stroke()", xt, y, "fillcolor={gray 0}");


        /* -----------------------------------------------------------------
         * Draw a rectangle and use it as the clipping a path. Draw and fill
         * a circle and clip it according to the clipping path defined.
         * -----------------------------------------------------------------
         */

        /* Save the current graphics state including the current clipping
         * path which is set to the entire page by default
         */
        p.save();

        /* Draw a rectangle at position (x, y) with a width of 200 and a height
         * of 50
         */
        p.rect(x, y-=dy, 200, 50);

        /* Use the current path as the clipping path for subsequent operations
         */
        p.clip();

        /* Draw a circle at position (x, y) with a radius of 100 */
        p.circle(x, y, 80);

        /* Fill the path with the current fill color and clear it
         */
        p.fill();

        /* Restore the graphics state which has been saved above */
        p.restore();

        /* Output some descriptive black text */
        p.fit_textline("rect(), clip(),", xt, y+20, "fillcolor={gray 0}");
        p.fit_textline("circle(), and fill()", xt, y, "fillcolor={gray 0}");

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
