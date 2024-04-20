#include<stdio.h>
int main()
{
    int i,num,fact=1;
    printf("enter a number");
    scanf("%d",&num);
    if(num<0)
    {
        printf("enter a number greater then ");

    }
    
    else{
        for(i=1;i<=num;i++)
        {
            fact=fact*i;
            
        }
        
    }
    printf("%d",fact);

}