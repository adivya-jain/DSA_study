#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &arr, int l, int r);

int findRank(vector<int> &arr, int l, int r, int rank)
{
    if (l <= r)
    {
        int p = rand() % (r - l + 1) + l;
        swap(arr[p], arr[l]);

        int k = partition(arr, l, r);
        int rightCount = r-k+1;
        if (rank == rightCount)
            return k;

        if (rank < rightCount)
        {
            return findRank(arr, k + 1, r, rank);
        }

        return findRank(arr, l, k - 1, rank - rightCount);
    }

    return -1;
}
// int findRankbyElement(vector<int> &arr, int l, int r, int rank)
// {
//     if (l <= r)
//     {
//         int p = rand() % (r - l + 1) + l;
//         swap(arr[p], arr[l]);

//         int k = partition(arr, l, r);
//         int rightCount = r-k+1;
//         if (rank == rightCount)
//             return k;

//         if (rank < rightCount)
//         {
//             return findRank(arr, k + 1, r, rank);
//         }

//         return findRank(arr, l, k - 1, rank - rightCount);
//     }

//     return -1;
// }

int partition(vector<int> &arr, int l, int r)
{
    int i = l + 1;
    int j = r;
    int pivot = arr[l];
    while (i <= j)
    {

        while (i <= r && arr[i] <= pivot)
        {
            i++;
        }
        while (j >= l && arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    // i pointing to 1st element on right array which is greater than pivot  or i → first element from left that is > pivot
    // j is pointing to last element on left array which is less than pivot  or j → first element from right that is <= pivot
    i--; // now i points to 1st element greater than pivot on right array
    swap(arr[l], arr[i]);
    return i; // pivot element index
}

void RQS(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int p = rand() % (r - l + 1) + l; // number between l and r

        swap(arr[l], arr[p]); // putting pivot in 1st index
        int k = partition(arr, l, r);
        // here k is previus pivot element
        RQS(arr, l, k - 1);
        RQS(arr, k + 1, r);
    }
}

int main()
{
    // cout<<"hello";
    vector<int> arr = {1, 52, 23, 53, 23, 876, 43, 28, 92, 113, 54, 73, 73, 92, 1, 9, 45, 852, 232, 56, 2368, 222, 579, 568, 2352, 4562, 8};

    int l = 0;
    int r = arr.size() - 1;
    // RQS(arr, l, r);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << i<<"->"<<arr[i] << " "<<endl;
    }
    cout << endl;
    cout << "here is your rank index" << arr[findRank(arr, l, r, 5)]; // k is the rank of element whose index you want

    return 1;
}