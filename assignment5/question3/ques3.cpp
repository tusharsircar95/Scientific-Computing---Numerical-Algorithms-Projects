#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

void solveThomas(double a[],double b[],double c[],double t[],double f[],int k);
double getF(double x)
{
    return 1/(1 + (x*x));
}

int main()
{
    double left = -5,right = 5;
    int noOfPoints = 41;
    double h = (right-left)/(noOfPoints-1);
    double x[noOfPoints];

    //nodes for interpolation
    x[0] = left;
    for(int i=1; i<noOfPoints; i++)
        x[i] = x[i-1] + h;

    //no of polynomials will be 40
    double a[noOfPoints],b[noOfPoints],c[noOfPoints],d[noOfPoints];
    for(int i=0; i<noOfPoints; i++)
        a[i] = getF(x[i]);


    c[0] = c[noOfPoints-1] = 0;

    int k = noOfPoints - 1; //40
    double tA[k],tB[k],tC[k],tF[k],tX[k];
    for(int i=1; i<k; i++)
    {
        tA[i] = h;
        tB[i] = (4*h);
        tC[i] = h;
        tF[i] = ((double)3/h)*(a[i+1] - a[i] - a[i] + a[i-1]);

    }
    tX[0] = tX[k] = 0;
    tF[0] = tF[k] = 0;
    solveThomas(tA,tB,tC,tX,tF,k);


    for(int i=0; i<=k; i++)
        c[i] = tX[i];



    for(int i=0; i<k; i++)
    {
        b[i] = ((a[i+1]-a[i])/h) - (h/3)*((2*c[i])+c[i+1]);
        d[i] = (c[i+1]-c[i])/(3*h);
    }

    for(int i=0; i<k; i++)
        printf("Poly %d: %f %f %f %f\n",i,a[i],b[i],c[i],d[i]);

    double low = 0;
    double high = 5;
    int points = 101;
    double H = (high-low)/(points-1);

    cout<<endl;
    for(int i=0; i<points; i++)
    {
        double X = low + (i*H);
        double orig = getF(X);
        int polyNumber = (X+5)/h;
        double estimate = a[polyNumber] + (b[polyNumber]*(X - x[polyNumber])) +  (c[polyNumber]*pow(X-x[polyNumber],2)) + (d[polyNumber]*pow(X-x[polyNumber],3));
        printf("Difference at point %d: %f\n",i,estimate-orig);
    }

    return 0;
}

void solveThomas(double a[],double b[],double c[],double t[],double f[],int k)
{

    //forward sweep
    f[1] = f[1] - (a[1]*t[0]);
    f[k-1] = f[k-1] - (c[k-1]*t[k]);

    b[1] = b[1]; //unchanged
    //c's are unchanged
    for(int i=2; i<=k-1; i++)
    {
        b[i] = b[i] - ((c[i-1]*a[i])/b[i-1]);
        f[i] = f[i] - ((f[i-1]*a[i])/b[i-1]);
    }

    //find solutions using backward sweep
    t[k-1] = f[k-1]/b[k-1];
    for(int i=k-2; i>=1; i--)
        t[i] = (f[i] - (c[i]*t[i+1]))/b[i];


}
