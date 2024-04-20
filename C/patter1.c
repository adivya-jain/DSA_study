#include<stdio.h>
int main()
{
int i,j,n,k;
printf("enter a number");
scanf("%d",&n);
for(i=0;i<=n;i++)
{
    for(k=n;k>=i;k--)
        {
            printf(" ");
        }
    for(j=1;j<=i;j++)
    {
        
        printf(" *");
    }
    printf("\n");
}
return 0;
}