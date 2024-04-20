#include <stdio.h>
int main()
{
    int sum = 0;
    //WAP WITH DO WHILE SUCH THAT 
    int i, b, c, d = 1;
    do
    {
        printf("enter a number");
        scanf("%d", &b);
        sum = sum + b;
        d++;
        c = -b;

    } while (b > 0 || d == 50);
    printf("%d\n", sum + c);

    return 0;
} 