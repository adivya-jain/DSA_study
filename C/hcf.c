#include <stdio.h>

int main()
{
    int hcf, i, a, b,c=0;
    printf("enter two number for hcf");
    scanf("%d %d", &a, &b);
    for (hcf =2; hcf <= a * b; hcf++)
    {
        if (a % hcf == 0 && b % hcf == 0)
        {
            printf("%d", hcf);
            c=1;
            break;
        }
    }
    if (c==0)
    {
        printf("hcf is 1");
    }

    return 0;
}