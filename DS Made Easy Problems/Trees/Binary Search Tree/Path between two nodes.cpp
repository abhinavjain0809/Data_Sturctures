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

int netPath[1000],x=0;
static int k=0;

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

N *findNode(N *root,int val){
    if(!root)   return NULL;
    if(root->data>val)      return findNode(root->left,val);
    else if(root->data<val)      return findNode(root->right,val);
    else    return root;
}

N *LCA(N *root,N *node1,N *node2){
    if(!root)   return NULL;
    if(root==node1 || root==node2)      return root;
    else if((root->data>node1->data && root->data<node2->data) || (root->data<node1->data && root->data>node2->data))
        return root;
    else if((root->data>node1->data && root->data>node2->data))     return LCA(root->left,node1,node2);
    else if((root->data<node1->data && root->data<node2->data))     return LCA(root->right,node1,node2);
}

void printPath(int path[],int pathlen){
    if(x==0){
        for(int i=0;i<pathlen;i++){
            netPath[k++] = path[pathlen-i-1];
        }
        x=1;
    }
    else if(x==1){
        for(int i=0;i<pathlen;i++){
            netPath[k++] = path[i];
        }
    }
}

void pathsRec(N *root,N *node,int path[],int pathlen){
    if(!root)       return;
    if(root==node){
        printPath(path,pathlen);
        return;
    }
    path[pathlen++] = root->data;
    /*if(root->data<node->data)*/        pathsRec(root->left,node,path,pathlen);
    /*else if(root->data>node->data)*/   pathsRec(root->right,node,path,pathlen);
}

void ancestors(N *root,N *node){
    if(!root)   return;
    int path[1000];
    int pathlen=0;
    pathsRec(root,node,path,pathlen);
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
    int a,b;
    cout<<"Enter nodes: ";
    cin>>a>>b;
    N *node1 = findNode(root,a);
    N *node2 = findNode(root,b);
    if(node1 && node2){
        N *lca = LCA(root,node1,node2);
        ancestors(lca,node1);
        ancestors(lca,node2);
        cout<<endl;
        cout<<"Path between given nodes is: ";
        cout<<node1->data<<"  ";
        for(int i=0;i<k;i++){
            if(netPath[i]==netPath[i+1]){
                continue;
            }
            cout<<netPath[i]<<"  ";
        }
        cout<<node2->data<<endl;
    }
    else    cout<<"Enter VALID Nodes!!"<<endl;
    return 0;
}
