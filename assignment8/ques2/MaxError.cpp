#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

double getG(double x)
{
    return sin((double)atan(1)*(double)4*x);
}
double getExact(double x,double b,double D)
{
    double pi = atan(1)*(double)4;
    return exp(-(b - (D*pi*pi)))*sin(pi*x);
}

int main()
{
    double xMin = 0, xMax = 1;
    double tMin = 0, tMax = 1;
    double D = 0.1;
    double b = 1.0;
    double deltaX,deltaT;
    double m[] = {4,8,16,32};
    FILE * output = fopen("maxError_1.txt","w");

    for(int index = 0; index<4; index++)
    {



   // cout<<"Enter size of space interval: ";
   // cin>>deltaX;
    cout<<"Enter size of time interval: ";
    deltaT = (double)1.0/m[index];//cin>>deltaT;
    cout<<"Enter size of space interval: ";
    deltaX = 1.0/10.0;//cin>>deltaX;
    int xPoints =  1 + floor(((double)1)/deltaX);
    int tPoints = 1 + floor(((double)1.0)/deltaT);

    double point[xPoints][tPoints];

    double x[xPoints];
    double t[tPoints];

    for(int i=0; i<xPoints; i++)
        x[i] = (double)i * deltaX;
    for(int i=0; i<tPoints; i++)
        t[i] = (double)i * deltaT;

    for(int c=0; c<xPoints; c++)
        point[c][0] = getG(x[c]);
    for(int r=0; r<tPoints; r++)
        point[0][r] = point[xPoints-1][r] = 0;


    double alpha = (D*deltaT)/(deltaX*deltaX);
    double beta = (b*deltaT);
    //cout<<"c1: "<<c1<<endl<<"c2: "<<c2<<endl;
    for(int r=1; r<tPoints; r++)
    {
        for(int c=1; c<xPoints-1; c++)
        {
            point[c][r] = (alpha * (point[c-1][r-1] + point[c+1][r-1])) + ((1 - (2*alpha) - beta)*(point[c][r-1]));
            cout<<point[c][r]<<endl;
        }
        cout<<"----------\n";
    }

    double maxError = -1;
    for(int r=0; r<xPoints; r++)
        maxError = max(maxError,abs(point[r][tPoints-1] - getExact(x[r],b,D)));
    fprintf(output,"%f %f\n",m[index],maxError);

    }
    fclose(output);

}

