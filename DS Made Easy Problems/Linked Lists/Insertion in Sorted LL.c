#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}N;
N *create();
void display(N*);
N *insert(N*, int);
int main()
{
    N *list;
    int n;
    list = create();
    printf("Linked List:\n");
    display(list);
    printf("\nEnter Data to be Inserted: ");
    scanf("%d", &n);
    list = insert(list, n);
    printf("After Insertion, List:\n");
    display(list);
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

N *insert(N *start, int val)
{
    N *ptr=start, *x, *temp;
    temp = (N*)malloc(sizeof(N));
    if(temp==NULL)
    {
        printf("OUT OF MEMORY!!!");
        exit(2);
    }
    temp->data = val;
    while(val>=ptr->data && ptr->next!=NULL)
    {
        x = ptr;
        ptr=ptr->next;
    }

    if(ptr==start)
    {
        temp->next=start;
        start = temp;
    }
    else if(x==start)
    {
        temp->next = x->next;
        x->next = temp;
    }
    else if(ptr->next==NULL && ptr->data<val)
    {
        ptr->next = temp;
        temp->next=NULL;
    }
    else
    {
        temp->next=x->next;
        x->next=temp;
    }
    return start;
}
