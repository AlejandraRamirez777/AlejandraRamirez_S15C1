import numpy as np
import matplotlib.pyplot as plt

#Datos Canal_ionico1.txt
x = np.genfromtxt("Canal_ionico1.txt", usecols = 0)
y = np.genfromtxt("Canal_ionico1.txt", usecols = 1)

p = np.linspace(0,2,100)
anx = np.pi*p
R = 5.82771
X = 3.36089
Y = 4.65511
xc = R*np.cos(anx) + X
yc = R*np.sin(anx) + Y
plt.scatter(X,Y,c= "k")
plt.plot(xc,yc, c = "g")
plt.scatter(x,y)
plt.title("x = " + str(X) + " y = " + str(Y) + " Radio = " + str(R))
plt.savefig("Grafica_radio.png")
plt.clf()

Dx = np.genfromtxt("datos_MC.txt", usecols = 0)
Dxx = np.genfromtxt("datos_MC.txt", usecols = 1)
Dyy = np.genfromtxt("datos_MC.txt", usecols = 2)
Radios = np.genfromtxt("datos_MC.txt", usecols = 3)


#f = nasty_function(x)
#norm = sum(y*(x[1]-x[0]))
#plt.plot(x,y/norm, linewidth=1, color='r')
count, bins, ignored = plt.hist(Dxx, 1000, normed=True)
plt.title("Histograma de coordenada x")
plt.savefig("Grafica_histX.png")
plt.clf()

count, bins, ignored = plt.hist(Dyy, 1000, normed=True)
plt.title("Histograma de coordenada y")
plt.savefig("Grafica_histY.png")
plt.clf()

count, bins, ignored = plt.hist(Radios, 1000, normed=True)
plt.title("Histograma del radio")
plt.savefig("Grafica_histR.png")
plt.clf()
