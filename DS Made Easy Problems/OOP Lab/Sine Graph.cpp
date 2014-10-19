#include<iostream>
#include<iomanip>
#include<cmath>
#define PI 3.1456
using namespace std;
int main(void)
{
    int min, max;
    int i, j, k;
    cout<<"Enter min and max values for the curve to be plotted: ";
    cin>>min>>max;
    for(i=min;i<=max;i+=10)
    {
        j = 20*sin(i*PI/180);
        if(j>0)
        {
            cout<<setw(39);
            for(k=0;k<=j;k++)   cout<<"*";
            cout<<endl;
        }
        else
        {
            j *= -1;
            cout<<setw(39-j);
            for(k=39-j;k<=39;k++)   cout<<"*";
            cout<<endl;
        }
    }
    return 0;
}
