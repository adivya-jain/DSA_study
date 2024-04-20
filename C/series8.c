#include<stdio.h>
#include<math.h>
int main()
{
    float b,p,sum=1,c;
//1+x/1+x^2/5+x^3/9+......................ap....---->>>8
printf("enter a base value");
scanf("%f",&b);
printf("enter power value");
scanf("%f",&p);
for(int i=1;i<=p;i++)

{
    c=1+(i-1)*4;
    sum=sum+((pow(b,i))/(c));

}
printf("%.2f",sum);



return 0;
}