/* $Id: starter_webform.java,v 1.3 2006/09/28 11:06:18 tm Exp $
 *
 * Webform starter:
 * create a linearized PDF (for fast delivery over the Web, also known
 * as "fast Web view") which is encrypted and contains some form fields.
 * A few lines of JavaScript are inserted as "page open" action to
 * automatically populate the date field with the current date.
 *
 * required software: PDFlib/PDFlib+PDI/PPS 7 or above
 * required data: none
 */

import java.io.*;
import com.pdflib.pdflib;
import com.pdflib.PDFlibException;

public class starter_webform
{
    public static void main (String argv[])
    {
	pdflib p = null;
	String optlist;
	int font, action;
	double llx=150, lly=550, urx=350, ury=575;

	/* JavaScript for automatically filling the date into a form field */
	String js =
	    "var d = util.printd(\"mm/dd/yyyy\", new Date());" +
	    "var date = this.getField(\"date\");" +
	    "date.value = d;";

	try {
	    p = new pdflib();

	    /* This means we must check return values of load_font() etc. */
	    p.set_parameter("errorpolicy", "return");

	    /* Prevent changes with a master password */
	    optlist = "linearize masterpassword=pdflib permissions={nomodify}";

	    if (p.begin_document("starter_webform.pdf", optlist) == -1)
		throw new Exception("Error: " + p.get_errmsg());

	    p.set_info("Creator", "PDFlib starter sample");
	    p.set_info("Title", "starter_webform");

	    optlist = "script={" + js + "}";
	    action = p.create_action("JavaScript", optlist);

	    optlist = "action={open=" + action + "}";
	    p.begin_page_ext(595, 842, optlist);

	    font = p.load_font("Helvetica", "winansi", "");

	    if (font == -1)
		throw new Exception("Error: " + p.get_errmsg());

	    p.setfont(font, 24);

	    p.fit_textline("Date: ", 125, lly+5, "position={right bottom}");

	    /* The tooltip will be used as rollover text for the field */
	    optlist =
		"tooltip={Date (will be filled automatically)} " +
		"bordercolor={gray 0} font=" + font;
	    p.create_field(llx, lly, urx, ury, "date", "textfield", optlist);

	    lly-=100; ury-=100;
	    p.fit_textline("Name: ", 125, lly+5, "position={right bottom}");

	    optlist =
		"tooltip={Enter your name here} " +
		"bordercolor={gray 0} font=" + font;
	    p.create_field(llx, lly, urx, ury, "name", "textfield", optlist);

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
