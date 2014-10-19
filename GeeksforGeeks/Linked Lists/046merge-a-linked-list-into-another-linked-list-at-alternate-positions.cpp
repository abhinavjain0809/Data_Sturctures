#include<iostream>
#include<assert.h>
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

N *mergeAlternate(N *head1,N **head2){
	N *ptr=head1,*temp=NULL,*next=NULL;
	
	while(ptr){
		temp = ptr->next;
		if(*head2){
			next = (*head2)->next;
			ptr->next = *head2;
			(*head2)->next = temp;
			*head2 = next;
			ptr = temp;
		}
		else	return head1;
	}
	return head1;
}

int main(){
	N *list1=NULL,*list2=NULL;
	list1 = createList();
	list2 = createList();
	display(list1);
	display(list2);
	list1 = mergeAlternate(list1,&list2);
	cout<<"Modified Lists:"<<endl;
	cout<<"List 1: ";
	display(list1);
	cout<<"List 2: ";
	display(list2);
	return 0;
}
