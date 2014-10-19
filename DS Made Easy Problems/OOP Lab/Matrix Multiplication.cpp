#include<iostream>
#include<cstdlib>
using namespace std;

int main(void)
{
    int i,j,k,r1,c1,r2,c2,sum=0;
    int **m1, **m2, **m3;
    cout<<"Matrix 1:"<<endl;
    cout<<"No of rows and columns: ";
    cin>>r1>>c1;

    cout<<"\nMatrix 2:"<<endl;
    cout<<"No of rows and columns: ";
    cin>>r2>>c2;

    if(c1!=r2){
        cout<<"Invalid Matrices!!!";
        return 1;
    }

    m1 = new int*[r1];
    for(i=0;i<r1;i++)
        m1[i] = new int[c1];

    m2 = new int*[r2];
    for(i=0;i<r2;i++)
        m2[i] = new int[c2];

    m3 = new int*[r1];
    for(i=0;i<r1;i++)
        m3[i] = new int[c2];

    cout<<"Elements for Matrix 1: "<<endl;
    for(i=0;i<r1;i++)
        for(j=0;j<c1;j++)
            cin>>m1[i][j];

    cout<<"Elements for Matrix 2: "<<endl;
    for(i=0;i<r2;i++)
        for(j=0;j<c2;j++)
            cin>>m2[i][j];

    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            for(k=0;k<r2;k++){
                sum += m1[i][k]*m2[k][j];
            }
            m3[i][j] = sum;
            sum=0;
        }
    }
    cout<<"Multiplied Matrix: "<<endl;
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            cout<<m3[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
