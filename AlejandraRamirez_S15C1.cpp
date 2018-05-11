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

   int N = 100;

   vector<double> x_walk;
   for(int i=0; i<N; i++){

       //Num aleatorio entre 0 y 1
       double a = (double) rand() / (RAND_MAX);

       //Num aleatorio entre -4 y 4
       double x_0 = 8.0*((a)-0.5);
       x_walk.push_back(x_0);
       //cout << x_walk[i] << endl;
   }


   for(int i=0; i<N; i++){

       //Num aleatorio entre 0 y 1
       double a = (double) rand() / (RAND_MAX);

       //Num aleatorio entre -0.05 y 0.05
       double paso_Al = (1/10.0)*((a)-0.5);
       //cout << paso_Al << endl;

       //Initial guess + paso aletario
       double x_prime = x_walk[i] + paso_Al;
       //cout << x_prime << endl;

       double alpha = nasty_function(x_prime)/nasty_function(x_walk[i]);
       //cout << alpha << endl;

       if(alpha >= 1.0){
           x_walk.push_back(x_prime);
       }
       else{
           //Num aleatorio entre 0 y 1
           double beta = (double) rand() / (RAND_MAX);
           if(beta <= alpha){
               x_walk.push_back(x_prime);
           }
           else{
               //Se guarda doble
               x_walk.push_back(x_walk[i]);
           }
       }
   }

double f[1000];

int u = 0;

//Valores que se dan a python
   double i = -4.0;
   double cc = (4.0-i)/1000;
   while(i<4.0){
       //f[u] = nasty_function(i);
       i = i + cc;
       u = u+1;

       cout << i << " " << nasty_function(i) << " " << nasty_function(x_walk[u]) << endl;

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
