#include <stdio.h>
#include <math.h>
int main()
{
    int x, a, i, sum = 1;
    //1+x^2+x^3
    printf("enter power");
    scanf("%d", &a);
    printf("enter value of base");
    scanf("%d", &x);
    int rating;
    printf("enter case number");
    scanf("%d", &rating);
    switch (rating)
    {
    case 1:
    //1+x^+x^2+x^3+x^4--------------
        for (i = 1; i <= a; i++)
        {
            sum = sum + pow(x, i);
        }

        printf("\nsum is %d", sum);
        break;
    case 2:
    //1-x+x^2-x^3+x^4-----------------
        for (i = 1; i <= a; i++)
        {
            sum = sum + pow(-x, i);
        }

        printf("\nsum is %d", sum);
        break;
    case 3:
    //1+x-x^2+x^3---------------------
        for (i = 1; i <= a; i++)
        {
            sum = sum - pow(-x, i);
        }

        printf("\nsum is %d", sum);
        break;
    }
}