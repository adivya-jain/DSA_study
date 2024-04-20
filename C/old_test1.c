// #include <stdio.h>
// float average(float sum, float c)
// {
//     float avg;
//     avg = sum / c;
//     return avg;
// }
// int count(int sum,int b,int c)
// {
//     c++;
//     sum=sum+b;

// }

// int main()
// {
//     int a, b;
//     int c = 0;
//     int sum = 0;
//     printf("enter numebr of numbers u want");
//     scanf("%d", &a);
//     for (int i = 1; i <= a; i++)
//     {
//         printf("enter nuber");
//         scanf("%d", &b);
//         if (b % 2 != 0)
//         {
//             count(sum,b,c);
//         }
//     }
//     float avg;
//     avg = average(sum, c);
//     printf("%.3f", avg);

//     return 0;
// }
#include <stdio.h>
float average(int n)
{
    int b;
    static float sum=0;
    static int c=0;
    printf("enter nuber");
    scanf("%d", &b);
    if (b % 2 != 0)
    {
        c++;
        sum=sum+b;
    }

    float avg =sum/c;
    return avg;
}
int main()
{
    int a;
    float y;
    printf("enter numebr of numbers u want");
    scanf("%d", &a);
    for (int i = 1; i <= a; i++)
    {
        y = average(a);
    }
    printf("%.3f",y);

    return 0;
}