#!/usr/bin/python
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#
# bode.py
#
# Create a Bode plot of transfer funtion:
# 
#		              8000s
#		G(s) = --------------------
#		        s^2 + 5000s + 10^6
#
#		where: s = jw from 10 to 10k rad/sec
# 
# PACKAGES:
#	 python-scypi
#	 python-matplotlib
#	 python-tk
#
# AUTHOR: Jordan Millington

import numpy as np
from scipy import signal
import matplotlib.pyplot as plt

def mag2db ( magnitdue ):
	mag_max = np.amax(magnitude)
	db = 20 * np.log10
sig = signal.lti([8000],[1, 5000, 10^6])
#w, mag, phase = signal.bode(sig)
#
#plt.figure()
#plt.semilogx(w, mag)
#plt.figure()
#plt.semilogx(w, phase)
#plt.show()
# w (omega) = 10-10k as rad/s in logspace

i = np.logspace(1,4,10000)
jw = 1j*i
w, mag, phase = signal.bode(sig,i) 
w1, mag1, phase1 = signal.bode(sig) 
plt.figure()
plt.semilogx(w, mag)
plt.figure()
plt.semilogx(w1, mag1)
plt.show()
#print i
#print jw
#print mag
#print mag1
