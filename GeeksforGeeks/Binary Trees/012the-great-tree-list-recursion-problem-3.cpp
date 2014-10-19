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

void displayList(N *head){
    if(head){
        cout<<head->data<<"  ";
        N *ptr=head->right;
        while(ptr!=head){
            cout<<ptr->data<<"  ";
            ptr = ptr->right;
        }
    }
}

void greatTree(N *root,N **head,N **prev){
    if(!root)   return;
    greatTree(root->left,head,prev);

    if(!*head)      *head=root;
    else            (*prev)->right = root;
    root->left = *prev;
    *prev = root;

    greatTree(root->right,head,prev);
}

N *greatTreeRecursion(N *root){
    N *head=NULL,*prev=NULL;
    greatTree(root,&head,&prev);

    head->left = prev;
    prev->right = head;

    return head;
}

int main(){
    //N *root = newNode(1);
    N *root = createTree();
    if(root){
		cout<<"Binary Tree:"<<endl;
		displayTree(root);
		cout<<endl;
	}
    N *head = greatTreeRecursion(root);
    root=NULL;      // For deleting the dangling pointer to the tree...
    cout<<"Circular List:"<<endl;
    displayList(head);
    return 0;
}
