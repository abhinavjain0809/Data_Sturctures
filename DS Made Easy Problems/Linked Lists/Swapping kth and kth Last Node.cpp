#include<iostream>
#include<stdlib.h>
#include<ctype.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}N;
static int len=0;
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
        len++;
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

int main(){
    N* start;
    int k;
    cout<<"Enter Data for List:\n";
    start=create();
    display(start);
    cout<<"\nEnter K: ";
    cin>>k;
    if(k>len){
        cout<<"Too few nodes!!"<<endl;
        return 0;
    }

    if(2*k-1==len){       // Kth and kth Last nodes are same...
        display(start);
        return 0;
    }

    N *kprev=NULL,*kth=start;
    for(int i=1;i<k;i++){
        kprev = kth;
        kth = kth->next;
    }

    N *kLastprev=NULL,*kthLast=start;
    for(int i=1;i<len-k+1;i++){
        kLastprev = kthLast;
        kthLast = kthLast->next;
    }

    if(kprev)       kprev->next=kthLast;
    if(kLastprev)   kLastprev->next=kth;

    N *temp=kth->next;
    kth->next=kthLast->next;
    kthLast->next=temp;
    if(k==1)        start=kthLast;
    if(k==len)      start=kth;
    cout<<"Modified List"<<endl;
    display(start);
    return 0;
}
