#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c,d,e,f;
printf("enter the value of a,b and c");
scanf("%f%f%f",&a,&b,&c);
//b+-(b)
d=pow((pow(b,2)-4*a*c),1/2);
e=(-b+d)/(2*a);
f=(-b-d)/(2*a);
if(b<0)
{
    printf("imaginery roots");
    printf("roots are %3f and %3f",e,f);


}

printf("roots are %3f and %3f",e,f);




return 0;
}