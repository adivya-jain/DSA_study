#include <stdio.h>
int main()
{
    int arr[7] = {1, 2, 31, 51, 67, 4,47};
    int arrev[10];
    int k = 0, q = 0;
    int arrodd[10];

    for (int i = 0; i < 7; i++)
    {

        if (arr[i] % 2 == 0)
        {
            arrev[k] = arr[i];
            k++;
        }
        else
        {
            arrodd[q] = arr[i];
            q++;
        }
    }
    for (int i = 0; i < k; i++)
    {
        printf("%d \n", arrev[i]);
    }

    return 0;
}