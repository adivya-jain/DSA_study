#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    char str1[50],str2[50];
    int i,j;
    printf("enter 2 strings");
    gets(str1);
    gets(str2);
    i=0;
    while(str1[i]!='\0')
    { i++;}
    j=0;
    while(str2[j]!='\0')
    {
        str1[i]=str2[j];
        i++;
        j++;

    }
    str1[i]='\0';
    printf("afre %s",str1);


}