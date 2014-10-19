#include<iostream>
using namespace std;
int main()
{
    typedef struct graph{
        int e,v,**adj;
    }G;
    G *gr;
    int a,b;
    gr = new G;
    cout<<"Enter number of edges and vertices: ";
    cin>>gr->e>>gr->v;
    gr->adj=new int*[gr->v];
    for(int i=0;i<gr->v;i++)    gr->adj[i] = new int[gr->v];
    for(int i=0;i<gr->v;i++)
        for(int j=0;j<gr->v;j++)
            gr->adj[i][j] = 0;
    cout<<"Enter the vertices that are connected: ";
    for(int i=0;i<gr->e;i++){
        cin>>a>>b;
        gr->adj[a-1][b-1] = gr->adj[b-1][a-1] = 1;
    }

    cout<<"Adjacency Matrix:\n";
    for(int i=0;i<gr->v;i++){
        for(int j=0;j<gr->v;j++){
            cout<<gr->adj[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
