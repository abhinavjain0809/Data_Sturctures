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
	int x=a[n/2];
	int count=0;
	for(int i=n/2;i>=0;i--){
		if(x==a[i])		count++;
	}
	
	for(int i=n/2+1;i<n;i++){
		if(x==a[i])		count++;
	}
	
	if(count >= n/2)	cout<<x<<endl;
	else 				cout<<"No Majority Element exists!!!";
	return 0;
}
