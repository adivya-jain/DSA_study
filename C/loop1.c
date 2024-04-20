#include<stdio.h>

int main()
{
    //using for loop to print 1,2,3.......10
    int i=2;
    int sum=0;
    
    while(i<=100)
    {
        printf("\n%d",i);
        sum+=i;
        i+=2;
       
       
        
    }
    printf("\n sum of even numbers between 2-20 is%d",sum);
    
}