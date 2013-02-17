# Makefile for PDFlib's Python binding
# $Id: Makefile,v 1.41.2.12 2008/02/22 16:09:27 rjs Exp $

top_builddir	= ../../..

include ../../../config/mkcommon.inc

DEPLIBS		= $(PDFLIBLINK)
LIBS		= $(DEPLIBS)
INCLUDES	= $(PDFLIBINC) $(PYINCLUDE) $(PDCORELIBINC)
# special CFLAGS, as -ansi is not working here.
PDFPEDANTIC	= 

LANG_LIBDIR 	= $(DESTDIR)$(PYTHONLIBDIR)

_LIBNAME	= pdflib_py
LIBNAME		= pdflib_py$(DLL)
OBJ		= pdflib_py$(LO)
SRC		= pdflib_py.c \
		  py_wrapped.c


include ../../../config/mkbind.inc

test:: all
	@-(. ./pdflib_py$(LA); cd .libs; cp $$library_names ..)
	@-(cp pdflib_py.dylib pdflib_py.so)
	-$(LIBTOOL_EXE) python hello.py
	-$(LIBTOOL_EXE) python image.py
	-$(LIBTOOL_EXE) python pdfclock.py
	-$(LIBTOOL_EXE) python chartab.py
	-$(LIBTOOL_EXE) python invoice.py
	-$(LIBTOOL_EXE) python businesscard.py
	-$(LIBTOOL_EXE) python quickreference.py
	-$(LIBTOOL_EXE) python starter_basic.py
	-$(LIBTOOL_EXE) python starter_block.py
	-$(LIBTOOL_EXE) python starter_pcos.py >starter_pcos.txt
	-$(LIBTOOL_EXE) python starter_pdfa.py
	-$(LIBTOOL_EXE) python starter_pdfmerge.py
	-$(LIBTOOL_EXE) python starter_pdfx.py
	-$(LIBTOOL_EXE) python starter_table.py
	-$(LIBTOOL_EXE) python starter_tagged.py
	-$(LIBTOOL_EXE) python starter_textflow.py
	-$(LIBTOOL_EXE) python starter_webform.py
	-$(LIBTOOL_EXE) python starter_3d.py
	-$(LIBTOOL_EXE) python starter_pvf.py
	-$(LIBTOOL_EXE) python starter_graphics.py
	-$(LIBTOOL_EXE) python starter_image.py
	-$(LIBTOOL_EXE) python starter_textline.py
	-$(LIBTOOL_EXE) python starter_color.py
	-$(LIBTOOL_EXE) python starter_type3font.py
	-$(LIBTOOL_EXE) python starter_layer.py


pdfcheck:
	../../../progs/pdi/pdfcheck -i ../java/starter.ref -o -

install:: $(LIBNAME)
	@-if test -f libpdflib_py.dylib; then		\
	    $(INSTALL_DATA) .libs/pdflib_py.so $(LANG_LIBDIR);	\
	else							\
	    $(LIBTOOL) --mode=install $(INSTALL_DATA) 		\
		$(LIBNAME) $(LANG_LIBDIR);			\
	fi

uninstall::
	@-if test -f .libs/libpdflib_py.dylib; then			 \
	    $(LIBTOOL) --mode=uninstall $(RM) $(LANG_LIBDIR)/pdflib_py.so\
	else 								 \
	    $(LIBTOOL) --mode=uninstall $(RM) $(LANG_LIBDIR)/$(LIBNAME) \
	fi

clean::
	@-if test -f pdflib_py.la; then			\
	    (. ./pdflib_py.la; $(RM) $$library_names)	\
	fi
	$(RM) libpdflib_py.* pdflib_py.so*
	$(RM) hello.pdf image.pdf pdfclock.pdf chartab.pdf invoice.pdf
	$(RM) businesscard.pdf quickreference.pdf
	$(RM) starter_basic.pdf	starter_pdfa.pdf
	$(RM) starter_pdfmerge.pdf starter_pdfx.pdf starter_table.pdf
	$(RM) starter_tagged.pdf starter_textflow.pdf 
	$(RM) starter_webform.pdf starter_block.pdf starter_pcos.txt
	$(RM) python21 python22 python23 python24 python25
	$(RM) pythonas23 pythonAS23 pythonAS24 pythonAS25
	$(RM) starter_pvf.pdf starter_graphics.pdf starter_image.pdf
	$(RM) starter_textline.pdf starter_color.pdf starter_type3font.pdf
	$(RM) starter_layer.pdf starter_3d.pdf

distclean::

# Automatically generated dependencies
