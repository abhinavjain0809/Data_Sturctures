#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int cost[10][10],i,j,k,n,stk[10],top,v,visit[10],visited[10];
int main(void)
{
    int m;
    cout<<"No. of Vertices: ";
    cin>>n;
    cout<<"No. of Edges: ";
    cin>>m;
    cout<<"\nConnected Edges:\n";
    for(k=1;k<=m;k++){
        cin >>i>>j;
        cost[i][j]=1;
    }
    cout <<"Initial Vertex: ";
    cin>>v;
    cout<<"\nORDER OF VISITED VERTICES: ";
    cout<<v<<" ";
    visited[v]=1;
    k=1;
    while(k<n){
        for(j=n;j>=1;j--)
            if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1){
                visit[j]=1;
                stk[top]=j;
                top++;
            }
            v=stk[--top];
            cout<<v<<" ";
            k++;
            visit[v]=0;
            visited[v]=1;
    }
}
