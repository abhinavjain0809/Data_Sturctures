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
	if(!a)			return b;
	else if(!b)		return a;
	else if(a->data <= b->data){
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
	if(!head || !head->next){
		*a = head;
		*b = NULL;
		return;
	}
	
	N *slow=head,*fast=slow->next;
	while(fast && fast->next){
		fast = fast->next->next;
		slow = slow->next;
	}
	*a = head;
	*b = slow->next;
	slow->next = NULL;
}

void mergeSort(N **start){
	N *head = *start;
	if(!head || !head->next)	return;
	
	N *a,*b;
	split(head,&a,&b);
	mergeSort(&a);
	mergeSort(&b);
	*start=merge(a,b);
}

N *removeDuplicates(N *head){
	mergeSort(&head);

	N *ptr=head,*x;
	while(ptr && ptr->next){
		if(ptr->data == ptr->next->data){
			x = ptr->next;
			ptr->next = x->next;
			delete x;
		}
		else 	ptr=ptr->next;
	}
	return head;
}

int main(){
	N *list = NULL;
	list = createList();
	display(list);
	list = removeDuplicates(list);
	cout<<"Modified List:"<<endl;
	display(list);
	return 0;
}
