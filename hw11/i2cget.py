#!/usr/bin/python
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# i2cget.py
#
# Retrieve raw ADC value from temp sensor on ECE XMEGA expansion  board
# 
# Expansion Board I2C Address: 0x41 (sudo i2cdetect -y 1)
#
# AUTHOR: Jordan Millington

import smbus
import time
bus = smbus.SMBus(1)	# 1 = /dev/i2c-1

addr = 0x41
reg = [0x0000,0x00ff]

#for y in range(0,30):
#	for x in range(0,50):
#		data = bus.read_byte_data(addr,x)
#		print data,
#	print 
#	time.sleep(1)
try:
	data = bus.read_block_data(addr,8)
except:
	print "unable to read from i2c bus"
#print hex(data)
#print dir(data)
print dir(data)
print type(data)
print data.__sizeof__
print data
