#include <iostream>
#include<queue>

using namespace std;

class heaps
{
    public:
    int arr[100];
    int size;
    heaps()
    {
        arr[0]=-1;
        size = 0; 
    }

    void insert(int x)
    {
        size=size+1;
        arr[size] = x;
        
        int i = size;
        while(i > 1)
        {
            int parent = (i) / 2;
            if(arr[parent] < arr[i])
            {
                swap(arr[parent], arr[i]);
                i = parent;
            }
            else
            {
                return;
            }
        }
    }
    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }

        // put last node element at root node
        arr[1] = arr[size];

        // remove lase node
        size--;

        // put root node at corect position
        int i = 1;

        while (i <= size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex] && arr[leftIndex] > arr[rightIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }

            else if (rightIndex < size && arr[i] < arr[rightIndex] && arr[leftIndex] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }

            else
            {
                return;
            }
        }
    }
void printHeap()
{
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
};


int main()
{
    heaps h;
    h.insert(10);
    h.insert(20);
    h.insert(30);

    h.insert(50);
    h.insert(60);
    h.insert(70);
    h.insert(40);
    h.insert(80);
    h.insert(90);
    h.insert(100);
    h.printHeap();
    h.deleteFromHeap();
       h.printHeap();
}