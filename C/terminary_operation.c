#include<stdio.h>
int count(int c)
{
    c++;

}
void myfunc1()
{

    int c=0;
    char c1;
    scanf("%c",&c1);
    if(c1!='X')
    count(c);
    
    myfunc1();
 printf("%c",c1);
 return;
 
}
int main(){
myfunc1();
    //printf("%d",y);
    myfunc1();
    //printf("%d",y);
    return 0;
}