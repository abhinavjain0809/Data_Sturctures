#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
    int n,swapped=1;
    cin>>n;
    int a[n];
    cout<<"Array elements will be assigned randomly"<<endl;
    for(int i=0;i<n;i++)    a[i]=rand();
    //for(int i=0;i<n;i++)    cin>>a[i];

    cout<<"Array:"<<endl;
    for(int i=0;i<n;i++)    cout<<a[i]<<"  ";
    cout<<endl<<endl;

    int k=0;
    for(int pass=n-1;pass>=0 && swapped;pass--){
        swapped=0;
        for(int i=0;i<pass;i++){
            if(a[i]>a[i+1]){
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swapped=1;
            }
        }
    }
    cout<<"Sorted Array:"<<endl;
    for(int i=0;i<n;i++)    cout<<a[i]<<"  ";
}
