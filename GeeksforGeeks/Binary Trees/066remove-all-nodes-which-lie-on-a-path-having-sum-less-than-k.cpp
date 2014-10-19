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
    queue<N*> q;
    q.push(root);
    while(!q.empty()){
        N *temp = q.front();
        q.pop();
        cout<<temp->data<<"  ";
        if(temp->left)      q.push(temp->left);
        if(temp->right)      q.push(temp->right);
    }
}

N* newNode(int data){
    N* node = new N;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

N *pruneUtil(N *root,int k,int sum){
    if(!root)   return NULL;
    sum += root->data;
    root->left = pruneUtil(root->left,k,sum);
    root->right = pruneUtil(root->right,k,sum);

    if(!root->left && !root->right){
        if(sum < k){
            delete root;
            return NULL;
        }
    }

    return root;
}

N *prune(N *root,int k){
    if(!root)   return NULL;
    int sum=0;
    return pruneUtil(root,k,sum);
}

int main(){
    int k = 45;
    N *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(12);
    root->right->right->left = newNode(10);
    root->right->right->left->right = newNode(11);
    root->left->left->right->left = newNode(13);
    root->left->left->right->right = newNode(14);
    root->left->left->right->right->left = newNode(15);
    //N *root = createTree();
    if(root){
		cout<<"Binary Tree:"<<endl;
		displayTree(root);
		cout<<endl;
	}

    root = prune(root,k);
    cout<<"Modified Tree: "<<endl;
    if(root)    displayTree(root);
    else        cout<<"Empty Tree";
    cout<<endl;
	return 0;
}
