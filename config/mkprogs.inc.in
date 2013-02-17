PROGS_BUILD = $(LIBTOOL_CC) $(CC) -c $(CPPFLAGS) $(CFLAGS) $@.c
CXXPROGS_BUILD = $(LIBTOOL_CC) $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) \
	$@.cpp $(EXTRA_SOURCES)
PROGS_LINK = $(LIBTOOL_LD) $(CC) -static -o $@ $@$(LO) $(LDFLAGS) \
	$(EXTRA_OBJS) $(LIBS) $(EXTERNALLIBS)
CXXPROGS_LINK = $(LIBTOOL_LD) $(CXX) -static -o $@ $@$(LO) \
	$(CXXFLAGS) $(LDFLAGS) $(EXTRA_OBJS) $(LIBS) $(EXTERNALLIBS)

all::    $(PROGS)

clean::
	-$(RM) *.$(OBJ) *$(LO) *$(LA) $(PROGS) *.bak .libs

distclean:: clean
	-$(RM) m.out ms.out

depend:: .dummy
	cp Makefile Makefile.bak
	sed '/^# Automatically generated dependencies/q' Makefile.bak >Makefile
	$(CC) $(CPPFLAGS) $(CFLAGS) -MM $(SRC) | sed 's/^\(.*\)\.o:/$$(OO)$$(PATHSEP)\1$$(LO):/' >>Makefile




ctags::

install::

uninstall::

test::

smoke::

.PHONY: clean

.dummy:


.SUFFIXES: .$(OBJ) $(LO) .cpp

.c$(LO):
	$(LIBTOOL_CC) $(CC) -c $(CPPFLAGS) $(CFLAGS) $<

.c.$(OBJ):
	$(LIBTOOL_CC) $(CC) -c $(CPPFLAGS) $(CFLAGS) $<

.cpp$(LO):
	$(LIBTOOL_CC) $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $<

.cpp.$(OBJ):
	$(LIBTOOL_CC) $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $<
