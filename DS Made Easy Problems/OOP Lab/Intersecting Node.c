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
void createIntersectingList(N*,N*,N*);
int intersectingNode(N*,N*);

main()
{
    N *a, *b, *c;
    int req;
    printf("\nEnter Data for 1st List:\n");
    a = create();
    printf("\nList 1:\n");
    display(a);

    printf("\nEnter Data for 2nd List:\n");
    b = create();
    printf("\nList 2:\n");
    display(b);

    printf("\nEnter Data for 3rd List:\n");
    c = create();
    printf("\nList 3:\n");
    display(c);

    createIntersectingList(a,b,c);
    /*printf("\nA:\n");
    display(a);
    printf("\nB:\n");
    display(b);*/
    req = intersectingNode(a,b);
    printf("\n\nIntersecting Node: %d", req);
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

void createIntersectingList(N *a, N *b, N *c)
{
    N *ptr;
    ptr = a;
    while(ptr->next!=NULL)    ptr=ptr->next;
    ptr->next = c;

    ptr = b;
    while(ptr->next!=NULL)    ptr=ptr->next;
    ptr->next = c;
}

int intersectingNode(N *a, N *b)
{
    int l1=0, l2=0, diff, i;
    N *list1=a, *list2=b;

    while(list1!=NULL)
    {
        l1++;
        list1 = list1->next;
    }

    while(list2!=NULL)
    {
        l2++;
        list2 = list2->next;
    }

    list1 = a;      // V Imp steps as list1 and list2 have already been assigned to NULL from above "while" Loops...
    list2 = b;

    if(l1>l2)
    {
        diff = l1-l2;
        for(i=0;i<diff;i++)     list1 = list1->next;

        while(list1 && list2)
        {
            if(list1 == list2)      return list1->data;
            list1 = list1->next;
            list2 = list2->next;
        }
    }

    else
    {
        diff = l2-l1;
        for(i=0;i<diff;i++)     list2 = list2->next;

        while(list1 && list2)
        {
            if(list1 == list2)      return list2->data;
            list1 = list1->next;
            list2 = list2->next;
        }
    }

    /*if(l1>l2)
    {
        diff = l1-l2;
        list1 = a;
        list2 = b;
    }
    else
    {
        diff = l2-l1;
        list1 = b;
        list2 = a;
    }

    for(i=0;i<diff;i++)     list1 = list1->next;

    while(list1 && list2)
    {
        if(list1 == list2)      return list1->data;
        list1 = list1->next;
        list2 = list2->next;
    }*/

    return 999;
}
