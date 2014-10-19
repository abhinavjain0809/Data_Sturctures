#include<iostream>
#include<cstdlib>
using namespace std;

static int postIndex;
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}N;

int findIndex(int inOrder[],int val,int a,int b){
	for(int i=a;i<=b;i++){
		if(inOrder[i]==val)		return i;
	}
	cout<<"Invalid Sequences"<<endl;
	exit(1);
}

N *constructTree(int inOrder[],int postOrder[],int inStart,int inEnd){
	if(inStart > inEnd)		return NULL;
	N *newNode = new N;
	newNode->data = postOrder[postIndex--];
	newNode->left = NULL;
	newNode->right = NULL;
	if(inStart == inEnd)	return newNode;
	int inIndex = findIndex(inOrder,newNode->data,inStart,inEnd);
	newNode->right = constructTree(inOrder,postOrder,inIndex+1,inEnd);
	newNode->left = constructTree(inOrder,postOrder,inStart,inIndex-1);
	return newNode;
}

void display(N *root){
	if(!root)	return;
	display(root->left);
	cout<<root->data<<"\t";
	display(root->right);
}

int main(){
	int nodes;
	cout<<"Number of nodes: ";
	cin>>nodes;
	postIndex = nodes-1;
	int inOrder[nodes],postOrder[nodes];
	cout<<"Inorder Traversal: ";
	for(int i=0;i<nodes;i++)		cin>>inOrder[i];
	cout<<"Postorder Traversal: ";
	for(int i=0;i<nodes;i++)		cin>>postOrder[i];
	N *root = constructTree(inOrder,postOrder,0,nodes-1);
	cout<<"Tree formed: "<<endl;
	display(root);
	cout<<endl;
	return 0;
}
