#include<iostream>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
}N;
N *prev=NULL;

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
/*
N *reverse(N *head){
	N *current=head,*next,*temp=NULL;
	
	while(current){
		next = current->next;
		current->next = temp;
		temp = current;
		current = next;
	}
	return temp;
}
*/

void reverse(N *head){
	if(!head)	return;

	N *next = head->next;
	head->next = prev;
	prev = head;
	
	reverse(next);
	//~ return prev;
}

int main(){
	N *list = NULL;
	list = createList();
	display(list);
	reverse(list);
	cout<<"Reversed List:"<<endl;
	display(prev);
	return 0;
}
