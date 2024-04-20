#include<stdio.h>

int main(){
    //series 9,99,999,9999.......

    int a,i,sum=0;
    printf("enter till where u want series sum");
    scanf("%d",&a);
    for(i=9;i<=a;i=i*10+9)
    {
        printf("\t%d",i);
        sum=sum+i;
    }
    printf("\nthe sum of series is %d",sum);
    return 0;
}