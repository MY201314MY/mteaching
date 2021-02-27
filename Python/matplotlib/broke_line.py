import numpy as np
import random
import matplotlib.pyplot as plt

plt.ion()
plt.figure(1)
t_list = []
result_list = []
t = 0

while True:
    t_list.append(t)
    result_list.append(random.random())
    if t_list.__len__() > 100:
        t_list.pop(0)
        result_list.pop(0)
        plt.clf()

    plt.plot(t_list, result_list, c='r', ls='-', marker='o', mec='b', mfc='w')
    plt.pause(0.01)
    t += 1
