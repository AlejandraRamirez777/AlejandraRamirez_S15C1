#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
//#include <random>

using namespace std;

double nasty_function(double x);

int main () {

   int N = 200000;

   vector<double> x_walk;

   //Num aleatorio entre 0 y 1
    double a = (double) rand() / (RAND_MAX);

    //Num aleatorio entre -4 y 4
    double x_0 = 8.0*((a)-0.5);
    //double x_0 = 3.0;
    x_walk.push_back(x_0);
    //cout << x_walk[1] << endl;


   for(int k=0; k<N; k++){

       //Num aleatorio entre 0 y 1
       double a = (double) rand() / (RAND_MAX);
       //cout << a << endl;

       //Num aleatorio entre -0.05 y 0.05
       double paso_Al = (1/10.0)*((a)-0.5);
       //cout << paso_Al << endl;

       //Initial guess + paso aletario
       double x_prime = x_walk[k] + paso_Al;
       //cout << x_prime << " " << x_walk[k] << endl;

       double alpha = nasty_function(x_prime)/nasty_function(x_walk[k]);
       //cout << alpha << endl;

       if(alpha >= 1.0){
         //cout << x_prime << endl;
           x_walk.push_back(x_prime);
       }
       else{
           //Num aleatorio entre 0 y 1
           double beta = (double) rand() / (RAND_MAX);
           //cout <<beta << endl;
           if(beta <= alpha){
               x_walk.push_back(x_prime);
               //cout << x_prime << endl;
           }
           else{
               //Se guarda doble
               x_walk.push_back(x_walk[k]);
               //cout << x_walk[k] << endl;
           }
       }
   }

//double f[1000];

int u = 0;

//Valores que se dan a python
   double i = -4.0;
   double cc = (4.0-i)/200000;
   while(i<4.0){

      cout << i << " " << nasty_function(i) << " " << nasty_function(x_walk[u]) << " " <<  x_walk[u] << endl;
       //f[u] = nasty_function(i);
       i = i + cc;
       u = u+1;

   }

//Se entra al while 1000 veces
//cout << u << endl;

   //cout << nasty_function(0.5) << endl;

   return 0;
}

//Genera la funcion horrible punto a punto
double nasty_function(double x){
    double x_0 = 3.0;
    double a = 0.01;
    return exp(-(x*x))/ (float) ((x-x_0)*(x-x_0) + a*a);
}
