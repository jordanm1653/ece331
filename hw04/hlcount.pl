#!/usr/bin/perl
# hlcount.pl
#
# Count the number of hardlinks in a directory

# while(<*>)
#	<>	= stdin
#	<*> 	= builtin grub for everything
 
while (<*>) {push @{$files{((stat $_ )[1])}}, $_;}
foreach $key (sort keys %files){
	my @fnm = @{$files{$key}};
	printf "Inode %s files: %s\n",$key,(join ', ',sort @fnm) if $#fnm >0;
}
