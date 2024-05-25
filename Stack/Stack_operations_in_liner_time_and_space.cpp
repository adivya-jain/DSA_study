//  Design a stack that supports getMin() in O(1) time and O(1) extra space
// GFG https://www.naukri.com/code360/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465?topList=love-babbar-dsa-sheet-problems%3Fsource%3Dyoutube&campaign=Codestudio_Lovebabbar&utm_source=youtube&utm_medium=affiliate&utm_campaign=Codestudio_Lovebabbar&leftPanelTabValue=SUBMISSION

#include<stack>
class SpecialStack {

    stack<int> st;
    int mini= INT_MAX;
    public:
     void push(int data) {
            // Implement the push() function.
        if(st.empty())
        {
            st.push(data);
            mini = data;
        }
        else{
            if(data<mini)
            {
                int val = 2*data - mini;
                st.push(val);
                mini = data;

            }
            else{
                st.push(data);
            }
        }
    }

    void pop() {
        // Implement the pop() function.
        int curr = st.top();
        
        st.pop();

        if(curr >mini)
        {
// return curr;
        }
        else{
                     int prevmin =  mini;
            int val = 2*mini - curr;
            
            mini = val;
            // return prevmin;
        }

    }

    int top() {
        // Implement the top() function.
        if(st.empty())
        {
            return -1;
        }
        int curr =  st.top();
        if(curr<mini)
        {
           return mini;
        }
        else{
        return curr;
        }
    }

    int getMin() {
        // Implement the getMin() function.
        if(st.empty())
        {
            return -1;
        }

        return mini;
    }  
};