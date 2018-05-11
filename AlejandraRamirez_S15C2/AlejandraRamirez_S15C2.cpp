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


       double r[numL];
       double  *rp;
       rp = r;      

       for(int i=0; i<numL; i++){

           double rr = ((cenx-tp[i])*(cenx-tp[i]) + (ceny - ftp[i])*(ceny- ftp[i]));
           r[i] = rr;
           //cout << r[i]<< endl;

          
       }

      double min = 100000000;

      for(int h=0; h<numL; h++){
         double ac = r[h];
         if(ac<min){
	     min = ac;
         }
      }

      //Num aleatorio entre -0.05 y 0.05
       double paso_Al = (1/10.0)*((a)-0.5);

       //cout << paso_Al << endl;

       //Initial guess + paso aletario
       double x_primeX = x_walkX[k] + paso_Al;
       double x_primeY = x_walkY[k] + paso_Al;
       

       //cout << x_prime << " " << x_walk[k] << endl;

       double r2[numL];
       double  *r2p;
       r2p = r2;      


       for(int i=0; i<numL; i++){

           double rr2 = ((x_primeX-tp[i])*(x_primeX-tp[i]) + (x_primeY - ftp[i])*(x_primeY- ftp[i]));
           r2[i] = rr2;
           //cout << r[i]<< endl;
 
       }

       double min2 = 100000000;

      for(int h=0; h<numL; h++){
         double ac2 = r2[h];
         if(ac2<min2){
	     min2 = ac2;
         }
      }

       double alpha = min2/min;
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

double fou(double *unP1, double *unP1, int N){

       double rrr[numL];
       double  *rrrp;
       rrrp = rrr;      


       for(int i=0; i<numL; i++){

           double rrr = ((x_primeX-tp[i])*(x_primeX-tp[i]) + (x_primeY - ftp[i])*(x_primeY- ftp[i]));
           r2[i] = rr2;
           //cout << r[i]<< endl;
 
       }

       double min2 = 100000000;

      for(int h=0; h<numL; h++){
         double ac2 = r2[h];
         if(ac2<min2){
	     min2 = ac2;
         }
      }
}