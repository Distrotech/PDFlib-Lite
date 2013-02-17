/*---------------------------------------------------------------------------*
 |              PDFlib - A library for generating PDF on the fly             |
 +---------------------------------------------------------------------------+
 | Copyright (c) 1997-2009 Thomas Merz and PDFlib GmbH. All rights reserved. |
 +---------------------------------------------------------------------------+
 |                                                                           |
 |    This software is subject to the PDFlib license. It is NOT in the       |
 |    public domain. Extended versions and commercial licenses are           |
 |    available, please check http://www.pdflib.com.                         |
 |                                                                           |
 *---------------------------------------------------------------------------*/

/* $Id: p_block.c,v 1.169.2.25 2010/04/20 11:52:15 tm Exp $
 *
 * Block processing routines (require the PDI library)
 *
 */

#define P_BLOCK_C

#include "p_intern.h"
#include "p_color.h"
#include "p_font.h"
#include "p_image.h"
#include "p_defopt.h"

