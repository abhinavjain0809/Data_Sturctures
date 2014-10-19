#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void push(char);
char pop();
typedef struct node
{
    char data;
    struct node *next;
}N;
N *start=NULL;
int main()
{
    char str[50];
    int i=0, m, n, x, ans;
    char a, b;
    printf("Postfix Expression: ");
    gets(str);
    while(str[i]!='\0')
    {
        if(str[i]=='+' || str[i]=='-' || str[i]=='/' || str[i]=='*' || str[i]=='^')
        {
            a = pop();
            b = pop();
            m = a-48;
            n = b-48;
            switch(str[i])
            {
                case '+':   push(48+(n+m));
                            break;

                case '-':   push(48+(n-m));
                            break;

                case '/':   push(48+(n/m));
                            break;

                case '*':   push(48+(n*m));
                            break;

                case '^':   x = pow(n,m);
                            push(48+x);
                            break;
            }
        }
        else    push(str[i]);
        i++;
    }
    ans = pop()-48;
    printf("Result: %d", ans);
    return 0;
}

void push(char c)
{
    N *new;
    new = (N*)malloc(sizeof(N));
    new->data=c;
    if(start==NULL)
    {
        start=new;
        new->next=NULL;
    }
    else
    {
        new->next=start;
        start=new;
    }
}

char pop()
{
    char c;
    c = start->data;
    start = start->next;
    return c;
}
