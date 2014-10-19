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

N *reverseAlternateK(N *head,int k){
	N *current=head,*next=NULL,*prev=NULL;
	int count=0;
	
	while(current && count<k){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	head->next = current;
	
	count=0;
	while(head && count<k){
		head=head->next;
		count++;
	}

	if(head){
		head->next = reverseAlternateK(head->next,k);
	}
	return prev;
}

int main(){
	N *list = NULL;
	list = createList();
	display(list);
	int k;
	cout<<"Enter block size to reverse in alternate fashion: ";
	cin>>k;
	if(k!=0 && k!=1)	list = reverseAlternateK(list,k);
	cout<<"Modified List:"<<endl;
	display(list);
	return 0;
}
