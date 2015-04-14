#!/usr/bin/perl
# mac2bin.pl
#
# Read a mac address from stdin and convert it to a decimal value
#
# Jordan Millington
#
use strict;
use warnings;
use bignum;

# output from program getmac piped into script
my $mac = <STDIN>;
$mac =~ tr/://d;
# Hex to decimal
my $dec = hex($mac);
printf "$dec\n";
