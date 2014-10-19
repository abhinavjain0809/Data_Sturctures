#include<iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
int main()
{
    char name[20],b[10];
    cout<<"enter the name";
    gets(name);
    int i=0,j=0;
    /*while(name[i]!='\0')
    {
        if(name[i]==' ')
            cspace++;
    }*/
    b[0]=name[0];
    b[1]='.';
    j=2;
    i=1;
    while(name[i]!='\0')
    {
        if(name[i]==' ')
            {
           i++;
           b[j]=name[i];
           j++;
           b[j]=' ';
           j++;
        }
        i++;
    }
    //b[j]='\0';
    cout<<endl;
    puts(b);
    return 0;

}
