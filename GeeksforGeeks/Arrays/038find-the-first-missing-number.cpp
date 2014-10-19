#include<iostream>
#include<algorithm>
using namespace std;

int firstMissingEntry(int a[],int low,int high){
	if(low <= high){
		if(a[low] != low)	return low;
		
		int mid = (low+high)/2;
		if(a[mid] > mid)	return firstMissingEntry(a,low,mid);
		else	 			return firstMissingEntry(a,mid+1,high);
	}
	return -1;
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	sort(a,a+n);
	int missing = firstMissingEntry(a,0,n-1);
	if(missing==-1)		cout<<"No element missing!!"<<endl;
	else 				cout<<"Missing ELement: "<<missing<<endl;
	return 0;
}
