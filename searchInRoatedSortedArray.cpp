#include <iostream>
using namespace std;

int findPivot(int arr[], int size)
{
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }

    return s;
}

int binarySearch(int arr[], int s, int e, int k)
{
int start =s;
int end=e;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (arr[mid] < k)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    int arr[5] = {7, 9, 1, 2, 3};
    int pivot = findPivot(arr, 5);
    cout << "pivot is " << arr[pivot];
    cout << "enter key to find in roatated sorted array " << endl;
    int k;
    cin >> k;
    int ans = -1;
    int n=5;
    if (k >= arr[pivot] && k <= arr[n-1])
    {
        ans = binarySearch(arr, pivot,n-1, k);
    }
    else
    {
        ans = binarySearch(arr, 0, pivot - 1, k);
    }

    cout << "element at index " << ans;
}