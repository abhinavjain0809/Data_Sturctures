#include<iostream>
using namespace std;
void DFS(int,int,int);
typedef struct stack{
    int data;
    struct stack *next;
}stk;
stk *top=NULL;
void push(int);
int pop();
int main(void)
{
    int n,m,v;
    cout<<"Number of vertices and edges: ";
    cin>>n>>m;
    cout<<"Initial Vertex: ";
    cin>>v;
    DFS(n,m,v);
    return 0;
}

void DFS(int n, int m, int v)
{
    int a,b,**adj;
    int onSite[n+1], visited[n+1];
    //top = new stk;
//    top->next = NULL;
    adj = new int*[n+1];
    for(int i=0;i<=n;i++)   adj[i] = new int[n+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            adj[i][j] = 0;

    cout<<"\nConnected Edges:\n";     // Adjacency Matrix...
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a][b] = adj[b][a] = 1;
    }
    cout<<"Adjacency Matrix:\n\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<adj[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<"\nOrder of Visiting the nodes:\n"<<v<<"\t";
    visited[v]=1;
    for(int i=1;i<n;i++){
        for(int j=n;j>=1;j--){
            if(visited[j]!=1 && onSite[j]!=1 && adj[v][j]!=0){
                onSite[j]=1;
                push(j);
            }
        }
        v = pop();
        cout<<v<<"\t";
        visited[v]=1;
        onSite[v]=0;
    }
}

void push(int n)
{
    stk *temp;
    temp = new stk;
    temp->data = n;
    temp->next = NULL;
    if(top==NULL){
        top = temp;
    }
    else{
        temp->next = top;
        top = temp;
    }
}

int pop()
{
    stk *temp = new stk;
    int n = top->data;
    temp = top;
    top = top->next;
    delete temp;
    return n;
}
