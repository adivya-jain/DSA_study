#include<iostream>
#include<vector>
using namespace std;

// Problem statement
// Given an array/list 'ARR' of integers and a position ‘M’. You have to reverse the array after that position.

// Example:

// We have an array ARR = {1, 2, 3, 4, 5, 6} and M = 3 , considering 0 
// based indexing so the subarray {5, 6} will be reversed and our 
// output array will be {1, 2, 3, 4, 6, 5}.

// Sample Input 1:
// 2
// 6 3
// 1 2 3 4 5 6
// 5 2
// 10 9 8 7 6
// Sample Output 1:
// 1 2 3 4 6 5
// 10 9 8 6 7

void reverseArray(vector<int> &arr , int m)
{
    // Write your code here      
    int start=m+1;
    int end=arr.size()-1;

    while(start<=end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }

    return;
}
void print(vector<int> arr)
{
    cout<<"elements of array after reversing are"<<endl;
    for (int i = 0; i < arr.size(); i++)
    {
        /* code */
        cout<<arr[i]<<" ";
    }
    
}
int main()
{
    vector<int> arr;
    for(int i=1;i<7;i++)
    {
        arr.push_back(i);
    }
    int m=3;

    reverseArray(arr,m);


    print(arr);
}