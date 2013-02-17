# Template to be included from every makefile that creates libs
# $Id: mkmainlib.inc.in,v 1.1.4.4 2008/01/09 20:32:20 rjs Exp $
#

LIBLINKSELF     = $(MAINOBJ) $(INTERNALLIBS) $(EXTERNALLIBS)

all::	$(MAINLIBNAME)

$(MAINLIBNAME): $(MAINOBJ) $(INTERNALLIBS)
	$(LIBTOOL_LD) $(CC) $(LDFLAGS) -o $@ $(RPATH) $(LIBLINKSELF) -export-dynamic
	$(LIBTOOL_LD) $(CC) $(LDFLAGS) -o libs_$@ $(LIBLINKSELF)

clean::
	-$(RM) $(MAINLIBNAME) $(MAINOBJ) libs_$(MAINLIBNAME)

depend::
	$(CC) $(CPPFLAGS) $(CFLAGS) -MM $(MAINSRC) | sed 's/^\(.*\)\.o:/$$(OO)$$(PATHSEP)\1$$(LO):/' >>Makefile

install:: $(MAINLIBNAME)
	if test ! -d $(DESTDIR)$(libdir) ; then 	\
	    mkdir -p $(DESTDIR)$(libdir);		\
	    chmod 755 $(DESTDIR)$(libdir);	\
	fi
	if test ! -d $(DESTDIR)$(includedir) ; then 	\
	    mkdir -p $(DESTDIR)$(includedir);		\
	    chmod 755 $(DESTDIR)$(includedir);		\
	fi
	$(INSTALL_DATA) $(MAININC) $(DESTDIR)$(includedir)
	@-if test "$(WITH_SHARED)" = "no"; then	\
	    cp .libs/$(MAINLIBNAME) .libs/$(MAINLIBNAME)i;\
	fi
	$(LIBTOOL) $(INSTALL_DATA) $(MAINLIBNAME) $(DESTDIR)$(libdir);
	@-if test "$(WITH_SHARED)" = "yes"; then	\
	    $(LIBTOOL) -n --finish $(DESTDIR)$(libdir);\
	else\
	    rm -f .libs/$(MAINLIBNAME)i;\
	fi

uninstall:: .dummy
	$(RM) $(DESTDIR)$(includedir)/$(MAININC)
	-$(LIBTOOL) --mode=uninstall $(RM) $(DESTDIR)$(libdir)/$(MAINLIBNAME)

test::

smoke::

.PHONY: clean
