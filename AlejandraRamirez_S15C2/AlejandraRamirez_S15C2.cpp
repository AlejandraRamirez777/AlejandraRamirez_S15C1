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

double minima(double xx, double yy, double *tx, double *ty);

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

    //Num aleatorio entre -15 y 15 --> x
    double cenx = 30.0*((a)-0.5);

    //Num aleatorio entre -15 y 15 --> y
    double ceny = 30.0*((a)-0.5);

    x_walkX.push_back(cenx);
    x_walkY.push_back(ceny);

   int N = 20000;

   for(int k=0; k<N; k++){

      //Num aleatorio entre -0.05 y 0.05
       double paso_Al = (1/10.0)*((a)-0.5);

       //cout << paso_Al << endl;

       //Initial guess + paso aletario
       double x_primeX = x_walkX[k] + paso_Al;
       double x_primeY = x_walkY[k] + paso_Al;
       
       double mpp = minima(x_primeX, x_primeY);

       double alpha = mpp/minima(x_primeX[k],x_primeY[k]);
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


   return 0;
}

double minima(double xx, double yy, double *tx, double *ty){

       double radios[numL];
       double  *radiosp;
       radiosp = radios;      


       for(int i=0; i<numL; i++){

           double radios = ((xx-tp[i])*(xx-tp[i]) + (yy - ftp[i])*(yy- ftp[i]));
           radios[i] = radios;
           //cout << r[i]<< endl;
 
       }

       double mini = 100000000;

      for(int h=0; h<numL; h++){
         double act = radios[h];
         if(act<mini){
	     mini = act;
         }
      }

return mini;
}
