#!/usr/bin/perl
# parser.pl
# Jordan Millington
#
# parses a file with a known format to generate a matlab readable data file
# of time and voltages

use strict;
use warnings;

open(IN, "<", $ARGV[0])
	 or die "Cannot open file: $!\n";
open(OUT, ">", $ARGV[1])
	or die "Cannot opne file: $!\n";

while(<IN>){
	chomp;
	my $x = $_;
	$x =~ s/,/ /g;
	print OUT "$x\n" if(/^[-+]?[0-9].*/);
}
close(IN);
close(OUT);
