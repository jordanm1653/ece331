#!/usr/bin/python
import re
import sys
for l in sys.stdin.readlines():
	#m=re.findall(r'([0-9])[0-9]+',l) # r for raw string, findall returns a list of captures
	#print m
	n=re.search(r'([0-9])[0-9]+',l) # r for raw string, findall returns a list of captures
	try:
		#print n.group()
		print n.groups()
	except:
		print
