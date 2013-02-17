/* $Id: starter_pcos.java,v 1.3.2.1 2007/02/13 11:53:46 stm Exp $
 *
 * pCOS starter:
 * Dump information from an existing PDF document
 *
 * required software: PDFlib+PDI/PPS 7
 * required data: PDF input file
 */

import com.pdflib.pdflib;
import com.pdflib.PDFlibException;
import java.text.DecimalFormat;

public class starter_pcos
{
    public static void main (String argv[])
    {
	/* This is where the data files are. Adjust as necessary. */
	String searchpath = "../data";

	pdflib p = null;
	String pdfinput = "TET-datasheet.pdf";

	final String	docoptlist = "requiredmode=minimum";
	int	count, pcosmode;
	int	i, doc;
	String	objtype;

	try
	{
	    p = new pdflib();

	    p.set_parameter("SearchPath", searchpath);

	    /* This means we must check return values of load_font() etc. */
	    p.set_parameter("errorpolicy", "return");

	    /* We do not create any output document, so no call to
	     * begin_document() is required.
	     */

	    /* Open the input document */
	    if ((doc = p.open_pdi_document(pdfinput, docoptlist)) == -1)
		throw new Exception("Error: " + p.get_errmsg());

	    /* --------- general information (always available) */

	    pcosmode = (int) p.pcos_get_number(doc, "pcosmode");

	    System.out.println("   File name: " + 
	    	p.pcos_get_string(doc,"filename"));

	    System.out.println(" PDF version: " +
		p.pcos_get_number(doc, "pdfversion")/10);

	    System.out.println("  Encryption: " +
		p.pcos_get_string(doc, "encrypt/description"));

	    System.out.println("   Master pw: " +
		((p.pcos_get_number(doc, "encrypt/master") != 0) ? "yes":"no"));

	    System.out.println("     User pw: " +
		((p.pcos_get_number(doc, "encrypt/user") != 0) ? "yes" : "no"));

	    System.out.println("Text copying: " +
		((p.pcos_get_number(doc, "encrypt/nocopy") != 0) ? "no":"yes"));

	    System.out.println("  Linearized: " +
		((p.pcos_get_number(doc, "linearized") != 0) ? "yes" : "no"));

	    System.out.println("      Tagged: " +
		((p.pcos_get_number(doc, "tagged") != 0) ? "yes" : "no") +"\n");

	    if (pcosmode == 0)
	    {
		System.out.println(
		    "Minimum mode: no more information available\n");
		p.delete();
		System.exit(0);
	    }

	    /* --------- more details (requires at least user password) */
	    System.out.println("No. of pages: " +
		(int) p.pcos_get_number(doc, "length:pages"));

	    DecimalFormat page_dim_format = new DecimalFormat();
	    page_dim_format.setMinimumFractionDigits(3);
	    page_dim_format.setMaximumFractionDigits(3);
	    
	    System.out.println(" Page 1 size: width=" + 
		 page_dim_format.format(p.pcos_get_number(doc, "pages[0]/width")) +
		 ", height=" + 
		 page_dim_format.format(p.pcos_get_number(doc, "pages[0]/height")));

	    count = (int) p.pcos_get_number(doc, "length:fonts");
	    System.out.println("No. of fonts: " +  count);

	    for (i=0; i < count; i++)
	    {
		String fonts;

		fonts = "fonts[" + i + "]/embedded";
		if (p.pcos_get_number(doc, fonts) != 0)
		    System.out.print("embedded ");
		else
		    System.out.print("unembedded ");

		fonts = "fonts[" + i + "]/type";
		System.out.print(p.pcos_get_string(doc, fonts) + " font ");
		fonts = "fonts[" + i + "]/name";
		System.out.println(p.pcos_get_string(doc, fonts));
	    }

	    System.out.println("");

	    if (pcosmode == 1)
	    {
		System.out.print(
		    "Restricted mode: no more information available");
		p.delete();
		System.exit(0);
	    }

	    /* ----- document info keys and XMP metadata (requires master pw) */

	    count = (int) p.pcos_get_number(doc, "length:/Info");

	    for (i=0; i < count; i++)
	    {
		String info;
		String key;
		int len;

		info = "type:/Info[" + i + "]";
		objtype = p.pcos_get_string(doc, info);

		info = "/Info[" + i + "].key";
		key = p.pcos_get_string(doc, info);
		len = 12 - key.length();
		while (len-- > 0) System.out.print(" ");

		System.out.print(key + ": ");

		/* Info entries can be stored as string or name objects */
		if (objtype.equals("name") || objtype.equals("string"))
		{
		    info = "/Info[" + i + "]";
		    System.out.println("'" + p.pcos_get_string(doc, info) +
		    					"'");
		}
		else
		{
		    info = "type:/Info[" + i + "]";
		    System.out.println("(" + p.pcos_get_string(doc, info) +
			 " object)");
		}
	    }

	    System.out.print("\n" + "XMP meta data: ");


	    objtype = p.pcos_get_string(doc, "type:/Root/Metadata");
	    if (objtype.equals("stream"))
	    {
		byte[] contents;

		contents = p.pcos_get_stream(doc, "", "/Root/Metadata");
		System.out.println(contents.length + " bytes");
	    }
	    else
	    {
		System.out.println("not present");
	    }

	    p.close_pdi_document(doc);

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
