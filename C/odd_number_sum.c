#include<stdio.h>
int main()
{
    //sum of odd natural numbers
    int a,sum,i,s;
    sum=0;
    s=0;
    printf("enter a odd natural number till u want sum");
    scanf("%d",&a);
    for (i=0;i<a;i++)
    {
        s=s*10+9;
        


        sum=sum+s;
        printf("\t%d",s);
    }
   
    
    printf("the sum is %d",sum);
    return 0;

}