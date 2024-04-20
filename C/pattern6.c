#include<stdio.h>
int main()
{
int i,j,k;
for(i=1;i<=5;i++)
{
    for(j=1;j<=i;j++)
    {
        printf("             ");
    }
    for(k=i;k<=5;k++)
    {
        printf("%4d * %d = %2d",i,k,i*k);
    }
    printf("\n");
}




return 0;
}