#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}N;
N *create();
N *nth_node_from_last(N*, int);
void display(N*);
int main()
{
    N *list, *req;
    int n;
    list = create();
    printf("Linked List:\n");
    display(list);
    printf("\nEnter Node from last which you wish to look for: ");
    scanf("%d", &n);
    req = nth_node_from_last(list, n);
    if(req)
    {
        if(n==1)    printf("%dst node from last: %d", n, req->data);
        else if(n==2||n==3)    printf("%dnd node from last: %d", n, req->data);
        else        printf("%dth node from last: %d", n, req->data);
    }
    return 0;
}

N *create()
{
    N *start=NULL, *ptr, *new;
    char ans='Y';
    while(toupper(ans)=='Y')
    {
        new = (N*)malloc(sizeof(N));
        printf("Data: ");
        scanf("%d", &new->data);
        new->next=NULL;
        if(new==NULL)
        {
            printf("OUT OF MEMORY!!!");
            exit(1);
        }
        if(start==NULL)     start=new;
        else
        {
            ptr=start;
            while(ptr->next!=NULL)      ptr=ptr->next;
            ptr->next=new;
        }
        fflush(stdin);
        printf("Insert more nodes(Y/N): ");
        scanf("%c", &ans);
    }
    return start;
}

void display(N *start)
{
    N *ptr=start;
    while(ptr!=NULL)
    {
        printf("%d\t", ptr->data);
        ptr=ptr->next;
    }
}

N *nth_node_from_last(N* start, int n)
{
    N *temp=start, *ptr=start;
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
        if(count>n)     ptr=ptr->next;
    }
    if(count<n)     printf("\nToo Few Nodes...");
    else            return ptr;
}
