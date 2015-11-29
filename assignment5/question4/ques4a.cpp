#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

double getF(double x)
{
    if(x == 0)
        return 0;
    if(x == 3)
        return 225;
    if(x == 5)
        return 383;
    if(x == 8)
        return 623;
    if(x == 13)
        return 993;
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
    int noOfPoints = 5;
    double x[5] = {0,3,5,8,13}; //nodes of the interpolating polynomial
    double dividedDiff[noOfPoints][noOfPoints];

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
    cout<<"\nPolynomial to predict Distance VS Time...\nCoefficients found to be...\n";
    for(int i=0; i<noOfPoints; i++)
    {
        a[i] = dividedDiff[0][i];
        printf("A%d = %f\n",i,dividedDiff[0][i]);
    }

    cout<<"\nChecking difference in [0,8]...\n";
    for(int i=0; i<noOfPoints; i++)
    {
        printf("Difference at %d = %f\n",i,abs(getF(x[i]) - getP(x[i],a,x,noOfPoints)));
    }




    return 0;
}

