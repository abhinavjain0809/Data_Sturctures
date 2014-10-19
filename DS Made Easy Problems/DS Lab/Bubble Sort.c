#include<stdio.h>
main()
{
    int a[100], n, i, j, k, temp;
    printf("No of Elements: ");
    scanf("%d", &n);
    for(i=0;i<n;i++)    scanf("%d", &a[i]);

    for(k=n-1;k>=0;k--)
        for(i=0;i<k;i++)
        {
            j = i+1;
            if(a[i]>a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

    printf("Sorted Array:\n");
    for(i=0;i<n;i++)    printf("%d\t", a[i]);
    return 0;
}
