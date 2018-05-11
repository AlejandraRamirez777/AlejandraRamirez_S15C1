import numpy as np
import matplotlib.pyplot as plt

x = np.genfromtxt("dato.txt", usecols = 0)
y = np.genfromtxt("dato.txt", usecols = 1)
d = np.genfromtxt("dato.txt", usecols = 2)
x_walk = np.genfromtxt("dato.txt", usecols = 3)


#f = nasty_function(x)
norm = sum(y*(x[1]-x[0]))
plt.plot(x,y/norm, linewidth=1, color='r')
count, bins, ignored = plt.hist(x_walk, 1000, normed=True)
#plt.scatter(x,d)
#plt.plot(x,y)
plt.savefig("Graphy.png")
