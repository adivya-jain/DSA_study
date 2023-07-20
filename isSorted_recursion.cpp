#include<iostream>

using namespace std;

bool isSorted(int arr[],int size)
{
    if(size==0 || size==1)
    {
        return true;
    }

    if(arr[0]>arr[1])
    {
        return false;
    }
    else{
        bool remainingpart=isSorted(arr+1,size-1);
        return remainingpart;
    }

}
int main()
{
    int arr[5]={2,3,9,7,8};


    int ans=isSorted(arr,5);

    (ans==1)?(cout<<"is sorted"):cout<<"not sorted";
}