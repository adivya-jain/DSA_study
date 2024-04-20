#include<stdio.h>
#include<math.h>
int main()
{
    float b,p,sum=1;
    int fact=1;


//1+x/1+x^2/3+x^3/5+..........................---->>>6
printf("enter a base value");
scanf("%f",&b);
printf("enter power value");
scanf("%f",&p);
for(int i=1;i<=p;i++)

{
    fact=fact*i;
    sum=sum+((pow(b,i))/(fact));

}
printf("%f",sum);



return 0;
}