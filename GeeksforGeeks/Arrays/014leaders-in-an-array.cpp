/*	Leaders in an Array...
*/
#include<iostream>
using namespace std;

void leaders(int a[],int n){
	int max=a[n-1];
	cout<<"Leaders: "<<max<<"  ";
	for(int i=n-2;i>=0;i--){
		if(a[i]>max){
			cout<<a[i]<<"  ";
			max = a[i];
		}
	}
	cout<<endl;
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	leaders(a,n);
	return 0;
}
