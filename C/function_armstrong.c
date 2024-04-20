#include<stdio.h>
#include<math.h>
int armstrong()
{
    int a;
    int rem;
    int sum=0;

    printf("enter 3 digit  number");
    scanf("%d",&a);
    int b;
    b=a;
    while(a!=0)
    {
        rem=a%10;
        a=a/10;
        sum=sum + pow(rem,3);

        


    }
    printf("%d",sum);
    if(sum==b)
    {
        printf("armstrong number");

    }
    else
    {
        printf("not arstrong");
    }
}
int perfect();
int main()
{
    armstrong();
return 0;
}
int perfect()
{
    int a,sum=0;
    printf("enter 3 digit  number");
    scanf("%d",&a);
    int b;
    b=a;
  
   
    printf("%d",sum);
    if(sum==b)
    {
        printf("perfect number");

    }
    else
    {
        printf("not perfect");
    }

}