PDFlib and different versions of Perl
=====================================

Since extensions for Perl depend on the specific version of Perl in
use, we deliver various binary flavors of the PDFlib binding for Perl.

In the binary packages you will find a separate directory for 
each supported version of Perl:

- perl58	for Perl 5.8.x
- perl58-nt	for Perl 5.8.x (compiled without ithread support)
- perl510	for Perl 5.10.x
- perl510-nt	for Perl 5.10.x (compiled without ithread support)

Note that not all versions are available for all platforms. Perl on
SunOS and FreeBSD normally does not have ithreads support.


If you see the following message when trying to use the PDFlib binding 
for Perl:

  Unresolved symbol: Perl_Gthr_key_ptr (code)

you are using a version of PDFlib which has been built with ithread
support, but have a Perl binary without ithread support. To solve
this you must use the "-nt" build of PDFlib.

ActiveState Perl distributions work with the PDFlib bindings for Perl,
i.e. those with ithread support (and not the "-nt" version).
