#!/usr/bin/perl
use strict;
use warnings;

open(my $fh, '>', 'nums.txt');

foreach my $i (0..255){
	print $fh "$i\n";
}
close($fh);
