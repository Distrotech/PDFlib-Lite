/* $Id: starter_3d.java,v 1.1.2.3 2008/03/10 18:43:48 rjs Exp $
 * 3D Starter:
 * Create a 3D model and load it into a U3D annotation.
 *
 * Define a 3D view and load some 3D data with the view defined. Then create
 * an annotation containing the loaded 3D data with the defined 3D view as the
 * initial view.
 *
 * Acrobat 7.07 or above is required for viewing PDF documents containing a
 * 3D model.
 *
 * Required software: PDFlib/PDFlib+PDI/PPS 7.0.1
 * Required data: U3D data file
 */
import com.pdflib.pdflib;
import com.pdflib.PDFlibException;

public class starter_3d
{
    public static void main (String argv[])
    {
    /* This is where the data files are. Adjust if necessary. */
    String searchpath = "../data";
    String outfile = "starter_3d.pdf";
    String title = "Starter 3D";

    pdflib p = null;

    /* Required minimum PDFlib version */
    final double requiredversion = 701;
    final String requiredvstr = "7.0.1";

    String optlist;
    int font, u3dview, u3ddata;

    try {
        p = new pdflib();

        p.set_parameter("SearchPath", searchpath);

        /* This means we must check return values of load_font() etc. */
        p.set_parameter("errorpolicy", "return");

        /* Check whether the required minimum PDFlib version is available */
        double major = p.get_value("major", 0);
        double minor = p.get_value("minor", 0);
        double revision = p.get_value("revision", 0);

        if (major*100 + minor*10 + revision < requiredversion)
            throw new Exception("Error: PDFlib " + requiredvstr +
                " or above is required");

        /* Start the document */
        if (p.begin_document(outfile, "") == -1)
            throw new Exception("Error: " + p.get_errmsg());

        p.set_info("Creator", "PDFlib Cookbook");

        font = p.load_font("Helvetica", "winansi", "");
        if (font == -1)
            throw new Exception("Error: " + p.get_errmsg());

        p.begin_page_ext(0, 0, "width=a4.width height=a4.height");

        /* Define a U3D view */
        optlist = "name=FirstView background={fillcolor={rgb 1 0.5 0.1}}";
        if ((u3dview = p.create_3dview("First view", optlist)) == -1)
            throw new Exception("Error: " + p.get_errmsg());

        /* Load some U3D data with the view defined above */
        if ((u3ddata 
		= p.load_3ddata("box.u3d", "views={" + u3dview + "}")) == -1)
            throw new Exception("Error: " + p.get_errmsg());

        /* Create an annotation containing the loaded U3D data with the
         * defined 3D view as the initial view
         */
        optlist = "name=annot usercoordinates contents=U3D 3ddata= " + u3ddata +
            " 3dactivate={enable=open} 3Dinitialview=" + u3dview;
        p.create_annotation(116, 400, 447, 580, "3D", optlist);

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
