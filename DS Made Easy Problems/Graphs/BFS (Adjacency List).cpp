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

typedef struct node{
    int v;
    struct node *next;
}N;

int m,n;
int *visited;
unsigned int *adj;

void adjacencyList(){
    adj = new unsigned int[n+1];
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

int hasEdge(int a,int b){
    N *ptr;
    ptr = (N*)adj[a];
    while(ptr->v!=b && ptr->next!=NULL){
        ptr = ptr->next;
    }
    if(ptr->v==b)   return 1;
    return 0;
}

void BFS(int v){
    enQueue(v);
    while(!isQueueEmpty()){
        v = deQueue();
        cout<<v<<"\t";
        visited[v]=1;
        for(int i=1;i<=n;i++){
            if(!visited[i] && hasEdge(v,i)){
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
    adjacencyList();
    int v;
    cout<<"Starting Vertex: ";
    cin>>v;
    BFS(v);
    return 0;
}
