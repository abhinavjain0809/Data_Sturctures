#include<iostream>
#include<ctype.h>
#include<cstdlib>

using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}N;
N *temp;
unsigned int start[10];

void hashSpace(void);
void input(void);
void display(void);
void search(int);

int main(void)
{
    int n;
    hashSpace();
    input();
    display();

    cout<<"Enter the data to search: ";
    cin>>n;
    search(n);
    return 0;
}

void hashSpace()
{
    for(int i=0;i<10;i++){
        start[i] = NULL;
    }
}
void input()
{
    int n, t;
    N *add[10];
    char ans = 'Y';
    while(toupper(ans)=='Y'){
        cout<<"Data: ";
        cin>>n;
        t = n%10;
        temp = new N;
        temp->data = n;
        temp->next = NULL;
        if(start[t]==NULL){
            start[t] = (unsigned int)temp;
            add[t] = temp;
        }
        else{
            temp->next = add[t];
            start[t] = (unsigned int)temp;
            add[t] = temp;
        }

        cout<<"Continue (Y/N): ";
        cin>>ans;
    }
}

void display()
{
    N *ptr;
    for(int i=0;i<10;i++){
        cout<<"Key : "<<i<<"\t";
        ptr = (N*)start[i];
        while(ptr!=NULL){
            cout<<ptr->data<<"\t";
            ptr = ptr->next;
        }
        cout<<endl;
    }
}

void search(int n)
{
    int t = n%10;
    N *temp1;
    //temp1 = new N;
    temp1 = (N*)start[t];

    while(temp1!=NULL){
        if(temp1->data==n){
            cout<<"Data Exists!!!"<<endl;
            return;
        }
        temp1 = temp1->next;
    }
    cout<<"Data does not exist!!!";
}
