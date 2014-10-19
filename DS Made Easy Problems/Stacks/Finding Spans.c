#include<stdio.h>
void push(int, int [], int *);
int pop(int [], int *);
int stackEmpty(int [], int *);
int main()
{
    int top=-1, i, days, price[50], stack[50], p, done, span[50];
    printf("Enter number of days for the Stock Market: ");
    scanf("%d", &days);
    printf("\nEnter prices for the days in the stock market: ");
    for(i=0;i<days;i++)         scanf("%d", &price[i]);

    for(i=0;i<days;i++)
    {
        done = 1;
        while(!stackEmpty(stack, &top) && done)
        {
            if(price[i]>price[stack[top]])      pop(stack, &top);
            else        done = 0;
        }
        if(stackEmpty(stack, &top))       p = -1;
        else                              p = stack[top];
        span[i] = i-p;
        push(i, stack, &top);
    }

    printf("\n\nThe Spans for the corresponding prices are:\n");
    for(i=0;i<days;i++)     printf("\n%d --> %d\n", price[i], span[i]);
    return 0;
}

void push(int x, int stack[], int *top)
{
    (*top)++;
    stack[*top] = x;
}

int pop(int stack[], int *top)
{
    int p;
    p = stack[*top];
    (*top)--;
    return p;
}

int stackEmpty(int stack[], int *top)
{
    if(*top==-1)    return 1;
    else            return 0;
}
