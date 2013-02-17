# Makefile for PDFlib clients
# $Id: Makefile,v 1.39.2.14 2008/08/07 22:12:12 rjs Exp $

top_builddir    = ../..

include ../../config/mkcommon.inc

INCLUDES        = $(PDFLIBINC) $(PDCORELIBINC) $(FONTLIBINC) $(CLLIBINC)
LIBS            = $(PDFLIBLINK) $(CLLIBLINK)
EXTRA_SOURCES   = getopt.c
EXTRA_OBJS	= getopt$(LO)

# ------------------------------

SRC     = \
        $(srcdir)/pdfimpose.c   \
        $(srcdir)/pdfimage.c    \
        $(srcdir)/text2pdf.c

PROGS   = \
        pdfimpose$(EXE) \
        pdfimage$(EXE) \
        text2pdf$(EXE)

include ../../config/mkprogs.inc

pdfimpose$(EXE): pdfimpose.c $(LIBS) $(EXTRA_OBJS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

pdfimage$(EXE): pdfimage.c $(LIBS) $(EXTRA_OBJS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

text2pdf$(EXE): text2pdf.c $(LIBS) $(EXTRA_OBJS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

install:: pdfimage text2pdf
	mkdir -p $(DESTDIR)$(bindir)
	$(INSTALL) pdfimage text2pdf $(DESTDIR)$(bindir)

# Automatically generated dependencies
