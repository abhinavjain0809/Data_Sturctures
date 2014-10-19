#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct queue{
    int data;
    int level;
    struct queue *next;
}Q;
Q *front=NULL, *rear=NULL;
void enQueue(int);
void enQueue0();
int **adj,*visited,*val;
int k=0,count=0,prevcount=0;
static int l=0,m=0;

int main(void)
{
    int n,m,a,b,v;
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

    visited= new int[n+1];
    for(int i=0;i<=n;i++)       visited[i] = 0;
    val = new int[n+1];
    for(int i=0;i<=n;i++)       val[i] = 0;

    cout<<"\nInitial Vertex: ";
    cin>>v;

    val[l++] = v;
    m=0;
    v = val[m++];
    enQueue(v);
    visited[v] = 1;
    enQueue0();
    for(int i=1;i<n;i++){
        while(prevcount!=0){
            for(int j=1;j<=n;j++){
                if(adj[v][j]!=0 && visited[j]!=1){
                    enQueue(j);
                    val[l++] = j;
                    visited[j] = 1;
                }
            }
            v = val[m++];
            prevcount--;
        }
        enQueue0();
    }

    cout<<"\nVertex\tLevel";
    cout<<"\n--------------\n";
    Q *ptr = front;
    while(ptr!=NULL){
        if(ptr->data!=0){
            cout<<ptr->data<<"\t"<<ptr->level<<endl;
        }
        ptr = ptr->next;
    }
    return 0;
}

void enQueue(int n)
{
    Q *temp,*temp1;
    temp = new Q;
    temp->data = n;
    temp->level = k;
    temp->next = NULL;

    if(front==NULL){
        front = rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
    count++;
}

void enQueue0()
{
    Q *temp;
    temp = new Q;
    temp->data = 0;
    temp->level = -999;
    temp->next = NULL;
    if(front==NULL)    front = rear = NULL;
    else{
        rear->next = temp;
        rear = temp;
    }
    prevcount = count;
    count=0;
    k++;
}
