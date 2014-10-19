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

void alternateSplit(N **head,N **a,N **b){
	N *ptr = *head,*prev1,*prev2;
	while(*head){
		ptr = *head;
		*head = (*head)->next;
		ptr->next = NULL;
		if(!*a)		*a = ptr;
		else		prev1->next = ptr;
		prev1 = ptr;
		
		if(*head){
			ptr = *head;
			*head = (*head)->next;
			ptr->next = NULL;
			if(!*b)		*b = ptr;
			else		prev2->next = ptr;
			prev2 = ptr;
		}
	}
}

int main(){
	N *list = NULL;
	list = createList();
	display(list);
	N *a=NULL,*b=NULL;
	alternateSplit(&list,&a,&b);
	cout<<"\nModified Lists:"<<endl;
	cout<<"\nOriginal List: ";
	display(list);
	cout<<"\nOdd List: ";
	display(a);
	cout<<"\nEven List: ";
	display(b);
	return 0;
}
