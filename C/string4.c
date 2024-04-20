#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    printf("enter string");
    gets(str);
    int i=0,j=0,k=0;
    while(str[i]!='\0')
    {
        if(str[i]=='a' || str[i]=='e'||str[i]=='i' || str[i]=='o'|| str[i]=='u')
        {
            k++;
        }
        else
        {
            j++;
        }
        i++;

    }
    printf("hello");
    printf("%d %d",k,j);





return 0;
}