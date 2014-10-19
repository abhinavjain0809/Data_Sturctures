#include<iostream>
#include<climits>
using namespace std;

void printArray(int a[],int start,int end){
	for(int i=start;i<=end;i++)	cout<<a[i]<<"  ";
	cout<<endl;
}

void unsortedPart(int a[],int n){
	int s=0,e=n-1;
	
	for(int i=0;i<n-1;i++){
		if(a[i] > a[i+1]){
			s = i;
			break;
		}
	}
	for(int i=n-1;i>=0;i--){
		if(a[i] < a[i-1]){
			e = i;
			break;
		}
	}
	
	int max=INT_MIN,min=INT_MAX;
	for(int i=s;i<=e;i++){
		if(a[i]>max)	max = a[i];
		if(a[i]<min)	min = a[i];
	}
	
	for(int i=0;i<s;i++){
		if(a[i] > min){
			s=i;
			break;
		}
	}
	for(int i=n-1;i>e;i--){
		if(a[i] < max){
			e=i;
			break;
		}
	}
	cout<<"Minimum UnSorted Array lies between indices "<<s<<" amd "<<e<<endl;
	cout<<"Minimum UnSorted Array: ";
	printArray(a,s,e);
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	unsortedPart(a,n);
	return 0;
}
