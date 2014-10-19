#include<iostream>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
}N;

N *createList(){
	N *ptr=NULL,*start=NULL;
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
			ptr->next = temp;
		}
		ptr = temp;
		cout<<"Enter more data(Y/N): ";
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

N* delAlternate(N *start){
	N *x=start,*ptr=NULL;
	while(x && x->next){
		ptr = x->next;
		x->next = ptr->next;
		ptr->next = NULL;
		delete ptr;
		x = x->next;
	}
	return start;
}

int main(void){
	N *list = NULL;
	list = createList();
	cout<<"List:"<<endl;
	display(list);
	list = delAlternate(list);
	cout<<"After deleting alternate nodes, List becomes:"<<endl;
	display(list);
	return 0;
}

