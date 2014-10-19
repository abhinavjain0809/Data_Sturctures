/*	Rotate By 'K' Positions...
*/
#include<iostream>
using namespace std;

void reverse(int a[],int start,int end){
	int temp;
	while(start<end){
		temp = a[start];
		a[start] = a[end];
		a[end] = temp;
		start++;
		end--;
	}
}

void rotate(int a[],int n,int k){
	reverse(a,0,k-1);
	reverse(a,k,n-1);
	reverse(a,0,n-1);
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	int k;
	cout<<"Rotate By: ";
	cin>>k;
	rotate(a,n,k);
	for(int i=0;i<n;i++)	cout<<a[i]<<"  ";
	return 0;
}
