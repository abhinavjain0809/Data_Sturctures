#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}N;

N* createList(){
    N *start=NULL,*temp,*prev;
    char ans;
    cout<<"Create List(Y/N): ";
    cin>>ans;
    while(ans=='Y' || ans=='y'){
        temp = new N;
        if(!start)	start=temp;
        else		prev->next=temp;
        prev = temp;
        cout<<"Data: ";
        cin>>temp->data;
        temp->next=start;
        cout<<"Continue(Y/N): ";
		cin>>ans;
	}
    return start;
}

void display(N *start){
    N *ptr = start;
    while(ptr->next!=start){
        cout<<ptr->data<<"  ";
        ptr = ptr->next;
    }
    cout<<ptr->data<<endl;
}

void splitCircularList(N* head,N **a,N **b){
	N *slow=head,*fast=head;
	*a=head;
	while(fast->next!=head && fast->next->next!=head){
		fast = fast->next->next;
		slow = slow->next;
	}
	
	if(fast->next==head){	// odd length...
		*b = slow->next;
		fast->next = *b;
		slow->next = head;
	}
	else if(fast->next->next==head){	// even length...
		*b = slow->next;
		fast->next->next = *b;
		slow->next = head;
	}
}

int main(){
    N *list=NULL;
	list = createList();
    display(list);
    N *a=NULL,*b=NULL;
    splitCircularList(list,&a,&b);
    cout<<"Two halves of the list: "<<endl;
    display(a);
    display(b);
    return 0;
}
