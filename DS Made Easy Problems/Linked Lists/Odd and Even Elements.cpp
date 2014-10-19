#include<iostream>
#include<stdlib.h>
#include<ctype.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}N;

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

N* rearrange(N* start){
    N *ptr=start,*even=NULL,*x=start,*temp=start;
    while(temp && temp->next){
        x = ptr;
        ptr = ptr->next;
        x->next=ptr->next;
        ptr->next=NULL;
        if(even==NULL)      even=ptr;
        else{
            ptr->next=even;
            even=ptr;
        }
        temp = x->next;
        ptr = x->next;
    }
    ptr=start;
    while(ptr->next!=NULL)      ptr=ptr->next;
    ptr->next = even;
    return start;
}

int main(){
    N* list;
    cout<<"Enter Data for List:\n";
    list=create();
    display(list);
    list=rearrange(list);
    cout<<"\n\nRearranged List:\n";
    display(list);
    return 0;
}
