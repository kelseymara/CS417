// power method for eigenvalues class example
#include <iostream>       
#include <random>
#include <ctime>
#include <cmath>
#include <list>
using namespace std;

 int main()
 {
     double ** A;
     A = new double * [3];
     for(int i=0; i<3; i++){A[i]=new double [3];}
     double b[3];
     double bnew[3];
     double norm;
  
     A[0][0]=4.0;
      A[0][1]=6.0;
       A[0][2]=10.0;
        A[1][0]=3;
         A[1][1]=10;
          A[1][2]=13;
           A[2][0]=-2;
            A[2][1]=-6;
             A[2][2]=-8;
             
    b[0]=1.0; b[1]=1.0;  b[2]=1.0;
    for(int j=0; j<10; j++)
    {
    for(int i=0; i<3; i++)
        {bnew[i]=A[i][0]*b[0] + A[i][1]*b[1] + A[i][2]*b[2];
       // cout<<bnew[i]<<endl;
        }
    norm = sqrt(pow(bnew[0],2.0)+pow(bnew[1],2)+pow(bnew[2],2));
    cout<<"iteration j:"<<j<<endl;
    for(int i=0; i<3; i++){bnew[i]=bnew[i]/norm; cout<<bnew[i]<<endl; b[i]=bnew[i];}
    cout<<endl;
    
    
 }
 for(int i=0; i<3; i++)
        {bnew[i]=A[i][0]*b[0] + A[i][1]*b[1] + A[i][2]*b[2];
        cout<<bnew[i]<<endl;
        }
    cout<<"max eigenvalue: "<<bnew[0]/b[0]<<endl;
 return 0;
    
}
