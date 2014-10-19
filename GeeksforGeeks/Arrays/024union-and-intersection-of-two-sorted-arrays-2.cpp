/*	Union and Intersection of two sorted arrays...
 */
#include<iostream>
#include<algorithm>
using namespace std;

void Union(int a[],int b[],int m,int n){
	int i=0,j=0;
	while(i<m && j<n){
		if(a[i] < b[j]){
			cout<<a[i]<<"  ";
			i++;
		}
		else if(b[j] < a[i]){
			cout<<b[j]<<"  ";
			j++;
		}
		else{
			cout<<a[i]<<"  ";
			i++;
			j++;
		}
	}
	while(i<m)		cout<<a[i++]<<"  ";
	while(j<n)		cout<<b[j++]<<"  ";
	cout<<endl;
}

void intersection(int a[],int b[],int m,int n){
	int i=0,j=0;
	while(i<m && j<n){
		if(a[i] < b[j])				i++;
		else if(b[j] < a[i])		j++;
		else{
			cout<<a[i]<<"  ";
			i++;
			j++;
		}
	}
	cout<<endl;
}

int main(){
	int m,n;
	cin>>m>>n;
	int a[m],b[n];
	for(int i=0;i<m;i++)	cin>>a[i];
	for(int i=0;i<n;i++)	cin>>b[i];
	sort(a,a+m);
	sort(b,b+n);
	cout<<"Union of Arrays: ";
	Union(a,b,m,n);
	cout<<"Intersection of Arrays: ";
	intersection(a,b,m,n);
	return 0;
}
