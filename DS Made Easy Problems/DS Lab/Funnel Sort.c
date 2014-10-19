#include<stdio.h>
#include<stdlib.h>
main()
{
   int n,i=0;
   printf("No of elements: ");
   scanf("%d", &n);
   int arr[n];
   for(i=0;i<n;i++)     scanf("%d",&arr[i]);
   funnel(arr,n);
   for(i=0;i<n;i++)     printf("%d\t",arr[i]);
   return 0;
}

int funnel(int arr[],int n)
{
   int first=0, i, last=n-1, temp, swap=0;
   while(first<last)
   {
   	for(i=0;i<last;i++)
        if(arr[i]>arr[i+1])
      	{
      	    temp=arr[i];
         	arr[i]=arr[i+1];
         	arr[i+1]=temp;
            swap++;
      	}

    if(swap!=0)
    {
        last--;
        swap=0;
    }
    else    return 0;

        for(i=last;i>first;i--)
           if(arr[i]<arr[i-1])
           {
               temp=arr[i];
               arr[i]=arr[i-1];
               arr[i-1]=temp;
               swap++;
           }
        if(swap!=0)
        {
            first++;
            swap=0;
        }
        else    return 0;
    }
}
