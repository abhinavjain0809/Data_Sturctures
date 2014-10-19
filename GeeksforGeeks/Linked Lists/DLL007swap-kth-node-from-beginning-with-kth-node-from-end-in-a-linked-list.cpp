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

int getSize(N *head){
	int count=0;
	while(head){
		head=head->next;
		count++;
	}
	return count;
}

N *swap(N *head,int k){
	if(!head)	return head;
	int n = getSize(head);
	if(k > n){
		cout<<"Too few nodes!!!"<<endl;
		return head;
	}
	else if((2*k-1)==n)		return head;
	
	N *x=head,*xPrev=NULL;
	N *y=head,*yPrev=NULL;
	int count=1;
	while(x && count<k){
		xPrev=x;
		x=x->next;
		count++;
	}
	count=1;
	while(y && count<(n-k+1)){
		yPrev=y;
		y=y->next;
		count++;
	}

	if(xPrev)	xPrev->next = y;
	if(yPrev)	yPrev->next = x;
	
	N *temp = x->next;
	x->next = y->next;
	y->next = temp;
	
	if(k==1)	head = y;
	if(k==n)	head = x;
	
	return head;
}

int main(){
	N *list = NULL;
	list = createList();
	display(list);
	int k;
	cout<<"Input k: ";
	cin>>k;
	list = swap(list,k);
	display(list);
	return 0;
}
