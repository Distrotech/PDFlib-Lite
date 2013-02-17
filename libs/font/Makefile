# Makefile for libfont
# This generates a libtool convenience library
# $Id: Makefile,v 1.11.2.5 2008/04/15 20:35:52 rjs Exp $

top_builddir	= ../..

include ../../config/mkcommon.inc

MAINLIBNAME=nop
LIBNAME 	= $(FONTLIBLINK)
INCLUDES	= $(FONTLIBINC) $(PDCORELIBINC) $(PDILIBINC) $(FLATELIBINC)

SRC	= \
	$(srcdir)/ft_cid.c	\
	$(srcdir)/ft_corefont.c	\
	$(srcdir)/ft_font.c	\
	$(srcdir)/ft_hostfont.c	\
	$(srcdir)/ft_pdffont.c	\
	$(srcdir)/ft_truetype.c \
	$(srcdir)/ft_type1.c

include Make_objs.inc
OBJS = $(FONTOBJS)

include ../../config/mklibs.inc

# Automatically generated dependencies
