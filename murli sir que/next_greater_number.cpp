#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int arr[] = {6, 3, 4, 2, 1, 7, 8};

    int n = sizeof(arr) / sizeof(arr[0]); 
    
    stack<pair<int, int>> st;
    vector<int> ans;

    for(int i = n - 1; i >= 0; i--)
    {
        int ele = arr[i];
         while(!st.empty() && st.top().first < ele)
        {
            st.pop();
        }
        
        if(st.empty())
        {
            ans.push_back(-1); 
        }

        if(!st.empty() && ele <= st.top().first)
        {
            ans.push_back(st.top().second); 
        }
       

        st.push(make_pair(arr[i], i));
    }
    
    for(int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }

    return 0; 
}
