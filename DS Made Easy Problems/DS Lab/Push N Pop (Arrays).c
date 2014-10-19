#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int push(int [], int, int *);
int pop(int [], int *);
main()
{
    int stack[100], top=-1, val, i;
    char ans='Y';

    //PUSH...
    while(toupper(ans)=='Y')
    {
        printf("Enter Data: ");
        scanf("%d", &val);
        push(stack, val, &top);
        fflush(stdin);
        printf("Add more elements to stack(Y/N): ");
        scanf("%c", &ans);
    }
    printf("\nStack after Pushing is:\n");
    for(i=0;i<=top;i++)     printf("%d\t", stack[i]);

    //POP...
    fflush(stdin);
    printf("\n\nPop out elememts(Y/N): ");
    scanf("%c", &ans);

    while(toupper(ans)=='Y')
    {
        pop(stack, &top);
        fflush(stdin);
        printf("Want to pop out more(Y/N): ");
        scanf("%c", &ans);
    }
    printf("\nStack after popping is:\n");
    for(i=0;i<=top;i++)     printf("%d\t", stack[i]);

    return 0;
}

int push(int stack[], int val, int *top)
{
    if(*top==99)
    {
       printf("Stack OVERFLOW");
        system("pause");
        exit(1);
    }
    (*top)++;
    stack[*top] = val;
}

int pop(int stack[], int *top)
{
    if(*top==-1)
    {
        printf("Stack UNDERFLOW");
        system("pause");
        exit(2);
    }
    (*top)--;
}
