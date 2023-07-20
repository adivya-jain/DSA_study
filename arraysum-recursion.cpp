#include<iostream>

using namespace std;
int sumRecursion(int arr[],int size)
{
    
    if(size==0)
    {
        return 0;
    }
    if(size==1)
    {
        return arr[0];
    }

    
    int sum=arr[0]+sumRecursion(arr+1,size-1);

    return sum;

}
int main()
{
    int arr[6]={1,2,3,4,5,6};

    int size=6;

    int ans=sumRecursion(arr,size);
    cout<<"sum is "<<ans;
}