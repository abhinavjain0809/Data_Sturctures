/*  path[] gives the Max Spanning Tree structure...
*/
#include<iostream>
using namespace std;

typedef struct queue{
    int data;
    int weight;
    struct queue *next;
}Q;
Q *front=NULL, *rear=NULL;

int m,n;
int *path,**cost,*dis;

int isQueueEmpty(){
    if(front==NULL)     return 1;
    else                return 0;
}

void enQueue(int n,int d)
{
    Q *temp;
    temp = new Q;
    temp->data = n;
    temp->weight = d;
    temp->next = NULL;
    if(front==NULL){
        front = rear = temp;
    }
    else{
        Q *ptr=front,*x=front;
        while(ptr!=NULL && ptr->weight<d){
            x=ptr;
            ptr=ptr->next;
        }
        if(ptr==NULL){
            x->next=temp;
            rear=temp;
        }
        else if(x==ptr){
            temp->next=ptr;
            front=temp;
        }
        else if(ptr->weight>=d){
            x->next=temp;
            temp->next=ptr;
        }
    }
}

int deQueue()
{
    int n;
    n = front->data;
    front = front->next;
    return n;
}

void updateQueue(int v,int d){
    Q *ptr=front;
    while(ptr->data!=v && ptr!=NULL)     ptr=ptr->next;
    if(ptr->data==v)    ptr->weight=d;
}

void prims(int s){
    int v,w,d;
    dis[s]=0;
    enQueue(s,dis[s]);
    while(!isQueueEmpty()){
        v = deQueue();
        cout<<"v: "<<v<<endl;
        for(int w=1;w<=n;w++){
            cout<<"w: "<<w<<endl;
            if(cost[v][w]!=0){
                d = dis[v]+cost[v][w];
                cout<<"d: "<<d<<endl;
                if(dis[w]==0){
                    dis[w]=cost[v][w];
                    cout<<"Before EnQueue"<<endl;
                    enQueue(w,d);
                    cout<<"After EnQueue"<<endl;
                    path[w]=v;
                }
                if(dis[w]>d){
                    dis[w]=cost[v][w];
                    cout<<"Before Update"<<endl;
                    updateQueue(w,d);
                    cout<<"After Update"<<endl;
                    path[w]=v;
                }
                cout<<"----------------"<<endl;
            }
        }
    }
}

int main(){
    cout<<"Number of Vertices and Edges: ";
    cin>>n>>m;
    path = new int[n+1];
    for(int i=0;i<=n;i++)   path[i]=0;

    dis = new int[n+1];
    for(int i=0;i<=n;i++)   dis[i]=0;

    cost = new int*[n+1];
    for(int i=0;i<=n;i++)   cost[i] = new int[n+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            cost[i][j]=0;

    int a,b,c;
    cout<<"Edges and their cost: <From> <To> <Weight of the Edge>"<<endl;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        cost[a][b] = -1*c;
    }
    int s;
    cout<<"Source Vertex: ";
    cin>>s;
    prims(s);
    for(int i=1;i<=n;i++)   cout<<i<<"  ";
    cout<<endl;
    for(int i=1;i<=n;i++)   cout<<dis[i]<<"  ";
    cout<<endl;
    for(int i=1;i<=n;i++)   cout<<path[i]<<"  ";
    return 0;
}
