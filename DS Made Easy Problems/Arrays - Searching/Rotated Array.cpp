//  Sorted Array Rotated unknown number of times. Search a particular element...
#include<iostream>
#include<cstdlib>
using namespace std;

int findPivot(int a[],int beg,int last){
    if(beg==last)               return beg;
    else if(beg==last-1){
        if(a[beg]>=a[last])     return beg;
        else                    return last;
    }
    else{
        int mid = (beg+last)/2;
        if(a[mid]<=a[beg])      findPivot(a,beg,mid);
        else                    findPivot(a,mid,last);
    }
}

void binarySearch(int a[],int beg,int last,int key){
    if(beg<=last){
        int mid = (beg+last)/2;
        if(a[mid]==key){
            cout<<endl<<key<<" found at position "<<mid<<endl;
            exit(0);
        }
        else if(a[mid]>key)     binarySearch(a,beg,mid-1,key);
        else                    binarySearch(a,mid+1,last,key);
    }
    cout<<key<<" not found"<<endl;
    exit(-1);
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)    cin>>a[i];
    int pivot = findPivot(a,0,n-1);
    cout<<"pivot: "<<pivot<<endl;
    int key;
    cout<<"Enter Search Term: ";
    cin>>key;
    if(a[pivot]==key){
        cout<<endl<<key<<" found at position "<<pivot<<endl;
        return 0;
    }
    else if(a[pivot]<key)       binarySearch(a,pivot+1,n-1,key);
    else                        binarySearch(a,0,pivot-1,key);
    return 0;
}
