#include<iostream>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
	struct node *random;
}N;

N *newNode(int val){
	N *temp = new N;
	temp->data = val;
	temp->next = NULL;
	temp->random = NULL;
	return temp;
}

N *createList(){
	N *temp = newNode(1);
	temp->next = newNode(2);
	temp->next->next = newNode(3);
	temp->next->next->next = newNode(4);
	temp->next->next->next->next = newNode(5);
	temp->random = temp->next->next;
	temp->next->random = temp;
	temp->next->next->random = temp->next->next->next->next;
	temp->next->next->next->random = temp->next->next;
	temp->next->next->next->next->random = temp->next;
	return temp;
}

void display(N *head){
	N *ptr=head;
	cout<<"NodeValue  RandomPointerValue"<<endl;
	while(ptr){
		cout<<ptr->data<<"\t\t"<<ptr->random->data<<endl;
		ptr=ptr->next;
	}
	cout<<endl;
}

N *copyList(N *head){
	N *copy=NULL,*temp=NULL,*ptr=head;
	while(ptr){
		temp = new N;
		temp->data = ptr->data;
		temp->next = ptr->next;
		ptr->next = temp;
		ptr = ptr->next->next;
	}
	
	ptr = head;
	while(ptr && ptr->next){
		ptr->next->random = ptr->random->next;
		ptr = ptr->next->next;
	}

	ptr = head;
	N *prev = NULL;
	while(ptr){
		if(copy==NULL)		copy = ptr->next;
		else 				prev->next = ptr->next;
		prev = ptr->next;
		ptr->next = ptr->next->next;
		ptr = ptr->next;
	}
	return copy;
}

int main(){
	N *list = NULL;
	list = createList();	// List created is same as the example shown above...
	display(list);
	N *copy = copyList(list);
	cout<<"Original List after copying:"<<endl;
	display(list);
	cout<<"Copy List:"<<endl;
	display(copy);
	return 0;
}
