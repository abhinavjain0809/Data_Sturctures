#include<iostream>
#include<cmath>
using namespace std;

void infix2postfix(char []);
void push(char, char [], int *);
void pop(char [], int *);

typedef struct node
{
    char data;
    struct node *next;
}N;
N *start=NULL;
void postfixEvaluation(void);
void push(char);
char pop(void);

static int l=0, m=0, len=0;
char postfix[75];

int main(void)
{
    char str[75];
    cout<<"Converting Infix to Postfix Expression:\n";
    cout<<"Infix Expression: ";
    cin>>str;
    infix2postfix(str);

    postfixEvaluation();
    return 0;
}

void infix2postfix(char str[])
{
    int top=-1, i=0;
    char stack[75];
    while(str[i]!='\0')
    {
        switch(str[i])
        {
            case '^':
            if(stack[top]!='^')     push(str[i], stack, &top);
            else
            {
                while(stack[top]=='^')
                    pop(stack, &top);
                push(str[i], stack, &top);
            }
            break;

            case '/':
            case '*':
            if(stack[top]!='^' && stack[top]!='/' && stack[top]!='*')   push(str[i], stack, &top);
            else
            {
                while(stack[top]=='^' || stack[top]=='/' || stack[top]=='*')
                    pop(stack, &top);
                push(str[i], stack, &top);
            }
            break;

            case '+':
            case '-':
            if(stack[top]!='^' && stack[top]!='/' && stack[top]!='*' && stack[top]!='+' && stack[top]!='-')
                push(str[i], stack, &top);
            else
            {
                while(stack[top]=='^' || stack[top]=='/' || stack[top]=='*' || stack[top]=='+' || stack[top]=='-')
                    pop(stack, &top);
                push(str[i], stack, &top);
            }
            break;

            case '(':
            push(str[i], stack, &top);
            break;

            case ')':
            while(stack[top]!='(')      pop(stack, &top);
            top--;
            break;

            default:
            len++;
            postfix[l++] = str[i];
        }
        i++;
    }
    for(i=top;i>=0;i--)
    {
        postfix[l++] = stack[top];
        top--;
    }
    cout<<"Postfix Expression:\n"<<postfix;
}

void push(char x, char stack[], int *top)
{
    (*top)++;
    stack[*top] = x;
}

void pop(char stack[], int *top)
{
    postfix[l++] = stack[*top];
    (*top)--;
}

void postfixEvaluation()
{
    int i=0, m, n, x, ans;
    char a, b, post[50];

    cout<<"\n\nEvaluating Postfix Expression\n"<<"Input Postfix Expression: ";
    cin>>post;

    while(post[i]!='\0')
    {
        if(post[i]=='+' || post[i]=='-' || post[i]=='/' || post[i]=='*' || post[i]=='^')
        {
            a = pop();
            b = pop();
            m = a-48;
            n = b-48;
            switch(post[i])
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
        else        push(post[i]);

        i++;
    }
    ans = pop()-48;
    cout<<"Result: "<<ans;
}

void push(char c)
{
    N *temp;
    temp = new N;
    temp->data=c;
    if(start==NULL)
    {
        start=temp;
        temp->next=NULL;
    }
    else
    {
        temp->next=start;
        start=temp;
    }
}

char pop()
{
    char c;
    c = start->data;
    start = start->next;
    return c;
}
