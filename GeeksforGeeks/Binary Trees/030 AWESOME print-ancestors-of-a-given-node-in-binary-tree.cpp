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

bool ancestors(N *root,int key){
	if(!root)	return false;
	if(root->data == key){
		return true;
	}
	
	if(ancestors(root->left,key) || ancestors(root->right,key)){
		cout<<root->data<<"  ";
		return true;
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
    int key=0;
    cout<<"Enter Node whose ancestors are required so as to kill them back in time resulting in conflictions in the node's existence in presence 3:): ";
    cin>>key;
    bool ans = ancestors(root,key);
    if(!ans)	cout<<"Node NOT FOUND!!"<<endl;
    cout<<endl;
    return 0;
}
