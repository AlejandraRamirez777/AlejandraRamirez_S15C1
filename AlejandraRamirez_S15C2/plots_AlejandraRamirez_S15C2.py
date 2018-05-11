import numpy as np
import matplotlib.pyplot as plt

x = np.genfromtxt("Canal_ionico1.txt", usecols = 0)
y = np.genfromtxt("Canal_ionico1.txt", usecols = 1)

plt.scatter(x,y)
plt.show()
