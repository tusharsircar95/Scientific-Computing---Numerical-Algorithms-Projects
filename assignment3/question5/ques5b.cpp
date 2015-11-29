#include<iostream>
#include<cmath>
using namespace std;

double getF(double x)
{
    return (x+1)*(x+1)*(x+1)*(x-1);
}

double getFDASH(double x)
{
    return 2*(x+1)*(x+1)*(x-1);
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
        if(abs(currentVal-prevVal) < epsilon)
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

