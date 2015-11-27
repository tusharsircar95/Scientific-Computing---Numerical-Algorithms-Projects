//TUSHAR SIRCAR
//130123038
#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

void solveThomas(double a[],double b[],double c[],double t[],double f[],int k);
int main()
{
    int noOfNodes = 33;
    double h = 1;

    FILE *output = fopen("output.txt","w");
    FILE *input = fopen("input.txt","r");


    float X[noOfNodes];
    float Y[noOfNodes];
    for(int i=0; i<noOfNodes; i++)
        fscanf(input,"%f, %f",&X[i],&Y[i]);


    double plotX[noOfNodes * 10];
    double plotY[noOfNodes * 10];
    double t[noOfNodes];
    double a[noOfNodes],b[noOfNodes],c[noOfNodes],d[noOfNodes];
    int k = noOfNodes - 1;
    double tA[k],tB[k],tC[k],tF[k],tX[k];



    //initialise the x-axis points
    t[0] = 0;
    for(int i=1; i<noOfNodes; i++)
        t[i] = t[i-1] + 1;


    //first parametrise the x-coordinates
    for(int i=0; i<noOfNodes; i++)
        a[i] = X[i];
    c[0] = c[noOfNodes-1] = 0;


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

    for(int i=0; i<(noOfNodes-1)*10; i++)
    {
        int polyNumber = i/10;
        double p = (double)i*(0.1);
        plotX[i] = a[polyNumber] + (b[polyNumber]*(p - (double)polyNumber)) + (c[polyNumber]*pow(p-(double)polyNumber,2)) + (d[polyNumber]*pow(p-(double)polyNumber,3));
    }

     for(int i=0; i<33; i++)
       printf("X: Polynomial %d: %f %f %f %f\n",i,a[i],b[i],c[i],d[i]);



    //second parametrise the y-coordinates
    for(int i=0; i<noOfNodes; i++)
        a[i] = Y[i];
    c[0] = c[noOfNodes-1] = 0;

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

    for(int i=0; i<(noOfNodes-1)*10; i++)
    {
        int polyNumber = i/10;
        double p = (double)i*(0.1);
        plotY[i] = a[polyNumber] + (b[polyNumber]*(p - (double)polyNumber)) + (c[polyNumber]*pow(p-(double)polyNumber,2)) + (d[polyNumber]*pow(p-(double)polyNumber,3));
    }

     for(int i=0; i<33; i++)
       printf("Y: Polynomial %d: %f %f %f %f\n",i,a[i],b[i],c[i],d[i]);



    for(int i=0; i<(noOfNodes-1)*10; i++)
        fprintf(output,"%f,%f\n",plotX[i],plotY[i]);

    fclose(output);

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
