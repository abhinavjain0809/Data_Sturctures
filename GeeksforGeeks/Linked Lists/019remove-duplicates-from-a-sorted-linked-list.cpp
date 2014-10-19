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
/**
    WORKING FUNCTION...
N *removeDuplicates(N *head){
	N *x=head,*ptr=head;

	while(ptr && ptr->next){
		if(ptr->data == ptr->next->data){
			ptr = ptr->next;
			x->next = ptr->next;
			delete ptr;
			ptr = x;
		}
		else{
			ptr = ptr->next;
			x = x->next;
		}
	}
	return head;
}
**/

N *removeDuplicates(N *head){
    if(!head)   return NULL;
    N*x=head,*y=head->next,*temp;
    while(y){
        if(x->data==y->data){
            temp=y;
            y=y->next;
            delete temp;
            x->next=y;
        }
        else{
            x=y;
            y=y->next;
        }
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
