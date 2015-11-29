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
    solveEulersExplicity(2);


    return 0;
}
