#include<stdio.h>
int main()
{
    //electricity bill such that first 100 units should be cost at 5rs/unit,next 100 @7/unit ,next 100 @12/unit and rest @16/unit
    int unit,bill;
    printf("enter units of electricity used");
    scanf(" %d",&unit);
    if (unit<=100)
    {
        bill=unit*5;
        printf("bill is %d",bill);
    }
    else if (unit>100 && unit<=200)
    {
        bill = 100*5 + (unit-100)*7;
        printf("bill is %d",bill);
    }
     else if (unit>200 && unit<=300)
    {
        bill = 100*5 + 100*7 + (unit-200)*12;
        printf("bill is %d",bill);

    }
    else if (unit>300)
    {
        bill = 100*5 + 100*7 + (100)*12 + (unit-300)*16;
        printf("bill is %d",bill);
        
    }
    else{
        printf("given unit is wrong");
    }


    

}