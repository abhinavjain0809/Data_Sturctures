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

void displayTree(N *root){
	if(!root)   return;
	displayTree(root->left);
	cout<<root->data<<"  ";
	displayTree(root->right);
}

void printLeftView(N *root){
    if(!root)   return;
    queue<N*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        //cout<<"Near the core!!"<<endl;
        N *temp = q.front();
        q.pop();
        if(!temp){
            //cout<<"IN the core!!"<<endl;
            if(!q.empty())      q.push(NULL);
            N *ptr=NULL;
            if(!q.empty())      ptr = q.front();
            if(ptr)     cout<<ptr->data<<"  ";
        }
        else{
            if(temp->left)       q.push(temp->left);
            if(temp->right)      q.push(temp->right);
        }
    }
}

N *newNode(int val){
    N *temp = new N;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int main(){
    N *root = createTree();
    if(root){
		cout<<"Inorder Traversal of the Binary Tree:"<<endl;
		displayTree(root);
		cout<<endl;
	}
	/*N *root = newNode(12);
	root->left = newNode(10);
	root->right = newNode(30);
	root->right->left = newNode(25);
	root->right->right = newNode(40);*/
	cout<<"Left View of the Tree:"<<endl;
	cout<<root->data<<"  ";
    printLeftView(root);
    return 0;
}
