#include<iostream>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
}N;

N *createList(){
	N *start=NULL,*prev=NULL;
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
			prev->next = temp;
		}
		prev = temp;
		cout<<"Enter more Digits(Y/N): ";
		cin>>ch;
	}
	return start;
}

void display(N *start){
	N *ptr = start;
	while(ptr){
		cout<<ptr->data<<"  ";
		ptr = ptr->next;
	}
	cout<<endl;
}

N *alternatingSplit(N *head){
	N *ptr=head,*a=NULL,*prev=NULL;

	while(ptr && ptr->next){
		if(!a)		a=ptr->next;
		else		prev->next = ptr->next;
		prev = ptr->next;
		
		ptr->next = ptr->next->next;
		ptr = ptr->next;
		prev->next = NULL;
	}
	return a;
}

int main(){
	N *list = NULL;
	list = createList();
	display(list);
	N *even = alternatingSplit(list);
	cout<<"Odd Elements:"<<endl;
	display(list);
	cout<<"Even Elements:"<<endl;
	display(even);
	return 0;
}
