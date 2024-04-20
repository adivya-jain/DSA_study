#include <stdio.h>
#include<conio.h>
int main()
{
    int a, j;
    int n;
    
    int sum = 0;
    printf("enter a number");

    scanf("%d",&a);
    n = a;

    while (n != 0)
    {
        j = n % 10;
        n=n/10;
        int fact = 1;
        for (int i = 1; i <= j; i++)
        {
            fact = fact * i;
        }
        sum = sum + fact;
    }
    if (sum == a)
    {
        printf("krishnamurthy number");
    }
    else
    {
        printf("not krishnamurthy number");
    }
    getch();
}