#include <iostream>
#include <queue>
using namespace std;

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
    struct node *nextRight;
}N;

N *createTree(){
	int val,n;
    cout<<"Enter total number of nodes: ";
    cin>>n;
    if(n==0)	return NULL;
    cout<<"Enter Values starting from root: ";
    cin>>val;
    queue<N*> q;
    N *root = new N;
    root->data = val;
	root->left = NULL;
	root->right = NULL;
	root->nextRight = NULL;
	for(int i=1;i<n;i++){
		q.push(root);
		cin>>val;
		N *newNode = new N;
		newNode->data = val;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->nextRight = NULL;
		while(!q.empty()){
			N *temp = q.front();
			q.pop();
			if(!temp->left){
				temp->left = newNode;
				break;
			}
			else if(!temp->right){
				temp->right = newNode;
				break;
			}
			q.push(temp->left);
			q.push(temp->right);
		}
		while(!q.empty())
			q.pop();
	}
	return root;
}

void display(N *root){
	queue<N*> q;
	q.push(root);
	while(!q.empty()){
		N *temp = q.front();
		q.pop();
		cout<<temp->data<<"  ";
		if(temp->nextRight)	cout<<temp->nextRight->data<<endl;
		else				cout<<"NULL"<<endl;
		if(temp->left)		q.push(temp->left);
		if(temp->right)		q.push(temp->right);
	}
	cout<<endl;
}

N *connect(N *root){
	if(!root)	return root;
	queue<N*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		N *temp = q.front();
		q.pop();
		
		if(!temp){
			if(!q.empty())	q.push(NULL);
		}
		else{
			temp->nextRight = q.front();
			if(temp->left)		q.push(temp->left);
			if(temp->right)		q.push(temp->right);
		}
	}
	return root;
}

int main(){
    N *root = createTree();
    if(root){
		cout<<"Binary Tree:"<<endl;
		display(root);
	}
	cout<<"Tree after connecting:"<<endl;
	root = connect(root);
	display(root);
	return 0;
}
