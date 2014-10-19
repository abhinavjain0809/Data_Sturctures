#include<iostream>
#include<stdlib.h>
#include<ctype.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}N;
N *list1=NULL,*list2=NULL;

N* create()
{
    N *start=NULL,*ptr,*temp;
    char ans='Y';
    while(toupper(ans)=='Y')
    {
        temp = new N;
        if(temp==NULL)
        {
            cout<<"OUT OF MEMORY!!!";
            exit(1);
        }
        cout<<"Data: ";
        cin>>temp->data;
        temp->next=NULL;

        if(start==NULL)     start = temp;
        else
        {
            ptr = start;
            while(ptr->next!=NULL)      ptr = ptr->next;
            ptr->next = temp;
        }

        cout<<"Insert more Data(Y/N): ";
        cin>>ans;
    }
    return start;
}

void display(N *start)
{
    N *ptr=start;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"\t";
        ptr = ptr->next;
    }
}

N *mergeList(){
    if(list2==NULL)     return list1;
    N *ptr1=list1,*temp;
    N *ptr2=list2;
/*
    while(ptr1 && ptr2){
        temp=ptr1->next;
        ptr1->next=ptr2;
        list2=list2->next;
        ptr2->next=temp;
        ptr1=temp;
        ptr2=list2;
    }
*/
	while(ptr1 && ptr2){
		temp = ptr2;
		ptr2 = ptr2->next;
		list2 = list2->next;
		temp->next = ptr1->next;
		ptr1->next = temp;
		ptr1 = temp;
		ptr1 = ptr1->next;
	}

    return list1;
}

int main(){
    cout<<"Data for 1st List: "<<endl;
    list1 = create();
    cout<<"Data for 2nd List: "<<endl;
    list2 = create();
    cout<<"List 1:\n";
    display(list1);
    cout<<endl<<endl;
    cout<<"List 2:\n";
    display(list2);
    cout<<endl<<endl;
    list1 = mergeList();
    cout<<endl<<"List 1: "<<endl;
    display(list1);
    cout<<endl<<"List 2: "<<endl;
    display(list2);
    cout<<endl;
    return 0;
}
