#include<stdio.h>
int recursion(int n)
{ int i=1 ,sum=0;

if(i<11)
{
    return i+recursion(n+1);
}
else{
    return 0;
    
}
printf("%d",sum);


}

int main()
{int sum;
scanf("%d",&n);
printf("%d",recursion());








return 0;
}