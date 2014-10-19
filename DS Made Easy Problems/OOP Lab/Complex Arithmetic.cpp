#include<iostream>
#include<cmath>
#include<ctype.h>
using namespace std;
typedef struct complx
{
    float re;
    float img;
}C;
void arithmetic(C,C);
int main(void)
{
    C a,b;
    char ans = 'Y';
    while(toupper(ans)=='Y'){
        cout<<"1st Complex Number (a + ib): ";
        cin>>a.re>>a.img;

        cout<<"2nd Complex Number (a + ib): ";
        cin>>b.re>>b.img;

        arithmetic(a,b);

        cout<<"\n\nWish to enter more complex numbers(Y/N): ";
        cin>>ans;
    }
    return 0;
}

void arithmetic(C a,C b)
{
    float real, imag;
    cout<<"\nAddition:\n";
    real = a.re + b.re;
    imag = a.img + b.img;
    if(imag>=0)     cout<<"Result: "<<real<<" + i("<<imag<<")";
    else            cout<<"Result: "<<real<<" - i("<<abs(imag)<<")";

    cout<<"\nSubtraction:\n";
    real = a.re - b.re;
    imag = a.img - b.img;
    if(imag>=0)     cout<<"Result: "<<real<<" + i("<<imag<<")";
    else            cout<<"Result: "<<real<<" - i("<<abs(imag)<<")";

    cout<<"\nMultiplication:\n";
    real = a.re*b.re - a.img*b.img;
    imag = a.re*b.img + a.img*b.re;
    if(imag>=0)     cout<<"Result: "<<real<<" + i("<<imag<<")";
    else            cout<<"Result: "<<real<<" - i("<<abs(imag)<<")";

    cout<<"\nDivision:\n";
    real = (a.re*b.re + a.img*b.img)/(pow(b.re,2) + pow(b.img,2));
    imag = (a.re*b.img - a.img*b.re)/(pow(b.re,2) + pow(b.img,2));
    if(imag>=0)     cout<<"Result: "<<real<<" + i("<<imag<<")";
    else            cout<<"Result: "<<real<<" - i("<<abs(imag)<<")";
}
