#include<iostream>
#include<cmath>
using namespace std;


double getF(double x)
{
    return pow(3,(3*x)+1) - pow(7.5,2*x);
}

double getFDASH(double x)
{
    return (log(3)*pow(3,(3*x)+2)) - (2*log(7.5)*pow(7.5,2*x));
}

int main()
{
    double prevVal;
    double currentVal;
    double firstInitial;
    double secondInitial;
    int n;
    double epsilon = 0.0000000000000001;
    bool rootFound = false;

    cout<<"Enter initial value: ";
    cin>>firstInitial;
    prevVal = firstInitial;

    cout<<"Enter number of iterations: ";
    cin>>n;

    cout<<"EVALUATING USING NEWTONS METHOD:\n";
    for(int i=0; i<n; i++)
    {
     //   double temp = currentVal;
        currentVal = prevVal - (getF(prevVal)/getFDASH(prevVal));
        if(abs(currentVal - prevVal) < epsilon)
        {
            cout<<"Root found at: "<<currentVal;
            cout<<"\nNumber of iterations: "<<i+1;
            rootFound = true;
            break;
        }
        prevVal = currentVal;
        //cout<<prevVal<<endl;
    }

    if(!rootFound)
        cout<<"Failed to converge!";

    return 0;
}
