import numpy as np
import matplotlib.pyplot as plt

x = np.genfromtxt("dato.txt", usecols = 0)
y = np.genfromtxt("dato.txt", usecols = 1)
d = np.genfromtxt("dato.txt", usecols = 2)

#plt.scatter(x,d)
plt.plot(x,y)
plt.savefig("Graphy.png")
