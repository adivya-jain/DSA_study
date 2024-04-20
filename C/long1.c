#include <stdio.h>
#include <math.h>
int main()
{
    int t1, t2, r1, r2, n;
    scanf("%d", &n);
    while (n=n-1)//new way
    {
        scanf("%d%d%d%d", &t1, &t2, &r1, &r2);
        if (pow(t1, 2)*pow(r2,3) == pow(t2, 2) * pow(r1, 3))
        {
            printf("yes");
        
        }
        else
            {
            printf("no");
                
            }
       // n = n - 1;
    }
    return 0;
}