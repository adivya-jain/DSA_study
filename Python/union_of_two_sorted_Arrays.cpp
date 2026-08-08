#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr1(n), arr2(m);

    for(int i = 0; i < n; i++)
        cin >> arr1[i];

    for(int i = 0; i < m; i++)
        cin >> arr2[i];

    vector<int> newarray;

    int i = 0, j = 0;

    while(i < n && j < m)
    {
        if(arr1[i] < arr2[j])
        {
            if(newarray.empty() || newarray.back() != arr1[i])
                newarray.push_back(arr1[i]);

            i++;
        }
        else if(arr1[i] > arr2[j])
        {
            if(newarray.empty() || newarray.back() != arr2[j])
                newarray.push_back(arr2[j]);

            j++;
        }
        else
        {
            if(newarray.empty() || newarray.back() != arr1[i])
                newarray.push_back(arr1[i]);

            i++;
            j++;
        }
    }

    // Remaining elements of arr1
    while(i < n)
    {
        if(newarray.empty() || newarray.back() != arr1[i])
            newarray.push_back(arr1[i]);

        i++;
    }

    // Remaining elements of arr2
    while(j < m)
    {
        if(newarray.empty() || newarray.back() != arr2[j])
            newarray.push_back(arr2[j]);

        j++;
    }

    for(int x : newarray)
        cout << x << " ";

    return 0;
}