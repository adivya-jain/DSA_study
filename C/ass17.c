
#include <stdio.h>
int main()
{
 int x,y,z;
printf("enter the value of x and y :");
 scanf("%d%d",&x,&y);
 z=x;
 x=y;
 y=z;
 printf("after swapping, values of x=%d and y=%d",x,y);
 return 0;
}