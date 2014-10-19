#include<iostream>
using namespace std;

int findPivot(int a[],int start,int end){
	if(start > end)		return -1;
	if(start==end)		return start;
	
	int mid = (start+end)/2;
	
	if(a[mid] > a[mid+1] && mid<end)			return mid;
	else if(a[mid] < a[mid-1] && mid>start)		return (mid-1);
	
	if(a[start] < a[mid])	return findPivot(a,mid+1,end);
	else 					return findPivot(a,start,mid-1);
}

int binarySearch(int a[],int low,int high,int key){
	if(low <= high){
		int mid = (low+high)/2;
		if(a[mid]==key)			return mid;
		else if(a[mid] < key)	return binarySearch(a,mid+1,high,key);
		else					return binarySearch(a,low,mid-1,key);
	}
	return -1;
}

int findKey(int a[],int n,int key){
	int pivot = findPivot(a,0,n-1);
	if(pivot==-1)		return binarySearch(a,0,n-1,key);		// Array is not rotated at all...
	if(a[pivot]==key)	return pivot;
	
	if(key < a[0])	return binarySearch(a,pivot+1,n-1,key);
	else 			return binarySearch(a,0,pivot-1,key);
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	
	int key;
	cout<<"Enter key to Search: ";
	cin>>key;
	int index = findKey(a,n,key);
	if(index == -1)		cout<<"Key NOT FOUND!!!"<<endl;
	else 				cout<<"Found Key "<<a[index]<<" at index "<<index<<endl;
	return 0;
}
