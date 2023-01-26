// Example program to load a matrix with input from a .txt file
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>
using namespace std;

int main()
{
    double **A;
    double *b;
    int r, c;

    fstream fin;
    fin.open("Ab1.txt",ios::in);

    fin>>r>>c;
    cout<<r<<" rows by "<<c<<" columns"<<endl;

    A = new double *[r];
    b = new double[r];
    for(int i = 0; i<r; i++){
        A[i] = new double[c];
    }
    cout<<endl<<endl;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            fin>>A[i][j];
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0; i<r; i++)
    {
        fin>>b[i];
        cout<<b[i]<<endl;
    }
    fin.close();
    return 0;
}
