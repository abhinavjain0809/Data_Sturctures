/*	Median of two sorted arrays...
 */
#include<iostream>
using namespace std;

int median(int a[],int m,int *b,int n){
	int x=m+n,mid;
	if(x&1)		mid=((m+n)/2)+1;
	else 		mid=(m+n)/2;
	int i=0,j=0;
	int med=0,count=0;
	
	while(i!=m || j!=n){		
		if((a[i]<=b[j] && i<m) || (j==n)){
			med = a[i];
			i++;
		}
		else{
			med = b[j];
			j++;
		}
		count++;
		if(count==mid)		break;
	}
	return med;
}

int main(){
	int m;
	cin>>m;
	int a[m];
	for(int i=0;i<m;i++)	cin>>a[i];
	int n;
	cin>>n;
	int b[n];
	for(int i=0;i<n;i++)	cin>>b[i];
	int med = median(a,m,b,n);
	cout<<"Median of both arrays: "<<med<<endl;
	return 0;
}
