#include<iostream>
#include<string.h>
#include<ctype.h>
#include<cstdio>
using namespace std;
int main(void)
{
    char str[50];
    int i=0,k=0,n;
    gets(str);
    while(str[i]!='\0'){
        if(str[i]>=48 && str[i]<=57){
            n=0;
            while(str[i]>=48 && str[i]<=57){
                n = n*10 + (str[i]-48);
                i++;
            }
            cout<<n<<" ";
        }
        i++;
    }

    return 0;
}
