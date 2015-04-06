#!/usr/bin/perl

# dec2bin.pl
#
# J. Millington
#
# Prints an unsigned integer passed on the command line in binary

# Check for integer and print as binary
if ($ARGV[0] =~ m/^\d+$/){
	printf "%b\n",$ARGV[0];
}
