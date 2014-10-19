#include <iostream>
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
    cout<<endl;
}

int max(int a,int b){
	return (a>b ? a:b);
}

int getHeight(N *root){
	if(!root)	return 0;
	int lh = getHeight(root->left);
	int rh = getHeight(root->right);
	return max(lh,rh)+1;
}

void print(int *path,int pathLen){
	for(int i=0;i<pathLen-1;i++)
		cout<<path[i]<<" -> ";
	cout<<path[pathLen-1];
	cout<<endl;
}

void printPathRec(N *root,int *path,int pathLen){
	if(!root)		return;
	path[pathLen++] = root->data;
	if(!root->left && !root->right){
		print(path,pathLen);
		return;
	}
	printPathRec(root->left,path,pathLen);
	printPathRec(root->right,path,pathLen);
}

void printPath(N *root){
	int pathLen=0;
	int n = getHeight(root);
	int path[n];
	printPathRec(root,path,pathLen);
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
    cout<<"Root to Leaf Paths: "<<endl;
    printPath(root);
    return 0;
}
