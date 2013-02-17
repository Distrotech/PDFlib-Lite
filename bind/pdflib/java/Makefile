# Makefile for PDFlib's Java binding
# $Id: Makefile,v 1.55.2.18 2009/04/21 12:15:36 rjs Exp $

top_builddir	= ../../..
MYJAR   = pdflib.jar
JAVAC   = javac -classpath $(MYJAR):.
COMPILE = $(JAVAC) $(JAVACFLAGS)
JAVA    = $(LIBTOOL_EXE) java -classpath $(MYJAR):.
JAR     = jar

include ../../../config/mkcommon.inc

PDFPEDANTIC	=
PDFWALL	=

DEPLIBS		= $(BIND_PDFLIBLINK)
LIBS		= $(DEPLIBS)
INCLUDES	= $(PDFLIBINC) $(PDCORELIBINC) $(JAVAINCLUDE)

LANG_LIBDIR 	= $(DESTDIR)$(libdir)

_LIBNAME	= pdf_java
LIBNAME		= lib$(_LIBNAME)$(DLL)
OBJ		= pdflib_java$(LO)
SRC		= pdflib_java.c

include ../../../config/mkbind.inc

TESTPROGS	= 		\
	hello.class 		\
	image.class 		\
	pdfclock.class 		\
	chartab.class 		\
	invoice.class 		\
	businesscard.class 	\
	quickreference.class	\
	starter_basic.class	\
	starter_block.class	\
	starter_pcos.class	\
	starter_pdfa.class	\
	starter_pdfmerge.class	\
	starter_pdfx.class	\
	starter_table.class	\
	starter_tagged.class	\
	starter_textflow.class	\
	starter_webform.class	\
	starter_3d.class	\
	starter_type3font.class	\
	starter_pvf.class	\
	starter_layer.class	\
	starter_color.class	\
	starter_textline.class	\
	starter_image.class	\
	starter_graphics.class

.SUFFIXES:      .java .class

.java.class:
	-$(COMPILE) $<

all::	$(LIBNAME) pdflib.jar


pdflib.jar:: pdflib.java PDFlibException.java
	$(RM) com
	$(MKDIR) com
	$(MKDIR) com$(PATHSEP)pdflib
	$(COMPILE) $(JAVA_COMPATIBILITY) PDFlibException.java pdflib.java 
	$(MOVE) pdflib.class com$(PATHSEP)pdflib
	$(MOVE) PDFlibException.class com$(PATHSEP)pdflib
	$(JAR) cvf pdflib.jar com/pdflib/pdflib.class \
	    com/pdflib/PDFlibException.class
	$(RM) com

javadoc::
	$(RM) javadoc
	$(MKDIR) javadoc
	-javadoc -notree -author -version -d javadoc -public \
	    pdflib.java PDFlibException.java

test:: $(LIBNAME) pdflib.jar $(TESTPROGS)
	$(JAVA) hello
	-$(JAVA) image
	-$(JAVA) pdfclock
	-$(JAVA) chartab
	-$(JAVA) invoice
	-$(JAVA) businesscard
	-$(JAVA) quickreference
	-$(JAVA) starter_basic
	-$(JAVA) starter_block
	-$(JAVA) starter_pcos >starter_pcos.txt
	-$(JAVA) starter_pdfa
	-$(JAVA) starter_pdfmerge
	-$(JAVA) starter_pdfx
	-$(JAVA) starter_table
	-$(JAVA) starter_tagged
	-$(JAVA) starter_textflow
	-$(JAVA) starter_webform
	-$(JAVA) starter_3d
	-$(JAVA) starter_type3font
	-$(JAVA) starter_pvf
	-$(JAVA) starter_layer
	-$(JAVA) starter_color
	-$(JAVA) starter_textline
	-$(JAVA) starter_image
	-$(JAVA) starter_graphics

install:: $(LIBNAME) pdflib.jar
	@-if test -f .libs/libpdf_java.jnilib; then		\
	    $(LIBTOOL) --mode=install $(INSTALL_DATA)		\
		.libs/libpdf_java.jnilib $(LANG_LIBDIR);	\
	else							\
	    $(LIBTOOL) --mode=install $(INSTALL_DATA)		\
		$(LIBNAME) $(LANG_LIBDIR);			\
	fi
	@echo Copy pdflib.jar and javadoc to an appropriate directory,
	@echo and include pdflib.jar in your CLASSPATH.

uninstall::
	@-if test -f .libs/libpdf_java.jnilib; then		\
	    $(LIBTOOL) --mode=uninstall $(RM)			\
		$(LANG_LIBDIR)/libpdf_java.jnilib;		\
	else							\
	    $(LIBTOOL) --mode=uninstall $(RM)			\
		$(LANG_LIBDIR)/$(LIBNAME);			\
	fi

clean::
	$(RM) pdflib_java.lo pdflib_java.o *.class com pdflib.jar javadoc
	$(RM) hello.pdf image.pdf pdfclock.pdf chartab.pdf invoice.pdf
	$(RM) businesscard.pdf quickreference.pdf starter_pcos.txt
	$(RM) starter_type3font.pdf starter_pvf.pdf starter_layer.pdf
	$(RM) starter_color.pdf starter_image.pdf starter_graphics.pdf
	$(RM) starter_textline.pdf starter_3d.pdf

pdfcheck:
	..$(PATHSEP)..$(PATHSEP)..$(PATHSEP)progs$(PATHSEP)pdi$(PATHSEP)pdfcheck -i starter.ref -o -

pdfcheck_update:
	../../../progs/pdi/pdfcheck -i starter.ref -o pdfcheck.out -update
		@cp pdfcheck.out starter.ref

# Automatically generated dependencies
