# Microsoft Developer Studio Project File - Name="jpeg" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=jpeg - Win32 Debug DLL TET
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "jpeg.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "jpeg.mak" CFG="jpeg - Win32 Debug DLL TET"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "jpeg - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "jpeg - Win32 Release DLL" (based on "Win32 (x86) Static Library")
!MESSAGE "jpeg - Win32 Release mtDLL" (based on "Win32 (x86) Static Library")
!MESSAGE "jpeg - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "jpeg - Win32 Debug DLL" (based on "Win32 (x86) Static Library")
!MESSAGE "jpeg - Win32 Release TET" (based on "Win32 (x86) Static Library")
!MESSAGE "jpeg - Win32 Release DLL TET" (based on "Win32 (x86) Static Library")
!MESSAGE "jpeg - Win32 Release mtDLL TET" (based on "Win32 (x86) Static Library")
!MESSAGE "jpeg - Win32 Debug TET" (based on "Win32 (x86) Static Library")
!MESSAGE "jpeg - Win32 Debug DLL TET" (based on "Win32 (x86) Static Library")
!MESSAGE "jpeg - Win32 Release pCOS" (based on "Win32 (x86) Static Library")
!MESSAGE "jpeg - Win32 Release DLL pCOS" (based on "Win32 (x86) Static Library")
!MESSAGE "jpeg - Win32 Release mtDLL pCOS" (based on "Win32 (x86) Static Library")
!MESSAGE "jpeg - Win32 Debug pCOS" (based on "Win32 (x86) Static Library")
!MESSAGE "jpeg - Win32 Debug DLL pCOS" (based on "Win32 (x86) Static Library")
!MESSAGE "jpeg - Win32 Release PLOP" (based on "Win32 (x86) Static Library")
!MESSAGE "jpeg - Win32 Release DLL PLOP" (based on "Win32 (x86) Static Library")
!MESSAGE "jpeg - Win32 Release mtDLL PLOP" (based on "Win32 (x86) Static Library")
!MESSAGE "jpeg - Win32 Debug PLOP" (based on "Win32 (x86) Static Library")
!MESSAGE "jpeg - Win32 Debug DLL PLOP" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "jpeg - Win32 Release"

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
# ADD CPP /nologo /MT /W3 /O2 /I "../pdcore" /I "../flate" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"jpeg.lib"

!ELSEIF  "$(CFG)" == "jpeg - Win32 Release DLL"

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
# ADD BASE CPP /nologo /MT /W3 /O2 /I "../pdcore" /I "../flate" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD CPP /nologo /MT /W3 /O2 /I "../pdcore" /I "../flate" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"jpeg.lib"
# ADD LIB32 /nologo /out:"jpeg.lib"

!ELSEIF  "$(CFG)" == "jpeg - Win32 Release mtDLL"

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
# ADD BASE CPP /nologo /MT /W3 /O2 /I "../pdflib" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD CPP /nologo /MD /W3 /O2 /I "../pdcore" /I "../flate" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"jpeg.lib"
# ADD LIB32 /nologo /out:"jpeg.lib"

!ELSEIF  "$(CFG)" == "jpeg - Win32 Debug"

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
# ADD CPP /nologo /MTd /W3 /Gm /ZI /Od /I "../pdcore" /I "../flate" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /GZ /c
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"jpeg.lib"

!ELSEIF  "$(CFG)" == "jpeg - Win32 Debug DLL"

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
# ADD BASE CPP /nologo /MTd /W3 /Gm /ZI /Od /I "../pdcore" /I "../flate" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /ZI /Od /I "../pdcore" /I "../flate" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /GZ /c
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"jpeg.lib"
# ADD LIB32 /nologo /out:"jpeg.lib"

!ELSEIF  "$(CFG)" == "jpeg - Win32 Release TET"

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
# ADD BASE CPP /nologo /MT /W3 /O2 /I "../pdcore" /I "../flate" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD CPP /nologo /MT /W3 /O2 /I "../pdcore" /I "../flate" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_TET_BUILD" /YX /FD /c
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"jpeg.lib"
# ADD LIB32 /nologo /out:"jpeg.lib"

!ELSEIF  "$(CFG)" == "jpeg - Win32 Release DLL TET"

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
# ADD BASE CPP /nologo /MT /W3 /O2 /I "../pdcore" /I "../flate" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD CPP /nologo /MT /W3 /O2 /I "../pdcore" /I "../flate" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_TET_BUILD" /YX /FD /c
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"jpeg.lib"
# ADD LIB32 /nologo /out:"jpeg.lib"

!ELSEIF  "$(CFG)" == "jpeg - Win32 Release mtDLL TET"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release_mtDLL_TET"
# PROP BASE Intermediate_Dir "Release_mtDLL_TET"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release_mtDLL_TET"
# PROP Intermediate_Dir "Release_mtDLL_TET"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O2 /I "../pdflib" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD CPP /nologo /MD /W3 /O2 /I "../pdcore" /I "../flate" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c /D "PDFLIB_TET_BUILD"
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"jpeg.lib"
# ADD LIB32 /nologo /out:"jpeg.lib"

!ELSEIF  "$(CFG)" == "jpeg - Win32 Debug TET"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release_mtDLL_TET"
# PROP BASE Intermediate_Dir "Release_mtDLL_TET"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release_mtDLL_TET"
# PROP Intermediate_Dir "Release_mtDLL_TET"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /Gm /ZI /O2 /I "../pdcore" /I "../flate" /I "../pdflib" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "NDEBUG" /YX /FD /GZ  /c
# ADD CPP /nologo /MD /W3 /Gm /ZI /Od /I "../pdcore" /I "../flate" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_TET_BUILD" /D "NDEBUG" /YX /FD /GZ  /c
# ADD BASE RSC /l 0x407 /d "_DEBUG" /d "NDEBUG"
# ADD RSC /l 0x407 /d "_DEBUG" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"jpeg.lib"
# ADD LIB32 /nologo /out:"jpeg.lib"

!ELSEIF  "$(CFG)" == "jpeg - Win32 Debug DLL TET"

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
# ADD BASE CPP /nologo /MTd /W3 /Gm /ZI /Od /I "../pdcore" /I "../flate" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /ZI /Od /I "../pdcore" /I "../flate" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_TET_BUILD" /YX /FD /GZ /c
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"jpeg.lib"
# ADD LIB32 /nologo /out:"jpeg.lib"

!ELSEIF  "$(CFG)" == "jpeg - Win32 Release pCOS"

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
# ADD BASE CPP /nologo /MT /W3 /O2 /I "../pdcore" /I "../flate" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD CPP /nologo /MT /W3 /O2 /I "../pdcore" /I "../flate" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PCOS_BUILD" /YX /FD /c
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"jpeg.lib"
# ADD LIB32 /nologo /out:"jpeg.lib"

!ELSEIF  "$(CFG)" == "jpeg - Win32 Release DLL pCOS"

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
# ADD BASE CPP /nologo /MT /W3 /O2 /I "../pdcore" /I "../flate" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD CPP /nologo /MT /W3 /O2 /I "../pdcore" /I "../flate" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PCOS_BUILD" /YX /FD /c
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"jpeg.lib"
# ADD LIB32 /nologo /out:"jpeg.lib"

!ELSEIF  "$(CFG)" == "jpeg - Win32 Release mtDLL pCOS"

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
# ADD BASE CPP /nologo /MT /W3 /O2 /I "../pdflib" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD CPP /nologo /MD /W3 /O2 /I "../pdcore" /I "../flate" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c /D "PDFLIB_PCOS_BUILD"
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"jpeg.lib"
# ADD LIB32 /nologo /out:"jpeg.lib"

!ELSEIF  "$(CFG)" == "jpeg - Win32 Debug pCOS"

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
# ADD BASE CPP /nologo /MT /W3 /Gm /ZI /O2 /I "../pdcore" /I "../flate" /I "../pdflib" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "NDEBUG" /YX /FD /GZ  /c
# ADD CPP /nologo /MD /W3 /Gm /ZI /Od /I "../pdcore" /I "../flate" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PCOS_BUILD" /D "NDEBUG" /YX /FD /GZ  /c
# ADD BASE RSC /l 0x407 /d "_DEBUG" /d "NDEBUG"
# ADD RSC /l 0x407 /d "_DEBUG" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"jpeg.lib"
# ADD LIB32 /nologo /out:"jpeg.lib"

!ELSEIF  "$(CFG)" == "jpeg - Win32 Debug DLL pCOS"

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
# ADD BASE CPP /nologo /MTd /W3 /Gm /ZI /Od /I "../pdcore" /I "../flate" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /ZI /Od /I "../pdcore" /I "../flate" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PCOS_BUILD" /YX /FD /GZ /c
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"jpeg.lib"
# ADD LIB32 /nologo /out:"jpeg.lib"

!ELSEIF  "$(CFG)" == "jpeg - Win32 Release PLOP"

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
# ADD BASE CPP /nologo /MT /W3 /O2 /I "../pdcore" /I "../flate" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD CPP /nologo /MT /W3 /O2 /I "../pdcore" /I "../flate" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PLOP_BUILD" /YX /FD /c
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"jpeg.lib"
# ADD LIB32 /nologo /out:"jpeg.lib"

!ELSEIF  "$(CFG)" == "jpeg - Win32 Release DLL PLOP"

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
# ADD BASE CPP /nologo /MT /W3 /O2 /I "../pdcore" /I "../flate" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD CPP /nologo /MT /W3 /O2 /I "../pdcore" /I "../flate" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PLOP_BUILD" /YX /FD /c
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"jpeg.lib"
# ADD LIB32 /nologo /out:"jpeg.lib"

!ELSEIF  "$(CFG)" == "jpeg - Win32 Release mtDLL PLOP"

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
# ADD BASE CPP /nologo /MT /W3 /O2 /I "../pdflib" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD CPP /nologo /MD /W3 /O2 /I "../pdcore" /I "../flate" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c /D "PDFLIB_PLOP_BUILD"
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"jpeg.lib"
# ADD LIB32 /nologo /out:"jpeg.lib"

!ELSEIF  "$(CFG)" == "jpeg - Win32 Debug PLOP"

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
# ADD BASE CPP /nologo /MT /W3 /Gm /ZI /O2 /I "../pdcore" /I "../flate" /I "../pdflib" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "NDEBUG" /YX /FD /GZ  /c
# ADD CPP /nologo /MD /W3 /Gm /ZI /Od /I "../pdcore" /I "../flate" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PLOP_BUILD" /D "NDEBUG" /YX /FD /GZ  /c
# ADD BASE RSC /l 0x407 /d "_DEBUG" /d "NDEBUG"
# ADD RSC /l 0x407 /d "_DEBUG" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"jpeg.lib"
# ADD LIB32 /nologo /out:"jpeg.lib"

!ELSEIF  "$(CFG)" == "jpeg - Win32 Debug DLL PLOP"

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
# ADD BASE CPP /nologo /MTd /W3 /Gm /ZI /Od /I "../pdcore" /I "../flate" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /ZI /Od /I "../pdcore" /I "../flate" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_PLOP_BUILD" /YX /FD /GZ /c
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"jpeg.lib"
# ADD LIB32 /nologo /out:"jpeg.lib"

!ENDIF 

# Begin Target

# Name "jpeg - Win32 Release"
# Name "jpeg - Win32 Release DLL"
# Name "jpeg - Win32 Release mtDLL"
# Name "jpeg - Win32 Debug"
# Name "jpeg - Win32 Debug DLL"
# Name "jpeg - Win32 Release TET"
# Name "jpeg - Win32 Release DLL TET"
# Name "jpeg - Win32 Release mtDLL TET"
# Name "jpeg - Win32 Debug TET"
# Name "jpeg - Win32 Debug DLL TET"
# Name "jpeg - Win32 Release pCOS"
# Name "jpeg - Win32 Release DLL pCOS"
# Name "jpeg - Win32 Release mtDLL pCOS"
# Name "jpeg - Win32 Debug pCOS"
# Name "jpeg - Win32 Debug DLL pCOS"
# Name "jpeg - Win32 Release PLOP"
# Name "jpeg - Win32 Release DLL PLOP"
# Name "jpeg - Win32 Release mtDLL PLOP"
# Name "jpeg - Win32 Debug PLOP"
# Name "jpeg - Win32 Debug DLL PLOP"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\jcapimin.c

# End Source File
# Begin Source File

SOURCE=.\jcapistd.c

# End Source File
# Begin Source File

SOURCE=.\jccoefct.c

# End Source File
# Begin Source File

SOURCE=.\jccolor.c
# End Source File
# Begin Source File

SOURCE=.\jcdctmgr.c

# End Source File
# Begin Source File

SOURCE=.\jchuff.c

# End Source File
# Begin Source File

SOURCE=.\jcinit.c

# End Source File
# Begin Source File

SOURCE=.\jcmainct.c

# End Source File
# Begin Source File

SOURCE=.\jcmarker.c

# End Source File
# Begin Source File

SOURCE=.\jcmaster.c

# End Source File
# Begin Source File

SOURCE=.\jcomapi.c

# End Source File
# Begin Source File

SOURCE=.\jcparam.c

# End Source File
# Begin Source File

SOURCE=.\jcphuff.c

# End Source File
# Begin Source File

SOURCE=.\jcprepct.c

# End Source File
# Begin Source File

SOURCE=.\jcsample.c

# End Source File
# Begin Source File

SOURCE=.\jctrans.c

# End Source File
# Begin Source File

SOURCE=.\jdapimin.c

# End Source File
# Begin Source File

SOURCE=.\jdapistd.c

# End Source File
# Begin Source File

SOURCE=.\jdatadst.c

# End Source File
# Begin Source File

SOURCE=.\jdatasrc.c

# End Source File
# Begin Source File

SOURCE=.\jdcoefct.c

# End Source File
# Begin Source File

SOURCE=.\jdcolor.c

# End Source File
# Begin Source File

SOURCE=.\jddctmgr.c

# End Source File
# Begin Source File

SOURCE=.\jdhuff.c

# End Source File
# Begin Source File

SOURCE=.\jdinput.c

# End Source File
# Begin Source File

SOURCE=.\jdmainct.c

# End Source File
# Begin Source File

SOURCE=.\jdmarker.c

# End Source File
# Begin Source File

SOURCE=.\jdmaster.c

# End Source File
# Begin Source File

SOURCE=.\jdmerge.c

# End Source File
# Begin Source File

SOURCE=.\jdphuff.c

# End Source File
# Begin Source File

SOURCE=.\jdpostct.c

# End Source File
# Begin Source File

SOURCE=.\jdsample.c

# End Source File
# Begin Source File

SOURCE=.\jdtrans.c

# End Source File
# Begin Source File

SOURCE=.\jerror.c

# End Source File
# Begin Source File

SOURCE=.\jfdctflt.c

# End Source File
# Begin Source File

SOURCE=.\jfdctfst.c

# End Source File
# Begin Source File

SOURCE=.\jfdctint.c

# End Source File
# Begin Source File

SOURCE=.\jidctflt.c

# End Source File
# Begin Source File

SOURCE=.\jidctfst.c

# End Source File
# Begin Source File

SOURCE=.\jidctint.c

# End Source File
# Begin Source File

SOURCE=.\jidctred.c

# End Source File
# Begin Source File

SOURCE=.\jmemmgr.c

# End Source File
# Begin Source File

SOURCE=.\jmemnobs.c

# End Source File
# Begin Source File

SOURCE=.\jquant1.c

# End Source File
# Begin Source File

SOURCE=.\jquant2.c

# End Source File
# Begin Source File

SOURCE=.\jutils.c

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "*.h"
# Begin Source File

SOURCE=.\jchuff.h
# End Source File
# Begin Source File

SOURCE=.\jconfig.h
# End Source File
# Begin Source File

SOURCE=.\jdct.h
# End Source File
# Begin Source File

SOURCE=.\jdhuff.h
# End Source File
# Begin Source File

SOURCE=.\jerror.h
# End Source File
# Begin Source File

SOURCE=.\jinclude.h
# End Source File
# Begin Source File

SOURCE=.\jmemsys.h
# End Source File
# Begin Source File

SOURCE=.\jmorecfg.h
# End Source File
# Begin Source File

SOURCE=.\jpegint.h
# End Source File
# Begin Source File

SOURCE=.\jpeglib.h
# End Source File
# Begin Source File

SOURCE=.\jversion.h
# End Source File
# End Group
# End Target
# End Project
