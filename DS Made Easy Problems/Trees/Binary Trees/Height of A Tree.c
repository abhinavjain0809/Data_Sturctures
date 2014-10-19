#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *lc;
    struct node *rc;
}N;
N *start;
void create(int, N**);
void display(N**);
int height(N*);

main()
{
    N *root;
    int n, b, i;
    printf("Total number of nodes: ");
    scanf("%d", &n);
    if(n==0)
    {
        printf("\nEmpty Tree!!!");
        exit(1);
    }
    root = (N*)malloc(sizeof(N));
    root->lc = NULL;
    root->rc = NULL;
    start = root;
    printf("\nRoot Data: ");
    scanf("%d", &root->data);
    if(n>1)
    {
        printf("Data for rest of the Nodes: ");
        for(i=1;i<n;i++)
        {
            scanf("%d", &b);
            create(b, &root);
        }
    }
    printf("\n\nTree:\n");
    display(&root);

    b = height(start);
    printf("\n\nHeight of Tree: %d", b);
    return 0;
}

void create(int b, N **root)
{
    N *queue[100], *temp;
    int front=-1, rear=-1;
    temp = (N*)malloc(sizeof(N));
    temp->data = b;
    temp->lc = NULL;
    temp->rc = NULL;
    rear++;
    queue[rear] = *root;
    while(front<=rear)
    {
        front++;
        if(queue[front]->lc==NULL)
        {
            queue[front]->lc = temp;
            return;
        }
        else if(queue[front]->rc==NULL)
        {
            queue[front]->rc = temp;
            return;
        }
        rear++;
        queue[rear] = queue[front]->lc;
        rear++;
        queue[rear] = queue[front]->rc;
    }
}

void display(N **root)
{
    N *queue[100], *temp;
    int front=-1, rear=-1;
    rear++;
    queue[rear] = *root;
    while(front<rear)
    {
        front++;
        temp = queue[front];
        printf("%d\t", temp->data);

        if(temp->lc)
        {
            rear++;
            queue[rear] = temp->lc;
        }

        if(temp->rc)
        {
            rear++;
            queue[rear] = temp->rc;
        }
    }
}

int height(N *root)
{
    int left, right;
    if(!root)       return 0;
    left = height(root->lc);
    right = height(root->rc);
    if(left>right)      return (left + 1);
    else                return (right + 1);
}
