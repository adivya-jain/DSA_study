#include<stdio.h>

int main(){
    //perfect number

    int a,sum,i;
    sum=0;
    printf("enter a num for checking");
    scanf("%d",&a);
    for(i=1;i<a;i++)
    {
        if(a%i==0)
        {
            printf("\n%d is factor",i);
            sum=sum+i;
        }
        else{
            continue;
        }
        
    }
    if(sum==a)
    {
        printf("number is perfect");
    }
    else{
        printf("\nnumber is not perfect");
    }

    return 0;
}