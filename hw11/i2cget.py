#!/usr/bin/python
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# i2cget.py
#
# Retrieve raw ADC value from temp sensor on ECE XMEGA expansion  board
# 
# Expansion Board I2C Address: 0x41 (sudo i2cdetect -y 1)
#
# AUTHOR: Jordan Millington

import struct
import smbus
from collections import namedtuple

bus = smbus.SMBus(1)	# 1 = /dev/i2c-1

#
# i2c Address of xmega
#
addr = 0x41

#
# Read 10 bytes from xmega
#
try:
	data = bus.read_i2c_block_data(addr,0x00,10)
except IOError:
	print "unable to read from i2c bus"

#
# Format data from i2c read
#
buff= struct.unpack('<HHHHBB', struct.pack('BBBBBBBBBB', *data))

#
# Create dictionary from i2c data
#
keys = ['roomcal','hotcal','adcal','v','room','hot']
temp_t = dict(zip(keys, buff))

print temp_t['v']
