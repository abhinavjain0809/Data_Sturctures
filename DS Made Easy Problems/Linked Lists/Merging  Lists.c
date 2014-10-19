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
N* mergeList(N*,N*);

main()
{
    N *a, *b, *sortedList;
    printf("WARNING: All Data must be entered in sorted order");
    printf("\nEnter Data for 1st List:\n");
    a = create();
    printf("\nList 1:\n");
    display(a);

    printf("\n\nEnter Data for 2nd List:\n");
    b = create();
    printf("\nList 2:\n");
    display(b);

    sortedList = mergeList(a, b);
    printf("\n\nSorted List:\n");
    display(sortedList);

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
            printf("OUT OF MEMORY!!!");
            exit(1);
        }
        printf("Data: ");
        scanf("%d", &new->data);
        new->next=NULL;

        if(start==NULL)     start = new;
        else
        {
            ptr = start;
            while(ptr->next!=NULL)      ptr = ptr->next;
            ptr->next = new;
        }

        fflush(stdin);
        printf("Insert more Data(Y/N): ");
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
        ptr = ptr->next;
    }
}

N* mergeList(N *a, N *b)
{
    N *result=NULL;

    if(a==NULL)          return b;
    else if(b==NULL)     return a;
    else if(a->data < b->data)
    {
        result = a;
        result->next = mergeList(a->next,b);
    }
    else
    {
        result = b;
        result->next = mergeList(a, b->next);
    }
    return result;
}
