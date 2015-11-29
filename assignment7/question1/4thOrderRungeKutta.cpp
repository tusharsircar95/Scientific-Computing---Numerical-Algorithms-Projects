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

void solveRungeKutta(double deltaT)
{
    double prev = To;
    double current;
    double y1,y2,y3,y4;
    cout<<"DeltaT = "<<deltaT<<endl;
    for(int i=1; i<=10; i++)
    {
        y1 = deltaT * getF(prev);
        y2 = deltaT * getF(prev + (0.5*y1));
        y3 = deltaT * getF(prev + (0.5*y2));
        y4 = deltaT * getF(prev + y3);
        current = prev + ((y1 + (2*y2) + (2*y3) + y4)/(double)6);
        printf("T at time %f: %f\n",0.0 + (deltaT*(double)i),current);
        prev = current;
    }
    cout<<endl;
}



int main()
{
    solveRungeKutta(2);


    return 0;
}

