#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

double Ta = 250;
double To = 2500;
double alpha = 2.0 * pow((double)10,(double)-12);

double getF(double T)
{
    return -alpha*(pow(T,4.0) - pow(Ta,4.0));
}

void solveEulersExplicity(double deltaT)
{
    double prev = To;
    double current;
    cout<<"DeltaT = "<<deltaT<<endl;
    for(int i=1; i<=10; i++)
    {
        current = prev + (deltaT*getF(prev));
        printf("T at time %f: %f\n",0.0 + (deltaT*(double)i),current);
        prev = current;
    }
    cout<<endl;
}



int main()
{
    double t = {2.0,1.0,0.05,0.025,0.01};

    for(int i=0; i<5; i++)
        solveEulersExplicity(t[i]);


    return 0;
}
