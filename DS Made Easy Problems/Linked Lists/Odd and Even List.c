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
N* oddEven(N*);

main()
{
    N *list;
    printf("Enter Data for List:\n");
    list = create();
    printf("\nList:\n");
    display(list);
    printf("\n\nList with Even elements at the beginning:\n");
    list = oddEven(list);
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
        len++;
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

N* oddEven(N* start)
{
    N *ptr=start, *temp, *odd=NULL, *even=NULL, *temp2;
    while(ptr!=NULL)
    {
        if((ptr->data)%2==1)
        {
            temp = (N*)malloc(sizeof(N));
            temp->data = ptr->data;
            if(odd==NULL)       odd = temp;
            else
            {
                temp2 = odd;
                while(temp2->next!=NULL)      temp2 = temp2->next;
                temp2->next = temp;
            }
            temp->next = NULL;
        }
        else
        {
            temp = (N*)malloc(sizeof(N));
            temp->data = ptr->data;
            if(even==NULL)       even = temp;
            else
            {
                temp2 = even;
                while(temp2->next!=NULL)      temp2 = temp2->next;
                temp2->next = temp;
            }
            temp->next = NULL;
        }
        ptr = ptr->next;
    }

    ptr = even;
    while(ptr->next!=NULL)      ptr = ptr->next;
    ptr->next = odd;

    return even;
}
