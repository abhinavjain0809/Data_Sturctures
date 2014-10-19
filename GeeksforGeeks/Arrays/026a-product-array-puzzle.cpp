/*	Product Array Puzzle...
 */
#include<iostream>
#include<cstring>
using namespace std;

int *productArray(int a[],int n){
	int temp=1;
	int *product = new int[n];
	for(int i=0;i<n;i++){
		product[i] = temp;
		temp *= a[i];
	}
	temp=1;
	for(int i=n-1;i>=0;i--){
		product[i] *= temp;
		temp *= a[i];
	}
	return product;
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	int *product = productArray(a,n);
	cout<<"Product Array: ";
	for(int i=0;i<n;i++)		cout<<product[i]<<"  ";
	cout<<endl;
	return 0;
}
