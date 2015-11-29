#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    double alpha = 2.0;
    double delta;
    cout<<"Enter delta: ";
    cin>>delta;
    double t[9];
    double f[9];
    t[0] = f[0] = 0;
    t[8] = f[8] = 100;

    //initialising the matrix
    double a[8],b[8],c[8];
    for(int i=1; i<=7; i++)
    {
        a[i] = c[i] = 1;
        b[i] = -(2 + (2*alpha*alpha*delta));
        f[i] = 0;
    }

    //forward sweep
    f[1] = f[1] - (a[1]*t[0]);
    f[7] = f[7] - (c[7]*t[8]);

    b[1] = b[1]; //unchanged
    //c's are unchanged
    for(int i=2; i<=7; i++)
    {
        b[i] = b[i] - ((c[i-1]*a[i])/b[i-1]);
        f[i] = f[i] - ((f[i-1]*a[i])/b[i-1]);
    }

    //find solutions using backward sweep
    t[7] = f[7]/b[7];
    for(int i=6; i>=1; i--)
        t[i] = (f[i] - (c[i]*t[i+1]))/b[i];

    cout<"Solution...\n";
    for(int i=0; i<9; i++)
        printf("T[%d] = %f\n",i,t[i]);

    cout<<"\nValues of 7 equations...\n";
    for(int i=1; i<=7; i++)
        printf("Equation %d: %f\n",i,(1*t[i-1]) + ((-2 - 2*alpha*alpha*delta)*t[i]) + (1*t[i+1]));




    return 0;
}
