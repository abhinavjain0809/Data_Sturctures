#include<iostream>
#include<cstdlib>
#include<queue>
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
	if(!newNode){
		cout<<"Memory Overflow"<<endl;
		exit(1);
	}
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
		cout<<temp->data<<"\t";
		if(temp->left)		q.push(temp->left);
		if(temp->right)		q.push(temp->right);
	}
	cout<<endl;
}

int main(){
	int n,val;
	cout<<"Number of nodes: ";
	cin>>n;
	cout<<"Data for root: ";
	cin>>val;
	N *root = new N;
	root->data =  val;
	root->left = NULL;
	root->right = NULL;
	cout<<"Data for other nodes: ";
	for(int i=1;i<n;i++){
		cin>>val;
		create(root,val);
	}
	cout<<"Created Tree:"<<endl;
	display(root);
	return 0;
}
