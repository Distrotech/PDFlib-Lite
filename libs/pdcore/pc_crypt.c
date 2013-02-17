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

/* $Id: pc_crypt.c,v 1.74.2.13 2008/12/02 12:19:46 stm Exp $
 *
 * Routines for PDF encryption and decryption
 *
 */

#include "time.h"

#include "pc_util.h"
#include "pc_md5.h"
#include "pc_crypt.h"


static void pdc_pd_crypt_c(void) {}

