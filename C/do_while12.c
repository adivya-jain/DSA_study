#include<stdio.h>
int main()
{
int n,i=0,sum=0,avg;
do{
    printf("enter number for sum and average if u do not want to continue press 0");
    scanf("%d",&n);
    sum+=0;
    i++;

}while(n!=0);
printf("sum of %d numbers is %d",i,sum);
avg=sum/(i-1);
printf("avg of %d numbers is %d",i,avg);



return 0;
}