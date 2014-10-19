#include<iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}N;

static int preIndex=0;

int searchIndex(int inOrder[],int val,int a,int b){
    for(int i=a;i<=b;i++){
        if(inOrder[i]==val)
            return i;
    }
}

N *constructTree(int inOrder[],int preOrder[],int inStart,int inEnd){
    if(inStart>inEnd)   return NULL;
    N *newNode = new N;
    newNode->data = preOrder[preIndex++];
    newNode->left = NULL;
    newNode->right = NULL;
    if(inStart==inEnd)     // Node is Leaf Node...
        return newNode;
    int inIndex = searchIndex(inOrder,newNode->data,inStart,inEnd);

    newNode->left = constructTree(inOrder,preOrder,inStart,inIndex-1);
    newNode->right = constructTree(inOrder,preOrder,inIndex+1,inEnd);
    return newNode;
}

void display(N *root){
    if(!root)   return;
    display(root->left);
    cout<<root->data<<"  ";
    display(root->right);
}

int main(){
    int nodes;
    cout<<"Total Nodes in the tree: ";
    cin>>nodes;
    int inOrder[nodes],preOrder[nodes];
    cout<<"InOrder Traversal: ";
    for(int i=0;i<nodes;i++)    cin>>inOrder[i];
    cout<<"PreOrder Traversal: ";
    for(int i=0;i<nodes;i++)    cin>>preOrder[i];
    N *root = constructTree(inOrder,preOrder,0,nodes-1);
    cout<<"Tree Constructed is as follows: "<<endl;
    display(root);
    cout<<endl;
    return 0;
}
