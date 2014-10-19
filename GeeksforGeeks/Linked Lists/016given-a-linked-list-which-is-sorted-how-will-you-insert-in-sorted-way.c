#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}N;
N *create();
void display(N*);
N *insert(N*, int);
int main()
{
    N *list;
    int n;
    list = create();
    printf("Linked List:\n");
    display(list);
    printf("\nEnter Data to be Inserted: ");
    scanf("%d", &n);
    list = insert(list, n);
    printf("After Insertion, List:\n");
    display(list);
    return 0;
}

N *create()
{
    N *start=NULL, *ptr, *new, *prev=NULL;
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
        if(start==NULL)     start=new;
        else
        {
            prev->next = new;
            /*ptr=start;
            while(ptr->next!=NULL)      ptr=ptr->next;
            ptr->next=new;*/

        }
        prev = new;
        fflush(stdin);
        printf("Insert more nodes(Y/N): ");
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
        ptr=ptr->next;
    }
    printf("\n");
}

N *insert(N *head, int val){
	N *temp = (N*)malloc(sizeof(N));
	temp->data = val;
	temp->next = NULL;
	if(!head){
		head=temp;
		return head;
	}
	else if(head->data >= val){
		temp->next=head;
		head=temp;
		return head;
	}

	N *ptr=head,*x=head;
	while(ptr && ptr->data <= val){
		x=ptr;
		ptr=ptr->next;
	}
	if(!ptr)	x->next=temp;
	else if(ptr->data > val){
		temp->next=x->next;
		x->next=temp;
	}
	return head;
}
