#include <stdio.h>
int ispalindrome(int x)
{
    int rem;
    int rev;
    int y = x;
    int c;
    while (x != 0)
    {
        rem = x % 10;
        x = x / 10;
        rev = rev * 10 + rem;
    }
    if (y == rev)
    {
        c = 1;
    }
    else
    {
        c = 0;
    }
    return c;
}
int main()
{
    int y;
    int num;
    scanf("%d",&num);
    y = ispalindrome(num);
    printf("%d",y);

    return 0;
}