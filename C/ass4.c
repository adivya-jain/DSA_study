#include <stdio.h>
#include <math.h>
int main()
{
    printf("THIS PROGRAM IS MADE BY ADIVYA ");
    printf("\n enter your choice");
    int ch;
    int v, u, a, t, b, c, s;
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:

        printf("enter initial velocity,acceleration and time");
        scanf("%d%d%d", &u, &a, &t);
        v = u + a * t;
        printf("final velocity is %d", v);

        break;
    case 2:

        printf("enter initial velocity,time and acceleration");
        scanf("%d%d%d", &u, &t, &a);
        s = u * t + 0.5 * a * t * t;
        printf("distance travelled  is %d", s);
        break;
    case 3:

        printf("enter a,b and c");
        scanf("%d%d%d", &a, &b, &c);
        t = 2 * a + pow(b + 9 * c, 0.5);
        printf("value of T is %d", t);
        break;
    }

    return 0;
}