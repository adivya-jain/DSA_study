#include <stdio.h>

int check(int n)
{
    if (n % 4 == 0)
    {
        return n + 1;
    }
    else
    {
        return 0;
    }
}
int prime(int n)
{
    int c = 0;
    for (int i = 2; i <= (n) / 2; i++)
    {
        if ((n) % i == 0)
        {
            c = 1;
        }
    }
    if (c == 1)
    {
        return n;
    }
    else
    {
        n = n - 1;
        prime(n);
    }
}
int main()
{
    int y;
    int z;
    int num;
    printf("enter number");
    scanf("%d", &num);
    y = check(num);
    if (y == num + 1)
    {
        printf("output is %d", num + 1);
    }
    else
    {
        num=num-1;
        z = prime(num);
        // if (z == 1)
        // {
        //     printf("prime number not possible");
        // }
        if (z != 1)
        {
            printf("prime number is %d", z);
        }
        else
        {
            printf("prime not possible");
        }
    }
    return 0;
}
