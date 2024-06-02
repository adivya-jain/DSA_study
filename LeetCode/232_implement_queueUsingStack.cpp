
// 232. Implement Queue using Stacks
#include <iostream>

#include <stack>
class MyQueue
{
    stack<int> s1, s2;

public:
    MyQueue() { return; }

    void push(int x) { s1.push(x); }

    int pop()
    {
        if (!s1.size())
        {
            return -1;
        }
        while (s1.size() > 1)
        {
            int element = s1.top();
            s2.push(element);
            s1.pop();
        }
        int pope = s1.top();
        s1.pop();

        while (s2.size())
        {
            int elemet = s2.top();
            s1.push(elemet);
            s2.pop();
        }

        return pope;
    }

    int peek()
    {
        if (!s1.size())
        {
            return -1;
        }
        while (s1.size() > 1)
        {
            int element = s1.top();
            s2.push(element);
            s1.pop();
        }
        int pope = s1.top();
        // s1.pop();
        s2.push(pope);
        s1.pop();

        while (s2.size())
        {
            int elemet = s2.top();
            s1.push(elemet);
            s2.pop();
        }

        return pope;
    }

    bool empty()
    {
        if (!s1.size())
            return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */