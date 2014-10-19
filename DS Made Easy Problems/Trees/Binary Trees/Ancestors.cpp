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
    Q *front=NULL,*rear=NULL;
    enQueue(root,&front,&rear);
    while(!isQueueEmpty(front)){
        N *temp=deQueue(&front);
        cout<<temp->data<<"  ";
        if(temp->left)       enQueue(temp->left,&front,&rear);
        if(temp->right)      enQueue(temp->right,&front,&rear);
    }
}

N *findNode(N *root,int val){
    Q *front=NULL,*rear=NULL;
    enQueue(root,&front,&rear);
    while(!isQueueEmpty(front)){
        N *temp = deQueue(&front);
        if(temp->data==val)     return temp;
        if(temp->left)          enQueue(temp->left,&front,&rear);
        if(temp->right)          enQueue(temp->right,&front,&rear);
    }
    return NULL;
}

void printPath(int path[],int pathlen){
    cout<<"\nAncestors of the given node are: ";
    for(int i=0;i<pathlen;i++)      cout<<path[i]<<"  ";
    cout<<endl;
}

void pathsRec(N *root,N *reqNode,int path[],int pathlen){
    if(!root)       return;
    path[pathlen++] = root->data;
    if(root==reqNode){
        printPath(path,pathlen);
        return;
    }
    pathsRec(root->left,reqNode,path,pathlen);
    pathsRec(root->right,reqNode,path,pathlen);
}

void ancestors(N *root,int val){
    int path[1000];
    int pathlen=0;
    N *reqNode = findNode(root,val);
    if(reqNode)     pathsRec(root,reqNode,path,pathlen);
    else            cout<<"Node DOES NOT EXIST!!"<<endl;
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
    cout<<"\nNode for which Ancestors are to be determined: ";
    cin>>val;
    ancestors(root,val);
    return 0;
}
