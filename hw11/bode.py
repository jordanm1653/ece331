#!/usr/bin/python
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
# bode.py
#
# Create a Bode plot of transfer funtion:
#
#	              8000s
#	G(s) = --------------------
#	        s^2 + 5000s + 10^6
#
#	where: s = jw from 10 to 10k rad/sec
# 
# PACKAGES:
#	 python-scypi
#	 python-matplotlib
#	 python-tk
#
# AUTHOR: Jordan Millington

#
# Imports
#
import numpy as np
from scipy import signal
import matplotlib.pyplot as plt

#
# Transfer function as LTI
#
sig = signal.lti([8000],[1, 5000, 10^6])

#
# Frequency range & Bode magnitude
# 	bode() returns magnitude in dB
#
w = np.logspace(1,4,100)
w, mag, phase = signal.bode(sig,w)

#
# Plot setup
#
plt.figure()
plt.semilogx(w, mag)
plt.title('Bode Plot of G(s) = 8000s / (s^2 + 5000s + 10^6)')
plt.xlabel('Frequency [rad/sec]')
plt.ylabel('Amplitude [dB]')
plt.grid(axis='both',which='both')
plt.show()
