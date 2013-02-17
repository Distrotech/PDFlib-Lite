# Makefile for PDFlib's Tcl binding
# $Id: Makefile,v 1.41.2.16 2009/10/23 09:41:42 rjs Exp $

top_builddir	= ../../..

TARGET=Release_MD_VS6

include ../../../config/mkcommon.inc

PDFWALL		=
PDFPEDANTIC	=
DEPLIBS		= $(PDFLIBLINK)
LIBS		= $(DEPLIBS) $(TCLLIB)
INCLUDES	= $(PDFLIBINC) $(TCLINCLUDE)

LANG_LIBDIR 	= $(DESTDIR)$(TCLPACKAGEDIR)

_LIBNAME	= pdflib_tcl
LIBNAME		= pdflib_tcl$(DLL)
OBJ		= pdflib_tcl$(LO)
SRC		= pdflib_tcl.c


include ../../../config/mkbind.inc

test:: all
	@-if test -d .libs; then  	\
	    cp pkgIndex.tcl .libs/; \
	fi
	-$(LIBTOOL_EXE) $(TCLBIN) hello.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) image.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) pdfclock.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) chartab.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) invoice.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) businesscard.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) quickreference.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) starter_basic.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) starter_block.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) starter_color.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) starter_graphics.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) starter_image.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) starter_layer.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) starter_pcos.tcl >starter_pcos.txt
	-$(LIBTOOL_EXE) $(TCLBIN) starter_pdfa.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) starter_pdfmerge.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) starter_pdfx.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) starter_pvf.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) starter_table.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) starter_tagged.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) starter_textflow.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) starter_textline.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) starter_type3font.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) starter_webform.tcl
	-$(LIBTOOL_EXE) $(TCLBIN) starter_3d.tcl

pdfcheck:
	../../../progs/pdi/pdfcheck -i ../java/starter.ref -o -

install:: $(LIBNAME)
	if test ! -d $(LANG_LIBDIR) ; then 	\
	    mkdir -p $(LANG_LIBDIR);		\
	    chmod 755 $(LANG_LIBDIR);		\
	fi
	$(INSTALL_DATA) pkgIndex.tcl $(LANG_LIBDIR)
	@-if test -f .libs/libpdflib_tcl.dylib; then			\
	    $(INSTALL_DATA) .libs/pdflib_tcl.dylib $(LANG_LIBDIR);	\
	else								\
	    $(LIBTOOL) --mode=install $(INSTALL_DATA)			\
		$(LIBNAME) $(LANG_LIBDIR);				\
	fi

uninstall::
	@-if test -f .libs/libpdflib_tcl.dylib; then			\
	    $(LIBTOOL) --mode=uninstall $(RM)				\
		$(LANG_LIBDIR)/pdflib_tcl.dylib				\
		$(LANG_LIBDIR)/pkgIndex.tcl;				\
	else								\
	    $(LIBTOOL) --mode=uninstall $(RM)				\
		$(LANG_LIBDIR)/$(LIBNAME)				\
		$(LANG_LIBDIR)/pkgIndex.tcl;				\
	fi
	$(RM) $(LANG_LIBDIR)

clean::
	$(RM) hello.pdf image.pdf pdfclock.pdf chartab.pdf invoice.pdf
	$(RM) businesscard.pdf quickreference.pdf

# Automatically generated dependencies
