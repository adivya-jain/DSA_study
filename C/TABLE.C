#include<stdio.h>
int main()
{
    int a;
    printf("enter a number");
    scanf("%d",&a);
    for(int i=1;i<=10;i++)
    {
        printf("%d * %d = %d \n",a,i,a*i);
    }
}