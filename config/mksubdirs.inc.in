# Template to be included from every makefile that handles subdirs
# $Id: mksubdirs.inc.in,v 1.8.4.2 2007/12/31 18:17:50 rjs Exp $
#
#
# The Makefile that uses this template has to set
# SUB_DIRS = ...
#
# additional actions may be done by using any of the makelabels with
# two colons.
#
# i.e.
# install:: .dummy
#	$(INSTALL) pdflib-config $(bindir)

# ------------------------- default target  -------------------------------
all::	.dummy
	@for i in $(SUB_DIRS);\
	do\
	    (cd $$i && $(MAKE) $(MAKEOPT) all) || exit $$?;\
	done

# --------------------------- test ---------------------------------
test::	.dummy
	@for i in $(SUB_DIRS);\
	do\
	    (cd $$i && $(MAKE) $(MAKEOPT) test);\
	done

# --------------------------- pditest ---------------------------------
smoke:: .dummy
	@for i in $(SUB_DIRS);\
	do\
	    (cd $$i && $(MAKE) $(MAKEOPT) smoke);\
	    if test -d $$i/smoke; then \
	      (cd $$i/smoke && $(MAKE) $(MAKEOPT) smoke);\
	    fi \
	done

# --------------------------- install ---------------------------------
install:: .dummy
	@for i in $(SUB_DIRS);\
	do\
	    (cd $$i && $(MAKE) $(MAKEOPT) install);\
	done

# --------------------------- uninstall ---------------------------------
uninstall:: .dummy
	@for i in $(SUB_DIRS);\
	do\
	    (cd $$i && $(MAKE) $(MAKEOPT) uninstall);\
	done

# --------------------------- clean ---------------------------------
clean:: .dummy
	@for i in $(SUB_DIRS);\
	do\
	    (cd $$i && $(MAKE) $(MAKEOPT) clean);\
	done

# ----------------------- distclean ---------------------------------
distclean:: .dummy
	@for i in $(SUB_DIRS);\
	do\
	    (cd $$i && $(MAKE) $(MAKEOPT) distclean);\
	done
	rm -rf m.out ms.out

# --------------------------- depend --------------------------------
depend:: .dummy
	@for i in $(SUB_DIRS);\
	do\
	    (cd $$i && $(MAKE) $(MAKEOPT) depend);\
	done

# --------------------------- ctags ---------------------------------
ctags:: .dummy
	@for i in $(SUB_DIRS);\
	do\
	    (cd $$i && $(MAKE) $(MAKEOPT) ctags);\
	done

.dummy:
