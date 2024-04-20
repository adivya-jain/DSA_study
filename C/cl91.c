#include <stdio.h>
int main()
{
    int i = 1, sum = 0, a,b=0;
    float avg;

    do
    {
        printf("enter number ");
        scanf("%d", &a);
        if (a > 0)
            goto sum;
            b++;

    sum:
    {
        sum = sum + a;
    }
        i++;
    } while (i != 10);

    printf("sum is %d", sum);
    avg = sum / b;
    printf("average is %f", avg);

    return 0;
}