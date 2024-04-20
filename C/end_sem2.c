#include <stdio.h>
#include <math.h>
int main()
{

    int num, n, res, rem, a, b;
    res = 0;
    b = 0;
    

    printf("enter a number \n");
    scanf("%d",&num);
    n = num;
    a=n;
    while ( a!=0 )
    {
    
      a = a/10;
      b++;
      
    }
    
   while (num != 0)

    {
        rem = num % 10;
        res += pow(rem, b);
        num = num / 10;
    }
    if (n == res)
    {
        printf("its armstrong number");
    }
    else
    {
        printf("number is not armstrong");

    }
}