#include<iostream>
#include<cstring>
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

N *removeDuplicates(N *head){
    N *current=head,*prev,*temp,*ptr;
    bool pr[1000];
    memset(pr,false,sizeof(pr));
    while(current){
        if(pr[current->data]){
            temp = current;
            current = current->next;
            prev->next = current;
            delete temp;
        }
        else{
            pr[current->data] = true;
            prev = current;
            current = current->next;
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
