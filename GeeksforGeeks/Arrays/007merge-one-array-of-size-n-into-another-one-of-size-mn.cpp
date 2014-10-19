#include<iostream>
#include<algorithm>
using namespace std;

void rearrangeA(int a[],int size){
	int j=size-1;
	for(int i=size-1;i>=0;i--){
		if(a[i]!=-1){
			a[j--]=a[i];
		}
	}
}

void merge(int a[],int *b,int m,int n){
	int i=n,j=0,k=0;
	while(i<m+n && j<n){
		if(a[i]<=b[j]){
			a[k++] = a[i++];
		}
		else{
			a[k++] = b[j++];
		}
	}
	while(i<m+n)	a[k++] = a[i++];
	while(j<n)		a[k++] = b[j++];
}

int main(){
	int m,n;
	cin>>m>>n;
	int a[m+n],b[n];
	for(int i=0;i<m+n;i++)	cin>>a[i];
	for(int i=0;i<n;i++)	cin>>b[i];
	cout<<"Array a[]: ";
	for(int i=0;i<m+n;i++)	cout<<a[i]<<"  ";
	cout<<endl;
	cout<<"Array b[]: ";
	for(int i=0;i<n;i++)	cout<<b[i]<<"  ";
	cout<<endl;
	rearrangeA(a,m+n);
	merge(a,b,m,n);
	for(int i=0;i<m+n;i++)	cout<<a[i]<<"  ";
	cout<<endl;
	return 0;
}
