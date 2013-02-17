/*---------------------------------------------------------------------------*
 |              PDFlib - A library for generating PDF on the fly             |
 +---------------------------------------------------------------------------+
 | Copyright (c) 1997-2007 Thomas Merz and PDFlib GmbH. All rights reserved. |
 +---------------------------------------------------------------------------+
 |                                                                           |
 |    This software is subject to the PDFlib license. It is NOT in the       |
 |    public domain. Extended versions and commercial licenses are           |
 |    available, please check http://www.pdflib.com.                         |
 |                                                                           |
 *---------------------------------------------------------------------------*/

/* $Id: p_color.c,v 1.217.2.12 2009/06/04 11:22:04 york Exp $
 *
 * PDFlib color routines
 *
 */

#define P_COLOR_C

#include "p_intern.h"
#include "p_color.h"


static const pdc_keyconn pdf_colortype_keylist[] =
{
    {"none",         color_none},
    {"gray",         color_gray},
    {"rgb",          color_rgb},
    {"cmyk",         color_cmyk},
    {"spotname",     color_spotname},
    {"spot",         color_spot},
    {"pattern",      color_pattern},
    {"iccbasedgray", color_iccbasedgray},
    {"iccbasedrgb",  color_iccbasedrgb},
    {"iccbasedcmyk", color_iccbasedcmyk},
    {"lab",          color_lab},
    {NULL, 0}
};

static const pdc_keyconn pdf_colorcomp_keylist[] =
{
    {"none",         0},
    {"gray",         1},
    {"rgb",          3},
    {"cmyk",         4},
    {"spotname",     2},
    {"spot",         2},
    {"pattern",      1},
    {"iccbasedgray", 1},
    {"iccbasedrgb",  3},
    {"iccbasedcmyk", 4},
    {"lab",          3},
    {NULL, 0}
};

/* ------------------------ color state ----------------------- */

struct pdf_cstate_s
{
    pdf_color   fill;
    pdf_color   stroke;
};

void
pdf_init_cstate(PDF *p)
{
    static const char fn[] = "pdf_init_cstate";
    pdf_cstate *cstate;

    if (!p->curr_ppt->cstate)
    {
	p->curr_ppt->cstate = (pdf_cstate *) pdc_malloc(p->pdc,
                                   PDF_MAX_SAVE_LEVEL * sizeof(pdf_cstate), fn);
    }

    cstate = &p->curr_ppt->cstate[p->curr_ppt->sl];

    cstate->fill.cs             = DeviceGray;
    cstate->fill.val.gray       = 0.0;

    cstate->stroke.cs           = DeviceGray;
    cstate->stroke.val.gray     = 0.0;
}

void
pdf_save_cstate(PDF *p)
{
    pdf_ppt *ppt = p->curr_ppt;
    int sl = ppt->sl;

    memcpy(&ppt->cstate[sl + 1], &ppt->cstate[sl], sizeof(pdf_cstate));
}

pdf_color *
pdf_get_cstate(PDF *p, pdf_drawmode mode)
{
    if (mode == pdf_fill)
        return &p->curr_ppt->cstate[p->curr_ppt->sl].fill;
    else
        return &p->curr_ppt->cstate[p->curr_ppt->sl].stroke;
}

void
pdf_cleanup_page_cstate(PDF *p, pdf_ppt *ppt)
{
    if (ppt->cstate != NULL)
        pdc_free(p->pdc, ppt->cstate);

    ppt->cstate = NULL;
}



/* Avoid wrong error messages due to rounding artifacts.
 * This doesn't do any harm since we truncate to 5 decimal places anyway
 * when producing PDF output.
 */
#define EPSILON	((1.0 + PDF_SMALLREAL))

static void pdf_check_color_values(PDF *p, pdf_colorspacetype type,
    pdc_scalar c1, pdc_scalar c2, pdc_scalar c3, pdc_scalar c4);

static int
pdf_color_components(PDF *p, int slot)
{
    static const char *fn = "pdf_color_components";
    pdf_colorspace *cs;
    int components = 0;

    cs = &p->colorspaces[slot];

    switch (cs->type) {
	case DeviceGray:
	case Indexed:
	components = 1;
	break;

	case DeviceRGB:
	components = 3;
	break;

	case DeviceCMYK:
	components = 4;
	break;

	case PatternCS:
	if (cs->val.pattern.base == pdc_undef)
	    components = 0;	/* PaintType 1: colored pattern */
	else
	    components = pdf_color_components(p, cs->val.pattern.base);

	default:
	    pdc_error(p->pdc, PDF_E_INT_BADCS, fn,
		pdc_errprintf(p->pdc, "%d", slot),
		pdc_errprintf(p->pdc, "%d", cs->type), 0);
    }

    return components;
} /* pdf_color_components */

static void
pdf_write_color_values(PDF *p, pdf_color *color, pdf_drawmode drawmode)
{
    static const char	fn[] = "pdf_write_color_values";

    pdf_colorspace *	cs = &p->colorspaces[color->cs];

    switch (cs->type)
    {
	case DeviceGray:
	{
	    pdc_printf(p->out, "%f", color->val.gray);

	    if (drawmode == pdf_fill)
		pdc_puts(p->out, " g\n");
	    else if (drawmode == pdf_stroke)
		pdc_puts(p->out, " G\n");

	    break;
	}

	case DeviceRGB:
	{
	    pdc_printf(p->out, "%f %f %f",
		    color->val.rgb.r, color->val.rgb.g, color->val.rgb.b);

	    if (drawmode == pdf_fill)
		pdc_puts(p->out, " rg\n");
	    else if (drawmode == pdf_stroke)
		pdc_puts(p->out, " RG\n");

	    break;
	}

	case DeviceCMYK:
	{
	    pdc_printf(p->out, "%f %f %f %f",
		    color->val.cmyk.c, color->val.cmyk.m,
		    color->val.cmyk.y, color->val.cmyk.k);

	    if (drawmode == pdf_fill)
		pdc_puts(p->out, " k\n");
	    else if (drawmode == pdf_stroke)
		pdc_puts(p->out, " K\n");

	    break;
	}


	case PatternCS:
	{
	    if (drawmode == pdf_fill)
	    {
		if (p->pattern[color->val.pattern].painttype == 1)
		{
		    pdc_puts(p->out, "/Pattern cs");
		}
		else if (p->pattern[color->val.pattern].painttype == 2)
		{
                    pdf_color *fillcolor = pdf_get_cstate(p, pdf_fill);

		    pdc_printf(p->out, "/C%d cs ", color->cs);
                    pdf_write_color_values(p, fillcolor, pdf_none);
		}

		pdc_printf(p->out, "/P%d scn\n", color->val.pattern);
	    }
	    else if (drawmode == pdf_stroke)
	    {
		if (p->pattern[color->val.pattern].painttype == 1)
		{
		    pdc_puts(p->out, "/Pattern CS");
		}
		else if (p->pattern[color->val.pattern].painttype == 2)
		{
                    pdf_color *strokecolor = pdf_get_cstate(p, pdf_stroke);

		    pdc_printf(p->out, "/C%d CS ", color->cs);
                    pdf_write_color_values(p, strokecolor, pdf_none);
		}

		pdc_printf(p->out, "/P%d SCN\n", color->val.pattern);
	    }

	    p->pattern[color->val.pattern].used_on_current_page = pdc_true;
	    break;
	}


	case Indexed: /* LATER */
	default:
	    pdc_error(p->pdc, PDF_E_INT_BADCS, fn,
		pdc_errprintf(p->pdc, "%d", color->cs),
		pdc_errprintf(p->pdc, "%d", cs->type), 0);
    }
} /* pdf_write_color_values */

static pdc_bool
pdf_color_equal(PDF *p, pdf_color *c1, pdf_color *c2)
{
    pdf_colorspace *cs1;

    cs1 = &p->colorspaces[c1->cs];

    if (c1->cs != c2->cs)
	return pdc_false;

    switch (cs1->type) {
	case DeviceGray:
	    return (c1->val.gray == c2->val.gray);
	    break;

	case DeviceRGB:
	    return (c1->val.rgb.r == c2->val.rgb.r &&
		    c1->val.rgb.g == c2->val.rgb.g &&
		    c1->val.rgb.b == c2->val.rgb.b);
	    break;

	case DeviceCMYK:
	    return (c1->val.cmyk.c == c2->val.cmyk.c &&
		    c1->val.cmyk.m == c2->val.cmyk.m &&
		    c1->val.cmyk.y == c2->val.cmyk.y &&
		    c1->val.cmyk.k == c2->val.cmyk.k);
	    break;

	case Indexed:
	    return (c1->val.idx == c2->val.idx);
	    break;

	case PatternCS:
	    return (c1->val.pattern == c2->val.pattern);
	    break;


	default:
	    break;
    }

    return pdc_true;
} /* pdf_color_equal */

static pdc_bool
pdf_colorspace_equal(PDF *p, pdf_colorspace *cs1, pdf_colorspace *cs2)
{
    static const char *fn = "pdf_colorspace_equal";

    if (cs1->type != cs2->type)
	return pdc_false;

    switch (cs1->type) {
	case DeviceGray:
	case DeviceRGB:
	case DeviceCMYK:
	return pdc_true;
	break;


	case Indexed:
	return ((cs1->val.indexed.base == cs2->val.indexed.base) &&
		(cs1->val.indexed.palette_size==cs2->val.indexed.palette_size)&&
		(cs1->val.indexed.colormap_id != PDC_BAD_ID &&
		 cs1->val.indexed.colormap_id == cs2->val.indexed.colormap_id));
	break;

	case PatternCS:
	return (cs1->val.pattern.base == cs2->val.pattern.base);
	break;


	default:
	    pdc_error(p->pdc, PDF_E_INT_BADCS, fn, "(unknown)",
		pdc_errprintf(p->pdc, "%d", cs1->type), 0);
    }

    return pdc_false;
} /* pdf_colorspace_equal */

static void
pdf_grow_colorspaces(PDF *p)
{
    int i;

    p->colorspaces = (pdf_colorspace *) pdc_realloc(p->pdc, p->colorspaces,
	sizeof(pdf_colorspace) * 2 * p->colorspaces_capacity,
	"pdf_grow_colorspaces");

    for (i = p->colorspaces_capacity; i < 2 * p->colorspaces_capacity; i++) {
	p->colorspaces[i].used_on_current_page = pdc_false;
    }

    p->colorspaces_capacity *= 2;
}

int
pdf_add_colorspace(PDF *p, pdf_colorspace *cs, pdc_bool inuse)
{
    pdf_colorspace *cs_new;
    static const char fn[] = "pdf_add_colorspace";
    int slot;

    for (slot = 0; slot < p->colorspaces_number; slot++)
    {
	if (pdf_colorspace_equal(p, &p->colorspaces[slot], cs))
	{
	    if (inuse)
		p->colorspaces[slot].used_on_current_page = pdc_true;
	    return slot;
	}
    }

    slot = p->colorspaces_number;

    if (p->colorspaces_number >= p->colorspaces_capacity)
	pdf_grow_colorspaces(p);

    cs_new = &p->colorspaces[slot];

    cs_new->type = cs->type;

    /* don't allocate id for simple color spaces, since we don't write these */
    if (PDF_SIMPLE_COLORSPACE(cs)) {
	cs_new->obj_id = PDC_BAD_ID;
	cs_new->used_on_current_page = pdc_false;

    } else {
	cs_new->obj_id = pdc_alloc_id(p->out);
	cs_new->used_on_current_page = inuse;
    }

    switch (cs_new->type) {
	case DeviceGray:
	case DeviceRGB:
	case DeviceCMYK:
	break;


	case Indexed:
	{
	size_t palsize; 	/* palette size in bytes */

	palsize = cs->val.indexed.palette_size *
			    pdf_color_components(p, cs->val.indexed.base);

        cs_new->val.indexed.base = cs->val.indexed.base;
        cs_new->val.indexed.palette_size = cs->val.indexed.palette_size;
        cs_new->val.indexed.colormap_id = pdc_alloc_id(p->out);
        cs_new->val.indexed.colormap =
	    (pdf_colormap *) pdc_malloc(p->pdc, palsize, fn);
        memcpy(cs_new->val.indexed.colormap, cs->val.indexed.colormap, palsize);
        cs_new->val.indexed.colormap_done = pdc_false;
	break;

	case PatternCS:
        cs_new->val.pattern.base = cs->val.pattern.base;
	break;
	}


	default:
	    pdc_error(p->pdc, PDF_E_INT_BADCS, fn,
		pdc_errprintf(p->pdc, "%d", slot),
		pdc_errprintf(p->pdc, "%d", cs_new->type), 0);
    }

    p->colorspaces_number++;

    return slot;
} /* pdf_add_colorspace */


static void
pdf_set_color_values(PDF *p, pdf_color *cfill, pdf_color *cstroke,
                     pdf_drawmode drawmode)
{
    pdf_colorspace *cs;

    if (drawmode == pdf_stroke || drawmode == pdf_fillstroke)
    {
        pdf_color *strokecolor = pdf_get_cstate(p, pdf_stroke);

        if (!pdf_color_equal(p, strokecolor, cstroke) || PDF_FORCE_OUTPUT())
        {
            if (PDF_GET_STATE(p) != pdf_state_document)
                pdf_write_color_values(p, cstroke, pdf_stroke);

            *strokecolor = *cstroke;
        }

        cs = &p->colorspaces[cstroke->cs];
        if (!PDF_SIMPLE_COLORSPACE(cs))
            cs->used_on_current_page = pdc_true;
    }

    if (drawmode == pdf_fill || drawmode == pdf_fillstroke)
    {
        pdf_color *fillcolor = pdf_get_cstate(p, pdf_fill);

        if (!pdf_color_equal(p, fillcolor, cfill) || PDF_FORCE_OUTPUT())
        {
            if (PDF_GET_STATE(p) != pdf_state_document)
                pdf_write_color_values(p, cfill, pdf_fill);

            *fillcolor = *cfill;
        }

        cs = &p->colorspaces[cfill->cs];
        if (!PDF_SIMPLE_COLORSPACE(cs))
            cs->used_on_current_page = pdc_true;
    }

} /* pdf_set_color_values */

void
pdf_init_colorspaces(PDF *p)
{
    int i, slot;
    pdf_colorspace cs;


    p->colorspaces_number = 0;
    p->colorspaces_capacity = COLORSPACES_CHUNKSIZE;

    p->colorspaces = (pdf_colorspace *)
	pdc_malloc(p->pdc, sizeof(pdf_colorspace) * p->colorspaces_capacity,
	    "pdf_init_colorspaces");

    for (i = 0; i < p->colorspaces_capacity; i++) {
	p->colorspaces[i].used_on_current_page = pdc_false;
    }

    /*
     * Initialize a few slots with simple color spaces for easier use.
     * These can be used without further ado: the slot number is identical
     * to the enum value due to the ordering below.
     */

    cs.type = DeviceGray;
    slot = pdf_add_colorspace(p, &cs, pdc_false);
    cs.type = DeviceRGB;
    slot = pdf_add_colorspace(p, &cs, pdc_false);
    cs.type = DeviceCMYK;
    slot = pdf_add_colorspace(p, &cs, pdc_false);

} /* pdf_init_colorspaces */

void
pdf_write_page_colorspaces(PDF *p)
{
    int i, total = 0;

    for (i = 0; i < p->colorspaces_number; i++)
	if (p->colorspaces[i].used_on_current_page)
	    total++;

    if (total > 0
       )
    {
	pdc_puts(p->out, "/ColorSpace");
	pdc_begin_dict(p->out);

	if (total > 0)
	{
	    for (i = 0; i < p->colorspaces_number; i++)
	    {
		pdf_colorspace *cs = &p->colorspaces[i];

		if (cs->used_on_current_page)
		{
		    cs->used_on_current_page = pdc_false; /* reset */

		    /* don't write simple color spaces as resource */
		    if (!PDF_SIMPLE_COLORSPACE(cs))
		    {
			pdc_printf(p->out, "/C%d", i);
			pdc_objref(p->out, "", cs->obj_id);
		    }
		}
	    }
	}


	    pdc_end_dict(p->out);		/* color space names */
    }
} /* pdf_write_page_colorspaces */

void
pdf_get_page_colorspaces(PDF *p, pdf_reslist *rl)
{
    int i;

    for (i = 0; i < p->colorspaces_number; i++)
    {
	pdf_colorspace *cs = &p->colorspaces[i];

	if (cs->used_on_current_page)
	{
	    cs->used_on_current_page = pdc_false;

	    if (!PDF_SIMPLE_COLORSPACE(cs))
		pdf_add_reslist(p, rl, i);
	}
    }
}

void
pdf_mark_page_colorspace(PDF *p, int n)
{
    p->colorspaces[n].used_on_current_page = pdc_true;
}

void
pdf_write_function_dict(PDF *p, pdf_color *c0, pdf_color *c1, pdc_scalar N)
{
    static const char *fn = "pdf_write_function_dict";

    pdf_colorspace *cs;

    cs = &p->colorspaces[c1->cs];

    pdc_begin_dict(p->out);			/* function dict */

    pdc_puts(p->out, "/FunctionType 2\n");
    pdc_puts(p->out, "/Domain[0 1]\n");
    pdc_printf(p->out, "/N %f\n", N);

    switch (cs->type) {

	case DeviceGray:
	pdc_puts(p->out, "/Range[0 1]\n");
	if (c0->val.gray != 0) pdc_printf(p->out, "/C0[%f]\n", c0->val.gray);
	if (c1->val.gray != 1) pdc_printf(p->out, "/C1[%f]", c1->val.gray);
	break;

	case DeviceRGB:
	pdc_puts(p->out, "/Range[0 1 0 1 0 1]\n");
	pdc_printf(p->out, "/C0[%f %f %f]\n",
		c0->val.rgb.r, c0->val.rgb.g, c0->val.rgb.b);
	pdc_printf(p->out, "/C1[%f %f %f]",
		c1->val.rgb.r, c1->val.rgb.g, c1->val.rgb.b);
	break;

	case DeviceCMYK:
	pdc_puts(p->out, "/Range[0 1 0 1 0 1 0 1]\n");
	pdc_printf(p->out, "/C0[%f %f %f %f]\n",
		c0->val.cmyk.c, c0->val.cmyk.m, c0->val.cmyk.y, c0->val.cmyk.k);
	pdc_printf(p->out, "/C1[%f %f %f %f]",
		c1->val.cmyk.c, c1->val.cmyk.m, c1->val.cmyk.y, c1->val.cmyk.k);
	break;


	default:
	pdc_error(p->pdc, PDF_E_INT_BADCS, fn, "(unknown)",
	    pdc_errprintf(p->pdc, "%d", cs->type), 0);
    }

    pdc_end_dict_c(p->out);		/* function dict */
} /* pdf_write_function_dict */

void
pdf_write_colormap(PDF *p, int slot)
{
    PDF_data_source src;
    pdf_colorspace *cs, *base;
    pdc_id length_id;

    cs   = &p->colorspaces[slot];

    if (cs->type != Indexed || cs->val.indexed.colormap_done == pdc_true)
	return;

    base = &p->colorspaces[cs->val.indexed.base];

    pdc_begin_obj(p->out, cs->val.indexed.colormap_id);	/* colormap object */
    pdc_begin_dict(p->out);

    if (pdc_get_compresslevel(p->out))
	pdc_puts(p->out, "/Filter/FlateDecode\n");

    /* Length of colormap object */
    length_id = pdc_alloc_id(p->out);
    pdc_objref(p->out, "/Length", length_id);
    pdc_end_dict(p->out);

    src.init		= NULL;
    src.fill		= pdf_data_source_buf_fill;
    src.terminate	= NULL;

    src.buffer_start	= (unsigned char *) cs->val.indexed.colormap;

    src.buffer_length = (size_t) (cs->val.indexed.palette_size *
				pdf_color_components(p, cs->val.indexed.base));

    src.bytes_available = 0;
    src.next_byte	= NULL;

    /* Write colormap data */
    pdf_copy_stream(p, &src, pdc_true);	/* colormap data */

    pdc_end_obj(p->out);				/* colormap object */

    pdc_put_pdfstreamlength(p->out, length_id);

    /* free the colormap now that it's written */
    pdc_free(p->pdc, cs->val.indexed.colormap);
    cs->val.indexed.colormap = NULL;
    cs->val.indexed.colormap_done = pdc_true;
} /* pdf_write_colormap */

void
pdf_write_colorspace(PDF *p, int slot, pdc_bool direct)
{
    static const char *fn = "pdf_write_colorspace";

    pdf_colorspace *cs;
    int base;

    if (slot < 0 || slot >= p->colorspaces_number)
	pdc_error(p->pdc, PDF_E_INT_BADCS, fn,
            pdc_errprintf(p->pdc, "%d", slot),
            "(unknown)", 0);

    cs = &p->colorspaces[slot];

    /* we always write simple colorspaces directly */
    if (PDF_SIMPLE_COLORSPACE(cs))
	direct = pdc_true;

    if (!direct) {
	pdc_objref_c(p->out, cs->obj_id);
	return;
    }

    switch (cs->type) {
	case DeviceGray:
	pdc_printf(p->out, "/DeviceGray");
	break;

	case DeviceRGB:
	pdc_printf(p->out, "/DeviceRGB");
	break;

	case DeviceCMYK:
	pdc_printf(p->out, "/DeviceCMYK");
	break;


	case Indexed:
	base = cs->val.indexed.base;

	pdc_begin_array(p->out);
	pdc_puts(p->out, "/Indexed");

	pdf_write_colorspace(p, base, pdc_false);

	pdc_printf(p->out, " %d", cs->val.indexed.palette_size - 1);
	pdc_objref_c(p->out, cs->val.indexed.colormap_id);
	pdc_end_array_c(p->out);
	break;

	case PatternCS:
	pdc_begin_array(p->out);
	pdc_printf(p->out, "/Pattern");
	pdf_write_colorspace(p, cs->val.pattern.base, pdc_false);
	pdc_end_array(p->out);
	break;

	default:
	pdc_error(p->pdc, PDF_E_INT_BADCS, fn,
	    pdc_errprintf(p->pdc, "%d", slot),
	    pdc_errprintf(p->pdc, "%d", cs->type), 0);
    }
} /* pdf_write_colorspace */

void
pdf_write_doc_colorspaces(PDF *p)
{
    int i;

    for (i = 0; i < p->colorspaces_number; i++) {
	pdf_colorspace *cs = &p->colorspaces[i];

	/* don't write simple color spaces as resource */
	if (PDF_SIMPLE_COLORSPACE(cs))
	    continue;

	pdc_begin_obj(p->out, cs->obj_id);
	pdf_write_colorspace(p, i, pdc_true);
	pdc_puts(p->out, "\n");
	pdc_end_obj(p->out);			/* color space resource */

	pdf_write_colormap(p, i);		/* write pending colormaps */
    }
}

void
pdf_cleanup_colorspaces(PDF *p)
{
    static const char *fn = "pdf_cleanup_colorspaces";

    int i;

    if (!p->colorspaces)
	return;

    for (i = 0; i < p->colorspaces_number; i++) {
	pdf_colorspace *cs = &p->colorspaces[i];;

	switch (cs->type) {
	    case DeviceGray:
	    case DeviceRGB:
	    case DeviceCMYK:
	    case PatternCS:
	    break;

	    case Indexed:
	    if (cs->val.indexed.colormap)
		pdc_free(p->pdc, cs->val.indexed.colormap);
	    break;


	    default:
		pdc_error(p->pdc, PDF_E_INT_BADCS, fn,
		    pdc_errprintf(p->pdc, "%d", i),
		    pdc_errprintf(p->pdc, "%d", cs->type), 0);
	}
    }

    pdc_free(p->pdc, p->colorspaces);
    p->colorspaces = NULL;
}





static void
pdf_check_color_values(
    PDF *p,
    pdf_colorspacetype type,
    pdc_scalar c1, pdc_scalar c2, pdc_scalar c3, pdc_scalar c4)
{
    switch (type) {
        case DeviceGray:
        pdc_check_number_limits(p->pdc, "c1", c1, 0.0, EPSILON);
        break;

        case DeviceRGB:
        pdc_check_number_limits(p->pdc, "c1", c1, 0.0, EPSILON);
        pdc_check_number_limits(p->pdc, "c2", c2, 0.0, EPSILON);
        pdc_check_number_limits(p->pdc, "c3", c3, 0.0, EPSILON);

        break;

        case DeviceCMYK:
        pdc_check_number_limits(p->pdc, "c1", c1, 0.0, EPSILON);
        pdc_check_number_limits(p->pdc, "c2", c2, 0.0, EPSILON);
        pdc_check_number_limits(p->pdc, "c3", c3, 0.0, EPSILON);
        pdc_check_number_limits(p->pdc, "c4", c4, 0.0, EPSILON);
        break;



	case PatternCS:
        pdf_check_handle(p, (int) c1, pdc_patternhandle);
        if (c1 == p->pattern_number - 1 && PDF_GET_STATE(p) & pdf_state_pattern)
        {
            pdc_error(p->pdc, PDF_E_PATTERN_SELF, 0, 0, 0, 0);
        }
	break;

	case Separation:
        pdf_check_handle(p, (int) c1, pdc_colorhandle);
        pdc_check_number_limits(p->pdc, "c2", c2, 0.0, EPSILON);
	break;

	case Indexed:
	default:
	    break;
    }
} /* pdf_check_color_values */

static void
pdf_setcolor_internal(PDF *p, int drawmode, int colortype,
    pdc_scalar c1, pdc_scalar c2, pdc_scalar c3, pdc_scalar c4,
    pdf_color *fcolor)
{
    pdf_color c, cstroke;
    pdf_colorspace cs;

    if (PDF_GET_STATE(p) == pdf_state_pattern &&
        pdf_get_shading_painttype(p) == 2)
    {
        pdc_error(p->pdc, PDF_E_COLOR_INVALSPEC, 0, 0, 0, 0);
    }

    /* TODO: synchronize the PDF/X checks below with pdf_check_pdfx_colorspaces
    */
    switch (colortype)
    {
        case color_gray:
        cs.type = DeviceGray;
	c.cs = cs.type;
	c.val.gray = c1;
	pdf_check_color_values(p, cs.type, c1, c2, c3, c4);
        break;

        case color_rgb:
        cs.type = DeviceRGB;
	c.cs = cs.type;
	c.val.rgb.r = c1;
	c.val.rgb.g = c2;
	c.val.rgb.b = c3;
	pdf_check_color_values(p, cs.type, c1, c2, c3, c4);
        break;

        case color_cmyk:
        cs.type = DeviceCMYK;
	c.cs = cs.type;
	c.val.cmyk.c = c1;
	c.val.cmyk.m = c2;
	c.val.cmyk.y = c3;
	c.val.cmyk.k = c4;
	pdf_check_color_values(p, cs.type, c1, c2, c3, c4);
        break;

        case color_spotname:
        case color_spot:
        pdc_error(p->pdc, PDF_E_UNSUPP_SPOTCOLOR, 0, 0, 0, 0);
        break;

        case color_pattern:
        cs.type = PatternCS;
        if (p->pdc->hastobepos) c1 -= 1;
        c.val.pattern = (int) c1;
        pdf_check_color_values(p, cs.type, c1, c2, c3, c4);

        if (p->pattern[c.val.pattern].painttype == 1)
        {
	    cs.val.pattern.base = pdc_undef;
	    c.cs = pdf_add_colorspace(p, &cs, pdc_false);
            cstroke = c;
	}
        else if (p->pattern[c.val.pattern].painttype == 2)
        {
            if (drawmode == pdf_stroke || drawmode == pdf_fillstroke)
            {
                pdf_color *strokecolor = pdf_get_cstate(p, pdf_stroke);

                if (p->colorspaces[strokecolor->cs].type == PatternCS)
                    pdc_error(p->pdc, PDF_E_COLOR_INVALPATT, 0, 0, 0, 0);

                cstroke.val.pattern = (int) c1;
                cs.val.pattern.base = strokecolor->cs;
                cstroke.cs = pdf_add_colorspace(p, &cs, pdc_true);
            }

            if (drawmode == pdf_fill || drawmode == pdf_fillstroke)
            {
                pdf_color *fillcolor = pdf_get_cstate(p, pdf_fill);

                if (p->colorspaces[fillcolor->cs].type == PatternCS)
                    pdc_error(p->pdc, PDF_E_COLOR_INVALPATT, 0, 0, 0, 0);

                cs.val.pattern.base = fillcolor->cs;
                c.cs = pdf_add_colorspace(p, &cs, pdc_true);
            }
	}
        break;

        case color_iccbasedgray:
        case color_iccbasedrgb:
        case color_iccbasedcmyk:
        case color_lab:
        pdc_error(p->pdc, PDF_E_UNSUPP_ICCBASEDCOLOR, 0, 0, 0, 0);
        break;
    }



    if (fcolor == NULL)
    {
        if (colortype != color_pattern)
            cstroke = c;
        pdf_set_color_values(p, &c, &cstroke, (pdf_drawmode) drawmode);
    }
    else
    {
        *fcolor = c;
    }
}

static const pdc_keyconn pdf_fstype_keylist[] =
{
    {"stroke",     pdf_stroke},
    {"fill",       pdf_fill},
    {"fillstroke", pdf_stroke | pdf_fill},
    {"both",       pdf_stroke | pdf_fill},
    {NULL, 0}
};

void
pdf__setcolor(
    PDF *p,
    const char *fstype,
    const char *colorspace,
    pdc_scalar c1, pdc_scalar c2, pdc_scalar c3, pdc_scalar c4)
{
    int drawmode = (int) pdf_none;
    int colortype;

    if (!fstype || !*fstype)
        pdc_error(p->pdc, PDC_E_ILLARG_EMPTY, "fstype", 0, 0, 0);

    if (!colorspace || !*colorspace)
        pdc_error(p->pdc, PDC_E_ILLARG_EMPTY, "colorspace", 0, 0, 0);

    drawmode = pdc_get_keycode_ci(fstype, pdf_fstype_keylist);
    if (drawmode == PDC_KEY_NOTFOUND)
        pdc_error(p->pdc, PDC_E_ILLARG_STRING, "fstype", fstype, 0, 0);

    colortype = pdc_get_keycode_ci(colorspace, pdf_colortype_keylist);
    if (colortype == PDC_KEY_NOTFOUND)
        pdc_error(p->pdc, PDC_E_ILLARG_STRING, "colorspace", colorspace, 0, 0);

    pdf_setcolor_internal(p, drawmode, colortype, c1, c2, c3, c4, NULL);
}

void
pdf_set_default_color(PDF *p, pdc_bool reset)
{



    if (reset)
        pdf__setcolor(p, "fillstroke", "gray", 0, 0, 0, 0);
}


void
pdf_parse_coloropt(PDF *p, const char *optname, char **optvalue, int ns,
                   int maxtype, pdf_coloropt *c)
{
    int errcode = 0;
    const char *stemp = NULL;

    if (ns)
    {
        int i, j, n, iz = 0;
        double dz;

        c->type = pdc_get_keycode_ci(optvalue[0], pdf_colortype_keylist);
        if (c->type == PDC_KEY_NOTFOUND || c->type > maxtype)
        {
            stemp = pdc_errprintf(p->pdc,
                        "%.*s", PDC_ERR_MAXSTRLEN, optvalue[0]);
            errcode = PDC_E_OPT_ILLKEYWORD;
            goto PDF_COLOPT_ERROR;
        }

        if (c->type == (int) color_spotname || c->type == (int) color_spot)
        {
            errcode = PDF_E_UNSUPP_SPOTCOLOR;
            goto PDF_COLOPT_ERROR;
        }

        n = 1 + pdc_get_keycode_ci(optvalue[0], pdf_colorcomp_keylist);
        if (n != ns)
        {
            if (c->type == (int) color_spotname)
                n++;
            if (n != ns)
            {
                stemp = pdc_errprintf(p->pdc, "%d", n);
                errcode = n < ns ? PDC_E_OPT_TOOMANYVALUES :
                                   PDC_E_OPT_TOOFEWVALUES;
                goto PDF_COLOPT_ERROR;
            }
        }

        for (i = 0; i < 4; i++)
        {
            j = i + 1;
            if (i >= ns - 1)
            {
                if (!i || c->type != (int) color_gray)
                    c->value[i] = 0.0;
                else
                    c->value[i] = c->value[0];
            }
            else
            {
                if (!i && (c->type >= (int) color_spotname &&
                           c->type <= (int) color_pattern))
                {
                    c->name[0] =0;
                    if (pdc_str2integer(optvalue[j], 0, (pdc_sint32 *) &iz) ==
                        pdc_false)
                    {
                        {
                            stemp = pdc_errprintf(p->pdc, "%.*s",
                                               PDC_ERR_MAXSTRLEN, optvalue[j]);
                            errcode = PDC_E_OPT_ILLNUMBER;
                            goto PDF_COLOPT_ERROR;
                        }
                    }
                    c->value[i] = iz;
                }
                else
                {
                    if (pdc_str2double(optvalue[j], &dz) == pdc_false)
                    {
                        stemp = pdc_errprintf(p->pdc, "%.*s",
                                              PDC_ERR_MAXSTRLEN, optvalue[j]);
                        errcode = PDC_E_OPT_ILLNUMBER;
                        goto PDF_COLOPT_ERROR;
                    }
                    else
                        c->value[i] = dz;
                }
            }
        }

        if (c->type <= (int) color_cmyk)
        {
            for (i = 0; i < ns - 1; i++)
            {
                if (c->value[i] < 0 || c->value[i] > EPSILON)
                {
                    stemp = pdc_errprintf(p->pdc, "%f", c->value[i]);
                    errcode = PDC_E_OPT_ILLNUMBER;
                    goto PDF_COLOPT_ERROR;
                }
            }
        }
    }

    PDF_COLOPT_ERROR:

    if (errcode)
        pdc_error(p->pdc, errcode, optname, stemp, 0, 0);
}


void
pdf_set_coloropt(PDF *p, int drawmode, pdf_coloropt *c)
{
    if (c->type == (int) color_none)
        return;
    if (c->type == (int) color_spotname)
    {
        pdc_error(p->pdc, PDF_E_UNSUPP_SPOTCOLOR, 0, 0, 0, 0);
    }

    pdf_setcolor_internal(p, drawmode, c->type,
                          c->value[0], c->value[1], c->value[2], c->value[3],
                          NULL);
}

void
pdf_init_coloropt(PDF *p, pdf_coloropt *c)
{
    (void) p;

    {
	c->name[0] = 0;
	c->type = (int) color_gray;
	c->value[0] = 0;
	c->value[1] = 0;
	c->value[2] = 0;
	c->value[3] = 0;
    }
}

void
pdf_logg_coloropt(PDF *p, pdf_coloropt *c, pdc_bool newline)
{
    const char *keyword =
    pdc_get_keyword((int) c->type, pdf_colortype_keylist);

    pdc_logg(p->pdc, "{%s ", keyword);

    switch (c->type)
    {
        case color_gray:
        case color_iccbasedgray:
        case color_pattern:
        case color_spot:
        pdc_logg(p->pdc, "%g}", c->value[0]);
        break;

        case color_rgb:
        case color_iccbasedrgb:
        case color_lab:
        pdc_logg(p->pdc, "%g %g %g}", c->value[0], c->value[1], c->value[2]);
        break;

        case color_cmyk:
        case color_iccbasedcmyk:
        pdc_logg(p->pdc, "%g %g %g %g}", c->value[0], c->value[1],
                                     c->value[2], c->value[3]);
        break;

        case color_spotname:
        pdc_logg(p->pdc, "{%s} %g}", c->name, c->value[0]);
        break;

        default:
        pdc_logg(p->pdc, "}");
        break;
    }

    if (newline)
        pdc_logg(p->pdc, "\n");
}
