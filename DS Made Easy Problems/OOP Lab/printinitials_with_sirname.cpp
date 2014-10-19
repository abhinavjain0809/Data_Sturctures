#include<iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>

using namespace std;
int main()
{
    char name[20],b[10];
    cout<<"Name: ";
    gets(name);
    int i=0,j=0,cspace=0,l=0;
    while(name[i]!='\0'){
        if(name[i]==' ')
            cspace++;
        i++;
    }
    b[0]=name[0];
    b[1]='.';
    b[2]=' ';
    j=3;
    i=1;
    l=0;
    while(name[i]!='\0')
    {
        if(name[i]==' ' && l<(cspace-1))
        {
           i++;
           b[j]=name[i];
           j++;
           b[j]='.';
           j++;
           l++;
        }
        else if(name[i]==' ' && l==(cspace-1))
        {
            int k=(i+1);
            while(name[k]!='\0')
            {
                b[j]=name[k];
                j++;
                k++;
            }
            break;
        }
    i++;
    }
    b[j]='\0';
    cout<<endl;
    puts(b);
    return 0;
}
