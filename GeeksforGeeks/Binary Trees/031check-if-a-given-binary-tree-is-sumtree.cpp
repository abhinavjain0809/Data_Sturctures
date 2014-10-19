#include <iostream>
#include <queue>
using namespace std;

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}N;

void create(N *root,int val){
	queue<N*> q;
	q.push(root);
	N *newNode = new N;
	newNode->data = val;
	newNode->left = NULL;
	newNode->right = NULL;
	while(!q.empty()){
		N *temp = q.front();
		q.pop();
		if(!temp->left){
			temp->left = newNode;
			return;
		}
		else if(!temp->right){
			temp->right = newNode;
			return;
		}
		q.push(temp->left);
		q.push(temp->right);
	}
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

bool isLeaf(N *root){
	if(!root)	return false;
	else if(!root->left && !root->right)	return true;
	return false;
}

bool isSumTree(N *root){
	if(!root || (!root->left && !root->right))		return true;
	int lSum=0,rSum=0;
	if(isSumTree(root->left) && isSumTree(root->right)){
		if(!root->left)		lSum=0;
		else if(isLeaf(root->left))	lSum=root->left->data;
		else	lSum = 2*(root->left->data);

		if(!root->right)		rSum=0;
		else if(isLeaf(root->right))	rSum=root->right->data;
		else	rSum = 2*(root->right->data);
		
		return (root->data == (lSum+rSum));
	}
	return false;
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
    if(isSumTree(root))		cout<<"Given Tree is Sum Tree..."<<endl;
    else					cout<<"Given Tree is NOT a Sum Tree!!"<<endl;
    return 0;
}
