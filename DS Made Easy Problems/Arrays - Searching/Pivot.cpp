//  Sequence first increases, then decreases. Pivot: The maxima point in the sequence...
#include<iostream>
#include<cstdlib>
using namespace std;

int findPivot(int a[],int n){
    int beg=0,last=n-1;
    if(beg==last)               return beg;
    else if(beg==last-1){
        if(a[beg]>=a[last])     return beg;
        else                    return last;
    }
    else{
        while(beg<=last){
            int mid = (beg+last)/2;
            if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
                return mid;
            else if(a[mid]>a[mid-1] && a[mid]<a[mid+1])
                beg=mid+1;
            else if(a[mid]<a[mid-1] && a[mid]>a[mid+1])
                last=mid-1;
            else{
                cout<<"INVALID ARRAY CONTENT FORMAT!!"<<endl;
                exit(1);
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)    cin>>a[i];
    int k = findPivot(a,n);
    cout<<"Pivot Index: "<<k<<endl<<"Pivot: "<<a[k]<<endl;
    return 0;
}
