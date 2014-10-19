#include<iostream>
#include<cstring>
using namespace std;

struct Edge{
    int src,dest;
};

struct Graph{
    int e,v;
    struct Edge *adj;
};

int find(int parent[],int i){
    if(parent[i]==-1)   return i;
    return find(parent,parent[i]);
}

void Union(int parent[],int x,int y){
    int xset = find(parent,x);
    int yset = find(parent,y);
    parent[xset] = yset;
}

bool containsCycle(Graph *g){
    int *parent = new int[g->v+1];
    memset(parent,-1,(g->v+1)*sizeof(int));
    for(int i=0;i<g->e;i++){
        int x = find(parent,g->adj[i].src);
        int y = find(parent,g->adj[i].dest);

        if(x==y)    return true;
        Union(parent,x,y);
    }
    return false;
}

int main(){
    Graph *graph = new Graph;
    cout<<"Number of Vertices and Edges: ";
    cin>>graph->v>>graph->e;
    graph->adj = new Edge[graph->e];
    int a,b;
    cout<<"Edges:"<<endl;
    for(int i=0;i<graph->e;i++){
        cin>>a>>b;
        graph->adj[i].src = a;
        graph->adj[i].dest = b;
    }

    if(containsCycle(graph))
        cout<<"The Graph contains cycle";
    else
        cout<<"The Graph does not contain any cycle";

    return 0;
}
