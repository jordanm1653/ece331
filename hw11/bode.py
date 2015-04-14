#!/usr/bin/python
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# bode.py
#
# Create a Bode plot of transfer funtion:
#									H(s) = 8000s/(s^2+5000s+10^6
# 	where: s = jw from 10 to 10k rad/s
# 
# AUTHOR: Jordan Millington

from numpy import signal
import matplotlib.pyplot as plt

sig = signal.lti([8000],[1, 5000, 10^6])
w, mag, phase = signal.bode(sig)
