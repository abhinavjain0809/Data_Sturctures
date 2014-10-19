#include <iostream>
#include <stack>
using namespace std;

void NGE(int *a,int n){
	stack<int> s;
	s.push(a[0]);
	for(int i=1;i<n;i++){
		if(!s.empty()){
			int x = s.top();
			s.pop();
			while(x < a[i]){
				cout<<"   "<<x<<"     "<<a[i]<<endl;
				if(s.empty())		break;
				x = s.top();
				s.pop();
			}
			
			if(x > a[i]){
				s.push(x);
			}
		}
		s.push(a[i]);
	}
	
	while(!s.empty()){
		cout<<"   "<<s.top()<<"    -1"<<endl;
		s.pop();
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)	cin>>a[i];
	cout<<"Element  NGE"<<endl;
	NGE(a,n);
	return 0;
}
