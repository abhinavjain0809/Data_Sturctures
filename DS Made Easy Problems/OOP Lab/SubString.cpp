#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string.h>

using namespace std;
int main(void)
{
    char s1[50],s2[50];
    int l1,l2,i=0,found=0,pos,j=0,k;
    gets(s1);
    gets(s2);
    l1=strlen(s1);
    l2=strlen(s2);
    while(s1[i]!='\0'){
        if(s1[i]==s2[0]){
            pos=i;
            k=pos+1;
            j=1;
            while(s2[j]!='\0'){
                if(s1[k]==s2[j]){
                    k++;
                    j++;
                }
                else    break;
            }
            if(j==l2){
                found=1;
                break;
            }
        }
        i++;
    }
    if(found)   cout<<"SubString Exists at index: "<<pos+1;
    else        cout<<"SubString NOT FOUND!!!";
    return 0;
}
