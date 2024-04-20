#include <stdio.h>
int main()
{
    int sum = 1;
     x:
    printf("%d\n", sum);

    if (sum == 1)
    {
        for (int i = 1; i <= 10; i++)
        {
            sum += i;
        }
    

        goto x;
       

        return 0;
    }
    }
