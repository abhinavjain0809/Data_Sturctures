#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

typedef struct node
{
    int data;
    int deg;
    char sign;
    struct node *next;
}N;

N *create(void);
void display(N*);
void evaluate(N*,int);

int main(void)
{
    N *poly=NULL;
    int x;
    cout<<"Polynomial:\n";
    poly = create();
    cout<<"\nFunction:\n";
    display(poly);

    cout<<"\n\nEnter the value for the variable x: ";
    cin>>x;
    evaluate(poly,x);
    return 0;
}

N* create(void)
{
    N *start=NULL, *ptr, *temp;
    char ans='Y';
    while(toupper(ans)=='Y')
    {
        temp = new N;
        if(temp==NULL)
        {
            cout<<"OUT OF MEMORY!!!";
            exit(1);
        }

        cout<<"Coefficient: ";
        cin>>temp->data;
        cout<<"Degree for coefficient: ";
        cin>>temp->deg;
        if(temp->data>=0)    temp->sign = '+';
        else                 temp->sign = '-';
        temp->next=NULL;

        if(start==NULL)     start = temp;
        else
        {
            ptr = start;
            while(ptr->next!=NULL)      ptr = ptr->next;
            ptr->next = temp;
        }

        cout<<"Insert more Terms(Y/N): ";
        cin>>ans;
    }
    return start;
}

void display(N *start)
{
    N *ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->data>0)     cout<<" +"<<ptr->data<<"x^"<<ptr->deg<<" ";
        else if(ptr->data==0);         //cout<<" "<<ptr->data<<"x^"<<ptr->deg<<" ";
        else if(ptr->data<0)         cout<<" "<<ptr->data<<"x^"<<ptr->deg<<" ";
        ptr = ptr->next;
    }
}

void evaluate(N *start, int x)
{
    N *ptr = start;
    int power,sum=0;
    while(ptr!=NULL){
        power = pow(x,ptr->deg);
        sum += ptr->data*power;
        ptr = ptr->next;
    }
    cout<<"Result: "<<sum;
}
