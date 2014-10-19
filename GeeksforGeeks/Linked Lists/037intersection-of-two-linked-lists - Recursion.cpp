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

N *Intersection(N *head1,N *head2){
	N *intersection = NULL;
	
	if(!head1 || !head2)	return NULL;
	
	if(head1->data == head2->data){
		intersection = head1;
		intersection->next = Intersection(head1->next,head2->next);
	}
	else if(head1->data < head2->data){
		return Intersection(head1->next,head2);
	}
	else
		return Intersection(head1,head2->next);

	return intersection;
}

int main(){
	N *list1=NULL,*list2=NULL;
	list1 = createList();
	list2 = createList();
	display(list1);
	display(list2);
	N *intersection = Intersection(list1,list2);
	cout<<"Intersection of lists:"<<endl;
	display(intersection);
	return 0;
}
