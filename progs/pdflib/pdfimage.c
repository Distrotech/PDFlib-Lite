/*---------------------------------------------------------------------------*
 |              PDFlib - A library for generating PDF on the fly             |
 +---------------------------------------------------------------------------+
 | Copyright (c) 1997-2007 Thomas Merz and PDFlib GmbH. All rights reserved. |
 +---------------------------------------------------------------------------+
 |                                                                           |
 |    This software is subject to the PDFlib license. It is NOT in the       |
 |    public domain. Extended versions and commercial licenses are           |
 |    available, please check http://www.pdflib.com.                         |
 |                                                                           |
 *---------------------------------------------------------------------------*/

/* $Id: pdfimage.c,v 1.31.2.3 2008/01/08 15:12:29 kurt Exp $
 *
 * Convert CCITT/BMP/PNG/TIFF/GIF/JPEG/JPX/RAW images to PDF or PDF/A
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#if defined(__CYGWIN32__)
#include <getopt.h>
#elif defined(WIN32)
int getopt(int argc, char * const argv[], const char *optstring);
extern char *optarg;
extern int optind;
#elif !defined(WIN32) && !defined(MAC)
#include <unistd.h>
#endif

#ifdef WIN32
#include <process.h>
#endif

#ifdef NeXT
#include <libc.h>	/* for getopt(), optind, optarg */
#endif

#ifdef __CYGWIN32__
#include <getopt.h>	/* for getopt(), optind, optarg */
#endif

#include "pdflib.h"

/* Activate this to use this program with PDFlib Lite */
/*
#define PDFLIB_LITE
*/

static void
usage(void)
{
    fprintf(stderr,
"\npdfimage: convert images to PDF.\n"
"(c) Thomas Merz and PDFlib GmbH 1997-2007 www.pdflib.com\n"
"\n"
"usage: pdfimage [options] imagefile(s)\n"
"\n"
"Available options:\n"

#ifndef PDFLIB_LITE
"-a level      PDF/A compatibility level: \"PDF/A-1a:2005\" or "
							"\"PDF/A-1b:2005\";\n"
"              \"none\": do not create PDF/A (default)\n"
#endif /* PDFLIB_LITE */

"-g graylevel  fill pages with gray area (useful for transparency testing)\n"

#ifndef PDFLIB_LITE
"-I intent     PDF/A output intent (default: sRGB)\n"
"              none: no intent\n"
"              sRGB: use sRGB ICC profile\n"
"              <filename>: name of an ICC profile\n"
#endif /* PDFLIB_LITE */
"-i <options>  image processing option list for PDF_load_image()\n"
"-o <file>     output file (required)\n"
"-p <num>      create bookmarks with page numbers starting at num\n"
"-r <res>      force resolution overriding image settings\n"
"-t type       force image type (default: auto)\n");

    exit(1);
}

int
main(int argc, char *argv[])
{
    char	*pdffilename = NULL;
    char	*imagetype = "auto";
    char	*useroptions = "";
    PDF		*p;
    int		image;
#ifndef PDFLIB_LITE
    int		tagged, opt;
    int		item=0;
    char 	*pdfalevel = NULL, *intent = "sRGB";
#endif /* PDFLIB_LITE */
    int		resolution = 0;
    int		page_numbering = 0;
    double	graylevel = -1.0;
    int		frame;
    int		current_page = 1;
#define BUFLEN	1024
    char	optlist[BUFLEN];
    char	buf[BUFLEN];

#ifndef PDFLIB_LITE
    while ((opt = getopt(argc, argv, "a:g:I:i:o:p:r:t:")) != -1)
#else
    while ((opt = getopt(argc, argv, "g:i:o:p:r:t:")) != -1)
#endif /* PDFLIB_LITE */
	switch (opt) {
#ifndef PDFLIB_LITE
	    case 'a':
		if (strcmp(optarg, "none"))
		    pdfalevel = optarg;
		break;
#endif /* PDFLIB_LITE */

	    case 'g':
		if (optarg) {
		    graylevel = atof(optarg);
		    if (graylevel < 0.0 || graylevel > 1.0)
		    {
			fprintf(stderr, "Error: Bad gray level %.2g for -g.\n",
				graylevel);
			usage();
		    }
		}
		break;

#ifndef PDFLIB_LITE
	    case 'I':
		if (!strcmp(optarg, "none"))
		    intent = NULL;
		else
		    intent = optarg;
		break;
#endif /* PDFLIB_LITE */

	    case 'i':
		useroptions = optarg;
		if (strlen(useroptions) > BUFLEN-20)
		{
		    fprintf(stderr, "Error: image option list too long.\n");
		    usage();
		}
		break;

	    case 'o':
		pdffilename = optarg;
		break;

	    case 'p':
		page_numbering = 1;
		if (optarg) {
		    current_page = atoi(optarg);
		}
		break;

	    case 'r':
		if (!optarg || (resolution = atoi(optarg)) <= 0) {
		    fprintf(stderr, "Error: non-positive resolution.\n");
		    usage();
		}
		break;

	    case 't':
		imagetype = optarg;
		break;

	    case '?':
	    default:
		usage();
	}

    if (optind == argc) {
	fprintf(stderr, "Error: no image files given.\n");
	usage();
    }

    if (pdffilename == NULL) {
	fprintf(stderr, "Error: no output file given.\n");
	usage();
    }

    if ((p = PDF_new()) == (PDF *) 0)
    {
        fprintf(stderr, "Couldn't create PDFlib object (out of memory)!\n");
	exit(99);
    }

    PDF_TRY(p)
    {
	optlist[0] = 0;

#ifndef PDFLIB_LITE
	tagged = pdfalevel && !strcmp(pdfalevel, "PDF/A-1a:2005");

	if (pdfalevel)
	{
            /* disabled (see bug #1577)
	    if (tagged)
		sprintf(optlist, "pdfa=%s lang=en", pdfalevel);
	    else
            */
		sprintf(optlist, "pdfa=%s", pdfalevel);
	}
#endif /* PDFLIB_LITE */

	if (PDF_begin_document(p, pdffilename, 0, optlist) == -1) {
	    fprintf(stderr, "Error: cannot open output file %s.\n",
		pdffilename);
	    exit(1);
	}

#ifndef PDFLIB_LITE
	if (pdfalevel && intent)
	{
	    if (strcmp("sRGB", intent))
	    {
		sprintf(optlist, "Intent=%s", intent);
		PDF_set_parameter(p, "ICCProfile", optlist);
	    }
	    fprintf(stderr, "Using '%s' as PDF/A output intent.\n", intent);
	    PDF_load_iccprofile(p, intent, 0, "usage=outputintent");
	}

	if (tagged)
	    item = PDF_begin_item(p, "Document",
	    	"Alt={Images converted with pdfimage by PDFlib GmbH}");
#endif /* PDFLIB_LITE */

	PDF_set_info(p, "Creator", "pdfimage");
	PDF_set_parameter(p, "warning", "false");

	while (optind++ < argc)
	{
#ifndef PDFLIB_LITE
	    int item2=0;
#endif /* PDFLIB_LITE */
	    int parent=0;

	    fprintf(stderr, "Processing image file '%s'...", argv[optind-1]);

	    /* process all frames in a multi-page image file */
	    for (frame=1; /* */; frame++)
	    {
		sprintf(optlist, "%s page %d", useroptions, frame);
		image = PDF_load_image(p, imagetype, argv[optind-1],0, optlist);

		if (image == -1) {
		    if (frame == 1)
			fprintf(stderr, "\n%s (skipped).\n", PDF_get_errmsg(p));
		    break;
		}

		/* dummy page size, will be adjusted later */
		PDF_begin_page_ext(p, 20, 20, "");

		if (graylevel >= 0.0)
		{
		    if (pdfalevel)
		    {
			PDF_setcolor(p, "fill",
				"lab", graylevel, 0.0, 0.0, 0.0);
		    }
		    else
		    {
			PDF_setcolor(p, "fill",
				"gray", graylevel, 0.0, 0.0, 0.0);
		    }
		    PDF_rect(p, 0, 0, 10000, 10000);
		    PDF_fill(p);
		}

		/* define outline with filename or page number */
		if (page_numbering)
		{
		    sprintf(buf, "Page %d", current_page++);
		    PDF_create_bookmark(p, buf, 0, "");
		}
		else {
		    if (frame == 1)
		    {
			parent = PDF_create_bookmark(p, argv[optind-1], 0,
						"open");
		    }
		    else
		    {
			sprintf(buf, "page %d", frame);
			sprintf(optlist, "parent=%d", parent);
			PDF_create_bookmark(p, buf, 0, optlist);
		    }
		}

#ifndef PDFLIB_LITE
		if (tagged)
		{
		    /* The file name is the best /Alt value we can provide */
		    sprintf(optlist, "Alt={%s}", argv[optind-1]);
		    item2 = PDF_begin_item(p, "Figure", optlist);
		}
#endif /* PDFLIB_LITE */

		if (resolution != 0)
		    sprintf(optlist, "dpi %d adjustpage", resolution);
		else
		    sprintf(optlist, "adjustpage");

		PDF_fit_image(p, image, 0.0, 0.0, optlist);

#ifndef PDFLIB_LITE
		if (tagged)
		    PDF_end_item(p, item2);
#endif /* PDFLIB_LITE */

		PDF_end_page_ext(p, "");
	    }

	    if (frame > 2)
		fprintf(stderr, "(%d frames)", frame-1);

	    fprintf(stderr, "\n");
	}

#ifndef PDFLIB_LITE
	if (tagged)
	    PDF_end_item(p, item);
#endif /* PDFLIB_LITE */

	PDF_end_document(p, "");
    }

    PDF_CATCH(p)
    {
        printf("\npdfimage: error while creating PDF output (%s(): %s)\n",
		PDF_get_apiname(p), PDF_get_errmsg(p));
        PDF_delete(p);
        exit(99);
    }

    PDF_delete(p);

    exit(0);
}
