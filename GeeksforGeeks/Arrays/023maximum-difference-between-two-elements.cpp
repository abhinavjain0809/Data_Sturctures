/*	Maximum difference between two elements such that larger element appears after the smaller number...
 */
#include<iostream>
#include<climits>
using namespace std;

int maxDiff(int a[],int n){
	int min=a[0],diff=INT_MIN;
	for (int i = 1; i < n; i++){
		if((a[i]-min) > diff)	diff = a[i]-min;
		if(a[i] < min)			min = a[i];
	}
	return diff;
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	int diff = maxDiff(a,n);
	cout<<"Maximum difference: "<<diff<<endl;
	return 0;
}
