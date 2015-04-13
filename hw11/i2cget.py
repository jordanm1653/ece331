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
bus = smbus.SMBus(1)	# 1 = /dev/i2c-1

# i2c Address of xmega
addr = 0x41

# i2c temperature data dict
temp_t = {
	'roomcal':	0,
	'hotcal':	0,
	'adcal':	0,
	'v':		0,
	'room':		0,
	'hot':		0,
}
	
# Read 10 bytes from xmega
try:
	data = bus.read_i2c_block_data(addr,0x00,10)
except IOError:
	print "unable to read from i2c bus"

# Populate temp_t dict from i2c transmission
temp_t['roomcal']	= (data[0] << 8) + data [1]
temp_t['hotcal']	= (data[2] << 8) + data [3]
temp_t['adcal']		= (data[4] << 8) + data [5]
temp_t['v']			= (data[6] << 8) + data [7]
temp_t['room']		=  data[8]
temp_t['hot']		=  data[9]

# Raw temperature reading for homework assignment
print "Raw Temp: %d" % temp_t['v']
