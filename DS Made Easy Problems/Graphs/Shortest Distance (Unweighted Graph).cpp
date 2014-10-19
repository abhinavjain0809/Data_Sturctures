// The distance indirectly represents the level the vertex will be at in a BFS Tree...
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct queue{
    int data;
    struct queue *next;
}Q;
Q *front=NULL, *rear=NULL;
void enQueue(int);
int deQueue();
int isQueueEmpty();

int m,n;
int *dis,*path,**adj;

void levelNumber(int s){
    int v;
    enQueue(s);
    while(!isQueueEmpty()){
        v = deQueue();
        //cout<<v<<"\t";
        //visited[v]=1;
        for(int i=1;i<=n;i++){
            if(adj[v][i] && dis[i]==-1){
                dis[i] = dis[v]+1;
                path[i]=v;
                enQueue(i);
                //visited[i]=1;
            }
        }
    }
    cout<<"Shortest Distance between source (vertex "<<s<<") and vertex:"<<endl;
    for(int i=1;i<=n;i++){
        if(i==s)    continue;
        cout<<i<<": "<<dis[i]<<" units"<<endl;
    }
}

int isQueueEmpty(){
    if(front==NULL)     return 1;
    else                return 0;
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
    n = front->data;
    front = front->next;
    return n;
}

int main(){
    cout<<"Number of Vertices and Edges: ";
    cin>>n>>m;
    dis = new int[n+1];
    for(int i=0;i<=n;i++)   dis[i]=-1;

    path = new int[n+1];
    for(int i=0;i<=n;i++)   path[i]=0;

    adj = new int*[n+1];
    for(int i=0;i<=n;i++)   adj[i] = new int[n+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            adj[i][j]=0;

    int a,b;
    cout<<"Edges: "<<endl;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a][b] = adj[b][a] = 1;
    }
    int s;
    cout<<"Enter source vertex: ";
    cin>>s;
    dis[s]=0;
    levelNumber(s);
    return 0;
}
