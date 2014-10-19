#include <iostream>
#include <cmath>
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
		N *temp = deQueue(&front);
		cout<<temp->data<<"  ";
		if(temp->left)		enQueue(temp->left,&front,&rear);
		if(temp->right)		enQueue(temp->right,&front,&rear);
	}
	cout<<endl;
}
/*
void increment(N *root,int val){
	if(root->left){
		root->left->data += val;
		increment(root->left,val);
	}
	else if(root->right){
		root->right->data += val;
		increment(root->right,val);
	}
}
*/
void editTree(N *root){
	if(!root)	return;
	else if(!root->left && !root->right)	return;
	
	editTree(root->left);
	editTree(root->right);
	
	int leftData=0,rightData=0;
	if(root->left)		leftData = root->left->data;
	if(root->right)		rightData = root->right->data;
	int sum = leftData+rightData;
	int diff = sum - root->data;
	
	if(diff==0)			return;
	else if(diff>0)		root->data += diff;
	//~ else				increment(root,abs(diff));
	else{
		if(root->left){
			root->left->data += abs(diff);
			editTree(root->left);
		}
		else if(root->right){
			root->right->data += abs(diff);
			editTree(root->right);
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
    editTree(root);
    cout<<"Modified Tree according to the Children Sum Property: "<<endl;
    display(root);
    return 0;
}
