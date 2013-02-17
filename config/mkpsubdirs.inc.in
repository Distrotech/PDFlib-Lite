# Template to be included from every makefile that handles parallel subdirs
# $Id: mkpsubdirs.inc.in,v 1.1.4.2 2007/10/09 12:04:34 rjs Exp $
#
#
# The Makefile that uses this template has to set
# PSUB_DIRS = ...
#

# the default label for this makefile is a bit tricky
# .PHONY hels us to do run make parallel on platforms where this is supported

.PHONY: subdirs $(PSUB_DIRS)

subdirs: $(PSUB_DIRS)

$(PSUB_DIRS):
	@(cd $@ && $(MAKE) $(MAKEOPT))

# additional actions may be done by using any of the makelabels with
# two colons.
#
# i.e.
# install:: .dummy
#	$(INSTALL) pdflib-config $(DESTDIR)$(bindir)

# ------------------------- default target  -------------------------------
all::	.dummy
	@for i in $(PSUB_DIRS);\
	do\
	    (cd $$i && $(MAKE) $(MAKEOPT) all);\
	done

# --------------------------- test ---------------------------------
test::	.dummy
	@for i in $(PSUB_DIRS);\
	do\
	    (cd $$i && $(MAKE) $(MAKEOPT) test);\
	done

# --------------------------- clean ---------------------------------
clean:
	@for i in $(PSUB_DIRS);\
	do\
	    (cd $$i && $(MAKE) $(MAKEOPT) clean);\
	done

# ----------------------- distclean ---------------------------------
distclean:: .dummy
	@for i in $(PSUB_DIRS);\
	do\
	    (cd $$i && $(MAKE) $(MAKEOPT) distclean);\
	done
	rm -rf m.out ms.out

# --------------------------- depend --------------------------------
depend:: .dummy
	@for i in $(PSUB_DIRS);\
	do\
	    (cd $$i && $(MAKE) $(MAKEOPT) depend);\
	done

.dummy:
