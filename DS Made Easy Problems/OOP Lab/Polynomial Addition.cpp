#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node
{
    int data;
    int x,y;
    int flag;
    struct node *next;
}N;

N* create();
void display(N*);
void add(N*,N*);
int main(void)
{
    N *a, *b, *c;
    cout<<"\nEnter Data for 1st Polynomial:\n";
    a = create();
    cout<<"\nList 1:\n";
    display(a);

    cout<<"\nEnter Data for 2nd Polynomial:\n";
    b = create();
    cout<<"\nList 2:\n";
    display(b);

    add(a,b);
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
        cout<<"Data: ";
        cin>>new->data;
        new->next=NULL;
        new->flag=0;
        cout<<"Power of x: ";
        cin>>new->x;
        cout<<"Power of y: ";
        cin>>new->y;

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

N *add(N*a, N*b)
{
    N *p=a, *q=b, *del;
    while(p!=NULL){
        while(q!=NULL){
            if(p->x==q->x && p->y==q->y){
                p->data += q->data;
                p->flag = q->flag = 1;
                deleteNode(q,b);
                break;
            }
            else{
                q=q->next;
            }
        }
        p=p->next;
}

void deleteNode(N *q, N *b)
{
    N *x=b;
}
