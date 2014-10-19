#include<iostream>
using namespace std;
void adjacencyList(int,int);

typedef struct node{
    int v;
    struct node *next;
}N;

int main(){
    int m,n;
    cout<<"Number of Vertices and Edges: ";
    cin>>n>>m;
    adjacencyList(n,m);
    return 0;
}

void adjacencyList(int n,int m){
    unsigned int adj[n+1];
    for(int i=0;i<=n;i++){
        adj[i] = NULL;
    }
    int a,b;
    N *temp1,*temp2;
    cout<<"Connected Edges: "<<endl;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        temp1 = new N;
        temp1->v = a;
        temp1->next=NULL;
        if(adj[b]==NULL){
            adj[b] = (unsigned int)temp1;
        }
        else{
            temp1->next = (N*)adj[b];
            adj[b]=(unsigned int)temp1;
        }
        temp2 = new N;
        temp2->v = b;
        temp2->next=NULL;
        if(adj[a]==NULL){
            adj[a] = (unsigned int)temp2;
        }
        else{
            temp2->next = (N*)adj[a];
            adj[a]=(unsigned int)temp2;
        }
    }
    cout<<endl<<"Adjacency List: "<<endl;
    N *ptr;
    for(int i=1;i<=n;i++){
        cout<<i<<": ";
        ptr = (N*)adj[i];
        while(ptr!=NULL){
            cout<<ptr->v<<"\t";
            ptr=ptr->next;
        }
        cout<<endl;
    }
}
