#include<stdio.h>
int main()
{
char name[7][100]={'adivya','ria','kshitij'};
printf("enter name for searching");
char yoyo[50];
gets(yoyo);
int temp=0;//
int i=1;
for(int j=0;j<=4;j++)
{

    if(name[i][j]==yoyo)
    {
        //printf("name is found at %d index",j);//2d array
    }


}








return 0;
}