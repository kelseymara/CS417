#include <iostream>
#include <iomanip>
#include <fstream>
#include <ostream>
#include <cmath>
#include <vector>

using namespace std;

void gaussElim(double **A, double *b, int n);
void matVec(double **A, double *b, double *x, int n);
void showMatrix(double **A, int n, double *b);

int main() {
    int n; // numbers of rows and col (square matrix)
    double sum = 0.0, relativeError = 0.0, twoNorm;
    double *b, *b_predicted, *x, *error;
    double **A;
   // ofstream file;
    fstream file;
    file.open("s9.txt",ios::in);

    b = new double[n]; // allocate memory for vector b 
    b_predicted = new double[n];
    x = new double[n];
    error = new double[n];
    A = new double *[n]; // nrows

    // Creates Matrix A 
    for(int i = 0; i < n; i++) {
        A[i] = new double[n]; // ncols
    }

    showMatrix(A, n, b);

    gaussElim(A, b, n);

    matVec(A, b, x, n);

    // output solution vector x, replace 30 with however many rows the matrix has
    for(int i = 0; i < n; i++)
    {
     cout << x[i] << " ";
     if ((i + 1) % 30 == 0) {
            cout << endl;
    }
    } 
    file.close();

    return 0;
}

void gaussElim(double **A, double *b, int n) {
    double temp = 0.0;

    // Loop over each column i of A[][]
    for(int i = 0; i < n; i++) {
        int maxRow = i;
        double maxVal = fabs(A[i][i]); // maxValue

        for(int k = i + 1; k < n; k++) {
            // Find the row with the max value in column k and store its row number
            if(fabs(A[k][i]) > maxVal) {
                maxVal = fabs(A[k][i]);
                maxRow = k;
            }
        }

        if(maxRow != i) 
        {
            // Swap the maximum row with the current row i 
            double *tempRow = A[i];
            A[i] = A[maxRow];
            A[maxRow] = tempRow;

            // Swap the maximum row with the current row i 
            double tempVal = b[i];
            b[i] = b[maxRow];
            b[maxRow] = tempVal;
        }

        temp = A[i][i];
        for(int j = 0; j < n; j++) 
        {
            // Divide row i by A[i][i]
            A[i][j] = A[i][j] / temp;
        }
        b[i] = b[i] / temp;

        // From Jan 25 first assignment explored notes
        for(int k = i + 1; k < n; k++) {
            temp = A[k][i];
            for(int j = 0; j < n; j++) {
                A[k][j] = A[k][j] - (temp * A[i][j]);
            }
            b[k] = b[k] - (temp * b[i]);
        }
    }
}

void matVec(double **A, double *b, double *x, int n) {
    for(int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for(int j = i + 1; j < n; j++) {
            x[i] = x[i] - A[i][j] * x[j];
        }
    }    
}

void showMatrix(double **A, int n, double *b) {
    fstream fin;
    fin.open("q9.txt", ios::in);
    fin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            fin >> A[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        fin >> b[i];
    }

    fin.close();
}
