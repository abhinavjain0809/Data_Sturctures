#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}N;
N *start;
void create();
void display();
void max_min();
main()
{
    char ans='Y';
    create();
    display();
    max_min();
    return 0;
}

void create()
{
    N *ptr, *new;
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
            while(ptr->next!=NULL)    ptr=ptr->next;
            ptr->next=new;
        }
        printf("Enter Data: ");
        scanf("%d", &new->data);
        new->next=NULL;
        fflush(stdin);
        printf("Continue(Y/N): ");
        scanf("%c", &ans);
    }
}

void display()
{
    N *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d\t", ptr->data);
        ptr=ptr->next;
    }
}

void max_min()
{
    int max, min, sum=0, count=1;
    float avg;
    N *ptr;
    ptr=start;
    max = ptr->data;
    min = ptr->data;
    sum += ptr->data;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
        if(max<ptr->data)   max = ptr->data;
        if(min>ptr->data)   min = ptr->data;
        sum += ptr->data;
        count++;
    }
    avg = (float)sum/count;
    printf("\nThe Max is: %d", max);
    printf("\nThe Min is: %d", min);
    printf("\nAverage is: %.2f", avg);
}
