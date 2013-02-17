/*---------------------------------------------------------------------------*
 |              PDFlib - A library for generating PDF on the fly             |
 +---------------------------------------------------------------------------+
 | Copyright (c) 1997-2006 Thomas Merz and PDFlib GmbH. All rights reserved. |
 +---------------------------------------------------------------------------+
 |                                                                           |
 |    This software is subject to the PDFlib license. It is NOT in the       |
 |    public domain. Extended versions and commercial licenses are           |
 |    available, please check http://www.pdflib.com.                         |
 |                                                                           |
 *---------------------------------------------------------------------------*/

/* $Id: p_subsett.c,v 1.104.2.25 2009/03/26 14:28:04 kurt Exp $
 *
 * PDFlib subsetting routines
 *
 */

#include <time.h>

#include "p_intern.h"
#include "p_font.h"

#include "ft_truetype.h"
#include "pc_md5.h"

