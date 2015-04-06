#!/usr/bin/perl
while (<*>) {push @{$files{((stat $_ )[1])}}, $_;}
foreach $key (sort keys %files){
	my @fnm = @{$files{$key}};
	printf "Inode %s files: %s\n",$key,(join ', ',sort @fnm) if $#fnm >0;
}
