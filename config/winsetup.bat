@echo off
rem Set up build environment for Windows builds with nmake
rem $Id: winsetup.bat,v 1.6.2.2 2008/02/25 12:37:22 rjs Exp $

rem you need to set up the environment for VC++, e.g.
rem "C:\Program Files\Microsoft Visual Studio\VC98\Bin\VCVARS32.BAT"

@copy mkbind.inc.win mkbind.inc
@copy mkcommon.inc.win mkcommon.inc
@copy mklibs.inc.win mklibs.inc
@copy mkmainlib.inc.win mkmainlib.inc
@copy mkprogs.inc.win mkprogs.inc
@copy mksubdirs.inc.win mksubdirs.inc
@copy mkpsubdirs.inc.win mkpsubdirs.inc
@IF EXIST mkats.inc.win copy mkats.inc.win mkats.inc

echo Now you can use nmake to build PDFlib
echo To build different configurations you can call nmake as follows:
echo nmake TARGET=CONFIG
echo where CONFIG may be one of Debug Release_DLL Release_MD Release_NET
