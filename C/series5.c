#include<stdio.h>
#include<math.h>
int main()
{
    float b,p,sum=1;
//1+x/2+x^2/4+x^3/6+..........................---->>>5
printf("enter a base value");
scanf("%f",&b);
printf("enter power value");
scanf("%f",&p);
for(int i=1;i<=p;i++)
{
    sum=sum+((pow(b,i))/(2*i));

}
printf("%f",sum);



return 0;
}