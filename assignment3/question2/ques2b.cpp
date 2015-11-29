#include<iostream>
#include<cmath>
using namespace std;

double getF(double x)
{
    return log((x*x)+1) - (exp(0.4*x)*cos(3.14*x));
}

int signum(double x)
{
    if( x < 0)
        return -1;
    if( x > 0)
        return 1;
    return 0;
}

int main()
{
    double low,high;
    int n;
    int val;
    double epsilon = 0.000001;
    bool rootFound = false;
    double prevValue;

    cout<<"Enter value of n: ";
    cin>>val;

    low = val-1;
    high = val;

    cout<<"Enter number of iterations: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        double mid = (low+high)/2;
        if(signum(getF(mid)) == 0 || (i !=0 && (abs(mid-prevValue)/abs(mid))< epsilon) )
        {
            cout<<"Root found at: "<<mid;
            cout<<"\nNumber of iterations: "<<i+1;
            rootFound = true;
            break;
        }
        if(signum(getF(low))*signum(getF(mid)) < 0)
            high = mid;
        else
            low = mid;
        prevValue = mid;
    }
    if(!rootFound)
        cout<<"Failed to converge!";



    return 0;
}

