#include<iostream>
using namespace std;

void equilibriumIndex(int a[],int n){
	int leftSum=0,sum=0;
	for(int i=0;i<n;i++)	sum += a[i];
	
	cout<<"Equilibrium Indices are: ";
	for(int i=0;i<n;i++){
		sum -= a[i];
		if(sum == leftSum)		cout<<i<<"  ";
		leftSum += a[i];
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	equilibriumIndex(a,n);
	return 0;
}
