#include<stdio.h>
int factorial()

{ int i;
int a;
int fact=1;
    printf("enter a number");
    scanf("%d",&a);
    for(i=1;i<=a;i++)
    {
        fact=fact*i;
    }
    printf("%d",fact);


}
int main()
{
    factorial();





return 0;
}