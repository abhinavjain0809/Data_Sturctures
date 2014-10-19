#include <iostream>
#include <stack>
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

void spiralOrder(N *root){
	stack<N*> s1;
	stack<N*> s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty()){
		while(!s1.empty()){
			N *temp = s1.top();
			s1.pop();
			cout<<temp->data<<"  ";
			if(temp->right)		s2.push(temp->right);
			if(temp->left)		s2.push(temp->left);
		}
		while(!s2.empty()){
			N *temp = s2.top();
			s2.pop();
			cout<<temp->data<<"  ";
			if(temp->left)		s1.push(temp->left);
			if(temp->right)		s1.push(temp->right);
		}
	}
    cout<<endl;
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
    cout<<"Spiral Traversal of Tree:"<<endl;
    spiralOrder(root);
    return 0;
}
