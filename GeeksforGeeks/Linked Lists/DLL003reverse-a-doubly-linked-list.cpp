#include<iostream>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
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
		temp->prev = NULL;
		
		if(start==NULL)		start = temp;
		else{
			prev->next = temp;
			temp->prev = prev;
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

N *reverse(N *head){
	N* next=NULL,*prev=NULL,*current=head;
	
	while(current){
		next = current->next;
		current->next = prev;
		current->prev = next;
		prev = current;
		current = next;
	}
	return prev;
}

int main(){
	N *list = NULL;
	list = createList();
	display(list);
	list = reverse(list);
	display(list);
	return 0;
}
