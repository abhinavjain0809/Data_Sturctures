#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *lc;
    struct node *rc;
}N;

void create(int, N**);
void display(N**);
void insert(int, N**);

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

    printf("\n\nEnter data to insert: ");
    scanf("%d", &b);
    insert(b, &root);
    //create(b, &root);

    printf("\n\nTree after insertion:\n");
    display(&root);

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

void insert(int b, N **root)
{
    N *queue[100], *temp, *new;
    int front=-1, rear=-1;
    new = (N*)malloc(sizeof(N));
    new->data = b;
    new->lc = NULL;
    new->rc = NULL;
    rear++;
    queue[rear] = *root;
    while(front<rear)
    {
        front++;
        temp = queue[front];

        if(temp->lc)
        {
            rear++;
            queue[rear] = temp->lc;
        }
        else
        {
            temp->lc = new;
            return;
        }

        if(temp->rc)
        {
            rear++;
            queue[rear] = temp->rc;
        }
        else
        {
            temp->rc = new;
            return;
        }
    }
}
