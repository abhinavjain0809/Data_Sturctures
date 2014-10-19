#include<iostream>
using namespace std;

int fact(int);

int main(void)
{
    int n, r, res;
    cout<<"Enter values of n and r: ";
    cin>>n>>r;
    res = fact(n)/(fact(r)*fact(n-r));
    cout<<endl<<res;
    return 0;
}

int fact(int n)
{
    if(n==1)    return 1;
    else
        return(n*fact(n-1));
}
