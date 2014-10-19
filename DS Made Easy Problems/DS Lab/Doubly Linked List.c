#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}N;
N *start=NULL, *ptr, *new, *temp;
main()
{
    int i, d;
    char ans = 'Y';
    while(1)
    {
        printf("\nChoices: ");
        printf("\n1. Create Doubly Linked List\n2. Insert element at beginning\n3. Insert elememt at end\n4. Insert element after given data");
        printf("\n5. Delete first element\n6. Delete last element\n7. Delete a given element\n8. Print your List\n9. Delete Whole List\n0. EXIT\n");
        printf("\nYour Choice: ");
        scanf("%d", &i);

        switch(i)
        {
            case 1:
            while(toupper(ans)=='Y')
            {
                new = (N*)malloc(sizeof(N));
                if(new==NULL)
                {
                    printf("Memory Overflow!!!");
                    exit(0);
                }
                printf("Data: ");
                scanf("%d", &new->data);
                if(start==NULL)
                {
                    new->prev=NULL;
                    new->next=NULL;
                    start = new;
                }
                else
                {
                    ptr=start;
                    while(ptr->next!=NULL)      ptr=ptr->next;
                    ptr->next=new;
                    new->prev=ptr;
                    new->next=NULL;
                }
                fflush(stdin);
                printf("Continue(Y/N): ");
                fflush(stdin);
                scanf("%c", &ans);
            }
            break;

            case 2:
            new = (N*)malloc(sizeof(N));
            if(new==NULL)
            {
                printf("Memory Overflow!!!");
                exit(0);
            }
            printf("Data: ");
            scanf("%d", &new->data);
            new->next=start;
            start->prev=new;
            new->prev=NULL;
            start=new;
            break;

            case 3:
            new = (N*)malloc(sizeof(N));
            if(new==NULL)
            {
                printf("Memory Overflow!!!");
                exit(0);
            }
            printf("Data: ");
            scanf("%d", &new->data);
            ptr=start;
            while(ptr->next!=NULL)      ptr=ptr->next;
            ptr->next=new;
            new->prev=ptr;
            new->next=NULL;
            break;

            case 4:
            printf("Enter element after which to insert new data: ");
            scanf("%d", &d);
            ptr=start;
            while(ptr->data!=d && ptr->next!=NULL)  ptr=ptr->next;
            if(ptr->data==d)
            {
                new = (N*)malloc(sizeof(N));
                if(new==NULL)
                {
                    printf("Memory Overflow!!!");
                    exit(0);
                }
                printf("Data: ");
                scanf("%d", &new->data);
                new->next = ptr->next;
                ptr->next = new;
                new->prev = ptr;
                new->next->prev = new;
            }
            else    printf("Given Data DOES NOT EXIST...");
            break;

            case 5:
            ptr=start;
            start=start->next;
            start->prev = NULL;
            free(ptr);
            printf("First Element Deleted...");
            break;

            case 6:
            ptr=start;
            while(ptr->next!=NULL)      ptr=ptr->next;
            ptr->prev->next=NULL;
            free(ptr);
            printf("Last Element Deleted...");
            break;

            case 7:
            printf("Data to Delete: ");
            scanf("%d", &d);
            ptr=start;
            while(ptr->data!=d && ptr->next!=NULL)      ptr=ptr->next;
            if(ptr->data==d)
            {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                free(ptr);
                printf("Given Element DELETED...");
            }
            else    printf("Given Data DOES NOT EXIST...");
            break;

            case 8:
            ptr=start;
            while(ptr!=NULL)
            {
                printf("%d\t", ptr->data);
                ptr=ptr->next;
            }
            break;

            case 9:
            start = NULL;
            printf("Whole List Deleted...");
            break;

            case 0:
            exit(0);
            break;

            default:
            printf("INVALID CHOICE!!!");
        }
    }
    return 0;
}
