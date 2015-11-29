#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

double Ta = 250;
double To = 2500;
double alpha = 2.0 * pow((double)10,(double)-12);
double epsilon = 0.000001;
bool rootFound;

double getF(double T,double p,double t)
{
    return (alpha*t*pow(T,4.0)) + T - p - (alpha*t*pow(Ta,4.0));
}

double solveBySecant(double T,double t)
{
    int noOfIterations = 1000;
    double prevVal = 2000;
    double currentVal = 2500;
    for(int i=0; i<noOfIterations; i++)
    {
        double temp = currentVal;
        //cout<<getF(currentVal,t)<<" "<<getF(prevVal,t)<<endl;
        currentVal = currentVal - ((getF(currentVal,T,t)*(currentVal-prevVal))/(getF(currentVal,T,t)-getF(prevVal,T,t)));
        prevVal = temp;
        if(abs(currentVal-prevVal)/abs(prevVal) < epsilon)
        {
           // cout<<"T: "<<currentVal;
           // cout<<"\tLHS - RHS = "<<getF(currentVal,T,t);
           // cout<<"\tIterations: "<<i+1;
            rootFound = true;
            return currentVal;
            break;
        }
        //cout<<prevVal<<endl;
    }
    return -1;
}

void solveEulersImplicitely(double deltaT)
{
    double prev = To;
    double current;
    cout<<"DeltaT = "<<deltaT<<endl;
    for(int i=1; i<=10; i++)
    {
        current = solveBySecant(prev,deltaT);
        printf("T at time %f: %f\n",0.0 + (deltaT*(double)i),current);
        prev = current;
    }
    cout<<endl;
}



int main()
{
    solveEulersImplicitely(2);


    return 0;
}

