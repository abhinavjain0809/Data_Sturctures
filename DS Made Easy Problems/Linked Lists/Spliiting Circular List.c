#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node
{
    int data;
    struct node *next;
}N;

N* create();
void display(N*);
void splitCircularList(N*);

int main()
{
    N *list;
    printf("Enter data for Circulat List:\n");
    list = create();
    printf("Circular List:\n");
    display(list);
    splitCircularList(list);
    return 0;
}

N* create()
{
    N *start=NULL, *ptr, *new;
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
    return start;
}

void display(N *start)
{
    N *ptr = start;
    while(ptr->next!=start)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
}

void splitCircularList(N* start)
{
    N *ptr=start, *temp;
    N *fast=start, *slow=start;
    int len=1;
    while(ptr->next!=start)
    {
        len++;
        ptr = ptr->next;
    }

    while(fast->next!=start && fast->next->next!=start)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    if(len%2==1)
    {
        temp = slow->next;
        fast->next = slow->next;
    }

    else
    {
        temp = slow->next;
        fast->next->next = slow->next;
    }
    slow->next = start;
    printf("\nFirst Half:\n");
    display(start);

    printf("\nSecond Half:\n");
    display(temp);
}
