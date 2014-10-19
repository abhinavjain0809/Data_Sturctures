#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node
{
    int data;
    struct node *lc;
    struct node *rc;
}N;
N *new_node();
N *create(N*);
void display(N*);
N *copy(N*);
main()
{
    N *root, *cpy_tree=NULL;
    root = new_node();
    create(root);
    printf("Original Tree:\n");
    display(root);
    /*cpy_tree = new_node();*/
    cpy_tree = copy(root);
    printf("\n\nCopied Tree:\n");
    display(cpy_tree);
    return 0;
}

N *new_node()
{
    N *new;
    new = (N*)malloc(sizeof(N));
    return new;
}

N *create(N* root)
{
    char ch;
    printf("Data: ");
    scanf("%d", &root->data);

    fflush(stdin);
    printf("Left Subtree(Y/N): ");
    scanf("%c", &ch);

    if(toupper(ch)=='Y')    root->lc=create(new_node());
    else    root->lc = NULL;

    fflush(stdin);
    printf("Right Subtree(Y/N): ");
    scanf("%c", &ch);

    if(toupper(ch)=='Y')    root->rc=create(new_node());
    else    root->rc = NULL;
}

void display(N* root)
{
    if(root==NULL)      return;

    display(root->lc);
    printf("%d\t", root->data);
    display(root->rc);
}

N* copy(N* root)
{
    N *new;
    if(root==NULL)      new = NULL;
    else
    {
        new = new_node();
        new->data = root->data;
        new->lc = copy(root->lc);
        new->rc = copy(root->rc);
    }
    return new;
}
