/* $Id: starter_pvf.java,v 1.1.2.2 2008/03/10 18:43:48 rjs Exp $
 * PDFlib Virtual File system (PVF):
 * Create a PVF file which holds an image or PDF, and import the data from the
 * PVF file
 *
 * This avoids disk access and is especially useful when the same image or PDF
 * is imported multiply. For examples, images which sit in a database don't
 * have to be written and re-read from disk, but can be passed to PDFlib
 * directly in memory. A similar technique can be used for loading other data
 * such as fonts, ICC profiles, etc.
 *
 * Required software: PDFlib Lite/PDFlib/PDFlib+PDI/PPS 7
 * Required data: image file
 */
import java.io.*;
import com.pdflib.pdflib;
import com.pdflib.PDFlibException;

public class starter_pvf
{
    public static void main (String argv[])
    {
    /* This is where the data files are. Adjust as necessary. */
    String searchpath = "../data";
    String outfile = "starter_pvf.pdf";
    String title = "PDFlib Virtual File System";

    pdflib p = null;
    FileInputStream fis;
    byte[] imageData = null;

    try {
        p = new pdflib();

        p.set_parameter("SearchPath", searchpath);

        /* This means we must check return values of load_font() etc. */
        p.set_parameter("errorpolicy", "return");

        /* Set an output path according to the name of the topic */
        if (p.begin_document(outfile, "") == -1)
            throw new Exception("Error: " + p.get_errmsg());

        p.set_info("Creator", "PDFlib Cookbook");

        /* We just read some image data from a file; to really benefit
         * from using PVF read the data from a Web site or a database instead
         */
        fis = new FileInputStream("../data/PDFlib-logo.tif");

        imageData = new byte[fis.available()];
        fis.read(imageData);

        p.create_pvf("/pvf/image", imageData, "");

        /* Load the image from the PVF */
        int image = p.load_image("auto", "/pvf/image" , "");
        if (image == -1)
            throw new Exception("Error: " + p.get_errmsg());

        /* Fit the image on page 1 */
        p.begin_page_ext(595, 842, "");

        p.fit_image(image, 350, 750, "");

        p.end_page_ext("");

        /* Fit the image on page 2 */
        p.begin_page_ext(595, 842, "");

        p.fit_image(image, 350, 50, "");

        p.end_page_ext("");

        /* Delete the virtual file to free the allocated memory */

        p.delete_pvf("/pvf/image");

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
