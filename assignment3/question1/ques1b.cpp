#include<iostream>
#include<cmath>
using namespace std;

double getF(double x)
{
    return (x*x*x) + (4.001*x*x) + (4.002*x) + 1.101;
}

double getFDASH(double x)
{
    return (3*x*x) + (8.002*x) + (4.002);
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
            cout<<"\nValue at this root: "<<getF(currentVal);
            rootFound = true;
            break;
        }
        prevVal = currentVal;
        //cout<<prevVal<<endl;
    }

    if(!rootFound)
        cout<<"Failed to converge!";

    cout<<"\n\nEVALUATING USING SECANTS METHOD:\n";
    rootFound = false;
    cout<<"Enter second initial value: ";
    cin>>secondInitial;
    prevVal = firstInitial;
    currentVal = secondInitial;
    for(int i=0; i<n; i++)
    {
        double temp = currentVal;
        currentVal = currentVal - ((getF(currentVal)*(currentVal-prevVal))/(getF(currentVal)-getF(prevVal)));
        prevVal = temp;
        if(abs(currentVal-prevVal) < epsilon)
        {
            cout<<"Root found at: "<<currentVal;
            cout<<"\nValue at this root: "<<getF(currentVal);
            cout<<"\nNumber of iterations: "<<i+1;
            rootFound = true;
            break;
        }
        //cout<<prevVal<<endl;
    }

    if(!rootFound)
        cout<<"Failed to converge!";


    return 0;
}

