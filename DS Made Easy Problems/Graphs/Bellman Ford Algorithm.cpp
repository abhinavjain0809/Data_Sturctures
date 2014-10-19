#include<iostream>
#include<climits>
using namespace std;

int m,n;
int *path,*dis,**weight;

typedef struct queue{
    int data;
    struct queue *next;
}Q;
Q *front=NULL, *rear=NULL;

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

bool isInQueue(int n){
    Q *temp=front;
    while(temp!=NULL){
        if(temp->data==n)   return true;
        temp=temp->next;
    }
    return false;
}

void bellmanFord(int s){
    int v;
    enQueue(s);
    dis[s]=0;
    while(!isQueueEmpty()){
        v = deQueue();
        for(int i=1;i<=n;i++){
            if(weight[v][i]!=0){
                int d = dis[v]+weight[v][i];
                if(d<dis[i]){
                    dis[i]=d;
                    path[i]=v;
                    if(!isInQueue(i))
                        enQueue(i);
                }
            }
        }
    }
}

int main(){
    cout<<"Number of Vertices and Edges: ";
    cin>>n>>m;
    dis = new int[n+1];
    for(int i=0;i<=n;i++)   dis[i]=INT_MAX;

    path = new int[n+1];
    for(int i=0;i<=n;i++)   path[i]=0;

    weight = new int*[n+1];
    for(int i=0;i<=n;i++)   weight[i] = new int[n+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            weight[i][j]=0;

    int a,b,c;
    cout<<"Edges: "<<endl;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        weight[a][b] = c;
    }

    int s;
    cout<<"Enter Source Vertex: ";
    cin>>s;
    bellmanFord(s);
    cout<<"Shortest Distance between source("<<s<<") and given vertex is:\n";
    cout<<"Vertex"<<"\t"<<"Distance"<<endl;
    cout<<"------------------";
    for(int i=1;i<=n;i++){
        if(i!=s)
            cout<<i<<"\t"<<dis[i];
        cout<<endl;
    }

    return 0;
}
