#include<iostream>
using namespace std;

void findRepeating(int a[],int size){
	int xr=a[0];
	int n=size-2;
	for(int i=1;i<size;i++)	xr ^= a[i];
	for(int i=1;i<=n;i++)	xr ^= i;
	
	int setBit=xr&~(xr-1);
	int x=0,y=0;
	for(int i=0;i<size;i++){
		if(a[i] & setBit)		x ^= a[i];
		else 					y ^= a[i];
	}
	
	for(int i=1;i<=n;i++){
		if(i & setBit)			x ^= i;
		else 					y ^= i;
	}
	
	cout<<"Repeating Elements are: "<<x<<" and "<<y<<endl;
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	findRepeating(a,n);
	return 0;
}
