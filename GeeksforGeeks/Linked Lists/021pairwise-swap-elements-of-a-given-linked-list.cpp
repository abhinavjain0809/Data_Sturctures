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

N *swap(N *head){
	N *current=head,*ptr,*temp,*newHead=NULL,*prev;
	
	while(current && current->next){
		temp = current->next->next;
		ptr = current->next;
		ptr->next = current;
		current->next = temp;
		if(!newHead)	newHead=ptr;
		else 			prev->next = ptr;
		prev = current;
		current = current->next;
	}
	return newHead;
}

int main(){
	N *list = NULL;
	list = createList();
	display(list);
	list = swap(list);
	cout<<"Modified List:"<<endl;
	display(list);
	return 0;
}
