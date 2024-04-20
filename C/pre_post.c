#include<stdio.h>
int main()
{
int a=10,b;
b=++a;
printf("pre %d %d",a,b);
a=10;
b=a++;
printf("post %d %d",a,b);





return 0;
}