# Microsoft Developer Studio Project File - Name="pdcore" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=pdcore - Win32 Debug DLL TET
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "pdcore.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "pdcore.mak" CFG="pdcore - Win32 Debug DLL TET"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "pdcore - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "pdcore - Win32 Release DLL" (based on "Win32 (x86) Static Library")
!MESSAGE "pdcore - Win32 Release mtDLL" (based on "Win32 (x86) Static Library")
!MESSAGE "pdcore - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "pdcore - Win32 Debug DLL" (based on "Win32 (x86) Static Library")
!MESSAGE "pdcore - Win32 Release PLOP" (based on "Win32 (x86) Static Library")
!MESSAGE "pdcore - Win32 Release DLL PLOP" (based on "Win32 (x86) Static Library")
!MESSAGE "pdcore - Win32 Release mtDLL PLOP" (based on "Win32 (x86) Static Library")
!MESSAGE "pdcore - Win32 Debug PLOP" (based on "Win32 (x86) Static Library")
!MESSAGE "pdcore - Win32 Debug DLL PLOP" (based on "Win32 (x86) Static Library")
!MESSAGE "pdcore - Win32 Release TET" (based on "Win32 (x86) Static Library")
!MESSAGE "pdcore - Win32 Release DLL TET" (based on "Win32 (x86) Static Library")
!MESSAGE "pdcore - Win32 Release mtDLL TET" (based on "Win32 (x86) Static Library")
!MESSAGE "pdcore - Win32 Debug TET" (based on "Win32 (x86) Static Library")
!MESSAGE "pdcore - Win32 Debug DLL TET" (based on "Win32 (x86) Static Library")
!MESSAGE "pdcore - Win32 Release pCOS" (based on "Win32 (x86) Static Library")
!MESSAGE "pdcore - Win32 Release DLL pCOS" (based on "Win32 (x86) Static Library")
!MESSAGE "pdcore - Win32 Release mtDLL pCOS" (based on "Win32 (x86) Static Library")
!MESSAGE "pdcore - Win32 Debug pCOS" (based on "Win32 (x86) Static Library")
!MESSAGE "pdcore - Win32 Debug DLL pCOS" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "pdcore - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MT /W3 /O2 /I "../pdi" /I "../flate" /I "../pdflib" /I "../expat" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"pdcore.lib"

!ELSEIF  "$(CFG)" == "pdcore - Win32 Release DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release_DLL"
# PROP BASE Intermediate_Dir "Release_DLL"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release_DLL"
# PROP Intermediate_Dir "Release_DLL"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O2 /I "../pdi" /I "../flate" /I "../pdflib" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD CPP /nologo /MT /W3 /O2 /I "../pdi" /I "../flate" /I "../pdflib" /I "../expat" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"pdcore.lib"
# ADD LIB32 /nologo /out:"pdcore.lib"

!ELSEIF  "$(CFG)" == "pdcore - Win32 Release mtDLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release_mtDLL"
# PROP BASE Intermediate_Dir "Release_mtDLL"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release_mtDLL"
# PROP Intermediate_Dir "Release_mtDLL"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O2 /I "..\pdflib" /I "..\flate" /I "..\tiff" /I "..\png" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD CPP /nologo /MD /W3 /O2 /I "../pdi" /I "../flate" /I "../pdflib" /I "../expat" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"pdcore.lib"

!ELSEIF  "$(CFG)" == "pdcore - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../pdi" /I "../flate" /I "../pdflib" /I "../expat" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"pdcore.lib"

!ELSEIF  "$(CFG)" == "pdcore - Win32 Debug DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug_DLL"
# PROP BASE Intermediate_Dir "Debug_DLL"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug_DLL"
# PROP Intermediate_Dir "Debug_DLL"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../pdi" /I "../flate" /I "../pdflib" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../pdi" /I "../flate" /I "../pdflib" /I "../expat" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"pdcore.lib"
# ADD LIB32 /nologo /out:"pdcore.lib"

!ELSEIF  "$(CFG)" == "pdcore - Win32 Release PLOP"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release_PLOP"
# PROP BASE Intermediate_Dir "Release_PLOP"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release_PLOP"
# PROP Intermediate_Dir "Release_PLOP"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O2 /I "../pdi" /I "../flate" /I "../pdflib" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD CPP /nologo /MT /W3 /O2 /I "../pdi" /I "../flate" /I "../pdflib" /I "../expat" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PLOP_BUILD" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"pdcore.lib"

!ELSEIF  "$(CFG)" == "pdcore - Win32 Release DLL PLOP"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release_DLL_PLOP"
# PROP BASE Intermediate_Dir "Release_DLL_PLOP"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release_DLL_PLOP"
# PROP Intermediate_Dir "Release_DLL_PLOP"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O2 /I "../pdi" /I "../flate" /I "../pdflib" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PLOP_BUILD" /YX /FD /c
# ADD CPP /nologo /MT /W3 /O2 /I "../pdi" /I "../flate" /I "../pdflib" /I "../expat" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PLOP_BUILD" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"pdcore.lib"
# ADD LIB32 /nologo /out:"pdcore.lib"

!ELSEIF  "$(CFG)" == "pdcore - Win32 Release mtDLL PLOP"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release_mtDLL_PLOP"
# PROP BASE Intermediate_Dir "Release_mtDLL_PLOP"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release_mtDLL_PLOP"
# PROP Intermediate_Dir "Release_mtDLL_PLOP"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O2 /I "../pdi" /I "../flate" /I "../pdflib" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PLOP_BUILD" /YX /FD /c
# ADD CPP /nologo /MD /W3 /O2 /I "../pdi" /I "../flate" /I "../pdflib" /I "../expat" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PLOP_BUILD" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"pdcore.lib"

!ELSEIF  "$(CFG)" == "pdcore - Win32 Debug PLOP"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug_PLOP"
# PROP BASE Intermediate_Dir "Debug_PLOP"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug_PLOP"
# PROP Intermediate_Dir "Debug_PLOP"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../pdi" /I "../flate" /I "../pdflib" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../pdi" /I "../flate" /I "../pdflib" /I "../expat" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PLOP_BUILD" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"pdcore.lib"
# ADD LIB32 /nologo /out:"pdcore.lib"

!ELSEIF  "$(CFG)" == "pdcore - Win32 Debug DLL PLOP"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug_DLL_PLOP"
# PROP BASE Intermediate_Dir "Debug_DLL_PLOP"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug_DLL_PLOP"
# PROP Intermediate_Dir "Debug_DLL_PLOP"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../pdi" /I "../flate" /I "../pdflib" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PLOP_BUILD" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../pdi" /I "../flate" /I "../pdflib" /I "../expat" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PLOP_BUILD" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"pdcore.lib"
# ADD LIB32 /nologo /out:"pdcore.lib"

!ELSEIF  "$(CFG)" == "pdcore - Win32 Release TET"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release_TET"
# PROP BASE Intermediate_Dir "Release_TET"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release_TET"
# PROP Intermediate_Dir "Release_TET"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O2 /I "../pdi" /I "../flate" /I "../pdflib" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_TET_BUILD" /YX /FD /c
# ADD CPP /nologo /MT /W3 /O2 /I "../pdi" /I "../flate" /I "../pdflib" /I "../expat" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_TET_BUILD" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"pdcore.lib"
# ADD LIB32 /nologo /out:"pdcore.lib"

!ELSEIF  "$(CFG)" == "pdcore - Win32 Release DLL TET"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release_DLL_TET"
# PROP BASE Intermediate_Dir "Release_DLL_TET"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release_DLL_TET"
# PROP Intermediate_Dir "Release_DLL_TET"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O2 /I "../pdi" /I "../flate" /I "../pdflib" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_TET_BUILD" /YX /FD /c
# ADD CPP /nologo /MT /W3 /O2 /I "../pdi" /I "../flate" /I "../pdflib" /I "../expat" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_TET_BUILD" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"pdcore.lib"
# ADD LIB32 /nologo /out:"pdcore.lib"

!ELSEIF  "$(CFG)" == "pdcore - Win32 Release mtDLL TET"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release_TET_mtDLL"
# PROP BASE Intermediate_Dir "Release_TET_mtDLL"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release_TET_mtDLL"
# PROP Intermediate_Dir "Release_TET_mtDLL"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O2 /I "..\pdflib" /I "..\flate" /I "..\tiff" /I "..\png" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_TET_BUILD" /YX /FD /c
# ADD CPP /nologo /MD /W3 /O2 /I "../pdi" /I "../flate" /I "../pdflib" /I "../expat" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_TET_BUILD" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"pdcore.lib"

!ELSEIF  "$(CFG)" == "pdcore - Win32 Debug TET"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug_TET"
# PROP BASE Intermediate_Dir "Debug_TET"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug_TET"
# PROP Intermediate_Dir "Debug_TET"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../pdi" /I "../flate" /I "../pdflib" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_TET_BUILD" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../pdi" /I "../flate" /I "../pdflib" /I "../expat" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_TET_BUILD" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"pdcore.lib"
# ADD LIB32 /nologo /out:"pdcore.lib"

!ELSEIF  "$(CFG)" == "pdcore - Win32 Debug DLL TET"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug_DLL_TET"
# PROP BASE Intermediate_Dir "Debug_DLL_TET"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug_DLL_TET"
# PROP Intermediate_Dir "Debug_DLL_TET"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../pdi" /I "../flate" /I "../pdflib" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_TET_BUILD" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../pdi" /I "../flate" /I "../pdflib" /I "../expat" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_TET_BUILD" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"pdcore.lib"
# ADD LIB32 /nologo /out:"pdcore.lib"

!ELSEIF  "$(CFG)" == "pdcore - Win32 Release pCOS"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release_pCOS"
# PROP BASE Intermediate_Dir "Release_pCOS"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release_pCOS"
# PROP Intermediate_Dir "Release_pCOS"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O2 /I "../pdi" /I "../flate" /I "../pdflib" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PCOS_BUILD" /YX /FD /c
# ADD CPP /nologo /MT /W3 /O2 /I "../pdi" /I "../flate" /I "../pdflib" /I "../expat" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PCOS_BUILD" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"pdcore.lib"
# ADD LIB32 /nologo /out:"pdcore.lib"

!ELSEIF  "$(CFG)" == "pdcore - Win32 Release DLL pCOS"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release_DLL_pCOS"
# PROP BASE Intermediate_Dir "Release_DLL_pCOS"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release_DLL_pCOS"
# PROP Intermediate_Dir "Release_DLL_pCOS"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O2 /I "../pdi" /I "../flate" /I "../pdflib" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PCOS_BUILD" /YX /FD /c
# ADD CPP /nologo /MT /W3 /O2 /I "../pdi" /I "../flate" /I "../pdflib" /I "../expat" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PCOS_BUILD" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"pdcore.lib"
# ADD LIB32 /nologo /out:"pdcore.lib"

!ELSEIF  "$(CFG)" == "pdcore - Win32 Release mtDLL pCOS"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release_mtDLL_pCOS"
# PROP BASE Intermediate_Dir "Release_mtDLL_pCOS"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release_mtDLL_pCOS"
# PROP Intermediate_Dir "Release_mtDLL_pCOS"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O2 /I "..\pdflib" /I "..\flate" /I "..\tiff" /I "..\png" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_pCOS_BUILD" /YX /FD /c
# ADD CPP /nologo /MD /W3 /O2 /I "../pdi" /I "../flate" /I "../pdflib" /I "../expat" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_pCOS_BUILD" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"pdcore.lib"

!ELSEIF  "$(CFG)" == "pdcore - Win32 Debug pCOS"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug_pCOS"
# PROP BASE Intermediate_Dir "Debug_pCOS"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug_pCOS"
# PROP Intermediate_Dir "Debug_pCOS"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../pdi" /I "../flate" /I "../pdflib" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PCOS_BUILD" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../pdi" /I "../flate" /I "../pdflib" /I "../expat" /D "PDFLIB_PCOS_BUILD" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"pdcore.lib"
# ADD LIB32 /nologo /out:"pdcore.lib"

!ELSEIF  "$(CFG)" == "pdcore - Win32 Debug DLL pCOS"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug_DLL_pCOS"
# PROP BASE Intermediate_Dir "Debug_DLL_pCOS"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug_DLL_pCOS"
# PROP Intermediate_Dir "Debug_DLL_pCOS"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../pdi" /I "../flate" /I "../pdflib" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PCOS_BUILD" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../pdi" /I "../flate" /I "../pdflib" /I "../expat" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PCOS_BUILD" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"pdcore.lib"
# ADD LIB32 /nologo /out:"pdcore.lib"

!ENDIF 

# Begin Target

# Name "pdcore - Win32 Release"
# Name "pdcore - Win32 Release DLL"
# Name "pdcore - Win32 Release mtDLL"
# Name "pdcore - Win32 Debug"
# Name "pdcore - Win32 Debug DLL"
# Name "pdcore - Win32 Release PLOP"
# Name "pdcore - Win32 Release DLL PLOP"
# Name "pdcore - Win32 Release mtDLL PLOP"
# Name "pdcore - Win32 Debug PLOP"
# Name "pdcore - Win32 Debug DLL PLOP"
# Name "pdcore - Win32 Release TET"
# Name "pdcore - Win32 Release DLL TET"
# Name "pdcore - Win32 Release mtDLL TET"
# Name "pdcore - Win32 Debug TET"
# Name "pdcore - Win32 Debug DLL TET"
# Name "pdcore - Win32 Release pCOS"
# Name "pdcore - Win32 Release DLL pCOS"
# Name "pdcore - Win32 Release mtDLL pCOS"
# Name "pdcore - Win32 Debug pCOS"
# Name "pdcore - Win32 Debug DLL pCOS"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\pc_aes.c
# End Source File
# Begin Source File

SOURCE=.\pc_aescbc.c
# End Source File
# Begin Source File

SOURCE=.\pc_arc4.c
# End Source File
# Begin Source File

SOURCE=.\pc_chartabs.c
# End Source File
# Begin Source File

SOURCE=.\pc_contain.c
# End Source File
# Begin Source File

SOURCE=.\pc_core.c
# End Source File
# Begin Source File

SOURCE=.\pc_crypt.c
# End Source File
# Begin Source File

SOURCE=.\pc_ctype.c
# End Source File
# Begin Source File

SOURCE=.\pc_digsig.c
# End Source File
# Begin Source File

SOURCE=.\pc_ebcdic.c
# End Source File
# Begin Source File

SOURCE=.\pc_encoding.c
# End Source File
# Begin Source File

SOURCE=.\pc_file.c
# End Source File
# Begin Source File

SOURCE=.\pc_geom.c
# End Source File
# Begin Source File

SOURCE=.\pc_md5.c
# End Source File
# Begin Source File

SOURCE=.\pc_optparse.c
# End Source File
# Begin Source File

SOURCE=.\pc_output.c
# End Source File
# Begin Source File

SOURCE=.\pc_resource.c
# End Source File
# Begin Source File

SOURCE=.\pc_scan.c
# End Source File
# Begin Source File

SOURCE=.\pc_scope.c
# End Source File
# Begin Source File

SOURCE=.\pc_string.c
# End Source File
# Begin Source File

SOURCE=.\pc_unicode.c
# End Source File
# Begin Source File

SOURCE=.\pc_util.c
# End Source File
# Begin Source File

SOURCE=.\pc_xmp.c
# End Source File
# End Group
# End Target
# End Project
