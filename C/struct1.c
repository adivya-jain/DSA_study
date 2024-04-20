#include <stdio.h>
#include<string.h>
struct employee
{
    int roll;
    float marks;
    char *name;
} s1, s2, s3;
//};
// struct employee s1,s2,s3;
s1 = {1, 5.6, "s"};
int main()
{
    // struct employee s1, s2,s3;
    printf("%d  %f  %s", s1.roll, s1.marks, s1.name);

    return 0;
}