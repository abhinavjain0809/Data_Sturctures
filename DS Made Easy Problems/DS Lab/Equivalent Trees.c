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
int equal(N*, N*);
main()
{
    N *root1, *root2;
    root1 = new_node();
    create(root1);
    printf("1st Tree:\n");
    display(root1);
    printf("\n");
    root2 = new_node();
    create(root2);
    printf("2nd Tree:\n");
    display(root2);
    if(equal(root1, root2)==0)      printf("\nTrees are not Equivalent...");
    else        printf("\nTrees are Equivalent...");
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

int equal(N* t1, N* t2)
{
    if(t1==NULL && t2==NULL)    return 1;
    else if(t1==NULL || t2==NULL)   return 0;
    else
    {
        if(t1->data==t2->data)
        {
            if(equal(t1->lc, t2->lc)==0)    return 0;
            else if(equal(t1->rc, t2->rc)==0)   return 0;
            else    return 1;
        }
        else    return 0;
    }
}
