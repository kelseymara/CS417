// jacobi solver: not direct method
/* 15:00 2/1/23
Ax=b 
D= diagonals of A (0 everywhere else)
C= modified matrix just A with 0 on diagonals
C=A-D (all zeros on diag)
(D+C)x=b
Dx+Cx=b
Dx=b-Cx easily generate Dinverse as 1/D[k][k]
inverse= 1/diagonal entries
Dinverse * D * x = Dinverse * (b-Cx)
x = Dinverse * (b-Cx) // uh oh... x on both sides of equations
(recursive process)xnew = Dinverse * (b-Cxold)
keep doing it, if xnew is right you quit.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>
void jacobiSolver(int N,double **A, double *b, double *xNew, double *xOld,double **C,double *dInv,int i);
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
   // N=sqrt(N);
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
    jacobiSolver(N,A,b,xNew,xOld,C,dInv,i);
    /*
    for(int i=0;i<N;i++)
    {
        cout << xOld[i] << endl;
    } */


return 0;
}


void jacobiSolver(int N,double **A, double *b, double *xNew, double *xOld,double **C,double *dInv,int i)
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
        xNew[row]=0.0;
    for(int col = 0; col<N; col++)
    { 
        xNew[row] = xNew[row] + C[row][col]*xOld[col];      
    }
    xNew[row] = dInv[row] * (b[row] - xNew[row]);    }
       // xOld=xNew;
    for(int i = 0; i < N; i++)
    {
    xOld[i] = xNew[i];
    }
    for(int i=0;i<N;i++)
    {
        cout << xOld[i] << endl;
    }
       // cout << i << "iteration. xOld is: " << xOld << endl;
    i++;
    jacobiSolver(N,A,b,xNew,xOld,C,dInv,i);
    }
}
