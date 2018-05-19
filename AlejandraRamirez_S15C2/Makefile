Grafica_histR.png: datos_MC.txt
	python plots_AlejandraRamirez_S15C2.py

Grafica_histX.png: datos_MC.txt
	python plots_AlejandraRamirez_S15C2.py

Grafica_histY.png: datos_MC.txt
	python plots_AlejandraRamirez_S15C2.py

Grafica_radio.png: datos_MC.txt
	python plots_AlejandraRamirez_S15C2.py

datos_MC.txt: S15C2
	./S15C2 > datos_MC.txt

S15C2 : AlejandraRamirez_S15C2.cpp
	g++ AlejandraRamirez_S15C2.cpp -o ./S15C2 > datos_MC.txt
