#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    int cnt = 0;
    int pivot = arr[s];

    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    int pivotIndex = s + cnt;

    swap(arr[pivotIndex], arr[s]);

    int i = s;
    int j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= arr[pivotIndex])
        {
            i++;
        }
        while (arr[j] >= arr[pivotIndex])
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
            swap(arr[i], arr[j]);
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    // Base Case
    if (s >= e)
    {
        return ;
    }

    // partition
    int p = partition(arr, s, e);

    // left part
    quickSort(arr, s, p - 1);
    // right part
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[10] = {2, 2, 1, 0, 5, 4,7,5,3,8};
    int n = 10;

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}