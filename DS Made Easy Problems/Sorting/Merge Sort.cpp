#include<iostream>
#include<cstdlib>
using namespace std;

void merge(int a[],int i,int j,int mid){
    //cout<<"Inside Merge"<<i<<"  "<<j<<endl;
    int start=i,l=i,k=mid+1;
    int b[100000];
    while(i<=mid && k<=j){
        if(a[i]>=a[k])      b[l++] = a[k++];
        else                b[l++] = a[i++];
    }
    if(i>mid){
        while(k<=j)      b[l++] = a[k++];
    }
    else{
        while(i<=mid)    b[l++]  = a[i++];
    }

    for(int i=start;i<=j;i++)   a[i] = b[i];
}

void mergeSort(int a[],int i,int j){

    if(i>=j){
        //cout<<"Leaving mergeSort "<<i<<"  "<<j<<endl;
        return;
    }
    //cout<<"Entered mergeSort "<<i<<"  "<<j<<endl;
    int mid=(i+j)/2;
    mergeSort(a,i,mid);
    //cout<<"Entered 2nd mergeSort"<<i<<"  "<<j<<endl;
    mergeSort(a,mid+1,j);
    //cout<<"Merging Step"<<i<<"  "<<j<<endl;
    merge(a,i,j,mid);
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)    a[i]=rand();

    cout<<"Array:"<<endl;
    for(int i=0;i<n;i++)    cout<<a[i]<<"  ";
    cout<<endl;

    mergeSort(a,0,n-1);
    cout<<"Sorted Array:"<<endl;
    for(int i=0;i<n;i++)    cout<<a[i]<<"  ";
    cout<<endl;
    return 0;
}
