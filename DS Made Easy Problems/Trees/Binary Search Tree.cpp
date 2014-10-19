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
N *root=NULL;
void create(N*,int);
void inOrder(N*);

typedef struct Queue
{
    N *add;
    Queue *next;
}Q;
Q *front=NULL, *rear=NULL;
void levelOrder(N*);
void enQueue(N*);
N *deQueue();

int main(void)
{
    N *tree;
    int val;
    char ans = 'Y';
    while(toupper(ans)=='Y'){
        cout<<"Data: ";
        cin>>val;
        if(!root){
            root = new N;
            root->data = val;
            root->left = root->right = NULL;
        }
        else    create(root,val);

        cout<<"Insert more nodes(Y/N): ";
        cin>>ans;
    }
    cout<<"PreOrder Traversal:\n";
    inOrder(root);

    cout<<"\n\nLevelOrder Traversal:\n";
    levelOrder(root);
    return 0;
}

void create(N *root, int val)
{
    N* temp;
    temp = new N;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    if(val<root->data){
        if(!root->left)     root->left = temp;
        else                create(root->left,val);
    }

    else{
        if(!root->right)    root->right = temp;
        else                create(root->right,val);
    }
}

void inOrder(N *root)
{
    if(root){
        inOrder(root->left);
        cout<<root->data<<"\t";
        inOrder(root->right);
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
