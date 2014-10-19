#include <iostream>
#include <cstdlib>
using namespace std;

int cmp(const void *a,const void *b){
	return (*(int*)a-*(int*)b);
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	qsort(a,n,sizeof(int),cmp);
	int x;
	cout<<"Enter number: ";
	cin>>x;
	
	int i=0,j=n-1,temp;
	while(i<j){
		temp = a[i]+a[j];
		if(temp==x){
			cout<<a[i]<<"  "<<a[j]<<endl;
			exit(0);
		}
		else if(temp<x)		i++;
		else 				j--;
	}
	cout<<"Pair doesn't exist!!!"<<endl;
	return 0;
}
