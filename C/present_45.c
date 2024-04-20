#include <stdio.h>
int main()
{
    int arr[5];

    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int j=0;j<5;j++)
    {
        if(arr[j]==45)
        {
            printf("45 present at %d",j);
        }
    }

    return 0;
}