#include<stdio.h>
int main()
{
    int a;
    printf("enter number ");
    scanf("%d",&a);
    if(a==1)
    {
        printf("mon");
    }
    if(a==2)
    {
        printf("tue");
    }
    if(a==3)
    {
        printf("wed");
    }
    if(a==4)
    {
        printf("thus");
    }
    if(a==5)
    {
        printf("fri");
    }
    if(a==6)
    {
        printf("sat");

    }
    if(a==7)
    {
        printf("sun");
    }
    if (a<0 || a>7)
    {
        printf("out of range");

    }
    

}