# Main PDFlib Makefile
# $Id: Makefile,v 1.11.2.4 2012/06/06 11:55:28 rjs Exp $

top_builddir=.

include config/mkcommon.inc

SUB_DIRS = $(STDDIRS) $(PROGSDIR) $(PTFDIR) $(INTERNDIR)

include config/mksubdirs.inc

# --------------------------- install ---------------------------------
install:: .dummy
	mkdir -p $(DESTDIR)$(bindir)
	$(INSTALL) pdflib-config $(DESTDIR)$(bindir)

# ----------------------- distclean ---------------------------------
distclean:: .dummy
	-$(RM) libtool pdflib-config config.cache config.log config.status \
	config/mkcommon.inc
