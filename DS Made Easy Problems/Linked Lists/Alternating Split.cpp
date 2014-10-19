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

void alternatingSplit(N *start,N **odd, N **even){
	N *ptr=start,*temp=start,*x=NULL,*prev=NULL;
	*odd = start;
	while(temp && temp->next){
		x = ptr;
		ptr=ptr->next;
		x->next = ptr->next;
		ptr->next = NULL;
		
		if(*even==NULL)		*even=ptr;
		else 				prev->next = ptr;
		prev = ptr;
		
		temp = x->next;
		ptr = temp;
	}
}

int main(void){
	N *list = NULL;
	list = createList();
	cout<<"List:"<<endl;
	display(list);
	
	N *odd=NULL,*even=NULL;
	alternatingSplit(list,&odd,&even);
	cout<<"Odd List: ";
	display(odd);
	cout<<"Even List: ";
	display(even);
	return 0;
}
