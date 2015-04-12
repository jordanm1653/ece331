#!/usr/bin/perl
# mscripter.pl
# generates a matlab script file to load oscope data and plot 
# Jordan Millington

use strict;
use warnings;

open(OUT, '>', $ARGV[0])
	or die "Cannot open file: $!\n";

print OUT "\# Jmillington scripting file\n\n";
print OUT	"clear;clc;\n\n".	
		"data = load(\'scope.txt\');\n".
		"t = data(:,1);\n".
		"ch1 = data(:,2);\n".
		"ch2 = data(:,4);\n".
		"plot(t,ch1,t,ch1_pk,t,ch2,t,ch2_pk);\n".
		"xlabel = (\"Time (seconds)\");\n".
		"ylabel = (\"Voltage (volts)\");\n";
