#!/usr/bin/env python3


import sys
import matplotlib.pyplot as plt
import numpy as np
import matplotlib as mpl
from math import floor


######################## Set Plot Parameter ##############################


SMALL_SIZE = 50
MEDIUM_SIZE = 55
BIGGER_SIZE = 60


plt.rc('font', size=SMALL_SIZE)          # controls default text sizes
plt.rc('axes', titlesize=SMALL_SIZE)     # fontsize of the axes title
plt.rc('axes', labelsize=MEDIUM_SIZE)    # fontsize of the x and y labels
plt.rc('xtick', labelsize=SMALL_SIZE)    # fontsize of the tick labels
plt.rc('ytick', labelsize=SMALL_SIZE)    # fontsize of the tick labels
plt.rc('legend', fontsize=SMALL_SIZE)    # legend fontsize
plt.rc('figure', titlesize=BIGGER_SIZE)  # fontsize of the figure title
plt.rc('axes', linewidth = 4)           # linewidth of axes broader
lw = 4.0
plt.rcParams['lines.linewidth'] = lw
plt.rcParams['mathtext.default'] = 'regular'


prop_cycle = plt.rcParams['axes.prop_cycle']
colors = prop_cycle.by_key()['color']


##################### plot diagram ########################
sample = []
with open("data.txt") as f:
    for line in f:
        data = [float(elem) for elem in line.rstrip().split()]
        data = data[0]
        sample.append(data)


bin_num = floor(len(sample)/2)
x = sample[0:bin_num+1]
x = np.array(x)
sample = np.array(sample[bin_num+1:])


print("Total number of data: {}".format(bin_num - 2))


def f(x1):
    a = 0.1
    Pi = np.pi
    res = 1.0
    res = res*(1/(a*np.sqrt(Pi)))
    res = res*np.exp(-np.pow(x1 - 1.0/2.0, 2)/np.pow(a, 2))
    return res


x1 = np.linspace(x[0], x[-1], 200)


fig, ax = plt.subplots()
fig.set_size_inches(24, 18)


ax.stairs(sample, edges = x, linewidth = lw, label = "VEGAS data")
ax.plot(x1, f(x1), linewidth = lw, label = r"$\frac{1}{a\pi^{1/2}}e^{-\frac{(x_1 - \frac{1}{2})^2}{a^2}}$")
ax.set(xlim = (x[0], x[-1]))
for ticks in ax.yaxis.get_majorticklabels():
    ticks.set_verticalalignment('baseline')
ax.set_ylabel(r"$\frac{d I_4}{d x_1}$", loc = "top")
ax.set_xlabel(r"$x_1$", loc = "right")
ax.tick_params(direction = "in", which = "both")
ax.tick_params(which='major', width=lw, length=30)
ax.tick_params(which='minor', width=0.80*lw, length=10)
ax.yaxis.set_ticks_position("both")
ax.xaxis.set_ticks_position("both")
ax.minorticks_on()
ax.set_xticks(x, minor = True)
ax.legend()


plt.savefig("Gauss.png")


