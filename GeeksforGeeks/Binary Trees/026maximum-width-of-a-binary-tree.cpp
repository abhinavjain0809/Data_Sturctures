#include <iostream>
#include <climits>
#include <cstdlib>
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
		cout<<temp->data<<"  ";
		if(temp->left)		q.push(temp->left);
		if(temp->right)		q.push(temp->right);
	}
	cout<<endl;
}

int getWidth(N *root){
	int width=0,max=INT_MIN;
	queue<N*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		N *temp = q.front();
		q.pop();
		if(temp==NULL){
			if(!q.empty())	q.push(NULL);
			if(width > max)		max = width;
			width=0;
		}
		else{
			width++;
			if(temp->left)		q.push(temp->left);
			if(temp->right)		q.push(temp->right);
		}
	}
	return max;
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
    int width = getWidth(root);
	cout<<"Maximum Width of the tree: "<<width<<endl;
    return 0;
}
