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

bool areIdentical(N *head1,N *head2){
	if(!head1 && !head2)			return true;
	else if(!head1 && head2)		return false;
	else if(head1 && !head2)		return false;
	return ((head1->data == head2->data) && areIdentical(head1->next,head2->next));
}

int main(){
	N *list1=NULL,*list2=NULL;
	list1 = createList();
	list2 = createList();
	display(list1);
	display(list2);
	if(areIdentical(list1,list2))	cout<<"Lists are Identical"<<endl;
	else							cout<<"Lists are NOT Identical!!"<<endl;
	return 0;
}
