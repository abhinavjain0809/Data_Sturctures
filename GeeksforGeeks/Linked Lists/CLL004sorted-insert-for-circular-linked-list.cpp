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
    if(ptr!=NULL){
		while(ptr->next!=start){
			cout<<ptr->data<<"  ";
			ptr = ptr->next;
		}
		cout<<ptr->data<<endl;
	}
}

N *insert(N *head,int val){
	N *ptr = head;
	N *temp = new N;
	temp->data = val;
	temp->next = NULL;
	if(!head){
		temp->next = temp;
		head = temp;
	}
	else if(head->data > val){
		while(ptr->next!=head)		ptr = ptr->next;
		ptr->next = temp;
		temp->next = head;
		head = temp;
	}
	else{
		while(ptr->next!=head && ptr->next->data <= val)
			ptr = ptr->next;
		temp->next = ptr->next;
		ptr->next = temp;
	}
	return head;
}

int main(){
    N *list=NULL;
	list = createList();
    display(list);
    int val;
    cout<<"Data to insert: ";
    cin>>val;
    list = insert(list,val);
    display(list);
    return 0;
}
