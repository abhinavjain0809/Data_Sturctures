#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node
{
    int data;
    struct node *next;
}N;

int len=0;
N* create();
void display(N*);
N* josephusCircle(N*, int);

main()
{
    N *list, *rank1;
    int k;
    printf("Enter data for Circulat List:\n");
    list = create();
    printf("\nCircular List:\n");
    display(list);
    printf("\n\nEnter number to skip: ");
    scanf("%d", &k);
    rank1 = josephusCircle(list,k);
    printf("\n\nRank 1: %d", rank1->data);

    return 0;
}

N* create()
{
    N *start=NULL, *ptr, *new;
    char ans='Y';
    while(toupper(ans)=='Y')
    {
        new = (N*)malloc(sizeof(N));
        len++;
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

N* josephusCircle(N *start, int k)
{
    N *x=start, *ptr=start;
    int i;
    while(len!=1)
    {
        ptr = x;
        for(i=0;i<k-1;i++)
        {
            x = ptr;
            ptr = ptr->next;
        }
        x->next = ptr->next;
        ptr->next = NULL;
        free(ptr);
        x = x->next;
        len--;
    }
    return x;
}
