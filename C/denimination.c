#include<stdio.h>
int main()
{
    int amt,n2000,n500,n200,n100,n50,n20,n10,n5,n2,n1;
    n2000=n500=n200=n100=n50=n20=n10=n5=n2=n1=0;
    
    printf("enter amount");

    scanf("%d",&amt);
    if (amt>=2000)
    {
        n2000=amt/2000;
        amt=amt-(n2000*2000);
        }
    if (amt>=500)
    {
        n500=amt/500;
        amt=amt-(n500*500);
        }
    if (amt>=200)
    {
        n200=amt/200;
        amt=amt-(n200*200);
        }
    if (amt>=100)
    {
        n100=amt/100;
        amt=amt-(n100*100);
        }
     if (amt>=50)
    {
        n50=amt/50;
        amt=amt-(n50*50);
        }
    if (amt>=20)
    {
        n20=amt/20;
        amt=amt-(n20*20);
        }
    if (amt>=10)
    {
        n10=amt/10;
        amt=amt-(n10*10);
        }
    if (amt>=5)
    {
        n5=amt/5;
        amt=amt-(n5*5);
        }
     if (amt>=2)
    {
        n2=amt/2;
        amt=amt-(n2*2);
        }
    if (amt>=1)
    {
        n1=amt;
    
        }
    printf("\n2000----> %d",n2000);
    printf("\n500----> %d",n500);
    printf("\n200---> %d",n200);
    printf("\n100----> %d",n100);
    printf("\n50----> %d",n50);
    printf("\n20----> %d",n20);
    printf("\n10----> %d",n10);
    printf("\n5----> %d",n5);
    printf("\n2----> %d",n2);
    printf("\n1----> %d",n1);
}

    
   