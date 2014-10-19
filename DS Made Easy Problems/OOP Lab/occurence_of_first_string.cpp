#include<iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
int main()
{
    char a[20], b[20];
    cout<<"\n enter the first string";
    gets(a);
    cout<<"\n enter the string to be searched for";
    gets(b);
    int i=0,s=0,s1=0,pos=0,f=0;
    s=strlen(b);
    while(a[i]!='\0')
    {
        if(a[i]==b[0])
        {   s1=1;
            pos=i;
            int j=(i+1),k=1;

            while(b[k]!='\0')
            {
                if(a[j]==b[k])
                {
                   j++;
                   k++;
                   s1++;
                }
                else
                    break;

            }
             if(s1==s)
        {
            f=1;
            break;
        }
        }

        i++;
    }
    if(f==1)
    {
        cout<<endl<<"found at posn"<<(pos+1);

    }
    else cout<<"\n not found";
    return 0;
}
