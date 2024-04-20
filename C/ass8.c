#include <stdio.h>
int main()
{
    // 8.	Write a program to find the largest of three numbers using ternary operators.
    int a, b, c, d, e, f;
    printf("enter value of a,b,c");
    scanf("%d %d %d", &a, &b, &c);
    d = a > b ? (a > c ? a : c) : (b > c ? b : c);
    printf("\n the gratest of all is %d", d);
     return 0;
}