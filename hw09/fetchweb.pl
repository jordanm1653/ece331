#!/usr/bin/perl
# Fetch contents of a webpage using IO::Socket
#
# Jordan Millington
# 03/31/15
use strict;
use warnings;
use IO::Socket::INET;   # Object interface for AF_INET domain sockets

my ($sock, $response);
my $site = 'courses.eece.maine.edu';
# Open Socket
$sock = IO::Socket::INET->new(
	PeerAddr => $site,
	PeerPort => 'http(80)',
	Proto => 'tcp');

die "Unable to open socket $!\n" unless $sock;
# Send "GET" command
print $sock "GET /\n\r";
# Print response from GET
while($response=<$sock>){
	print "$response\n";
}
close $sock;
