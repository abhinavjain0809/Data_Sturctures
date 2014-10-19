#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

struct Edge{
    int src,dest,weight;
};

struct Graph{
    int v,e;
    struct Edge *edge;
};

int cmp(const void *a,const void *b){
    struct Edge *a1 = (struct Edge*)a;
    struct Edge *b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

int find(int subset[],int i){
    if(subset[i]==-1)   return i;
    else    return find(subset,subset[i]);
}

void Union(int subset[],int x,int y){
    int xset = find(subset,x);
    int yset = find(subset,y);
    subset[xset] = yset;
}

void kruskal(struct Graph *g){
    struct Edge result[g->v];
    qsort(g->edge,g->e,sizeof(g->edge[0]),cmp);

    int *subset = new int[g->v+1];
    memset(subset,-1,sizeof(int)*(g->v+1));
    int e=0,k=0;
    while(e<(g->v-1)){
        struct Edge nextEdge = g->edge[k++];
        int x = find(subset,nextEdge.src);
        int y = find(subset,nextEdge.dest);

        if(x!=y){
            result[e++] = nextEdge;
            Union(subset,x,y);
        }
    }

    for(int i=0;i<(g->v-1);i++){
        cout<<result[i].src<<"  "<<result[i].dest<<"  "<<result[i].weight<<endl;
    }
}

int main(){
    struct Graph *g = new Graph;
    cout<<"Number of Vertices and Edges: ";
    cin>>g->v>>g->e;
    g->edge = new Edge[g->e];
    int a,b,c;
    cout<<"Edges and their weights:\n";
    for(int i=0;i<g->e;i++){
        cin>>a>>b>>c;
        g->edge[i].src = a;
        g->edge[i].dest = b;
        g->edge[i].weight = c;
    }
    kruskal(g);
    return 0;
}
