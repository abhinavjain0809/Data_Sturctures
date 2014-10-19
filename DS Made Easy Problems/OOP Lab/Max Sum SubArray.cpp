#include<iostream>
using namespace std;

int main(void)
{
    int n,count=0;
    static int k=0;
    cout<<"Enter no of elements: ";
    cin>>n;
    int a[n];
    cout<<"Elements:\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>0)      count++;
    }
    int b[count];
    for(int i=0;i<n;i++){
        if(a[i]>0)      b[k++] = a[i];
    }

    cout<<"Max Sum SubArray:\n";
    for(int i=0;i<count;i++){
        cout<<b[i]<<"\t";
    }
    return 0;
}
