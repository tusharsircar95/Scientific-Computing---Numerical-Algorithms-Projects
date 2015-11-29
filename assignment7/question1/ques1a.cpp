#include<iostream>
#include<cmath>
using namespace std;

double Ta = 250;
double To = 2500;
double alpha = 2.0 * pow((double)10,(double)-12);


double getF(double T,double t)
{
    return atan(T/Ta) - atan(To/Ta) + 0.5*log(((To-Ta)*(T+Ta))/((T-Ta)*(To+Ta))) - (2*alpha*Ta*Ta*Ta*t);
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

    for(int t = 1; t <= 10; t++)
    {

        cout<<"For time "<<t<<" : "<<endl;

        for(int i=0; i<n; i++)
        {
            double temp = currentVal;
            //cout<<getF(currentVal,t)<<" "<<getF(prevVal,t)<<endl;
            currentVal = currentVal - ((getF(currentVal,t)*(currentVal-prevVal))/(getF(currentVal,t)-getF(prevVal,t)));
            prevVal = temp;
            if(abs(currentVal-prevVal)/abs(prevVal) < epsilon)
            {
                cout<<"T: "<<currentVal;
                cout<<"\tLHS - RHS = "<<getF(currentVal,t);
                cout<<"\tIterations: "<<i+1;
                rootFound = true;
                break;
            }
            //cout<<prevVal<<endl;
        }

        if(!rootFound)
            cout<<"Failed to converge!";
        cout<<endl;
    }


    return 0;
}

