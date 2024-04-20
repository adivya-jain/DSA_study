#include<stdio.h>

int main(){

    int a,b,d;
    printf("enter two numbers");
    scanf("%d %d",&a,&b);
    int LCM;
    d=a>b? a:b;

    
    for(LCM=d;LCM<=a*b;LCM+=d)
    
    {
    if (LCM%a==0 && LCM%b==0)
    {
        break;
    }
    }
    printf("%d",LCM);
    return 0;
}