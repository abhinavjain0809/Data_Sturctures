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

typedef struct stack{
    N *add;
    struct stack *next;
}S;

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
    Q *front=NULL,*rear=NULL;
    enQueue(root,&front,&rear);
    while(!isQueueEmpty(front)){
        N *temp=deQueue(&front);
        cout<<temp->data<<"  ";
        if(temp->left)       enQueue(temp->left,&front,&rear);
        if(temp->right)      enQueue(temp->right,&front,&rear);
    }
}

void push(N *data,S **top){
    S *temp = new S;
    temp->add = data;
    temp->next = NULL;
    if(*top==NULL){
        *top = temp;
    }
    else{
        temp->next = *top;
        *top = temp;
    }
}

N *pop(S **top){
    N *temp = (*top)->add;
    (*top) = (*top)->next;
    return temp;
}

bool isStackEmpty(S *top){
    if(!top)   return true;
    return false;
}

void zigzag(N *root){
    S *top1=NULL,*top2=NULL;
    push(root,&top1);
    while(!isStackEmpty(top1) || !isStackEmpty(top2)){
        while(!isStackEmpty(top1)){
            N *temp = pop(&top1);
            cout<<temp->data<<"  ";
            if(temp->left)       push(temp->left,&top2);
            if(temp->right)      push(temp->right,&top2);
        }

        while(!isStackEmpty(top2)){
            N *temp = pop(&top2);
            cout<<temp->data<<"  ";
            if(temp->right)      push(temp->right,&top1);
            if(temp->left)       push(temp->left,&top1);
        }
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
    if(n>1){
        cout<<"Enter data for rest of the nodes: ";
        for(int i=1;i<n;i++){
            cin>>val;
            create(root,val);
        }
    }
    cout<<"Binary Tree:"<<endl;
    display(root);
    cout<<endl<<endl;
    cout<<"Zig Zag Traversal of the Binary Tree:"<<endl;
    zigzag(root);
    return 0;
}
