# Makefile for PDFlib's Perl binding
# $Id: Makefile,v 1.48.2.11 2008/02/20 22:06:41 rjs Exp $

top_builddir	= ../../..

CP	= cp
include ../../../config/mkcommon.inc

DEPLIBS		= $(PDFLIBLINK)
LIBS		= $(DEPLIBS)
INCLUDES	= $(PDFLIBINC) $(PERLBOOLDEF) $(PERLINCLUDE)
# special CFLAGS, as -ansi is not working here.
PDFPEDANTIC	=

PERLBIN		= $(PERL) -I. -I.libs
LANG_LIBDIR 	= $(DESTDIR)$(PERLLIBDIR)
BINDEXTERNALLIBS= $(PERLLINK)

_LIBNAME	= pdflib_pl
LIBNAME		= pdflib_pl$(DLL)
OBJ		= pdflib_pl$(LO)
SRC		= pdflib_pl.c

include ../../../config/mkbind.inc

test:: all
	-$(PERLBIN) hello.pl
	-$(PERLBIN) image.pl
	-$(PERLBIN) pdfclock.pl
	-$(PERLBIN) chartab.pl
	-$(PERLBIN) invoice.pl
	-$(PERLBIN) businesscard.pl
	-$(PERLBIN) quickreference.pl
	-$(PERLBIN) starter_basic.pl
	-$(PERLBIN) starter_block.pl
	-$(PERLBIN) starter_pcos.pl >starter_pcos.txt
	-$(PERLBIN) starter_pdfa.pl
	-$(PERLBIN) starter_pdfmerge.pl
	-$(PERLBIN) starter_pdfx.pl
	-$(PERLBIN) starter_table.pl
	-$(PERLBIN) starter_tagged.pl
	-$(PERLBIN) starter_textflow.pl
	-$(PERLBIN) starter_webform.pl
	-$(PERLBIN) starter_3d.pl
	-$(PERLBIN) starter_layer.pl
	-$(PERLBIN) starter_pvf.pl
	-$(PERLBIN) starter_type3font.pl
	-$(PERLBIN) starter_color.pl
	-$(PERLBIN) starter_textline.pl
	-$(PERLBIN) starter_image.pl
	-$(PERLBIN) starter_graphics.pl


pdfcheck:
	../../../progs/pdi/pdfcheck -i ../java/starter.ref -o -

install:: $(LIBNAME)
	$(LIBTOOL) --mode=install \
		$(INSTALL_DATA) $(LIBNAME) $(LANG_LIBDIR)
	$(INSTALL_DATA) pdflib_pl.pm $(LANG_LIBDIR)

uninstall::
	$(LIBTOOL) --mode=uninstall \
		$(RM) $(LANG_LIBDIR)/$(LIBNAME) $(LANG_LIBDIR)/pdflib_pl.pm

atstest: test
	$(CP) businesscard.pdf		results/busicard.pdf
	$(CP) chartab.pdf		results/chartab.pdf
	$(CP) hello.pdf			results/hello.pdf
	$(CP) image.pdf			results/image.pdf
	$(CP) invoice.pdf		results/invoice.pdf
	$(CP) pdfclock.pdf		results/pdfclock.pdf
	$(CP) quickreference.pdf	results/quickref.pdf
	$(CP) starter_basic.pdf		results/basic.pdf
	$(CP) starter_block.pdf		results/block.pdf
	$(CP) starter_pdfa.pdf		results/pdfa.pdf
	$(CP) starter_pdfmerge.pdf	results/pdfmerge.pdf
	$(CP) starter_pdfx.pdf		results/pdfx.pdf
	$(CP) starter_table.pdf		results/table.pdf
	$(CP) starter_tagged.pdf	results/tagged.pdf
	$(CP) starter_textflow.pdf	results/textflow.pdf
	$(CP) starter_webform.pdf	results/webform.pdf
	$(CP) starter_3d.pdf		results/3d.pdf
	$(CP) starter_layer.pdf		results/layer.pdf
	$(CP) starter_pvf.pdf		results/pvf.pdf
	$(CP) starter_type3font.pdf	results/type3font.pdf
	$(CP) starter_color.pdf		results/color.pdf
	$(CP) starter_textline.pdf	results/textline.pdf
	$(CP) starter_image.pdf		results/image.pdf
	$(CP) starter_graphics.pdf	results/graphics.pdf
	$(CP) starter_pcos.txt		results/pcos.txt

ats:
	../../../intern/progs/ats/ats -t ../c/testtab.txt

clean::
	$(RM) hello.pdf image.pdf pdfclock.pdf chartab.pdf invoice.pdf
	$(RM) businesscard.pdf quickreference.pdf
	$(RM) starter_basic.pdf	starter_pdfa.pdf
	$(RM) starter_pdfmerge.pdf starter_pdfx.pdf starter_table.pdf
	$(RM) starter_tagged.pdf starter_textflow.pdf 
	$(RM) starter_webform.pdf starter_block.pdf starter_pcos.txt
	$(RM) starter_layer.pdf starter_pvf.pdf starter_type3font.pdf
	$(RM) starter_graphics.pdf starter_color.pdf starter_textline.pdf
	$(RM) starter_3d.pdf starter_image.pdf
	$(RM) perl56 perl58 perlAS56 perlAS58 results

distclean::


# Automatically generated dependencies
