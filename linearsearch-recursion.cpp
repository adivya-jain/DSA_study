#include <iostream>

using namespace std;
bool linearSearch(int arr[], int size,int num)
{
    if(size==0)
    {
        return 0;
    }
    
    if(arr[0]==num)
    {
        return 1;
    }

    int smallProblem=linearSearch(arr+1,size-1,num);
 
    return smallProblem;

}
int main()
{
    int arr[10] = {1,
                   2,
                   3,
                   4,
                   5,
                   6,
                   7,
                   8,
                   9,
                   10};

    int size = 10;
    int num;
    cin>>num;
    int ans = linearSearch(arr, size,num);
    if(ans)
    {
        cout<<"found";

    }
    else
    {
        cout<<"not found";
    }
}