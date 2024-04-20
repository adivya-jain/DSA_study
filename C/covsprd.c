#include <stdio.h>
#include <math.h>
int main()
{

    int n; //tot population
    int d; //day
    int tescas;
    printf("enter number of test cases");
    scanf("%d", &tescas);
    for (int i = 1; i <= tescas; i++)
    {
        int tot = 1; //number of infected at day 0
        printf("\nenter total population and days");
        scanf("%d %d", &n, &d);

        if (d <= 10)
        {
            tot = pow(2, d);
        }
        else
        {
            tot = pow(2, 10) + 1024*pow(3, d - 10);
        }
        if(tot>=n)
        {
            printf("the total number of infected personds are %d",n);
        }
        else{
            printf("the total infeccted persons after %d days are %d",d,tot);
        }
    }

    return 0;
}