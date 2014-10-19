#include<iostream>
#include<stdlib.h>
using namespace std;
void BFS(int,int,int);
typedef struct queue{
    int data;
    struct queue *next;
}Q;
Q *front=NULL, *rear=NULL;
void enQueue(int);
int deQueue();
int *level,**adj,*onSite,*visited;

int main(void)
{
    int n,m,a,b,count=0;
    cout<<"Number of Vertices and Edges: ";;
    cin>>n>>m;
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

    onSite = new int[n+1];
    for(int i=0;i<=n;i++)       onSite[i] = 0;
    visited= new int[n+1];
    for(int i=0;i<=n;i++)       visited[i] = 0;
    level = new int[n+1];
    for(int i=0;i<=n;i++)       level[i] = -1;

    for(int v=1;v<=n;v++){
        if(level[v]==-1){
            level[v] = 1;
            count++;
            BFS(v,n,m);
        }
    }
    cout<<"\nNo. of Connected Components: "<<count;
    return 0;
}

void BFS(int v, int n, int m)
{
    for(int i=1;i<n;i++){
        visited[v] = 1;
        for(int j=1;j<=n;j++){
            if(adj[v][j]!=0 && onSite[j]!=1 && visited[j]!=1){
                onSite[j] = 1;
                enQueue(j);
            }
        }

        onSite[v] = 0;
        v = deQueue();
        if(v!=-999)     level[v] = 1;
        else            return;
    }
}

void enQueue(int n)
{
    Q *temp;
    temp = new Q;
    temp->data = n;
    temp->next = NULL;
    if(front==NULL){
        front = rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
}

int deQueue()
{
    int n;
    if(front==NULL){
        return -999;
    }
    n = front->data;
    front = front->next;
    return n;
}
