# Makefile for zlib
# This generates a libtool convenience library
# $Id: Makefile,v 1.27.2.11 2008/05/27 14:22:28 rjs Exp $

top_builddir	= ../..

INCLUDES	= $(PDCORELIBINC)

MAINLIBNAME=nop
LIBNAME = $(FLATELIBLINK)

CP = cp
include ../../config/mkcommon.inc

SRC	= \
	$(srcdir)/adler32.c 	\
	$(srcdir)/compress.c	\
	$(srcdir)/crc32.c	\
	$(srcdir)/deflate.c	\
	$(srcdir)/inffast.c	\
	$(srcdir)/inflate.c	\
	$(srcdir)/inftrees.c 	\
	$(srcdir)/trees.c	\
	$(srcdir)/uncompr.c	\
	$(srcdir)/zutil.c

include Make_objs.inc
OBJS = $(FLATEOBJS)

include ../../config/mklibs.inc

# GCC compiling ASM module
match$(LO): match.S zprefix.h
	$(CPP) -DNO_UNDERLINE match.S > match.s
	$(LIBTOOL_CC) $(CC) -c match.s
	$(RM) match.s

$(OO)$(PATHSEP)gvmat32.obj: ./gvmat32.asm
	$(AS) $(ASFLAGS) $(PROGFLAGS) /Fo$(OO)/gvmat32.obj gvmat32.asm

$(OO)$(PATHSEP)inffas32.obj: ./inffas32.asm
	$(AS) $(ASFLAGS) $(PROGFLAGS) /Fo$(OO)/inffas32.obj inffas32.asm


# Automatically generated dependencies
