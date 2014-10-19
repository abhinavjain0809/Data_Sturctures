/// If all array elements are negative, then maximum sum is obtained by taking 0 elements from the array...

#include<iostream>
#include<climits>
using namespace std;

void maxSum(int *a,int n){
    int sum=0,curr=0,posStart=-1,posEnd=-1;
    for(int i=0;i<n;i++){
        curr += a[i];
        if(curr < 0)        curr=0;
        if(curr > sum){
            sum = curr;
            posEnd = i;
        }
    }
    cout<<"Maximum Contiguous Sum: "<<sum<<endl;
    for(int i=posEnd;i>=0;i--){
        sum -= a[i];
        if(sum==0){
            posStart = i;
            break;
        }
    }
    cout<<"Starting Position: "<<posStart<<endl;
    cout<<"Ending Position: "<<posEnd<<endl<<endl;
}

int main(){
    int a[8] = {1,3,-2,4,6,-10,8,1};
    maxSum(a,8);

    int b[8] = {-2,-3,4,-1,-2,1,5,3};
    maxSum(b,8);
    return 0;
}
