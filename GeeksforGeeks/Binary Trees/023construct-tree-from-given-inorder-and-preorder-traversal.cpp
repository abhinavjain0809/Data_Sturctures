#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}N;

N *newNode(int val){
	N *temp = new N;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}

int find(int a[],int x,int y,int key){
	for(int i=x;i<=y;i++)
		if(a[i]==key)	return i;
	return -1;
}

N *makeTree(int inOrder[],int preOrder[],int inStart,int inEnd){
	static int preIndex=0;
	if(inStart > inEnd)		return NULL;
	N *temp = newNode(preOrder[preIndex++]);
	if(inStart == inEnd)	return temp;
	
	int inIndex = find(inOrder,inStart,inEnd,temp->data);
	temp->left  = makeTree(inOrder,preOrder,inStart,inIndex-1);
	temp->right = makeTree(inOrder,preOrder,inIndex+1,inEnd);
	return temp;
}

void display(N *root){
	if(!root)	return;
	display(root->left);
	cout<<root->data<<"  ";
	display(root->right);
}

int main(){
    int n;
    cout<<"Enter total number of nodes: ";
    cin>>n;
    int inOrder[n],preOrder[n];
    cout<<"InOrder Traversal: "<<endl;
    for(int i=0;i<n;i++)	cin>>inOrder[i];
    cout<<"PreOrder Traversal: "<<endl;
    for(int i=0;i<n;i++)	cin>>preOrder[i];
    N *root = makeTree(inOrder,preOrder,0,n-1);
    display(root);
    cout<<endl;
    return 0;
}
