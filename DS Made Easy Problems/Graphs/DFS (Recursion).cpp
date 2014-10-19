#include<iostream>
using namespace std;

int m,n;
int *visited,**adj;

void DFS(int v){
    visited[v]=1;
    cout<<v<<"\t";
    for(int i=1;i<=n;i++){
        if(!visited[i] && adj[v][i])     DFS(i);
    }
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
    DFS(v);
    return 0;
}
