#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cout<<"Number of Elements in array: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)        cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++)        a[i]*=a[i];
    int low,high,sum;
    for(int i=n-1;i>=0;i--){
        low=0;
        high=n-2;
        while(low<high){
            sum = a[low]+a[high];
            if(sum==a[i]){
                cout<<a[low]<<" + "<<a[high]<<" = "<<a[i]<<endl;
                break;
            }
            else if(sum<a[i])       low++;
            else                    high--;
        }
    }
    return 0;
}
