#include<stdio.h>
int swap(int a,int b)
{
   int c;
    
    c=a;
    a=b;
    printf("first number is %d",a);
    printf("second number is %d",c);

}
int main()
{
     int a,b;
    printf("enter two numbers for swaping");
    scanf("%d%d",&a,&b);

    swap(a,b);





return 0;
}