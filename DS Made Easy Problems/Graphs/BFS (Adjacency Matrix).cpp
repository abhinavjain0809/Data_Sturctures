#include<iostream>
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
int *visited,**adj;

void BFS(int v){
    enQueue(v);
    while(!isQueueEmpty()){
        v = deQueue();
        cout<<v<<"\t";
        visited[v]=1;
        for(int i=1;i<=n;i++){
            if(!visited[i] && adj[v][i]){
                enQueue(i);
                visited[i]=1;
            }
        }
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
    visited = new int[n+1];
    for(int i=0;i<=n;i++)   visited[i]=0;

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
    int v;
    cout<<"Starting Vertex: ";
    cin>>v;
    BFS(v);
    return 0;
}
