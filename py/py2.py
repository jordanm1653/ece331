#!/usr/bin/python
import sys;
lines=sys.stdin.readlines()
for l in lines:
	print type(l)
	print l.rstrip()
