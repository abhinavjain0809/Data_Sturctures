#include<stdio.h>
main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int n, i, j, start, middle, end, found=0;

    printf("Enter number to search: ");
    scanf("%d", &n);

    start = 0;
    end = 9;

    while(start<=end)
    {
        middle = (start+end)/2;

        if(a[middle]==n)
        {
            printf("Element %d Found at position %d", n, middle+1);
            found=1;
            break;
        }

        else if(n>a[middle]) start = middle+1;

        else end = middle-1;
    }
    if(!found)
        printf("Element NOT FOUND");

    return 0;
}
