#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int cmp(const void *, const void *);
int main(void)
{
    int n,even=0,odd=0,k=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2==0)   even++;
        else            odd++;
    }
    if(odd>even){
        k=2*odd-1;
    }
    else{
        k=2*even-1;
    }

    int b[k];
    for(int i=0;i<k;i++){
        if(i%2==0)      b[i] = 0;
        else            b[i] = 1;
    }
    //for(int i=0;i<k;i++)    cout<<b[i];
    qsort(a, n, sizeof(int), cmp);
    //for(int i=0;i<n;i++)    cout<<a[i];
    int e=0,o=1;
    for(int i=0;i<n;i++){
        if(a[i]%2==0){
            while(b[e]!=0)      e+=2;
            b[e] = a[i];
        }
        else{
            while(b[o]!=1)      o+=2;
            b[o] = a[i];
        }
    }
    for(int i=0;i<k;i++)    cout<<b[i]<<"\t";

    int key,flag=0;
    cout<<"\n\nSearch Term: ";
    cin>>key;
    if(key%2==0){
        for(int i=0;i<k;i+=2){
            if(key==b[i]){
                flag=1;
                cout<<"Data Exists...";
                break;
            }
        }
    }
    else{
        for(int i=1;i<k;i+=2){
            if(key==b[i]){
                flag=1;
                cout<<"Data Exists...";
                break;
            }
        }
    }
    if(flag==0)     cout<<"Data NOT FOUND!!!";
    return 0;
}

int cmp(const void *x, const void *y)
{
    return (*(int*)x - *(int*)y);
}
