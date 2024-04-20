#include <stdio.h>
int search(float a[], int n, float x)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            c = i;
        
        }
    }
    if (c == 0)
    {
        printf("%d",-1);
    }
    else
    {
        printf("%d",c);
    }
}
int main()
{
    int n = 1;
    scanf("%d", &n);
    float a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &a[i]);
    }
    printf("enter a number to search");
    float x;
    scanf("%f", &x);

    search(a, n, x);

    return 0;
}