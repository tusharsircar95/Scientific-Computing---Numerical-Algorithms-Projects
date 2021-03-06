#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

double getF(double x)
{
    return (double)200.0 * x * (x - (double)4.0);
}
double getAnalytic(double x,double y)
{
    double ans = 0;
    double pi = atan(1);
    for(int i=1; i<=50; i+=2)
        ans += -2.0 * ((double)1/sinh(-(double)i * pi))* ((double)200/(pow((double)i*pi,3.0))) * sin(((double)i*pi*x)) * sinh((double)i*pi*(y-(double)1));
    return ans;
}


void solvePDE(double deltaX,double deltaY)
{
    double beta = deltaX/deltaY;
    int Nx = -1 + floor((double)4.0/deltaX);
    int Ny = -1 + floor((double)1.0/deltaY);
    printf("Number of variables along X: %d\nNumber of variables along Y: %d\nAspect Ratio: %f\n",Nx,Ny,beta);

    double x[Nx+2];
    double y[Ny+2];

    x[0] = y[0] = 0;
    for(int i=1; i<Nx+2; i++)
        x[i] = x[i-1] + deltaX;
    for(int i=1; i<Ny+2; i++)
        y[i] = y[i-1] + deltaY;

    double T[Nx+2][Ny+2];
    double tempT[Nx+2][Ny+2];

    for(int i=0; i<Nx+2; i++)
        T[i][0] = tempT[i][0] =  getF(x[i]);
    for(int i=0; i<Ny+2; i++)
        T[0][i] = tempT[0][i] = T[Nx+1][i] = tempT[Nx+1][i] = 0;
    for(int i=0; i<Nx+2; i++)
        T[i][Ny+1] = tempT[i][Ny+1] = 0;

    //initialisation code
    for(int i=1; i<=Nx; i++)
        for(int j=1; j<=Ny; j++)
            T[i][j] = 0;

    double errorNum,errorDen;
    double epsilon = 0.000001;
    double errorCount = 0;
    long long iterations = 0;
    do
    {
        errorCount = 0;
        iterations++;
        errorNum = errorDen = 0;
        for(int j=1; j<=Ny; j++)
            for(int i=1; i<=Nx; i++)
        {
            tempT[i][j] = tempT[i-1][j] + T[i+1][j] + (pow(beta,(double)2)*(tempT[i][j-1] + T[i][j+1]));
            tempT[i][j] /= (double)2.0*((double)1 + pow(beta,(double)2));
            errorNum += pow(fabs(tempT[i][j] - T[i][j]),(double)2);
            errorDen += pow(T[i][j],(double)2);
            if(fabs(tempT[i][j] - T[i][j])/fabs(T[i][j]) < epsilon)
                errorCount++;
        }

        for(int i=1; i<=Nx; i++)
            for(int j=1; j<=Ny; j++)
                T[i][j] = tempT[i][j];

    }while(errorCount < Nx*Ny);
    cout<<"Number of iterations: "<<iterations<<endl;


    FILE *output = fopen("outputTest.txt","w");
    FILE *aOutput = fopen("analyticOutput.txt","w");


    for(int j=0; j<=Ny; j++)
    {
        fprintf(output,"%f %f\n",y[j],T[(Nx+1)/2][j]);
        fprintf(aOutput,"%f %f\n",y[j],getAnalytic(x[(Nx+1)/2],y[j]));
    }
    fclose(output);
    fclose(aOutput);
}


int main()
{
    double deltaX,deltaY;


    while(1)
    {
        cout<<"\nEnter deltaX and deltaY: ";
        scanf("%lf %lf",&deltaX,&deltaY);
        solvePDE(deltaX,deltaY);
    }

    return 0;
}
