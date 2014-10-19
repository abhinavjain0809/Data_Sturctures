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

N *deleteMN(N *head,int m,int n){
	N *current=head,*prev=NULL;
	int count1=0,count2=0;
	
	while(current){
		count1=0;
		while(current && count1<m){
			prev=current;
			current = current->next;
			count1++;
		}
		count2=0;
		while(current && count2<n){
			prev->next = current->next;
			delete current;
			current = prev->next;
			count2++;
		}
	}
	return head;
}

int main(){
	N *list = NULL;
	list = createList();
	display(list);
	int m,n;
	cout<<"Enter m nad n: ";
	cin>>m>>n;
	assert(m!=0);
	list = deleteMN(list,m,n);
	cout<<"Modified List:"<<endl;
	display(list);
	return 0;
}
