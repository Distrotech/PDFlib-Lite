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

/* $Id: p_table.c,v 1.88.2.43 2009/07/31 10:41:03 kurt Exp $
 *
 * PDFlib table function
 *
 */

#define P_TABLE_C

#include "p_intern.h"
#include "p_color.h"
#include "p_defopt.h"
#include "p_font.h"
#include "p_tagged.h"

