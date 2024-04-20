#include<stdio.h>
int main(){//question 4
printf("enter 3 subject marks : \n");
int a[3];
for (int i = 0; i < 3; i++)
 {
scanf("%d" , &a[i]);
}
if(a[0]>50 && a[1]>80 && a[2]>70 )
printf("10");
else if(a[0]>50 && a[1]>80 && a[2]<70 )
printf("9");
else if(a[0]<50 && a[1]>80 && a[2]>70 )
printf("8");
else if(a[0]>50 && a[1]<80 && a[2]>70 )
printf("7");
else if(a[0]>50 || a[1]>80 || a[2]>70 )
printf("6"); 
else
{
    printf("5");
}

}