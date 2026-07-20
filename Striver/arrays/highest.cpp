#include<iostream>
#include<math.h>
#include<climits>
using namespace std;
int main()
{
    int arr[5]={2,5,1,3,810};
    int maxi = INT_MIN;
    for(int i=0;i<(sizeof(arr) / sizeof(arr[i]));i++)
    {
        maxi = max(maxi,arr[i]);
    }
    cout << maxi;
    return 0;
}