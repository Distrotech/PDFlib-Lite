# Makefile for PDFlib,  C++ language binding
# $Id: Makefile,v 1.53.2.9 2008/02/20 21:47:01 rjs Exp $

top_builddir	= ../../..

include ../../../config/mkcommon.inc

DEPLIBS		= $(PDFLIBLINK) pdflib$(LO)
LIBS		= $(DEPLIBS) $(STDCPP)
INCLUDES	= $(PDFLIBINC)

# --------------------------------------------------------------------------

SRC	= \
	$(srcdir)/pdflib.cpp		\
	$(srcdir)/hello.cpp		\
	$(srcdir)/image.cpp		\
	$(srcdir)/pdfclock.cpp		\
	$(srcdir)/chartab.cpp		\
	$(srcdir)/invoice.cpp		\
	$(srcdir)/businesscard.cpp	\
	$(srcdir)/quickreference.cpp

PROGS = \
	hello$(EXE)		\
	image$(EXE)		\
	pdfclock$(EXE)		\
	chartab$(EXE)		\
	invoice$(EXE)		\
	businesscard$(EXE)	\
	quickreference$(EXE)    \
	starter_basic$(EXE)	\
	starter_block$(EXE)	\
	starter_color$(EXE)	\
	starter_graphics$(EXE)	\
	starter_image$(EXE)	\
	starter_layer$(EXE)	\
	starter_pcos$(EXE)	\
	starter_pdfa$(EXE)	\
	starter_pdfmerge$(EXE)	\
	starter_pdfx$(EXE)	\
	starter_pvf$(EXE)	\
	starter_table$(EXE)	\
	starter_tagged$(EXE)	\
	starter_textflow$(EXE)	\
	starter_textline$(EXE)	\
	starter_type3font$(EXE)	\
	starter_webform$(EXE)	\
	starter_3d$(EXE)

include ../../../config/mkprogs.inc


test:: $(PROGS)
	-.$(PATHSEP)hello
	-.$(PATHSEP)image
	-.$(PATHSEP)pdfclock
	-.$(PATHSEP)chartab
	-.$(PATHSEP)invoice
	-.$(PATHSEP)businesscard
	-.$(PATHSEP)quickreference
	-.$(PATHSEP)starter_basic
	-.$(PATHSEP)starter_block
	-.$(PATHSEP)starter_color
	-.$(PATHSEP)starter_graphics
	-.$(PATHSEP)starter_image
	-.$(PATHSEP)starter_layer
	-.$(PATHSEP)starter_pcos >starter_pcos.txt
	-.$(PATHSEP)starter_pdfa
	-.$(PATHSEP)starter_pdfmerge
	-.$(PATHSEP)starter_pdfx
	-.$(PATHSEP)starter_pvf
	-.$(PATHSEP)starter_table
	-.$(PATHSEP)starter_tagged
	-.$(PATHSEP)starter_textflow
	-.$(PATHSEP)starter_textline
	-.$(PATHSEP)starter_type3font
	-.$(PATHSEP)starter_webform
	-.$(PATHSEP)starter_3d

clean::
	$(RM) hello.pdf image.pdf pdfclock.pdf chartab.pdf invoice.pdf
	$(RM) businesscard.pdf quickreference.pdf starter*.pdf


hello$(EXE): hello.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

image$(EXE): image.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

pdfclock$(EXE): pdfclock.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

chartab$(EXE): chartab.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

invoice$(EXE): invoice.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

businesscard$(EXE): businesscard.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

quickreference$(EXE): quickreference.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

starter_basic$(EXE): starter_basic.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

starter_block$(EXE): starter_block.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

starter_color$(EXE): starter_color.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

starter_graphics$(EXE): starter_graphics.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

starter_image$(EXE): starter_image.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

starter_layer$(EXE): starter_layer.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

starter_pcos$(EXE): starter_pcos.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

starter_pdfa$(EXE): starter_pdfa.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

starter_pdfmerge$(EXE): starter_pdfmerge.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

starter_pdfx$(EXE): starter_pdfx.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

starter_pvf$(EXE): starter_pvf.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

starter_table$(EXE): starter_table.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

starter_tagged$(EXE): starter_tagged.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

starter_textflow$(EXE): starter_textflow.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

starter_textline$(EXE): starter_textline.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

starter_type3font$(EXE): starter_type3font.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

starter_webform$(EXE): starter_webform.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

starter_3d$(EXE): starter_3d.cpp $(DEPLIBS)
	$(CXXPROGS_BUILD)
	$(CXXPROGS_LINK)

pdflib$(LO): ./pdflib.cpp pdflib.hpp ../../../libs/pdflib/pdflib.h
	$(LIBTOOL_CC) $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) pdflib.cpp

# Automatically generated dependencies
