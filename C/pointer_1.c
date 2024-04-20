#include<stdio.h>
int modify1(int num)
{
    printf("number is %d",num);
    num+=20;
    printf("numbee is %d",num);
}
int modify2(int *num)
{
    printf("number is %d",*num);
    *num+=20;
    printf("number is %d",*num);
}
int main()
{
    int num;
    printf("eneter a number");
    scanf("%d",&num);
    printf("number is %d",num);
    modify1(num);
    printf("number 4 is %d",num);
    modify2(&num);
    printf("number 5 is %d",num);







return 0;
}