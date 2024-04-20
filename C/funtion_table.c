#include<stdio.h>
int function1()
{
    int a,b;
    printf("enter starting and ending limits");
    scanf("%d%d",&a,&b);
    for(int j=a;j<=b;j++)
    {

    for(int i=1;i<=10;i++)
    {
        printf("%d * %d =%d \t",j,i,j*i);
    }

    }
    printf("               ");
}

int main()
{
    function1();





return 0;
}