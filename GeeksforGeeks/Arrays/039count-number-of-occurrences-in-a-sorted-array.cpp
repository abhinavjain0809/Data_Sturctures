#include<iostream>
#include<algorithm>
using namespace std;
/*
int firstPos(int a[],int low,int high,int key){
	if(low <= high){
		int mid = (low+high)/2;
		
		if((mid==0 || a[mid] > a[mid-1]) && a[mid]==key)		return mid;
		else if(a[mid] < key)		return firstPos(a,mid+1,high,key);
		else 						return firstPos(a,low,mid-1,key);
	}
	return -1;
}

int lastPos(int a[],int n,int low,int high,int key){
	if(low <= high){
		int mid = (low+high)/2;
		
		if((mid==n-1 || a[mid] < a[mid+1]) && a[mid]==key)		return mid;
		else if(a[mid] > key)		return lastPos(a,n,low,mid-1,key);
		else 						return lastPos(a,n,mid+1,high,key);
	}
	return -10;
}
*/

int firstPos(int *a,int low,int high,int key){
	if(low <= high){
		int mid = (low+high)/2;
		if((mid==0 || a[mid]>a[mid-1]) && a[mid]==key)		return mid;
		else if(key <= a[mid])	return firstPos(a,low,mid-1,key);
		else					return firstPos(a,mid+1,high,key);
	}
	return -1;
}

int lastPos(int *a,int n,int low,int high,int key){
	if(low <= high){
		int mid=(low+high)/2;
		if((mid==n-1 || a[mid]<a[mid+1]) && a[mid]==key)	return mid;
		else if(key >= a[mid])	return lastPos(a,n,mid+1,high,key);
		else					return lastPos(a,n,low,mid-1,key);
	}
	return -10;
}

int count(int a[],int n,int key){
	if(key < a[0])	return 0;
	
	int start = firstPos(a,0,n-1,key);
	int last = lastPos(a,n,start,n-1,key);
	return (last-start+1);
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	sort(a,a+n);
	int key;
	cout<<"Key to count: ";
	cin>>key;
	int num = count(a,n,key);
	if(num >= 0)	cout<<"Input Key occurs "<<num<<" times"<<endl;
	else 			cout<<"Given Key DOES NOT exist!!!"<<endl;
	return 0;
}
