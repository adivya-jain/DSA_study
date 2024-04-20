#include<stdio.h>
int main()
{
    int arr[]={12,31,-90,-34,67,-3};
    int neg=0;
    int pos=0;
    for(int i=0;i<6;i++)
    {
        if(arr[i]<=0)
        {
            neg=neg+arr[i];
        }
        else
        {
            pos=pos + arr[i];
        }
    }
    printf("%d %d",pos,neg);







return 0;
}