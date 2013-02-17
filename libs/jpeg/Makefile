# Makefile for tifflib
# This generates a libtool convenience library
# $Id: Makefile,v 1.4.2.3 2008/01/09 20:32:25 rjs Exp $

top_builddir	= ../..

include ../../config/mkcommon.inc

MAINLIBNAME=nop
LIBNAME		= $(JPEGLIBLINK)
INCLUDES	= 

SRC	= \
	$(srcdir)/jcapimin.c	\
	$(srcdir)/jcapistd.c	\
	$(srcdir)/jccoefct.c	\
	$(srcdir)/jccolor.c	\
	$(srcdir)/jcdctmgr.c	\
	$(srcdir)/jchuff.c	\
	$(srcdir)/jcinit.c	\
	$(srcdir)/jcmainct.c	\
	$(srcdir)/jcmarker.c	\
	$(srcdir)/jcmaster.c	\
	$(srcdir)/jcomapi.c	\
	$(srcdir)/jcparam.c	\
	$(srcdir)/jcphuff.c	\
	$(srcdir)/jcprepct.c	\
	$(srcdir)/jcsample.c	\
	$(srcdir)/jctrans.c	\
	$(srcdir)/jdapimin.c	\
	$(srcdir)/jdapistd.c	\
	$(srcdir)/jdatadst.c	\
	$(srcdir)/jdatasrc.c	\
	$(srcdir)/jdcoefct.c	\
	$(srcdir)/jdcolor.c	\
	$(srcdir)/jddctmgr.c	\
	$(srcdir)/jdhuff.c	\
	$(srcdir)/jdinput.c	\
	$(srcdir)/jdmainct.c	\
	$(srcdir)/jdmarker.c	\
	$(srcdir)/jdmaster.c	\
	$(srcdir)/jdmerge.c	\
	$(srcdir)/jdphuff.c	\
	$(srcdir)/jdpostct.c	\
	$(srcdir)/jdsample.c	\
	$(srcdir)/jdtrans.c	\
	$(srcdir)/jerror.c	\
	$(srcdir)/jfdctflt.c	\
	$(srcdir)/jfdctfst.c	\
	$(srcdir)/jfdctint.c	\
	$(srcdir)/jidctflt.c	\
	$(srcdir)/jidctfst.c	\
	$(srcdir)/jidctint.c	\
	$(srcdir)/jidctred.c	\
	$(srcdir)/jmemmgr.c	\
	$(srcdir)/jmemnobs.c	\
	$(srcdir)/jquant1.c	\
	$(srcdir)/jquant2.c	\
	$(srcdir)/jutils.c

include Make_objs.inc
OBJS = $(JPEGOBJS)

include ../../config/mklibs.inc

# Automatically generated dependencies
