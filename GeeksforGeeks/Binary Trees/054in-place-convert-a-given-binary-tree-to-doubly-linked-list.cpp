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

void convertToDLLUtil(N *root,N **head,N **prev){
    if(!root)   return;
    convertToDLLUtil(root->left,head,prev);

    root->left = *prev;
    if(!*head)   *head=root;
    else        (*prev)->right=root;
    *prev=root;

    convertToDLLUtil(root->right,head,prev);
}

N *convertToDLL(N *root){
    if(!root)   return NULL;
    N *head=NULL,*prev=NULL;
    convertToDLLUtil(root,&head,&prev);
    return head;
}

void displayDLL(N *head){
    N *ptr=head,*x=NULL;
    cout<<"List from beginning is:"<<endl;
    while(ptr){
        cout<<ptr->data<<"  ";
        x=ptr;
        ptr=ptr->right;
    }
    cout<<endl;
    cout<<"List from end is:"<<endl;
    while(x){
        cout<<x->data<<"  ";
        x=x->left;
    }
}

int main(){
    N *root = createTree();
    if(root){
		cout<<"Inorder Traversal of the Binary Tree:"<<endl;
		displayTree(root);
		cout<<endl;
	}
    N *head = convertToDLL(root);
    displayDLL(head);
	return 0;
}
