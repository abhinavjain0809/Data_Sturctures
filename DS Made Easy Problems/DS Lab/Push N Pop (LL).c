#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node
{
    int data;
    struct node *next;
}N;
N *start=NULL;
void push(int);
void display();
void pop();
main()
{
    int val;
    char ans='Y';

    // PUSH...
    while(toupper(ans)=='Y')
    {
        printf("Enter Data: ");
        scanf("%d", &val);
        push(val);
        fflush(stdin);
        printf("Push more elements(Y/N): ");
        scanf("%c", &ans);
    }
    printf("Stack after pushing is:\n");
    display();

    // POP...
    fflush(stdin);
    printf("\n\nPop out Elements(Y/N): ");
    scanf("%c", &ans);
    while(toupper(ans)=='Y')
    {
        pop();
        fflush(stdin);
        printf("Pop more(Y/N): ");
        scanf("%c", &ans);
    }
    printf("Stack after Popping:\n");
    display();

    return 0;
}

void push(int val)
{
    N *new;
    new = (N*)malloc(sizeof(N));
    if(new==NULL)
    {
        printf("Stack OVERFLOW");
        system("pause");
        exit(1);
    }
    new->data = val;
    if(start==NULL)
    {
        start = new;
        new->next=NULL;
    }
    else
    {
        new->next = start;
        start = new;
    }
}

void display()
{
    N *ptr;
    ptr = start;
    while(ptr!=NULL)
    {
        printf("%d\t", ptr->data);
        ptr=ptr->next;
    }
}

void pop()
{
    N *ptr=start;
    if(start==NULL)
    {
        printf("Stack UNDERFLOW");
        system("pause");
        exit(2);
    }
    start = start->next;
    free(ptr);
}
