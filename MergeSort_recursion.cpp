#include <iostream>
using namespace std;

void merge(int *arr, int start, int end)
{
    int mid = (start + end) / 2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
    int k = start;

    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k];
        k++;
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k];
        k++;
    }


    //merge

    int index1=0;
    int index2=0;

    int mainIndex=start;

    while(index1 < len1 &&  index2 <len2)
    {
        if(first[index1]>second[index2])
        {
            arr[mainIndex++]=second[index2++];
        }
        else
        {
            arr[mainIndex++]=first[index1++];
        }
    }
    while(index1<len1)
    {
        arr[mainIndex++]=first[index1++];
    }
    while(index2<len2)
    {
        arr[mainIndex++]=second[index2++];
    }
}

void MergeSort(int *arr, int start, int end)
{

    // Base Case
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;

    // Left part sort krna h
    MergeSort(arr, start, mid);

    // right part sort krna h
    MergeSort(arr, mid + 1, end);

    // merge
    merge(arr, start, end);
}

int main()
{
    int arr[5] = {13, 51, 6, 1, 9};
    int n = 5;
    MergeSort(arr, 0, n - 1);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<"  ";
    }
}