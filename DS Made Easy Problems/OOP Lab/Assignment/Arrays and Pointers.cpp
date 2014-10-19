#include<iostream>
#include<cstdio>
using namespace std;

void rcUnknown();
void rUnknown();
void cUnknown();

int main(void){
    rcUnknown();
    cout<<endl;
    rUnknown();
    cout<<endl;
    cUnknown();
    return 0;
}

void rcUnknown(){
    int **p;
    int r,c;
    cout<<"Enter the number of rows and columns: ";
    cin>>r>>c;
    p = new int*[r];
    for(int i=0;i<r;i++)    p[i] = new int[c];

    cout<<"Enter elements: ";
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>p[i][j];

    cout<<"Matrix when rows and columns were unknown: "<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            cout<<p[i][j]<<"\t";
        cout<<endl;
    }
}

void rUnknown(){
    int r;
    cout<<"Columns = 3"<<endl;
    cout<<"Enter number of rows: ";
    cin>>r;
    int (*q)[3];
    q = new int[r][3];

    cout<<"Enter elements: ";
    for(int i=0;i<r;i++)
        for(int j=0;j<3;j++)
            cin>>q[i][j];

    cout<<"Matrix when rows are unknown and columns = 3: "<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<3;j++){
                cout<<q[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void cUnknown(){
    int c;
    cout<<"Rows = 3"<<endl;
    cout<<"Enter number of columns: ";
    cin>>c;
    int *s[3];
    for(int i=0;i<3;i++)    s[i] = new int[c];

    cout<<"Enter elements: ";
    for(int i=0;i<3;i++)
        for(int j=0;j<c;j++)
            cin>>s[i][j];

    cout<<"Matrix when columns are unknown and rows=3: "<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<c;j++)
            cout<<s[i][j]<<"\t";
        cout<<endl;
    }
}
