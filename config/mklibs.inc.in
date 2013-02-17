# Template to be included from every makefile that creates libs
# $Id: mklibs.inc.in,v 1.7.4.3 2008/05/30 12:48:16 rjs Exp $
#

all::	$(LIBNAME)

$(LIBNAME): $(OBJS)
	$(LIBTOOL_LD) $(CC) $(LDFLAGS) -o $@ $(OBJS)

clean::
	-$(RM) $(OBJS) *.$(OBJ) *$(LO) *$(LA) *.bak .libs

distclean:: clean
	-$(RM) m.out ms.out

depend:: .dummy
	cp Makefile Makefile.bak
	sed '/^# Automatically generated dependencies/q' Makefile.bak >Makefile
	$(CC) $(CPPFLAGS) $(CFLAGS) -MM $(SRC) | sed 's/^\(.*\)\.o:/$$(OO)$$(PATHSEP)\1$$(LO):/' >>Makefile

install::

uninstall::

test::

smoke::

.PHONY: clean

.dummy:

# suffixes
.SUFFIXES: .$(OBJ) $(LO) .cpp

.c$(LO):
	$(LIBTOOL_CC) $(CC) -c $(CPPFLAGS) $(CFLAGS) $<

.c.$(OBJ):
	$(LIBTOOL_CC) $(CC) -c $(CPPFLAGS) $(CFLAGS) $<

.cpp$(LO):
	$(LIBTOOL_CC) $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $<

.cpp.$(OBJ):
	$(LIBTOOL_CC) $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $<
