#include <stdio.h>
#include<string.h>
int main()
{
    printf("THIS PROGRAM IS MADE BY ADIVYA ");
    char name[100];
    int sum;
    int roll, marks;
    printf("\n enter name and roll number");
    gets(name);
    scanf("%d",&roll);
    int s1, s2, s3, s4, s5;
    printf("enter marks of 5 subject");
    scanf("%d%d%d%d%d",&s1,&s2,&s3,&s4,&s5);
    sum=s1+s2+s3+s4+s5;
    printf("\n name: - %s",name);
    printf("\n roll is %d",roll);
    float per;
    per = sum/5;
    printf("\n percentage is %.2f", per);

    return 0;
}