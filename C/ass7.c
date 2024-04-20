#include<stdio.h>

int main ()
{
int inum1=6;
int sum;
sum=++inum1 + ++inum1;
printf("The sum1=++inum1 + ++inum1 is %d\n",sum);
sum=++inum1 + --inum1;
printf("The sum2=++inum1 + --inum1 is %d\n",sum);
sum=++inum1 + inum1;
printf("The sum3=++inum1 + inum1 is %d\n",sum);
sum=++inum1 + inum1++;
printf("The sum4=++inum1 + inum1++ is %d\n",sum);
sum=--inum1 + ++inum1;
printf("The sum5=--inum1 + ++inum1 is %d\n",sum);
sum=inum1-- + inum1--;
printf("The sum6=inum1-- + inum1-- is %d\n",sum);
return 0;
}