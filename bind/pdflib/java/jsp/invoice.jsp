<%@page import="java.io.*, 
		javax.servlet.*, 
		java.text.*, 
		java.util.*,
		com.pdflib.pdflib"
		%><%

   /* $Id: invoice.jsp,v 1.14 2004/10/26 14:14:44 rp Exp $
    *
    * invoice.jsp
    */

    pdflib p = null ;
    int         i, stationery, pdipage, regularfont, boldfont;
    String      infile = "stationery.pdf";
    /* This is where font/image/PDF input files live. Adjust as necessary.*/
    String      searchpath = "../data";
    final float left = 55;
    final float right = 530;
    float       fontsize = 12, leading, y;
    float       sum, total;
    float       pagewidth = 595, pageheight = 842;
    String      buf, optlist;
    String      baseopt =
		    "ruler        {   30 45     275   375   475} " +
		    "tabalignment {right left right right right} " +
		    "hortabmethod ruler fontsize 12 ";
     
    int textflow;
 

    Date now = new Date();
    DateFormat fulldate = DateFormat.getDateInstance(DateFormat.LONG);

    byte[] bufout;
    ServletOutputStream output;

    String      closingtext =
	"Terms of payment: <fillcolor={rgb 1 0 0}>30 days net. " +
	"<fillcolor={gray 0}>90 days warranty starting at the day of sale. " +
	"This warranty covers defects in workmanship only. " +
	"<fontname=Helvetica-BoldOblique encoding=host>Kraxi Systems, Inc. " +
	"<resetfont>will, at its option, repair or replace the " +
	"product under the warranty. This warranty is not transferable. " +
	"No returns or exchanges will be accepted for wet products.";

    String[][] data = {
	{ "Super Kite",         "20",     "2"},
	{ "Turbo Flyer",        "40",     "5"},
	{ "Giga Trash",         "180",    "1"},
	{ "Bare Bone Kit",      "50",     "3"},
	{ "Nitty Gritty",       "20",     "10"},
	{ "Pretty Dark Flyer",  "75",     "1"},
	{ "Free Gift",          "0",      "1"},
    };

    String[] months = {
	"January", "February", "March", "April", "May", "June",
	"July", "August", "September", "October", "November", "December"
    };

    p = new pdflib();

    // Generate a PDF in memory; insert a file name to create PDF on disk
    if (p.begin_document("", "") == -1) {
        System.err.println("Error: " + p.get_errmsg());
	System.exit(1);
    }

    p.set_parameter("SearchPath", searchpath);

    p.set_info("Creator", "invoice.jsp");
    p.set_info("Author", "Rainer Ploeckl");
    p.set_info("Title", "PDFlib invoice generation demo (Java/JSP)");

    stationery = p.open_pdi(infile, "", 0);
    if (stationery == -1) {
	System.err.println("Couldn't open infile '" + infile + "'.\n");
	System.exit(1);
    }

    pdipage = p.open_pdi_page(stationery, 1, "");
    if (pdipage == -1) {
	System.err.println("Error: " + p.get_errmsg());
	System.exit(1);
    }

    boldfont = p.load_font("Helvetica-Bold", "unicode", "");
    regularfont = p.load_font("Helvetica", "unicode", "");
    leading = fontsize + 2;

    // Establish coordinates with the origin in the upper left corner.
    p.begin_page_ext(pagewidth, pageheight, "topdown");

    p.fit_pdi_page(pdipage, 0, pageheight, "");
    p.close_pdi_page(pdipage);

    p.setfont(regularfont, fontsize);

    // Print the address
    y = 170;
    p.set_value("leading", leading);

    p.show_xy("John Q. Doe", left, y);
    p.continue_text("255 Customer Lane");
    p.continue_text("Suite B");
    p.continue_text("12345 User Town");
    p.continue_text("Everland");

    // Print the header and date

    p.setfont(boldfont, fontsize);
    y = 300;
    p.show_xy("INVOICE", left, y);

    p.fit_textline(fulldate.format(now), right, y, "position {100 0}");

    // Print the invoice header line

    y = 370;

    buf = "\tITEM\tDESCRIPTION\tQUANTITY\tPRICE\tAMOUNT";
    optlist = baseopt + " font " + boldfont;

    textflow = p.create_textflow(buf, optlist);

    if (textflow == -1) {
	System.err.println("Error: " + p.get_errmsg());
	System.exit(1);
    }

    p.fit_textflow(textflow, left, y-leading, right, y, "");
    p.delete_textflow(textflow);


    // Print the article list

    y += 2*leading;
    total = 0;
    optlist = baseopt + " font " + regularfont;

    for (i = 0; i < data.length; i++) {
	sum = Integer.parseInt(data[i][2]) * Integer.parseInt(data[i][1]);
	buf = "\t" + Integer.toString(i+1) + "\t" +data[i][0] + "\t" +
	    data[i][2] + "\t" + data[i][1] + "\t" + Float.toString(sum);
	textflow = p.create_textflow(buf, optlist);

	if (textflow == -1) {
	    System.err.println("Error: " + p.get_errmsg());
	    System.exit(1);
	}
	p.fit_textflow(textflow, left, y-leading, right, y, "");
	p.delete_textflow(textflow);

	y += leading;
	total += sum;
    }

    y += leading;
    p.setfont(boldfont, fontsize);
    p.fit_textline(Float.toString(total), right, y, "position {100 0}");

    // Print the closing text

    y += 5*leading;
    optlist = "alignment=justify leading=120% " +
	    "fontname=Helvetica fontsize=12 encoding=unicode ";

    textflow = p.create_textflow(closingtext, optlist);

    if (textflow == -1) {
	System.err.println("Error: " + p.get_errmsg());
	System.exit(1);
    }

    p.fit_textflow(textflow, left, y+6*leading, right, y, "");
    p.delete_textflow(textflow);
    p.end_page_ext("");
    p.end_document("");

    p.close_pdi(stationery);

    bufout = p.get_buffer();

    response.setContentType("application/pdf");
    response.setContentLength(bufout.length);

    output = response.getOutputStream();
    output.write(bufout);
    output.close();
%>
