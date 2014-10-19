#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int main(void)
{
    char s1[50],s2[50],s3[50];
    char *p;
    static int k=0;
    int l1=0,flag=0;
    cout<<"String 1: ";
    gets(s1);
    cout<<"String 2: ";
    gets(s2);
    p=s2;
    l1 = strlen(s1);
    while(*p!='\0'){
        flag=0;
        for(int i=0;i<l1;i++){
            if(s1[i]==*p){
                flag=1;
                break;
            }
        }
        if(flag==0){
            s3[k++] = *p;
        }
        p++;
    }
    //s3[k] = '\0';
    for(int i=0;i<k;i++)
        cout<<s3[i];

    return 0;
}
