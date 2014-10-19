#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}N;
N *ptr, *start=NULL, *new, *x;
main()
{
    int i, d;
    char ans = 'Y';
    while(1)
    {
        printf("\nChoices: ");
        printf("\n1. Create Linked List\n2. Insert element at beginning\n3. Insert elememt at end\n4. Insert element after given data");
        printf("\n5. Delete first element\n6. Delete last element\n7. Delete a given element\n8. Print your List\n9. Delete Whole List\n0. EXIT\n");
        printf("\nYour Choice: ");
        scanf("%d", &i);

        switch(i)
        {
            case 1: //Creation of a Linked List...
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
                fflush(stdin);
                scanf("%c", &ans);
            }
            break;

            case 2: //Insert element at beginning...
            new = (N*)malloc(sizeof(N));
            if(new==NULL)
            {
                printf("MEMORY OVERFLOW");
                system("pause");
                exit(0);
            }
            printf("\nEnter Data: ");
            scanf("%d", &new->data);
            new->next=start;
            start=new;
            break;

            case 3: //Insert element at end...
            new = (N*)malloc(sizeof(N));
            if(new==NULL)
            {
                printf("MEMORY OVERFLOW");
                system("pause");
                exit(0);
            }
            printf("\nEnter Data: ");
            scanf("%d", &new->data);
            new->next=NULL;
            ptr=start;
            while(ptr->next!=NULL)    ptr=ptr->next;
            ptr->next=new;
            break;

            case 4: //Insert element after a given element...
            printf("\nElement after which you wish to insert data: ");
            scanf("%d", &d);
            ptr=start;
            while(ptr->data!=d && ptr->next!=NULL)      ptr=ptr->next;
            if(ptr->data==d)
            {
                new = (N*)malloc(sizeof(N));
                printf("Data to Insert: ");
                scanf("%d", &new->data);
                new->next=ptr->next;
                ptr->next=new;
            }
            else    printf("\nGiven Data DOES NOT EXIST...\n");
            break;

            case 5: // Delete First Element...
            ptr=start;
            start=start->next;
            free(ptr);
            printf("First Element Deleted.\n");
            break;

            case 6: // Delete Last Element...
            ptr=start;
            while(ptr->next!=NULL)
            {
                x=ptr;
                ptr=ptr->next;
            }
            free(ptr);
            x->next=NULL;
            printf("Last Element Deleted.\n");
            break;

            case 7: // Delete given element...
            printf("\nEnter Data to Delete: ");
            scanf("%d", &d);
            ptr=start;
            x=start;
            while((ptr->data)!=d && ptr->next!=NULL)
            {
                x=ptr;
                ptr=ptr->next;
            }
            if(ptr->data==d)
            {
                x->next=ptr->next;
                free(ptr);
            }
            else    printf("Data Entry DOES NOT EXIST.\n");
            break;

            case 8: // Printing the List...
            ptr=start;
            while(ptr!=NULL)
            {
                printf("%d\t", ptr->data);
                ptr=ptr->next;
            }
            break;

            case 9: // Deleting Whole List...
            start=NULL;
            printf("Whole List DELETED.\n");
            break;

            case 0:
            exit(1);

            default:
            printf("\nINVALID ENRTY!!!\n");
        }
    }
    return 0;
}
