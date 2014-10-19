#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int data;
    struct node *lc;
    struct node *rc;
}node;
node* new_node();
node* create_tree(node*);
void display(node *);

main()
{
    node *root;
    root = /*new_node()*/(node*)malloc(sizeof(node));
    root = create_tree(root);
    display(root);
    return 0;
}

node* new_node()
{
    node* temp;
    temp=(node*)malloc(sizeof(node));
    return temp;
}

node* create_tree(node *root)
{
    char ch;
    printf("Data: ");
    scanf("%d",&root->data);

    fflush(stdin);
    printf("Left Subtree(Y/N): ");
    ch=getchar();

    if(ch=='Y' || ch=='y')
        root->lc=create_tree(new_node());
    else
        root->lc=NULL;

    fflush(stdin);
    printf("Right Subtree(Y/N): ");
    ch=getchar();

    if(ch=='Y' || ch=='y')
        root->rc=create_tree(new_node());
    else
        root->rc=NULL;
}

void display(node *root)
{
    if(root==NULL)  return;
    display(root->lc);
    printf("%d\t", root->data);
    display(root->rc);
}
