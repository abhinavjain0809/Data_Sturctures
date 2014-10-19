#include<iostream>
using namespace std;

typedef struct node{
	int data;
	struct node *right;
	struct node *down;
}N;

void push (N** head_ref, int new_data)
{
    /* allocate node */
    N* new_node = new N;
    new_node->right = NULL;
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->down = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

void display(N *start){
	N *ptr = start;
	while(ptr){
		cout<<ptr->data<<"  ";
		ptr = ptr->down;
	}
	cout<<endl;
}

N *merge(N *a,N *b){
	N *res=NULL;
	if(!a)		return b;
	else if(!b)	return a;
	
	if(a->data <= b->data){
		res = a;
		res->down = merge(a->down,b);
	}
	else{
		res = b;
		res->down = merge(a,b->down);
	}
	return res;
}

N *flatten(N *root){
	if(!root || !root->down)	return root;
	
	return merge(root,flatten(root->right));
}

int main(){
	N* root = NULL;
 
    /* Let us create the following linked list
       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
    */
    push( &root, 30 );
    push( &root, 8 );
    push( &root, 7 );
    push( &root, 5 );
 
    push( &( root->right ), 20 );
    push( &( root->right ), 10 );
 
    push( &( root->right->right ), 50 );
    push( &( root->right->right ), 22 );
    push( &( root->right->right ), 19 );
 
    push( &( root->right->right->right ), 45 );
    push( &( root->right->right->right ), 40 );
    push( &( root->right->right->right ), 35 );
    push( &( root->right->right->right ), 20 );
	
	root = flatten(root);
	display(root);
	return 0;
}
