#include<stdio.h>
void sel_sort(int [], int);
main()
{
    int n, i;
    printf("No of Elements: ");
    scanf("%d", &n);
    int a[n];
    for(i=0;i<n;i++)    scanf("%d", &a[i]);
    sel_sort(a, n);
    printf("\nSorted Array:\n");
    for(i=0;i<n;i++)    printf("%d\t", a[i]);
    return 0;
}

void sel_sort(int a[], int n)
{
    int i, j, temp, min, pos;
    for(i=0;i<n-1;i++)
    {
        min = a[i];
        pos = i;
        for(j=i+1;j<n;j++)
            if(min>a[j])
            {
                min = a[j];
                pos = j;
            }
        if(pos!=i)
        {
            temp = a[i];
            a[i] = a[pos];
            a[pos] = temp;
        }
    }
}
