/*	Counting Inversions in an Array...
*/
#include<iostream>
using namespace std;

int merge(int a[],int temp[],int start,int mid,int end){
	int inv=0;
	int i=start,j=mid,k=start;
	
	while(i<=(mid-1) && j<=end){
		if(a[i]<=a[j])		temp[k++] = a[i++];
		else{
			temp[k++] = a[j++];
			inv += (mid-i);
		}
	}
	while(i<=(mid-1))	temp[k++] = a[i++];
	while(j<=end)		temp[k++] = a[j++];
	
	for(int i=start;i<=end;i++)		a[i] = temp[i];
	return inv;
}

int mergeMod(int a[],int temp[],int start,int end){
	int inv=0,mid;
	if(start < end){
		mid = (start+end)/2;
		inv += mergeMod(a,temp,start,mid);
		inv += mergeMod(a,temp,mid+1,end);
		
		inv += merge(a,temp,start,mid+1,end);
	}
	return inv;
}

int countInv(int a[],int n){
	int *temp = new int[n];
	return mergeMod(a,temp,0,n-1);
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	int inv = countInv(a,n);
	cout<<"Inversions: "<<inv<<endl;
	for(int i=0;i<n;i++)	cout<<a[i]<<"  ";
	return 0;
}
