# Microsoft Developer Studio Project File - Name="png" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=png - Win32 Debug DLL
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "png.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "png.mak" CFG="png - Win32 Debug DLL"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "png - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "png - Win32 Release DLL" (based on "Win32 (x86) Static Library")
!MESSAGE "png - Win32 Release mtDLL" (based on "Win32 (x86) Static Library")
!MESSAGE "png - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "png - Win32 Debug DLL" (based on "Win32 (x86) Static Library")
!MESSAGE "png - Win32 Release TET" (based on "Win32 (x86) Static Library")
!MESSAGE "png - Win32 Release DLL TET" (based on "Win32 (x86) Static Library")
!MESSAGE "png - Win32 Release mtDLL TET" (based on "Win32 (x86) Static Library")
!MESSAGE "png - Win32 Debug DLL TET" (based on "Win32 (x86) Static Library")
!MESSAGE "png - Win32 Debug TET" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "png - Win32 Release"

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
# ADD CPP /nologo /MT /W3 /GX /O2 /I "../flate" /I "../pdcore" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"png.lib"

!ELSEIF  "$(CFG)" == "png - Win32 Release DLL"

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
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "../flate" /I "../pdcore" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "../flate" /I "../pdcore" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"png.lib"
# ADD LIB32 /nologo /out:"png.lib"

!ELSEIF  "$(CFG)" == "png - Win32 Release mtDLL"

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
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "../flate" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../flate" /I "../pdcore" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"png.lib"
# ADD LIB32 /nologo /out:"ibpng.lib"

!ELSEIF  "$(CFG)" == "png - Win32 Debug"

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
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../flate" /I "../pdcore" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /GZ /c
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"png.lib"

!ELSEIF  "$(CFG)" == "png - Win32 Debug DLL"

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
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../flate" /I "../pdcore" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /GZ  /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../flate" /I "../pdcore" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /GZ  /GZ /c
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"png.lib"
# ADD LIB32 /nologo /out:"png.lib"

!ELSEIF  "$(CFG)" == "png - Win32 Release TET"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "../flate" /I "../pdcore" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_TET_BUILD" /YX /FD /c
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"png.lib"

!ELSEIF  "$(CFG)" == "png - Win32 Release DLL TET"

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
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "../flate" /I "../pdcore" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "../flate" /I "../pdcore" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_TET_BUILD" /YX /FD /c
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"png.lib"
# ADD LIB32 /nologo /out:"png.lib"

!ELSEIF  "$(CFG)" == "png - Win32 Release mtDLL TET"

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
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "../flate" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../flate" /I "../pdcore" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_TET_BUILD" /YX /FD /c
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"png.lib"
# ADD LIB32 /nologo /out:"ibpng.lib"

!ELSEIF  "$(CFG)" == "png - Win32 Debug DLL TET"

BSC32=bscmake.exe
LIB32=link.exe -lib

!ELSEIF  "$(CFG)" == "png - Win32 Debug TET"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../flate" /I "../pdcore" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_MT" /D "PDFLIB_TET_BUILD" /YX /FD /GZ /c
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x407 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"png.lib"

!ENDIF 

# Begin Target

# Name "png - Win32 Release"
# Name "png - Win32 Release DLL"
# Name "png - Win32 Release mtDLL"
# Name "png - Win32 Debug"
# Name "png - Win32 Debug DLL"
# Name "png - Win32 Release TET"
# Name "png - Win32 Release DLL TET"
# Name "png - Win32 Release mtDLL TET"
# Name "png - Win32 Debug DLL TET"
# Name "png - Win32 Debug TET"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\png.c

!IF  "$(CFG)" == "png - Win32 Release"

!ELSEIF  "$(CFG)" == "png - Win32 Release DLL"

!ELSEIF  "$(CFG)" == "png - Win32 Release mtDLL"

!ELSEIF  "$(CFG)" == "png - Win32 Debug"

!ELSEIF  "$(CFG)" == "png - Win32 Debug DLL"

!ELSEIF  "$(CFG)" == "png - Win32 Release TET"

!ELSEIF  "$(CFG)" == "png - Win32 Release DLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Release mtDLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Debug DLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Debug TET"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pngerror.c

!IF  "$(CFG)" == "png - Win32 Release"

!ELSEIF  "$(CFG)" == "png - Win32 Release DLL"

!ELSEIF  "$(CFG)" == "png - Win32 Release mtDLL"

!ELSEIF  "$(CFG)" == "png - Win32 Debug"

!ELSEIF  "$(CFG)" == "png - Win32 Debug DLL"

!ELSEIF  "$(CFG)" == "png - Win32 Release TET"

!ELSEIF  "$(CFG)" == "png - Win32 Release DLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Release mtDLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Debug DLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Debug TET"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pngget.c

!IF  "$(CFG)" == "png - Win32 Release"

!ELSEIF  "$(CFG)" == "png - Win32 Release DLL"

!ELSEIF  "$(CFG)" == "png - Win32 Release mtDLL"

!ELSEIF  "$(CFG)" == "png - Win32 Debug"

!ELSEIF  "$(CFG)" == "png - Win32 Debug DLL"

!ELSEIF  "$(CFG)" == "png - Win32 Release TET"

!ELSEIF  "$(CFG)" == "png - Win32 Release DLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Release mtDLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Debug DLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Debug TET"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pngmem.c

!IF  "$(CFG)" == "png - Win32 Release"

!ELSEIF  "$(CFG)" == "png - Win32 Release DLL"

!ELSEIF  "$(CFG)" == "png - Win32 Release mtDLL"

!ELSEIF  "$(CFG)" == "png - Win32 Debug"

!ELSEIF  "$(CFG)" == "png - Win32 Debug DLL"

!ELSEIF  "$(CFG)" == "png - Win32 Release TET"

!ELSEIF  "$(CFG)" == "png - Win32 Release DLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Release mtDLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Debug DLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Debug TET"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pngread.c

!IF  "$(CFG)" == "png - Win32 Release"

!ELSEIF  "$(CFG)" == "png - Win32 Release DLL"

!ELSEIF  "$(CFG)" == "png - Win32 Release mtDLL"

!ELSEIF  "$(CFG)" == "png - Win32 Debug"

!ELSEIF  "$(CFG)" == "png - Win32 Debug DLL"

!ELSEIF  "$(CFG)" == "png - Win32 Release TET"

!ELSEIF  "$(CFG)" == "png - Win32 Release DLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Release mtDLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Debug DLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Debug TET"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pngrio.c

!IF  "$(CFG)" == "png - Win32 Release"

!ELSEIF  "$(CFG)" == "png - Win32 Release DLL"

!ELSEIF  "$(CFG)" == "png - Win32 Release mtDLL"

!ELSEIF  "$(CFG)" == "png - Win32 Debug"

!ELSEIF  "$(CFG)" == "png - Win32 Debug DLL"

!ELSEIF  "$(CFG)" == "png - Win32 Release TET"

!ELSEIF  "$(CFG)" == "png - Win32 Release DLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Release mtDLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Debug DLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Debug TET"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pngrtran.c

!IF  "$(CFG)" == "png - Win32 Release"

!ELSEIF  "$(CFG)" == "png - Win32 Release DLL"

!ELSEIF  "$(CFG)" == "png - Win32 Release mtDLL"

!ELSEIF  "$(CFG)" == "png - Win32 Debug"

!ELSEIF  "$(CFG)" == "png - Win32 Debug DLL"

!ELSEIF  "$(CFG)" == "png - Win32 Release TET"

!ELSEIF  "$(CFG)" == "png - Win32 Release DLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Release mtDLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Debug DLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Debug TET"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pngrutil.c

!IF  "$(CFG)" == "png - Win32 Release"

!ELSEIF  "$(CFG)" == "png - Win32 Release DLL"

!ELSEIF  "$(CFG)" == "png - Win32 Release mtDLL"

!ELSEIF  "$(CFG)" == "png - Win32 Debug"

!ELSEIF  "$(CFG)" == "png - Win32 Debug DLL"

!ELSEIF  "$(CFG)" == "png - Win32 Release TET"

!ELSEIF  "$(CFG)" == "png - Win32 Release DLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Release mtDLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Debug DLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Debug TET"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pngset.c

!IF  "$(CFG)" == "png - Win32 Release"

!ELSEIF  "$(CFG)" == "png - Win32 Release DLL"

!ELSEIF  "$(CFG)" == "png - Win32 Release mtDLL"

!ELSEIF  "$(CFG)" == "png - Win32 Debug"

!ELSEIF  "$(CFG)" == "png - Win32 Debug DLL"

!ELSEIF  "$(CFG)" == "png - Win32 Release TET"

!ELSEIF  "$(CFG)" == "png - Win32 Release DLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Release mtDLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Debug DLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Debug TET"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\pngtrans.c

!IF  "$(CFG)" == "png - Win32 Release"

!ELSEIF  "$(CFG)" == "png - Win32 Release DLL"

!ELSEIF  "$(CFG)" == "png - Win32 Release mtDLL"

!ELSEIF  "$(CFG)" == "png - Win32 Debug"

!ELSEIF  "$(CFG)" == "png - Win32 Debug DLL"

!ELSEIF  "$(CFG)" == "png - Win32 Release TET"

!ELSEIF  "$(CFG)" == "png - Win32 Release DLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Release mtDLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Debug DLL TET"

!ELSEIF  "$(CFG)" == "png - Win32 Debug TET"

!ENDIF 

# End Source File
# End Group
# End Target
# End Project
