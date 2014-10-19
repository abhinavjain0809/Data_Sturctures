#include<stdio.h>
#include<stdlib.h>
void push(char, char [], int *);
void pop(char [], char, int *);
int main()
{
    int i=0, top=-1;
    char str[50], stack[50];

    printf("Input Expression: ");
    scanf("%s", str);
    while(str[i]!='\0')
    {
        if(str[i]=='('||str[i]=='{'||str[i]=='[')       push(str[i], stack, &top);

        else if(str[i]==')'||str[i]=='}'||str[i]==']')  pop(stack, str[i], &top);

        i++;
    }
    printf("Expression is correct...");
    return 0;
}

void push(char x, char stack[], int *top)
{
    (*top)++;
    stack[*top] = x;
}

void pop(char stack[], char y, int *top)
{
    char x;
    x = stack[*top];
    if(*top==-1)
    {
        printf("LIMITER MISMATCH!!!");
        system("pause");
        exit(1);
    }
    else if(y==')' && x=='(')       (*top)--;
    else if(y=='}' && x=='{')       (*top)--;
    else if(y==']' && x=='[')       (*top)--;
    else
    {
        printf("LIMITER MISMATCH!!!");
        system("pause");
        exit(2);
    }
}
