#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node
{
    int data;
    struct node *next;
}N;
N *start=NULL, *new, *ptr, *temp;
main()
{
    int i, d;
    char ans = 'Y';
    while(1)
    {
        printf("\nChoices: ");
        printf("\n1. Create Circular Linked List\n2. Insert element at beginning\n3. Insert elememt at end\n4. Insert element after given data");
        printf("\n5. Delete first element\n6. Delete last element\n7. Delete a given element\n8. Print your List\n0. EXIT\n");
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
            break;

            case 2:
            new = (N*)malloc(sizeof(N));
            if(new==NULL)
            {
                printf("MEMORY OVERFLOW");
                system("pause");
                exit(0);
            }
            printf("Data: ");
            scanf("%d", &new->data);
            new->next=start;
            ptr=start;
            while(ptr->next!=start)     ptr=ptr->next;
            ptr->next=new;
            start=new;
            break;

            case 3:
            new = (N*)malloc(sizeof(N));
            if(new==NULL)
            {
                printf("MEMORY OVERFLOW");
                system("pause");
                exit(0);
            }
            printf("Data: ");
            scanf("%d", &new->data);
            new->next=start;
            ptr=start;
            while(ptr->next!=start)     ptr=ptr->next;
            ptr->next=new;
            break;

            case 4:
            printf("Enter Data after which New Data is to be inserted: ");
            scanf("%d", &d);
            ptr=start;
            while(ptr->data!=d && ptr->next!=start)     ptr=ptr->next;
            if(ptr->data==d)
            {
                new = (N*)malloc(sizeof(N));
                if(new==NULL)
                {
                    printf("MEMORY OVERFLOW");
                    system("pause");
                    exit(0);
                }
                printf("Data: ");
                scanf("%d", &new->data);
                new->next=ptr->next;
                ptr->next=new;
            }
            else    printf("Given Data DOES NOT EXIST!!!");
            break;

            case 5:
            ptr=start;
            while(ptr->next!=start)      ptr=ptr->next;
            temp=start;
            start=start->next;
            ptr->next=start;
            free(temp);
            printf("First Element Deleted...");
            break;

            case 6:
            ptr=start;
            while(ptr->next!=start)
            {
                temp=ptr;
                ptr=ptr->next;
            }
            temp->next=ptr->next;
            free(ptr);
            printf("Last Element Deleted...");
            break;

            case 7:
            printf("Enter Element to Delete: ");
            scanf("%d", &d);
            ptr=start;
            while(ptr->data!=d && ptr->next!=start)
            {
                temp = ptr;
                ptr=ptr->next;
            }
            if(ptr->data==d)
            {
                temp->next = ptr->next;
                free(ptr);
                printf("Data Entry Deleted...");
            }
            else    printf("Given Data DOES NOT EXIST...");
            break;

            case 8:
            ptr=start;
            while(ptr->next!=start)
            {
                printf("%d\t", ptr->data);
                ptr=ptr->next;
            }
            printf("%d\n", ptr->data);
            break;

            case 0:
            exit(0);
            break;

            default:
            printf("Invalid Choice Entered...");
        }
    }
    return 0;
}
