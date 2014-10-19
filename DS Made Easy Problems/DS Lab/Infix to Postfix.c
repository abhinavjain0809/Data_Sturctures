#include<stdio.h>
void push(char, char [], int *);
void pop(char [], int *);
main()
{
    int top=-1, i=0, len;
    char stack[75], str[75];

    printf("INFIX Expression: ");
    gets(str);

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
            printf("%c", str[i]);
        }
        i++;
    }
    for(i=top;i>=0;i--)
    {
        printf("%c", stack[top]);
        top--;
    }
    return 0;
}

void push(char x, char stack[], int *top)
{
    (*top)++;
    stack[*top] = x;
}

void pop(char stack[], int *top)
{
    printf("%c", stack[*top]);
    (*top)--;
}
