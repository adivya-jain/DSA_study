#include <stdio.h>
#include <string.h>
int main()
{
    int t;
    int n,x;
    int arr[100];
    int c=0;
    
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d",&n,&x);
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&arr[i]);
        }
        for(int k=1;k<=n;k++)
        {
            if(arr[k]<x)
            {
                c++;
            }
        }
        printf("%d \n",c);
        
    }

    
    
}