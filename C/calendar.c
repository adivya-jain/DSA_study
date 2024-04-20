#include <stdio.h>
int main()
{
    int a,b,c;
    int i;
    printf("enter a number");
    scanf("%d",&a);
    for(i=2001;i<=a;i++)
    {
    
    if(i%4==0 && i%100 !=0 || i%400==0)
    {
    
        b=b+1;
    }
    else{
        continue;
    }
    }
    c=(((a-2000)*365)+b)%7;
    
    switch(c)
    {
        case 1:
        printf("its monday");
        break;
        case 2:
        printf("its tue");
        break;
        case 3:
        printf("its wed");
        break;
        case 4:
        printf("its thus");
        break;
        case 5:
        printf("its fri");
        break;
        case 6:
        printf("its sat");
        break;
        case 7:
        printf("its sun");
        break;
        
    }
    
    




    return 0;
}