#include<iostream>
#include<cmath>
using namespace std;

double det(int n,double mat[10][10]);   // u can replace 10 with any number
double d=0;

int main(void)
{
    int n;
    cout<<"enter the order of matrix" ;
    cin>>n;
    double mat[10][10];
    int i,j;
    cout<<"enter the elements"<<endl;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>mat[i][j];

    cout<<"\ndeterminant    "<<det(n,mat);
    return 0;
}

double det(int n,double mat[10][10])
{
    double submat[10][10];

    if(n==2) return( (mat[0][0]*mat[1][1])-(mat[1][0]*mat[0][1]));
    else{
        for(int c=0;c<n;c++){
            int subi=0;   //submatrix's i value
            for(int i=1;i<n;i++){
                int subj=0;
                for(int j=0;j<n;j++){
                    if(j==c)    continue;
                    submat[subi][subj]=mat[i][j];
                    subj++;
                }
                subi++;
            }
            d=d+(pow(-1,c)*mat[0][c]*det(n-1 ,submat));
        }
    }
    return d;
}
