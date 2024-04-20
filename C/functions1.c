#include <stdio.h>
//function prototype
//all 4 types that can be used
int add(int a, int b);
int sub();
int mult(int a, int b);
int div();
int main()
{
    int a, b;
    add(3, 4);
    printf("sum of 3,4  is ----->%d", add(3, 4));
    printf("enter the values of a and b");
    scanf("%d%d", &a, &b);
    sub();
    mult(a, b);
    div();
    return 0;
}
//with argumnent and return value
int add(int x, int y)
{
    return x + y;
}
//without arg but return value
int sub()
{
    int a, b;
    printf("enter the values of a and b");
    scanf("%d%d", &a, &b);
    return a - b;
}

//with argument without return value
int mult(int a, int b)
{
    int c = a * b;
    printf("multi------>>> %d", c);
}

//No arg and no return value
int div()
{
    int a, b;
    printf("\n enter the1 value of a and b:");
    scanf("%d%d", &a, &b);
    printf("%d", a / b);
}
