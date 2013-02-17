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

/* $Id: p_textflow.c,v 1.306.2.141 2010/03/18 12:02:29 kurt Exp $
 *
 * PDFlib textflow function
 *
 */

#define P_TEXTFLOW_C

#include "p_intern.h"
#include "p_color.h"
#include "p_font.h"
#include "p_defopt.h"
#include "p_tagged.h"


