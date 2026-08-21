#include<iostream>
#include<stack>
using namespace std;


class Solution {
public:
    void pushstack(stack<int>&st,int ele)
    {   
        if(st.empty()){
            st.push(ele);
            return;
        }
        if(st.top() <= ele)
        {
            st.push(ele);
        }else{
            int ele2 = st.top();
            st.pop();
            pushstack(st,ele);
            st.push(ele2);
        }

    }
    void sortStack(stack<int> &st) {
    
        if(st.empty()) return;
        int ele  = st.top();
        st.pop();
        sortStack(st);
        pushstack(st,ele);
    }
};

int main() {

    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(-5);
    st.push(7);
    st.push(15);

    Solution obj;

    obj.sortStack(st);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}