#include <stdio.h>
#include <string.h>
int main()
{
    char str1[100];
    int str2[100];
    gets(str1);
    for (int i = 0; i < strlen(str1); i++)
    {
        int c = 0;
        for (int j = i+1; j < strlen(str1); j++)
        {
            if (str1[i] == str1[j])
            {
                c++;
                str2[j] = 0;
            }
            if (str2[i] != 0)
            {
                str2[i] = c;
            }
        }
    }
    int max = str2[0];
    int min = str2[0];
    int maxi = 0;
    int mini = 0;
    for (int i = 0; i < strlen(str1); i++)
    {
        if (str2[i] > max)
        {
            max = str2[i];
            maxi = i;
        }
        if (str2[i] < min)
        {
            min = str2[i];
            mini =i;
        }
    }
printf("the character which is occured highest is %c \n\t", str1[maxi]);
printf("the character which is occured lowest is %c \n\t", str1[mini]);



    return 0;
}
