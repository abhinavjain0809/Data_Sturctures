#include<iostream>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
}N;

N *createList(){
	N *start=NULL;
	char ch;
	int val;
	cout<<"Create List (Y/N): ";
	cin>>ch;
	
	while(ch=='Y' || ch=='y'){
		cout<<"Data: ";
		cin>>val;
		N *temp = new N;
		temp->data = val;
		temp->next = NULL;
		
		if(start==NULL)		start = temp;
		else{
			temp->next = start;
			start = temp;
		}
		cout<<"Enter more Digits(Y/N): ";
		cin>>ch;
	}
	return start;
}

void display(N *start){
	N *ptr = start;
	while(ptr){
		cout<<ptr->data;
		ptr = ptr->next;
	}
	cout<<endl;
}

N *add(N *num1,N *num2){
	N *a=num1,*b=num2,*result=NULL;
	int sum,carry=0;
	
	while(a || b){
		sum = carry + (a ? a->data : 0) + (b ? b->data : 0);
		if(sum>9)	carry = sum/10;
		sum %= 10;
		
		N *temp = new N;
		temp->data = sum;
		temp->next = NULL;
		
		if(!result)		result = temp;
		else{
			temp->next = result;
			result = temp;
		}
		
		if(a)	a = a->next;
		if(b)	b = b->next;

		if(!a && !b && carry){
			N *temp = new N;
			temp->data = carry;
			if(!result)		result = temp;
			else{
				temp->next = result;
				result = temp;
			}					
		}
	}
	return result;
}

int main(){
	N *num1=NULL,*num2=NULL;
	cout<<"Number 1:"<<endl;
	num1 = createList();
	//display(num1);
	cout<<"Number 2:"<<endl;
	num2 = createList();
	//display(num2);
	N *result = add(num1,num2);
	cout<<"Sum is: ";
	display(result);
	return 0;
}
