#include <stdio.h>
#include <math.h>

int main()
{
    int u1, a1, t1;
    int a2, b, c1;
    int u, a, t;
    int c;
    printf("Enter your choice from 1 to 3 ");
    scanf(" %d ", &c);

    switch (c)
    {
    case 1:
        printf("Enter initial velocity");
        scanf("%d", &u);
        printf("Enter the acceleration value");
        scanf("%d", &a);
        printf("Enter time ");
        scanf("%d", &t);
        int s = u + a * t;
        printf(" s = u + at  = %d ", s);
        break;

    case 2:
        printf("Enter initial velocity ");
        scanf("%d ", &u1);
        printf("Enter acceleration value ");
        scanf("%d ", &a1);
        printf("Enter time ");
        scanf("%d", &t1);

        int S = ((u1 * t1) + (1 / 2 * a));
        printf("S = u1t + 1/2a = %d  ", S);
        break;

    case 3:
        printf("Enter value of a2 ");
        scanf("%d ", &a2);
        printf("Enter value of b");
        scanf("%d ", &b);
        printf("Enter value of c1 ");
        scanf(" %d ", &c1);
        int T = 2 * a + sqrt(b) + 9 * c1;
        printf(" T = 2a  + sqrt(b) + 9c  = %d  ", T);
        break;
    }
}