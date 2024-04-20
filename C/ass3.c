#include <stdio.h>
int main()
{
    printf("THIS PROGRAM IS MADE BY ADIVYA ");
    int a, b;
    float vol = 1;
    printf("\n enter radius and height");
    scanf("%d%d", &a, &b);
    vol = (22.0/7)*a*a*b;
    printf("volume  is %.2f", vol);

    return 0;
}