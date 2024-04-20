#include <stdio.h>
int main()
{
    int x;
    int b = 1;
    printf("enter a number");
    scanf("%d", &x);
    int y;
    y = x;
    while (y / 10 != 0)
    {
        b = b + 1;
        y = y / 10;
    }
    int rem = 0;
    for (int i = 1; i <= b; i++)
    {
        rem = rem + x % 10;
        x = x / 10;
    }
    printf("%d", rem);

    return 0;
}