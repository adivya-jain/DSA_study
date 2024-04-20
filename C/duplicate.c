#include<stdio.h>
# define max 10
int main()
{
int dup[10];
int arr[10];
printf("entere array elements");
for(int i=0;i<10;i++)
{
    scanf("%d",&arr[i]);
    dup[i]=-1;
}
// for(int i=0;i<10;i++)
// {
        // printf("%d--\t\t\t-->%d \n",arr[i],dup[i]);
    
// }


for(int i=0;i<10;i++)
{
    int cmd=1;
    for(int j=i+1;j<10;j++)
    {
        if(arr[i]==arr[j])
        {
            cmd++;
            dup[j]=0;
        }
    }
    if(dup[i]!=0)
    {
        dup[i]=cmd;
    }
}
for(int i=0;i<10;i++)
{
    if(dup[i]==1)
    {
        printf("%d---\t\t\t->%d \n",arr[i],dup[i]);
    }
}





return 0;
}