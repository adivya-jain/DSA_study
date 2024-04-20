#include<stdio.h>
#include<math.h>
int conversion(int n)
{int rem,num,i=1;
while(n!=0){

    rem=n%2;
    n=n/2;
    num=num+rem*pow(10,i);
    i++;}
    printf("%d",num);

}

int main()
{
    conversion(100);

 



return 0;
}