#include <stdio.h>
int main()
{
    int arr[] = {158, 54, 75, 34, 13};
    for (int i = 0; i <= 5; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (arr[i] > arr[j])
            {
                int c;
                c = arr[j];
                arr[j] = arr[i];
                arr[i] = c;
            }
            else
            {
                continue;
            }
        }
    }
    for (int x = 0; x < 5; x++)
    {
        printf("%d \n",arr[x]);
    }
    printf("%d minimum \n",arr[4]);
    printf("%d maxmimum \n",arr[0]);

    return 0;
}