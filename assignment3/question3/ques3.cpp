#include<iostream>
#include<cmath>
using namespace std;

double getF(double x)
{
    return (1000000*exp(x)) + ((435000/x)*(exp(x)-1)) - 1564000;
}

int main()
{
    double prevVal;
    double currentVal;
    double firstInitial;
    double secondInitial;
    int n;
    double epsilon = 0.000001;
    bool rootFound = false;

    cout<<"Enter initial value: ";
    cin>>firstInitial;
    cout<<"Enter second initial value: ";
    cin>>secondInitial;
    prevVal = firstInitial;
    currentVal = secondInitial;

    cout<<"Enter number of iterations: ";
    cin>>n;
    cout<<"\n\nEVALUATING USING SECANTS METHOD:\n";

    for(int i=0; i<n; i++)
    {
        double temp = currentVal;
        currentVal = currentVal - ((getF(currentVal)*(currentVal-prevVal))/(getF(currentVal)-getF(prevVal)));
        prevVal = temp;
        if(abs(currentVal-prevVal)/abs(prevVal) < epsilon)
        {
            cout<<"Root found at: "<<currentVal;
            cout<<"\nNumber of iterations: "<<i+1;
            rootFound = true;
            break;
        }
        cout<<prevVal<<endl;
    }

    if(!rootFound)
        cout<<"Failed to converge!";


    return 0;
}

