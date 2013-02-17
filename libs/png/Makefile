# Makefile for libpng 1.2.5
# This generates a libtool convenience library
# $Id: Makefile,v 1.30.2.4 2008/01/09 20:32:27 rjs Exp $

top_builddir	= ../..

include ../../config/mkcommon.inc

MAINLIBNAME=nop
LIBNAME		= $(PNGLIBLINK)
INCLUDES	= $(ZLIBINC) $(PDCORELIBINC)

SRC	= \
	$(srcdir)/png.c	\
	$(srcdir)/pngset.c	\
	$(srcdir)/pngget.c	\
	$(srcdir)/pngrutil.c	\
	$(srcdir)/pngtrans.c	\
	$(srcdir)/pngread.c	\
	$(srcdir)/pngrio.c	\
	$(srcdir)/pngrtran.c	\
	$(srcdir)/pngmem.c	\
	$(srcdir)/pngerror.c

include Make_objs.inc
OBJS = $(PNGOBJS)

include ../../config/mklibs.inc

# Automatically generated dependencies
