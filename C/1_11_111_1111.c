#include<stdio.h>
int main()
{
    //series of 1,11,111,1111,...........
    int a,sum,i,s;
    sum=0;
    s=0;
    printf("enter a odd natural number till u want sum");
    scanf("%d",&a);
    for (i=0;i<a;i++)
    {
        s=s*10+1;
        


        sum=sum+s;
        printf("\t%d",s);
    }
   
    
    printf("\nthe sum is %d",sum);
    return 0;

}