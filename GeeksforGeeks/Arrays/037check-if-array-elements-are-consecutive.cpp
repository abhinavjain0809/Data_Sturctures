/*	Check if Array elements are consecutive or not...
 *	14.08.2014
*/
#include <iostream>
#include <climits>
using namespace std;

int getMin(int a[],int n){
	int min = INT_MAX;
	for(int i=0;i<n;i++){
		if(a[i] < min)	min = a[i];
	}
	return min;
}

int getMax(int a[],int n){
	int max = INT_MIN;
	for(int i=0;i<n;i++){
		if(a[i] > max)	max = a[i];
	}
	return max;
}

bool isConsecutive(int a[],int n){
	int max = getMax(a,n);
	int min = getMin(a,n);
	
	if(max-min+1==n){
		bool *visited = new bool[n];
		for(int i=0;i<n;i++)	visited[i]=false;
		
		for(int i=0;i<n;i++){
			if(visited[a[i]-min]!=false)	return false;
			else	visited[a[i]-min] = true;
		}
		return true;
	}
	else 	return false;
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	bool ans = isConsecutive(a,n);
	if(ans)		cout<<"Array Elements are Consecutive"<<endl;
	else		cout<<"Array Elements are not Consecutive"<<endl;
	return 0;
}
