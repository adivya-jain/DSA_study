#include <stdio.h>
int main()
{
    printf("THIS PROGRAM IS MADE BY ADIVYA JAIN");
    int a, b;
    printf("\n enter 2 numbers");
    scanf("%d%d", &a, &b);
    printf("before swaping a=%d and b=%d", a, b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("\n after swaping a=%d and b=%d", a, b);

    return 0;
}