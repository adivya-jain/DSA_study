#include <stdio.h>
#include <string.h>
int readSentance(char s[])
{
    int i = 0;
    int c = 0;
    int sp = 0;
    int n=strlen(s);
    for(int i=0;i<n;i++)
    {
        if (s[i] == ' ' || s[i] == '.')
        {
            sp++;
        }
        else
        {
            c++;
        }
        
    }
    return c;
}
int main()
{
    char word[100];
    gets(word);
    int y;
    y = readSentance(word);
    printf("eihfu =%d", y);

    return 0;
}