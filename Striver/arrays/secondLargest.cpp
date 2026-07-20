#include<iostream>
#include<math.h>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> arr = {1,2,4,17,787,5};
    for(int i=0;i<arr.size();i++)
    {
        pq.push(arr[i]);
        if(pq.size() > 2) pq.pop();
    }
    cout<< pq.top();

    return 0;
}