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
N *reverse(N*);             //Original List's base address is lost...
void reverse_stacks(N *);   //We dont lose our original list using stacks...
void push(int, int [], int *);
void pop(int [], int *);
int main()
{
    N *list, *req;
    int n;
    list = create();
    printf("Linked List:\n");
    display(list);
    reverse_stacks(list);
    req = reverse(list);
    printf("\nReversed List is:\n");
    display(req);
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

N *reverse(N *start)
{
    N *nxt=NULL, *temp=NULL;
    while(start)
    {
        nxt = start->next;
        start->next = temp;
        temp = start;
        start = nxt;
    }
    return temp;
}

void reverse_stacks(N *start)
{
    int stack[50], top=-1, val;
    N *temp=start;
    while(temp)
    {
        push(temp->data, stack, &top);
        temp = temp->next;
    }
    printf("\nReversed List is:\n");
    while(top!=-1)      pop(stack, &top);
}

void push(int val, int stack[], int *top)
{
    if(*top==49)
    {
        printf("Stack FULL Exception!!!");
        exit(2);
    }
    (*top)++;
    stack[*top] = val;
}

void pop(int stack[], int *top)
{
    printf("%d\t", stack[*top]);
    (*top)--;
}
