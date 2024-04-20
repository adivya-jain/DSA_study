#include<stdio.h>
int main()
{
int i,j,n;
for(n=1;n<=5;n++)
{
for(i=5;i>=1;i--)
{
    printf(" ");
}
for(j=1;j<=i;j++)
{
    printf("%d\n",j);
}
}

return 0;
}