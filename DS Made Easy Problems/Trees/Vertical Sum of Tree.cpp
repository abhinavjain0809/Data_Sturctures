#include<iostream>
#include<stdlib.h>
#include<ctype.h>
using namespace std;

typedef struct node
{
    int data;
    int num;
    struct node *left;
    struct node *right;
}N;
static int sum[20];
N *start=NULL;
void createtree(int n,N *st,int num1)
{
     if(n<st->data)
     {
         if(!st->left)
         {
             st->left=new N;
             st->left->data=n;
             st->left->num=num1;
             st->left->left=st->left->right=NULL;
         }
         else createtree(n,st->left,num1-1);
     }
     else
     {
         if(!st->right)
         {
             st->right=new N;
             st->right->data=n;
             num1 += 2;
             st->right->num=num1;
             st->right->left=st->right->right=NULL;
         }
         else createtree(n,st->right,num1+1);
     }
}

void printtreein(N *root)
{
    if(root)
    {


    printtreein(root->left);
    cout<<root->data<<"\t";
    cout<<root->num<<"\n";
    printtreein(root->right);
    }
}

void vSum(N *root)
{
    if(root)
    {
    vSum(root->left);
    sum[root->num] += root->data;
    vSum(root->right);
    }
}

int main()
{
    char ch;
    int n;
    cout<<"want to create tree?????";
    cin>>ch;
    while(toupper(ch)=='Y')
          {
              cout<<"\nenter the data";
              cin>>n;
              if(!start)
              {
                  start=new N;
                  start->data=n;
                  start->num = 10;
                  start->left=start->right=NULL;
              }
              else    createtree(n,start,start->num-1);
              cout<<"want to create more nodes????????";
              cin>>ch;
          }
          cout<<"\nnow printing the tree in inorder"<<endl;
          printtreein(start);
          cout<<"--------------------------------------"<<endl;
          vSum(start);
          for(int i=0;i<20;i++)
          {
                cout<<i<<"\t";
                cout<<sum[i]<<"\n";
        }
          return 0;
}
