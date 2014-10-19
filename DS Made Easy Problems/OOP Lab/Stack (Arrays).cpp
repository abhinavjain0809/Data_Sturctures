#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<process.h>
using namespace std;

int push(int [], int, int *);
int pop(int [], int *);

int main(void)
{
    int stack[100], top=-1, val, i;
    char ans='Y';

    //PUSH...
    while(toupper(ans)=='Y')
    {
        cout<<"Enter Data: ";
        cin>>val;
        push(stack, val, &top);
        fflush(stdin);
        cout<<"Add more elements to stack(Y/N): ";
        cin>>ans;
    }
    cout<<"\nStack after Pushing is:\n";
    for(i=0;i<=top;i++)     cout<<"\t"<<stack[i];

    //POP...
    fflush(stdin);
    cout<<"\n\nPop out elememts(Y/N): ";
    cin>>ans;

    while(toupper(ans)=='Y')
    {
        pop(stack, &top);
        fflush(stdin);
        cout<<"Want to pop out more(Y/N): ";
        cin>>ans;
    }
    cout<<"\nStack after popping is:\n";
    for(i=0;i<=top;i++)     cout<<"\t"<<stack[i];

    return 0;
}

int push(int stack[], int val, int *top)
{
    if(*top==99)
    {
        cout<<"Stack OVERFLOW";
        //exit(1);
    }
    (*top)++;
    stack[*top] = val;
}

int pop(int stack[], int *top)
{
    if(*top==-1)
    {
        cout<<"Stack UNDERFLOW";
        //exit(2);
    }
    (*top)--;
}
