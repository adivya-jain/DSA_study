#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    int num, a, n, b = 1;
    srand(time(0));
    num = rand() % 100 + 1;
    //printf("the number is %d", num);
    do
    {
        printf("enter a number\n");
        scanf("%d", &a);
        if (num < a)
        {
            printf("lower number please\n");
        }
        else if (num > a)
        {
            printf("greater  number please\n");
        }
        else
        {
            printf("you guessed the number in %d chances", b);
        }
        b++;
    } while (num != a);
}