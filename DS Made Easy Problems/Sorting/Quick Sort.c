#include<stdio.h>
void q_sort(int [], int, int);
int main()
{
    int n, i;
    printf("No of Elements: ");
    scanf("%d", &n);
    int a[n];
    for(i=0;i<n;i++)    scanf("%d", &a[i]);
    q_sort(a, 0, n-1);
    printf("\nSorted Array:\n");
    for(i=0;i<n;i++)    printf("%d\t", a[i]);
    return 0;
}

void q_sort(int a[], int lb, int ub)
{
    int i, j, pv, temp;
    if(lb<ub)
    {
        i = lb;
        j = ub+1;
        pv = a[lb];
        do{
            do  i++;
            while(a[i]<=pv);

            do  j--;
            while(a[j]>pv);

            if(i<j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }while(i<j);
        temp = a[j];
        a[j] = a[lb];
        a[lb] = temp;
        q_sort(a, lb, j-1);
        q_sort(a, j+1, ub);
    }
}
