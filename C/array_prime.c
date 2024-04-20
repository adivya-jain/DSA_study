#include <stdio.h>
int isprime(int num)
{
    int i, c = 0;
    for (i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            c++;
            break;
        }
    }
    if (c == 0)
        return 1;
    else
        return 0;
}
int main()
{
    int c = 0;
    int arr[10] = {};
    for (int j = 0; j < 10; j++)
    {
        printf("enter 10 elements for array");
        scanf("%d", &arr[j]);
    }
    for (int i = 0; i < 10; i++)
    {
        int b = isprime(arr[i]);
        if (b == 1)
        {
            printf("%d is prime \n", arr[i]);
            c++;
        }
        else
        {
            printf("%d not prime", arr[i]);
        }
        printf("\t\n\t");
    }
    printf("total prime number in array are %d", c);

    return 0;
}