#include <stdio.h>
int main()
{
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    int avg = 0;
    int c = 0;
    for (int i = 1; i < 5; i += 2)
    {

        sum = sum + arr[i];
        c++;
    }
    printf("%d",sum);
    avg = sum / c;
    printf("%d", avg);

    return 0;
}