#!/usr/bin/perl
# intelhex.pl
#
# Generate an Intel Hex Record from stdin
#
# Jordan Millington
# 02/17/2015
use Encode;
# Read Input from STDIN
while (<>){
	chomp;
	push @dat, unpack('H*',$_);
}
# Build record
for $i (0 .. $#dat){
	$len = length(Encode::encode_utf8($dat[$i]));
	# <ByteLength><Offset><TYPE><Data>
	$str = sprintf("%02X%04X00$dat[$i]",$len,$i);
	$tmp = pack('H*', $str);
	$chksm = unpack('%8C*',$tmp);
	printf ":$str%02X\r\n",(-$chksm & 0xFF);
}
# Termination Record
printf(":00000001FF\r\n");
