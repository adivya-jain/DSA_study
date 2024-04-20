#include <stdio.h>
int main()
{
    char str1[100];
    printf("enter a string");
    gets(str1);
    int i = 0, j = 0;
    do
    {
        if (str1[i] == ' ' || str1[i]=='\t' || str1[i]=='\n')
        {
            j++;
        }
        i++;

    } while (str1[i] = '\0');
    printf("%d", j);

    return 0;
}