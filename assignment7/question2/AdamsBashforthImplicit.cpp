
#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

double Ta = 250;
double To = 2500;
double alpha = 2.0 * pow((double)10,(double)-12);
double epsilon = 0.000001;
bool rootFound;

double getF(double T,double p1,double p2,double p3,double t)
{
    double temp = (9.0*T) + (19.0*p3) - (5*p2) + p1;
    return T - p3 - ((t/(double)24)*temp);
}

double getFo(double T)
{
    return -alpha*(pow(T,4.0) - pow(Ta,4.0));
}

double solveBySecant(double T1,double T2,double T3,double t)
{
    int noOfIterations = 1000;
    double prevVal = 2000;
    double currentVal = 2500;
    for(int i=0; i<noOfIterations; i++)
    {
        double temp = currentVal;
        //cout<<getF(currentVal,t)<<" "<<getF(prevVal,t)<<endl;
        currentVal = currentVal - ((getF(currentVal,T1,T2,T3,t)*(currentVal-prevVal))/(getF(currentVal,T1,T2,T3,t)-getF(prevVal,T1,T2,T3,t)));
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

void solveAdamsBashforthImplicitely(double deltaT)
{
    double prev = To;
    double current;
    double vals[20];

    vals[0] = To;
    vals[1] = vals[0] + (deltaT*getFo(vals[0]));
    vals[2] = vals[1] + (deltaT*getFo(vals[1]));

    cout<<"DeltaT = "<<deltaT<<endl;

    printf("T at time %f: %f\n",0.0 + (deltaT*(double)1),vals[1]);
    printf("T at time %f: %f\n",0.0 + (deltaT*(double)2),vals[2]);


    for(int i=3; i<=10; i++)
    {
        double predicted = vals[i-1] + (deltaT*getFo(vals[i-1]));
        double v = (9.0*getFo(predicted)) + (19.0*getFo(vals[i-1])) - (5.0*getFo(vals[i-2])) + getFo(vals[i-3]);
        v = v/(double)24.0;
        vals[i] = vals[i-1] + v;
        printf("T at time %f: %f\n",0.0 + (deltaT*(double)i),vals[i]);
        prev = current;
    }
    cout<<endl;
}



int main()
{
    solveAdamsBashforthImplicitely(2);


    return 0;
}

