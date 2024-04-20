#include<stdio.h>
int main()

{
    //factorial of any number
    int i,fact,a;
    fact=i=1;
    printf("enter a number");
    scanf("%d",&a);

    while (i<=a)
    { 
        fact=fact*i;
        i++;
    }
    printf("factorial of %d id %d",a,fact);


}