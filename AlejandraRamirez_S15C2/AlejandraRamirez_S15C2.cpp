#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <iomanip>
//#include <stdio.h>
#include <tgmath.h>


using namespace std;

double minima(double xx, double yy, double *tx, double *ty, int nn);

int main () {

    //info inputs

    //num lineas
    int numL = 0;

    //LEER EL TXT
    ifstream inl;

    //info line
    string s;

    //Contador avance lineas
    int g = 0;

    //Abrir el archivo
    inl.open("Canal_ionico1.txt");

    //Si se produce algun error leyendolo se maneja
    if(inl.fail()){
        cout << "Error al leer datos.txt" << endl;
        return 0;
    }

    //Lee todo el archivo hasta el final
    while(!inl.eof()){
        getline(inl,s);
        //cuenta el numero de lineas que no esten vacias
        if(s != ""){
        ++numL;
      }
    }

    //Cierre archivo
    inl.close();

    //Inicializar arrays con sus pointers donde se guardara info
    //Primera columna --> x
    double t[numL];
    double *tp;
    tp = t;

    //Segunda columna --> y
    double ft[numL];
    double  *ftp;
    ftp = ft;

    //Abre archivo
    inl.open("Canal_ionico1.txt");

   //Lee todo el archivo hasta el final
    while(!inl.eof()){
        //Lee primera columna
        inl >> t[g];
        //Lee segunda columna
        inl >> ft[g];
        ++g;
    }
    //Cierre archivo
   inl.close();

   //cout << numL << endl;
   //------------------------

   vector<double> x_walkX;
   vector<double> x_walkY;

   //Num aleatorio entre 0 y 1
    double a = (double) rand() / (RAND_MAX);
    double b = (double) rand() / (RAND_MAX);

    //Num aleatorio entre -15 y 15 --> x
    //double cenx = 32*((a)+0.5) ;
    //double cenx = 7.0 ;
    double cenx = 10.0*((a)+0.5) ;
    //cout << cenx << endl;

    //Num aleatorio entre -15 y 15 --> y
    //double ceny = 10.0*((a)+0.5);
    //double ceny = 7.0;
    double ceny = 10.0*((b)+0.5) ;

    x_walkX.push_back(cenx);
    x_walkY.push_back(ceny);

   int N = 20000;

   for(int k=0; k<N; k++){

     double aa = (double) rand() / (RAND_MAX);

       //Num aleatorio entre -0.05 y 0.05
       //double paso_Al = (1/42.5)*((aa)-0.5);
       double paso_Al = (1/10.0)*((aa)-0.5);

       //cout << paso_Al << endl;

       //Initial guess + paso aletario
       double x_primeX = x_walkX[k] + paso_Al;
       double x_primeY = x_walkY[k] + paso_Al;

       //Retorna el numero minimo
       double mpp = minima(x_primeX, x_primeY,t,ft,numL);

       double alpha = mpp/minima(x_walkX[k],x_walkY[k],t,ft,numL);
       //cout << alpha << endl;

       if(alpha >= 1.0){
           //cout << x_prime << endl;
           x_walkX.push_back(x_primeX);
   	       x_walkY.push_back(x_primeY);
       }
       else{
           //Num aleatorio entre 0 y 1
           double beta = (double) rand() / (RAND_MAX);
           //cout <<beta << endl;
           if(beta <= alpha){
               x_walkX.push_back(x_primeX);
   	           x_walkY.push_back(x_primeY);
               //cout << x_prime << endl;
           }
           else{
               //Se guarda doble
               x_walkX.push_back(x_walkX[k]);
               x_walkY.push_back(x_walkY[k]);
               //cout << x_walk[k] << endl;
           }
       }
   }

//--------------------

for(int k=0; k<N; k++){
   cout << k << " " <<x_walkX[k]  << " " << x_walkY[k] << " " << sqrt(minima(x_walkX[k],x_walkY[k],t,ft,numL)) << endl;
}
   return 0;
}

//Retorna el radio -distancia- minimo de los generados a partir de punto (xx,yy)
// y todos los punto del archivo txt (tx,ty). nn -> size del array de datos del txt
double minima(double xx, double yy, double *tx, double *ty, int nn){

       //Inicializar arrays con sus pointers donde se guardaran los radios
       double radios[nn];
       double  *radiosp;
       radiosp = radios;

       //Se genera un array lleno de los radios -distancias- generados a partir del punto
       // inicial (xx,yy) y todos los punto del archivo txt (tx,ty)
       for(int i=0; i<nn+2; i++){
           double r = (((xx-tx[i])*(xx-tx[i])) + ((yy - ty[i])*(yy- ty[i])));
           radios[i] = r;
           //cout << radios[i]<< endl;
       }

      //Numero muy alto para comparacion inicial
      double mini = 100000000;

      //Se asigna a mini el valor minimo del array radios
      for(int h=0; h<nn+2; h++){
          double act = radios[h];
          if(act<mini){
	            mini = act;
          }
      }

return mini;
}
