#include<iostream>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    int a[m][n];
    int b[m*n],k=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];

    int top=0, bottom=m-1;
    int left=0, right=n-1;
    for(int j=1;j<=m/2 && j<=n/2;j++){
        for(int i=left;i<=right;i++){
            b[k++] = a[top][i];
        }
        for(int i=top+1;i<=bottom;i++){
            b[k++] = a[i][right];
        }
        for(int i=right-1;i>=left;i--){
            b[k++] = a[bottom][i];
        }
        for(int i=bottom-1;i>=top+1;i--){
            b[k++] = a[i][left];
        }
        top++;  bottom--;
        left++; right--;
    }

    if(top==bottom && left==right)      b[k++] = a[top][left];
    else if(top<bottom){
        for(int i=top;i<=bottom;i++){
            b[k++] = a[i][left];
        }
    }
    else if(left<right){
        for(int i=left;i<=right;i++){
            b[k++] = a[top][i];
        }
    }
    for(int i=0;i<k;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
