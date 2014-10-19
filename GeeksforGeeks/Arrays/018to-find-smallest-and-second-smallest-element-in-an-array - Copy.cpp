/*	Smallest and Second Smallest elements in an Array...
*/
#include<iostream>
#include<climits>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	int min=INT_MAX,secMin=INT_MAX;
	for(int i=0;i<n;i++){
		if(a[i]<min){
			secMin = min;
			min = a[i];
		}
		else if(a[i]>min && a[i]<secMin)
			secMin = a[i];
	}
	if(secMin == INT_MAX){
		cout<<"Smallest Element: "<<min<<endl;
		cout<<"Second Smallest Entry does not exist!!"<<endl;
	}
	else{
		cout<<"Smallest Element: "<<min<<endl;
		cout<<"Second Smallest Element: "<<secMin<<endl;
	}
	return 0;
}
