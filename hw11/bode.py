#!/usr/bin/python
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# bode.py
#
# Create a Bode plot of transfer funtion:
#	H(s) = 8000s/(s^2+5000s+10^6
# 	where: s = jw from 10 to 10k rad/s
# 
# PACKAGES:
#	apt-get install python-scypi
#	apt-get install python-matplotlib
#	apt-get install python-tk
#
# AUTHOR: Jordan Millington

import numpy as np
from scipy import signal
import matplotlib.pyplot as plt

sig = signal.lti([8000],[1, 5000, 10^6])
w, mag, phase = signal.bode(sig)

plt.figure()
plt.semilogx(w, mag)
plt.figure()
plt.semilogx(w, phase)
plt.show()
