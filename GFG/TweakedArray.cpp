#include <bits/stdc++.h> 
vector<int> tweakTheArray(vector<int> arr, int n){
    // Write your code here.
    int sum = 0 ;
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
    }


    for(int i=0;i<arr.size();i++)
    {
        arr[i]=sum-arr[i];
    }

    return arr;
}