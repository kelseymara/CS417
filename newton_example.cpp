// In Class Example 2/27
/// for function f = -3.14*x^2   +  5.84*x  +  2.12;

///              df/dx = - 6.28x + 5.84

#include <iostream>       // std::cout
#include <random>
#include <ctime>
#include <cmath>
#include <list>
using namespace std;
double fx(double v);
double fprime(double v);
 int main()
 {
   double xold = -5.0; // 
   double xnew = 0;
   while(abs(fx(xnew))>.0001) 
    {
        xnew = xold - (fx(xold)/fprime(xold)); // from the ratio https://en.wikipedia.org/wiki/Newton%27s_method
        cout<<"xold = "<<xold<<" xnew = "<<xnew<<endl;
        xold = xnew;
    }
   cout<<"solution = "<<xnew<<endl;
    return 0;
 }

 
double fx(double v)
{
    return (-3.14*pow(v,2) +(5.84*v)  + 2.12);
}

double fprime(double v) // first derivative
{
    return (-6.28*v + 5.84);  
}
