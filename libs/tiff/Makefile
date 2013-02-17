# Makefile for tifflib
# This generates a libtool convenience library
# $Id: Makefile,v 1.50.2.7 2008/04/15 20:35:54 rjs Exp $

top_builddir	= ../..

include ../../config/mkcommon.inc

MAINLIBNAME=nop
LIBNAME		= $(TIFFLIBLINK)
INCLUDES	= $(PDCORELIBINC) $(FLATELIBINC) $(JPEGLIBINC) $(TIFFWRITE)

SRC	= \
	$(srcdir)/tif_auxx.c		\
	$(srcdir)/tif_close.c		\
	$(srcdir)/tif_codec.c		\
	$(srcdir)/tif_color.c		\
	$(srcdir)/tif_compress.c	\
	$(srcdir)/tif_dir.c		\
	$(srcdir)/tif_dirinfo.c		\
	$(srcdir)/tif_dirread.c		\
	$(srcdir)/tif_dirwrite.c	\
	$(srcdir)/tif_dumpmode.c	\
	$(srcdir)/tif_error.c		\
	$(srcdir)/tif_extension.c	\
	$(srcdir)/tif_fax3.c		\
	$(srcdir)/tif_fax3sm.c		\
	$(srcdir)/tif_flush.c		\
	$(srcdir)/tif_getimage.c	\
	$(srcdir)/tif_jpeg.c		\
	$(srcdir)/tif_luv.c		\
	$(srcdir)/tif_lzw.c		\
	$(srcdir)/tif_next.c		\
	$(srcdir)/tif_ojpeg.c		\
	$(srcdir)/tif_open.c		\
	$(srcdir)/tif_packbits.c	\
	$(srcdir)/tif_predict.c		\
	$(srcdir)/tif_print.c		\
	$(srcdir)/tif_read.c		\
	$(srcdir)/tif_strip.c		\
	$(srcdir)/tif_swab.c		\
	$(srcdir)/tif_tile.c		\
	$(srcdir)/tif_unix.c		\
	$(srcdir)/tif_version.c		\
	$(srcdir)/tif_warning.c		\
	$(srcdir)/tif_write.c		\
	$(srcdir)/tif_zip.c

# unused modules
#mkg3states.c mkspans.c
#$(srcdir)/tif_thunder.c
#$(srcdir)/tif_pixarlog.c

include Make_objs.inc
OBJS = $(TIFFOBJS)

include ../../config/mklibs.inc

# Automatically generated dependencies
