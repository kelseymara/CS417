/* 2/3/23 Lecture
*/
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>
void SOR(int N,double **A, double *b, double *xNew, double *xOld,double **C,double *dInv,double w,int i);
using namespace std;
int main()
{
// look at 2/1/23 lecture
    double **A; // pointer pointer to matrix A, stores address of a pointer, can store as many pointers as rows
    double *b; // pointer to vector b
    
    int N; // rows and cols (square matrix)
    

    fstream fin;
    fin.open("Ab2.txt",ios::in);

    fin>>N; // reading rows and cols
    N=sqrt(N);
    // cout<<r<<" rows by "<<c<<" columns"<<endl;

    A = new double *[N]; // allocate pointers for each row
    b = new double[N]; // allocate memory for vector b
   


    for(int i = 0; i<N; i++)
    {
        A[i] = new double[N]; // allocate memory for columns of each row
    }
// from now on, like any other matrix
// Read in matrix A from file
    for(int i=0; i<N; i++)
    {
    for(int j=0; j<N; j++)
    {
        fin>>A[i][j];
    }
    }

// Read in vector b from file
for(int i=0; i<N; i++)
{
    fin>>b[i];
} 

fin.close();
    double **C; // C is A but 0s on the diagonals
    double *dInv; // pointer to d inverse
    double *xNew;
    double *xOld;
    dInv= new double[N]; // allocate memory
    xNew= new double[N];
    xOld= new double[N];
    C= new double*[N];
     for(int i = 0; i<N; i++)
    {
        C[i] = new double[N]; // allocate memory for columns of each row
    }
    // initalize matrix C
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(i==j)
            C[i][j]=0;
            else
            C[i][j]=A[i][j];
           // cout << "Matrix C: " << C[i][j];
        }
      //  cout << endl;
    }

// initalize vector d inverse (1/diagonal of matrice A)
    for(int i=0;i<N;i++)
    {
    dInv[i]=1/A[i][i];
   // cout << "D inverse: " << dInv[i] << endl;
    }
    // initialize xOld to 0 vector
    for(int i=0;i<N;i++)
    {
        xOld[i]=0;
    }

    int i=1;
    double w=0.0;
    cout << "Enter omega " << endl;
    cin >> w;
    SOR(N,A,b,xNew,xOld,C,dInv,w,i);
    /*
    for(int i=0;i<N;i++)
    {
        cout << xOld[i] << endl;
    } */

    

return 0;
}


void SOR(int N,double **A, double *b, double *xNew, double *xOld,double **C,double *dInv, double w,int i)
{
    
    if(i==11)
    {
         exit;
    }
    else
    {
    cout << "iteration:   " << i << endl;
    // from feb 1 notes
   for(int row = 0; row<N; row++)
    { 
        // xNew[row]=0.0;
        double sumOne=0.0;
        double sumTwo=0.0;
    for(int col = 0; col<row; col++) // if already computed, use x new
    {
        sumOne=xNew[row]+C[row][col]*xNew[col];
    }
    for(int col=row+1;col<N;col++) // else use xold
    { 
        sumTwo = xNew[row] + C[row][col]*xOld[col]; 
        }
        xOld[row]=xNew[row]; // immediate update of xOld
       // this is gauss siedel xNew[row] = dInv[row] * (b[row] - sumOne-sumTwo);    
        xNew[row]=(1 - w) * xOld[row] + (w * dInv[row] * (b[row] - sumOne - sumTwo));
    } 
      
    for(int i=0;i<N;i++)
    {
        cout << xOld[i] << endl;
    }
       // cout << i << "iteration. xOld is: " << xOld << endl;
    i++;
    SOR(N,A,b,xNew,xOld,C,dInv,w,i);
    }
}