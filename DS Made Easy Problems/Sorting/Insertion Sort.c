#include<stdio.h>
void ins_sort(int [], int);
main()
{
    int n, i;
    printf("No of Elements: ");
    scanf("%d", &n);
    int a[n];
    for(i=0;i<n;i++)    scanf("%d", &a[i]);
    ins_sort(a, n);
    printf("\nSorted Array:\n");
    for(i=0;i<n;i++)    printf("%d\t", a[i]);
    return 0;
}

void ins_sort(int a[], int n){
    int i, j, k, temp;
    for(i=1;i<n;i++){
        temp = a[i];
        for(j=0;j<i;j++){
            if(a[j]>a[i]){
                for(k=i-1;k>=j;k--)     a[k+1] = a[k];
                a[j] = temp;
            }
        }
    }
}
