Which Binding to use
====================

The PYTHON_API_VERSION of the PDFlib binding and the Python version used
have to match.

PYTHON_API_VERSION

1009    Python 2.0      (Unicode Support added)
1010    Python 2.1
1011    Python 2.2
1012    Python 2.3 ... Python 2.4
1013    Python 2.5 ... Python 2.6rc2 ... Python 3.0rc1

The PDFlib Python binding needs at least PYTHON_API_VERSION 1009.


Python binding on Mac OS X
==========================

The build process creates pdflib_py.dylib (as usual on Mac OS X), but Python
wants to have pdflib_py.so. Therefore you must rename pdflib_py.dylib to
pdflib_py.so before you can use the binaries.
