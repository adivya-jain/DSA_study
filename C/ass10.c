#include <stdio.h>
int main()
{
    int n, c = 0;
    printf("enter a number to check");
    scanf("%d", &n);
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            c = c + 1;
        }
    }
    if (c == 0)
    {
        printf("%d is prime", n);
    }
    else
    {
        printf("%d is not prime", n);
    }

    return 0;
}