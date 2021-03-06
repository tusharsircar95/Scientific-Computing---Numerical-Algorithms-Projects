#include<iostream>
#include<cmath>
using namespace std;

double getF(double x)
{
    return (x*x*x*x) - (3*x*x) - 21;
}

double getFDASH(double x)
{
    return (4*x*x*x) - (6*x);
}

int main()
{
    double prevVal;
    double currentVal;
    double firstInitial;
    double secondInitial;
    int n;
    double epsilon = 0.0001;
    bool rootFound = false;

    cout<<"Enter initial value: ";
    cin>>firstInitial;
    prevVal = firstInitial;

    cout<<"Enter number of iterations: ";
    cin>>n;

    cout<<"EVALUATING USING NEWTONS METHOD:\n";
    for(int i=0; i<n; i++)
    {
        currentVal = prevVal - (getF(prevVal)/getFDASH(prevVal));
        if(abs(currentVal - prevVal) < epsilon)
        {
            cout<<"Root found at: "<<currentVal;
            cout<<"\nNumber of iterations: "<<i+1;
            rootFound = true;
            break;
        }
        prevVal = currentVal;
      //  cout<<prevVal<<endl;
    }

    if(!rootFound)
        cout<<"Failed to converge!";




    return 0;
}
