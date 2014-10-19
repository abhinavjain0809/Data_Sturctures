#include<iostream>
#include<cstdlib>
using namespace std;

int main(void)
{
    int i,j,*a,b,l,n;
    cout<<"Enter no of rows: ";
    cin>>n;
    b = (n*(n+1))/2;
    a = (int*)malloc(b*sizeof(int));
    cout<<"Enter elements for the matrix ("<<b<<"):\n";

    for(i=0;i<b;i++)    cin>>a[i];

    cout<<"Lower Trialngular Matrix:"<<endl<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i>=j){
                l = (i*(i+1))/2 + j;
                cout<<a[l]<<"\t";
            }
            else        cout<<"0"<<"\t";
        }
        cout<<"\n";
    }

    return 0;
}
