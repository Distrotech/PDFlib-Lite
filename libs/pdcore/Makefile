# Makefile for libpdcore
# This generates a libtool convenience library
# $Id: Makefile,v 1.86.2.11 2009/12/03 11:35:15 rjs Exp $

top_builddir	= ../..

include ../../config/mkcommon.inc

MAINLIBNAME=nop
LIBNAME 	= $(PDCORELIBLINK)
INCLUDES	= $(PDCORELIBINC) $(PDFLIBINC) $(PDILIBINC) $(FLATELIBINC) \
		  $(EXPATLIBINC) $(OPENSSLLIBINC)

SRC	= \
	$(srcdir)/pc_aes.c     	\
	$(srcdir)/pc_aescbc.c 	\
	$(srcdir)/pc_arc4.c     \
	$(srcdir)/pc_chartabs.c	\
	$(srcdir)/pc_contain.c	\
	$(srcdir)/pc_core.c	\
	$(srcdir)/pc_crypt.c	\
	$(srcdir)/pc_ctype.c	\
	$(srcdir)/pc_digsig.c	\
	$(srcdir)/pc_ebcdic.c	\
	$(srcdir)/pc_encoding.c	\
	$(srcdir)/pc_file.c	\
	$(srcdir)/pc_geom.c	\
	$(srcdir)/pc_md5.c	\
	$(srcdir)/pc_optparse.c	\
	$(srcdir)/pc_output.c	\
	$(srcdir)/pc_resource.c	\
	$(srcdir)/pc_scan.c	\
	$(srcdir)/pc_scope.c	\
	$(srcdir)/pc_string.c	\
	$(srcdir)/pc_unicode.c	\
	$(srcdir)/pc_util.c     \
	$(srcdir)/pc_xmp.c   

include Make_objs.inc
OBJS = $(PDCOREOBJS)

include ../../config/mklibs.inc

pc_geom_no-O.lo: pc_geom.c
	$(LIBTOOL_CC) $(CC) -c $(CPPFLAGS) $(NOOCFLAGS) pc_geom.c -o pc_geom_no-O.o

# Automatically generated dependencies
