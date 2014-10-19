#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
using namespace std;

int main(void)
{
    char str[50];
    int i=0,n,num,min=INT_MAX;
    gets(str);
    cin>>num;
    while(str[i]!='\0'){
        if(str[i]>=48 && str[i]<=57){
            n=0;
            while(str[i]>=48 && str[i]<=57){
                n = n*10 + (str[i]-48);
                i++;
            }
            if(n>num && min>n)   min = n;
        }
        i++;
    }
    cout<<min;
    return 0;
}
