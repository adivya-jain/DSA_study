#include <stdio.h>
#include<stdlib.h>

int main(){
    int *ptr;
    int i,n,sum=0;
    float avg;
    printf("enter the number of element you want to store in array");
    scanf("%d",&n);
    ptr=(int*)calloc(n,sizeof(int));//malloc(sizeof())
    if(ptr==NULL)
    {
        printf("The required amount of memory is not available:");
        exit(0);
    }
    else
    {
        printf("\nenter elements:");
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

