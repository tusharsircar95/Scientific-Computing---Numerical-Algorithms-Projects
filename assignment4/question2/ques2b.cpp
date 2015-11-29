#include<iostream>
#include<cmath>
using namespace std;

double getG(double x,double y)
{
    return sin(x+y) - exp(x-y);
}
double getGx(double x,double y)
{
    return cos(x+y) - exp(x-y);
}
double getGy(double x,double y)
{
    return cos(x+y) + exp(x-y);
}
double getH(double x,double y)
{
    return cos(x+6) - (x*x*y*y);
}
double getHx(double x,double y)
{
    return -sin(x+6) - (2*x*y*y);
}
double getHy(double x,double y)
{
    return (-2*x*x*y);
}

int main()
{
    double prevValX,prevValY;
    double currentValX,currentValY;
    double initialX,initialY;
    int n;
    double epsilon = 0.0000001;
    bool rootFound = false;

    cout<<"Enter initial value for x: ";
    cin>>initialX;
    cout<<"Enter initial value for y: ";
    cin>>initialY;
    prevValX = initialX;
    prevValY = initialY;

    cout<<"Enter number of iterations: ";
    cin>>n;

    cout<<"EVALUATING USING NEWTONS METHOD:\n";

    for(int i=0; i<n; i++)
    {
        double x = prevValX;
        double y = prevValY;
        currentValX = x - ((getG(x,y)*getHy(x,y) - getH(x,y)*getGy(x,y))/(getGx(x,y)*getHy(x,y) - getGy(x,y)*getHx(x,y)));
        currentValY = y - ((getH(x,y)*getGx(x,y) - getG(x,y)*getHx(x,y))/(getGx(x,y)*getHy(x,y) - getGy(x,y)*getHx(x,y)));
        if(abs(currentValX - prevValX) < epsilon && abs(currentValX - prevValX) < epsilon)
        {
            cout<<"Root found at: ("<<currentValX<<" "<<currentValY<<")";
            cout<<"\nNumber of iterations: "<<i+1;
            rootFound = true;
            cout<<endl<<"Value of functions: "<<getG(currentValX,currentValY)<<" "<<getH(currentValX,currentValY);
            break;
        }
        prevValX = currentValX;
        prevValY = currentValY;
       // cout<<prevVal<<endl;
    }

    if(!rootFound)
        cout<<"Failed to converge!";




    return 0;
}
