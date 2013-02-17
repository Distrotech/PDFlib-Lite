<%@page import="java.io.*, javax.servlet.*, com.pdflib.pdflib" %><%

   /* $Id: businesscard.jsp,v 1.12 2004/05/17 12:46:42 rp Exp $
    *
    * businesscard.jsp
    */


    int font;
    pdflib p = null ;
    int i, blockcontainer, pdipage;
    String infile = "boilerplate.pdf";
    /* This is where font/image/PDF input files live. Adjust as necessary.
     *
     * Note that this directory must also contain the LuciduxSans font
     * outline and metrics files.
     */
    String searchpath = "../data";
    String[][] data = {
	{ "name",                   "Victor Kraxi" },
	{ "business.title",         "Chief Paper Officer" },
	{ "business.address.line1", "17, Aviation Road" },
	{ "business.address.city",  "Paperfield" },
	{ "business.telephone.voice","phone +1 234 567-89" },
	{ "business.telephone.fax", "fax +1 234 567-98" },
	{ "business.email",         "victor@kraxi.com" },
	{ "business.homepage",      "www.kraxi.com" },
	};

    byte[] buf;
    ServletOutputStream output;

    p = new pdflib();

    // Generate a PDF in memory; insert a file name to create PDF on disk
    if (p.begin_document("","") == -1) {
        System.err.println("Error: " + p.get_errmsg());
	System.exit(1);
    }

    /* Set the search path for fonts and PDF files */
    p.set_parameter("SearchPath", searchpath);

    p.set_info("Creator", "businesscard.jsp");
    p.set_info("Author", "Rainer Ploeckl");
    p.set_info("Title","PDFlib block processing sample (JSP)");

    blockcontainer = p.open_pdi(infile, "", 0);
    if (blockcontainer == -1) {
        System.err.println("Error: " + p.get_errmsg());
	System.exit(1);
    }

    pdipage = p.open_pdi_page(blockcontainer, 1, "");
    if (pdipage == -1) {
        System.err.println("Error: " + p.get_errmsg());
	System.exit(1);
    }

    p.begin_page_ext(20, 20, "");              // dummy page size

    // This will adjust the page size to the block container's size.
    p.fit_pdi_page(pdipage, 0, 0, "adjustpage");

    // Fill all text blocks with dynamic data 
    for (i = 0; i < (int) data.length; i++) {
	if (p.fill_textblock(pdipage, data[i][0], data[i][1],
		"embedding encoding=unicode") == -1) {
	    System.err.println("Warning: " + p.get_errmsg());
	}
    }

    p.end_page_ext("");                        // close page
    p.close_pdi_page(pdipage);

    p.end_document("");                           // close PDF document
    p.close_pdi(blockcontainer);

    buf = p.get_buffer();

    response.setContentType("application/pdf");
    response.setContentLength(buf.length);

    output = response.getOutputStream();
    output.write(buf);
    output.close();
%>
