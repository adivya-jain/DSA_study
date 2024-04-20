#include<stdio.h>
#include<math.h>

int main()
{
  int n ;
 printf("enter the number ");
 scanf("%d ", &n );
 int num = n, rem , j = 1 , sum=0;
 while(n!=0)
 {
     rem = n%10;
     sum += pow(rem , j++); 
     n=n/10;
 }
 printf("sum is %d ", sum );
}