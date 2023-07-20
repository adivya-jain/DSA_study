#include <iostream>
using namespace std;

bool BinarySearch(int arr[], int key, int start, int end)
{
    int size = end - start + 1;
    if (size == 0)
    {
        return false;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
    {
        return true;
    }
    int ans;
    if (arr[mid] > key)
    {
        ans = BinarySearch(arr, key, start, mid - 1);
    }
    else
    {
        ans = BinarySearch(arr, key, mid + 1, end);
    }

    return ans;
}

int main()
{
    int arr[10] = {1, 2, 3, 6, 8, 9, 22, 26, 34, 89};
    int start = 0;
    int key = 1;
    int end = 9;
    int found = BinarySearch(arr, key, start, end);

    if (found)
    {
        cout << "found";
    }
    else
    {
        cout << "not found";
    }
}