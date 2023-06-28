#include <iostream>
using namespace std;

void printarray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void swapalternate(int arr[], int size)
{
    for (int i = 0; i < size; i = i + 2)
    {
        if(i+1<size)
        {
        swap(arr[i], arr[i + 1]);
        }
    }


}

int main()
{
    cout << "enter size of array";
    int size;
    cin >> size;

    int arr[100];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // printarray(arr, size);

    swapalternate(arr,size);
    printarray(arr,size);


    return 0;
}
