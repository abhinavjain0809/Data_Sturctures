#include<stdio.h>
#include<stdlib.h>
void push(char);
char pop();
int ip(char);
int sp(char);
char stack[50];
int top=-1;
main()
{
    char str[50], exp[50];
    int i=0, k=0;
    char c;
    printf("Infix Expression: ");
    gets(str);
    push('#');
    while(str[i]!='#')
    {
        c = str[i];
        if(c!='/' && c!='*' && c!='+' && c!='-' && c!='^' && c!='(' && c!=')')      exp[k++] = c;
        else if(c=='(')     push('(');
        else if(c==')')
        {
            while(stack[top]!='(')   exp[k++] = pop();
            top--;
        }
        else
        {
            while(sp(stack[top])>=ip(c))       exp[k++]=pop();
            push(c);
        }
        i++;
    }
    if(str[i]=='#')
        while(stack[top]!='#')    exp[k++] = pop();

    exp[k]='\0';
    puts(exp);
    return 0;
}

void push(char x)
{
    if(top==49)
    {
       printf("Stack OVERFLOW");
        system("pause");
        exit(1);
    }
    top++;
    stack[top] = x;
}

char pop()
{
    char x;
    if(top==-1)
    {
        printf("Stack UNDERFLOW");
        system("pause");
        exit(2);
    }
    x = stack[top];
    top--;
    return x;
}

int ip(char x)
{
    switch(x)
    {
        case '^':   return 4;
        case '+':
        case '-':   return 1;
        case '/':
        case '*':   return 2;
        case '(':   return 4;
        case '#':   return 0;
    }
}

int sp(char x)
{
    switch(x)
    {
        case '^':   return 3;
        case '+':
        case '-':   return 1;
        case '/':
        case '*':   return 2;
        case '(':   return 0;
        case '#':   return -1;
    }
}
