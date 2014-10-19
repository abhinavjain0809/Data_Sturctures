#include<iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}N;

typedef struct queue{
    N *add;
    struct queue *next;
}Q;

void enQueue(N *data,Q **front,Q **rear){
    Q *temp = new Q;
    temp->add = data;
    temp->next = NULL;
    if(*front==NULL){
        *front = *rear = temp;
    }
    else{
        (*rear)->next=temp;
        *rear=temp;
    }
}

N* deQueue(Q **front){
    N *temp = (*front)->add;
    *front=(*front)->next;
    return temp;
}

bool isQueueEmpty(Q *front){
    if(front==NULL)     return true;
    return false;
}

void create(N *root,int val){
    N *temp = new N;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    if(root->data>val){
        if(!root->left)     root->left = temp;
        else                create(root->left,val);
    }
    else if(root->data<val){
        if(!root->right)    root->right = temp;
        else                create(root->right,val);
    }
}
/*
void display(N *root){
    if(!root)   return;
    display(root->left);
    cout<<root->data<<"  ";
    display(root->right);
}
*/
void display(N *root){
    Q *front=NULL,*rear=NULL;
    enQueue(root,&front,&rear);
    while(!isQueueEmpty(front)){
        N *temp=deQueue(&front);
        cout<<temp->data<<"  ";
        if(temp->left)       enQueue(temp->left,&front,&rear);
        if(temp->right)      enQueue(temp->right,&front,&rear);
    }
}

int main(){
    int n,val;
    cout<<"Total nodes: ";
    cin>>n;
    cout<<"Data for Root: ";
    cin>>val;
    N *root = new N;
    root->data = val;
    root->left = NULL;
    root->right = NULL;
    if(n>1){
        cout<<"Data for other nodes: ";
        for(int i=1;i<n;i++){
            cin>>val;
            create(root,val);
        }
    }
    cout<<"Binary Search Tree:"<<endl;
    display(root);
    cout<<endl;
    return 0;
}
