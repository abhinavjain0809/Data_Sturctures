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
N* reversingInPairs(N*);

main()
{
    N *list;
    printf("Enter Data for List:\n");
    list = create();
    printf("\nList:\n");
    display(list);
    printf("\n\nList with pairs reversed:\n");
    list = reversingInPairs(list);
    display(list);
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

/*void reversingInPairs(N *start)           // Karumanchi's Book method. Does NOT Work...
{
    N *temp;
    if(start==NULL || start->next==NULL)    return;

    temp = start->next;
    start->next = temp->next;
    temp->next = start;

    reversingInPairs(start->next);
}*/

/*void reversingInPairs(N *start)           // Karumanchi's Book method. Does NOT Work...
{
    N *temp, *temp2, *current=start;
    while(current && current->next)
    {
        temp = current->next;
        temp2 = temp->next;
        temp->next = current;
        current->next = temp2;
        if(current)     current = current->next;
    }
}*/

N* reversingInPairs(N *start)
{
    int a=1, b=1;
    N *current=start, *temp, *temp2;

    while(current && current->next)
    {
        temp = current->next;
        current->next = temp->next;
        temp->next = current;
        if(a==1)
        {
            start = temp;
            a = 0;
        }
        if(b==0)        temp2->next = temp;
        b=0;

        temp2 = current;
        if(current)     current = current->next;
    }
    return start;
}
