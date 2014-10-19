#include<iostream>
using namespace std;

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort012(int a[],int n){
	int left=0,mid=0,right=n-1;
	
	while(mid<=right){
		switch(a[mid]){
			case 0:
					swap(a[left],a[mid]);
					left++;
					mid++;
					break;
					
			case 1:
					mid++;
					break;
			
			case 2:
					swap(a[mid],a[right]);
					right--;
					break;
		}
	}
}

void printArray(int a[],int n){
	for(int i=0;i<n;i++)	cout<<a[i]<<"  ";
	cout<<endl;
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	sort012(a,n);
	printArray(a,n);
	return 0;
}
