#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>
void MatVec(double **A, double *x, double *sol, int n);
void computeRelativeError(double *x, double *sol, int n);

using namespace std;

int main()
{
double **A; // pointer pointer to matrix A, stores address of a pointer, can store as many pointers as rows
double *b; // pointer to vector b
int N; // rows and cols (square matrix)



fstream fin;
fin.open("Ab1.txt",ios::in);

fin>>N; // reading rows and cols
// cout<<r<<" rows by "<<c<<" columns"<<endl;

A = new double *[N]; // allocate pointers for each row
b = new double[N]; // allocate memory for vector b

for(int i = 0; i<N; i++){
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

/* Gaussian elimination */
int maxRow;
// Loop over each column k of A[][]
for(int k=0;k<N;k++)
{
    maxRow=k;
    // find the row with the max value in column k and store its row number
    for(int i=k+1;i<N;i++) 
    {
        if(A[i][k]>A[maxRow][k])
        {
            maxRow=i;
        }
    }
    // Swap the maximum row with the current row k
    if(maxRow!=k)
    {
        swap(A[maxRow],A[k]);
        swap(b[maxRow],b[k]);
    }
    
  double temp=A[k][k]; // inside or outside for loop?
  //  cout << "temp = " << A[k][k]<<endl;
    for(int i=0;i<N;i++)
    {
        
     // double temp=A[k][k]; // inside or outside for loop?
        // Divide row k by A[k][k]
        A[k][i]=A[k][i]/temp;
        // Also divide b
        b[k]=b[k]/temp;
    }
    // from jan 25 first assignment explored notes
    for(int j=k+1;j<N;j++)
    {
        double temp=A[j][k];
        for(int col=0;col<N;col++)
        {
            A[j][col]=A[j][col]-(temp*A[k][col]);
        }
       b[j]=b[j]-(temp*b[k]);
    }
    
    
}


// Output the upper triangular matrix 
    cout << "Upper Row Echelon Format: " << endl;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

// Output b vector
cout << "B vector " << endl;
for(int i=0;i<N;i++)
{
    cout << b[i] << endl;
}
double *x;
x= new double[N];
/* Perform a back-solve (bottom-up) 
From Jan 11 notes*/ 
x[N-1]=b[N-1];
for(int i=N-2;i>=0;i--)
{
    int sum=0;
    for(int j=i+1;j<N;j++)
    {
        sum=sum+A[i][j]*x[j];
        x[i]=(b[i]-sum);    
    }
}


 //Solution vector x after back substitution
 cout << "Actual solution X vector " << '\n';
for(int i = 0; i < N; i++)
{
    cout << x[i] << " ";
} 
cout << endl;

// Expected solution
double *sol;
sol = new double[N];
MatVec(A, x, sol, N);


//Computing the error vector and its two norm feb 3 notes.

double *error;
error = new double[N];
double sum = 0;
for(int i = 0; i<N; i++)
{error[i]=b[i]-A[i][i]*x[i]; // Error[] = b[] – A[][]*x[] 
sum = sum + pow(error[i],2); // sum = sum + pow(error[i],2);
}

double two_norm=sqrt(sum);
double average_error = two_norm / N;
cout << "Average error: " << average_error << endl; 

computeRelativeError(x, sol, N);

    return 0;
}



void MatVec(double **A, double *x, double *sol, int n)
{
    { double sum = 0.0;
    for(int row=0; row<n; row++)
    {
    for(int col=0; col<n; col++)
    {sum = sum + A[row][col]*x[col];}
    sol[row]=sum;
    sum = 0.0;
}
    }
} 

void computeRelativeError(double *x, double *sol, int n) {
    cout << "Relative Error: " << endl;
    for (int i = 0; i < n; i++) {
        double relativeError = abs(x[i] - sol[i]) / x[i];
        cout << relativeError << endl;
    }
}