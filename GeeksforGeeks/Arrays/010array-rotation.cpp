#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	int k;
	cout<<"Rotate By: ";
	cin>>k;
	int temp[k];
	for(int i=0;i<k;i++)	temp[i]=a[i];
	int i=0;
	for(i=0;i<n-k;i++){
		a[i]=a[i+k];
	}
	for(int j=0;j<k;j++){
		a[i++]=temp[j];
	}
	for(int i=0;i<n;i++)	cout<<a[i]<<"  ";
	return 0;
}
