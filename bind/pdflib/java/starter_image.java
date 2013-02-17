/* $Id: starter_image.java,v 1.2.2.2 2008/03/10 18:43:48 rjs Exp $
 * Starter image:
 * Load and place an image using various options for scaling and positioning
 *
 * Place the image it its original size.
 * Place the image with scaling and orientation to the west.
 * Fit the image into a box with clipping.
 * Fit the image into a box with proportional resizing.
 * Fit the image into a box entirely.
 *
 * Required software: PDFlib Lite/PDFlib/PDFlib+PDI/PPS 7
 * Required data: image file
 */
import com.pdflib.pdflib;
import com.pdflib.PDFlibException;

public class starter_image
{
    public static void main (String argv[])
    {
    /* This is where the data files are. Adjust as necessary. */
    String searchpath = "../data";
    String outfile = "starter_image.pdf";
    String title = "Starter Image";

    pdflib p = null;
    String imagefile = "lionel.jpg";
    int font, image;
    int bw = 400, bh = 200;
    int x = 20, y = 580, yoffset = 260;

    try {
        p = new pdflib();

        p.set_parameter("SearchPath", searchpath);

        /* This means we must check return values of load_font() etc. */
        p.set_parameter("errorpolicy", "return");

        if (p.begin_document(outfile, "") == -1)
            throw new Exception("Error: " + p.get_errmsg());

        p.set_info("Creator", "PDFlib Cookbook");

        /* For PDFlib Lite: change "unicode" to "winansi" */
        font = p.load_font("Helvetica", "unicode", "");
        if (font == -1)
            throw new Exception("Error: " + p.get_errmsg());

        /* Load the image */
        image = p.load_image("auto", imagefile, "");
        if (image == -1)
            throw new Exception("Error: " + p.get_errmsg());

        /* Start page 1 */
        p.begin_page_ext(0, 0, "width=a4.width height=a4.height");
        p.setfont(font, 12);


        /* ------------------------------------
         * Place the image in its original size
         * ------------------------------------
         */

        /* Position the image in its original size with its lower left corner
         * at the reference point (20, 380)
         */
        p.fit_image(image, 20, 380, "");

        /* Output some descriptive text */
        p.fit_textline("The image is placed with the lower left corner in " +
            "its original size at reference point (20, 380):", 20, 820, "");
        p.fit_textline("fit_image(image, 20, 380, \"\");", 20, 800, "");


        /* --------------------------------------------------------
         * Place the image with scaling and orientation to the west
         * --------------------------------------------------------
         */

        /* Position the image with its lower right corner at the reference
         * point (580, 20).
         * "scale=0.5" scales the image by 0.5.
         * "orientate=west" orientates the image to the west.
         */
        p.fit_image(image, 580, 20, "scale=0.5 position={right bottom} " +
            "orientate=west");

        /* Output some descriptive text */
        p.fit_textline("The image is placed with a scaling of 0.5 and an " +
            "orientation to the west with the lower right corner", 580, 320,
            "position={right bottom}");
        p.fit_textline(" at reference point (580, 20): fit_image(image, 580, " +
            "20, \"scale=0.5 orientate=west position={right bottom}\");",
            580, 300, "position={right bottom}");

        p.end_page_ext("");

        /* Start page 2 */
        p.begin_page_ext(0, 0, "width=a4.width height=a4.height");
        p.setfont(font, 12);


        /* --------------------------------------
         * Fit the image into a box with clipping
         * --------------------------------------
         */

        /* The "boxsize" option defines a box with a given width and height and
         * its lower left corner located at the reference point.
         * "position={right top}" positions the image on the top right of the
         * box.
         * "fitmethod=clip" clips the image to fit it into the box.
         */
        p.fit_image(image, x, y, "boxsize={" + bw + " " + bh + "} " +
            "position={right top} fitmethod=clip");

        /* Output some descriptive text */
        p.fit_textline("fit_image(image, x, y, \"boxsize={400 200} " +
            "position={right top} fitmethod=clip\");", 20, y+bh+10, "");


        /* ---------------------------------------------------
         * Fit the image into a box with proportional resizing
         * ---------------------------------------------------
         */

        /* The "boxsize" option defines a box with a given width and height and
         * its lower left corner located at the reference point.
         * "position={center}" positions the image in the center of the
         * box.
         * "fitmethod=meet" resizes the image proportionally until its height
         * or width completely fits into the box.
         * The "showborder" option is used to illustrate the borders of the box.
         */
        p.fit_image(image, x, y-=yoffset, "boxsize={" + bw + " " + bh + "} " +
            "position={center} fitmethod=meet showborder");

        /* Output some descriptive text */
        p.fit_textline("fit_image(image, x, y, \"boxsize={400 200} " +
            "position={center} fitmethod=meet showborder\");", 20, y+bh+10, "");


        /* ---------------------------------
         * Fit the image into a box entirely
         * ---------------------------------
         */

        /* The "boxsize" option defines a box with a given width and height and
         * its lower left corner located at the reference point.
         * By default, the image is positioned in the lower left corner of the
         * box.
         * "fitmethod=entire" resizes the image proportionally until its height
         * or width completely fits into the box.
         */
        p.fit_image(image, x, y-=yoffset, "boxsize={" + bw + " " + bh + "} " +
            "fitmethod=entire");

        /* Output some descriptive text */
        p.fit_textline("fit_image(image, x, y, \"boxsize={400 200} " +
            "fitmethod=entire\");", 20, y+bh+10, "");

        p.end_page_ext("");

        p.close_image(image);

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
