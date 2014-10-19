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

N *findMax(N *root){
    if(!root->right)    return root;
    findMax(root->right);
}

N *findMin(N *root){
    if(!root->left)    return root;
    findMin(root->left);
}

N *findNode(N *root,int val){
    if(!root)   return NULL;
    if(root->data==val)         return root;
    else if(root->data>val)     return findNode(root->left,val);
    else if(root->data<val)     return findNode(root->right,val);
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
    N *max = findMax(root);
    cout<<"Maximum Element: "<<max->data<<endl;
    N *min = findMin(root);
    cout<<"Minimum Element: "<<min->data<<endl;

    cout<<"Enter node to search: ";
    cin>>val;
    N *result = findNode(root,val);
    if(result)      cout<<"Node EXISTS!!"<<endl;
    else            cout<<"Node NOT FOUND!!"<<endl;
    return 0;
}
