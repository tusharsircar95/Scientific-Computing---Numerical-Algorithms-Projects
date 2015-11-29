#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

double getF(double x)
{
    return 1/(1 + (x*x));
}
double getP(double p,double a[],double x[],int noOfPoints)
{
    double mul = 1;
    double ans = 0;
    for(int i=0; i<noOfPoints; i++)
    {
        ans += a[i]*mul;
        mul = mul * (p - x[i]);
    }
    return ans;
}

int main()
{
    double left,right; //end points
    int noOfPoints; //number of equally spaced points
    double h; //spacing between consequetive nodes

    cout<<"Enter end points: ";
    cin>>left>>right;
    cout<<"Enter number of nodes: ";
    cin>>noOfPoints;
    h = (right-left)/((double)(noOfPoints-1));

    double x[noOfPoints]; //nodes of the interpolating polynomial
    double dividedDiff[noOfPoints][noOfPoints];


    //store all nodes
    x[0] = left;
    for(int i=1; i<noOfPoints; i++)
        x[i] = x[i-1] + h;

    for(int i=0; i<noOfPoints; i++)
        dividedDiff[i][i] = getF(x[i]);

    //calculate divided differences
    for(int i=1; i<noOfPoints; i++)
    {
        int r = 0;
        int c = i;
        while(c<noOfPoints)
        {
            dividedDiff[r][c] = (dividedDiff[r+1][c] - dividedDiff[r][c-1])/(x[c] - x[r]);
            r++;
            c++;
        }
    }

    //print coefficients
    double a[noOfPoints];
    cout<<"\nCoefficients found to be...\n";
    for(int i=0; i<noOfPoints; i++)
    {
        a[i] = dividedDiff[0][i];
        printf("A%d = %f\n",i,dividedDiff[0][i]);
    }






    return 0;
}
