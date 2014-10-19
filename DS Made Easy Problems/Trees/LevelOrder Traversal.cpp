#include<iostream>
#include<stdlib.h>
#include<ctype.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}N;
N *start=NULL;

typedef struct Queue
{
    N *add;
    Queue *next;
}Q;
Q *front=NULL, *rear=NULL;
void createtree(int n,N *st)
{
     if(n<st->data)
     {
         if(!st->left)
         {
             st->left=new N;
             st->left->data=n;
             st->left->left=st->left->right=NULL;
         }
         else createtree(n,st->left);
     }
     else
     {
         if(!st->right)
         {
             st->right=new N;
             st->right->data=n;
             st->right->left=st->right->right=NULL;
         }
         else createtree(n,st->right);
     }
}

void enQueue(N *n)
{
    Q *temp;
    temp = new Q;
    temp->add = n;
    temp->next = NULL;
    if(!front)      front = rear = temp;
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

N* deQueue()
{
    N* n;
    n = front->add;
    if(front==rear)     front = rear = NULL;
    else                front = front->next;
    return n;
}

void levelOrder(N *root)
{
    N* temp;
    enQueue(root);
    while(front){
        temp = deQueue();
        cout<<temp->data<<"\t";
        if(temp->left)      enQueue(temp->left);
        if(temp->right)      enQueue(temp->right);
    }
}

int main()
{
    char ch='Y';
    int n;
    while(toupper(ch)=='Y')
          {
              cout<<"\nenter the data: ";
              cin>>n;
              if(!start)
              {
                  start=new N;
                  start->data=n;
                  start->left=start->right=NULL;
              }
              else    createtree(n,start);
              cout<<"want to create more nodes? ";
              cin>>ch;
          }

    cout<<"Printing Tree: \n";
    levelOrder(start);
          return 0;
}
