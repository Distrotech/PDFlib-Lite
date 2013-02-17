# $id:$
# All objects for building libraries

FLATEOBJS	= \
	$(OO)$(PATHSEP)adler32$(LO) 	\
	$(OO)$(PATHSEP)compress$(LO)	\
	$(OO)$(PATHSEP)crc32$(LO)	\
	$(OO)$(PATHSEP)deflate$(LO)	\
	$(OO)$(PATHSEP)inffast$(LO)	\
	$(OO)$(PATHSEP)inflate$(LO)	\
	$(OO)$(PATHSEP)inftrees$(LO) 	\
	$(OO)$(PATHSEP)trees$(LO)	\
	$(OO)$(PATHSEP)uncompr$(LO)	\
	$(OO)$(PATHSEP)zutil$(LO)	\
	$(FLATE_ASM_OBJ)

FLATE_OBJS	= \
	$(top_builddir)/libs/flate$(PATHSEP)adler32$(LO) 	\
	$(top_builddir)/libs/flate$(PATHSEP)compress$(LO)	\
	$(top_builddir)/libs/flate$(PATHSEP)crc32$(LO)	\
	$(top_builddir)/libs/flate$(PATHSEP)deflate$(LO)	\
	$(top_builddir)/libs/flate$(PATHSEP)inffast$(LO)	\
	$(top_builddir)/libs/flate$(PATHSEP)inflate$(LO)	\
	$(top_builddir)/libs/flate$(PATHSEP)inftrees$(LO) 	\
	$(top_builddir)/libs/flate$(PATHSEP)trees$(LO)	\
	$(top_builddir)/libs/flate$(PATHSEP)uncompr$(LO)	\
	$(top_builddir)/libs/flate$(PATHSEP)zutil$(LO)	\
	$(FLATE_ASM_OBJ)

