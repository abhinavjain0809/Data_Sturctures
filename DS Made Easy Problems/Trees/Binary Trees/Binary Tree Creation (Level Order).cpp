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
    //cout<<"Data to be enQueued: "<<data<<endl;
    Q *temp = new Q;
    temp->add = data;
    temp->next = NULL;
    if(*front==NULL){
        //cout<<"Front is NULL"<<endl;
        *front = *rear = temp;
    }
    else{
        //cout<<"Front is not NULL"<<endl;
        (*rear)->next=temp;
        *rear=temp;
    }
    //cout<<"--------------------------------------"<<endl;
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

/*
void printQueue(Q *front){
    Q *ptr=front;
    cout<<"Current Queue"<<endl;
    while(ptr!=NULL){
        cout<<ptr->add<<"  ";
        ptr=ptr->next;
    }
    cout<<endl;
}
*/

void create(N *root,int val){
    Q *front=NULL,*rear=NULL;
    N *temp = new N;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    enQueue(root,&front,&rear);
    //printQueue(front);
    while(!isQueueEmpty(front)){
        N *newNode = deQueue(&front);
        if(!newNode->left){
            newNode->left = temp;
            return;
        }
        else if(!newNode->right){
            newNode->right = temp;
            return;
        }
        enQueue(newNode->left,&front,&rear);
        enQueue(newNode->right,&front,&rear);
    }
}

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
    cout<<"Enter total number of nodes: ";
    cin>>n;
    cout<<"Root Data: ";
    cin>>val;
    N *root = new N;
    root->data = val;
    root->left = NULL;
    root->right = NULL;
    //cout<<"Root Adress: "<<root<<endl;
    if(n>1){
        cout<<"Enter data for rest of the nodes: ";
        for(int i=1;i<n;i++){
            cin>>val;
            create(root,val);
        }
    }
    cout<<"Binary Tree:"<<endl;
    display(root);
    cout<<endl;
    return 0;
}
