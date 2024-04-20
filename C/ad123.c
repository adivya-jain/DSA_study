#include<stdio.h>
int main()
{
    int a=2;
    printf("%d %d %d %d",--a,a++,++a,a--);
    a++;
    printf("\n%d %d %d %d",--a,a++,++a,a--);
}