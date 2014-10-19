#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void push(int [], int *, int);
int pop(int [], int *);

int main()
{
    int mainStack[50], minStack[50], maxStack[50];
    int data, mainTop=-1, minTop=-1, maxTop=-1, i;
    char ans='Y';

    while(toupper(ans)=='Y')
    {
        printf("Data: ");
        scanf("%d", &data);
        push(mainStack, &mainTop, data);
        if(minTop==-1 || minStack[minTop]>data)         push(minStack, &minTop, data);
        if(maxTop==-1 || maxStack[maxTop]<data)         push(maxStack, &maxTop, data);

        fflush(stdin);
        printf("Continue(Y/N): ");
        scanf("%c", &ans);
    }

    printf("\n\nMain Stack:\n");
    for(i=0;i<mainTop;i++)      printf("%d\t", mainStack[i]);

    printf("\n\nMin Stack:\n");
    for(i=0;i<minTop;i++)      printf("%d\t", minStack[i]);

    printf("\n\nMax Stack:\n");
    for(i=0;i<maxTop;i++)      printf("%d\t", maxStack[i]);

    printf("\n\nMinimum Element: %d", pop(minStack, &minTop));
    printf("\nMaximum Element: %d", pop(maxStack, &maxTop));
    return 0;
}

void push(int stack[], int *top, int val)
{
    if(*top==49)
    {
        printf("\n\nStack Full Exception!!");
        exit(1);
    }
    (*top)++;
    stack[*top] = val;
}

int pop(int stack[], int *top)
{
    int val;
    if(*top==-1)
    {
        printf("Stack Empty Exception!!");
        exit(2);
    }
    val = stack[*top];
    (*top)--;
    return val;
}
