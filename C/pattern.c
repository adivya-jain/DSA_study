#include<stdio.h>
int main()
/*
     E
    DE
   CDE
  BCDE
 ABCDE
 */

{
int i,j;

for(i=5;i>=1;i--)
{
    for(int k=i;k>=1;k--)
    {
        printf(" ");
    }
    for(j=i;j<=5;j++)
    {
        printf("%c",j+64);
    }
    printf("\n");
}

return 0;
}

