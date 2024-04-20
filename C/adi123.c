#include<stdio.h>
#include<conio.h>
int main()
{
    int a,b,c;
    char ch;
    printf("enter two numbers\n");
    scanf("%d,%d",&a,&b);
    printf("enter 1 for there sum\n");
    printf("enter 2 for there difference\n");
    printf("enter 3 for there product\n");
    printf("enter 4 for there division\n");
    scanf("%d",&c);
    do
    {
    if (c=1)
    {
        printf("%d",a+b);
    }
    else if (c=2)
    {
        printf("%d",a-b);

    }
    else if (c=3)
    {
        printf("%d",a*b);
    }
    else if (c=4)
    {
        printf("%d",a/b);
        printf("%d",a%b);
    }
    printf("want for calculations?");
    scanf("%c",&ch);
    }while(ch=='y');
}