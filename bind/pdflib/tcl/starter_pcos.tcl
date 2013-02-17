#!/bin/sh
# $Id: starter_pcos.tcl,v 1.3.2.3 2008/09/02 20:56:06 rjs Exp $
#
# Hide the exec to Tcl but not to the shell by appending a backslash\
exec tclsh "$0" ${1+"$@"}

# pCOS starter:
# Dump information from an existing PDF document
#
# required software: PDFlib+PDI/PPS 7
# required data: PDF input file


# The lappend line is unnecessary if PDFlib has been installed
# in the Tcl package directory
set auto_path [linsert $auto_path 0 .libs .]

package require pdflib 7.0

proc yesno {p doc path} {
    set retval [PDF_pcos_get_number $p $doc $path]
    if {$retval != 0} {
	return "yes"
    } else {
	return "no"
    }
}

proc noyes {p doc path} {
    set retval [PDF_pcos_get_number $p $doc $path]
    if {$retval != 0} {
	return "no"
    } else {
	return "yes"
    }
}

# This is where the data files are. Adjust as necessary.
set searchpath  "../data"
set pdfinput  "TET-datasheet.pdf"
set docoptlist  "requiredmode=minimum"

set p [PDF_new]

if { [catch {
    # This means we must check return values of load_font() etc.
    PDF_set_parameter $p "errorpolicy" "return"

    PDF_set_parameter $p "SearchPath" $searchpath

    # We do not create any output document so no call to
    # begin_document is required.

    # Open the input document
    set doc [PDF_open_pdi_document $p $pdfinput $docoptlist]
    if {$doc == -1} {
	puts stderr "Error: [PDF_get_errmsg $p]"
	exit
    }

    # --------- general information (always available)

    set pcosmode [PDF_pcos_get_number $p $doc "pcosmode"]

    puts [format "   File name: %s" [PDF_pcos_get_string $p $doc "filename"]]

    puts [format " PDF version: %s" [expr [PDF_pcos_get_number $p $doc "pdfversion"]/10]]

    puts [format "  Encryption: %s" [PDF_pcos_get_string $p $doc "encrypt/description"]]

    puts [format "   Master pw: %s" [yesno $p $doc "encrypt/master"]]

    puts [format "     User pw: %s" [yesno $p $doc "encrypt/user"]]

    puts [format "Text copying: %s" [noyes $p $doc "encrypt/nocopy"]]

    puts [format "  Linearized: %s" [yesno $p $doc "linearized"]]

    puts [format "      Tagged: %s" [yesno $p $doc "tagged"]]
    puts ""

    if {$pcosmode == 0} {
	puts "Minimum mode: no more information available\n"
	PDF_delete $p
	exit 0
    }

    # --------- more details (requires at least user password)
    puts [format "No. of pages: %d" [expr int([PDF_pcos_get_number $p $doc "length:pages"])]]

    puts [format " Page 1 size: width=%.3f, height=%.3f" [expr [PDF_pcos_get_number $p $doc "pages\[0\]/width"]] [expr [PDF_pcos_get_number $p $doc "pages\[0\]/height"]]]

    set count [PDF_pcos_get_number $p $doc "length:fonts"]
    puts [format "No. of fonts: %d" [expr int($count)]]

    for {set i 0} {$i < $count} {set i [expr $i + 1]} {
	set fonts [format "fonts\[%d\]/embedded" $i]
	if {[PDF_pcos_get_number $p $doc $fonts] != 0} {
	    puts -nonewline "embedded "
	} else {
	    puts -nonewline "unembedded "
	}

	set fonts [format "fonts\[%d\]/type" $i]
	puts -nonewline [format "%s font " [PDF_pcos_get_string $p $doc $fonts]]
	set fonts [format "fonts\[%d\]/name" $i]
	puts [format "%s" [PDF_pcos_get_string $p $doc $fonts]]
    }

    puts ""

    if {$pcosmode == 1} {
	puts -nonewline "Restricted mode: no more information available"
	PDF_delete $p
	exit 0
    }

    # ----- document $info keys and XMP metadata  requires master pw)

    set count [PDF_pcos_get_number $p $doc "length:/Info"]

    for {set i 0} {$i < $count} {set i [expr $i + 1]} {
	set info [format "type:/Info\[%d\]" $i]
	set objtype [PDF_pcos_get_string $p $doc $info]

	set info [format "/Info\[%d\].key" $i]
	set key [PDF_pcos_get_string $p $doc $info]
	set len [expr 12 - [string length $key]]
	while {$len > 0} {
	    set len [expr $len -1]
	    puts -nonewline " "
	}

	puts -nonewline [format "%s: " $key]

	# $info entries can be stored as string or name objects
	if {$objtype == "name" || $objtype == "string"} {
	    set info [format "/Info\[%d\]" $i]
	    puts [format "'%s'" [PDF_pcos_get_string $p $doc $info]] 
	} else {
	    set info [format "type:/Info\[%d\]" $i]
	    puts [format "(%s object)" [PDF_pcos_get_string $p $doc $info]]
	}
    }

    puts -nonewline "\nXMP meta data: "


    set objtype [PDF_pcos_get_string $p $doc "type:/Root/Metadata"]
    if {$objtype == "stream"} {
	set contents [PDF_pcos_get_stream $p $doc "" "/Root/Metadata"]
	puts [format "%d bytes " [string length $contents]]
    } else {
	puts "not present"
    }

    PDF_close_pdi_document $p $doc

} result] } {
    global errorInfo
    puts stderr "$result"
    puts stderr "$errorInfo"
}

# delete the PDFlib object
PDF_delete $p
