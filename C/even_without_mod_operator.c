#include <stdio.h>

int main()
{

    int arr[10];
    int ans[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        int div = arr[i] / 2;
        int mul = div * 2;
        if (mul == arr[i])
        {
            ans[i]=0;
        }
        else
        {
            ans[i]=1;
        }
    }
    for(int i=0;i<10;i++)
    {
        printf("%d",ans[i]);
    
    }
    
    return 0;
}