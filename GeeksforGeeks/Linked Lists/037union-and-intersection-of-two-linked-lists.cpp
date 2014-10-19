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

N *insert(N *head,int val){
	N *temp = new N;
	temp->data = val;
	temp->next = NULL;
	if(!head)
		head = temp;
	else
		prev->next = temp;
	prev = temp;
	
	return head;
}

N *Intersection(N *head1,N *head2){
	N *intersection = NULL;
	N *ptr1=head1,*ptr2=head2;
	
	while(ptr1 && ptr2){
		if(ptr1->data < ptr2->data)			ptr1=ptr1->next;
		else if(ptr1->data > ptr2->data)	ptr2=ptr2->next;
		else{
			intersection = insert(intersection,ptr1->data);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
	}
	return intersection;
}

N *UnionOfLists(N *head1,N *head2){
	N *Union = NULL;
	N *ptr1=head1,*ptr2=head2;
	
	while(ptr1 && ptr2){
		if(ptr1->data < ptr2->data){
			Union = insert(Union,ptr1->data);
			ptr1=ptr1->next;
		}
		else if(ptr1->data > ptr2->data){
			Union = insert(Union,ptr2->data);
			ptr2=ptr2->next;
		}
		else{
			Union = insert(Union,ptr1->data);
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
	}
	while(ptr1){
		Union = insert(Union,ptr1->data);
		ptr1=ptr1->next;
	}
	while(ptr2){
		Union = insert(Union,ptr2->data);
		ptr2=ptr2->next;
	}
	return Union;
}

int main(){
	N *list1 = NULL,*list2=NULL;
	list1 = createList();
	list2 = createList();
	display(list1);
	display(list2);
	N *intersection = Intersection(list1,list2);
	cout<<"Intersection of lists:"<<endl;
	display(intersection);
	N *Union = UnionOfLists(list1,list2);
	cout<<"Union of lists:"<<endl;
	display(Union);
	return 0;
}
