#include<stdio.h>

void f(char *c)
{
    c++;
    c[2] = 'm';
    printf("%c\n", *c);
}
void main()
{
    char n[] = "hello";
    f(n);
}
