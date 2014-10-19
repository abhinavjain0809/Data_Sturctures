#include<iostream>
using namespace std;
int main()
{
    int a[10];

    cout<<"Enter 10 Values: "<<endl;
    for(int i=0;i<10;i++){
        cin>>a[i];
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                if(a[i]*a[i]==a[j]*a[j]+a[k]*a[k]){
                    cout<<"\n sides="<<a[i]<<" "<<a[j]<<" "<<a[k];
                }
            }
        }
    }
    return 0;
}
