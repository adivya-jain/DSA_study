// GFG Queue Reversal
 
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        // add code here.
        stack<int> st;
              int ele ;
        while(!q.empty())
        {
            ele = q.front();
            st.push(ele);
            q.pop();
        }
        while(!st.empty())
        {
            ele = st.top();
            q.push(ele);
            st.pop();
        }
        
        return q;
    }
};