/*	list1 can be unsorted, list2 is sorted in ascending order and list3 is sorted in descending order...
*/
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

void triplet(N *head1,N *head2,N *head3,int key){
	N *a=head1,*b=head2,*c=head3;
	int sum=0;
	while(a){
		b = head2;
		c = head3;
		while(b && c){
			sum = a->data + b->data + c->data;
			
			if(sum==key){
				cout<<"Triplet FOUND - "<<a->data<<"  "<<b->data<<"  "<<c->data<<endl;
				return;
			}
			else if(sum < key)		b=b->next;
			else					c=c->next;
		}
		a = a->next;
	}
	cout<<"NO such Triplet exists!!"<<endl;
}

int main(){
	N *list1=NULL,*list2=NULL,*list3=NULL;
	cout<<"List 1:"<<endl;
	list1 = createList();
	cout<<"List 2:"<<endl;
	list2 = createList();
	cout<<"List 3:"<<endl;
	list3 = createList();
	int key;
	cout<<"Key to look for: ";
	cin>>key;
	triplet(list1,list2,list3,key);
	return 0;
}
