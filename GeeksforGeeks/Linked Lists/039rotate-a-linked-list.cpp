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
	N *current=head,*next=NULL,*temp=NULL;
	
	while(current){
		next = current->next;
		current->next = temp;
		temp = current;
		current = next;
	}
	return temp;
}

N *rotate(N *head,int k){
	N *current=head;
	int count=1;
	
	while(current && count<k){
		current = current->next;
		count++;
	}
	if(!current){
		cout<<"Too few Nodes!!"<<endl;
		return head;
	}
	N *a=head,*b=current->next;
	current->next = NULL;
	
	a = reverse(a);
	b = reverse(b);
	head->next = b;
	head = reverse(a);
	return head;
}
*/

N *rotate(N *head,int k){
	N *current=head,*kth=NULL,*kPlusOneth=NULL;
	int count=0;
	
	while(current && count<k){
		kth = current;
		current = current->next;
		count++;
	}
	if(!current){
		cout<<"Too Few Nodes!!!"<<endl;
		return head;
	}
	kPlusOneth = current;
	kth->next=NULL;
	N *ptr=kPlusOneth;
	while(ptr->next)	ptr=ptr->next;
	ptr->next = head;
	head = kPlusOneth;
	return head;
}

int main(){
	N *list=NULL;
	list = createList();
	display(list);
	int k;
	cout<<"Rotate by: ";
	cin>>k;
	list = rotate(list,k);
	cout<<"Rotated list: "<<endl;
	display(list);
	return 0;
}
