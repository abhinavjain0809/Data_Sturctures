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

N *merge(N *a,N *b){
	N *result=NULL;
	if(a==NULL)				return b;
	else if(b==NULL)		return a;
	
	if(a->data <= b->data){
		result = a;
		result->next = merge(a->next,b);
	}
	else{
		result = b;
		result->next = merge(a,b->next);
	}
	return result;
}

void split(N *head,N **a,N **b){
	if(head==NULL || head->next==NULL){
		*a = head;
		*b = NULL;
		return;
	}

	N *slow=head,*fast=head->next;
	while(fast && fast->next){
		fast = fast->next->next;
		slow = slow->next;
	}
	*a = head;
	*b = slow->next;
	slow->next=NULL;
}

void mergeSort(N **start){
	N *head = *start;
	if(head==NULL || head->next==NULL)	return;
	N *a=NULL,*b=NULL;
	split(head,&a,&b);
	mergeSort(&a);
	mergeSort(&b);
	*start = merge(a,b);
}

int main(){
	N *list = NULL;
	list = createList();
	display(list);
	mergeSort(&list);
	cout<<"Sorted List:"<<endl;
	display(list);
	return 0;
}
