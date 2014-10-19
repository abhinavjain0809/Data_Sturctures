#include<iostream>
using namespace std;

typedef struct node{
    int data;
    int num;
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
    temp->num = 0;
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
/*
void displayNumbering(N *root){
    Q *front=NULL,*rear=NULL;
    enQueue(root,&front,&rear);
    while(!isQueueEmpty(front)){
        N *temp=deQueue(&front);
        cout<<temp->num<<"  ";
        if(temp->left)       enQueue(temp->left,&front,&rear);
        if(temp->right)      enQueue(temp->right,&front,&rear);
    }
}
*/
void vNumbering(N **root,int n){
    if(!(*root))    return;
    (*root)->num = n;
    vNumbering(&(*root)->left,n-1);
    vNumbering(&(*root)->right,n+1);
}

void vSum(N *root,int level,int *sum){
    if(!root)    return;
    if(root->num==level)    *sum += root->data;
    vSum(root->left,level,&*sum);
    vSum(root->right,level,&*sum);
}

void getRange(N *root,int *min,int *max){
    if(!root)   return;
    int level = root->num;
    if(*min>level)           *min = level;
    else if(*max<level)      *max = level;
    getRange(root->left,&*min,&*max);
    getRange(root->right,&*min,&*max);
}

int main(){
    int n,val;
    cout<<"Enter total number of nodes: ";
    cin>>n;
    cout<<"Root Data: ";
    cin>>val;
    N *root = new N;
    root->data = val;
    root->num = 0;
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
    vNumbering(&root,0);
    //displayNumbering(root);
    int min=999,max=-999;
    getRange(root,&min,&max);
    //cout<<min<<"  "<<max<<endl;
    cout<<"Vertical Summations are as follows:"<<endl;
    for(int i=min;i<=max;i++){
        int sum=0;
        vSum(root,i,&sum);
        cout<<sum<<endl;
    }
    return 0;
}
