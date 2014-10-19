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

int main(void)
{
    int n,m,v;
    cout<<"Number of Vertices and Edges: ";
    cin>>n>>m;
    cout<<"\nStarting Vertex: ";
    cin>>v;
    BFS(n,m,v);
    return 0;
}

void BFS(int n, int m, int v)
{
    int a,b,**adj;
    int onSite[n+1], visited[n+1];
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
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<adj[i][j]<<"\t";
        }
        cout<<endl;
    }


    cout<<"\nOrder of Visiting the nodes:\n"<<v<<"\t";

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
        cout<<v<<"\t";
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
        //cout<<"Queue Empty";
        exit(1);
    }
    n = front->data;
    front = front->next;
    return n;
}
