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

main()
{
    N *root;
    int n, i, b, max = -999999;
    printf("Enter Total number of Nodes: ");
    scanf("%d", &n);
    root = (N*)malloc(sizeof(N));
    root->lc = NULL;
    root->rc = NULL;
    printf("\nData for Root: ");
    scanf("%d", &root->data);
    max = root->data;
    printf("\nData for rest of the nodes: ");
    for(i=1;i<n;i++)
    {
        scanf("%d", &b);
        if(max<b)       max = b;
        create(b, &root);
    }
    printf("\n\nLevel Order Tree Traversal:\n");
    display(&root);

    printf("\n\nMaximum Element is (Mathod 1): %d", max);       // Finding Max at the time of creation of tree...

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
    N *temp, *queue[100];
    int max=-999999, front=-1, rear=-1;
    rear++;
    queue[rear] = *root;

    while(front<rear)
    {
        front++;
        temp = queue[front];
        printf("%d\t", temp->data);
        if(max<temp->data)      max = temp->data;

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
    printf("\n\nMaximum Element is (Method 2): %d", max);       // Finding Maximum at the time of traversing the tree in Level Order Traversal...
}
