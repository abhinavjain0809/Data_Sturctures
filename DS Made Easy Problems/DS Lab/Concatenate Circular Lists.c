#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node
{
    int data;
    struct node *next;
}N;
N *create();
void display(N*);
void concat(N*, N*);
main()
{
    N *head1, *head2;
    printf("Enter Data Values for 1st List:\n");
    head1 = create();
    printf("Enter Data Values for 2nd List:\n");
    head2 = create();
    printf("1st List: ");
    display(head1);
    printf("2nd List: ");
    display(head2);
    printf("Concatenated Lists are as follows:\n");
    concat(head1, head2);
    return 0;
}

struct node *create()
{
    N *start=NULL, *new, *ptr;
    char ans='Y';
    while(toupper(ans)=='Y')
    {
        new = (N*)malloc(sizeof(N));
        if(new==NULL)
        {
            printf("MEMORY OVERFLOW");
            system("pause");
            exit(0);
        }
        if(start==NULL)     start=new;
        else
        {
            ptr=start;
            while(ptr->next!=start)    ptr=ptr->next;
            ptr->next=new;
        }
        printf("Enter Data: ");
        scanf("%d", &new->data);
        new->next=start;
        fflush(stdin);
        printf("Continue(Y/N): ");
        fflush(stdin);
        scanf("%c", &ans);
    }
    return(start);
}

void display(N *start)
{
    N *ptr;
    ptr=start;
    while(ptr->next!=start)
    {
        printf("%d\t", ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n", ptr->data);
}

void concat(N *head1, N *head2)
{
    N *ptr;
    ptr=head1;
    while(ptr->next!=head1)     ptr=ptr->next;
    ptr->next=head2;
    ptr=head2;
    while(ptr->next!=head2)     ptr=ptr->next;
    ptr->next=head1;
    display(head1);
}
