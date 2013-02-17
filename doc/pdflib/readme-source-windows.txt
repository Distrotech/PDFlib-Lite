==============================
PDFlib Source Code for Windows
==============================

Building PDFlib with MS Visual Studio 6 (GUI)
---------------------------------------------

To compile PDFlib with MS Visual Studio 6, open the *.dsw workspace
corresponding to the target product (e.g. PDFlib.dsw). It contains several
projects for the core library and language bindings. Select the "pdflib"
project to build a static library pdflib.lib.

The "pdflib_dll" project can be used to build a DLL version pdflib.dll.

This will set the PDFLIB_EXPORTS #define. Client programs must define
PDFLIB_DLL before including pdflib.h in order to use the DLL.


The following configurations are supported:
- "Debug"
- "Release" will include a static version of the C runtime.
- "Release mtDLL" (only for target pdflib) builds a static library for
   use with applications which use a multithreaded DLL version of the
   C runtime (msvcrt.dll).

Sample applications:

The examples_c.dsw and examples_cpp.dsw contain targets for a few
C/C++ sample applications.

Note that some tests may fail because they need features which
require a higher product version (e.g. tests requiring PDI will
fail with PDFlib).


Building PDFlib with MS Visual Studio .NET (command-line)
---------------------------------------------------------

Build PDFlib using nmake from a command-line prompt:

- Run vcvars32.bat from a command-line prompt. This script is part of
  VS.NET, and can conveniently be run via an entry in the Windows start menu
  (Visual Studio .NET Tools, Visual Studio .NET 2003 Command Prompt).

- Run the following commands from the same command prompt:
  cd pdflib-x.y.z/config
  winsetup.bat
  cd pdflib-x.y.z/libs

- Now you can run "nmake" to start the build process, or call a command
  similar to the following to build a special configuration:

  nmake TARGET=CONFIG

  where CONFIG may be one of Release Debug Release_DLL Release_MD Release_NET


Note: the nmake-based build process uses assembler modules for zlib, which
improves performance by ca. 5%. The assembler modules are not supported for
other build processes or for PDFlib Lite.

64bit builds correctly work only on 64bit systems, builds from a 
"x64 cross command Tools Prompts" are not supported.

Building ofther bindings than C may need adjustment of library and include
paths in "config/mkcommon.inc.win".


Building PDFlib with MS Visual Studio .NET (GUI)
------------------------------------------------

The PDFlib packages contain solution files for use with Visual Studio
.NET 2003 (aka VS 7.1).


Building PDFlib with MS Visual Studio 2005
------------------------------------------
The VS.NET solution files can also be used with Visual Studio .NET 2005
(aka VS 8).  After importing and automatically converting the solution
files the following must be added manually:

Additional Dependencies:
pdf.lib flate.lib jpeg.lib pdcore.lib png.lib tiff.lib expat.lib
Additional Library Directories:
../flate,../jpeg,../pdcore,../png,../tiff, ../expat

When building PDFlib+PDI or PPS the following must also be added:
Additional Dependencies: pdi.lib pdpage.lib
Additional Library Directories: ../pdi, ../pdpage

The PDFlib .NET binding can only be built with MS Visual Studio 2003.


Building PDFlib with other Windows compilers
--------------------------------------------

In order to build PDFlib with other compilers, observe the above
notes and make sure to define the preprocessor symbol WIN32.


Compiling the language wrappers
-------------------------------

In order to compile the C wrappers for the supported languages you
will have to install the relevant source code package
and adjust the include paths for these packages in the project files.
Since we supply prebuilt binaries for all supported languages this is
generally not required. Project files for the language wrappers are
only supplied for Microsoft Visual C++, but not any other compiler.
