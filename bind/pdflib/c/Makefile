# Makefile for PDFlib C samples, C language binding
# $Id: Makefile,v 1.62.2.10 2008/03/19 12:55:33 rjs Exp $

top_builddir	= ../../..

CP	= cp
include ../../../config/mkcommon.inc

DEPLIBS		= $(PDFLIBLINK) $(PDFLIBLINK)
LIBS		= $(DEPLIBS)
INCLUDES	= $(PDFLIBINC) $(PDCORELIBINC)

# the following is platform-specific
DLLIB		= -ldl

# ------------------------------

SRC	= \
	$(srcdir)/chartab.c		\
	$(srcdir)/hello.c		\
	$(srcdir)/hellodl.c		\
	$(srcdir)/image.c		\
	$(srcdir)/pdfclock.c		\
	$(srcdir)/invoice.c		\
	$(srcdir)/businesscard.c	\
	$(srcdir)/quickreference.c

STARTER_SRC	= \
	$(srcdir)/starter_basic.c	\
	$(srcdir)/starter_block.c	\
	$(srcdir)/starter_pcos.c	\
	$(srcdir)/starter_pdfa.c	\
	$(srcdir)/starter_pdfmerge.c	\
	$(srcdir)/starter_pdfx.c	\
	$(srcdir)/starter_table.c	\
	$(srcdir)/starter_tagged.c	\
	$(srcdir)/starter_textflow.c	\
	$(srcdir)/starter_webform.c	\
	$(srcdir)/starter_layer.c	\
	$(srcdir)/starter_pvf.c		\
	$(srcdir)/starter_type3font.c	\
	$(srcdir)/starter_color.c	\
	$(srcdir)/starter_textline.c	\
	$(srcdir)/starter_image.c	\
	$(srcdir)/starter_3d.c	\
	$(srcdir)/starter_graphics.c	

STARTER	= \
	starter_basic$(EXE)	\
	starter_block$(EXE)	\
	starter_pcos$(EXE)	\
	starter_pdfa$(EXE)	\
	starter_pdfmerge$(EXE)	\
	starter_pdfx$(EXE)	\
	starter_table$(EXE)	\
	starter_tagged$(EXE)	\
	starter_textflow$(EXE)	\
	starter_webform$(EXE)	\
	starter_layer$(EXE)	\
	starter_pvf$(EXE)	\
	starter_type3font$(EXE)	\
	starter_color$(EXE)	\
	starter_textline$(EXE)	\
	starter_image$(EXE)	\
	starter_3d$(EXE)	\
	starter_graphics$(EXE)

PROGS = \
	hello$(EXE)		\
	image$(EXE)		\
	pdfclock$(EXE)		\
	chartab$(EXE)		\
	invoice$(EXE)		\
	businesscard$(EXE)	\
	quickreference$(EXE)

include ../../../config/mkprogs.inc

test:: $(PROGS) $(STARTER)
	-.$(PATHSEP)hello
	-.$(PATHSEP)image
	-.$(PATHSEP)pdfclock
	-.$(PATHSEP)chartab
	-.$(PATHSEP)invoice
	-.$(PATHSEP)businesscard
	-.$(PATHSEP)quickreference
	-.$(PATHSEP)starter_basic
	-.$(PATHSEP)starter_block
	-.$(PATHSEP)starter_pcos >starter_pcos.txt
	-.$(PATHSEP)starter_pdfa
	-.$(PATHSEP)starter_pdfmerge
	-.$(PATHSEP)starter_pdfx
	-.$(PATHSEP)starter_table
	-.$(PATHSEP)starter_tagged
	-.$(PATHSEP)starter_textflow
	-.$(PATHSEP)starter_webform
	-.$(PATHSEP)starter_layer
	-.$(PATHSEP)starter_pvf
	-.$(PATHSEP)starter_type3font
	-.$(PATHSEP)starter_color
	-.$(PATHSEP)starter_textline
	-.$(PATHSEP)starter_image
	-.$(PATHSEP)starter_3d
	-.$(PATHSEP)starter_graphics

atstest: test
	$(CP) businesscard.pdf		results$(PATHSEP)busicard.pdf
	$(CP) chartab.pdf		results$(PATHSEP)chartab.pdf
	$(CP) hello.pdf			results$(PATHSEP)hello.pdf
	$(CP) image.pdf			results$(PATHSEP)image.pdf
	$(CP) invoice.pdf		results$(PATHSEP)invoice.pdf
	$(CP) pdfclock.pdf		results$(PATHSEP)pdfclock.pdf
	$(CP) quickreference.pdf	results$(PATHSEP)quickref.pdf
	$(CP) starter_basic.pdf		results$(PATHSEP)basic.pdf
	$(CP) starter_block.pdf		results$(PATHSEP)block.pdf
	$(CP) starter_pdfa.pdf		results$(PATHSEP)pdfa.pdf
	$(CP) starter_pdfmerge.pdf	results$(PATHSEP)pdfmerge.pdf
	$(CP) starter_pdfx.pdf		results$(PATHSEP)pdfx.pdf
	$(CP) starter_table.pdf		results$(PATHSEP)table.pdf
	$(CP) starter_tagged.pdf	results$(PATHSEP)tagged.pdf
	$(CP) starter_textflow.pdf	results$(PATHSEP)textflow.pdf
	$(CP) starter_webform.pdf	results$(PATHSEP)webform.pdf
	$(CP) starter_pcos.txt		results$(PATHSEP)pcos.txt
	$(CP) starter_layer.pdf		results$(PATHSEP)layer.pdf
	$(CP) starter_pvf.pdf		results$(PATHSEP)pvf.pdf
	$(CP) starter_type3font.pdf	results$(PATHSEP)type3font.pdf
	$(CP) starter_color.pdf		results$(PATHSEP)color.pdf
	$(CP) starter_textline.pdf	results$(PATHSEP)textline.pdf
	$(CP) starter_image.pdf		results$(PATHSEP)image.pdf
	$(CP) starter_3d.pdf		results$(PATHSEP)3d.pdf
	$(CP) starter_graphics.pdf	results$(PATHSEP)graphics.pdf

ats:
	..$(PATHSEP)..$(PATHSEP)..$(PATHSEP)intern$(PATHSEP)progs$(PATHSEP)ats$(PATHSEP)ats

clean::
	$(RM) chartab.pdf hello.pdf image.pdf pdfclock.pdf invoice.pdf
	$(RM) hellodl hellodl.pdf businesscard.pdf quickreference.pdf
	$(RM) starter_basic.pdf starter_block.pdf starter_pcos.pdf
	$(RM) starter_pdfa.pdf
	$(RM) starter_pdfmerge.pdf starter_pdfx.pdf starter_table.pdf
	$(RM) starter_tagged.pdf starter_textflow.pdf starter_webform.pdf
	$(RM) starter_basic starter_block starter_pcos starter_pdfa
	$(RM) starter_pdfmerge starter_pdfx starter_table
	$(RM) starter_tagged starter_textflow starter_webform
	$(RM) starter_layer.pdf starter_pvf.pdf starter_type3font.pdf
	$(RM) starter_color.pdf starter_textline.pdf
	$(RM) starter_image.pdf starter_2d.pdf starter_graphics.pdf
	$(RM) $(STARTER)
	$(RM) results

hello$(EXE): hello.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

image$(EXE): image.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

pdfclock$(EXE): pdfclock.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

chartab$(EXE): chartab.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

invoice$(EXE): invoice.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

businesscard$(EXE): businesscard.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

quickreference$(EXE): quickreference.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

hellodl$(EXE): hellodl.c pdflibdl.c $(DEPLIBS) $(DLLIB) pdflibdl.h
	$(PROGS_BUILD) pdflibdl.c $(DLLIB)
	$(PROGS_LINK)

starter_basic$(EXE): starter_basic.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

starter_block$(EXE): starter_block.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

starter_pcos$(EXE): starter_pcos.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

starter_pdfa$(EXE): starter_pdfa.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

starter_pdfmerge$(EXE): starter_pdfmerge.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

starter_pdfx$(EXE): starter_pdfx.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

starter_table$(EXE): starter_table.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

starter_tagged$(EXE): starter_tagged.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

starter_textflow$(EXE): starter_textflow.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

starter_webform$(EXE): starter_webform.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

starter_layer$(EXE): starter_layer.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

starter_pvf$(EXE): starter_pvf.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

starter_type3font$(EXE): starter_type3font.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

starter_color$(EXE): starter_color.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

starter_textline$(EXE): starter_textline.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

starter_image$(EXE): starter_image.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

starter_3d$(EXE): starter_3d.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

starter_graphics$(EXE): starter_graphics.c $(DEPLIBS)
	$(PROGS_BUILD)
	$(PROGS_LINK)

# Automatically generated dependencies
