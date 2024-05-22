// Largest Rectangle in Histogram
//  https://leetcode.com/problems/largest-rectangle-in-histogram/description/
class Solution {
private:
vector<int> nextSmallest(vector<int> arr, int n) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for (int i = n-1; i >= 0 ; i--) {
            while( st.top() != -1 && arr[st.top()] >= arr[i])
            {
                st.pop();
            }   
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
   vector<int> prevSmallest(vector<int> arr, int n) {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while( st.top() != -1 && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int area = INT_MIN;
        int n = heights.size();
        vector<int> next(n);
        next = nextSmallest(heights, n);
        vector<int> prev(n);
        prev = prevSmallest(heights, n);
        for (int i = 0; i < n; i++) {
            int l = heights[i];
            if (next[i] == -1) {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newarea = l * b;
            area = max(area, newarea);
        }
        return area;
    }
};