#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

double getF(double x)
{
    return sin(x)/x;
}

double convertValue(double x,double a,double b)
{
    return ((b-a)*x + (b+a))/2;
}

double threePointGaussian(double left,double right)
{
    double x1,x2,x3;
    double c1,c2,c3;

    c1 = 0.555555;
    c2 = 0.888888;
    c3 = 0.555555;

    x1 = convertValue(0.7745966692,left,right);
    x2 = convertValue(0,left,right);
    x3 = convertValue(-0.7745966692,left,right);

    return (c1*getF(x1) + c2*getF(x2) + c3*getF(x3));


}

void evaluateByDividing(double left,double right,int n)
{
    double h = (right-left)/n;
    double ans = 0;
    for(int i=0; i<n; i++)
        ans += (h/(double)2)*threePointGaussian(left + (i*h),left + ((i+1)*h));
    printf("Approximation: %f\n",ans);
}

int main()
{
    double left,right;
    cout<<"Enter end points: ";
    cin>>left>>right;

    int n;

    int i = 1;
    while((i++)<5)
    {
        cout<<"Enter number of intervals: ";
        cin>>n;
        evaluateByDividing(left,right,n);
    }


    return 0;
}
