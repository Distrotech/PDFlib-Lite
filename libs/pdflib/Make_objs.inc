# $id:$
# All objects for building libraries

PDFLIBOBJS	= \
	$(OO)$(PATHSEP)p_3d$(LO)	 \
	$(OO)$(PATHSEP)p_actions$(LO) \
	$(OO)$(PATHSEP)p_afm$(LO)	 \
	$(OO)$(PATHSEP)p_annots$(LO)	 \
	$(OO)$(PATHSEP)p_block$(LO)   \
	$(OO)$(PATHSEP)p_bmp$(LO)	 \
	$(OO)$(PATHSEP)p_ccitt$(LO)	 \
	$(OO)$(PATHSEP)p_cid$(LO)	 \
	$(OO)$(PATHSEP)p_color$(LO)	 \
	$(OO)$(PATHSEP)p_document$(LO)\
	$(OO)$(PATHSEP)p_draw$(LO)	 \
	$(OO)$(PATHSEP)p_encoding$(LO)\
	$(OO)$(PATHSEP)p_fields$(LO)	 \
	$(OO)$(PATHSEP)p_filter$(LO)	 \
	$(OO)$(PATHSEP)p_font$(LO)	 \
	$(OO)$(PATHSEP)p_gif$(LO)	 \
	$(OO)$(PATHSEP)p_gstate$(LO)	 \
	$(OO)$(PATHSEP)p_hyper$(LO)	 \
	$(OO)$(PATHSEP)p_icc$(LO)	 \
	$(OO)$(PATHSEP)p_icclib$(LO)	 \
	$(OO)$(PATHSEP)p_image$(LO)	 \
	$(OO)$(PATHSEP)p_jpeg$(LO)	 \
	$(OO)$(PATHSEP)p_jpx$(LO)	 \
	$(OO)$(PATHSEP)p_kerning$(LO) \
	$(OO)$(PATHSEP)p_layer$(LO)	 \
	$(OO)$(PATHSEP)p_mbox$(LO)	 \
	$(OO)$(PATHSEP)p_object$(LO)  \
	$(OO)$(PATHSEP)p_opi$(LO)	 \
	$(OO)$(PATHSEP)p_page$(LO)	 \
	$(OO)$(PATHSEP)p_params$(LO)	 \
	$(OO)$(PATHSEP)p_pattern$(LO) \
	$(OO)$(PATHSEP)p_pdi$(LO)	 \
	$(OO)$(PATHSEP)p_pfm$(LO)	 \
	$(OO)$(PATHSEP)p_photoshp$(LO)	 \
	$(OO)$(PATHSEP)p_png$(LO)	 \
	$(OO)$(PATHSEP)p_shading$(LO) \
	$(OO)$(PATHSEP)p_subsett$(LO) \
	$(OO)$(PATHSEP)p_table$(LO)  \
	$(OO)$(PATHSEP)p_tagged$(LO)  \
	$(OO)$(PATHSEP)p_template$(LO)\
	$(OO)$(PATHSEP)p_text$(LO)	 \
	$(OO)$(PATHSEP)p_textflow$(LO)\
	$(OO)$(PATHSEP)p_tiff$(LO)	 \
	$(OO)$(PATHSEP)p_truetype$(LO)\
	$(OO)$(PATHSEP)p_type1$(LO)	 \
	$(OO)$(PATHSEP)p_type3$(LO)	 \
	$(OO)$(PATHSEP)p_util$(LO)	 \
	$(OO)$(PATHSEP)p_xgstate$(LO) \
	$(OO)$(PATHSEP)p_xmp$(LO)


PDFLIB_OBJS	= \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_3d$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_actions$(LO) \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_afm$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_annots$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_block$(LO)   \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_bmp$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_ccitt$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_cid$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_color$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_document$(LO)\
	$(top_builddir)/libs/pdflib$(PATHSEP)p_draw$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_encoding$(LO)\
	$(top_builddir)/libs/pdflib$(PATHSEP)p_fields$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_filter$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_font$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_gif$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_gstate$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_hyper$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_icc$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_icclib$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_image$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_jpeg$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_jpx$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_kerning$(LO) \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_layer$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_mbox$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_object$(LO)  \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_opi$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_page$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_params$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_pattern$(LO) \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_pdi$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_pfm$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_photoshp$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_png$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_shading$(LO) \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_subsett$(LO) \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_table$(LO)  \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_tagged$(LO)  \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_template$(LO)\
	$(top_builddir)/libs/pdflib$(PATHSEP)p_text$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_textflow$(LO)\
	$(top_builddir)/libs/pdflib$(PATHSEP)p_tiff$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_truetype$(LO)\
	$(top_builddir)/libs/pdflib$(PATHSEP)p_type1$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_type3$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_util$(LO)	 \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_xgstate$(LO) \
	$(top_builddir)/libs/pdflib$(PATHSEP)p_xmp$(LO)
