#include <stdio.h>
#include <string.h>
// strrev is built in function ,seeing how it works// strlen for lenght of string
void strre(char st[], int l)
{
    for (int i = 0; i < l / 2; i++)
    {
        char temp;
        temp = st[i];
        st[i] = st[l - 1 - i];
        st[l - i - 1] = temp;
    }
    //return st;
}
int strle(char st[])
{
    int n = 0;
    int i = 0;
    while (st[i] != '\0')
    {
        n++;
        i++;
    }
    return n;
}
int main()
{
    char st[30];
    gets(st);
    int l = strle(st);
    printf("%d \n", l);
    strre(st, l);
    puts(st);
    strlwr(st);
    puts(st);
    return 0;
}