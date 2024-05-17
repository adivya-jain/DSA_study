#include <iostream>
// #include<stack>

using namespace std;

class Stack
{
    int *arr;
    int top;
    int size;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int x)
    {
        if (size - top > 1)
        {
                    top++;
        arr[top] = x;
            
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }

    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow" << endl;
        }
    }
    int peek()
    {
        if (top >= 0)
            return arr[top];
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }
    bool isEmpty()
    {
        return top == -1;
    }
    int Size()
    {
        return top + 1;
    }
};

int main()
{
    Stack st(5);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(22);
    st.push(33);
    st.push(44);

    cout << "Top element is: " << st.peek() << endl;

    st.pop();

    cout << "Top element after pop: " << st.peek() << endl;
    
    st.pop();

    cout << "Top element after pop: " << st.peek() << endl;
    
    st.pop();

    cout << "Top element after pop: " << st.peek() << endl;
    
}