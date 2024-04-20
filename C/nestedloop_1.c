#include<stdio.h>
int main()
{
int i,j,n,b;
printf("enter a number");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
    for(j=1;j<=i;j++)
    {
        printf("*");
    }
    printf("\n");
}
for(i=1;i<=n;i++)
{
    for(j=5;j>=i;j--)
    {
        printf("*");
    }
    printf("\n");
}






return 0;
}