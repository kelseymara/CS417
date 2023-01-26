#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
using namespace std;
void MatVec(int r, int c, double **A, double*x,double* b);
int main()
{
    fstream fout;
    fout.open("Mat1.txt",ios::out);
    int r, c;
    double **A;
    double *x;
    double *b;
    cout<<"how many rows and cols?"<<endl;
    cin>>r>>c;

    A = new double*[r];
    for(int i=0; i<r; i++){A[i]=new double[c];}
    b = new double[r];
    x = new double[r];

    default_random_engine * gptr;
    gptr = new default_random_engine(time(NULL));
    normal_distribution<double> valdist(0.0, 50);
    uniform_real_distribution<double> xdist(10.0, 50.0);
    double val;
    double sum=0;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
           /// val = valdist(*gptr);
           val = 1.0;
            sum = sum + fabs(val);
            A[i][j]=val;
        }
        A[i][i]=sum;
        sum = 0.0;
        //val = xdist(*gptr);
        val = 1;
        x[i]= val;
    }

    cout<<"matrix A:"<<endl;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    cout<<"solution x"<<endl;
    for(int i=0; i<r; i++)
    {
        cout<<x[i]<<endl;
    }
        MatVec(r,c,A,x,b);
    cout<<endl<<endl;
    cout<<"right side vector b"<<endl;
    for(int i=0; i<r; i++)
    {
        cout<<b[i]<<endl;
    }
    return 0;
}

void MatVec(int r, int c, double **A, double*x, double* b)
{   double sum = 0;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
             sum= sum + (A[i][j]*x[j]);
        }
        b[i]=sum;
        sum = 0.0;
    }
}