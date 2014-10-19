#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
using namespace std;

main()
{
    int n, i, j;
    char str[100], temp[100], ch[3];
    str[0] = '\0';
    cout<<"Enter number of rows: ";
    cin>>n;
    for(i=1,j=1;i<=n;i++,j++)
    {
        if(i>9)   j = i%10;
        ch[0] = char(j+48);
        ch[1] = '\0';
        cout<<setw(40);
        if(i==1)
        {
            strcat(str,ch);
            cout<<str<<endl;
        }
        else
        {
            strcat(str,ch);
            cout<<str;
            strcpy(temp,str);
            temp[i-1] = '\0';
            strrev(temp);
            puts(temp);
        }
    }
    return 0;
}
