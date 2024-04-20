#include <stdio.h>
#include <math.h>
int main()
{
    int n, b, c = 0, i = 0;
    printf("enter number");
    scanf("%d", &n);
    int rem;
    while (n != 0)
    {
        rem = n % 2;
        n = n / 2;
        b = rem * pow(10, i);
        c = c + b;
        i++;
    }
    printf("%d", c);

    return 0;
}