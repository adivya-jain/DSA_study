#include<stdio.h>
int main()
{
int rank;
printf("enter your rank");
scanf("%d",&rank);
if (rank==1)
{
    printf("you won 10000 rupees");
}
else if (rank==2)
{
    printf("you won 5000 rupees");
}
else if (rank==3)
{
    printf("you won 2500 rupees");
}
else if (rank<=10)
{
    printf("you won 1000 rupees");
}
else if (rank<=20)
{
    printf("you won 500 rupees");
}
else if (rank>20)
{
    printf("thanks for taking part you didnt won any prize");
}
return 0;
}