#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}N;
N *create();
int floyd_cycle(N*);
int main()
{
    N *list;
    printf("Press 'N' to end the list in cyclic format (For Cyclic Form, min 2 nodes must be present)\n");
    list = create();
    floyd_cycle(list);
    return 0;
}

N *create()
{
    N *start=NULL, *ptr, *new;
    int p, nodes=0;
    char ans='Y';
    while(toupper(ans)=='Y')
    {
        new = (N*)malloc(sizeof(N));
        printf("Data: ");
        scanf("%d", &new->data);
        new->next=NULL;
        if(new==NULL)
        {
            printf("OUT OF MEMORY!!!");
            exit(1);
        }
        nodes++;
        if(nodes==2)    p = new;
        if(start==NULL)     start=new;
        else
        {
            ptr=start;
            while(ptr->next!=NULL)      ptr=ptr->next;
            ptr->next=new;
        }
        fflush(stdin);
        printf("Insert more nodes(Y/N): ");
        scanf("%c", &ans);
        if(toupper(ans)=='N')   new->next = p;
    }
    return start;
}

int floyd_cycle(N *start)
{
    N *slow=start, *fast=start, *intersection=NULL, *loopStart=NULL, *x=NULL, *ptr;
    int loop=0, count=0;
    while(fast)
    {
        fast=fast->next;
        if(fast==NULL)
        {
            loop = 0;
            break;
        }
        fast=fast->next;
        if(fast==NULL)
        {
            loop = 0;
            break;
        }

        slow=slow->next;

        if(fast==slow)
        {
            intersection=fast;
            loop = 1;
            break;
        }
    }
    if(loop)    printf("Loop Exists...\n");
    else        printf("Loop doesn't Exist...\n");

    // Determining Number of nodes in the loop...
    if(loop)
    {
        slow=slow->next;
        count++;
        while(slow!=fast)
        {
            count++;
            slow=slow->next;
        }
        printf("\nNo. of nodes present in the loop: %d\n\n", count);
    }

    // Determining the start of the loop...
    if(loop)
    {
        slow = start;
        while(slow!=fast)
        {
            fast=fast->next;
            slow=slow->next;
        }
        printf("\nStarting of the loop: %d\n\n", fast->data);
        loopStart = fast;
    }

    // Removing Loop...
    if(loop){
        ptr=intersection;
        while(ptr!=loopStart){
            x=ptr;
            ptr=ptr->next;
        }
        x->next=NULL;
        printf("Linked List after loop removal:\n");
        ptr=start;
        while(ptr!=NULL){
            printf("%d\t", ptr->data);
            ptr=ptr->next;
        }
    }
}
