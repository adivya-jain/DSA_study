#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr;
    int i,n,sum=0;
    float avg;
    printf("enter number of elements you want to store in array");
    scanf("%d",&n);

    ptr=(int *)malloc(n * sizeof(int));
    if(ptr == NULL)
    {
        printf("the requirement amount of memory is not available");
        exit(0);
    }
    else
    {
        printf("\n enter element");
        for(i=0;i<n;i++)
        {
            scanf("%d",ptr+i);
        }
        for(i=0;i<n;i++)
        {
         sum+=(*(ptr+i));
        }
        printf("\nsum is -->%d",sum);
        avg=sum/n;
        printf("\navg is--> %f",avg);
    }
    return 0;
}




