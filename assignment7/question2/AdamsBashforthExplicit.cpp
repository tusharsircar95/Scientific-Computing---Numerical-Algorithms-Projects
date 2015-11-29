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

void solveAdamsBashforthExplicit(double deltaT)
{
    cout<<"DeltaT = "<<deltaT<<endl;

    double vals[20];
    vals[0] = To;
    vals[1] = vals[0] + (deltaT*getF(vals[0]));
    vals[2] = vals[1] + (deltaT*getF(vals[1]));
    vals[3] = vals[2] + (deltaT*getF(vals[2]));

    printf("T at time %f: %f\n",0.0 + (deltaT*(double)1),vals[1]);
    printf("T at time %f: %f\n",0.0 + (deltaT*(double)2),vals[2]);
    printf("T at time %f: %f\n",0.0 + (deltaT*(double)3),vals[3]);


    for(int i=4; i<=13; i++)
    {
        double temp = (55.0*getF(vals[i-1]) - (59.0*getF(vals[i-2]) + (37.0*getF(vals[i-3]) - (9.0*getF(vals[i-4])))));
        vals[i] = vals[i-1] - (temp/(double)24);
        printf("T at time %f: %f\n",0.0 + (deltaT*(double)i),vals[i]);
    }
    cout<<endl;
}



int main()
{
    solveAdamsBashforthExplicit(2);


    return 0;
}
