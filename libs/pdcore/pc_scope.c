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

/* $Id: pc_scope.c,v 1.110.2.48 2010/04/22 09:16:26 rjs Exp $
 *
 * Scoping routines and macros
 *
 */

#include "pc_util.h"
#include "pc_scope.h"
#include "pc_file.h"
#include "pc_ctype.h"


static void pdc_check_scope_core(void) {}

