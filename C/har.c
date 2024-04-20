#include <stdio.h>
#include <string.h>
struct student
{
    double rn;
    char name[100];
    char addr[100];
    char con[15];
    char email[20];
} s1;
int main()
{
printf("%d",sizeof(s1));
}