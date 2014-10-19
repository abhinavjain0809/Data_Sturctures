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

void printPath(int path[],int pathlen){
    int i;
    for(i=0;i<pathlen-1;i++)      cout<<path[i]<<" --> ";
    cout<<path[i]<<endl;
}

bool pathsRec(N *root,int path[],int pathlen,int sum){
    if(!root){
        if(sum==0){
            cout<<"Path FOUND!!"<<endl;
            printPath(path,pathlen);
            return true;
        }
        return false;
    }
    path[pathlen++]=root->data;
    int leftSum = sum - root->data;
    bool ans = false;
    if(leftSum==0){
        cout<<"Path FOUND!!"<<endl;
        printPath(path,pathlen);
        return true;
    }
    if(root->left)
        ans = ans || pathsRec(root->left,path,pathlen,leftSum);
    if(root->right)
        ans = ans || pathsRec(root->right,path,pathlen,leftSum);

    return ans;
}

void givenSum(N *root,int sum){
    int path[1000];
    int pathlen=0;
    bool y=pathsRec(root,path,pathlen,sum);
    if(y==false)
        cout<<"No path with given sum exists!!!"<<endl;
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
    int sum;
    cout<<"Required Sum: "<<endl;
    cin>>sum;
    givenSum(root,sum);
    return 0;
}
