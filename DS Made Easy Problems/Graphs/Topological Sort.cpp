#include<iostream>
using namespace std;

int m,n,cycle=0;
int *indegree,*topologicalOrder,**adj;

typedef struct queue{
    int data;
    struct queue *next;
}Q;
Q *front=NULL, *rear=NULL;
void enQueue(int);
int deQueue();
int isQueueEmpty();

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

void topSort(){
    int counter=1,v;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0)      enQueue(i);
    }
    while(!isQueueEmpty()){
        v = deQueue();
        topologicalOrder[v] = counter++;
        for(int j=1;j<=n;j++){
            if(adj[v][j] && --indegree[j]==0)   enQueue(j);
        }
    }
    if(counter!=n+1){
        cout<<"Graph has a Cycle"<<endl;
        cycle=1;
    }
}

int main(){
    cout<<"Number of Vertices and Edges: ";
    cin>>n>>m;
    indegree = new int[n+1];
    for(int i=0;i<=n;i++)   indegree[i]=0;

    topologicalOrder = new int[n+1];
    for(int i=0;i<=n;i++)   topologicalOrder[i]=0;

    adj = new int*[n+1];
    for(int i=0;i<=n;i++)   adj[i] = new int[n+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            adj[i][j]=0;

    int a,b;
    cout<<"Edges: "<<endl;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a][b] = 1;
        indegree[b]++;
    }
/*
    cout<<"Indegree: "<<endl;
    for(int i=1;i<=n;i++)   cout<<indegree[i]<<"  ";
    cout<<endl;
*/
    topSort();
    /*for(int i=1;i<=n;i++)   cout<<i<<"  ";
    cout<<endl;
    for(int i=1;i<=n;i++)   cout<<topologicalOrder[i]<<"  ";*/

    int k=1;
    if(!cycle){
        while(k!=n+1){
            for(int i=1;i<=n;i++){
                if(topologicalOrder[i]==k)  cout<<i<<"  ";
            }
            k++;
        }
    }
    return 0;
}
