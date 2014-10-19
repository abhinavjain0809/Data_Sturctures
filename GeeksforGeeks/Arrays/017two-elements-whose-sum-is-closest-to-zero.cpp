#include<iostream>
#include<cstdlib>
#include<climits>
#include<cmath>
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
	int i=0,j=n-1,sum,minSum=INT_MAX;
	cout<<"Sum closest to 0 in the array: ";
	while(i<j){
		sum = a[i]+a[j];
		if(abs(sum) < abs(minSum))		minSum = sum;

		if(sum<0)			i++;
		else if(sum>0)		j--;
		else 				break;
	}
	cout<<minSum<<endl;
	return 0;
}
