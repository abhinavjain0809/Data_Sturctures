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
    Q *front=NULL,*rear=NULL;
    N *temp = new N;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    enQueue(root,&front,&rear);
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
    if(!root)   return;
    Q *front=NULL,*rear=NULL;
    enQueue(root,&front,&rear);
    while(!isQueueEmpty(front)){
        N *temp=deQueue(&front);
        cout<<temp->data<<"  ";
        if(temp->left)       enQueue(temp->left,&front,&rear);
        if(temp->right)      enQueue(temp->right,&front,&rear);
    }
}

void freeNode(N *temp,N *root){
    Q *front=NULL,*rear=NULL;
    enQueue(root,&front,&rear);
    if(root==temp){
        root=NULL;
        return;
    }
    while(!isQueueEmpty(front)){
        N *del = deQueue(&front);
        if(del->left){
            if(del->left==temp){
                del->left=NULL;
                return;
            }
            enQueue(del->left,&front,&rear);
        }
        if(del->right){
            if(del->right==temp){
                del->right=NULL;
                return;
            }
            enQueue(del->right,&front,&rear);
        }
    }
}

void deleteNode(N *root,int val){
    Q *front=NULL,*rear=NULL;
    N *delNode=NULL,*temp;
    if(!root)       return;
    enQueue(root,&front,&rear);
    while(!isQueueEmpty(front)){
        temp = deQueue(&front);
        if(temp->data==val)     delNode = temp;
        if(temp->left)       enQueue(temp->left,&front,&rear);
        if(temp->right)      enQueue(temp->right,&front,&rear);
    }
    //cout<<delNode->data<<"  "<<temp->data<<endl;
    if(delNode){
        delNode->data = temp->data;
        freeNode(temp,root);
    }
    else        cout<<"Data Entry doesn't exists!!"<<endl;
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
    cout<<"Node to delete: ";
    cin>>val;
    if(n==1 && root->data==val)         root=NULL;
    else if(n==1 && root->data!=val)    cout<<"Data doesn't exist!!"<<endl;
    else                                deleteNode(root,val);
    cout<<"Tree left"<<endl;
    display(root);
    return 0;
}
