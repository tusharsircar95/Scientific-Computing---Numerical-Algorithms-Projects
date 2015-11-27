#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

double getExactSolution(double x,double Re)
{
    return (exp(Re*x)-1.0)/(exp(Re)-1.0);
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


void solvePDE(double Re,double deltaX)
{
    int Nx = -1 + floor((double)1.0/deltaX);
    cout<<"Number of variables along X-axis: "<<Nx<<endl;

    double beta = (Re*deltaX)/(double)2.0;
    double solution[Nx+2];
    solution[0] = 0.0;
    solution[Nx+1] = 1.0;

    double a[Nx+2],b[Nx+2],c[Nx+2],f[Nx+2];
    for(int i=0; i<Nx+2; i++)
    {
        a[i] = (double)1.0 + beta;
        b[i] = -(double)2.0;
        c[i] = (double)1.0 - beta;
        f[i] = 0;
    }

    solveThomas(a,b,c,solution,f,Nx+1);

    FILE *output = fopen("output.txt","w");
    FILE *aOutput = fopen("aOutput.txt","w");
    for(int i=0; i<Nx+2; i++)
    {
        fprintf(output,"%f %f\n",deltaX*(double)i,solution[i]);
        fprintf(aOutput,"%f %f\n",deltaX*(double)i,getExactSolution((double)i*deltaX,Re));
    }
    fclose(output);
    fclose(aOutput);
}







int main()
{
    double Re,deltaX;

    while(1)
    {
        cout<<"\nEnter values of Re and deltaX: ";
        scanf("%lf %lf",&Re,&deltaX);
        solvePDE(Re,deltaX);
    }



    return 0;
}
