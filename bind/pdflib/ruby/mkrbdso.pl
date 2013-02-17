#!/usr/bin/perl
# $Id: mkrbdso.pl,v 1.1.2.5 2009/11/05 15:49:00 rjs Exp $
#
# mkrbdso.pl: create a PDFlib-DSO for ruby versions
#
# what do we do here:
#
# - cleanup old stuff
# - compile the *.c file
# - compile the DSO
# - cp the DSO to the right place


use Config;
use strict;
use Getopt::Long;
use Cwd;
use File::Copy;

my $debug = 0;
my $verbose = 0;
my $rbvers;
my $ruby;
my $rubydir;
my $OPSYS=`perl ../../../dist/tools/sysinfo.pl`; chomp $OPSYS;
my $LOG_FILE;

GetOptions (
"rbvers=s"	=> \$rbvers,	# 18, 19
"verbose!"      => \$verbose,
"debug!"        => \$debug,
) || die "$0: fatal error\n";

$LOG_FILE = cwd() . "/mkruby$rbvers.log";

sub my_system {
    my $ret = 0;
    open(README, "@_ |") or die "cannot execute $!\n";
    open(LOG, ">> $LOG_FILE");

    print LOG "@_\n";
    print "@_\n" if ($verbose || $debug);
    while(<README>) {
        print LOG $_;
        print $_ if ($debug);
    }
    $ret = close(README);
    $ret = 0 if ($! == 0);
    print "RET= -$ret- -$!- -$?-\n" if ($debug);
    close(LOG);
    return $ret;
}

sub mycopy {
    my ($from, $to) = @_;
    open(LOG, ">> $LOG_FILE");
    print LOG "cp $from $to\n" if ($verbose);
    copy($from, $to) || die "copy of $from failed: $!\n";
    close(LOG);
}


if ($OPSYS =~ m/^MSWin/) {
    print "building pdflib-ruby WIN-binding for ruby Version: $rbvers\n";
    $ruby =  "C:/Programme/ruby-$rbvers/bin/ruby";
} else {
    print "building pdflib-ruby binding for Ruby Version: $rbvers\n";

    $ruby =  "/usr/local/ruby-$rbvers/bin/ruby";
    if (!-f $ruby) {
        print "$ruby not installed; skipping $rbvers !!!!!!!!!!!!!!!!!!!\n";
        exit(0);
    }
}

$rubydir = "ruby$rbvers";
$rubydir =~ s/\.//;

# cleanup
my_system("rm -rf $rubydir");

# setup fresh builddir
mkdir "$rubydir";
mycopy("extconf.rb", "$rubydir");
mycopy("pdflib_ruby.c", "$rubydir");
mycopy("rb_wrapped.c", "$rubydir");

chdir "$rubydir";

my_system("$ruby extconf.rb --with-opt-include=../../../../libs/pdflib") &&
        die("rubyconf failed?");
my_system("make") && die("make failed");

# test the new binding
mycopy("../hello.rb", ".");
my_system("$ruby hello.rb") && die("ruby hello.rb failed\n");
system("ls -l hello.pdf") && die("hello.pdf not found\n");

system("mv $LOG_FILE .");
system("echo \"*** PDFlib-ruby Binding $rbvers succesfully built ***\n\"");
