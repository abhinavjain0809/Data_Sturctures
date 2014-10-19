#include <iostream>
#include <cmath>
using namespace std;

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}N;

void display(N *root){
	if(!root)	return;
	display(root->left);
	cout<<root->data<<"  ";
	display(root->right);
}

N *newNode(int val){
	N *temp = new N;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int max(int a,int b){
	return (a>b ? a:b);
}

bool isBal(N *root,int *height){
	if(!root){
		*height=0;
		return true;
	}
	int lh=0,rh=0;
	int l = isBal(root->left,&lh);
	int r = isBal(root->right,&rh);
	
	*height = max(lh,rh)+1;
	if(abs(lh-rh)>1)	return false;
	return l&&r;
}

int main(){
    N *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    //~ root->right->right = newNode(7);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(6);
/*    root->left = newNode(2);
	root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->left->left->left = newNode(7);*/
    cout<<"Binary Tree:"<<endl;
    display(root);
    cout<<endl;
    int height=0;
    if(isBal(root,&height))		cout<<"Tree is Balanced..."<<endl;
    else						cout<<"Tree is NOT Balanced!!!"<<endl;
    return 0;
}
