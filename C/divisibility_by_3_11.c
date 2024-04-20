#include<stdio.h>
int main()
{
    int a;
    printf("enter a number");
    scanf("%d",&a);
    if (a%3==0 && a%11==0)
    {
        printf("number is dividible by both");
    }
    else
    {
        printf("number is not divisible by both");
    }
}