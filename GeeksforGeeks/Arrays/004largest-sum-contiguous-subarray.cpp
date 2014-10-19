#include <iostream> 
#define maximum(a,b) ((a>b)?a:b)
using namespace std;
/*
int maximum(int x,int y){
	return (x>y ? x:y);
}
*/
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	
	int max=a[0],curr=a[0];
	for(int i=1;i<n;i++){
		curr = maximum(a[i],curr+a[i]);
		max  = maximum(max,curr);
	}
	cout<<"Maximum continuos sum: "<<max<<endl;
	return 0;
}
