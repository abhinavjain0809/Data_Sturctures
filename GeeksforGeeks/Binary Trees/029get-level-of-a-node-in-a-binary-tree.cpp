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

int getLevelUtil(N *root,int key,int level){
	if(!root)	return 0;
	int l=0;
	if(root->data == key)	return level;
	else{
		l = getLevelUtil(root->left,key,level+1);
		if(l==0)	l = getLevelUtil(root->right,key,level+1);
	}
	return l;
}

int getLevel(N *root,int key){
	if(!root)	return 0;
	int level=1;
	return getLevelUtil(root,key,level);
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
    cout<<"Enter Node whose level is required: ";
    cin>>key;
    int level = getLevel(root,key);
	cout<<"Level of Node "<<key<<": "<<level<<endl;
    return 0;
}
