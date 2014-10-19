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

bool isPalindrome(N *head){
	N *prevSlow,*slow=head,*fast=head;
	bool ans=true;
	while(fast && fast->next){
		fast = fast->next->next;
		prevSlow = slow;
		slow = slow->next;
	}
	N *mid = NULL;
	if(fast){		// List has odd number of elements...
		mid = slow;
		slow = slow->next;
	}
	prevSlow->next=NULL;
	slow = reverse(slow);
	N *a=head,*b=slow;
	while(a){
		if(a->data != b->data){
			ans=false;
			break;
		}
		a=a->next;
		b=b->next;
	}
	slow=reverse(slow);
	if(mid){		// List has odd number of elements...
		prevSlow->next = mid;
		mid->next = slow;
	}
	else
		prevSlow->next = slow;
	return ans;
}

int main(){
	N *list = NULL;
	list = createList();
	display(list);
	bool ans = isPalindrome(list);
	if(ans)		cout<<"Given List is a Palindrome..."<<endl;
	else 		cout<<"Given List is not a Palindrome..."<<endl;
	display(list);
	return 0;
}
