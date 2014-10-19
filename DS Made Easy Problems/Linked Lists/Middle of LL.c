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
N *middle(N*);
int main()
{
    N *list, *mid;
    int n;
    list = create();
    printf("\nLinked List:\n");
    display(list);
    mid = middle(list);
    printf("\nMiddle Node is: %d", mid->data);
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

N *middle(N *start)
{
    N *fast=start, *slow=start;
    int i=0;
    while(fast->next!=NULL)
    {
        if(i==0)
        {
            fast=fast->next;
            i=1;
        }
        else if(i==1)
        {
            fast=fast->next;
            slow=slow->next;
            i=0;
        }
    }
    return slow;
}
