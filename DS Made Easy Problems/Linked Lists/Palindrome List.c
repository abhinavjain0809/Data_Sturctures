#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define X 50

typedef struct node
{
    int data;
    struct node *next;
}N;

int stack[X];
int top = -1;

N* create();
void display(N*);
int palindrome(N*);
void push(int);
int pop();

N* reverse(N*start){
    N *nxt=NULL,*temp=NULL;
    while(start){
        nxt=start->next;
        start->next=temp;
        temp=start;
        start=nxt;
    }
    return temp;
}

int palindromeRev(N*start){
    N *mid=start,*last=start;
    while(last && last->next && last->next->next){
        mid=mid->next;
        last=last->next->next;
    }
    if(mid==last){
        if(mid->next){
            if(mid->data==mid->next->data)      return 1;
            else                                return 0;
        }
        else                                    return 1;
    }
    last=reverse(mid->next);
    mid->next=last;
    N *ptr=start;
    while(ptr!=mid){
        if(ptr->data!=last->data)       return 0;
        ptr=ptr->next;
        last=last->next;
    }
    return 1;
}

main()
{
    N *list;
    int i;
    printf("Enter Data for List:\n");
    list = create();
    printf("\nList:\n");
    display(list);
    /*i = palindrome(list);
    if(i==0)        printf("\n\nList is not a Palindrome...");
    else            printf("\n\nList is a Palindrome...");*/
    i = palindromeRev(list);
    if(i==0)        printf("\n\nList is not a Palindrome...");
    else            printf("\n\nList is a Palindrome...");
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

int palindrome(N *start)
{
    N *ptr=start;
    int len = 0, count=0;

    while(ptr!=NULL)
    {
        len++;
        push(ptr->data);
        ptr = ptr->next;
    }

    ptr = start;
    while(top!=-1 && pop()==ptr->data)
    {
        count++;
        ptr = ptr->next;
    }
    if(count==len)      return 1;
    else                return 0;
}

void push(int val)
{
    if(top==X-1)
    {
        printf("Stack Full Exception");
        exit(1);
    }
    top++;
    stack[top] = val;
}

int pop()
{
    int m;
    if(top==-1)
    {
        printf("Stack Empty Exception");
        exit(2);
    }
    m = stack[top];
    top--;
    return m;
}
