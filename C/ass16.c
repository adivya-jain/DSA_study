#include <stdio.h>

int main()
{

    int a, b, d;
    printf("enter two numbers");
    scanf("%d %d", &a, &b);
    int LCM;
    d = a > b ? a : b;

    for (LCM = d; LCM <= a * b; LCM += d)

    {
        if (LCM % a == 0 && LCM % b == 0)
        {
            break;
        }
    }
    int hcf, i, e, c = 0;
    for (hcf = 2; hcf <= (e = a > b ? (b) : a); hcf++)
    {
        if (a == b)
        {
            c = 2;
        }
        else if (a % hcf == 0 && b % hcf == 0)
        {
            printf("HCF OF %d and %d is %d", a, b, hcf);
            c = 1;
            break;
        }
    }
    if (c == 0)
    {
        printf("hcf is 1");
    }
    if (c == 2)
    {
        printf("hcf is %d", a);
    }
    printf("\n LCM OF %d and %d is %d", a, b, LCM);
    return 0;
}
