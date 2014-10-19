#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node*next;
}L;
L*head=NULL,*y;

L *prev=NULL;
static int a=1,b=0;

void insert(int);
void display();
void reverse(L*);
int main()
{
    int d,ch=1;
    while(ch==1)
    {
        cout<<"Enter data for node : ";
        cin>>d;
        insert(d);
        cout<<"Do u wanna enter more nodes ? (1-->yes) : ";
        cin>>ch;
    }
    cout<<"The linked list is - "<<endl;
    display();
    cout<<endl<<endl;
    reverse(head);
    cout<<"The Modified linked list is - "<<endl;
    cout<<endl<<endl;
    display();
    cout<<endl<<endl;
    return 0;
}
void insert(int k)
{
    L*temp=new L;
    temp->data=k;
    temp->next=NULL;

    if(head==NULL)
    {
        head=y=temp;
    }
    else
    {
        y->next=temp;
        y=temp;
    }
}
void display()
{
    L*p;
    p=head;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
void reverse(L*current)
{
    //if(current==NULL || current->next==NULL)
    if(current==NULL)       return;     // u cant access current->next if current=NULL as NULL->next is undefined...
	
    if(current->next==NULL) return;
/*	
    if(current->next==NULL){
        cout<<current->data<<" ";
        return;
    }
*/
        L*temp;
        temp=current->next;
        //cout<<temp->data<<" ";
        current->next=temp->next;
        temp->next=current;
        if(a==1){
            head=temp;
            a=0;
        }
        if(b==1){
            prev->next = temp;
//            b=1;
        }
        //cout<<current->data<<" ";
        prev = current;
        b=1;
        reverse(current->next);
}
