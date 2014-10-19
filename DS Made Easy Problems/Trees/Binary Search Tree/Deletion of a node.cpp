#include<iostream>
#include<cstdlib>
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

void findNode(N **,int);

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

void deleteNode(N **root,int val){
    if(!*root)       return;
    N *temp = *root;
    if(!(*root)->left){
        *root = (*root)->right;
        delete temp;
    }
    else if(!(*root)->right){
        *root = (*root)->left;
        delete temp;
    }
    else{
        temp = (*root)->left;
        while(temp->right)      temp = temp->right;
        (*root)->data = temp->data;
        findNode(&(*root)->left,temp->data);
    }
}

void findNode(N **root,int val){
    if(!(*root))   return;
    if((*root)->data>val)           findNode(&(*root)->left,val);
    else if((*root)->data<val)      findNode(&(*root)->right,val);
    else                            deleteNode(&*root,val);
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
    cout<<"Node to Delete: ";
    cin>>val;
    findNode(&root,val);
    cout<<"Updated Tree: "<<endl;
    display(root);
    cout<<endl;
    return 0;
}
