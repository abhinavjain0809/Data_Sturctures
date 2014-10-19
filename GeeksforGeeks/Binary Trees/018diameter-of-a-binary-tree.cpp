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
/*
int height(N *root){
	if(!root)	return 0;
	
	int lh = height(root->left);
	int rh = height(root->right);
	
	return (1+max(lh,rh));
}

int diameter(N *root){
	if(!root)	return 0;
	
	int lh = height(root->left);
	int rh = height(root->right);
	
	int ld = diameter(root->left);
	int rd = diameter(root->right);
	
	return max(lh+rh+1,max(ld,rd));
}
*/

int diameter(N *root,int *height){
	if(!root){
		*height=0;
		return 0;
	}
	int lh=0,rh=0;
	int ld = diameter(root->left,&lh);
	int rd = diameter(root->right,&rh);
	
	*height = max(lh,rh)+1;
	
	return max(lh+rh+1,max(ld,rd));
}

int main(){
    N *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->right = newNode(7);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(6);
    cout<<"Binary Tree:"<<endl;
    display(root);
    cout<<endl;
    int height=0;
    int d = diameter(root,&height);
    cout<<"Diameter: "<<d<<endl;
    return 0;
}
