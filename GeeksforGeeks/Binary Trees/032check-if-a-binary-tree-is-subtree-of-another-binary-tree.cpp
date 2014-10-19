#include <iostream>
#include <queue>
using namespace std;

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
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
	for(int i=1;i<n;i++){
		q.push(root);
		cin>>val;
		N *newNode = new N;
		newNode->data = val;
		newNode->left = NULL;
		newNode->right = NULL;
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
		if(temp->left)		q.push(temp->left);
		if(temp->right)		q.push(temp->right);
	}
	cout<<endl;
}

bool areIdentical(N *root1,N *root2){
	if(!root1 && !root2)		return true;
	else if(!root1 || !root2)	return false;
	
	return (root1->data == root2->data && areIdentical(root1->left,root2->left) && areIdentical(root1->right,root2->right));
}

bool isSubTree(N *T,N *S){
	if(!S)		return true;
	else if(!T)	return false;
	
	if(areIdentical(T,S))	return true;
	
	return (isSubTree(T->left,S) || isSubTree(T->right,S));
}

int main(){
    N *root1 = createTree();
    if(root1){
		cout<<"Binary Tree:"<<endl;
		display(root1);
	}
	N *root2 = createTree();
    if(root2){
		cout<<"Binary Tree:"<<endl;
		display(root2);
	}
	
	if(isSubTree(root1,root2))		cout<<"Tree 2 is a subtree of Tree 1"<<endl;
	else							cout<<"Tree 2 is NOT a subtree of Tree 1"<<endl;
	return 0;
}
