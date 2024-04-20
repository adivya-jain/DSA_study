#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("");
    int a;
    int bill = 0;
    printf("\n\t\t\t\t\nwelcome to baba ka dhaba\n");

    while (1)
    {
        printf("\n*********************************");
        printf("\npress1 for water");
        printf("\npress2 for panner tikka-100");
        printf("\npress3 for aloo tamatar");
        printf("\npress4 for dal makkni");
        printf("\npress5 for soup");
        printf("\npress6 for rotis");
        printf("\npress7 for rice");
        printf("\npress8 for mutter panner");
        printf("\npress9 for exit and bill");
        printf("\n****************************");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("press 1 for normal water--10rs per liter\n press2 for cold water-15rs per liter");
            int b;
            scanf("%d", &b);
            int d;
            switch (b)
            {
            case 1:
                printf("you ordered normal water\n enter quantity inn lt plz");
                scanf("%d", &d);
                bill += d * 10;
                break;
            case 2:
                printf("you ordered cold water\n enter quantity inn lt plz");
                scanf("%d", &d);
                bill = bill + d * 15;
                break;
            }
            break;
        case 2:
        
            printf("you ordered panner tikka");
            bill += 100;
            break;
        case 3:
            printf("you ordered aloo tamatar");
            bill += 70;
            break;
        case 4:
            printf("you ordered dal makni");
            bill += 80;
            break;
        case 5:
            printf("you ordered soup ");
            bill += 30;
            break;
        case 6:
            printf("\n*********************************");
            printf("you ordered rotis \n enter quantity of respecctive rotis \a");
            printf("thandori roti-@7 \a ");
            printf("taba roti-@4");
            printf("tandori roti with butter-@8");
            printf("taba roti with butter-@5");
            printf("please enter ");
            printf("\n*********************************");

            int q, w, e, f;
            scanf("%d%d%d%d", &q, &w, &e, &f);

            bill += q * 7 + w * 4 + e * 8 + f * 5;
            break;
        case 7:
            printf("you orderes  rice");
            bill += 50;
            break;
        case 8:
            printf("you orderes panner mutter panner");
            bill += 200;
            break;
        case 9:
            printf("total bill is %d", bill);
            exit(0);
            break;
        }
    }

    return 0;
}