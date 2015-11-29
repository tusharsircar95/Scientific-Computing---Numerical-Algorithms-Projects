
#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;


FILE *output = fopen("output2b.txt","w");

double getF(double x)
{
    return sqrt(1 - (x*x)) - x;
}


double simpsonsOneThirdValue(double *x,int n,double h)
{
    double ans = 0;
    ans = getF(x[0]) + getF(x[n]);
    for(int i=1; i<=n-1; i++)
    {
        if(i%2 == 0)
            ans += 2*getF(x[i]);
        else ans += 4*getF(x[i]);
    }
    return (ans*h)/3;
}



double printValuesAndErrors(double *x,int n,double h)
{
    double actual = 0.5*atan(1);
    double sonethird = simpsonsOneThirdValue(x,n,h);
    printf("%d\t\t\t%f\t%f\n",n,sonethird,abs(sonethird-actual));
    fprintf(output,"%d %f\n",n,abs(sonethird-actual));
    return abs(sonethird-actual);
}


double printIntervalsVsError(double left,double right,int n)
{
    double h = (right-left)/n;
    double *x = new double[n+1];
    x[0] = left;
    for(int i=1; i<=n; i++)
        x[i] = x[i-1] + h;
    return printValuesAndErrors(x,n,h);
}

int main()
{
    double left,right;
    cout<<"Enter end points: ";
    cin>>left>>right;

    int n;
    cout<<"Enter initial number of intervals: ";
    cin>>n;

    double *x = new double[(50*n)+1];
    double h = (right-left)/n;

    printf("NO. OF INTERVALS\tAPPROXIMATION\tERROR\n");
    int i = n;
    while(1)
    {
        double error = printIntervalsVsError(left,right,i);
        if(error < 0.5*pow(10,-5))
            break;
        i+=2;
    }
    fclose(output);

    return 0;
}

