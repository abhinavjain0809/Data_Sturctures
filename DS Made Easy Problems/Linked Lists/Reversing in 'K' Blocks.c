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
N* reversingInkBlocks(N*, int);

int main()
{
    N *list;
    int k;
    printf("Enter Data for List:\n");
    list = create();
    printf("\nList:\n");
    display(list);
    printf("\n\nEnter number of Blocks to reverse: ");
    scanf("%d", &k);
    printf("\nList with pairs reversed:\n");
    list = reversingInkBlocks(list, k);
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
    printf("\n");
}

N* reversingInkBlocks(N *start, int k)
{
    N *ptr, *x, *current=start, *head, *next, *kPlusOneth=start;
    int i=0,a=1,c=0;

    if(len<k || k==0 || k==1)       return start;

    while(len>0)
    {
        if(len<k)       break;

        for(i=0;i<k;i++)
        {
            x = kPlusOneth;
            kPlusOneth = kPlusOneth->next;
        }
        ptr = kPlusOneth;
        if(a==1)
        {
            head = x;
            a=0;
        }

        i=0;
        while(i<k)
        {
            next = current->next;
            current->next = ptr;
            ptr = current;
            current = next;
            i++;
        }

        if(c!=0)
        {
            start->next = x;
            for(i=0;i<k;i++)    start = start->next;
        }
        c=1;
        len -= k;
    }
    return head;
}

/*
N* reversingInkBlocks(struct node *head, int k)
{
    N* current = head;
    N* next;
    N* prev = NULL;
    int count = 0;  
     
    /*reverse first k nodes of the linked list */
/*    while (current != NULL && count < k)
    {
       next  = current->next;
       current->next = prev;
       prev = current;
       current = next;
       count++;
    }
     
    /* next is now a pointer to (k+1)th node
       Recursively call for the list starting from current.
       And make rest of the list as next of first node */
/*    if(next !=  NULL)
    {  head->next = reversingInkBlocks(next, k); }
 
    /* prev is new head of the input list */
/*    return prev;
}
*/
