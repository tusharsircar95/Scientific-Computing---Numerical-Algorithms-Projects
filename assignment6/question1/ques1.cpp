#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

double getF(double x)
{
    return 1/(1 + (x*x));
}

double trapizoidalValue(double *x,int n,double h)
{
    double ans = 0;
    for(int i=1; i<n; i++)
        ans += getF(x[i]);
    ans = ans*2;
    ans += getF(x[0]) + getF(x[n]);
    return (h*ans)/2;
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

double simpsonsThreeEighthValue(double *x,int n,double h)
{
    double ans = 0;
    ans = getF(x[0]) + getF(x[n]);
    for(int i=1; i<n; i++)
    {
        if(i%3 == 0)
            ans += 2*getF(x[i]);
        else ans += 3*getF(x[i]);
    }
    return (3*h*ans)/8;
}

void printValuesAndErrors(double *x,int n,double h)
{
    cout<<endl;
    double actual = 3.141/4;
    printf("Actual value of intergal: %f\nApproximation using %d intervals...\n",actual,n);
    double trapizoidal = trapizoidalValue(x,n,h);
    double sonethird = simpsonsOneThirdValue(x,n,h);
    double sthreeeighth = simpsonsThreeEighthValue(x,n,h);
    printf("Trapizoidal                : %f .... Error: %f\n",trapizoidal,abs(actual-trapizoidal));
    printf("Simpsons One Third         : %f .... Error: %f\n",sonethird,abs(actual-sonethird));
    printf("Simpsons Three Eighth Value: %f .... Error: %f\n",sthreeeighth,abs(actual-sthreeeighth));
}

int main()
{
    double left,right;
    cout<<"Enter end points: ";
    cin>>left>>right;

    int n;
    cout<<"Enter number of intervals: ";
    cin>>n;

    double *x = new double[(20*n)+1];
    double h = (right-left)/n;

    x[0] = left;
    for(int i=1; i<=n; i++)
        x[i] = x[i-1] + h;
    printValuesAndErrors(x,n,h);


    x[0] = left;
    h = h/(double)10;
    for(int i=1; i<=10*n; i++)
        x[i] = x[i-1] + h;
    printValuesAndErrors(x,10*n,h);

    x[0] = left;
    h = h/(double)2;
    for(int i=1; i<=20*n; i++)
        x[i] = x[i-1] + h;
    printValuesAndErrors(x,20*n,h);





    return 0;
}
