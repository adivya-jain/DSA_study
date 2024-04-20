#include<stdio.h>
int main()
{
int i,j,k,z;
for(i=1;i<=5;i++)
{
    for(k=i;k<=5;k++)
    {
        printf(" ");
    }
    for(j=1;j<=i;j++)
    {
        printf("*");
    }
    printf("\n");
}
for(i=1;i<=5;i++)
{
    printf(" ");
    for(k=i;k>=1;k--)
    {
        printf(" ");
    }
    for(j=4;j>=i;j--)
    {
        printf("*");
    }
    printf("\n");
}
return 0;
}