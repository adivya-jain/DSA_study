#include<stdio.h>
int main()
{
    int num,temp,rem=0,sum=0;
    printf("Enter a numerical value : ");
    scanf("%d",&num);

    temp=num;

    while(num>0)
    {
        if(num==temp || num==rem)
        {
            rem=num%10;
            sum=sum+rem;
            num=(num-rem)/10;
        }
        else
        {
            continue;
        }
    }
    printf("%d",sum);

}