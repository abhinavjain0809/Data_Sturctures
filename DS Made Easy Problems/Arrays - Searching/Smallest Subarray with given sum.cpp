#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int a[n];
    cout<<"Array Elements:"<<endl;
    for(int i=0;i<n;i++)    cin>>a[i];
    sort(a,a+n);

    int x;
    cout<<"Required Sum: ";
    cin>>x;
    cout<<endl;
    int sum=0,count=0,flag=0;
    for(int i=n-1;i>=0;i++){
        count++;
        sum += a[i];
        if(sum>x){
            cout<<"Total elements in the SubArray: "<<count<<endl;
            flag=1;
            break;
        }
    }
    if(flag){
        int i=1,j=n-1;
        cout<<"Smallest SubArray: "<<endl;
        while(i<=count){
            cout<<a[j--]<<"\t";
            i++;
        }
    }
    else{
        cout<<"SubArray doesn't exists!!!"<<endl;
    }
    return 0;
}
