#include<iostream>
#include<cstdlib>
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

N *insertNode(N *head, int val){
	N *temp = (N*)malloc(sizeof(N));
	temp->data = val;
	temp->next = NULL;
	if(!head){
		head=temp;
		return head;
	}
	else if(head->data >= val){
		temp->next=head;
		head=temp;
		return head;
	}

	N *ptr=head,*x=head;
	while(ptr && ptr->data <= val){
		x=ptr;
		ptr=ptr->next;
	}
    x->next = temp;
    temp->next = ptr;
	return head;
}

int main(){
	N *list = NULL;
	list = createList();
	display(list);
	int val;
	cout<<"Value to insert: ";
	cin>>val;
	list = insertNode(list,val);
	cout<<"Modified List:"<<endl;
	display(list);
	return 0;
}
