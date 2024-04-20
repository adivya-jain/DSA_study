#include <stdio.h>  // include stdio.h library
#include <stdlib.h> // include stdlib.h library

struct date
{
    int day;
    int month;
    int year;
};

void date_diff(struct date start, struct date stop, struct date *diff);

int main()
{
    // int day1, mon1, year1,
    //     day2, mon2, year2;
    struct date start, stop, diff;

    // int day_diff=0, mon_diff=0, year_diff=0;

    printf("Enter start date (MM/DD/YYYY): ");
    scanf("%d/%d/%d", &start.day, &start.month, &start.year);

    printf("Enter end date (MM/DD/YYYY): ");
    scanf("%d/%d/%d", &stop.day, &stop.month, &stop.year);

    date_diff(start, stop, &diff);
    printf("\ndate Difference: %d:%d:%d - ", start.day,
           start.month,
           start.year);
    printf("%d:%d:%d ", stop.day,
           stop.month,
           stop.year);
    printf("= days=%d:months=%d:year=%d\n", diff.day,
           diff.month,
           diff.year);
    return 0;
}
void date_diff(struct date start, struct date stop, struct date *diff)
{
    if (stop.day < start.day)
    {
        // borrow days from february
        if (stop.month == 3)
        {
            //  check whether year is a leap year
            if ((stop.year % 4 == 0 && stop.year % 100 != 0) || (stop.year % 400 == 0))
            {
                stop.day += 29;
            }

            else
            {
                stop.day += 28;
            }
        }

        // borrow days from April or June or September or November
        else if (stop.month == 5 || stop.month == 7 || stop.month == 10 || stop.month == 12)
        {
            stop.day += 30;
        }

        // borrow days from Jan or Mar or May or July or Aug or Oct or Dec
        else
        {
            stop.day += 31;
        }

        stop.month = stop.month - 1;
    }

    if (stop.month < start.month)
    {
        stop.month += 12;
        stop.year -= 1;
    }

    diff->day = stop.day - start.day;
    diff->month = stop.month - start.month;
    diff->year = stop.year - start.year;
}