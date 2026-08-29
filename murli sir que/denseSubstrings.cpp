// NUMBER OF DENSE SUBSTRINGS

//A binary string is called dense if the number of 1’s in the string is more than
// the number of 0’s. For example 1, 101,110101 are dense, but 10, 1001,100001
// are not dense.
// 2
// Given a binary string of length n, design an O(nlogn) time algorithm to com
// pute the number of dense sub-strings of the given string. For example, given
// 10101, the answer is 6.
#include<bits/stdc++.h>
using namespace std;



int merge(vector<int>& A,int l,int mid, int r)
{
    int left = l;
    int right = mid+1;
    int cnt=0;
    vector<int> temp;
    while(left <= mid && right <= r)
    {
        if(A[left] > A[right])
        {
            cnt +=(mid-left+1);
            temp.push_back(A[right]);
            right++;
        }else{
            temp.push_back(A[left]);
            left++;
        }
    }
    while(right <= r)
    {
        temp.push_back(A[right]);
        right++;
    }
    while(left <= mid)
    {
        temp.push_back(A[left]);
        left++;
    }

    for(int i = 0; i < temp.size(); i++)
        A[l + i] = temp[i];


    return cnt;
}





int mergeSort(vector<int>& A, int l, int r)
{
    if (l >= r) return 0;

    int mid = (l + r) / 2;

    int cnt = 0;

    cnt += mergeSort(A, l, mid);
    cnt += mergeSort(A, mid + 1, r);
    cnt += merge(A, l, mid, r);

    return cnt;
}







int main()
{
    // string str ="1111111111111000000000000"; // 169
    //    string str = "1001010100101001000101111010110111110100101010101001101010010110111101001010110101110010101101001011"; //4060
        string str = "10"; //0



    vector<int> A(str.length()+1);
    A[0] = 0;
    for(int i=1;i<=str.length();i++)
    {
        if(str[i-1] == '1')
        {
            A[i] = A[i-1] - 1;
        }else{
            A[i] = A[i-1] + 1;
        }
    }

    for(int i=0;i<str.length();i++)
    {
        cout<<str[i]<<" ";
    }

    cout<<endl;
    for(int i=0;i<A.size();i++)
    {
        cout<<A[i]<<" ";
    }


    int l =0;
    int r = A.size()-1;
    cout<<endl;
    cout <<"number of substrings which are dence is "<<mergeSort(A,0,r);

}