#include <stdio.h>
int square()
{
    int a;
    printf("enter a number");
    scanf("%d", &a);
    printf("%d", a * a);
}
int main()
{
    square();

    return 0;
}