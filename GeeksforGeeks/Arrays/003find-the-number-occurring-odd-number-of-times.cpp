#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	int xr=a[0];
	for(int i=1;i<n;i++)	xr ^= a[i];
	cout<<"Element occuring ODD times: "<<xr<<endl;
	return 0;
}
