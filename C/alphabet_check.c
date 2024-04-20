#include<stdio.h>
int main()
{
    char ch;
    printf("enter the values of a");
    scanf("%c",&ch);
    if(ch>='a'&& ch<='z' || ch>='A' && ch<='Z' )
    {
        printf("%c alphabet",ch);
    }
}