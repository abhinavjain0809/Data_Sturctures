#include<iostream>
#include<algorithm>
using namespace std;

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}N;

N *arrayToBST(int a[],int start,int end){
    if(start>end)   return NULL;
    int mid = (start+end)/2;
    N *newNode = new N;
    newNode->data =  a[mid];
    newNode->left =  NULL;
    newNode->right = NULL;
    if(start==end)      return newNode;
    newNode->left = arrayToBST(a,start,mid-1);
    newNode->right = arrayToBST(a,mid+1,end);
}

void display(N *root){
    if(!root)   return;
    display(root->left);
    cout<<root->data<<"  ";
    display(root->right);
}

int main(){
    int n;
    cout<<"Number of nodes: ";
    cin>>n;
    int a[n];
    cout<<"Input Data Values for tree: ";
    for(int i=0;i<n;i++)    cin>>a[i];
    sort(a,a+n);
    N *root = arrayToBST(a,0,n-1);
    cout<<"BST thus formed: "<<endl;
    display(root);
    return 0;
}
