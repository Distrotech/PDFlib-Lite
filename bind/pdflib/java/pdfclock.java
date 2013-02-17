/* $Id: pdfclock.java,v 1.20.2.1 2007/03/12 14:04:48 rp Exp $
 *
 * PDFlib client: pdfclock example in Java
 */

import java.io.*;
import java.text.*;		// SimpleDateFormat
import java.util.*;		// Date
import com.pdflib.pdflib;
import com.pdflib.PDFlibException;

public class pdfclock
{
    public static void main (String argv[])
    {
	pdflib p = null;
	int tm_hour, tm_min, tm_sec, alpha;
	double RADIUS = 200.0;
	double MARGIN = 20.0;
	SimpleDateFormat format;
	Date now = new Date();

	try{
	    p = new pdflib();

	    /* This means we must check return values of load_font() etc. */
	    p.set_parameter("errorpolicy", "return");

	    if (p.begin_document("pdfclock.pdf", "") == -1)
		throw new Exception("Error: " + p.get_errmsg());

	    p.set_info("Creator", "pdfclock.java");
	    p.set_info("Author", "Thomas Merz");
	    p.set_info("Title", "PDF clock (Java)");

	    p.begin_page_ext( (int) (2 * (RADIUS + MARGIN)),
				    (int) (2 * (RADIUS + MARGIN)), "");

	    p.translate(RADIUS + MARGIN, RADIUS + MARGIN);
	    p.setcolor("fillstroke", "rgb", 0.0, 0.0, 1.0, 0.0);
	    p.save();

	    // minute strokes 
	    p.setlinewidth(2.0);
	    for (alpha = 0; alpha < 360; alpha += 6)
	    {
		p.rotate(6.0);
		p.moveto(RADIUS, 0.0);
		p.lineto(RADIUS-MARGIN/3, 0.0);
		p.stroke();
	    }

	    p.restore();
	    p.save();

	    // 5 minute strokes
	    p.setlinewidth(3.0);
	    for (alpha = 0; alpha < 360; alpha += 30)
	    {
		p.rotate(30.0);
		p.moveto(RADIUS, 0.0);
		p.lineto(RADIUS-MARGIN, 0.0);
		p.stroke();
	    }

	    format = new SimpleDateFormat("hh");
	    tm_hour= Integer.parseInt(format.format(now));
	    format = new SimpleDateFormat("mm");
	    tm_min = Integer.parseInt(format.format(now));
	    format = new SimpleDateFormat("ss");
	    tm_sec = Integer.parseInt(format.format(now));

	    // draw hour hand 
	    p.save();
	    p.rotate((-((tm_min/60.0) + tm_hour - 3.0) * 30.0));
	    p.moveto(-RADIUS/10, -RADIUS/20);
	    p.lineto(RADIUS/2, 0.0);
	    p.lineto(-RADIUS/10, RADIUS/20);
	    p.closepath();
	    p.fill();
	    p.restore();

	    // draw minute hand
	    p.save();
	    p.rotate((-((tm_sec/60.0) + tm_min - 15.0) * 6.0));
	    p.moveto(-RADIUS/10, -RADIUS/20);
	    p.lineto(RADIUS * 0.8, 0.0);
	    p.lineto(-RADIUS/10, RADIUS/20);
	    p.closepath();
	    p.fill();
	    p.restore();

	    // draw second hand
	    p.setcolor("fillstroke", "rgb", 1.0, 0.0, 0.0, 0.0);
	    p.setlinewidth(2);
	    p.save();
	    p.rotate(-((tm_sec - 15.0) * 6.0));
	    p.moveto(-RADIUS/5, 0.0);
	    p.lineto(RADIUS, 0.0);
	    p.stroke();
	    p.restore();

	    // draw little circle at center
	    p.circle(0, 0, RADIUS/30);
	    p.fill();

	    p.restore();
	    p.end_page_ext("");
	    p.end_document("");

        } catch (PDFlibException e) {
	    System.err.print("PDFlib exception occurred in pdfclock sample:\n");
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
