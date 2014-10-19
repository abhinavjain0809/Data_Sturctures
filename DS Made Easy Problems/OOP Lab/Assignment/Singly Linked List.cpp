#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}N;

N *create(void);
void display(N*);
void search(N*,int);

int main(void)
{
    N *list=NULL;
    int val;
    cout<<"Enter Data for List:\n";
    list = create();

    cout<<"\nThe List entered is:\n";
    display(list);

    cout<<"\n\nElement to look for: ";
    cin>>val;
    search(list,val);
    return 0;
}

N* create(void)
{
    N *start=NULL, *ptr, *temp;
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

void search(N *start, int val)
{
    N *ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->data==val){
            cout<<"Data Exists!!!";
            return;
        }
        ptr = ptr->next;
    }
    cout<<"Data Entry DOES NOT Exist!!!";
}
