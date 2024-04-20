#include <stdio.h>
int main()
{
    // palindrome
    int num, n, rev, rem;
    // input number
    rev = 0;
    printf("enter value");
    scanf("%d", &num);
    n = num;
    while (num != 0)
    {
        rem = num % 10;
        rev = rev * 10 + rem;
        num = num / 10;
    }
    if (rev == n)
    {
        printf("%d is palindrome", n);
    }
    else
    {
        printf("its not a palindrome");
    }
}