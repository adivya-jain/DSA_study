#include <stdio.h>
int main()
{
    int per;
    printf("enter grade");
    scanf("%d", &per);
    if (per >= 90)
        printf("grade is A");
    else if (per >= 80 && per < 90)
        printf("grade is B");
    else if (per >= 70 && per < 80)
        printf("grade is C");
    else if (per >= 60 && per < 70)
        printf("grade is D");
    else if (per >= 50 && per < 60)
        printf("grade is E");
    else
        printf("grade is F");

            return 0;
}