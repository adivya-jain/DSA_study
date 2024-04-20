#include <stdio.h>
int main()
{
    int T;
    int a, b, c, d;
    scanf("%d%d%d", &a, &b, &c);
    if (a == b && b== c)
    {
        printf("%d", a);
    }
    else if (((a >= b) || (a>=c)) && ((a <= b) || (a<=c)))
    {
        printf("%d", a);
    }
    else if (((b >= a) || (b>=c)) && ((b <= a) || (b<=c)))
    {
        printf("%d", b);
    }
    else
    {
        printf("%d", c);
    }
    

    return 0;
}