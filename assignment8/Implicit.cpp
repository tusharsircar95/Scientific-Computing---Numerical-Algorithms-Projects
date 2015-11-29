#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

double getG(double x)
{
    return sin((double)atan(1)*(double)4*x);
}

void solveGaussSiedel(int xPoints,double alpha,double beta,double arr1[],double arr2[])
{
    int n = xPoints-2;
    double b[n+1];

    double c1 = alpha/(double)2.0;
    double c2 = (double)1 - (alpha) - (beta/(double)2);

    double c3 = -alpha/(2.0);
    double c4 = (double)1 + (alpha) + (beta/(double)2);

    cout<<c3<<" "<<c4<<endl;


    for(int i=1; i<=n; i++)
        b[i] = (c1*arr1[i-1]) + (c2*arr1[i]) + (c1*arr1[i+1]);
    double err;
    do
    {
        for(int i=1; i<=n; i++)
        {
            if(i == 1)
            {
                arr2[i] = (b[i] - (c3*arr1[i+1]))/c4;
            }
            else if(i != n)
            {
                arr2[i] = (b[i] - (c3*arr2[i-1]) - (c3*arr1[i+1]))/c4;
            }
            else
                arr2[i] = (b[i] - (c3*arr2[i-1]))/c4;

        }
        double maxErr1 = -1;
        double maxErr2 = -1;
        for(int i=1; i<=n; i++)
        {
            maxErr1 = max(maxErr1,fabs(arr1[i]-arr2[i]));
            maxErr2 = max(maxErr2,fabs(arr1[i]));
            cout<<arr2[i]<<" ";
            arr1[i] = arr2[i];
        }
        cout<<endl;
        err = maxErr1/maxErr2;

    }while(err > 0.0001);
}



int main()
{
    double xMin = 0, xMax = 1;
    double tMin = 0, tMax = 1;
    double D = 0.1;
    double b = 1.0;
    double deltaX,deltaT;
   // cout<<"Enter size of space interval: ";
   // cin>>deltaX;
    cout<<"Enter size of time interval: ";
    cin>>deltaT;
    deltaX =  sqrt((double)4*D*deltaT/(2.0 - (b*deltaT)));
    cout<<"Space interval: "<<deltaX<<endl;
    int xPoints =  1 + floor(((double)1)/deltaX);
    int tPoints = 1 + floor(((double)1.0)/deltaT);

    cout<<"X-Points: "<<xPoints<<endl;

    double arr1[xPoints];
    double arr2[xPoints];

    double x[xPoints];
    double t[tPoints];

    for(int i=0; i<xPoints; i++)
        x[i] = (double)i * deltaX;
    for(int i=0; i<tPoints; i++)
        t[i] = (double)i * deltaT;

    for(int c=0; c<xPoints; c++)
        arr1[c] = getG(x[c]);


    double alpha = (D*deltaT)/(deltaX*deltaX);
    double beta = (b*deltaT);

    for(int i=0; i<tPoints; i++)
        solveGaussSiedel(xPoints,alpha,beta,arr1,arr2);


     FILE * output = fopen("output.txt","w");
     fprintf(output,"%f %f\n",x[0],0);
    for(int r=1; r<xPoints-1; r++)
        fprintf(output,"%f %f\n",x[r],arr1[r]);

    fprintf(output,"%f %f\n",x[xPoints-1],0.0);
    fclose(output);

}
