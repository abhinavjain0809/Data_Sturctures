#include <iostream>
#include <climits>
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

void getRange(N *root,int n,int *min,int *max){
    if(!root)   return;
    if(*max < n)     *max = n;
    if(*min > n)     *min = n;
    getRange(root->left,n-1,min,max);
    getRange(root->right,n+1,min,max);
}

void verticalSum(N *root,int level,int n,int *sum){
    if(!root)   return;
    if(level==n){
        *sum += root->data;
    }
    verticalSum(root->left,level,n-1,sum);
    verticalSum(root->right,level,n+1,sum);
}

int main(){
    N *root = createTree();
    if(root){
		cout<<"Binary Tree:"<<endl;
		display(root);
	}
	cout<<"Vertical Traversal of the tree:"<<endl;
    int min=INT_MAX,max=INT_MIN;
    getRange(root,0,&min,&max);
	for(int i=min;i<=max;i++){
        int sum=0;
        verticalSum(root,i,0,&sum);
        cout<<"Level "<<i<<": "<<sum<<endl;
    }
	return 0;
}
