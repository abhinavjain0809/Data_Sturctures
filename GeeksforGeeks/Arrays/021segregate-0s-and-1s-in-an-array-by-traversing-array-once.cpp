#include<iostream>
using namespace std;

void sort0n1(int a[],int n){
	int i=-1,j=n;
	while(i<j){
		do 	i++;
		while(a[i]==0);
		
		do 	j--;
		while(a[j]==1);
		
		if(i<j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	cout<<"Input Array with 0's and 1's only:"<<endl;
	for(int i=0;i<n;i++)	cin>>a[i];
	sort0n1(a,n);
	for(int i=0;i<n;i++)	cout<<a[i]<<"  ";
	cout<<endl;
	return 0;
}
