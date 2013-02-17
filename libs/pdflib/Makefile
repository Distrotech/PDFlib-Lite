# Makefile for PDFlib
# $Id: Makefile,v 1.159.2.12 2009/04/03 09:51:19 rjs Exp $

top_builddir	= ../..

include ../../config/mkcommon.inc

INCLUDES	= $(PDFLIBINC) $(PDCORELIBINC) $(TIFFLIBINC) $(FLATELIBINC)\
		  $(PNGLIBINC) $(PDILIBINC) $(PLOPLIBINC) $(JPEGLIBINC) \
		  $(FONTLIBINC) $(EXPATLIBINC)

LIBNAME		= $(PDFLIB_LINK)

SRC	= \
	$(srcdir)/p_3d.c      \
	$(srcdir)/p_actions.c   \
	$(srcdir)/p_afm.c       \
	$(srcdir)/p_annots.c	\
	$(srcdir)/p_block.c     \
	$(srcdir)/p_bmp.c	\
	$(srcdir)/p_ccitt.c	\
	$(srcdir)/p_cid.c	\
	$(srcdir)/p_color.c	\
	$(srcdir)/p_document.c	\
	$(srcdir)/p_draw.c	\
	$(srcdir)/p_encoding.c	\
	$(srcdir)/p_fields.c    \
	$(srcdir)/p_filter.c    \
	$(srcdir)/p_font.c	\
	$(srcdir)/p_gif.c	\
	$(srcdir)/p_gstate.c	\
	$(srcdir)/p_hyper.c	\
	$(srcdir)/p_icc.c	\
	$(srcdir)/p_icclib.c	\
	$(srcdir)/p_image.c	\
	$(srcdir)/p_jpeg.c	\
	$(srcdir)/p_jpx.c	\
	$(srcdir)/p_kerning.c   \
	$(srcdir)/p_layer.c     \
	$(srcdir)/p_mbox.c     \
	$(srcdir)/p_object.c    \
	$(srcdir)/p_opi.c       \
	$(srcdir)/p_page.c	\
	$(srcdir)/p_params.c	\
	$(srcdir)/p_pattern.c	\
	$(srcdir)/p_pdi.c	\
	$(srcdir)/p_pfm.c	\
	$(srcdir)/p_photoshp.c	\
	$(srcdir)/p_png.c	\
	$(srcdir)/p_shading.c	\
	$(srcdir)/p_subsett.c	\
	$(srcdir)/p_table.c	\
	$(srcdir)/p_tagged.c	\
	$(srcdir)/p_template.c	\
	$(srcdir)/p_text.c	\
	$(srcdir)/p_textflow.c	\
	$(srcdir)/p_tiff.c      \
	$(srcdir)/p_truetype.c	\
	$(srcdir)/p_type1.c	\
	$(srcdir)/p_type3.c	\
	$(srcdir)/p_util.c      \
	$(srcdir)/p_xgstate.c	\
	$(srcdir)/p_xmp.c

include Make_objs.inc
OBJS = $(PDFLIBOBJS)

include ../../config/mklibs.inc

WINVERS 	= "7.0"
MAINLIB 	= pdf
MAINLIBNAME	= lib$(PDFLIBNAME)$(LA)
MAINSRC		= $(srcdir)/pdflib.c
MAINOBJ		= $(OO)$(PATHSEP)pdflib$(LO)
MAININC		= pdflib.h

INTERNALLIBS	= $(PDFLIB_LINK) $(PDILIBLINK) $(FONTLIBLINK) \
		  $(PLOPLIB_LINK) $(PDPAGELIBLINK) $(PDCORELIBLINK) \
		  $(PNGLIBLINK) $(FLATELIBLINK) $(TIFFLIBLINK) $(JPEGLIBLINK) \
		  $(EXPATLIBLINK)
INTERNALOBJS  = $(PDFLIB_OBJS) $(PDI_OBJS) $(FONT_OBJS) $(PLOP_OBJS) \
		$(PDPAGE_OBJS) $(PDCORE_OBJS) $(PNG_OBJS) $(FLATE_OBJS) \
		$(TIFF_OBJS) $(JPEG_OBJS) $(EXPAT_OBJS)

include Make_objs2.inc

include ../../config/mkmainlib.inc

clean::
	$(RM) $(MAINOBJ)

# Automatically generated dependencies
