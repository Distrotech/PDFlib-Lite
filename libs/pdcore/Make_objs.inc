# $id:$
# All objects for building libraries

PDCOREOBJS	= \
	$(OO)$(PATHSEP)pc_aes$(LO)      \
	$(OO)$(PATHSEP)pc_aescbc$(LO)   \
	$(OO)$(PATHSEP)pc_arc4$(LO)	   \
	$(OO)$(PATHSEP)pc_chartabs$(LO) \
	$(OO)$(PATHSEP)pc_contain$(LO)  \
	$(OO)$(PATHSEP)pc_core$(LO)	   \
	$(OO)$(PATHSEP)pc_crypt$(LO)	   \
	$(OO)$(PATHSEP)pc_ctype$(LO)    \
	$(OO)$(PATHSEP)pc_digsig$(LO)   \
	$(OO)$(PATHSEP)pc_ebcdic$(LO)   \
	$(OO)$(PATHSEP)pc_encoding$(LO) \
	$(OO)$(PATHSEP)pc_file$(LO)	   \
	$(OO)$(PATHSEP)pc_geom$(NO_O)$(LO)	   \
	$(OO)$(PATHSEP)pc_md5$(LO)	   \
	$(OO)$(PATHSEP)pc_optparse$(LO) \
	$(OO)$(PATHSEP)pc_output$(LO)   \
	$(OO)$(PATHSEP)pc_resource$(LO) \
	$(OO)$(PATHSEP)pc_scan$(LO)	   \
	$(OO)$(PATHSEP)pc_scope$(LO)	   \
	$(OO)$(PATHSEP)pc_string$(LO)   \
	$(OO)$(PATHSEP)pc_unicode$(LO)  \
	$(OO)$(PATHSEP)pc_util$(LO)     \
	$(OO)$(PATHSEP)pc_xmp$(LO)

PDCORE_OBJS	= \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_aes$(LO)      \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_aescbc$(LO)   \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_arc4$(LO)	   \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_chartabs$(LO) \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_contain$(LO)  \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_core$(LO)	   \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_crypt$(LO)	   \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_ctype$(LO)    \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_digsig$(LO)   \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_ebcdic$(LO)   \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_encoding$(LO) \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_file$(LO)	   \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_geom$(NO_O)$(LO)  \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_md5$(LO)	   \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_optparse$(LO) \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_output$(LO)   \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_resource$(LO) \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_scan$(LO)	   \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_scope$(LO)	   \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_string$(LO)   \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_unicode$(LO)  \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_util$(LO)     \
	$(top_builddir)/libs/pdcore$(PATHSEP)pc_xmp$(LO)

