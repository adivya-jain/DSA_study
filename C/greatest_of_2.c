#include<stdio.h>
int main()
{
    int a,b;
    printf("enter values of a and b");
    scanf("%d %d",&a,&b);
    if (a>b)
    {
        printf("%d is greater",a);
    }
    if (b>a)
    {
        printf("%d is greater",b);
    }

}