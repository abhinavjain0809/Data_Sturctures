#include<iostream>
#include<ctype.h>
#include<stdlib.h>
using namespace std;
typedef struct node
{
    int data;
    struct node *next;
}N;
N *create();
int floyd_cycle(N*);
int main()
{
    N *list;
    cout<<"Press 'N' to end the list in cyclic format (For Cyclic Form, min 2 nodes must be present)\n";
    list = create();
    floyd_cycle(list);
    return 0;
}

N *create()
{
    N *start=NULL, *ptr, *temp;
    unsigned int p, nodes=0;
    char ans='Y';
    while(toupper(ans)=='Y')
    {
        temp = new N;
        cout<<"Data: ";
        cin>>temp->data;
        temp->next=NULL;
        if(temp==NULL)
        {
            cout<<"OUT OF MEMORY!!!";
            exit(1);
        }
        nodes++;
        if(nodes==2)    p = (unsigned int)temp;
        if(start==NULL)     start=temp;
        else
        {
            ptr=start;
            while(ptr->next!=NULL)      ptr=ptr->next;
            ptr->next=temp;
        }
        cout<<"Insert more nodes(Y/N): ";
        cin>>ans;
        if(toupper(ans)=='N')   temp->next = (N*)p;
    }
    return start;
}

int floyd_cycle(N *start)
{
    N *slow=start, *fast=start;
    int loop=0, count=0;
    while(fast)
    {
        fast=fast->next;
        if(fast==NULL)
        {
            loop = 0;
            break;
        }
        fast=fast->next;
        if(fast==NULL)
        {
            loop = 0;
            break;
        }

        slow=slow->next;

        if(fast==slow)
        {
            loop = 1;
            break;
        }
    }
    if(loop)    cout<<"Loop Exists...";
    else        cout<<"Loop doesn't Exist...";

    // Determining Number of nodes in the loop...
    if(loop)
    {
        slow=slow->next;
        count++;
        while(slow!=fast)
        {
            count++;
            slow=slow->next;
        }
        cout<<"\nNo. of nodes present in the loop: "<<count;
    }

    // Determining the start of the loop...
    if(loop)
    {
        slow = start;
        while(slow!=fast)
        {
            fast=fast->next;
            slow=slow->next;
        }
        cout<<"\nStarting of the loop: "<<fast->data;
    }
}
